#include "browser/win/window_win.h"

namespace brightray_example {

Window* Window::Create(brightray::BrowserContext* browser_context) {
  return new WindowWin(browser_context);
}

WindowWin::WindowWin(brightray::BrowserContext* browser_context)
    : Window(browser_context) {
}

WindowWin::~WindowWin() {
}

void WindowWin::Show() {
}

}
