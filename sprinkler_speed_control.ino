//pwm   3, 5, 6, 9, 10
#define LED LED_BUILTIN
#define PWM 3
#define SPEED A0
int loops;
int seconds;
int minutes;
void setup() {
  Serial.begin(115200);
  pinMode(PWM, OUTPUT);
  pinMode(LED, OUTPUT);
  seconds = millis() / 1000;
}

void loop() {
  int ontime = 4000;
  int hotness = 64;
  unsigned long delayMilliSeconds = 60000;
  unsigned long pot;
  seconds = millis() / 1000;
  minutes = seconds / 60;
  analogWrite(PWM, hotness);//ON
  delay(ontime);
  analogWrite(PWM, 0);//OFF
  pot = analogRead(SPEED);
  delayMilliSeconds = pot * 300L ; //0..1023 -- seconds 0..255
  Serial.print(pot); Serial.print(","); Serial.println(delayMilliSeconds);
  delay(delayMilliSeconds);
}
