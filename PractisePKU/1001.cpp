// input R and n output R^n

#include<iostream>
#include<string>
using namespace std;

class bignumber
{
public:
	string number;
	int point;
	bignumber(string strnum)
	{
		const int pointnum = strnum.find(".");
		point = strnum.length() - pointnum-1;
		number = strnum.substr(0, pointnum) + strnum.substr(pointnum + 1, point);
		//cout << point << "/" << number << endl;
	}
	string mutiply(bignumber& bignum)
	{
		int numlength = bignum.number.length();
		int mylength = number.length();
		string* strPointer = new string[numlength];
		for (int i = 0; i < numlength; i++)
		{
			string theStrNum = "";
			for (int k = 0; k <= mylength; k++) 
			{
				theStrNum += "0";
			}
			for (int j = 0; j < mylength; j++)
			{
				int a = bignum.number[numlength - i - 1] - 48;
				int b = number[mylength - j - 1] - 48;
				string c = to_string(a * b);
				//cout << c << endl;
				if (c.length() == 1)
				{
					theStrNum[mylength - j] = c[0];
				}
				else
				{
					theStrNum[mylength - j] = c[1];
					theStrNum[mylength - j - 1] = c[0];
				}
			}
			*(strPointer+i) = theStrNum;
			//cout << theStrNum << endl;
		}
		int lastNumLength = (strPointer + numlength - 1)->length() + numlength -2;
		//cout << lastNumLength << endl;
		string theStrNum = "";
		for (int k = 0; k < lastNumLength; k++)
		{
			theStrNum += "0";
		}
		for (int i = 0; i < numlength;i++)
		{
			for (int j = 0; j < mylength;j++)
			{
				int a = theStrNum[lastNumLength - 1 - j - i] - 48;
				string strTmp = *(strPointer + i);
				int b = strTmp[mylength - j] - 48;
				string c = to_string(a + b);
				if (c.length() == 1)
				{
					theStrNum[lastNumLength - 1 - j - i] = c[0];
				}
				else
				{
					theStrNum[lastNumLength - 1 - j - i] = c[1];
					theStrNum[lastNumLength - 2 - j - i] = c[0];
				}
			}
		}
		point += bignum.point;
		string tmp = "0";
		number = theStrNum;
		string thelaststring = theStrNum.substr(0, theStrNum.length() - point) + "." + theStrNum.substr(theStrNum.length() - point, point);
		
		delete[] strPointer;
		
		cout << thelaststring << endl;
		return thelaststring;
		
	}
};

int main()
{
	string R;
	int n;
	cin >> R >> n;
	bignumber bigR(R);
	bignumber bigM(R);
	string strTmp;
	for (int i = 0; i < n-1 ;i++)
	{
		strTmp = bigM.mutiply(bigR);
		//bigM = bignumber(strTmp);
	}
	cout << strTmp << endl;
}