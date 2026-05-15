// Road LEDs
int R1 = 2;
int Y1 = 3;
int G1 = 4;

int R2 = 5;
int Y2 = 6;
int G2 = 7;

int R3 = 8;
int Y3 = 9;
int G3 = 10;

// Ultrasonic pins
int trig1 = 11;
int echo1 = 12;

int trig2 = A0;
int echo2 = A1;

int trig3 = A2;
int echo3 = A3;

long duration;
int distance;

int getDistance(int trig, int echo)
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);

  distance = duration * 0.034 / 2;

  return distance;
}

void setup()
{
  pinMode(R1, OUTPUT);
  pinMode(Y1, OUTPUT);
  pinMode(G1, OUTPUT);

  pinMode(R2, OUTPUT);
  pinMode(Y2, OUTPUT);
  pinMode(G2, OUTPUT);

  pinMode(R3, OUTPUT);
  pinMode(Y3, OUTPUT);
  pinMode(G3, OUTPUT);

  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);

  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  pinMode(trig3, OUTPUT);
  pinMode(echo3, INPUT);

  Serial.begin(9600);
}

void loop()
{
  int d1 = getDistance(trig1, echo1);
  int d2 = getDistance(trig2, echo2);
  int d3 = getDistance(trig3, echo3);

  // SMART PRIORITY MODE
  if (d1 <= 20)
  {
    greenRoad1();
  }
  else if (d2 <= 20)
  {
    greenRoad2();
  }
  else if (d3 <= 20)
  {
    greenRoad3();
  }
  else
  {
    normalCycle();
  }
}

// FUNCTIONS

void greenRoad1()
{
  digitalWrite(G1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  delay(7000);

  digitalWrite(G1, LOW);
  digitalWrite(Y1, HIGH);
  delay(2000);
  digitalWrite(Y1, LOW);
}

void greenRoad2()
{
  digitalWrite(G2, HIGH);
  digitalWrite(R1, HIGH);
  digitalWrite(R3, HIGH);
  delay(7000);

  digitalWrite(G2, LOW);
  digitalWrite(Y2, HIGH);
  delay(2000);
  digitalWrite(Y2, LOW);
}

void greenRoad3()
{
  digitalWrite(G3, HIGH);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, HIGH);
  delay(7000);

  digitalWrite(G3, LOW);
  digitalWrite(Y3, HIGH);
  delay(2000);
  digitalWrite(Y3, LOW);
}

void normalCycle()
{
  // ROAD 1
  digitalWrite(G1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  delay(8000);

  digitalWrite(G1, LOW);
  digitalWrite(Y1, HIGH);
  delay(2000);
  digitalWrite(Y1, LOW);
  digitalWrite(R1, HIGH);

  // ROAD 2
  digitalWrite(R2, LOW);
  digitalWrite(G2, HIGH);
  delay(8000);

  digitalWrite(G2, LOW);
  digitalWrite(Y2, HIGH);
  delay(2000);
  digitalWrite(Y2, LOW);
  digitalWrite(R2, HIGH);

  // ROAD 3
  digitalWrite(R3, LOW);
  digitalWrite(G3, HIGH);
  delay(8000);

  digitalWrite(G3, LOW);
  digitalWrite(Y3, HIGH);
  delay(2000);
  digitalWrite(Y3, LOW);
  digitalWrite(R3, HIGH);
}