#include <NewPing.h>
#include <Servo.h>
#include <Wire.h>
#include <MPU6050.h>
#include "HUSKYLENS.h"
#include "SoftwareSerial.h"


#define right_motor_forward 8
#define right_motor_backward 7
#define right_motor_speed 6

#define MAX_DISTANCE 200
#define trigger_fr  5
#define echo_fr  4

#define trigger_right  12
#define echo_right  11

#define trigger_left  2
#define echo_left  3
#define startButton 9

NewPing frs(trigger_fr, echo_fr, MAX_DISTANCE);
NewPing rts(trigger_right, echo_right, MAX_DISTANCE);
NewPing lts(trigger_left, echo_left, MAX_DISTANCE);
Servo axis;

MPU6050 mpu;
int16_t initialGyroY;
float currentAngle = 0.0;

HUSKYLENS huskylens;
void printResult(HUSKYLENSResult result);

int sphigh = 170, r = 60, l = 140, m = 101 , rb = 60 , lb = 130, splow = 140, spmid = 110; // r = servo right , l = servo left , m = servo middleint count[1] = {0};
int ignoreTurn = 0;
int decision[1] = {0};
int axisdeci[1] = {0};
int isTurned[1] = {0};
int incrementTurn[1] = {0};
int flagCalibrate = 0;
//int turnAngle = 1.99;
int turnAngle = 2.5;
int state[1] = {0};
int section = 0;
int turnangle = 0;
int count[1] = {0};
unsigned long startTime = 0;
void setup() {

  pinMode(right_motor_forward, OUTPUT);
  pinMode(right_motor_backward, OUTPUT);
  pinMode(right_motor_speed, OUTPUT);
  pinMode(trigger_fr, OUTPUT);
  pinMode(echo_fr, INPUT);
  pinMode(trigger_left, OUTPUT);
  pinMode(echo_left, INPUT);
  pinMode(trigger_right, OUTPUT);
  pinMode(echo_right, INPUT);
  pinMode(startButton, INPUT_PULLUP);
  axis.attach(13);
  axis.write(m);

  Wire.begin();
  mpu.initialize();
  mpu.setFullScaleGyroRange(0);
  initialGyroY = mpu.getRotationY();

  Serial.begin(9600);

  Wire.begin();
  while (!huskylens.begin(Wire))
  {
    Serial.println(F("Begin failed!"));
  }
  delay(1000);
}

void loop() {
  unsigned long currentTime = millis();
  int stateButton = digitalRead(startButton);
  if (stateButton == 1) {
    state[0] = 1;
  }
  if (state[0] == 1) {
    int disfr = frs.ping_cm();
    int disrt = rts.ping_cm();
    int dislt = lts.ping_cm();
        Serial.print("    Front: ");
        Serial.print(disfr);
        Serial.print("    left: ");
        Serial.print(dislt);
        Serial.print("    right: ");
        Serial.print(disrt);
        Serial.println(" cm");

    int16_t gyroY = mpu.getRotationY();
    int16_t gyroYChange = gyroY - initialGyroY;
    float gyroY_deg_per_sec = gyroYChange / 131.0;
    currentAngle += (gyroY_deg_per_sec * 0.001);
    //    monprint();
    axis.write(m);
    motor(spmid);
    flagCalibrate == 0;
    obstacle(disfr, disrt, dislt, &flagCalibrate, &ignoreTurn, &startTime);
  }

  else if (state[0] == 0) {
    Serial.println("Button OFF");
  }
}
