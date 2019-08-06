/*
  Project name: ledsPlay

  Description:  switch between two leds, while controlling the led illumination.
                One led is off, while the other quickly increases its illumination,
                and then the leds switch.

  Components:   matrix, 2 leds, 2 resistors of 220[Ohm].

  Circuit:  (digitalPin3) -> (led0) -> (resistor220) -> (GND).
            (digitalPin11) -> (led1) -> (resistor220) -> (GND).
*/

//--------------------------------------------------------
//---------------START OF EDITABLE SECTION----------------
//--------------------------------------------------------
// define constants
#define LED_0_PIN 3           // only pins marked with (~): 3, 5, 6, 9, 10 or 11.
#define LED_1_PIN 11          // only pins marked with (~): 3, 5, 6, 9, 10 or 11.
#define START_INTENSITY 20    // illumination start intensity
#define END_INTENSITY 200     // illumination end intensity
#define INTENSITY_STEP 20     // intensity step value
#define LED0_DELAY 150        // time interval of each illumination intensity, in msec (led0)
#define LED1_DELAY 150        // time interval of each illumination intensity, in msec (led1)
//--------------------------------------------------------
//----------------END OF EDITABLE SECTION-----------------
//--------------------------------------------------------


// define variables
int iIntensity = 0;

void setup() {
  // dedicate pins
  pinMode(LED_0_PIN, OUTPUT);
  pinMode(LED_1_PIN, OUTPUT);
  // turn off leds
  analogWrite(LED_0_PIN, 0);
  analogWrite(LED_1_PIN, 0);
}

void loop() {
  // incremental increase illumination of led0
  for (iIntensity = START_INTENSITY; iIntensity <= END_INTENSITY; iIntensity = iIntensity + INTENSITY_STEP) {
    analogWrite(LED_0_PIN, iIntensity);
    delay(LED0_DELAY);
  }
  // turn off led0
  analogWrite(LED_0_PIN, 0);
  // incremental increase illumination of led1
  for (iIntensity = START_INTENSITY; iIntensity <= END_INTENSITY; iIntensity = iIntensity + INTENSITY_STEP) {
    analogWrite(LED_1_PIN, iIntensity);
    delay(LED1_DELAY);
  }
  // turn off led1
  analogWrite(LED_1_PIN, 0);
}
