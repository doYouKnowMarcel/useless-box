#ifndef MusicBuzzer_h
#define MusicBuzzer_h
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define debug true


class MusicBuzzer{
public:
  void init(int buzzerPin);
  void initBuzzer(int buzzerPin);
  void play(int tempo, int melody[], int notes, int stopp=-1);
  
  void asabranca(int stopp=-1);
  void babyelephantwalk(int stopp=-1);
  void bloodytears(int stopp=-1);
  void brahmslullaby(int stopp=-1);
  void cannonind(int stopp=-1);
  void cantinaband(int stopp=-1);
  void doom(int stopp=-1);
  void furelise(int stopp=-1);
  void gameofthrones(int stopp=-1);
  void greenhill(int stopp=-1);
  void greensleeves(int stopp=-1);
  void happybirthday(int stopp=-1);
  void harrypotter(int stopp=-1);
  void imperialmarch(int stopp=-1);
  void jigglypuffsong(int stopp=-1);
  void keyboardcat(int stopp=-1);
  void merrychristmas(int stopp=-1);
  void miichannel(int stopp=-1);
  void minuetg(int stopp=-1);
  void nevergonnagiveyouup(int stopp=-1);
  void odetojoy(int stopp=-1);
  void pacman(int stopp=-1);
  void pinkpanther(int stopp=-1);
  void princeigor(int stopp=-1);
  void professorlayton(int stopp=-1);
  void pulodagaita(int stopp=-1);
  void silentnight(int stopp=-1);
  void songofstorms(int stopp=-1);
  void startrekintro(int stopp=-1);
  void starwars(int stopp=-1);
  void supermariobros(int stopp=-1);
  void takeonme(int stopp=-1);
  void tetris(int stopp=-1);
  void thegodfather(int stopp=-1);
  void thelick(int stopp=-1);
  void thelionsleepstonight(int stopp=-1);
  void vampirekiller(int stopp=-1);
  void zeldaslullaby(int stopp=-1);
  void zeldatheme(int stopp=-1);

private:
  int buzzerPin;
  int divider;
  int noteDuration;
};

extern MusicBuzzer music;

#endif
