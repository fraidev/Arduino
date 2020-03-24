const int listNumbers[5] = {13, 12, 11, 10, 9};
const int buttonTwo = 8;
const int buttonOne = 7;

int restoParImparComparator = 0;
int count = 0;
int first = 0;
int last = 4;
bool liga = true;

bool channelOne = false;
bool channelTwo = false;

int currentButtonChannelOneState = LOW;
int currentButtonChannelTwoState = LOW;

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
}

void desliga(int pino)
{
    digitalWrite(listNumbers[pino], LOW);
}

int canMove()
{
    return (count >= 0 && count <= 4);
}

void ligaOuDesliga(bool liga)
{
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        if (i % 2 == restoParImparComparator)
        {
            if (liga)
            {
                pisca(i);
            }
            else
            {
                desliga(i);
            }
        }
    }
}

void turnOnAll()
{
    digitalWrite(listNumbers[first], HIGH);
    digitalWrite(listNumbers[last], HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
}

// void turnOffAll()
// {
//     digitalWrite(listNumbers[first], LOW);
//     digitalWrite(listNumbers[last], LOW);
// }

void turnOffAll()
{
    for (int i = 0; i < 5; i++)
    {
        desliga(i);
    }
}

void loop()
{
    int channelOne = digitalRead(buttonOne);
    int channelTwo = digitalRead(buttonTwo);

    if (!channelOne && !channelTwo)
    {
        turnOffAll();
    }
    if (channelOne && !channelTwo)
    {
        for (int i = 0; i < 5; i++)
        {
            pisca(i);
            delay(200); // Wait for 1000 millisecond(s)
        }
    }
    if (!channelOne && channelTwo)
    {
        ligaOuDesliga(true);
        delay(1000); // Wait for 1000 millisecond(s)
        ligaOuDesliga(false);
        if (restoParImparComparator == 0)
        {
            restoParImparComparator = 1;
        }
        else
        {
            restoParImparComparator = 0;
        }
    }
    if (channelOne && channelTwo)
    {
        turnOnAll();
        turnOffAll();
        if (first == 4 && last == 0)
        {
            first = 0;
            last = 4;
        }
        else
        {
            first++;
            last--;
        }
    }
}