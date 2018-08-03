/* SmartPlant
 *  Greg McIntyre
 *  1/8/18
 *  
 *  John has many plants on the balcony of his house. These plants require constant attention and caring. He has to water them when they require, add fertilizers and pesticide.
 * 
 * One of the most tedious tasks that John has to do is to keep the plants’ soil moist at all times. Otherwise the plants will not be in good shape and may not survive. John 
 * has become very busy these days and with his age it is hard for him to keep record and remember when to water the plants. He is looking for a smart solution to notify him 
 * when the plants need to be watered. Such a solution needs to provide a notification using an LED light connected to the pot to turn on and indicate when the soil moisture 
 * is below a certain limit.
 * 
 * This code contains a modified version of niroshini's DFRobotSoilMositure
 * 
 * Assumptions
 * 0    ~ 300     dry soil 
 * 300  ~ 700     humid soil
 * 700  ~ 950     in water
 * 
 */

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  //Serial.begin(9600); // open serial port, set the baud rate as 9600 bps
}
void loop() {
  int val;
  val = read();
  compare(val);
  delay(2000);
}

int read () {
  int val;
  val = analogRead(0);  //read from pin 0
  //Serial.println(val); //print the value to serial port
  return val;
}

void compare(int val){
    if (val<=300){                      //if soil is dry
    digitalWrite(LED_BUILTIN, HIGH);
  }else{
    digitalWrite(LED_BUILTIN, LOW);
  }
}

