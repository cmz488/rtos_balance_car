//
// Created by 34254 on 2026/4/15.
//

#include "../Inc/ChassisOnline.h"


#include <cmath>
#include <cstdint>

extern "C" {
}
extern int16_t todo_rename;

ChassisOnline::ChassisOnline(BalanceCtrl* b){
  balance_ctrl_ = b;
}

void ChassisOnline::update() {
  if (std::abs(todo_rename)<150) {
    balance_ctrl_->clear();
  }
}
