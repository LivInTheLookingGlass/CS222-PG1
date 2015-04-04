//Gabe Appleton, CS222
//This is the header file for the program which will grab the square root and remainder of any counting number
#ifndef _Header_
#define _Header_

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main (int argc, char **argv);
string sum (string a, string b);
string mult (string a, string b);
int compare (string a, string b);
string subtract(string a, string b, bool orig);
string rmLeadZero(string input);
void sqrt_weird(string radicand, string &answer, string &remainder);
string toString(int a);

#endif
