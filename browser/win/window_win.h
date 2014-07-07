#ifndef BRIGHTRAY_EXAMPLE_BROWSER_WIN_WINDOW_WIN_H_
#define BRIGHTRAY_EXAMPLE_BROWSER_WIN_WINDOW_WIN_H_

#include "browser/window.h"

namespace views {
class Widget;
}

namespace brightray_example {

class WindowWin : public Window {
 public:
  WindowWin(brightray::BrowserContext*);
  ~WindowWin();

  virtual void Show() OVERRIDE;

 private:
  views::Widget* widget_;

  DISALLOW_COPY_AND_ASSIGN(WindowWin);
};

}

#endif
