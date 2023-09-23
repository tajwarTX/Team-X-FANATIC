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




void obstacle(int disfr, int disrt, int dislt, int *flagCalibrate, int *ignoreTurn, unsigned long *startTime) {

  if (!huskylens.request()) Serial.println(F(" "));
  else if (!huskylens.isLearned()) Serial.println(F("Nothing learneda"));
  else {
    if (huskylens.available()) {

      HUSKYLENSResult result = huskylens.read();
      int xAxis = result.xCenter;

      if (result.ID == 1 ) {
        axis.write(map(xAxis, 40, 280, 125 , 110));
        *startTime = millis();
        //        delay(150);
        //        axis.write(m);

      }
      else if (result.ID == 2) {

        axis.write(map(xAxis, 50, 280, 85, 70 ));

      }
    }

    else {
      if ( disfr <= 100 && disfr != 0) { //&& (dislt+disrt >= 100 && dislt+disrt <= 200)) {
        axis.write(130);
      }

      else {
        int error = dislt - disrt;

        axis.write(constrain(map(error, -80, 80, 65, 135), 65, 135));
       
      }

    }
  }

}
