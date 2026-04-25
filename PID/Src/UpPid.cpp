//
// Created by 34254 on 2026/4/25.
//

#include "../Inc/UpPid.h"
#include "cmath"

extern "C" {
}
UpPid::UpPid(float kp, float ki, float kd, float max_output, float integral_limit) :PIDbase(kp, ki, kd, max_output, integral_limit) {
}
float UpPid::calculate(float target, float current, float gyro, float dt) {
  const float error = target - current; //计算当前错误

  if (pretarget * target < 0) {
    integral = 0.0f;
  } // 过零处理
  float der = (gyro - 0); //对角速度进行
  float output = Kp * error + Kd * der;
  if (output < max_output && output > -max_output) {
    integral += Ki * error * dt;
    integral = std::clamp(integral, -max_integral, max_integral);
  }
  output += integral;
  output = std::clamp(output, -max_output, max_output);
  precError = error;
  pretarget = target;
  return output;
}