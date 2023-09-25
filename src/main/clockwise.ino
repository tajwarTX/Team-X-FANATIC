//void loop() {
//  monprint();
//  int stateButton = digitalRead(startButton);
//  Serial.println(stateButton);
//  if (stateButton == 1) {
//    state[0] = 1;
//  }
//  if (state[0] == 1) {
//    int disfr = frs.ping_cm();
//    int disrt = rts.ping_cm();
//    int dislt = lts.ping_cm();
//    int16_t gyroY = mpu.getRotationY();
//    int16_t gyroYChange = gyroY - initialGyroY;
//    float gyroY_deg_per_sec = gyroYChange / 131.0;
//    currentAngle += (gyroY_deg_per_sec * 0.001);
//    //Serial.println(currentAngle);
//    axis.write(m);
//    motor(sphigh);
//    flagCalibrate == 0;
//    //    obstacle(disfr,disrt, dislt,&flagCalibrate, &ignoreTurn);
//    if (flagCalibrate == 0) {
//      if ((currentAngle > -7) && (currentAngle < -3)) {
//        axis.write(85);
//        motor(spmid);
//      }
//      else if ((currentAngle > -2.5) && (currentAngle < 7)) {
//        axis.write(130);
//        motor(spmid);
//      }
//      else {
//        axis.write(m);
//        motor(spmid);
//      }
//    }
//
//    if ( (disrt != 0 || disrt > 90) && (dislt != 0 || dislt > 90)) {
//      int error = (dislt - disrt);
//      axis.write(constrain(map(error, -50, 50, 80, 120), 90, 110));
//    }
//
//
//
//    if ((disfr < 90 && disfr != 0) && (dislt > 70 || dislt == 0)) {
//      flagCalibrate == 1;
//      count[0] = count[0] + 1;
//      if ( count [0] != 12) {
//        axis.write(130);
//        motor(sphigh);
//        delay(300);
//        currentAngle = 0.0;
//        axis.write(m);
//        motor(sphigh);
//        delay(500);
//      }
//      else {
//        axis.write(130);
//        motor(sphigh);
//        delay(300);
//        axis.write(m);
//        motor(sphigh);
//        delay(900);
//        stp();
//        exit(0);
//      }
//    }
//  }
//  else if (state[0] == 0) {
//    Serial.println("bhai button click koren");
//  }
//}
