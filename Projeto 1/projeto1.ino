String input = "";

const int FIRST_TEAM = 0;
const int SECOND_TEAM    = 0;

const int ONE_A = 3;
const int ONE_B = 4;
const int ONE_C = 5;
const int ONE_D = 6;
const int ONE_E = 7;
const int ONE_F = 8;
const int ONE_G = 9;

const int TWO_A = 10;
const int TWO_B = 11;
const int TWO_C = 12;
const int TWO_D = 13;
const int TWO_E = 14;
const int TWO_F = 15;
const int TWO_G = 16;

int DisplayPorts[2][10][10] = {{
                                {ONE_A, ONE_B, ONE_C, ONE_D, ONE_E, ONE_F},        //0
                                {ONE_B, ONE_C},                                    //1
                                {ONE_A, ONE_B, ONE_D, ONE_E, ONE_G},               //2
                                {ONE_A, ONE_B, ONE_C, ONE_D, ONE_G},               //3
                                {ONE_B, ONE_C, ONE_F, ONE_G},                      //4
                                {ONE_A, ONE_C, ONE_D, ONE_F, ONE_G},               //5
                                {ONE_C, ONE_D, ONE_E, ONE_F, ONE_G},               //6
                                {ONE_A, ONE_B, ONE_C},                             //7
                                {ONE_A, ONE_B, ONE_C, ONE_D, ONE_E, ONE_F, ONE_G}, //8
                                {ONE_A, ONE_B, ONE_C, ONE_F, ONE_G},               //9
                            },
                            {
                                {TWO_A, TWO_B, TWO_C, TWO_D, TWO_E, TWO_F},        //0
                                {TWO_B, TWO_C},                                    //1
                                {TWO_A, TWO_B, TWO_D, TWO_E, TWO_G},               //2
                                {TWO_A, TWO_B, TWO_C, TWO_D, TWO_G},               //3
                                {TWO_B, TWO_C, TWO_F, TWO_G},                      //4
                                {TWO_A, TWO_C, TWO_D, TWO_F, TWO_G},               //5
                                {TWO_C, TWO_D, TWO_E, TWO_F, TWO_G},               //6
                                {TWO_A, TWO_B, TWO_C},                             //7
                                {TWO_A, TWO_B, TWO_C, TWO_D, TWO_E, TWO_F, TWO_G}, //8
                                {TWO_A, TWO_B, TWO_C, TWO_F, TWO_G},               //9
                            }};

boolean ligaPonto = false;

void setup()
{
    Serial.begin(9600);

    for (int i = 0; i <= 16; i++)
    {
        pinMode(i, OUTPUT);
    }
}

void turnOffAllOne()
{
    for (int i = ONE_A; i <= ONE_G; i++)
    {
        pinMode(i, OUTPUT);
    }
}

void turnOffAllTwo()
{
    for (int i = TWO_A; i <= TWO_G; i++)
    {
        pinMode(i, OUTPUT);
    }
}

void loop()
{

    for (int i = 0; i < 10; i++)
    {
        if (firstDisplayPorts[0][i])
        {
            digitalWrite(secondDisplayPorts[0][i], HIGH);
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (secondDisplayPorts[0][i])
        {
            digitalWrite(secondDisplayPorts[0][i], HIGH);
        }
    }
    if (Serial.available())
    {
        input = Serial.readStringUntil('\n');
        int valor = (int)input[0] - '0';
        Serial.println(valor);

        //    turnOffAllOne();
        for (int i = 0; i < 10; i++)
        {
            if (firstDisplayPorts[valor][i])
            {
                digitalWrite(firstDisplayPorts[valor][i], HIGH);
            }
        }

        //    turnOffAllTwo();
        for (int i = 0; i < 10; i++)
        {
            if (secondDisplayPorts[valor][i])
            {
                digitalWrite(secondDisplayPorts[valor][i], HIGH);
            }
        }
    }
}
