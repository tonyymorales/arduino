// stepper 1 
const int en = 2;
const int dir = 3;
const int pul = 4;

// stepper 2 
const int en2 = 5;
const int dir2 = 6;
const int pul2 = 7;

int interval1 = 0;
int interval2 = 0;

int rw_speed;
int lw_speed;

// Details about wheel
const int w_diam;

//boolean
boolean pulse = LOW;
int count = 0;


void setup() {
  // pin modes for stepeprs
  pinMode(en, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(pul, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pul2, OUTPUT);

  digitalWrite(en, HIGH);
  digitalWrite(dir, HIGH); //low cw, high ccw
  digitalWrite(pul, HIGH);

  digitalWrite(en2, HIGH);
  digitalWrite(dir2, LOW); //low cw, high ccw
  digitalWrite(pul2, HIGH);

  //serial monitor
  Serial.begin(9600);
}

void loop() {

  pulse = !pulse;
  digitalWrite(pul, pulse); 
  digitalWrite(pul2, pulse); 

  delayMicroseconds(500); 


}
