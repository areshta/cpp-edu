#pragma once

#include "../dbus/sdbus-gen/CanProxyGlue.h"
#include <iostream>
#include <sdbus-c++/sdbus-c++.h>

using namespace com::daimler::oagw::test;

class CanSenderProxy
    : public sdbus::ProxyInterfaces<
          com::daimler::oagw::test::
              Can_proxy /*, more proxy classes if there are more interfaces*/> {
public:
  CanSenderProxy(std::string destination, std::string objectPath)
      : ProxyInterfaces(std::move(destination), std::move(objectPath)) {
    registerProxy();
  }

  ~CanSenderProxy() { unregisterProxy(); }
};
