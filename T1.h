#pragma once
#include <string>
#include <iostream>
using namespace std;

class SymString
{
protected:
	string id = "t1_id";
	string s;
	int value;
public:
	SymString() = default;
	SymString(const string& id, const string& val) : id(id), s(val) {}

	void Show() const;
	void SetS(const string value) { this->s;  }
	string getS() const { return s; }
	string getId() const { return id; }

	friend SymString operator+(const SymString& s1, const SymString& s2);
	friend bool operator==(const SymString& sym, const string& str);
};