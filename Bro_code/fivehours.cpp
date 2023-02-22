#include <iostream>

class Shape
{
public:
    double area;
    double volume;
};

class Cube : public Shape
{
public:
    double side;
    Cube(double side)
    {
        this->side = side;
        this->area = side * side * 6;
        this->volume = side * side * side;
    }
};

class Sphere : public Shape
{
public:
    double radius;
    Sphere(double radius)
    {
        this->radius = radius;
        this->area = 4 * 3.14159 * (radius * radius);
        this->volume = (4 / 3.0) * 3.14159 * (radius * radius * radius);
    }
};

class Animal
{
public:
    bool alive = true;

    void eat()
    {
        std::cout << "YAM YAM YAM\n";
    }
};
class Dog : public Animal
{
public:
    void bark()
    {
        std::cout << "The dog goes woof!\n";
    }
};

class Cat : public Animal
{
public:
    void meow()
    {
        std::cout << "The cat goes meow!";
    }
};
int main()
{

    /* Inheritance = A class can receive attributes and methods from another class
                    Children classes inherit from a Parent class
                    helps to reuse similar code found within mulitple classes

    */
    // Dog dog;
    // std::cout << dog.alive << "\n";
    // dog.eat();
    // dog.bark();

    // Cat cat;
    // std::cout << cat.alive << "\n";
    // cat.eat();
    // cat.meow();

    Cube cube(10);
    Sphere sphere(5);
    std::cout << "Area: " << sphere.area << " cm"
              << "\n";
    std::cout << "Area: " << sphere.volume << " cm"
              << "\n";
    return 0;
}

/*
Abstraction = hiding unnecessary data from outside a class
getter = function that makes a private attribute READABLE
setter = function that makes a private attribute WRITEABLE

Stove stove(2);
// stove.temperature = 1000;

std::cout << "The temperature setting is : " << stove.getTemperature() << "\n";
class Stove
{
private: // No longer access this attribute outside of this class
int temperature = 0;

public:
Stove(int temperature)
{
    setTemperature(temperature);
}
int getTemperature()
{
    return temperature;
}
void setTemperature(int temperature)
{
    if (temperature < 0)
    {
        this->temperature = 0;
    }
    else if (temperature >= 10)
    {
        this->temperature = 10;
    }
    else
    {
        this->temperature = temperature;
    }
}
};
*/

/* Overloaded constructors
multiple constructors w/ same name as long as it contains different parameters
allows for varying arguemnts when instantiating an objext;

class Pizza
{
public:
std::string topping1;
std::string topping2;

Pizza()
{
}

Pizza(std::string topping1)
{
    this->topping1 = topping1;
}
Pizza(std::string topping1, std::string topping2)
{
    this->topping1 = topping1;
    this->topping2 = topping2;
}
};
Pizza pizza1("pepperoni");
Pizza pizza2("mushroom", "pepper");
Pizza pizza3;
std::cout << pizza2.topping1 << "\n";
std::cout << pizza2.topping2 << "\n";

*/
/*Constructor
special method that is automatically called when an object is instantiated
useful for assigning vlaues to attributes as arguements;
class Students
{
public:
std::string name;
int age;
double gpa;
Students(std::string x, int y, double z)
{
    name = x;
    age = y;
    gpa = z;
}
// Students(std::string name, int age, double gpa)
// {
//     this->name = name;
//     this->age = age;
//     this->gpa = gpa;
// }
};
class Car
{
public:
std::string make;
std::string model;
int year;
std::string color;
Car(std::string make, std::string model, int year, std::string color)
{
    this->make = make;
    this->model = model;
    this->year = year;
    this->color = color;
}
};

// Students student1("Spongebob", 12, 2.37);
// Students student2("Patrick", 21, 2.11);
// Students student3("Sandy", 23, 3.1);
// std::cout << student3.name << "\n";
// std::cout << student3.age << "\n";
// std::cout << student3.gpa << "\n";
Car car1("Ford", "Mustang", 1992, "silver");
Car car2("Toyota", "Camry", 2020, "black");

std::cout << car1.make << "\n";
std::cout << car1.model << "\n";
std::cout << car1.year << "\n";
std::cout << car1.color << "\n";
std::cout << car2.make << "\n";
std::cout << car2.model << "\n";
std::cout << car2.year << "\n";
std::cout << car2.color << "\n";
*/

