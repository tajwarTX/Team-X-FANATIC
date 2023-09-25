void anticlockwise(int disfr, int disrt, int dislt,  float *currentAngle, int *flagCalibrate) {
  *flagCalibrate = 0;
  motor(165);
  if (disfr < 80 && disfr != 0) {
    motor(120);
  }
  if ((disfr < 90 && disfr != 0) && (dislt > 70 || dislt == 0)) {
    *flagCalibrate = 1;
    count[0] = count[0] + 1;
    if ( count [0] != 12) {
      axis.write(130);
      motor(120);
      *currentAngle = 0.0;
      delay(340);
      axis.write(m);
      motor(165);
      delay(500);
    }
    else {
      axis.write(130);
      motor(120);
      delay(340);
      axis.write(m);
      motor(165);
      delay(750);
      stp();
      exit(0);
    }
  }
  else {
    int error = (dislt - disrt);
    if (abs(error) < 90) {
      axis.write(constrain(map(error, -80, 80, 90, 115), 90, 115));
    }
    else {
      if (disrt < dislt) {
        axis.write(115);
      }
      else if (dislt < disrt) {
        axis.write(90);
      }
      else {
        motor(0);
      }
    }
  }

  //  if (*flagCalibrate == 0) {
  //    Serial.println("calibbbbrrrraaaaaa");
  //    if ((*currentAngle > -7) && (*currentAngle < -1.5)) {
  //      axis.write(95);
  //      motor(200);
  //    }
  //    else if ((*currentAngle > -1) && (*currentAngle < 7)) {
  //      axis.write(103);
  //      motor(200);
  //    }
  //    else {
  //      axis.write(99);
  //      motor(255);
  //    }
  //  }


}
