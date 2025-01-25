
#pragma once
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Sat Jan 25 09:35:04 PM CET 2025
brief:
*/
namespace sp {
template <typename T> class Display {

public:
  virtual ~Display() = default;
  virtual void show(T msg) = 0;

private:
};
} // namespace sp
