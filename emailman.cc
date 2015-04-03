#include <nan.h>
#include <regex>


using namespace v8;

static const std::regex rx("^([\\w_\\.\\-\\+])+\\@([\\w\\-]+\\.)+([\\w]{2,10})+$");

NAN_METHOD(Validate) {
	NanScope(); 
	Local<String> address = args[0].As<String>();
	if(std::regex_match(*String::Utf8Value(address),rx)){
		NanReturnValue(NanNew<Boolean>(true));
	}else{
		NanReturnValue(NanNew<Boolean>(false));
	}
	
}

void Init(Handle<Object> exports) {
  exports->Set(NanNew("validate"), NanNew<FunctionTemplate>(Validate)->GetFunction());
}

NODE_MODULE(emailman, Init)
