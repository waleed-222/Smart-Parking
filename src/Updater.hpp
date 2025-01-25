
#pragma once
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Sat Jan 25 08:56:31 PM CET 2025
brief:
*/
#include "Monitor.hpp"
namespace sp {
template <typename T> class Updater {

public:
  Updater() {}
  ~Updater() {}
  void update(T parkinglot_available) {
    Monitor monitor;
    std::string msg =
        "First Floor: " + std::to_string(parkinglot_available[0]) +
        " Second Floor: " + std::to_string(parkinglot_available[1]);
    monitor.show(msg);
  }

private:
};
} // namespace sp
  // Explicit instantiation of the template if you want to move impl to cpp
  // template class sp::Updater<std::array<int, 2>>;