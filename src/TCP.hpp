#pragma once
/********************************************/
//
//              CopyRight Waleed Ebrahem
//
/********************************************/
/*
author : Waleed Ebrahem
date :Sun Mar 16 07:06:15 PM CET 2025
brief:
*/

#include "Input.hpp"
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <thread>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

namespace sp {

enum class Key { CarEnter1, CarEnter2, CarExit1, CarExit2, NONE, Quit };

class TcpInput : public Input<Key> {
public:
    TcpInput(int port) : serverPort(port) {
        setupServer();
        listenerThread = std::thread([this] { listen(); });
    }

    ~TcpInput() {
        terminate();
        if (listenerThread.joinable()) {
            listenerThread.join();
        }

        close(serverSocket);
        std::cout << "TCP Input destructor\n";
    }

    Key get() override {
        std::lock_guard<std::mutex> lock(key_mutex);
        return key;
    }

    void terminate() override {
        quit = true;
        if (clientSocket >= 0) {
            close(clientSocket);
        }
    }

private:
    int serverSocket = -1, clientSocket = -1;
    int serverPort;
    std::thread listenerThread;
    std::mutex key_mutex;
    Key key = Key::NONE;
    bool quit = false;

    void setupServer() {
        serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (serverSocket == -1) {
            std::cerr << "Error creating socket\n";
            exit(EXIT_FAILURE);
        }

        sockaddr_in serverAddr{};
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_port = htons(serverPort);

        if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
            std::cerr << "Binding failed\n";
            exit(EXIT_FAILURE);
        }

        if (::listen(serverSocket, 5) < 0) {  // Allow multiple connections
            std::cerr << "Listening failed\n";
            exit(EXIT_FAILURE);
        }

        std::cout << "TCP Server started on port " << serverPort << std::endl;
    }

    void listen() override {
        while (!quit) {
            sockaddr_in clientAddr{};
            socklen_t clientLen = sizeof(clientAddr);
    
            clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientLen);
            if (clientSocket < 0) {
                if (quit) break;  // Exit loop if quitting
                std::cerr << "Accept failed\n";
                continue;
            }
            std::cout << "Client connected!\n";
    
            char buffer[1024];
            while (!quit) {
                memset(buffer, 0, sizeof(buffer));
                int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    
                if (bytesReceived <= 0) {
                    std::cout << "Client disconnected.\n";
                    break;
                }
    
                std::string receivedKey(buffer);
                if (receivedKey.empty()) continue; // Ignore empty messages
    
                Key keyPressed = mapKey(receivedKey);
                {
                    std::lock_guard<std::mutex> lock(key_mutex);
                    key = keyPressed;
                }
    
                // Process the key and reset it after a short delay
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                {
                    std::lock_guard<std::mutex> lock(key_mutex);
                    key = Key::NONE;  // Reset key after processing
                }
    
                if (keyPressed == Key::Quit) {
                    exit(0);
                }
            }
    
            close(clientSocket);
            clientSocket = -1;
        }
    }
    
    
    
    
    
    

    Key mapKey(const std::string &input) {
        if (input == "CarEnter1") return Key::CarEnter1;
        if (input == "CarEnter2") return Key::CarEnter2;
        if (input == "CarExit1") return Key::CarExit1;
        if (input == "CarExit2") return Key::CarExit2;
        if (input == "Quit") return Key::Quit;
        return Key::NONE;
    }
};

} // namespace sp
