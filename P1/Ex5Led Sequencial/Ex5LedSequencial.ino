String input = "";

const int A = 2; // Primeiramente setamos os 7 pinos dos segmentos
const int B = 3;
const int C = 4;
const int D = 5;
const int E = 6;
const int F = 7;
const int G = 8;

int numbers [][10] = {
  {A,B,C,D,E,F}, //0
  {B,C},  //1
  {A,B,D,E,G},  //2
  {A,B,C,D,G},  //3
  {B,C,F,G},  //4
  {A,C,D,F,G},  //5
  {C,D,E,F,G},  //6
  {A,B,C},  //7
  {A,B,C,D,E,F,G},  //8
  {A,B,C,F,G},  //9
}; 

boolean ligaPonto = false;

void setup(){
  Serial.begin(9600);
  
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  
}

void turnOffAll(){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void loop(){
  if (Serial.available()) {
    input = Serial.readStringUntil('\n');
    int valor = (int)input[0] - '0';
    Serial.println(valor);
    
    turnOffAll();
    for(int i = 0; i < 10; i++){
      if(numbers[valor][i]){
        digitalWrite(numbers[valor][i], HIGH);
      }
    }
  }
}
 
