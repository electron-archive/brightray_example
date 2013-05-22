#ifndef BRIGHTRAY_EXAMPLE_BROWSER_WIN_WINDOW_WIN_H_
#define BRIGHTRAY_EXAMPLE_BROWSER_WIN_WINDOW_WIN_H_

#include "browser/window.h"

namespace brightray_example {

class WindowWin : public Window {
 public:
  WindowWin(brightray::BrowserContext*);
  ~WindowWin();

  virtual void Show() OVERRIDE;

 private:
  DISALLOW_COPY_AND_ASSIGN(WindowWin);
};

}

#endif
