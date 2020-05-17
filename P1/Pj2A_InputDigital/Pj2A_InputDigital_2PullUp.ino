
void setup()
{
    Serial.begin(9600);
    pinMode(10, INPUT_PULLUP);
}
void loop()
{
    if (digitalRead(10) == LOW)
    {
        Serial.println("ON");
    }
    else
    {
        Serial.println("OFF");
    }

    delay(300);
}