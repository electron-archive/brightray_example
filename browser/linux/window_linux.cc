#include <gtk/gtk.h>
#include "window_linux.h"

#include "base/message_loop/message_loop.h"
#include "brightray/browser/inspectable_web_contents.h"
#include "brightray/browser/inspectable_web_contents_view.h"

namespace brightray_example {

Window* Window::Create(brightray::BrowserContext* browser_context) {
  return new WindowLinux(browser_context);
}

static void window_closed(GtkWindow *gtk_window, WindowLinux *window_object) {
  // There's only one window, so exit when it closes.
  delete window_object;
  base::MessageLoop::current()->QuitWhenIdle();
}

WindowLinux::WindowLinux(brightray::BrowserContext* browser_context)
    : Window(browser_context) {
  window_ = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window_), "Brightray Example");
  gtk_container_border_width(GTK_CONTAINER(window_), 8);
  g_signal_connect(GTK_OBJECT(window_), "destroy", G_CALLBACK(window_closed), 0);

  // Make the window 70% the width and height of the default screen.
  GdkScreen *screen = gdk_screen_get_default();
  gtk_window_set_default_size(GTK_WINDOW(window_),
    gdk_screen_get_width(screen) * 7 / 10,
    gdk_screen_get_height(screen) * 7 / 10);

  auto view = inspectable_web_contents()->GetView()->GetNativeView();
  gtk_container_add(GTK_CONTAINER(window_), view);

  WindowReady();
}

WindowLinux::~WindowLinux() {
  gtk_widget_destroy(window_);
}

void WindowLinux::Show() {
  gtk_widget_show(window_);
}

}
