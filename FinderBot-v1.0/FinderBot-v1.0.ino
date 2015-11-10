int motorPin1 = 1;
int motorPin2 = 2;
int motorPin3 = 3;
int motorPin4 = 4;

int enablePin1 = 5;
int enablePin2 = 6;
int enablePin3 = 7;
int enablePin4 = 8;

int flag=0;

int state;

void setup() {
  
 pinMode (motorPin1, OUTPUT);
 pinMode (motorPin2, OUTPUT);
 pinMode (motorPin3, OUTPUT);
 pinMode (motorPin4, OUTPUT);
 
 pinMode (enablePin1, OUTPUT);
 pinMode (enablePin2, OUTPUT);
 pinMode (enablePin3, OUTPUT);
 pinMode (enablePin4, OUTPUT);
 
 digitalWrite(enablePin1, HIGH);
 digitalWrite(enablePin2, HIGH);
 digitalWrite(enablePin3, HIGH);
 digitalWrite(enablePin4, HIGH);
 
 Serial.begin(9600);

}

void loop() {
  
  if (Serial.available() > 0){
    state = Serial.read();
    flag=0;
  }
  
  if (state == '0'){
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    if (flag == 0){
      Serial.println("Motor: stop");
      flag=1;
    }
  }    
  
  else if (state == '1'){
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, HIGH);
    if (flag == 0){
      Serial.println("Motor: forward");
      flag=1;
    }
  }    
  
  else if (state == '2'){
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    if (flag == 0){
      Serial.println("Motor: left");
      flag=1;
    }
  }
  
  else if (state == '3'){
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, HIGH);
    if (flag == 0){
      Serial.println("Motor: right");
      flag=1;
    }
  }

}
