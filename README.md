Documentation / PERANAUT / Team X-FANATIC
----
![bg](https://github.com/tajwarTX/Team-X-FANATIC/assets/136412241/c95aff3c-2e0b-4215-9a15-3e1359191f65)

### This repository is the collection of engineering materials pertaining to PERANAUT, a self-driving vehicle model developed by Team X-FANATIC, participating in the 2023 WRO Future Engineers competition (National Round).
----


## Team Members
Having a team of two members with specialized expertise in different sectors which gives us a significant advantage in the competition. Each of us can bring unique skills, perspectives, and knowledge to the table, which leads us to a more well-rounded and comprehensive approach to problem-solving or competition tasks.
>Mahir Tajwar Chowdhury  - Email: <tajwar185@gmail.com>
 
>Abrar Shahid - Email: <abrarshahidrahik@gmail.com>

----
<img align="left" alt="NAUT" width="320" src="https://github.com/tajwarTX/Team-X-FANATIC/assets/136412241/1cde1d49-0fbf-4b64-91f9-fa90e38e641f">

## Content

* `t-photos` contains team photos with all the members.
* `v-photos` contains photos of the robot from different angles.
* `video` contains all driving demonstrations of the robot (Drive link).
* `models` contains all the version samples and photos of the robot Peranaut.
* `src` contains all the code of the robot for all control systems and drive units.
* `other (preparation of the robot)` contains other files and essential documents to prepare the robot for the competition.
* `schemes` contains all the schematics of the custom circuit board and connections of all the electromechanical components present in the robot.

----
  ## Introduction / PERANAUT
 
The ATmega328-based Arduino Nano, which is compact, complete, and breadboard-friendly, powers the robot and allows it to control all of its components and adjust it to its surrounding environment. The Huskylens is being used to see red and green obstructions. The robot's orientation is determined using an MPU6050 gyroscope and accelerometer sensor.
To keep track of the number of laps, ultrasonic sensors are used in the robot and also to detect walls around it in the track.

----

## Components used in our robot PERANAUT

 <img align="right" alt="bleh" width="190" src="https://github.com/tajwarTX/Team-X-FANATIC/assets/136412241/44067f00-4899-4423-a721-315360c3bf8d">
 
+ Arduino Nano: Microcontroller based on the ATmega328
+ HC-SR04 Ultrasonic Sensors
+ MPU6050
+ Huskylens: AI machine vision sensor + lens
+ TB6612FNG Motor Driver
+ 12V 1000 RPM DC Geared Motor
+ 35KG digital servo motor DS3235
+ 2x Lm2596 Buck Converter
+ Capacitors
+ lights
+ buttons
+ 3S LiPo battery

----

# Algorithm Designing and Planning

When turning the robot for the first time, the chip initializes itself and sets up communication with the Huskylens and IMU sensor using the I2C protocol. The servo motor then centers itself once it is prepared and waits for the user to press the button. After that, the code is split into some sections:

### Initial run:

The initial section chooses the direction in which the robot will run, and In order to determine the direction of the run after it, the robot proceeds slowly through the first part and uses its sonar sensors. A high range of 70 cm from one of the sensors triggers the marking of the direction as either clockwise or anticlockwise.

### Clockwise/Anticlockwise Run:
Using some automatic calibration system, the robot runs on the track either in the clockwise direction or in the anti-clockwise direction. The calibration system is based on the ultrasonic sensors placed at three different angles of the robot and the MPU-6050 gyroscopic sensor, which works to make the robot steer in a straight line parallel to the walls on both sides.

### Avoiding walls in the whole run:

Based on the run direction identified in Part 1, we check the distance on both wall sides using an ultrasonic sensor in the first round to execute an auto-calibration code. The code slows down the front axle drive motor whenever a turn is initiated in an effort to keep the robot at a constant distance from the wall.
We employ effective algorithms to find a straight segment and a turn segment in order to finish the run precisely. In order to make its run considerably more precise, the robot then temporarily slows down its drive motor.

### Tackling the closest wall problems:

The robot rotates the servo in the other direction for a brief period of time if it detects a wall on any one of the sides in order to avoid colliding with the wall. It helps in the smooth run of the robot without any collusion in the wall.

### Avoiding obstacles in the whole run:

The Arduino nano receives the object's color ID and location in the X and Y axes when the huskylens identifies an object or is available. After that, the robot pursues the obstruction at an offset. That is, it follows on the right side of red barriers and on the left side of green obstacles. The front wheel is then turned proportionately to the item's distance (determined by height) and location on the screen's horizontal dimension once it is within the range of the object.

### Determining the end of the laps:

Integrating the rotational acceleration values on the Y-axis over time provides angular velocity information, which, when further integrated, yields the yaw angle of the robot. This approach allows the MPU6050 gyroscope sensor to determine the orientation of the robot in relation to the starting position, making it a valuable tool for navigation and orientation tasks. By integrating the rotational acceleration values on the Y axis over time and positioning the sensor so that the Y axis functions as the Z axis, the robot's gyroscope sensor, Mpu6050, can measure the yaw angle. By calibrating the initial position as zero during startup and incrementally tracking the yaw angle, the robot can accurately count laps based on predefined angle increments. Implementing a stop function after three laps are detected allows for autonomous lap counting and precise navigation, ensuring the robot can efficiently reach its designated endpoint and execute the stop command for a controlled termination of its mission.


The robot's initial position is set to zero when it is turned on for the first time. which has an impact on the lap count. For example, if the start angle is zero and 90 degrees are added for each turn, the total at the end of the lap is a full 360 degrees. We can teach the robot when to stop by applying the same technique to recognize the three laps. then, when the stop function has been activated, it continues to the designated area and executes the stop command again to end the 3 laps.

----
