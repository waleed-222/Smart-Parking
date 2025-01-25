
#pragma once
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Sat Jan 25 08:39:59 PM CET 2025
brief:
*/
#include "Input.hpp"
#include "Keyboard.hpp"
#include "Updater.hpp"
#include <array>
#include <cstddef>
#include <memory>
#include <thread>
namespace sp {
enum Floors { FIRST, SECOND, NUM_FLOORS };
// constexpr std::size_t FLOORS_COUNT =
//     static_cast<std::size_t>(Floors::NUM_FLOORS);
constexpr std::size_t PARKING_LOT_SIZE = 4;
using parking_type = std::array<int, NUM_FLOORS>;
class Parking {

public:
  Parking(std::unique_ptr<Input<Key>> &input);
  ~Parking();
  void park(Floors floor);
  void unpark(Floors floor);
  void close() { quit = true; }

private:
  parking_type parkinglot_available{PARKING_LOT_SIZE, PARKING_LOT_SIZE};
  std::thread t1_executer;
  Updater<parking_type> updater;
  std::unique_ptr<Input<Key>> &input;
  bool quit = false;
};

} // namespace sp
