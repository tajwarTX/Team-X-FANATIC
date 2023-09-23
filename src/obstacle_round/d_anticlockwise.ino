void anticlockwise(int dislt, int disfr, int disrt, int angle, int delaytime) {

  //  if (disfr < 100 && disfr != 0) {
  //    count[0] = count[0] + 1;
  //    if ( count [0] != 11) {
  //      axis.write(angle);
  //      motor(sphigh);
  //      delay(delaytime);
  //      axis.write(m);
  //      motor(sphigh);
  //      delay(1000);
  //    }
  //    else {
  //      axis.write(angle);
  //      motor(sphigh);
  //      delay(delaytime);
  //      axis.write(m);
  //      motor(sphigh);
  //      delay(750);
  //      stp();
  //      exit(0);
  //    }
  //  }
  //  if (disfr < 120 && disfr != 0) {
  //    stp();
  //  }

  if ((dislt != 0 && disrt != 0) && (disfr > 110 )) {

    if ((dislt >= 0) && (dislt <= 10)) {
      axis.write(94);
      motor(sphigh);
    }
    else if (disrt >= 0 && disrt <= 10) {
      axis.write(110);
      motor(sphigh);
    }
  }
}
