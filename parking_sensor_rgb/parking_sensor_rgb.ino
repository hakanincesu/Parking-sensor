const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH, 30000);
  if (duration == 0) return 999;
  return duration * 0.034 / 2;
}

void setColor(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

void loop() {
  distance = getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 50) {
    setColor(0, 255, 0);      // green
    noTone(buzzerPin);

  } else if (distance > 20) {
    setColor(255, 255, 0);    // yellow
    tone(buzzerPin, 1000);
    delay(300);
    noTone(buzzerPin);
    delay(300);

  } else if (distance > 10) {
    setColor(255, 100, 0);    // orange
    tone(buzzerPin, 1500);
    delay(100);
    noTone(buzzerPin);
    delay(100);

  } else {
    setColor(255, 0, 0);      // red
    tone(buzzerPin, 2000);
  }

  delay(60);
}