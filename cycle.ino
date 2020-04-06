const int redPin = 14;
const int greenPin = 12;
const int bluePin = 13;

const int max_red = 2550;
const int max_green = 700; //90;
const int max_blue = 1000; //100;

void setup() {
  // Start off with the LED off.
  setColourRgb(0,0,0);
}

void loop() {
  unsigned int rgbColour[3];

  // Start off with red.
  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  

  // Choose the colours to increment and decrement.
  for (int decColour = 0; decColour < 3; decColour += 1) {
    int incColour = decColour == 2 ? 0 : decColour + 1;

    // cross-fade the two colours.
    for(int i = 0; i < 255; i += 1) {
      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
      
      setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
      delay(25);
    }
  }
}

void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(redPin, map(red, 0, 255, 0, max_green));
  analogWrite(greenPin, map(green, 0, 255, 0, max_green));
  analogWrite(bluePin, map(blue, 0, 255, 0, max_green));
 }