#include "TCP.hpp"
#include "TcpConverter.hpp"
#include "Monitor.hpp"
#include "Parking.hpp"
#include <bits/stdc++.h>
#include <memory>
#include <csignal>

// Main function
int main() {
    static bool quit = false;

    // Create a TCP input instance on port 5000
    std::unique_ptr<sp::Input<sp::Key>> tcpInput = std::make_unique<sp::TcpInput>(5000);
    sp::TcpConverter tcpConverter;
    sp::Monitor monitor;
    sp::Parking<sp::TcpConverter, sp::Key> parking(tcpConverter, tcpInput, monitor);

    // Handle SIGINT to safely exit
    signal(SIGINT, [](int signal) {
        quit = true;
        exit(0);
    });

    while (!quit) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Clean up
    tcpInput->terminate();
    parking.close();
    tcpInput.reset();

    return 0;
}
