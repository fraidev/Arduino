
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
  int list[5] = {13, 12, 11, 10, 9};
  digitalWrite(list[pino], HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(list[pino], LOW);
}

void loop()
{
  int i = 0;
  for(i = 0; i < 5; i++){
    pisca(i);
  }
}
