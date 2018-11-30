#include <iostream>
#include <string>

#include <pistache/endpoint.h>

#include "_error.h"

struct HelloHandler : public Pistache::Http::Handler {
    HTTP_PROTOTYPE(HelloHandler)

    void onRequest(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter writer) {
        writer.send(Pistache::Http::Code::Ok, "Hello, World!");
    }
};

int main(int argc, char const *argv[])
{
	std::cout<<"Insomnai version .013"<<std::endl;
	try
	{
		Pistache::Http::listenAndServe<HelloHandler>("*:9080");
	}
	catch(const _error& e)
	{
		std::cerr<<"Error: "<<e.what()<<std::endl;
		return 1;
	}
	catch(...)
	{
		std::cerr<<"Error: unknown exception"<<std::endl;
		return 2;
	}
	return 0;
}
