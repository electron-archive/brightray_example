#include "renderer/render_view_observer.h"

#include "base/stringprintf.h"
#include "base/string_util.h"
#include "third_party/WebKit/Source/WebKit/chromium/public/WebDocument.h"
#include "third_party/WebKit/Source/WebKit/chromium/public/WebFrame.h"
#include "v8/include/v8.h"

namespace brightray_example {

namespace {

v8::Handle<v8::Value> HelloWorld(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
  return v8::String::New(base::StringPrintf("Hello, World from %s:%d!", __FILE__, __LINE__).c_str());
}

v8::Persistent<v8::ObjectTemplate> ConstructorTemplate() {
  static auto constructor_template = []() -> v8::Persistent<v8::ObjectTemplate> {
    auto constructor_template = v8::Persistent<v8::ObjectTemplate>::New(v8::Isolate::GetCurrent(), v8::ObjectTemplate::New());
    constructor_template->SetAccessor(v8::String::New("helloWorld"), HelloWorld);
    return constructor_template;
  }();

  return constructor_template;
}

}

RenderViewObserver::RenderViewObserver(content::RenderView *render_view)
    : content::RenderViewObserver(render_view) {
}

RenderViewObserver::~RenderViewObserver() {
}

void RenderViewObserver::DidClearWindowObject(WebKit::WebFrame* frame) {
  GURL url = frame->document().url();
  if (!url.SchemeIs("http") ||
      !url.DomainIs("adam.roben.org") ||
      !StartsWithASCII(url.path(), "/brightray_example/", true))
    return;

  v8::HandleScope scope;

  auto context = frame->mainWorldScriptContext();
  v8::Context::Scope contextScope(context);

  context->Global()->Set(v8::String::New("brightray_example"), ConstructorTemplate()->NewInstance());
}

}