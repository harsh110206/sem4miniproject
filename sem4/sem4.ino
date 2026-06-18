int gasSensor = A0;
int flameSensor = 2;

int relay = 8;
int buzzer = 9;

int gasThreshold = 300;

void setup() {

  pinMode(flameSensor, INPUT);

  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(relay, HIGH);
  digitalWrite(buzzer, LOW);

  Serial.begin(9600);
}

void loop() {

  int gasValue = analogRead(gasSensor);
  int flameStatus = digitalRead(flameSensor);

  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  // DANGER CONDITION
  if (gasValue > gasThreshold || flameStatus == HIGH) {

    digitalWrite(relay, LOW);
    digitalWrite(buzzer, HIGH);

    Serial.println("DANGER DETECTED!");
  }

  // SAFE CONDITION
  else {

    digitalWrite(relay, HIGH);
    digitalWrite(buzzer, LOW);

    Serial.println("SYSTEM SAFE");
  }

  delay(500);
}