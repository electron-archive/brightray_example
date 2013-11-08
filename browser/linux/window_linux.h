#ifndef BRIGHTRAY_EXAMPLE_BROWSER_LINUX_WINDOW_LINUX_H_
#define BRIGHTRAY_EXAMPLE_BROWSER_LINUX_WINDOW_LINUX_H_

#include <gtk/gtk.h>
#include "browser/window.h"

namespace brightray_example {

class WindowLinux : public Window {
 public:
  WindowLinux(brightray::BrowserContext*);
  ~WindowLinux();

  virtual void Show() OVERRIDE;

 private:
  GtkWidget *window_;
  DISALLOW_COPY_AND_ASSIGN(WindowLinux);
};

}

#endif
