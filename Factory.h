#pragma once
#include <iostream>
#include <string>
#include "T1.h"
#include "T2.h"
#include <iomanip>
using namespace std;

class Factory
{
public:
	static SymString* CreateEl1(const string& id, const string& val) { return new SymString(id, val); }
	static DecString* CreateEl2(const string& id, const string& val) { return new DecString(id, val); }

	static void Delete(SymString* obj) { delete obj; }
	static void Delete(DecString * obj) { delete obj; }
};