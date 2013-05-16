#include "common/library_main.h"
#include "common/main_delegate.h"

#if defined(OS_WIN)

#include <Windows.h>

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE, wchar_t*, int) {
  return 0;
}

#else

int main(int argc, const char* argv[]) {
  return BrightrayExampleMain(argc, argv);
}

#endif
