#include <iostream>
#include <string>

using namespace std;

class Human
{
private:
	int wealth;
	int health;
	int age;
	string name;
public:
	Human(string toName, int toWealth)
	{
		name = toName;
		wealth = toWealth;
		age = 0;
		health = 100;
		cout << "A human named " << name << " was bron."<< endl;
	}
	~Human()
	{
		cout << "A human named " << name << " dies,he/she was " << age << endl;
	};
	int GetAge()
	{
		return age;
	};
	void AddAge(int number)
	{
		age += number;
	}
	string GetName()
	{
		return name;
	}
	int GetWealth()
	{
		return wealth;
	}
};
void IntroduceSelf(Human Aman)
{
	cout << "I am " << Aman.GetName() << ",I am " << Aman.GetAge() << ",I have " << Aman.GetWealth() << " yuan.;" << endl;
}
int main()
{
	Human* A = new Human("ZhangSan", 5000);
	Human* B = new Human("LiSi", 10000);
	(*A).AddAge(20);
	B->AddAge(25);
	IntroduceSelf(*A);
	IntroduceSelf(*B);
	delete A;
}