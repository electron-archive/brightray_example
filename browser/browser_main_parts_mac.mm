#import "browser/browser_main_parts.h"

#import "brightray/browser/browser_context.h"
#import "content/public/browser/web_contents.h"
#import "content/public/browser/web_contents_view.h"
#import <AppKit/AppKit.h>

namespace brightray_example {

void BrowserMainParts::PreMainMessageLoopRun() {
  brightray::BrowserMainParts::PreMainMessageLoopRun();

  auto contentRect = NSMakeRect(0, 0, 800, 600);
  auto styleMask = NSTitledWindowMask | NSClosableWindowMask | NSMiniaturizableWindowMask | NSResizableWindowMask;
  auto window = [[NSWindow alloc] initWithContentRect:contentRect styleMask:styleMask backing:NSBackingStoreBuffered defer:YES];
  window.title = @"Brightray Example";

  auto contents = content::WebContents::Create(content::WebContents::CreateParams(browser_context()));
  auto contentsView = contents->GetView()->GetNativeView();

  contentsView.frame = [window.contentView bounds];
  contentsView.autoresizingMask = NSViewWidthSizable | NSViewHeightSizable;

  [window.contentView addSubview:contentsView];
  [window makeKeyAndOrderFront:nil];

  contents->GetController().LoadURL(GURL("http://dev.chromium.org/Home"), content::Referrer(), content::PAGE_TRANSITION_AUTO_TOPLEVEL, std::string());
}

}
