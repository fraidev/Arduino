
int restoParImparComparator = 0;
int list[5] = {13, 12, 11, 10, 9};
  
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void pisca(int pino)
{
  digitalWrite(list[pino], HIGH);
  delay(50); // Wait for 1000 millisecond(s)
}

void desliga(int pino)
{
  digitalWrite(list[pino], LOW);
  delay(50); // Wait for 1000 millisecond(s)
}

void ligaOuDesliga(bool liga){
  int i = 0;
  for(i = 0; i < 5; i++){
    if(i%2==restoParImparComparator){
      if(liga){
        pisca(i);
      }else{
        desliga(i);
      }
    }
  }
}

void loop()
{
  ligaOuDesliga(true);
  delay(1000); // Wait for 1000 millisecond(s)
  ligaOuDesliga(false);
  if(restoParImparComparator == 0){
    restoParImparComparator = 1;
  }else{
    restoParImparComparator = 0;
  }
}
