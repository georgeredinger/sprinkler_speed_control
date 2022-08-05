//pwm   3, 5, 6, 9, 10
#define LED LED_BUILTIN
#define PWM 10
void setup() {
  Serial.begin(115200);
  pinMode(PWM, OUTPUT);
  pinMode(LED, OUTPUT);
}

void wait(int seconds){
  for(int i = 0;i<seconds;i++){
    delay(1000);
    Serial.println(i);
  }
}

void ramp(int begin, int end, int rate, int on) {
  digitalWrite(LED, HIGH);
  for (int i = begin; i <= end; i++) {
    analogWrite(PWM, i);
    delay(rate);
    Serial.println(i);
  }
  delay(on);
  digitalWrite(LED, LOW);
  for (int i = end; i > begin; i--) {
    analogWrite(PWM, i);
    delay(rate);
    Serial.println(i);
  }
}
void loop() {
  int ontime = 5000;
  //read pot for on time?
  ramp(10, 256 / 6, 25, ontime);
  analogWrite(PWM, 0);
  //read pot to determine this delay
  int delaySeconds = 60;
  //read pot to determine this delay
  wait(delaySeconds);
}
