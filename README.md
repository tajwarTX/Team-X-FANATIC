Documentation / Team X-FANATIC
----

![bg](https://github.com/tajwarTX/Team-X-FANATIC/assets/136412241/a765bea4-70ed-4f82-979a-b2137f6febfd)
### This repository is the collection of engineering materials pertaining to PERANAUT, a self-driving vehicle model developed by Team X-FANATIC, participating in the 2023 WRO Future Engineers competition (National Round).
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
  <img align="right" alt="bleh" width="200" src="https://github.com/tajwarTX/Team-X-FANATIC/assets/136412241/c2fe084c-ac93-4350-91d2-58cf4e58633e">
The ATmega328-based Arduino Nano, which is compact, complete, and breadboard-friendly, powers the robot and allows it to control all of its components and adjust it to its surrounding environment. The Huskylens is being used to see red and green obstructions. The robot's orientation is determined using an MPU6050 gyroscope and accelerometer sensor.
To keep track of the number of laps, ultrasonic sensors are used in the robot and also to detect walls around it in the track.



# Program arrangement and Algorithm Planning

When turning the robot for the first time, the chip initializes itself and sets up communication with the Huskylens and IMU sensor using the I2C protocol. The servo motor then centers itself once it is prepared and waits for the user to press the button. After that, the code is split into three main sections:

### Part 1 - Determining the Run Direction:

The initial section chooses the direction in which the robot will run and In order to determine the direction of the run after it, the robot proceeds slowly through the first part and uses its sonar sensors. A high range of 70 cm from one of the sensors triggers the marking of the direction as either clockwise or anticlockwise.

### Part 2 - Clockwise/Anticlockwise Run:
Using some Automatic calibration system, the robot runs on the track either in the clockwise direction or in the anti-clockwise direction. The calibration system is based on the ultrasonic sensors placed at three different angles of the robot and the MPU-6050 gyroscopic sensor which works to make the robot steer in a straight line parallel to the walls on both sides.

### Part 3 - Wall avoidance:

In the first round, we only check the sonar on the inner wall side (based on the direction of run detected from Part 1) to run a PID (proportional, integral, derivative) code. The code tries to keep the robot at a fixed distance from the wall while slowing down the rear axle drive motor whenever a turn is initiated.
To complete this part as fast as possible, we use smart algorithms to detect when the robot has just finished a turning section and is about to enter a straight section. The robot then spins the drive motor at maximum speed for a short period of time (40-50mS) to give the robot a great acceleration or “boost”.

In the 2nd round, however, we decided to disable the boost and changed PID control to just P or proportional to keep the robot centered on the track, which is sufficient at the slow speed of the robot.
