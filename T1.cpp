#include "T1.h"
#include <iostream>
#include <string>
using namespace std;

void SymString::Show() const
{
	cout << "Value of " << id << ": " << s << endl;
}

SymString operator+(const SymString& s1, const SymString& s2) {
    string result = s1.getS() + s2.getS();
    return SymString("", result);
}

bool operator==(const SymString& sym, const string& str)
{
    return sym.getS() == str;
}
