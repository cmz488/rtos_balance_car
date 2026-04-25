//
// Created by 34254 on 2026/4/10.
//

#ifndef BALANCE_CAR_CHASSISSTATEGY_H
#define BALANCE_CAR_CHASSISSTATEGY_H

#ifdef __cplusplus
#include "BalanceCtrl.h"
extern "C" {
#endif

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
class ChassisStrategy {
protected:
  BalanceCtrl*  balance_ctrl_{nullptr};
public:
  virtual ~ChassisStrategy() = 0;
  virtual void update();
};
#endif


#endif //BALANCE_CAR_CHASSISSTATEGY_H