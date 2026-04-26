//
// Created by 34254 on 2026/2/12.
//

#include "../Inc/Mpu6050Task.h"
#include <cmath>
#include <array>
#include "FusionAHRS.h"
#define DT 0.005f //单位秒
#define MY_PI 3.14159265358979323846f
#define lb 0.95238    //合成角度滤波
extern "C" {
#include "MPU6050.h"
#include "MPU6050_Reg.h"
#include "inv_mpu.h"
static MPU6050Task mpu6050Task; // 创建 MPU6050 任务实例
void MPU6050_Task() {
  mpu6050Task.start(const_cast<char *>("mpu6050Task"), 2048, osPriorityAboveNormal); // 启动 MPU6050 任务
}
}

int16_t a_raw[3];
float a_real[3];
int16_t g_raw[3];
float g_real[3];
float pitch1;
float roll1;
float yaw1;
float pitch,roll,yaw;
float pa,ra,ya;
std::array<float, 4> q = {1, 0, 0, 0};
extern FusionAHRS fusionAHRS;

void MPU6050Task::run() {
  for (;;) {
    //计算pitch
    MPU6050_GetData(&a_raw[0], &a_raw[1], &a_raw[2], &g_raw[0], &g_raw[1], &g_raw[2]);
    for (uint8_t i = 0; i < 3; i++) {
      a_real[i] = a_raw[i] * ACCL_RAW_TO_REAL_4G;
      g_real[i] = g_raw[i] * GYRO_RAW_TO_REAL_250degree;
    }
    fusionAHRS.update(g_real[0] / 180.0f * MY_PI, g_real[1] / 180.0f * MY_PI, g_real[2] / 180.0f * MY_PI, a_real[0],
                      a_real[1], a_real[2]);
    q = fusionAHRS.getQuaternion();
    roll1 = atan2f(2.0f * (q[0] * q[1] + q[2] * q[3]), 1.0f - 2.0f * (q[1] * q[1] + q[2] * q[2])) / MY_PI * 180.0f;
    pitch1 = asinf(2.0f * (q[0] * q[2] - q[3] * q[1])) / MY_PI * 180;
    yaw1 = atan2f(2.0f * (q[0] * q[3] + q[1] * q[2]), 1.0f - 2.0f * (q[2] * q[2] + q[3] * q[3])) / MY_PI * 180;
      pa = atan2f(a_real[0], a_real[2]) / MY_PI * 180.0f;
      ra = atan2f(-a_real[0], sqrtf(a_real[1] * a_real[1] + a_real[2] * a_real[2])) / MY_PI * 180.0f;
      ya = atan2f(g_real[1], g_real[0]) / MY_PI * 180.0f;
      pitch = lb * (pitch + g_real[0] * DT) + (1 - lb) * pa;
      roll = lb * (roll + g_real[1] * DT) + (1 - lb) * ra;
      yaw = lb * (yaw + g_real[2] * DT) + (1 - lb) * ya;
    osDelay(DT*1000);
  }
}
