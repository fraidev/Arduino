const int pino_analogico = A0;
const int list[5] = {2, 3, 4, 5, 6};
const int maxDec = 1023;
const int divisor = 1023 / 3;

int first = 0;
int last = 4;
bool liga = true;
int restoParImparComparator = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
}
void loop()
{
    int dec = analogRead(pino_analogico);
    Serial.print("Decimal: ");
    Serial.print(dec);
    float tensao = converter_tensao(dec);
    Serial.print(" | Tensao: ");
    Serial.println(tensao);

    int value = dec / divisor;
    if (value == 0)
    {
        parImpar();
    }
    if (value == 1)
    {
        sequencial();
    }
    if (value >= 2)
    {
        pontasAoMeio();
    }

    Serial.println(value);

    delay(15);
}

void ligaOuDesliga(bool liga)
{
    for (int i = 0; i < 5; i++)
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

void sequencial()
{
    for (int i = 5; i >= 0; i--)
    {
        pisca(i);
        delay(1000);
        desliga(i);
    }
}

void pontasAoMeio()
{
    pisca(first);
    pisca(last);
    delay(1000);
    desliga(first);
    desliga(last);
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

void parImpar()
{
    ligaOuDesliga(true);
    delay(1000);
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

float converter_tensao(int dec)
{
    return (5 * float(dec)) / maxDec;
}

void pisca(int pino)
{
    digitalWrite(list[pino], HIGH);
}

void desliga(int pino)
{
    digitalWrite(list[pino], LOW);
}