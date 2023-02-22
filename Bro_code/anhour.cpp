#include <iostream>
#include <ctime>

int myNum = 3;

void printNum();
int main()
{
    /* Variable scope
     */
    int myNum = 1;
    std::cout << ::myNum << "\n";
    printNum();
    return 0;
}
void printNum()
{
    int myNum = 2;
    std::cout << myNum << "\n";
}
/*Overloaded function
each function's param has to be unique;
bakePizza();
void bakePizza(std::string topping1, std::string topping2);
void bakePizza(std::string topping1);
void bakePizza();
void bakePizza()
{
    std::cout << "Here is your pizza!\n";
}
void bakePizza(std::string topping1)
{
    std::cout << "Here is your " << topping1 << " pizza!";
}
void bakePizza(std::string topping1, std::string topping2)
{
    std::cout << "Here is your " << topping1 << " and " << topping2 << " pizza!";
}

/* return Type
std::string firstName = "Dohyun";
std::string lastName = "Kang";
std::string fullName = concatStrings(firstName, lastName);
std::cout << "Hello " << fullName;
std::string concatStrings(std::string string1, std::string string2);
std::string concatStrings(std::string string1, std::string string2)
{
    return string1 + " " + string2;
}
*/
/*
// function type should be match with return type
double square(double length);
double cube(double length);
double length = 5.0;
double area = square(length);
double volume = cube(length);
std::cout << "Area: " << area << "cm^2\n";
std::cout << "Volume: " << volume << "cm^3";
double square(double length)
{
    double result = length * length;
    return result;
}

double cube(double length)
{
    double result = length * length * length;
    return result;
}
*/

/*  Function
void happyBirthday(std::string name, int age);
    // function = a block of resusable code
    std::string name = "Doh";
    int age = 21;
    happyBirthday(name, age);
    happyBirthday(name, age);
    happyBirthday(name, age);

void happyBirthday(std::string happybirthdayboi, int age)
{
    std::cout << "Happy Birthdayt to you \n"
              << happybirthdayboi << '\n';
    std::cout << "Happy Birthdayt to you \n"
              << happybirthdayboi << '\n';
    std::cout << "Happy Birthdayt dear you \n"
              << happybirthdayboi << '\n';
    std::cout << "Happy Birthdayt to you " << happybirthdayboi << '\n';
    std::cout << "You are " << age << "Years old";
}
*/
/* RANDOM EVENT
    srand(time(0));
    int randNUm = (rand() % 5) + 1;
    switch (randNUm)
    {
    case 1:
        std::cout << "You win a bumper stickers!\n";
        break;
    case 2:
        std::cout << "You win a T-shirt!\n";
        break;
    case 3:
        std::cout << "You win a $20!\n";
        break;
    case 4:
        std::cout << "You win a lollypop!\n";
        break;
    case 5:
        std::cout << "You win a bumper car!\n";
        break;
    }
    */

/* random number
srand(time(NULL)); // us current time as  a seed

int num = (rand() % 20) + 1; // without + 1 for dice, you need 0 ~ 5 , 1~20 for dungeon & dragon
int num1 = (rand() % 6) + 1;
int num2 = (rand() % 6) + 1;
int num3 = (rand() % 6) + 1;
std::cout << num1 << "\n";
std::cout << num2 << "\n";
std::cout << num3 << "\n";
/*


/* Nested loop
int rows;
int columns;
char symbol;

std::cout << "How many rows?: ";
std::cin >> rows;

std::cout << "How many columns?: ";
std::cin >> columns;

std::cout << "Enter a symbol to use: ";
std::cin >> symbol;

for (int j = 0; j < rows; j++)
{
for (int i = 0; i < columns; i++)
{
    std::cout << symbol;
}
std::cout << "\n";
}
*/

/*  Break or continue
    for (int i = 20; i >= 3; i -= 2)
    {
        if (i < 10)
        {
            break; // continue
        }
        std::cout << i << "\n";
    }
*/

/*  For loop
for (int i = 10; i >= 1; i -= 4)
{
    std::cout << i << "\n";
}
std::cout << "Happy New Year";
*/

/*  DO WHILE
 do while loop = do some block of code first,
 then repeat again if condition is true



int number; // if we don't specify, it default to 0
do
{
    std::cout << "Enter a positive number: ";
    std::cin >> number;
} while (number < 0);

std::cout << "The number is :" << number;
*/

/* While

std::string name;
while (name.empty())
{
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
}
std::cout << "Hello " << name;
*/

/* Useful String method


std::string name;
std::cout << "Enter your name: ";
std::getline(std::cin, name);

name.erase(0, 3); // delete 0, 1, 2 index
std::cout << "Your name is ?" << name;
// std::cout << name.find(" "); find certain character's index

// name.insert(0, "@"); // insert at certain index
// std::cout << "Your name " << name;
// std::cout << name.at(0);

// name.clear(); // string get cleared
// name.append("@gmail.com");

// std::cout << "Your email address is: " << name;
// if (name.empty())
// {
//     std::cout << "You didn't enter your name";
// }
// else
// {
//     std::cout << "Welcome" << name;
// }
// if (name.length() > 12)
// {
//     std::cout << "Your name can't be over 12 characters";
// }
// else
// {
//     std::cout << "Welcome " << name;
// }
*/

/*  LOGICAL OPERATOR
&& || !(reverse the logical state of its operand)

int temp;
std::cout << "What is the temperature outside";
std::cin >> temp;

if (temp > 0 && temp < 30)
{
    std::cout << "The temperature is good";
}
else
{
    std::cout << "The temperature is bad";
}

bool sunny = false;
if (!sunny)
{
    std::cout << "It is sunny outside";
}
else
{
    std::cout << "It is not good";
}
*/

/*
    ternary operator ?:
    replacement to an if/else statement
    condition? expression 1 : expression 2

int grade = 50;
grade >= 60 ? std::cout << "You passed" : std::cout << "You failed";

int number = 8;
number % 2 ? std::cout << "It's Odd" : std::cout << "It's an even number!";

bool hungry = true;
std::cout << (hungry ? "You are hungry\n" : "You are full\n");
hungry ? std::cout << "Order pizza!" : std::cout << "Let's watch TV";
*/

/*
        Switches
        alternative to using many "else if"

int month;
std::cout << "Enter the month (1-12): ";
std::cin >> month;

switch (month)
{
case 1:
    std::cout << "It is January";
    break;
case 2:
    std::cout << "It is February";
    break;
case 3:
    std::cout << "It is March";
    break;
case 4:
    std::cout << "It is April";
    break;
case 5:
    std::cout << "It is May";
    break;
default:
    std::cout << "Please enter in only numbers (1-12)";
}


char grade;
std::cout << "What letter grade?: ";
std::cin >> grade;
switch (grade)
{
case 'A':
    std::cout << "You are awesome";
    break;
case 'B':
    std::cout << "You did good";
    break;
case 'C':
    std::cout << "You did okay";
    break;
case 'D':
    std::cout << "You should be better";
    break;
case 'F':
    std::cout << "Ohoh...";
    break;
default:
    std::cout << "Please enter one letter for grading";
}
 */

/* IF statemnet
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;
    if (age >= 100)
    {
        std::cout << "You are too old for this site";
    }
    else if (age >= 18)
    {
        std::cout << "Welcome to the site";
    }
    else if (age < 0)
    {
        std::cout << "You haven't been born yet";
    }
    else
    {
        std::cout << "Access denied";
    }
*/