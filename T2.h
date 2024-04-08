#pragma once
#include "T1.h"
#include <iostream>
#include <string>
using namespace std;

class DecString : public SymString
{
public:
	DecString() : SymString() {}
	DecString(const string& id, const string& val) : SymString(id, val) {}

	void ShowBin() const;

	
	friend DecString operator+(const DecString& s1, const DecString& s2);
};