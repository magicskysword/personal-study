#include<iostream>
#include<sstream>
#include<string>

using namespace std;
class star
{
private:
	int num;
	string pic;
	string starString;
public:
	star() :num(1), pic("*") {};
	~star()
	{
		cout << "The stars fall." << endl;
	}
	star& operator ++ ()//前置运算重载
	{
		++num;
		pic += "*";
		return *this;
	}
	star operator ++ (int)//后置运算重载
	{
		star copy(*this);
		++num;
		pic += "*";
		return copy;
	}
	operator const char* ()//转换运算符重载
	{
		ostringstream starInfo;
		starInfo << "Star num:" << num << endl << "The picture:" << pic << endl;
		starString = starInfo.str();//用私有成员保存，防止临时变量返回时被销毁
		return starString.c_str();
	}
	star operator + (int addNum)//加减运算符重载
	{
		star newStar = *this;
		newStar.num += addNum;
		for (int i = 0; i < addNum; i++)
		{
			newStar.pic += "*";
		};
		return newStar;
	}
	star operator - (int addNum)
	{
		star newStar = *this;
		newStar.num -= addNum;
		if (newStar.num <= 0)
		{
			newStar.num = 0;
			newStar.pic = "";
		}
		else
		{
			newStar.pic = newStar.pic.substr(0, newStar.num);
		}
		return newStar;
	}
	star operator + (star addStar)//同类型加减运算符重载
	{
		star newStar;
		newStar.num = num + addStar.num;
		newStar.pic = pic + addStar.pic;
		return newStar;
	}
	star operator - (star addStar)//同类型加减运算符重载
	{
		star newStar;
		newStar.num = num - addStar.num;
		if (newStar.num <= 0)
		{
			newStar.num = 0;
			newStar.pic = "";
		}
		else
		{
			newStar.pic = pic.substr(0, newStar.num);
		}
		return newStar;
	}
	void operator += (int addNum)//自增自减运算符重载
	{
		num += addNum;
		for (int i = 0; i < addNum; i++)
		{
			pic += "*";
		};
	}
	void operator -= (int addNum)
	{
		num -= addNum;
		if (num <= 0)
		{
			num = 0;
			pic = "";
		}
		else
		{
			pic = pic.substr(0, num);
		}
	}
	bool operator == (const star& compareTo)//比较运算符重载
	{
		return (num == compareTo.num && pic == compareTo.pic);
	}
	bool operator != (const star& compareTo)
	{
		return !(*this == compareTo);
	}
	star& operator= (const star& starCopy)//重载赋值运算符
	{
		num = starCopy.num;
		pic = starCopy.pic;
		return *this;
	}
	star(const star& starCopy)//复制构造函数
	{
		num = starCopy.num;
		pic = starCopy.pic;
	}
	void show()//函数运算符
	{
		cout << "Star num:" << num << endl;
		cout << "The picture:" << pic << endl;
	}
	void operator ()()
	{
		cout << pic << endl;
		cout << "Star across.So beautiful!" << endl;
	}
};
int main()
{
	star A;
	A += 5;
	cout << A;
	star B = A+10;//使用复制构造函数
	star C;
	C = B - 1;//使用复制运算符
	cout << B;
	cout << C;
	star D;
	D = B - A;
	cout << D;
	if (A == A) { cout << "true" << endl; }
	if (A != B) { cout << "true" << endl; }
	if (A != A) { cout << "true" << endl; }//不会输出
	if (A == B) { cout << "true" << endl; }//同上
	A();
	B();
	C();
}