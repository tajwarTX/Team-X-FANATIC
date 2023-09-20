Documentation / Team X-FANATIC
----

![bg](https://github.com/tajwarTX/Team-X-FANATIC/assets/136412241/a765bea4-70ed-4f82-979a-b2137f6febfd)
### This repository is the collection of engineering materials pertains to PERANAUT, a self-driving vehicle model developed by Team X-FANATIC, participating in the 2023 WRO Future Engineers competition (National Round).
----

## Team Members

- Mahir Tajwar Chowdhury - email: <tajwar185@gmail.com>
- Abrar Shahid - email: <abrarshahidrahik@gmail.com>

----
<img align="left" alt="NAUT" width="260" src="https://github.com/tajwarTX/Team-X-FANATIC/assets/136412241/c826f894-4ba4-4ae7-a872-7e6bfae7c387">

## Content

* `t-photos` contains team photos with all the members.
* `v-photos` contains photos of the robot from different angles.
* `video` contains all driving demonstrations of the robot (Drive link).
* `src` contains all the code of the robot for all control systems and drive units.
* `other` contains other files and essential documents to prepare the robot for the competition.
* `schemes` contains all the schematics of the custom circuit board and connections of all the electromechanical components present in the robot.

----
  ## Introduction

<img align="right" alt="bleh" width="250" src="https://github.com/tajwarTX/Team-X-FANATIC/assets/136412241/c2fe084c-ac93-4350-91d2-58cf4e58633e">

The ATmega328-based Arduino Nano, a compact, feature-rich, and breadboard-friendly board, powers the robot and allows it to control all of its actuators and adapt to its surroundings. To see the red/green obstacles, it is employing the Huskylens. The robot's orientation is determined using an MPU6050 gyroscope and accelerometer sensor. The robot also has an ultrasonic sensor to count laps and detect barriers.



  # Program arrangement and Algorithm Planning

  The robot is running on an ESP32-based development board called the JRC board locally made in our country to run all the actuators and sense the environment. It is using the Huskylens 
  to see the red/green obstacles as well as the corner lines (blue/orange). An MPU6050 gyroscope and accelerometer sensor are used to detect the orientation of the robot and count laps.

  When the robot is first powered on with the battery, it initializes the chip and starts communicating with the Huskylens and IMU sensor. Once it is ready, the servo motor gets 
  centered and it waits for the user to push the button. The code is then divided into three major parts - 

### Part 1 - Detecting run direction:

The first part determines the direction of the robot run. The robot moves slowly through the first straightforward section to ensure it can safely detect the direction of the run with its sonar sensors. Once it detects a large distance (>90cm) from one of the sensors, it marks the direction as “L” - clockwise, or “R”  - anti-clockwise accordingly.

### Part 2 - Completing the run as fast as possible:

In this part, we run a PID loop (1st round) or a proportional+obstacle avoiding code(2nd round) to complete the run as fast as possible. 

### **Wall avoidance:**

In the first round, we only check the sonar on the inner wall side (based on the direction of run detected from Part 1) to run a PID (proportional, integral, derivative) code. The code tries to keep the robot at a fixed distance from the wall while slowing down the rear axle drive motor whenever a turn is initiated.
To complete this part as fast as possible, we use smart algorithms to detect when the robot has just finished a turning section and is about to enter a straight section. The robot then spins the drive motor at maximum speed for a short period of time (40-50mS) to give the robot a great acceleration or “boost”.

In the 2nd round, however, we decided to disable the boost and changed PID control to just P or proportional to keep the robot centered on the track, which is sufficient at the slow speed of the robot.
