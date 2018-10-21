#include <Servo.h>
int pos =0;
Servo myservo3;
Servo myservo1;
Servo myservo2;

int curr_ang1;
int curr_ang2;
int curr_ang3;
int set_ang2;
int set_ang3;
int words_ln;
void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:
  myservo3.attach(9);  //purple, x
  myservo1.attach(10); //red, z
  myservo2.attach(11); //yellow, y
  curr_ang1 = 20;
  set_ang2 = curr_ang2 = 180;
  set_ang3 = curr_ang3 = 200;
  words_ln = 0;
  delay(1000);
  myservo1.write(curr_ang1);
  delay(1000);
  myservo2.write(curr_ang2);
  delay(1000);
  myservo3.write(curr_ang3);
}

void print_braille() {
  delay(1000);
  myservo1.write(160);  //fast
  delay(500);
  myservo1.write(20);
}

void move_y(int y) {
  curr_ang2 += y;
  delay(1000);
  myservo2.write(curr_ang2 + y);
}


void move_x(int x) {
  curr_ang3 += x;
  delay(1000);
  myservo3.write(curr_ang3);
}

void next_letter() {
  words_ln++;
  reset();
  if(words_ln < 2) {
    set_ang3 -= 60;
    move_x(-60);
  }
  else {
    words_ln = 0;
    next_line();
  }
}

void next_line() {
  set_ang2 -= 60;
  set_ang3 = 200;
  reset();
}

void reset() {
  move_x(set_ang3 - curr_ang3);
  move_y(set_ang2 - curr_ang2); 
  curr_ang2 = set_ang2;
  curr_ang3 = set_ang3;
}

void loop() {
  if (Serial.available() > 0) {
    char data = Serial.read() - 'a';
    Serial.print(data);
    switch (data) {
      // a
      case 0:
        print_braille();
        next_letter();
        break;

      // b
      case 1:
        print_braille();
        move_y(-20);
        print_braille();
        next_letter();
        break;

      // c 
      case 2:
        print_braille();
        move_x(-20);
        print_braille();
        next_letter();
        break;

      // d 
      case 3:
        print_braille();
        move_x(-20);
        print_braille();
        move_y(-20);
        print_braille();
        next_letter();
        break;

      // e
      case 4:
        print_braille();
        move_x(-20);
        move_y(-20);
        print_braille();
        next_letter();
        break;

      // f 
      case 5:
        print_braille();
        move_y(-20);
        print_braille();
        move_x(-20);
        move_y(20);
        print_braille();
        next_letter();
        break;

      // g
      case 6:
        print_braille();
        move_x(-20);
        print_braille();
        move_y(-20);
        print_braille();
        move_x(20);
        print_braille();
        next_letter();
        break;

      // h
      case 7:
        print_braille();
        move_y(-20);
        print_braille();
        move_x(-20);
        print_braille();
        next_letter();
        break;

      // i
      case 8:
        move_y(-20);
        print_braille();
        move_x(-20);
        move_y(20);
        print_braille();
        next_letter();
        break;

      // j
      case 9:
        move_y(-20);
        print_braille();
        move_x(-20);
        print_braille();
        move_y(20);
        print_braille();
        next_letter();
        break;
      
      // k
      case 10:
        print_braille();
        move_y(-40);
        print_braille();
        next_letter();
        break;

      // l
      case 11:
        print_braille();
        move_y(-20);
        print_braille();
        move_y(-20);
        print_braille();
        next_letter();
        break;
    
      // m
      case 12:
        print_braille();
        move_y(-40);
        print_braille();
        move_y(40);
        move_x(-20);
        print_braille();
        next_letter();
        break;

      // n
      case 13:
        print_braille();
        move_x(-20);
        print_braille();
        move_y(-20);
        print_braille();
        move_y(-20);
        move_x(20);
        print_braille();
        next_letter();
        break;

      // o
      case 14:
        print_braille();
        move_y(-20);
        move_x(-20);
        print_braille();
        move_x(20);
        move_y(-20);
        print_braille();
        next_letter();
        break;

      // p
      case 15:
        print_braille();
        move_y(-20);
        print_braille();
        move_x(-20);
        move_y(20);
        print_braille();
        move_y(-40);
        move_x(20);
        print_braille();
        next_letter();
        break;

      // q
      case 16:
        print_braille();
        move_x(-20);
        print_braille();
        move_y(-20);
        print_braille();
        move_x(20);
        print_braille();
        move_y(-20);
        print_braille();
        next_letter();
        break;

      // r
      case 17:
        print_braille();
        move_y(-20);
        print_braille();
        move_x(-20);
        print_braille();
        move_y(-20);
        move_x(20);
        print_braille();
        next_letter();
        break;

      // s
      case 18:
        move_y(-20);
        print_braille();
        move_x(-20);
        move_y(20);
        print_braille();
        move_y(-20);
        print_braille();
        next_letter();
        break;

      // t
      case 19:
        move_x(-20);
        print_braille();
        move_y(-20);
        print_braille();
        move_x(20);
        print_braille();
        move_y(-20);
        print_braille();
        next_letter();
        break;

      // u
      case 20:
	print_braille();
        move_y(-40);
        print_braille();
        move_x(-20);
        print_braille();
        next_letter();
        break;

      // v
      case 21:
        print_braille();
        move_y(-20);
        print_braille();
        move_y(-20);
        print_braille();
        move_x(-20);
        print_braille();
        next_letter();
	break;

      // w
      case 22:
        move_x(-20);
        print_braille();
        move_y(-20);
        print_braille();
        move_y(-20);
        print_braille();
        move_x(20);
        move_y(20);
        print_braille();
        next_letter();
        break;

      // x 
      case 23:
        print_braille();
        move_x(-20);
        print_braille();
        move_y(-40);
        print_braille();
        move_x(20);
        print_braille();
        next_letter();
        break;

      // y 
      case 24:
        print_braille();
        move_x(-20);
        print_braille();
        move_y(-20);
        print_braille();
        move_y(-20);
        print_braille();
        move_x(20);
        print_braille();
        next_letter();
        break;

      // z 
      case 25:
        print_braille();
        move_y(-20);
        move_x(-20);
        print_braille();
        move_y(-20);
        print_braille();
        move_x(20);
        print_braille();
        next_letter();
        break;

      case -41:  
        next_letter();
        break;
    }
  }
}
