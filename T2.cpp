#include "T2.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <bitset>
using namespace std;

void DecString::ShowBin() const {
    int value = stoi(getS());
    bitset<32> bits(value);
    cout << "Bin value of " << getId() << ": " << bits << endl; 
}

DecString operator+(const DecString& s1, const DecString& s2) {
    int sum = stoi(s1.getS()) + stoi(s2.getS());
    return DecString(s1.getId(), to_string(sum));
}


