//
// Created by 34254 on 2026/2/12.
//

#include <cmath>

#include "../Inc/AnglePid.h"
#include "cmath"

extern "C" {
}

AnglePID::AnglePID(const float kp, const float ki, const float kd, const float maxOut,
                   const float maxIntegral) : PIDbase(kp, ki, kd, maxOut, maxIntegral), offset(4.0f) {
}
void AnglePID::AnglePID_set(const float kp, const float ki, const float kd) {
  PIDbase::PID_set(kp, ki, kd);
}
float AnglePID::AnglePID_Calculate(const float target, const float current, const float dt) {
  const float error = target - current; //计算当前错误

  if (pretarget * target < 0) {
    integral = 0.0f;
  } // 过零处理
float der = (error - precError) / dt;
  float output = Kp * error + Kd * der;
  if (output < max_output && output > -max_output) {
    integral += Ki * error * dt;
    integral = std::clamp(integral, -max_integral, max_integral);
  }
  output += integral;

  if (fabsf(output) > 0.01f) {
    if (output > 0.0f)  output += offset;
    else output -= offset;
  }
  output = std::clamp(output, -max_output, max_output);

  precError = error;
  pretarget = target;
  last_current = current;
  return output;
}
