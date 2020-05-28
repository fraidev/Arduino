const int pino_digital = 2;
const int pino_pwm = 6;
int dec = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(pino_digital, OUTPUT);
}
void loop()
{
  	if(digitalRead(pino_digital) == HIGH){
      if(dec >= 0 && dec<=250){
        dec += 5;
      }
    }else if(dec >= 5 && dec<=255){
        dec -= 5;
    }
    
  	Serial.println(dec);
  	analogWrite(pino_pwm, dec);
  	delay(100);
}