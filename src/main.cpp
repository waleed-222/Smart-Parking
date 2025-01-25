#include "Keyboard.hpp"
#include "Parking.hpp"
#include <bits/stdc++.h>
#include <memory>
// Main function
int main() {
  static bool quit = false;
  std::unique_ptr<sp::Input<sp::Key>> keyboard =
      std::make_unique<sp::keyboard>();
  sp::Parking parking(keyboard);

  signal(SIGINT, [](int signal) {
    quit = true;
    exit(0);
  });
  while (!quit) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  keyboard->terminate();
  parking.close();
  keyboard.reset();
  return 0;
}
