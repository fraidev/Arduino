
void setup()
{
    pinMode(10, OUTPUT);
    Serial.begin(9600);
}
void loop()
{
    if (digitalRead(10) == HIGH)
    {
        Serial.println("ON");
    }
    else
    {
        Serial.println("OFF");
    }

    delay(300);
}