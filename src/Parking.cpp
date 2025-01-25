
/********************************************/
//
//              CopyRight Moatasem Elsayed
//
/********************************************/
/*
author : Moatasem Elsayed
date :Sat Jan 25 08:40:00 PM CET 2025
brief:
*/
#include "Parking.hpp"

namespace sp {
Parking::Parking(std::unique_ptr<Input<Key>> &input) : input(input) {
  t1_executer = std::thread([this] {
    while (!quit) {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      this->input->get();
      if (this->input->get() == Key::LControl1) {
        this->park(Floors::FIRST);
      } else if (this->input->get() == Key::LControl2) {
        this->park(Floors::SECOND);
      } else if (this->input->get() == Key::LAlt1) {
        this->unpark(Floors::FIRST);
      } else if (this->input->get() == Key::LAlt2) {
        this->unpark(Floors::SECOND);
      } else {
      }
      this->updater.update(parkinglot_available);
    }
  });
}
Parking::~Parking() {
  if (t1_executer.joinable()) {
    t1_executer.join();
  }
}

void Parking::park(Floors floor) {
  if (floor < Floors::NUM_FLOORS) {
    if (parkinglot_available[floor] > 0) {
      parkinglot_available[floor]--;
    }
  }
}

void Parking::unpark(Floors floor) {
  if (floor < Floors::NUM_FLOORS) {
    if (parkinglot_available[floor] < PARKING_LOT_SIZE) {
      parkinglot_available[floor]++;
    }
  }
}
} // namespace sp