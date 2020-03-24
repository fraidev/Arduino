const int listNumbers[5] = {13, 12, 11, 10, 9};
const int buttonLeft = 8;
const int buttonRight = 7;
int count = 0;

void setup()
{
    Serial.begin(9600);
    for (int i = 7; i <= 13; i++)
    {
        pinMode(i, OUTPUT);
    }
}

void pisca(int pino)
{
    digitalWrite(listNumbers[pino], HIGH);
    delay(1000);
    digitalWrite(listNumbers[pino], LOW);
}

int canMove()
{
    return (count >= 0 && count <= 4);
}

void loop()
{
    int buttonStateLeft = digitalRead(buttonLeft);
    int buttonStateRight = digitalRead(buttonRight);

    if (buttonStateLeft == HIGH && canMove())
    {
        pisca(count);

        count--;

        if (!canMove())
        {
            count = 0;
        }
    }
    if (buttonStateRight == HIGH && canMove())
    {
        pisca(count);
        count++;

        if (!canMove())
        {
            count = 4;
        }
    }
}
