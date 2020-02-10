//#define LED_PIN 2
#define LED_BUILTIN 2

void setup() {
  // initialize digital pin LED_PIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}


/*void timedBlink(int interval) {
  digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(interval);                       // wait for a second
  digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW
  delay(interval);                       // wait for a second
}
*/


void dimmer(int freq, int duty) {
  int period, onTime, offTime;
  period = 1000/freq;
  onTime = period * duty / 100;
  offTime = period - onTime;
  digitalWrite(LED_BUILTIN, HIGH);
  delay(onTime);
  digitalWrite(LED_BUILTIN, LOW);
  delay(offTime);
}


void loop() {
   int f = 100;
   for (int d = 0; d < 100; d++){
    //f = f - 10;
    dimmer (f, d);

   }

   for (int d = 100; d > 0; d--){
     //f = f - 10;
     dimmer(f, d);
   }

}
