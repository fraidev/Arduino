int list[5] = {13, 12, 11, 10, 9};
int first = 0;
int last = 4;
bool liga = true;
  
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void pisca()
{
  digitalWrite(list[first], HIGH);
  digitalWrite(list[last], HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
}

void desliga()
{
  digitalWrite(list[first], LOW);
  digitalWrite(list[last], LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}

void ligaOuDesliga(){
}

void loop()
{
  pisca();
  desliga();
  if(first == 4 && last == 0){
    first = 0;
    last = 4;
  }else{
    first++;
    last--;
  }
  
  delay(1000); // Wait for 1000 millisecond(s)
}
