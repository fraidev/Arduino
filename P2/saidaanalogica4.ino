const int pino_analogico = A0;
const int list[5] = {2, 3, 4, 5, 6};
const int maxDec = 1023;
const float divisor = 1000 / 4;

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
    Serial.print(tensao);
    float litros = converter_litros(dec);
    Serial.print(" | Litros: ");
    Serial.println(litros);

    int value = litros / divisor;

    pisca(value);
    delay(1000);
    desliga(value);

    delay(15);
}

float converter_tensao(int dec)
{
    return (5 * float(dec)) / maxDec;
}

float converter_litros(int dec)
{
    return (1000 * float(dec)) / maxDec;
}

void pisca(int pino)
{
    digitalWrite(list[pino], HIGH);
}

void desliga(int pino)
{
    digitalWrite(list[pino], LOW);
}