#import "browser/browser_main_parts.h"

#import "brightray/browser/browser_context.h"
#import "brightray/browser/default_web_contents_delegate.h"
#import "brightray/browser/inspectable_web_contents.h"
#import "brightray/browser/inspectable_web_contents_view.h"
#import <AppKit/AppKit.h>

namespace brightray_example {

void BrowserMainParts::PreMainMessageLoopRun() {
  brightray::BrowserMainParts::PreMainMessageLoopRun();

  auto contentRect = NSMakeRect(0, 0, 800, 600);
  auto styleMask = NSTitledWindowMask | NSClosableWindowMask | NSMiniaturizableWindowMask | NSResizableWindowMask;
  auto window = [[NSWindow alloc] initWithContentRect:contentRect styleMask:styleMask backing:NSBackingStoreBuffered defer:YES];
  window.title = @"Brightray Example";

  // FIXME: We're leaking this object (see #3).
  auto contents = brightray::InspectableWebContents::Create(content::WebContents::CreateParams(browser_context()));
  // FIXME: And this one!
  contents->GetWebContents()->SetDelegate(new brightray::DefaultWebContentsDelegate());
  auto contentsView = contents->GetView()->GetNativeView();

  contentsView.frame = [window.contentView bounds];
  contentsView.autoresizingMask = NSViewWidthSizable | NSViewHeightSizable;

  [window.contentView addSubview:contentsView];
  [window makeFirstResponder:contentsView];
  [window makeKeyAndOrderFront:nil];

  contents->GetWebContents()->GetController().LoadURL(GURL("http://adam.roben.org/brightray_example/start.html"), content::Referrer(), content::PAGE_TRANSITION_AUTO_TOPLEVEL, std::string());
}

}
