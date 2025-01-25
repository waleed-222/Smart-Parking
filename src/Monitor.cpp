
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Sat Jan 25 09:35:19 PM CET 2025
brief:
*/
#include "Monitor.hpp"
#include <iostream>
namespace sp {
Monitor::Monitor() {}
Monitor::~Monitor() {}

void Monitor::show(std::string message) {
  std::system("clear");
  std::cout << message << std::endl;
}

} // namespace sp
