#include <iostream>
using std::string;

class AbstractEmployee 
{
	virtual void AskForPromotion()=0; //become pure virtual function. abstract function
};


class Employee: AbstractEmployee
{
private:
	string Company;
	int Age;
protected:
	string Name;
public:
	void setName(string name) //setter 
	{

		Name = name;
	}
	string getName() 
	{
		return Name;
	}
	void setCompany(string company) //setter 
	{
		Company = company;
	}
	string getCompany()
	{
		return Company;
	}
	void setAge(int age)  //setter 
	{
		if (age > 17)
		{
			Age = age;
		}
		
	}
	int getAge()
	{
		return Age;
	}

	void IntroduceYourself()
	{
		std::cout << "Name -" << Name << std::endl;
		std::cout << "Company -" << Company << std::endl;
		std::cout << "Age -" << Age << std::endl;
	}
	void AskForPromotion() 
	{
		if (Age > 30)
			std::cout << Name << " got promoted" << std::endl;
		else
		{
			std::cout << Name << ", sorry No promotion for you!" << std::endl;
		}
	}
	Employee(string name, string company, int age) 
	{
		Name = name;
		Company = company;
		Age = age;
	}
	virtual void Work() //Virtual function is invoked, please check whether my derived class have a same name function, and if yes, execute that one instead for me.
	{
		std::cout << Name << " is checking email, task backlog, performing task...." << std::endl;
	}
};
class Developer : public Employee 
{
public:
	string FavProgrammingLanguage;
	Developer(string name, string company, int age, string favProgrammingLanguage)
		:Employee(name, company, age)
	{
		FavProgrammingLanguage = favProgrammingLanguage;
	}
	void FixBug() 
	{
		std::cout << Name << " fixed bug using" << FavProgrammingLanguage << std::endl;
		
	}
	void Work()
	{
		std::cout << Name << " is writing " << FavProgrammingLanguage << " code" << std::endl;
	}
};

class Teacher : public Employee 
{
public:
	string Subject;
	void PrepareLesson() 
	{
		std::cout << Name << " is prepareing " << Subject << " lesson" << std::endl;
	}
	Teacher(string name, string company, int age, string subject)
		:Employee(name, company, age)
	{
		Subject = subject;
	}
	void Work()
	{
		std::cout << Name << " is teaching " << Subject << std::endl;
	}
};

int main()
// The most common use of polymorphism is when a 
//parent class reference is used to refer to a child class object
{
	Developer d = Developer("Dohyun", "Newcastle", 40, "C++");
	Teacher t = Teacher("Saldina", "YT", 35, "Math");
	Employee* e1 = &d;
	Employee* e2 = &t;

	e1->Work();
	e2->Work();

	//d.FixBug();
	//d.FixBug();
	//d.FixBug();
	//d.AskForPromotion();

	
	//d.Work();
	//t.Work();
	
	//t.PrepareLesson();
	//t.AskForPromotion();
	//Employee employee1 = Employee("Dohyun", "Newcastle",20);
	//employee1.IntroduceYourself();

	//Employee employee2 = Employee("John", "Amazon", 35);
	//employee2.IntroduceYourself();
	
	//employee1.AskForPromotion();
	//employee2.AskForPromotion();

	/*employee1.setName("Saldina");
	employee1.setAge(39);
	employee1.setCompany("Youtuber");
	employee1.IntroduceYourself();
	std::cout << employee1.getName() << "is " << employee1.getAge() << " years old" << std::endl;*/
}