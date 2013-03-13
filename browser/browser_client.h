#ifndef BRIGHTRAY_EXAMPLE_BROWSER_BROWSER_CLIENT_H_
#define BRIGHTRAY_EXAMPLE_BROWSER_BROWSER_CLIENT_H_

#include "brightray/browser/browser_client.h"

namespace brightray_example {

class BrowserClient : public brightray::BrowserClient {
public:
  BrowserClient();
  ~BrowserClient();

private:
  virtual brightray::BrowserMainParts* OverrideCreateBrowserMainParts(const content::MainFunctionParams&) OVERRIDE;

  DISALLOW_COPY_AND_ASSIGN(BrowserClient);
};

}

#endif
