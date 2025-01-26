
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
#include "Keyboard.hpp"
#include "Types.hpp"
#include "converter.hpp"
namespace sp {
class keyboardConverter : public Converter<Key> {
public:
  Actions convert(Key data) override {
    Actions action = Actions::NONE;
    if (data == Key::LControl1) {
      action = Actions::PARK_FIRST;
    } else if (data == Key::LControl2) {
      action = Actions::PARK_SECOND;
    } else if (data == Key::LAlt1) {
      action = Actions::UNPARK_FIRST;
    } else if (data == Key::LAlt2) {
      action = Actions::UNPARK_SECOND;
    } else {
    }
    return action;
  }
};
} // namespace sp
