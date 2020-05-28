const int pino_digital_direita = 2;
const int pino_digital_esquerda = 3;
const int pino_pwm = 6;
int dec = 80;

void setup()
{
    Serial.begin(9600);
    pinMode(pino_digital_esquerda, OUTPUT);
    pinMode(pino_digital_direita, OUTPUT);
}
void loop()
{
  	if(digitalRead(pino_digital_esquerda) == HIGH){
      if(dec >= 5 && dec<=255){
        dec -= 5;
      }
    }  
  
  	if(digitalRead(pino_digital_direita) == HIGH){
      if(dec >= 0 && dec<=250){
        dec += 5;
      }
    }
    
  	Serial.println(dec);
  	analogWrite(pino_pwm, dec);
  	delay(100);
}