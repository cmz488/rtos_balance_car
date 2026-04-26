//
// Created by 34254 on 2026/2/12.
//

#include "../Inc/Debug.h"
#include "../serial/Inc/Serial.h"

extern "C" {
void Debug_Task() {
  static debug debugTask; // 创建 debug 任务实例
  debugTask.start((char *) "debugTask", 256, osPriorityLow); // 启动 debug 任务
}
}
extern float angle_speed_kp;
extern float angle_speed_ki;
extern float angle_speed_kd;
extern float Angle_kp, Angle_ki, Angle_kd;
extern float Speed_kp, Speed_ki, Speed_kd;
extern float pitch1;
extern Serial serial;
extern int16_t left_pwm, right_pwm;
extern float pitch,roll,yaw;

void debug::run() {
  serial.receive_init();
  serial.relocate({&Angle_kp, &Speed_kp}, {&Angle_ki, &Speed_ki}, {&Angle_kd, &Speed_kd});
  for (;;) {
    serial.write(
      pitch,pitch1, roll,Angle_kp, Angle_ki, Angle_kd, Speed_kp, Speed_ki, Speed_kd, left_pwm, right_pwm
    );
    osDelay(10);
  }
}
