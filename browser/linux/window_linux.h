#ifndef BRIGHTRAY_EXAMPLE_BROWSER_LINUX_WINDOW_LINUX_H_
#define BRIGHTRAY_EXAMPLE_BROWSER_LINUX_WINDOW_LINUX_H_

#include "browser/window.h"

namespace brightray_example {

class WindowLinux : public Window {
 public:
  WindowLinux(brightray::BrowserContext*);
  ~WindowLinux();

  virtual void Show() OVERRIDE;
  void ResizeWebContents();

 private:
  DISALLOW_COPY_AND_ASSIGN(WindowLinux);
};

}

#endif
