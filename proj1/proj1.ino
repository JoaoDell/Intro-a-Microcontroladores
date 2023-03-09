
//Esse na verdade é o projeto 4
#define trigPin 13
#define echoPin 12
float distancia; unsigned long tempo;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  tempo = pulseIn(echoPin, HIGH);
  distancia = 0.0340*(tempo/2);
  Serial.print(distancia, 1);
  Serial.println(" cm");

  delay(500);
}
