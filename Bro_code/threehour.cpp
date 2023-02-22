#include <iostream>

int main()
{

    return 0;
}

/* 2d array

std::string cars[][3] = {{"Mustang", "Escape", "F-150"},
                         {"Corvette", "Equinox", "Silverado"},
                         {"Challenger", "Durango", "Ram1500"}};

int rows = sizeof(cars) / sizeof(cars[0]);
int columns = sizeof(cars[0]) / sizeof(cars[0][0]);

for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < columns; j++)
    {
        std::cout << cars[i][j] << " ";
    }
    std::cout << "\n";
// std::cout << cars[0][0] << " ";
// std::cout << cars[0][1] << " ";
// std::cout << cars[0][2] << " \n";
// std::cout << cars[1][0] << " ";
// std::cout << cars[1][1] << " ";
// std::cout << cars[1][2] << " \n";
// std::cout << cars[2][0] << " ";
// std::cout << cars[2][1] << " ";
// std::cout << cars[2][2] << " ";
}
  */

/*  User_input in array
std::string foods[5];
int size = sizeof(foods) / sizeof(foods[0]);
std::string temp;

for (int i = 0; i < size; i++)
{
    std::cout << "Enter a food you like or 'q' to quit #" << i + 1 << ": \n";
    std::getline(std::cin, temp);
    if (temp == "q")
    {
        break;
    }
    else
    {
        foods[i] = temp;
    }
}
std::cout << "You like the following food \n";

for (int i = 0; !foods[i].empty(); i++)
{
    std::cout << foods[i] << "\n";
}
*/

/*  Fill
fills a range of elements with a specified value
fill(begin, end, value)

const int SIZE = 99;
std::string foods[SIZE];
fill(foods, foods + SIZE / 3, "pizza");
fill(foods + SIZE / 3, foods + SIZE * 2 / 3, "hamburger");
fill(foods + SIZE * 2 / 3, foods + SIZE, "hotdog");
for (std::string food : foods)
{
    std::cout << food << "\n";
}
// std::string foods[10] = {"pizza", "pizza", "pizza", "pizza", "pizza", "pizza", "pizza", "pizza", "pizza", "pizza"};
// for (std::string food : foods)
// {
//     std::cout << food << "\n";
// }
*/

/*  Sort array
void sort(int arrayp[], int size);
    int array[] = {6, 10, 9, 5, 4, 1, 7, 8, 2, 3};
    int size = sizeof(array) / sizeof(array[0]);

    sort(array, size);
    for (int element : array)
    {
        std::cout << element << " ";
    }
void sort(int array[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
*/
/*      search through array

std::string foods[] = {"pizza", "hamburger", "hotdog"};
int size = sizeof(foods) / sizeof(foods[0]);
std::string myFood;
// int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// int size = sizeof(numbers) / sizeof(numbers[0]);
int index;
// int myNum;

std::cout << "Enter food to search for \n";
std::getline(std::cin, myFood);

index = searchArray(foods, size, myFood);
if (index != -1)
{
    std::cout << myFood << " is at index " << index << "\n";
}
else
{
    std::cout << myFood << " is not in the array";
}
int searchArray(std::string foods[], int size, std::string element);
int searchArray(std::string foods[], int size, std::string element)
{
for (int i = 0; i < size; i++)
{
    if (foods[i] == element)
    {
        return i;
    }
}
return -1; // something wasn't find
}

*/

/* Pass array to function
    double getTotal(double prices[], int size);


double prices[] = {49.99, 15.05, 75, 9.99};
int size = sizeof(prices) / sizeof(prices[0]);
double total = getTotal(prices, size);
double getTotal(double prices[], int size)
{
    double total = 0;
    for (int i = 0; i < size; i++)
    {
        total = total + prices[i];
    }
    return total;
}

std::cout << "$" << total;
*/

/* for each loop
loop that eases the traversal over an iterable data set
std::string students[] = {"spongebob", "Patrick", "Squidward", "Sandy"};
for (std::string student : students)
{
    std::cout << student << "\n";
}

int grades[] = {24, 57, 65, 87};
for (int grade : grades)
{
    std::cout << grade << "\n";
}
*/

/* iterate over for loop

char grades[] = {'A', 'B', 'C', 'D', 'F'};
for (int i = 0; i < sizeof(grades) / sizeof(grades[0]); i++)
{
    std::cout << grades[i] << "\n";
}

std::string students[] = {"spongebob", "Patrick", "Squidward"};
// std::cout << students[0] << "\n";
// std::cout << students[1] << "\n";
// std::cout << students[2] << "\n";

for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++)
{
    std::cout << students[i] << "\n";
}
*/

/*      sizeof operator -- get the byte size of variable
std::string name = "dohyun  kang is the one who did thathghhhhhhhhhhhhhhhhhhhhhhhhhhh";
// sizeof()
char gpa = '2'; //1byte
bool student = true; // 1byte
// int = 4byte, double = 8byte
char grades[] = {'A', 'B', 'C', 'D', 'F'}; //this case 5byte
std::cout << sizeof(grades)/sizeof(grades[0]) << "elements\n"; // get total array's element size
std::cout << sizeof(name) << "bytes\n";

std::string students[] = {"spongebob", "Patrick", "Squidward"};
std::cout << sizeof(students) << "students\n"; // 96 bytes..
*/

/*  Array

    double prices[] = {5.00, 7.50, 9.99, 15.00};

    std::cout << prices[0] << "\n";
    std::cout << prices[1] << "\n";
    std::cout << prices[2] << "\n";
    std::cout << prices[3] << "\n";
    std::string cars[] = {"Corvette", "Mustang", "Camry"};
    // array has to be same data type

    std::string tea[3];

    tea[0] = "Herbal";
    tea[1] = "Not herbal";

    std::cout << tea[0] << "\n";
    std::cout << tea[1] << "\n";

    cars[0] = "Camaro";
    std::cout << cars[0] << "\n";
    std::cout << cars[1] << "\n";
    std::cout << cars[2] << "\n";
*/