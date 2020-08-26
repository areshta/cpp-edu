#include "CanClient.h"
#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[]) {
  std::cout << "client is starting... \n";
  // Create proxy object for the concatenator object on the server side
  const char *destinationName = "com.daimler.oagw.test.can";
  const char *objectPath = "/com/daimler/oagw/test/can";
  CanSenderProxy canSenderProxy(destinationName, objectPath);

  // Invoke concatenate with some numbers
  auto retOK = canSenderProxy.CANSignal("Test signal", 123);
  assert(retOK);

  // Give sufficient time to receive 'concatenated' signal from the first
  // concatenate invocation
  sleep(1);

  return 0;
}
