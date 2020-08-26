#include "CanServer.h"
#include <iostream>

using namespace com::daimler::oagw::test;

int main(int argc, char *argv[]) {
  std::cout << "server is starting... \n";
  // Create D-Bus connection to the system bus and requests name on it.
  const char *serviceName = "com.daimler.oagw.test.can";
  auto connection = sdbus::createSystemBusConnection(serviceName);

  // Create concatenator D-Bus object.
  const char *objectPath = "/com/daimler/oagw/test/can";
  CanReciver reciver(*connection, objectPath);

  // Run the loop on the connection.
  std::cout << "server is working..." << std::endl;
  connection->enterEventLoop();
}
