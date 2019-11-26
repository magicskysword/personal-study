#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int HumanIdNum = 0;
class Human
{
public:
	enum HumanFrom
	{
		East = 0,
		West = 1,
		South = 2,
		North = 3
	};
	enum HumanSex
	{
		male = 0,
		female = 1,
	};
	enum HumanCall
	{
		personal = 0,
		possessive = 1,
	};
	Human()
	{
		*id = HumanIdNum;
		HumanIdNum += 1;
		cout << "A human was bron."<< GetCall(possessive, false)<< " ID is " << *id << endl;
	}
	virtual ~Human()
	{
		cout << "A human was dead."<< GetCall(possessive, false)<<" ID is " << *id << endl;
		delete id;
	}
	virtual string GetName() = 0;
	string GetCall(HumanCall what,bool upper)
	{
		string First;
		string Last;
		First = "h";
		if (what == personal)
		{
			if (sex == male)
			{
				Last = "e";
			}
			if (sex == female)
			{
				First = "s";
				Last = "he";
			}
		}
		if (what == possessive)
		{
			if (sex == male)
			{
				Last = "is";
			}
			if (sex == female)
			{
				Last = "er";
			}
		}
		if (upper == true)
		{
			transform(First.begin(), First.end(), First.begin(), ::toupper);
		}
		return First + Last;
	}
protected:
	HumanFrom from;
	HumanSex sex;
	string familyName;
	string givenName;
	int wealth;
	int health;
	int age;
	int* id = new int;
};
class Chinese:public Human
{
public:
	Chinese(string nameFirst, string nameLast, Human::HumanSex whichSex)
	{
		familyName = nameFirst;
		givenName = nameLast;
		sex = whichSex;
		from = Human::East;
		age = 0;
		health = 100;
		wealth = 0;
		cout << GetName() << " come the world." << endl;
	}
	~Chinese() override final
	{
		cout << GetName() << " stop " << GetCall(possessive,false) << " breath." << endl;
	};
	string GetName() override final
	{
		return familyName + givenName;
	}
private:

};
class American :public Human
{
public: 
	American(string nameFirst, string nameLast, Human::HumanSex whichSex)
	{
		familyName = nameLast;
		givenName = nameFirst;
		sex = whichSex;
		from = Human::East;
		age = 0;
		health = 100;
		wealth = 0;
		cout << GetName() << " step the world." << endl;
	}
	~American() override final
	{
		cout << GetName() << " give up " << GetCall(possessive, false) << " mind." << endl;
	};
	string GetName() override final
	{
		return familyName + " " + givenName;
	}
private:

};

int main()
{
	Chinese A("Zhang","San", Human::male);
	American B("Dante", "Sparta", Human::male);
}