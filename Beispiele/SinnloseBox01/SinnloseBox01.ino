
#include <Servo.h>
#include "MusicBuzzer.h"

Servo servo_driver;  // create servo object to control a servo

int servo_pos = 0;    // variable to store the servo position
const int servo_closed = 95;    //  Servo Min-Stellung
int servo_opened = 10;    // Servo Max-Stellung
int servo_range = 0;  

const int button_pin = 3;  // Eingang Kippstellung
int button_state = 0; 
bool button_debug = false; 

int buzzerPin = 6;

void setup() {
  servo_driver.attach(2);  // attach servo on pin 2
  pinMode(button_pin, INPUT_PULLUP); //attach button on pin 3
  music.initBuzzer(6); // attach music buzzer on pin 4
  Serial.begin(9600);

  servoMaxInit();
}

void loop() {
  //Button position einlesen
  button_state = digitalRead(button_pin);
  delay(100);
  if(buttonPushed() || button_debug) {
    Serial.println("button on");
    
    button_debug = false;

    delay(300);
    long programm = random(0,3); //0 oder 1
    Serial.print("Ausführen von Programm ");
    Serial.println(programm);
    switch (programm) {
      case 2:
        servoButtonOffVariante2();
        break;
      case 1:
        servoButtonOffVariante1();
        break;
      default:
        servoButtonOffVariante0();
        break;
    }

    //warte um Button zu entprellen
    delay(700);
  }
}


bool buttonPushed(){
  button_state = digitalRead(button_pin);
  return (button_state == LOW);
}

void servoButtonOffVariante0(){
  music.dumdadadumdumdumdum(12);

  /*
    music.asabranca();
    music.babyelephantwalk();
    music.bloodytears();
    music.brahmslullaby();
    music.cannonind();
    music.cantinaband();
    music.doom();
    music.furelise();
    music.gameofthrones();
    music.greenhill();
    music.greensleeves();
    music.happybirthday();
    music.harrypotter();
    music.imperialmarch();
    music.jigglypuffsong();
    music.keyboardcat();
    music.merrychristmas();
    music.miichannel();
    music.minuetg();
    music.nevergonnagiveyouup();
    music.odetojoy();
    music.pinkpanther();
    music.princeigor();
    music.professorlayton();
    music.pulodagaita();
    music.silentnight();
    music.songofstorms();
    music.startrekintro();
    music.starwars();
    music.supermariobros();
    music.takeonme();
    music.tetris();
    music.thegodfather();
    music.thelick();
    music.thelionsleepstonight();
    music.vampirekiller();
    music.zeldaslullaby();
    music.zeldatheme();
  */

    servoMove(servo_opened, 1.0);
    delay(1000);
    servoMove(servo_closed, 0.3);
    delay(1000);
}
void servoButtonOffVariante1(){
    //vor mit kleiner Geschwindigkeit bis zur Hälfte
    servoMovePerc(0.6, 0.1);
    delay(1000);
    
    //bis zum Ende Fahren mit hoher Geschwindigkeit
    servoMove(servo_opened, 1.0);
    delay(200);
    
    servoMovePerc(0.55, 0.1);
    delay(500);
    
    servoMovePerc(0.8, 1.0);

    //zurück
    servoMove(servo_closed, 0.7);
}

void servoButtonOffVariante2(){
    //vor mit kleiner Geschwindigkeit bis zur Hälfte
    servoMovePerc(0.6, 0.1);
    delay(1000);
    
    //bis zum Ende Fahren mit hoher Geschwindigkeit
    servoMove(servo_opened, 1.0);
    delay(200);

    //zurück
    servoMove(servo_closed, 0.7);
}

void servoMovePerc(float servo_pos_perc, float pace){
  float servo_open_val = 0;
  if(servo_closed > servo_opened){
    servo_open_val = servo_range*servo_pos_perc;
  }else{
    servo_open_val = servo_range*(1-servo_pos_perc);
  }
  servoMove(servo_closed + servo_open_val, pace);
}

//moves servo to servo_pos_end with pace (0.1=slow=10%, 1=fast=100%)
void servoMove(int servo_pos_end, float pace){
  int servo_delay = (int) (20-20*pace+2);
  
  Serial.print("Servo von ");
  Serial.print(servo_pos);
  Serial.print(" nach ");
  Serial.println(servo_pos_end);

  bool buttonPush = buttonPushed();
  
  //init servo step
  if(servo_pos<=servo_pos_end){
    //for (servo_pos = servo_closed; servo_pos <= servo_opened; servo_pos += 1) { // goes from 0 degrees to 180 degrees
    for (servo_pos = servo_pos; servo_pos <= servo_pos_end; servo_pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servo_driver.write(servo_pos);              // tell servo to go to position in variable 'pos'
      delay(servo_delay);                       // waits 15 ms for the servo to reach the position

      //check if button end reached
      if(!buttonPush){
        if(buttonPushed())return;
      }
    }
  }else{
    for (servo_pos = servo_opened; servo_pos >= servo_pos_end; servo_pos -= 1) { // goes from 180 degrees to 0 degrees
      servo_driver.write(servo_pos);              // tell servo to go to position in variable 'pos'
      delay(servo_delay);                       // waits 15 ms for the servo to reach the position
      
      if(!buttonPush){
        if(buttonPushed())return;
      }
    }
  }
  //Serial.println(servo_pos);
}

void servoMaxInit(){
  /*
  // set bounds of servo automatically
  if(!buttonPushed() && servo_opened == -1) {
    int pos = 0;
    for (servo_pos = servo_closed; servo_pos >= 0; servo_pos -= 1) { // goes from 0 degrees to 180 degrees
      servo_driver.write(servo_pos); 
      if(buttonPushed()){
        servo_opened = servo_pos;
        break;
      }
      delay(5);                       // waits 15 ms for the servo to reach the position
    }
  }
  */
  
  Serial.print("Servo range: ");
  servo_range = (servo_opened - servo_closed);
  Serial.println(servo_range);
  
  Serial.println("Close servo");
  servoMove(servo_closed, 1);
}