/* object = A collection of attributes and methods ** work like struct system + method
 they can have characteristics and could perform actions
 can be used to mimic real world items( ex, phone, book)
 created from a class which acts as a "blue-print"


class Car
{
public:
 std::string make;
 std::string model;
 int year;
 std::string color;

 void accelerate()
 {
     std::cout << "You step on the gas!\n";
 }
 void brake()
 {
     std::cout << "you step on the brake\n";
 }
};
class Human
{
public:
 std::string name = "Rick";
 std::string occupation = "scientist";
 int age = 70;

 void eat()
 {
     std::cout << "This person is eating\n";
 }
 void drink()
 {
     std::cout << "This person is drinking\n";
 }
 void sleep()
 {
     std::cout << "This person is sleeping\n";
 } // method: class own function
};

 Human human1;
 // human1.name = "Rick";
 // human1.occupation = "scientist";
 // human1.age = 21;

 Human human2;
 // human2.name = "Morty";
 // human2.occupation = "student";
 // human2.age = 15;
 // std::cout << human1.name << "\n";
 // std::cout << human1.occupation << "\n";
 // std::cout << human1.age << "\n";

 // std::cout << human2.name << "\n";
 // std::cout << human2.occupation << "\n";
 // std::cout << human2.age << "\n";

 // human2.eat();
 // human2.drink();
 // human2.sleep();

 Car car1;
 car1.make = "Ford";
 car1.model = "Mustang";
 car1.year = 2023;
 car1.color = "silver";

 std::cout << car1.make << "\n";
 std::cout << car1.model << "\n";
 std::cout << car1.year << "\n";
 std::cout << car1.color << "\n";
 car1.accelerate();
 car1.brake();

     */

/*
enums = a user-defined data type that consists of paired named-integer constants
great if you hav a set of potential options

enum Day
{
sunday = 0,
monday = 1,
tuesday = 2,
wednesday = 3,
thursday = 4,
friday = 5,
saturday = 6
};
enum Flavor {vanilla, chocolate, strawberry, mint}; //automatically assign ascending order from 0
Day today = sunday;

switch (today)
{
case 0:
    std::cout << "It is Sunday!\n";
    break;
}
 */

/* pass struct as an argument
struct Car
{
std::string model;
int year;
std::string color;
};
void printCar(Car car);
void paintCar(Car &car, std::string color);
Car car1;
Car car2;

car1.model = "Mustang";
car1.year = 1993;
car1.color = "yellow";

car2.model = "Camry";
car2.year = 2016;
car2.color = "blue";
paintCar(car1, "black");
printCar(car1);void printCar(Car car)
{
std::cout << car.model << "\n";
std::cout << car.year << "\n";
std::cout << car.color << "\n";
// struct is worked as pass by value, add &(reference) to work directly.
}
void paintCar(Car &car, std::string color) //make changes to original
{
car.color = color;
}
*/

/*    struct
can contain many different data types
variables in a struct are known as "members"
members can be access with. "Class Member Acess Operator"


struct student
{
std::string name;
double gpa;
bool enrolled = true; // make defualt
};
student student1;
student1.name = "Spongebob";
student1.gpa = 3.2;
// student1.enrolled = true;

student student2;
student2.name = "Patrick";
student2.gpa = 2.1;
// student2.enrolled = true;

student student3;
student3.name = "Squidward";
student3.gpa = 1.5;
student3.enrolled = false;

std::cout << student1.name << "\n";
std::cout << student1.gpa << "\n";
std::cout << student1.enrolled << "\n";

std::cout << student2.name << "\n";
std::cout << student2.gpa << "\n";
std::cout << student2.enrolled << "\n";

std::cout << student3.name << "\n";
std::cout << student3.gpa << "\n";
std::cout << student3.enrolled << "\n";
*/