#include <iostream>
#include <ctime>
#include <cstdlib>

int arrayAnimal[4][5];
int checkAnimal[4][5];
std::string strAnimal[10];
void initAniamlArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestion();
int foundAllAnimals();

//-------------------------------------
//-------------------------------------

int main()
{
    srand(time(NULL));
    initAniamlArray();
    initAnimalName();
    shuffleAnimal();
    int failCount = 0;

    while (1)
    {
        int select1 = 0;
        int select2 = 0;
        printAnimals();
        printQuestion();
        std::cout << "Please pick two cards to flip";
        std::cout << "First:";
        std::cin >> select1;
        std::cout << "Second:";
        std::cin >> select2;

        if (select1 == select2)
        {
            std::cout << "Please pick 2 seperate card\n";
            continue;
        }
        int firstSelect_x = conv_pos_x(select1);
        int firstSelect_y = conv_pos_x(select1);
        int secondSelect_x = conv_pos_x(select2);
        int secondSelect_y = conv_pos_x(select2);

        if (checkAnimal[firstSelect_x][firstSelect_y] == 0 &&
            checkAnimal[secondSelect_x][secondSelect_y] == 0 &&
            arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y])
        {
            std::cout << "BINGO! YOU FOUND" << strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]];
            checkAnimal[firstSelect_x][firstSelect_y] = 1;
            checkAnimal[secondSelect_x][secondSelect_y] = 1;
        }
        else
        {
            std::cout << "Wrong Guess. Try again..\n";
            std::cout << "The cards you fliped were\n"
                      << strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]] << ",\n"
                      << strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]];
            failCount++;
        }
        if (foundAllAnimals() == 1)
        {
            std::cout << "**Congrats. You found all animals";
            std::cout << "You missed " << failCount << " chances this round";
        }
    }

    return 0;
}

//-------------------------------------
//-------------------------------------
void initAniamlArray()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arrayAnimal[i][j] = -1;
        }
    }
}

void initAnimalName()
{
    strAnimal[0] = "Monkey";
    strAnimal[1] = "Zebra";
    strAnimal[2] = "Horse";
    strAnimal[3] = "Dog";
    strAnimal[4] = "Lion";
    strAnimal[5] = "Camel";
    strAnimal[6] = "Lama";
    strAnimal[7] = "Slut";
    strAnimal[8] = "Eagle";
    strAnimal[9] = "Tiger";
}

void shuffleAnimal()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int pos = getEmptyPosition();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);

            arrayAnimal[x][y] = i;
        }
    }
}

int getEmptyPosition()
{ // xxxxx 0 1 2 3 4//
  // xxxxx 5 6 7 8 9//
  // xxxxx 1011121314//
  // xxxxx 1516171819//
    while (1)
    {
        int randPos = rand() % 20; // 0~19
        // 19 --> row 3 column 4
        int x = conv_pos_x(randPos);
        int y = conv_pos_y(randPos);

        if (arrayAnimal[x][y] == -1)
        {
            return randPos;
        }
    }
}
int conv_pos_x(int x)
{
    return x % 5;
}

int conv_pos_y(int y)
{
    return y % 5;
}

void printAnimals()
{
    std::cout << "*********** Cheat Sheet ***********\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << strAnimal[arrayAnimal[i][j]];
        }
        std::cout << "\n";
    }
    std::cout << "*********** Cheat Sheet END***********\n";
}
void printQuestion()
{
    std::cout << "\n\n Question\n\n";
    int seq = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (checkAnimal[i][j] != 0)
            {
                std::cout << strAnimal[arrayAnimal[i][j]];
            }
            else
            {
                std::cout << seq;
            }
            seq++;
        }
        std::cout << "\n";
    }
}
int foundAllAnimals()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (checkAnimal[i][j] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}