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
#include "Display.hpp"
#include "Input.hpp"
#include "Keyboard.hpp"
#include "KeyboardConverter.hpp"
#include "Types.hpp"
#include "Updater.hpp"
#include <array>
#include <cstddef>
#include <memory>
#include <thread>
namespace sp {
// constexpr std::size_t FLOORS_COUNT =
//     static_cast<std::size_t>(Floors::NUM_FLOORS);
constexpr std::size_t PARKING_LOT_SIZE = 4;
using parking_type = std::array<int, NUM_FLOORS>;

// where T is the converter class and U is the input
template <typename T, typename U> class Parking {

public:
  Parking(T converter, std::unique_ptr<Input<U>> &input, Display &monitor);
  ~Parking();
  void park(Floors floor);
  void unpark(Floors floor);
  void close() { quit = true; }

private:
  parking_type parkinglot_available{PARKING_LOT_SIZE, PARKING_LOT_SIZE};
  std::thread t1_executer;
  Updater<parking_type> updater;
  std::unique_ptr<Input<U>> &input;
  bool quit = false;
  T converter;
};

extern template class Parking<keyboardConverter,
                              Key>; // this only because i wrote template in cpp

} // namespace sp
