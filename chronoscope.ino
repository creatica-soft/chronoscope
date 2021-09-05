//pin connected to the first laser's signal pin
const byte ledPin1 = 42;

//pin connected to the second laser's signal pin
const byte ledPin2 = 44;

//pin connected to the first photodiode's signal pin
const byte interruptPin1 = 18;

//pin connected to the second photodiode's signal pin
const byte interruptPin2 = 19;

//distance between two laser-photodiode pairs in meters
const float distance = 0.1;

//time in microseconds breaking the first laser beam
volatile unsigned long t1 = 0;

//time in microseconds breaking the second laser beam
volatile unsigned long t2 = 0;

void setup() {
  //setup laser pins as output
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  
  //turn on both lasers
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);

  //setup photdiode signal pins as input pulled up
  pinMode(interruptPin1, INPUT_PULLUP);
  pinMode(interruptPin2, INPUT_PULLUP);

  //attach interrupt routine to these pins
  attachInterrupt(digitalPinToInterrupt(interruptPin1), blink1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), blink2, CHANGE);

  //setup serial
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  if (t2 > 0 || t1 > 0) {
    Serial.print("t1 ");
    Serial.println(t1);
    Serial.print("t2 ");
    Serial.println(t2);
    Serial.print("speed ");
    Serial.print(distance * 1000000/(t2 - t1), 1);
    Serial.println(" m/s");
    t1 = 0;
    t2 = 0;
  }
  
}

void blink1() {
  t1 = micros();
}
void blink2() {
  t2 = micros();
}
