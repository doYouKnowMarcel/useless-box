
#include <Servo.h>
#include "MusicBuzzer.h"

Servo servo_driver;  // create servo object to control a servo

int servo_pos = 0;    // variable to store the servo position
const int servo_min = 55;    //  Servo Min-Stellung
const int servo_max = 150;    // Servo Max-Stellung
int servo_range = 0;  

const int button_pin = 3;  // Eingang Kippstellung
int button_state = 0; 
bool button_debug = false; 

void setup() {
  servo_driver.attach(2);  // attach servo on pin 2
  pinMode(button_pin, INPUT); //attach button on pin 3
  music.init(4); // attach music buzzer on pin 4
  Serial.begin(9600);

  servoMaxInit();

}

void loop() {
  //Button position einlesen
  button_state = digitalRead(button_pin);
  delay(100);
  if(button_state == HIGH || button_debug) {
    Serial.println("button on");
    
    button_debug = false;

    delay(300);
    long programm = random(0,2); //0 oder 1
    Serial.print("Ausführen von Programm ");
    Serial.println(programm);
    switch (programm) {
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

void servoButtonOffVariante0(){
  music.starwars(12);
  
  /*
    Author: Everton Ramires
    More Tutorial: https://www.youtube.com/channel/UC7zG4YQJc8v-9jNGQknOx5Q
  
    Based on the great work of robsoncouto at github (https://github.com/robsoncouto/arduino-songs).
  
    CURRENT SONG OPTIONS:
    (PT-BR)OPÇÕES ATUAIS DE MUSICAS:
  
  
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

    servoMove(servo_max, 1.0);
    delay(1000);
    servoMove(servo_min, 0.3);
    delay(2000);
}
void servoButtonOffVariante1(){
    //vor mit kleiner Geschwindigkeit bis zur Hälfte
    servoMove(servo_min + (servo_range)/2, 0.1);
    delay(1000);
    
    //bis zum Ende Fahren mit hoher Geschwindigkeit
    servoMove(servo_max, 1.0);
    delay(200);

    //zurück
    servoMove(servo_min, 1);
}

void servoMaxInit(){
  /*
  for (servo_pos = servo_pos; servo_pos <= 180; servo_pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo_driver.write(servo_pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15 ms for the servo to reach the position
    
  }
  */
  
  
  servo_range = servo_max - servo_min;
  servoMove(servo_min, 1);
}

//moves servo to servo_pos_end with pace (0.1=slow=10%, 1=fast=100%)
void servoMove(int servo_pos_end, int pace){
  int servo_delay = (int) (20-20*pace+2);
  
  //init servo step
  if(servo_pos<=servo_pos_end){
    //for (servo_pos = servo_min; servo_pos <= servo_max; servo_pos += 1) { // goes from 0 degrees to 180 degrees
    for (servo_pos = servo_pos; servo_pos <= servo_pos_end; servo_pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servo_driver.write(servo_pos);              // tell servo to go to position in variable 'pos'
      delay(servo_delay);                       // waits 15 ms for the servo to reach the position

      //check if button end reached
      /*
      button_state = digitalRead(button_pin);
      if(button_state == LOW)return;
      */
    }
  }else{
    for (servo_pos = servo_max; servo_pos >= servo_pos_end; servo_pos -= 1) { // goes from 180 degrees to 0 degrees
      servo_driver.write(servo_pos);              // tell servo to go to position in variable 'pos'
      delay(servo_delay);                       // waits 15 ms for the servo to reach the position
    }
  }
  //Serial.println(servo_pos);
}
