int motorPin1 = 3;
int motorPin2 = 5;
int motorPin3 = 7;
int motorPin4 = 9;

int enablePin1 = 2;
int enablePin2 = 4;
int enablePin3 = 6;
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
 
 digitalWrite(enablePin1, LOW);
 digitalWrite(enablePin2, LOW);
 digitalWrite(enablePin3, LOW);
 digitalWrite(enablePin4, LOW);
 
 Serial.begin(9600);

}

void loop() {
  
  if (Serial.available() > 0){
    state = Serial.read();
    flag=0;
  }
  if (flag == 0){
    switch(state) {
      case 0:
        flag=1;
        Serial.println("Motor: stop");
        rightStop();
        leftStop();
      }
      case 0:
        flag=1;
        Serial.println("Motor: stop");
        rightStop();
        leftStop();
      }
    }  
  } 
  if (state == '0'){
    digitalWrite(enablePin1, LOW);
    digitalWrite(enablePin2, LOW);
    digitalWrite(enablePin3, LOW);
    digitalWrite(enablePin4, LOW);
    if (flag == 0){
      Serial.println("Motor: stop");
      flag=1;
    }
  }    
  
  else if (state == '1'){
    digitalWrite(enablePin1, HIGH);
    digitalWrite(enablePin2, HIGH);
    digitalWrite(enablePin3, HIGH);
    digitalWrite(enablePin4, HIGH);
    if (flag == 0){
      Serial.println("Motor: forward");
      flag=1;
    }
  }    
  
  else if (state == '2'){
    digitalWrite(enablePin1, LOW);
    digitalWrite(enablePin2, LOW);
    digitalWrite(enablePin3, HIGH);
    digitalWrite(enablePin4, HIGH);
    if (flag == 0){
      Serial.println("Motor: left");
      flag=1;
    }
  }
  
  else if (state == '3'){
    digitalWrite(enablePin1, HIGH);
    digitalWrite(enablePin2, HIGH);
    digitalWrite(enablePin3, LOW);
    digitalWrite(enablePin4, LOW);
    if (flag == 0){
      Serial.println("Motor: right");
      flag=1;
    }
  }

}

void rightForward() {
  digitalWrite(enablePin1, HIGH);
  digitalWrite(enablePin2, HIGH);
  digitalWrite(enablePin3, HIGH);
  digitalWrite(enablePin4, HIGH);
}
