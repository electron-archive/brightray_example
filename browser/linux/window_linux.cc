#include "window_linux.h"

#include "brightray/browser/inspectable_web_contents.h"
#include "brightray/browser/inspectable_web_contents_view.h"

namespace brightray_example {

Window* Window::Create(brightray::BrowserContext* browser_context) {
  return new WindowLinux(browser_context);
}

WindowLinux::WindowLinux(brightray::BrowserContext* browser_context)
    : Window(browser_context) {
  // TODO
  fprintf(stderr, "WindowLinux::WindowLinux\n");
  auto view = inspectable_web_contents()->GetView()->GetNativeView();
  //SetParent(view, window_);
  ResizeWebContents();
  WindowReady();
}

WindowLinux::~WindowLinux() {
  // TODO
  fprintf(stderr, "WindowLinux::~WindowLinux\n");
}

void WindowLinux::Show() {
  // TODO
  fprintf(stderr, "WindowLinux::Show\n");
}

void WindowLinux::ResizeWebContents() {
  // TODO
  fprintf(stderr, "WindowLinux::ResizeWebContents\n");
}

}
