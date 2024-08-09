#ifndef __IMU_H__
#define __IMU_H__
#include "Wire.h"
#include "MPU6050.h"

typedef struct 
{
    float w;
    float x;
    float y;
    float z;
}quaternion_t;

typedef struct 
{
    float x;
    float y;
    float z;
}vector_3d_t;

typedef struct 
{
    quaternion_t orientation;
    vector_3d_t orientation_euler;
    vector_3d_t angular_velocity;
    vector_3d_t linear_acceleration;
}imu_t;

class imu
{
private:  
    MPU6050 &mpu_;
public:
    /**
     * 
     * 
     * @param mpu 
     * 
     */
    imu(MPU6050 &mpu);
    ~imu() = default;
    bool begin(int sda, int scl);
    void update();
    void Euler2Quaternion(float roll, float pitch, float yaw, quaternion_t &q);
    void getImuData(imu_t &imu);
};



#endif