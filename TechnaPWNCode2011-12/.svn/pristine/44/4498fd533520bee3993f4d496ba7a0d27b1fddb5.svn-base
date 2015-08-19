#pragma config(Sensor, in2,    rightEncoder,        sensorVirtual)
#pragma config(Sensor, in3,    leftEncoder,         sensorVirtual)
#pragma config(Sensor, in5,    lineFollower,        sensorVirtual)
#pragma config(Sensor, in6,    touch,               sensorVirtual)
#pragma config(Sensor, in7,    compass,             sensorVirtual)
#pragma config(Sensor, in8,    sonar,               sensorVirtual)
#pragma config(Motor,  port1,           gripper,       tmotorNormal, openLoop)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)

task main()
{
  int target_value = 800;
  int target_power = 50;
  int kp = 1000;
  int ki = 1;
  int kd = 1000;
  int past_derivative = 0;
  int derivative = 0;
  int light_value = 0;
  int error = 0;
  int integer = 0;
  int g = 4;
  int g = g + 8;
  int v = 4;
  v = v + 8;
  while (1==1)
  {
    light_value = SensorValue(lineFollower);
    error = light_value - target_value;
    integer = (integer * (2 / 3)) + error;
    int derivative = past_derivative - derivative;
    int corrected_error = (error * kp) + (integer*ki)+(derivative*kd);
    motor[leftMotor] = target_power - corrected_error;
    motor[rightMotor] = target_power + corrected_error;
    int past_derivative = derivative;
  }
}
