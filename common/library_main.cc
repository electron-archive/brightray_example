#include "common/library_main.h"

#include "common/main_delegate.h"
#include "content/public/app/content_main.h"

int BrightrayExampleMain(int argc, const char* argv[]) {
  brightray_example::MainDelegate delegate;
  return content::ContentMain(argc, argv, &delegate);
}
