#include "common/main_delegate.h"

#include "browser/browser_client.h"

namespace brightray_example {

MainDelegate::MainDelegate() {
}

MainDelegate::~MainDelegate() {
}

content::ContentBrowserClient* MainDelegate::CreateContentBrowserClient() {
  browser_client_.reset(new BrowserClient);
  return browser_client_.get();
}

}
