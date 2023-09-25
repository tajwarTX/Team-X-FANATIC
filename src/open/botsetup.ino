void monprint() {
  int disfr = frs.ping_cm();
  int disrt = rts.ping_cm();
  int dislt = lts.ping_cm();
  Serial.print(" Front: ");
  Serial.print(disfr);
  Serial.print("    left: ");
  Serial.print(dislt);
  Serial.print("      right: ");
  Serial.print(disrt);
  Serial.println(" cm");
}

void deci() {

//  motor(spmid);
//  if (disfr < 50 && disfr != 0) {
//    stp();
//  }
//  if (decision[0] == 0) {
//    if ((disfr < 120 ) && (dislt == 0 || dislt > 85)) {
//      axis.write(140);
//      motor(sphigh);
//      delay(370);
//      fwd();
//      delay(1000);
//      decision[0] = 1;
//
//    }
//    if ((disfr < 120 ) && (disrt == 0 || disrt > 85)) {
//      axis.write(65);
//      motor(sphigh);
//      delay(570);
//      fwd();
//      delay(1000);
//      decision[0] = 2;
//
//    }
//  }
//  else if (decision[0] == 1) {
//    //  anticlockwise(dislt, disfr, disrt, 140, 320);
//  }
//
//  else if (decision[0] == 2) {
//    //  clockwise(dislt, disfr, disrt, 140, 320);
//  }
//  //   turn(dislt);
//
//  obstacle();
}
