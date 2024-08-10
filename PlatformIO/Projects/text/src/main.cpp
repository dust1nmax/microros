#include <Arduino.h>
#include <micro_ros_platformio.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

rcl_allocator_t allocator;
rclc_support_t support;
rcl_node_t node;
rclc_executor_t executor;

void setup() {
  Serial.begin(115200);
  set_microros_serial_transports(Serial); //确认 micro-ros 使用串口通信
  delay(2000);
  allocator = rcl_get_default_allocator();
  rclc_support_init(&support, 0, NULL, &allocator);
  rclc_node_init_default(&node, "hello_mocroros", "", &support);
  rclc_executor_init(&executor, &support.context, 1, &allocator);
}

void loop() {
  delay(100);
  rclc_executor_spin_some(&executor,RCL_MS_TO_NS(100));
}

