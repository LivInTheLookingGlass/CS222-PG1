//Gabe Appleton, CS222
//This is the main file for the program which will grab the square root and remainder of any counting number
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include "Header.h"
using namespace std;

int main (int argc, char **argv) {

	string answer, remainder, input;
	cout << "What would you like to find the square root of?" << endl;
	getline(cin,input);
	sqrt_weird(input,answer,remainder);

	cout << "The square root of " << input << " is " << answer;
	if (remainder != "0")
		cout << " with a remainder of " << remainder;
	cout << "." << endl;
	system ("pause");

	return 0;
}

//This method returns the sum of two counting numbers
string sum (string a, string b) {

	string s = "";
	while (a.length() < b.length())
		a = "0"+a;
	while (b.length() < a.length()) 
		b = "0"+b;
	a = "0"+a;
	b = "0"+b;
	int carry = 0;
	for (int i=a.length()-1; i >= 0; i--) {
		int S = a[i]-'0' + b[i]-'0' + carry;
		carry = S/10;
		S %= 10;
		s = ((char)(S+'0')) + s;
	}
	while (s[0] == '0')
		s = s.substr(1);
	return s;
}

//This method returns the product of two counting numbers
string mult (string a, string b) {

	string s = "0";
	for (int i=0; i < (int)a.length(); i++)
		for (int j=0; j < (int)b.length(); j++) {
			int p = (a[i]-'0')*(b[j]-'0');
			string pstr = ((string)"")+(char)(p/10+'0')+(char)(p%10+'0');
			for (int k=0; k < (int)a.length()-i-1 + (int)b.length()-j-1; k++)
				pstr += "0";
			s = sum (s,pstr);
		}
	while (s[0] == '0')
		s = s.substr(1);
	return s;
}

//This method returns a comparison of two counting numbers. It's sign will match a-b, or 0 if they match
int compare (string a, string b)	{

	while (a.length() < b.length())
		a = "0"+a;
	while (b.length() < a.length())
		b = "0"+b;
	for (int i = 0; i < a.length(); i++)	{
		if (a[i] != b[i])
			return (a[i]>b[i])*1+(a[i]<b[i])*(-1); //returns 1 if a > b, -1 if a < b
	}
	return 0;
}

//This method returns the difference of two counting numbers
string subtract(string a, string b, bool orig) {

	while (a.length() < b.length())
		a = "0"+a;
	while (b.length() < a.length())
		b = "0"+b;
	int comp = compare(a,b);
	int carry = 0;
	if (comp == 0)
		return "0";
	else if (comp < 0)	{
		a = subtract(b,a, false);
	}
	else 
		for (int i = a.length()-1; i >= 0; i--)	{
			int S =( a[i]-'0') - (b[i]-'0');
			while (S < 0)	{
				a = subtract(a.substr(0,i),"1", false) + a.substr(i);
				S += 10;
			}
			a[i] = S+'0';
	}
	if (orig)
		return rmLeadZero(a);
	return a;
}

//This method returns the a counting number with no leading zeros
string rmLeadZero(string input)	{
	while (input[0] == '0')
		input = input.substr(1);
	return input;
}

//This method returns the square root and remainder of a counting number
void sqrt_weird(string radicand, string &answer, string &remainder)	{
	vector<string> table(1);
	answer = "0";
	string orig = radicand;
	table[0] = "1";
	string i = "4";
	while (compare(i,radicand) != 1)	{
		table.push_back(i);
		i = mult(i,"4");
	}
	table.shrink_to_fit();
	for (int i =  (int)table.size() - 1; i >= 0; i--)    { //This is the part that's broken???
        string multiple = mult(table[i],sum("1",mult("4",answer)));
		answer = mult(answer, "2");
		if (compare(radicand, multiple) != -1)	{
			radicand = subtract(radicand,multiple,true);
			answer = sum(answer,"1");
		}
	}
	remainder = radicand;
}

//This method returns the string version of a counting number
string toString(int a)	{
	stringstream ss;
	ss << a;
	return ss.str();
}
