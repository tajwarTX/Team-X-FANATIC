Documentation / PERANAUT / Team X-FANATIC
----

![bg](https://github.com/tajwarTX/Team-X-FANATIC/assets/136412241/a765bea4-70ed-4f82-979a-b2137f6febfd)
### This repository is the collection of engineering materials pertaining to PERANAUT, a self-driving vehicle model developed by Team X-FANATIC, participating in the 2023 WRO Future Engineers competition (National Round).
----
<img align="right" alt="NAUT" width="228" src="https://github.com/tajwarTX/Team-X-FANATIC/assets/136412241/38051223-f6f4-48ce-9a29-e6bd14254239">

## Team Members
Having a team of two members with specialized expertise in different sectors which gives us a significant advantage in the competition. Each of us can bring unique skills, perspectives, and knowledge to the table, which leads us to a more well-rounded and comprehensive approach to problem-solving or competition tasks.
>Mahir Tajwar Chowdhury  - Email: <tajwar185@gmail.com>
 
>Abrar Shahid - Email: <abrarshahidrahik@gmail.com>


----
<img align="left" alt="NAUT" width="260" src="https://github.com/tajwarTX/Team-X-FANATIC/assets/136412241/c826f894-4ba4-4ae7-a872-7e6bfae7c387">

## Content

* `t-photos` contains team photos with all the members.
* `v-photos` contains photos of the robot from different angles.
* `video` contains all driving demonstrations of the robot (Drive link).
* `src` contains all the code of the robot for all control systems and drive units.
* `other (preparation of the robot)` contains other files and essential documents to prepare the robot for the competition.
* `schemes` contains all the schematics of the custom circuit board and connections of all the electromechanical components present in the robot.

----
  ## Introduction / PERANAUT
  <img align="right" alt="bleh" width="210" src="https://github.com/tajwarTX/Team-X-FANATIC/assets/136412241/c2fe084c-ac93-4350-91d2-58cf4e58633e">
The ATmega328-based Arduino Nano, which is compact, complete, and breadboard-friendly, powers the robot and allows it to control all of its components and adjust it to its surrounding environment. The Huskylens is being used to see red and green obstructions. The robot's orientation is determined using an MPU6050 gyroscope and accelerometer sensor.
To keep track of the number of laps, ultrasonic sensors are used in the robot and also to detect walls around it in the track.

----

## Components used in our robot PERANAUT

+ Arduino Nano: Microcontroller based on the ATmega328
+ Huskylens: AI machine vision sensor
+ HC-SR04 Ultrasonic Sensors
+ 12V 1000 RPM DC Geared Motor
+ 35KG digital servo motor DS3235
+ TB6612FNG Motor Driver
+ MPU6050
+ 2x Lm2596 Buck Converter
+ 3S LiPo battery

----

# Program arrangement and Algorithm Planning

When turning the robot for the first time, the chip initializes itself and sets up communication with the Huskylens and IMU sensor using the I2C protocol. The servo motor then centers itself once it is prepared and waits for the user to press the button. After that, the code is split into some sections:

### 1 - Determining the Run Direction:

The initial section chooses the direction in which the robot will run and In order to determine the direction of the run after it, the robot proceeds slowly through the first part and uses its sonar sensors. A high range of 70 cm from one of the sensors triggers the marking of the direction as either clockwise or anticlockwise.

### 2 - Clockwise/Anticlockwise Run:
Using some Automatic calibration system, the robot runs on the track either in the clockwise direction or in the anti-clockwise direction. The calibration system is based on the ultrasonic sensors placed at three different angles of the robot and the MPU-6050 gyroscopic sensor which works to make the robot steer in a straight line parallel to the walls on both sides.

### 3 - Wall avoidance:

Based on the run direction identified in Part 1, we check the distance on both wall sides using an ultrasonic sensor in the first round to execute an auto-calibration code. The code slows down the front axle drive motor whenever a turn is initiated in an effort to keep the robot at a constant distance from the wall.
We employ effective algorithms to find a straight segment and a turn segment in order to finish the run precisely. In order to make its run considerably more precise, the robot then temporarily slows down its drive motor.

In the 2nd round, however, we decided to disable the boost and changed PID control to just P or proportional to keep the robot centered on the track, which is sufficient at the slow speed of the robot.

### **Obstacle avoidance:**

The arduino nano receives the object's colour ID and location in the X and Y axes when the huskylens identifies an object or is available. After that, the robot pursues the obstruction at an offset. That is, it follows on the right side of red barriers and on the left side of green obstacles. The front wheel is then turned proportionately to the item's distance (determined by height) and location on the screen's horizontal dimension once it is within the range of the object.

### Wall collision protection:

If the robot detects a wall within 8cm of one of the sides, it rotates the servo in the other direction for a few milliseconds to keep the robot from hitting the wall.

### 3 - Detecting the end of 3 laps:

The robot equips a gyroscope sensor to measure the yaw angle by integrating the rotational acceleration values on the Z axis over time. Gyroscope sensors are infamous for drift in the angle over time, but our robot runs for such a short time that it does not affect its performance.

When the start button is pressed, the robot is at a zero-degree angle starting position. After each lap of the track, the robot spins 360 degrees. So we can detect the completion of three laps as soon as the robot completes 3x360 or 1080 degrees turn (+/- 20 degrees to compensate for errors). 
However, the robot is not instantly stopped, since it may not have reached the straightforward section. We start waiting for the Huskylens to detect a blue or orange line in front of it and stop instantly with a short backward pulse to the drive motor (hard break).

----
