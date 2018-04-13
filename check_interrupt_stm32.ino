HardwareTimer ssi_timer = HardwareTimer(3);
volatile long count = 0;
void ssi_timer_callback(void) {
  if (count & 1) gpio_write_bit(GPIOC, 13, HIGH);
  else gpio_write_bit(GPIOC, 13, LOW);
  count ++;
}


void setup() {
  // put your setup code here, to run once:
  pinMode(PC13, OUTPUT);
  digitalWrite(PC13, LOW);
  ssi_timer.setPeriod(42000); //us
  delay(100);
  ssi_timer.attachInterrupt(0, ssi_timer_callback);
  delay(100);


}

void loop() {
  // put your main code here, to run repeatedly:

}
