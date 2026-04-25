//
// Created by 34254 on 2026/4/14.
//

#include "../Inc/BalanceCtrl.h"

BalanceCtrl balance_ctrl;
extern "C" {
}

BalanceCtrl::BalanceCtrl() :
                              pitch_pid_(UpPid(Angle_kp, 0.0f, Angle_kd, 2000, 1000)),
                             speed_pid_(SpeedPID(Speed_kp, Speed_ki, Speed_kd, 20, 10)),
                             turn_pid_(SpeedPID(0, 0, 0, 0, 0)),
                             target_speed_(0), left_output_(0), right_output_(0) {
}

void BalanceCtrl::update(const float pitch, const float diff_speed, const float average_speed, const float gyro, float dt) {
  pitch_pid_.uppid_set(Angle_kp, 0, Angle_kd);
  speed_pid_.SpeedPID_set(Speed_kp, Speed_ki, Speed_kd);
  float speed_output = speed_pid_.speed_PID_calculate(target_speed_, average_speed, dt);
  float angle_output = pitch_pid_.calculate(0, pitch,gyro, dt); //这里的零是机械中值
  float diff_output = turn_pid_.speed_PID_calculate(0, diff_speed, dt); // TODO! 脱线状态下应该以yaw角度环为外环
  left_output_ = std::clamp( speed_output+angle_output- diff_output/2,-2000.0f,2000.0f);
  right_output_ = std::clamp(speed_output+angle_output+ diff_output/2,-2000.0f,2000.0f);
}

void BalanceCtrl::clear() {
  left_output_ = 0;
  right_output_ = 0;
  speed_pid_.speed_PID_clear();
  turn_pid_.speed_PID_clear();
}