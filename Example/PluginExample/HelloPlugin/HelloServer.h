#ifndef HELLOSERVER_H
#define HELLOSERVER_H

#include <QtPlugin>

class HelloServer
{
public:
    HelloServer();
    virtual ~HelloServer();

public:
    virtual void sayHello() = 0;
};

#define HelloServer_iid "org.commontk.service.demos.HelloService"
Q_DECLARE_INTERFACE(HelloServer, HelloServer_iid)

#endif // HELLOSERVER_H
