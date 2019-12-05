int buzzerPin = 9;
int songLength = 62;

const int swC = 3;
const int swD = 5;
const int swE = 6;
const int swPlaySong = 10;

char notes[] = "EGAGECE DCDCDCC ggg CCC EE EDCD EGAGECE DCDCDCC ggCCEGA GEDgC ";
int beats[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

int tempo = 200;

void setup() {
  pinMode(buzzerPin,OUTPUT);

  pinMode(swC, INPUT_PULLUP);
  pinMode(swD, INPUT_PULLUP);
  pinMode(swE, INPUT_PULLUP);
  pinMode(swPlaySong, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(swC) == LOW){
    tone(buzzerPin,262,100);
  }
  if(digitalRead(swD) == LOW){
    tone(buzzerPin,294,100);
  }
  if(digitalRead(swE) == LOW){
    tone(buzzerPin,330,100);
  }
}  
int frequency(char note){
  int i;

  int notes = 9;

  char names[] = {'g','a','b','C','D','E','F','G','A'};
  int frequencies[] = {392,440,494,524,588,660,699,785,881};

  for(i=0; i < notes; i++){
    if(names[i] == note){
      return(frequencies[i]);
    }
  }
  return(0);
}
