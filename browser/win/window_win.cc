#include "browser/win/window_win.h"

#include "brightray/browser/inspectable_web_contents.h"
#include "brightray/browser/inspectable_web_contents_view.h"

#include "base/win/wrapped_window_proc.h"
#include "ui/base/win/hwnd_util.h"

namespace brightray_example {

namespace {

const wchar_t kClassName[] = L"Brightray Example";

}

HINSTANCE WindowWin::instance_handle_ = nullptr;

Window* Window::Create(brightray::BrowserContext* browser_context) {
  return new WindowWin(browser_context);
}

WindowWin::WindowWin(brightray::BrowserContext* browser_context)
    : Window(browser_context) {
  RegisterWindowClass();

  window_ = CreateWindow(kClassName, L"Brightray Example",
                         WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                         nullptr, nullptr, instance_handle_, nullptr);
  ui::SetWindowUserData(window_, this);

  auto view = inspectable_web_contents()->GetView()->GetNativeView();
  SetParent(view, window_);
  ResizeWebContents();
  WindowReady();
}

WindowWin::~WindowWin() {
}

void WindowWin::Show() {
  ShowWindow(window_, SW_SHOWNORMAL);
}

void WindowWin::RegisterWindowClass() {
  static bool registered;
  if (registered)
    return;
  registered = true;

  WNDCLASSEX wndclass;
  base::win::InitializeWindowClass(
      kClassName, &WindowWin::WndProc,
      CS_HREDRAW | CS_VREDRAW,
      0, 0,
      LoadCursor(nullptr, IDC_ARROW), nullptr,
      nullptr,
      nullptr, nullptr,
      &wndclass);
  instance_handle_ = wndclass.hInstance;
  RegisterClassEx(&wndclass);
}

LRESULT WindowWin::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
  WindowWin* window = static_cast<WindowWin*>(ui::GetWindowUserData(hwnd));

  switch (message) {
    case WM_SIZE:
      window->ResizeWebContents();
      return 0;
    case WM_DESTROY:
      delete window;
      PostQuitMessage(0);
      return 0;
  }

  return DefWindowProc(hwnd, message, wParam, lParam);
}

void WindowWin::ResizeWebContents() {
  RECT client_rect;
  GetClientRect(window_, &client_rect);
  auto view = inspectable_web_contents()->GetView()->GetNativeView();
  SetWindowPos(view, nullptr, client_rect.left, client_rect.top, client_rect.right - client_rect.left, client_rect.bottom - client_rect.top, SWP_NOZORDER);
}

}
