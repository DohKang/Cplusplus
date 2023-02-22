#include <iostream>
#include <cmath>

int main()
{
    std::string questions[] = {"1. What year was C++ inventeed?: ",
                               "2. Who invented C++? ",
                               "3. What is the predecessor of C++ ",
                               "4. Is the earth flat?"};
    std::string options[][4] = {{"A. 1969", "B. 1975", "C. 1985", "D. 1989"},
                                {"A. Guido van Rossum", "B. Bjarne Struoustrup", "C. John Carmack", "D. Mark Zackenberg"},
                                {"A. C", "B. C+", "C. C--", "D. B++"},
                                {"A. yes", "B. No", "C. sometimes", "D. It's square"}};
    char answerkey[] = {'C', 'B', 'A', 'B'};
    int size = sizeof(questions) / sizeof(questions[0]);
    int sizeoption = sizeof(options[0]) / sizeof(options[0][0]);
    char guess;
    int score;

    for (int i = 0; i < size; i++)
    {
        std::cout << "*******************\n";
        std::cout << questions[i] << "\n";
        for (int j = 0; j < sizeoption; j++)
        {
            std::cout << "   " << options[i][j] << "\n";
        }
        std::cin >> guess;
        guess = toupper(guess);
        if (guess == answerkey[i])
        {
            std::cout << "Correct!\n";
            score++;
        }
        else
        {
            std::cout << "Wrong!\n"
                      << "Answer is " << answerkey[i] << "\n";
        }
    }
    std::cout << "*******************\n";
    std::cout << "      Results     \n";
    std::cout << "*******************\n";
    std::cout << "CORRECT GUEESE: " << score << "\n";
    std::cout << "# of Questions: " << size << "\n";
    std::cout << "SCORE: " << (score / (double)size) * 100 << "%";
    return 0;
}

/*
    int num;
    int guess;
    int tries;

    srand(time(NULL));
    num = (rand() % 100) + 1; // 1~100

    std::cout << "****** Number Guessing Game******\n";
    do
    {
        std::cout << "Enter a guess between (1-100)";
        std::cin >> guess;
        if (guess > num)
        {
            std::cout << "Too high!\n";
        }
        else if (guess < num)
        {
            std::cout << "Too low\n";
        }
        else
        {
            std::cout << "Correct! #of tries: \n"
                      << tries;
        }
        tries++;
    } while (guess != num);
    std::cout << "*************************************\n";
*/

// calculator
// int main()
// {
//     char op;
//     double num1;
//     double num2;
//     double result;

//     std::cout << "************* CALCULATOR *************\n";

//     std::cout << "Enter #1: ";
//     std::cin >> num1;

//     std::cout << "Enter #2: ";
//     std::cin >> num2;

//     std::cout << " Enter either ( + - * /): ";
//     std::cin >> op;

//     switch (op)
//     {
//     case '+':
//         result = num1 + num2;
//         std::cout << "result: " << result << "\n";
//         break;

//     case '-':
//         result = num1 - num2;
//         std::cout << "result: " << result << "\n";
//         break;

//     case '*':
//         result = num1 * num2;
//         std::cout << "result: " << result << "\n";
//         break;

//     case '/':
//         result = num1 / num2;
//         std::cout << "result: " << result << "\n";
//         break;

//     default:
//         std::cout << "That was not valid input\n";
//         break;
//     }

//     std::cout << "************* ********** *************";

//     return 0;
// }

// temp conversion

// #include <iostream>

// int main()
// {
//     double temp;
//     char unit;

//     std::cout << "***** Temperature Conversion ******\n";
//     std::cout << "F = Fahrenheit\n";
//     std::cout << "C = Celcius\n";
//     std::cout << "WHat unit would you like to convert to";
//     std::cin >> unit;

//     if (unit == "F" || unit == 'f')
//     {
//         std::cout << "Enter the temperature in Celcius";
//         std::cin >> temp;
//         temp = (1.8 * temp) + 32;
//         std::cout << "Temperatrue is: " << temp << "F\n";
//     }
//     else if (unit == 'C' || unit == 'c')
//     {
//         std::cout << "Enter the temperature in Fahrenheit";
//         std::cin >> temp;
//         temp = (temp - 32) / 1.8;
//         std::cout << "Temperature is: " << temp << "C";
//     }
//     else
//     {
//         std::cout << "Please enter in only C or F\n";
//     }

//     return 0;
// }

// hypotenuse
//  int main()
//  {
//      double a;
//      double b;
//      double c;

//     std::cout << "Enter side A: ";
//     std::cin >> a;

//     std::cout << "Enter side B: ";
//     std::cin >> b;

//     // a = pow(a, 2);
//     // b = pow(b, 2);
//     c = sqrt(pow(a, 2) + pow(b, 2));
//     std::cout << "side C: " << c;
// }