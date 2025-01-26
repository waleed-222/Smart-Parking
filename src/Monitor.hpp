
#pragma once
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Sat Jan 25 09:35:16 PM CET 2025
brief:
*/
#include "Display.hpp"
#include <string>
namespace sp {
class Monitor : public Display {

public:
  Monitor();
  ~Monitor();

  void show(std::string msg) override;

private:
};
} // namespace sp
