#include <iostream>

int main()
{

    return 0;
}

/*   Function template
describes what a function look like
can be used to generate as many overloaded functions as needed, each using different data time

template <typename T, typename U>

// int max(int x, int y)
// {
//     return (x > y) ? x : y;
// }
// double max(double x, double y)
// {
//     return (x > y) ? x : y;
// }
// char max(char x, char y)
// {
//     return (x > y) ? x : y;
// }

auto max(T x, U y)
{
return (x > y) ? x : y;
}

std::cout << max(1, 2.1) << "\n";
*/

/*  recursive
pros: less code and cleaner. useful for sorting and searching
cons: uses more memory, slower

// walk(100);

std::cout << factorial(10);
void walk(int steps);
int factorial(int num);

int factorial(int num)
{
if (num > 1)
{
    num *= factorial(num - 1);
    return num;
}
else
{
    return 1;
}
}
void walk(int steps)
{
if (steps > 0)
{
    std::cout << "You take a step!\n";
    walk(steps - 1);
}
// for (int i = 0; i < steps; i++)
// {
//     std::cout << "You take a step!\n";
// }
}
*/
/*  Dynamic memory
memory allocated after the program is compiled and running
use the 'new' operator to allocate memory in the heap rather than the sttack
useful when we don't know how much memory we will need
make our programs more flexible,
especially when accepting user input;

int *pNum = NULL;

pNum = new int;
*pNum = 21;
std::cout << "address: " << pNum << "\n";
std::cout << "value: " << *pNum << "\n";

delete pNum;

char *pGrades = NULL;

int size;
std::cout << "How many grades to enter in?: ";
std::cin >> size;
pGrades = new char[size];
for (int i = 0; i < size; i++)
{
    std::cout << "Enter grade #" << i + 1 << ": ";
    std::cin >> pGrades[i];
}
for (int i = 0; i < size; i++)
{
    std::cout << pGrades[i] << " ";
}
delete[] pGrades;
*/

/* Null value = a special value that has no value
when a pointer is holding a null value
that pointer is not pointing at anything(null pointer)

nullptr = keyword represents a null pointer literal

nullptrs are helpful when determininf if an address was successfully assigned to a pointer

int *pointer = nullptr;
int x = 123;

pointer = &x;
// if pointer is not assigned yet. it could cause undefined behavior.
if (pointer == nullptr)
{
    std::cout << "address was not assigned";
}
else
{
    std::cout << "address was assigned";
    std::cout << *pointer;
}

*/

/*  Pointers
sometimes it is eaasier to work with an address
& address of operator
* dereference operator

std::string name = "Bro";
std::string *pName = &name;

int age = 21;
int *pAge = &age;

std::string freepizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};
std::string *pFreepizzas = freepizzas;

std::cout << *pAge << "\n";
std::cout << *pName << "\n";
std::cout << *pFreepizzas << "\n";
*/

/*  const parameter
parameter that is effectively read only
code is secure & convey intentt
useful for references and pointers
when we pass arguement. that argument can not be changed in the function.

void printInfo(const std::string name, const int age);
std::string name = "Dohyun";
int age = 21;
printInfo(name, age);
void printInfo(const std::string name, const int age)
{

std::cout << name << "\n";
std::cout << age << "\n";
}
*/

/* Pass by Value, Pass by reference
void swap(std::string &x, std::string &y);
std::string x = "Kool-aid";
std::string y = "Water";

swap(x, y);

std::cout << "X: " << x << "\n";
std::cout << "Y: " << y << "\n";
void swap(std::string &x, std::string &y)
{
std::string temp;
temp = x;
x = y;
y = temp;
}
*/