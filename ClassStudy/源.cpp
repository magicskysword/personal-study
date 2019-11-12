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
	}
	int GetAge()
	{
		return age;
	}
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

	Human A("ZhangSan", 10000);
	Human B("LiSi", 50000);
	A.AddAge(20);
	B.AddAge(25);
	IntroduceSelf(A);
	IntroduceSelf(B);
}