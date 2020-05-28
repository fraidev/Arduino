const int pino_digital_direita = 2;
const int pino_digital_esquerda = 3;
const int pino_pwm1 = 9;
const int pino_pwm2 = 6;
const int pino_pwm3 = 5;

int dec = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(pino_digital_esquerda, OUTPUT);
    pinMode(pino_digital_direita, OUTPUT);
  
    pinMode(pino_pwm1, OUTPUT);
    pinMode(pino_pwm2, OUTPUT);
    pinMode(pino_pwm3, OUTPUT);
}
void loop()
{
  	if(digitalRead(pino_digital_esquerda) == HIGH){
      if(dec >= 5 && dec<=765){
        dec -= 5;
      }
    }  
  
  	if(digitalRead(pino_digital_direita) == HIGH){
      if(dec >= 0 && dec<=760){
        dec += 5;
      }
    }
    
  	Serial.println(dec);
  	
  	if(dec <= 255){
      analogWrite(pino_pwm1, dec);
    }
  	
  	if(dec >= 255 && dec <= 510){
      analogWrite(pino_pwm2, dec - 255);
    }
  	
  	if(dec >= 510 && dec <= 765){
      analogWrite(pino_pwm3, dec - 510);
    }
  
  	delay(100);
}
