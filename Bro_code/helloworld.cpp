#include <iostream>
#include <vector>
#include <cmath>
// function that contains input and output

int main(void)
{

    return 0;
}

/*
Useful math function

double x = 3.41;
double y = 4;
double z;

// z = std::max(x, y);
// z = std::min(x, y);.
// z = pow(x, y);
// z = sqrt(9);
// z = abs(-30);
// z = round(x);
// z = ceil(x);
//z = floor(x);
std::cout << z;
 */

/*      Type conversion
    = conversion a value of one data type to another
    implicit = automatic
    explicit = preced value with new data type(int)

/*  User input
    std::string name;
    int age;

    std::cout << "What's your name?: ";
    std::getline(std::cin >>std::ws // remove whitespace , name); // if we need to use space, this is the way to get space character

    std::cout << "What's your age?: ";
    std::cin >> age;

    std::cout << "Hello " << name << "\n";
    std::cout << "You are " << age << "Years old";
    // << insertion operator
    // >> extraction operator
*/
/*
int correct = 8;
int question = 10;
double score = correct / (double)question * 100; // truncate decimal point if we use int data type
std::cout << score << "%\n";

std::cout << (char)100 << "\n";

double x = (int)3.14;
std::cout << x << "\n";

char y = 100;
std::cout << y; // convert ascii code key for value 100
*/

/*  Typedef
    // typedef = reserved keyword used to create an additional name (alias) for another data type.
    // it is alias
    //  new identifier for an existing type
    // helps with readability and reduce typos

    // typedef std::vector<std::pair<std::string, int>> pairlist_t;
    // pairlist_t pairlist;
    // text_t firstname = "dohyun";
    // number_t age = 21;
    // std::cout << firstname << "\n";
    // std::cout << age;
    // typedef std::string text_t;
    // typedef int number_t;
    // text_t firstname = "Dohyun";
    //     using text_t = std::string;
    // using number_t = int;
    // number_t age = 21;
    // std::cout << firstname << "\n"
    //           << age;
*/

/*      NameSPACE

namespace first
{
    int x = 1;
}
namespace second
{
    int x = 2;
}
    solution for same variable conflicts.
    using std::cout;
    using std::string;
    using namespace first;
    using namespace std;

    cout << x;
    // std::cout << first::x;
    // std::cout << second::x;
    //:: scope resolution
*/

/*      CONSTANT
    const double PI = 3.14159; // secure data
    // you can't do PI = 420;
    double radius = 10;
    double circumference = 2 * PI * radius;
    const int LIGHT_SPEED = 2299792458;
    const int WIDTH = 1920;
    const int HEIGHT = 1080;

    std::cout << circumference << "cm";
    // constant = read-only variable
*/

/* VARIABLE OF BOOL, CHAR, STRING, INT, ETC
    int age = 21;
    int year = 2023;
    int days = 7.5; // int only can hold integer value. decimal point will be truncated
    std::cout << days << '\n';
    // double (number with decimal point)
    double price = 10.99;
    double gpa = 2.5;
    double temp = 25.1;

    std::cout << gpa << '\n';

    // single character
    char grade = 'A';
    char currency = '$';
    char initial = 'Bc'; // show last character of word
    std::cout << initial << '\n';
    std::cout << currency << '\n';

    // boolean (True of False)
    bool student = false;
    bool power = true;
    bool forSale = true;

    // string (objects represent sequence of text)
    std::string name = "Doh";
    std::string day = "Friday";
    std::string food = "pizza";
    std::string address = "123123123 facebook";
    std::cout << name << "\n";
    std::cout << address << "\n";

    std::cout << "Hello " << name << "\n";
    std::cout << "You are " << age << "years old";
*/

/*
int x; // declaration
x = 5; // assignment
int y = 6;
std::cout << x << "\n";
std::cout << y << "\n";
int sum = x + y;
std::cout << sum << "\n";
*/

/*
std::cout << "I like pizza!"
            << "\n"; // std::endl; // end line
std::cout << "It's really good!" << std::endl;
return 0;
*/

// if we return all the way 0; it means there was no issue.
// std::cout: standard character output
/* */