
#pragma once
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Sat Jan 25 08:15:06 PM CET 2025
brief:
*/
#include "Input.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <mutex>
#include <thread>
namespace sp {
enum class Key { LControl1, LControl2, LAlt1, LAlt2, NONE };
class keyboard : public Input<Key> {

public:
  keyboard() {
    t1_listners = std::thread([this] { this->listen(); });
  }
  ~keyboard() {
    if (t1_listners.joinable()) {
      t1_listners.join();
    }

    std::cout << "keyboard destructor\n";
  }
  Key get() override {
    std::unique_lock<std::mutex> lock(key_mutex);
    Key keypressed = key;
    lock.unlock();
    return keypressed;
  }
  void terminate() override { quit = true; }

private:
  void listen() override {
    while (!quit) {
      Key keypressed = Key::NONE;

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) &&
          sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        keypressed = Key::LControl1;
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) &&
                 sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        keypressed = Key::LControl2;
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) &&
                 sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        keypressed = Key::LAlt1;
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) &&
                 sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        keypressed = Key::LAlt2;
      } else {
      }

      std::unique_lock<std::mutex> lock(key_mutex);
      key = keypressed;
      lock.unlock();
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
  }
  Key key;
  std::mutex key_mutex;
  std::thread t1_listners;
  bool quit = false;
};
} // namespace sp
