//
// Created by 34254 on 2026/4/25.
//

#ifndef BALANCE_CAR_UPPID_H
#define BALANCE_CAR_UPPID_H

#ifdef __cplusplus
#include "PIDBase.h"
extern "C" {
#endif

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
class UpPid:public PIDbase{
  public:
  UpPid(float kp, float ki, float kd, float max_output, float integral_limit);
  float calculate(float target, float current, float gyro, float dt);
  void uppid_set(float kp, float ki, float kd) {
    PIDbase::PID_set(kp, ki, kd);
  };
};
#endif


#endif //BALANCE_CAR_UPPID_H