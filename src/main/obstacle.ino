void printResult(HUSKYLENSResult result) {
  if (result.command == COMMAND_RETURN_BLOCK) {
    Serial.println(String() + F("Block:xCenter=") + result.xCenter + F(",yCenter=") + result.yCenter + F(",width=") + result.width + F(",height=") + result.height + F(",ID=") + result.ID);
  }
  else if (result.command == COMMAND_RETURN_ARROW) {
    Serial.println(String() + F("Arrow:xOrigin=") + result.xOrigin + F(",yOrigin=") + result.yOrigin + F(",xTarget=") + result.xTarget + F(",yTarget=") + result.yTarget + F(",ID=") + result.ID);
  }
  else {
    Serial.println("Object unknown!");
  }
}




void obstacle(int disfr, int disrt, int dislt, int *flagCalibrate, int decision) {

  if (!huskylens.request()) Serial.println(F(" "));
  else if (!huskylens.isLearned()) Serial.println(F("Nothing learneda"));
  else {
    if (huskylens.available()) {

      HUSKYLENSResult result = huskylens.read();
      int xAxis = result.xCenter;
      if (decision == 1) {
        if (result.ID == 1 ) {
          Serial.println("green");
          axis.write(map(xAxis, 50, 280, 125 , 110));

          //        delay(150);
          //        axis.write(m);

        }
        else if (result.ID == 2) {

          axis.write(map(xAxis, 50, 280, 85, 70 ));

        }
      }
      else if (decision == 2 ) {
        if (result.ID == 1 ) {
          axis.write(map(xAxis, 50, 280, 135 , 120));
        }
        else if (result.ID == 2) {
          axis.write(map(xAxis, 50, 280, 95, 80 ));
        }
      }
    }

    else {
      if (decision == 1) {

        if ( (disfr <= 90 && disfr != 0) && (dislt > 70 || dislt == 0)) { //&& (dislt+disrt >= 100 && dislt+disrt <= 200)) {
          axis.write(135);
        }
        else {
          int error = dislt - disrt;
          if (abs(error) > 120 && disfr > 80 ) {
            stp();
          }
          axis.write(constrain(map(error, -80, 80, 70, 135), 70, 135));
        }
      }
      else if (decision == 2) {

        if ( (disfr <= 90 && disfr != 0) && (disrt > 70 || disrt == 0)) { //&& (dislt+disrt >= 100 && dislt+disrt <= 200)) {
          axis.write(65);
        }
        else {
          int error = dislt - disrt;
          if (abs(error) > 120 && disfr > 80 ) {
            stp();
          }
          axis.write(constrain(map(error, -80, 80, 70, 120), 70, 120));
        }
      }
    }
  }

}
