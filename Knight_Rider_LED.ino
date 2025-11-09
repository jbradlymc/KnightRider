int ledpins[] = {2,3,4,5,6,7,8,9};

int button1 = A0;
int button2 = A1;
int button3 = A2;
int button4 = A3;
int button5 = A4;
int button6 = A5;

void setup() {
  for (int i=0; i<8; i++) {
    pinMode(ledpins[i], OUTPUT);
  }
  
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  pinMode(button6, INPUT_PULLUP);
}

void loop() {
  
  if (digitalRead(button1) == LOW) {
    pattern1();
    turnOff();
  }
  
  if (digitalRead(button2) == LOW) {
    pattern2();
    turnOff();
  }
  
  if (digitalRead(button3) == LOW) {
    pattern3();
    turnOff();
  }
  
  if (digitalRead(button4) == LOW) {
    pattern4();
    turnOff();
  }
  
  if (digitalRead(button5) == LOW) {
    for (int i = 0; i < 256; i++) {  
      pattern5(i);
      delay(200);
    }
    turnOff();
  }
  
  if (digitalRead(button6) == LOW) {
    for (int i=0; i<10; i++) {
      pattern6(i,500);
    }
    turnOff();
  }
}

void pattern1() {
  for (int i=0; i<8; i++) {
    digitalWrite(ledpins[i], HIGH);
    delay(500);
  }

  for (int i=7; i>=0; i--) {
    digitalWrite(ledpins[i], LOW);
    delay(500);
  }
}

void pattern2() {
   for (int i=0; i<8; i++) {
    digitalWrite(ledpins[i], HIGH);
    delay(500);
    digitalWrite(ledpins[i], LOW);
    delay(500);
   }
}

void pattern3() {
  int ledpairs[4][2] = {{0,7}, {1,6}, {2,5}, {3,4}};
  
  for (int i=0; i<4; i++) {
    digitalWrite(ledpins[ledpairs[i][0]],HIGH);
    digitalWrite(ledpins[ledpairs[i][1]],HIGH);
    delay(500);
    digitalWrite(ledpins[ledpairs[i][0]],LOW);
    digitalWrite(ledpins[ledpairs[i][1]],LOW);
    delay(500);
  }
}

void pattern4() {
  int ledpairs[4][2] = {{0,7}, {1,6}, {2,5}, {3,4}};
  
  for (int i=0; i<4; i++) {
    digitalWrite(ledpins[ledpairs[i][0]],HIGH);
    digitalWrite(ledpins[ledpairs[i][1]],HIGH);
    delay(500);
  }
  
  for (int i=3; i>=0; i--) {
    digitalWrite(ledpins[ledpairs[i][0]],LOW);
    digitalWrite(ledpins[ledpairs[i][1]],LOW);
    delay(500);
  }
}

void pattern5(int num) {
  for (int i = 0; i < 8; i++) {
    int bitValue = num % 2;       
    num = num / 2;                
    digitalWrite(ledpins[i], bitValue);
  }
}

void pattern6(int pin, int duration) {
  digitalWrite(pin, HIGH);
  delay(duration);
  digitalWrite(pin, LOW);
  delay(duration);
}

void turnOff() {
  for (int i=0; i<8; i++) {
    digitalWrite(ledpins[i], LOW);
    }
  delay(1000);
}
