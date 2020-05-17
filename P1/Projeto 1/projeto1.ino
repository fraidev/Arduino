String input = "";

const int FIRST_TEAM = 0;
const int SECOND_TEAM = 0;

const int ONE_A = 2;
const int ONE_B = 3;
const int ONE_C = 4;
const int ONE_D = 5;
const int ONE_E = 6;
const int ONE_F = 7;
const int ONE_G = 8;

const int TWO_A = 9;
const int TWO_B = 10;
const int TWO_C = 11;
const int TWO_D = 12;
const int TWO_E = 14;
const int TWO_F = 15;
const int TWO_G = 16;

int DISPLAY_PORTS[2][10][10] = {{
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

enum serial_state
{
    Menu,
    TeamOne,
    TeamTwo
} state;

void setup()
{
    Serial.begin(9600);

    for (int i = 0; i <= 16; i++)
    {
        pinMode(i, OUTPUT);
    }

    turnOnDisplay(0, 0);
    turnOnDisplay(1, 0);

    printMenu();
    state = Menu;
}

void loop()
{
    if (Serial.available())
    {
        input = Serial.readStringUntil('\n');
        int valor = (int)input[0] - '0';

        if (state == TeamOne)
        {
            turnOnDisplay(0, valor);
            state = Menu;
        }

        if (state == TeamTwo)
        {
            turnOnDisplay(1, valor);
            state = Menu;
        }

        if (input[0] == 'a' || input[0] == 'A')
        {
            Serial.println("Informe Gols do Time 1");
            state = TeamOne;
        }

        if (input[0] == 'b' || input[0] == 'B')
        {
            Serial.println("Informe Gols do Time 2");
            state = TeamTwo;
        }

        if (input[0] == 'c' || input[0] == 'C')
        {
            turnOnDisplay(0, 0);
            turnOnDisplay(1, 0);
            Serial.println("Placar zerado");
        }

        if (state == Menu)
        {
            printMenu();
        }
    }
}

void turnOffDisplay(int display)
{
    int init, limit;
    if (display == 0)
    {
        init = ONE_A;
        limit = ONE_G;
    }
    else
    {
        init = TWO_A;
        limit = TWO_G;
    }

    for (int i = init; i <= limit; i++)
    {
        pinMode(i, LOW);
    }
}

void turnOnDisplay(int display, int number)
{
    turnOffDisplay(display);
    for (int i = 0; i < 10; i++)
    {
        if (DISPLAY_PORTS[display][number][i])
        {
            digitalWrite(DISPLAY_PORTS[display][number][i], HIGH);
        }
    }
}

void printMenu()
{
    Serial.println("\nA - Placar Time 1? \nB - Placar Time 2? \nC - Zerar placar\n");
}