//
// Created by 34254 on 2026/4/15.
//

#ifndef BALANCE_CAR_CHASSISONLINE_H
#define BALANCE_CAR_CHASSISONLINE_H

#ifdef __cplusplus
#include "ChassisStrategy.h"
extern "C" {
#endif

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
class ChassisOnline : public ChassisStrategy{
  ChassisOnline(BalanceCtrl* b);
  void update() override;
};
#endif


#endif //BALANCE_CAR_CHASSISONLINE_H