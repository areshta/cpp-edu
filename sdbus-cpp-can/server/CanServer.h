#pragma once

#include "../dbus/sdbus-gen/CanAdapterGlue.h"
#include <iostream>
#include <sdbus-c++/sdbus-c++.h>

namespace com {
namespace daimler {
namespace oagw {
namespace test {
class CanReciver : public sdbus::AdaptorInterfaces<com::daimler::
                                                       oagw::
                                                           test::Can_adaptor /*, more adaptor classes if there are more interfaces*/> {
public:
  CanReciver(sdbus::IConnection &connection, std::string objectPath)
      : AdaptorInterfaces(connection, std::move(objectPath)) {
    registerAdaptor();
  }

  ~CanReciver() { unregisterAdaptor(); }

protected:
  bool CANSignal(const std::string &name, const int32_t &value) override {
    std::cout << "server :" << name << ":" << value << std::endl;
    return true;
  }
};
} // namespace test
} // namespace oagw
} // namespace daimler
} // namespace com
