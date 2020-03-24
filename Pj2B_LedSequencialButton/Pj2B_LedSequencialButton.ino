const int listNumbers[5] = {13, 12, 11, 10, 9};
const int buttonPin = 8;

int count = 0;

void setup()
{
    Serial.begin(9600);
    for (int i = 8; i <= 13; i++)
    {
        pinMode(i, OUTPUT);
    }

    pinMode(buttonPin, INPUT);
}

void pisca(int pino)
{
    digitalWrite(listNumbers[pino], HIGH);
    delay(1000);
    digitalWrite(listNumbers[pino], LOW);
}

void loop()
{
    int buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH)
    {
        pisca(count);
        count++;

        if (count >= 5)
        {
            count = 0;
        }
    }
}
