unsigned long tempo_antes;
unsigned long tempo_depois;
unsigned long tempo_gasto;

void setup() {
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  tempo_antes = millis();

  //tempo_antes = micros();
  
  delay(2000);

  //delayMicroseconds(16000);

  tempo_depois = millis();

  //tempo_depois = micros();

  tempo_gasto = tempo_depois - tempo_antes;
  Serial.print("Tempo: ");
  Serial.println(tempo_gasto);

}
