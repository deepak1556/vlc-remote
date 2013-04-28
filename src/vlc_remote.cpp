#include <v8.h>
#include <node.h>
#include <string>

using namespace v8;

class vlc_remote : node::ObjectWrap {
private:
  std::string action;
public:
  vlc_remote() {}
  ~vlc_remote() {}
  static v8::Persistent<FunctionTemplate> persistent_function_template;
  static void Init(Handle<Object> target){
    v8::HandleScope scope;

    //constructor
    v8::Local<FunctionTemplate> local_function_template = v8::FunctionTemplate::New(New);
    vlc_remote::persistent_function_template = v8::Persistent<FunctionTemplate>::New(local_function_template);
    vlc_remote::persistent_function_template->InstanceTemplate()->SetInternalFieldCount(1);
    vlc_remote::persistent_function_template->SetClassName(v8::String::NewSymbol("remote"));

    //getters and setters
    vlc_remote::persistent_function_template->InstanceTemplate()->SetAccessor(String::New("action"), GetRemoteAction, SetRemoteAction);

    //methods
    NODE_SET_PROTOTYPE_METHOD(vlc_remote::persistent_function_template, "send", Send);

    // Binding constructor function to the target variable
    target->Set(String::NewSymbol("remote"), vlc_remote::persistent_function_template->GetFunction());
  }

// new()
static Handle<Value> New(const Arguments& args) {
  HandleScope scope;
  vlc_remote* vlc_remote_instance = new vlc_remote();

  // Wrap our C++ object as a Javascript object
  vlc_remote_instance->Wrap(args.This());

  return args.This();
}

// this.remoteaction
static v8::Handle<Value> GetRemoteAction(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
  // Extract the C++ request object from the JavaScript wrapper.
  vlc_remote* vlc_remote_instance = node::ObjectWrap::Unwrap<vlc_remote>(info.Holder());
  return v8::String::New(vlc_remote_instance->action.c_str());
}

// this.remoteaction=
static void SetRemoteAction(Local<String> property, Local<Value> value, const AccessorInfo& info) {
  vlc_remote* vlc_remote_instance = node::ObjectWrap::Unwrap<vlc_remote>(info.Holder());
  v8::String::Utf8Value v8str(value);
  vlc_remote_instance->action = *v8str;
}

// this.send()
static v8::Handle<Value> Send(const Arguments& args) {
  v8::HandleScope scope;
  // Extract C++ object reference from "this"
  vlc_remote* vlc_remote_instance = node::ObjectWrap::Unwrap<vlc_remote>(args.This());

  // Convert first argument to V8 String
  v8::String::Utf8Value v8str(args[0]);

  // Return value
  return v8::Boolean::New(true);
}
};

//v8::Persistent<FunctionTemplate> vlc_remote::persistent_function_template;
extern "C" {
  static void init(Handle<Object> target) {
    vlc_remote::Init(target);
  }
  NODE_MODULE(vlc_remote, init);
}
