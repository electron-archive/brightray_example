#include "common/library_main.h"
#include "common/main_delegate.h"

#include "content/public/app/content_main.h"
#include "sandbox/win/src/sandbox_types.h"

#if defined(OS_WIN)

#include "content/public/app/startup_helper_win.h"
#include <Windows.h>

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE, wchar_t*, int) {
  sandbox::SandboxInterfaceInfo sandbox_info = {0};
  content::InitializeSandboxInfo(&sandbox_info);
  brightray_example::MainDelegate delegate;
  return content::ContentMain(instance, &sandbox_info, &delegate);
}

#else

int main(int argc, const char* argv[]) {
  return BrightrayExampleMain(argc, argv);
}

#endif
