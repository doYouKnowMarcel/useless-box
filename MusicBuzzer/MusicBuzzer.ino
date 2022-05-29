#include "MusicBuzzer.h"

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

void setup(){
  Serial.begin(9600);
  music.init(4);
}

void loop(){
  music.zeldaslullaby();
  delay(2000);
}
