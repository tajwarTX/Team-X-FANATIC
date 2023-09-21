# Software Setup

- First we need to install the latest Arduino IDE on our computer from: arduino.cc/en/Main/Software. If you already have an older version, uninstall it and install the latest one again. Otherwise, it may not work.

- In your Arduino IDE, go to File > Preferences, and enter the following into the "Additional Board Manager URLs" field, and click OK:


- Open the Arduino Boards Manager: Tools > Board > Boards Manager... and search for ESP32. Press install button for the "ESP32 by Espressif Systems".


- Now we try to upload our code to the ESP32. Select your Board in Tools > Board menu (in our case it is the DOIT ESP32 DEVKIT V1).


- Select the COM port, and open the sketch.


- Press the Upload button in the Arduino IDE. Wait a few seconds while the code compiles and uploads to your board. It should say "Done Uploading" if the upload completes successfully.

- Now you can place the robot on the track, power it up, and wait until the front servo centers.

- Press the button and it will start doing the laps.
-
-
- ![port select](https://github.com/tajwarTX/Team-X-FANATIC/assets/136412241/367c089d-3b4b-43c4-9add-aab6031c99c6)
![avr select](https://github.com/tajwarTX/Team-X-FANATIC/assets/136412241/d10835e3-75e3-45e6-8944-937a9a5b0acd)
![bootloader select](https://github.com/tajwarTX/Team-X-FANATIC/assets/136412241/58504676-7e06-43ab-9b51-b40ab2816852)
![upload](https://github.com/tajwarTX/Team-X-FANATIC/assets/136412241/3e30e6a4-d484-4723-8d78-144664cef281)
![error](https://github.com/tajwarTX/Team-X-FANATIC/assets/136412241/e32a0afb-20c2-48fc-9fb9-531e2617ee1d)
