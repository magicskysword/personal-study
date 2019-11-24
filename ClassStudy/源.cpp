#include <iostream>
#include <string>

using namespace std;
int HumanIdNum = 1;
enum humanFrom
{
	East = 0,
	West = 1 
};
class Human
{
private:
	int wealth;
	int health;
	int age;
	string givenName;
	string familyName;
	int* id = new int;
	friend class Dog;
	humanFrom from;
public:
	Human(string lastname, string firstName, humanFrom fromWhere) //构造函数
	{
		givenName = firstName;
		familyName = lastname;
		wealth = 0;
		age = 0;
		from = fromWhere;
		health = 100;
		*id = HumanIdNum;
		HumanIdNum += 1;
		cout << "A human named " << GetName() << " was bron.His/Her id is "<< GetId() <<endl;
	}
	~Human() //析构函数
	{
		cout << "A human named " << GetName() << " dies,he/she was " << GetAge() << ".His/Her id is " << GetId() << endl;
		delete id;
	};
	Human(const Human& copyHuman) //复制构造函数
	{
		id = new int;
		memcpy(id, copyHuman.id, sizeof(int));
		*id *= -1;
		givenName = copyHuman.givenName;
		familyName = copyHuman.familyName;
		wealth = copyHuman.wealth;
		age = copyHuman.age;
		health = copyHuman.health;
		from = copyHuman.from;
		cout << givenName + "" + familyName << " was copied" << endl;
		givenName += "\'s copy";
	}
	int GetAge()
	{
		return age;
	};
	int GetId()
	{
		return *id;
	};
	void AddAge(int number)
	{
		age += number;
	};
	string GetName()
	{
		string nameTmp;
		switch (from)
		{
		case West:
			nameTmp = givenName + " " + familyName;
			break;
		case East:
			nameTmp = familyName + givenName;
			break;
		};
		return nameTmp;
	};
	int GetWealth()
	{
		return wealth;
	}
	void AddWealth(int number)
	{
		wealth += number;
	};
};
class Dog
{
public:
	Dog(Human& AMan)
	{
		cout << AMan.GetName() << " buy a dog." << endl;
	}
};
void IntroduceSelf(Human Aman)
{
	cout << "I am " << Aman.GetName() << ",I am " << Aman.GetAge() << ",I have " << Aman.GetWealth() << " yuan,my id is " << Aman.GetId() << endl;
};
int main()
{
	Human* A = new Human("Zhang","San",East);
	Human* B = new Human("Sparta","Dante",West);
	(*A).AddAge(20);
	B->AddAge(25);
	IntroduceSelf(*A);
	IntroduceSelf(*B);
	Dog DA(*A);
	Dog DB(*B);
	delete A;
}