#ifndef BRIGHTRAY_EXAMPLE_BROWSER_WIN_WINDOW_WIN_H_
#define BRIGHTRAY_EXAMPLE_BROWSER_WIN_WINDOW_WIN_H_

#include "browser/window.h"
#include <Windows.h>

namespace brightray_example {

class WindowWin : public Window {
 public:
  WindowWin(brightray::BrowserContext*);
  ~WindowWin();

  virtual void Show() OVERRIDE;

 private:
  static HINSTANCE instance_handle_;
  static void RegisterWindowClass();
  static LRESULT CALLBACK WndProc(HWND, UINT message, WPARAM, LPARAM);

  void ResizeWebContents();

  HWND window_;

  DISALLOW_COPY_AND_ASSIGN(WindowWin);
};

}

#endif
