// stepper 1 
const int en1 = 2;
const int dir1 = 3;
const int pul1 = 4;

// stepper 2 
const int en2 = 5;
const int dir2 = 6;
const int pul2 = 7;

float interval1 = 0.0;
float interval2 = 0.0;
int microint1 = 0;
int microint2 = 0;

float rps1;
float rps2;

float rw_speed = 0.1; //speed n=in m/s
float lw_speed = 0.2;

int steps = 3200;
int pulse1 = HIGH;
int pulse2 = HIGH;

float pps1;
float pps2;

int timecount = 0;

// Details about wheel
const float w_diam = 0.120; //wheel diam is 120 mm or 0.120 m 

void setup() {  
  // pin modes for stepeprs
  pinMode(en1, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(pul1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pul2, OUTPUT);

  digitalWrite(en1, HIGH);
  digitalWrite(dir1, HIGH); //low cw, high ccw
  digitalWrite(pul1, HIGH);

  digitalWrite(en2, HIGH);
  digitalWrite(dir2, LOW); //low cw, high ccw
  digitalWrite(pul2, HIGH);

  //serial monitor
  //Serial.begin(9600);

}

void loop() {

  if(timecount == 5000){ //when timecount reaches 5000, 1 second has passed
    timecount = 0;
  }

  //if the time is at an increment divisible by our chosen speed, we send a pulse

  //first calculate desired rpm
  rps1 = rw_speed / (PI*w_diam);
  rps2 = lw_speed / (PI*w_diam);

  //then pulse per second (pps)
  pps1 = rps1*steps;
  pps2 = rps2*steps;

  // cap at max speed
  if(pps1 > 5000){
    pps1 = 5000;
  }  
  if(pps2 > 5000){
    pps2 = 5000;
  }

  // then calculate interval
  interval1 = 1/pps1;
  interval2 = 1/pps2;

  microint1 = int(interval1 * 5000);
  microint2 = int(interval2 * 5000);

  if (microint1 < 1) {
    microint1 = 1;  // Preventing zero or very small intervals
  }
  if (microint2 < 1) {
    microint2 = 1;  // Preventing zero or very small intervals
  }

  if((timecount % microint1) == 0){
//    Serial.print(rw_speed);
//    Serial.print(" ");
//    Serial.print(rps1);
//    Serial.print(" ");
//    Serial.print(pps1);
//    Serial.print(" ");
//    Serial.print(interval1);
//    Serial.print(" ");
//    Serial.print(timecount);
//    Serial.print(" ");
//    Serial.println(microint1);
    pulse1 = !pulse1;
    digitalWrite(pul1, pulse1); 
  }
  if((timecount % microint2) == 0){
//    Serial.print(lw_speed);
//    Serial.print(" ");
//    Serial.print(rps2);
//    Serial.print(" ");
//    Serial.print(pps2);
//    Serial.print(" ");
//    Serial.print(interval2);
//    Serial.print(" ");
//    Serial.print(timecount);
//    Serial.print(" ");
//    Serial.println(microint2);
    pulse2 = !pulse2;
    digitalWrite(pul2, pulse2); 
  }


  delayMicroseconds(200);  //delay in micro, with a 1 ms delay, the fastest we can go is 5000 pulse / sec
  timecount++;
  
  

}
