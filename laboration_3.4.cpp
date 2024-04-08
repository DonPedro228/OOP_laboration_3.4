#include <iostream>
#include <string>
#include <sstream>
#include "T1.h"
#include "T2.h"
#include "Factory.h"
#include <iomanip>

using namespace std;

int main() {
	string c;
	string id1, val1;
	string id2, val2;

	SymString* sym1 = nullptr;
	DecString* bin1 = nullptr;
	SymString* sym2 = nullptr;
	DecString* bin2 = nullptr;

	DecString* resultDec = nullptr;
	int menu;
	do {
		cout << endl << endl;
		cout << "Choose exersice: " << endl << endl;
		cout << " [1] - create SymString" << endl;
		cout << " [2] - create DecString" << endl;
		cout << " [3] - cout string" << endl;
		cout << " [4] - cout Dec in Bin" << endl;
		cout << " [5] - plus SumString" << endl;
		cout << " [6] - plus DecString" << endl;
		cout << " [7] - delete SymString" << endl;
		cout << " [8] - delete DecString" << endl;
		cout << " [0] - exit and end work" << endl;
		cout << "Input value: "; cin >> menu;
		cout << endl << endl;
		switch (menu)
		{
		case 1:
			cout << "Enter identifier: ";
			cin >> id1;
			cout << "Enter value: ";
			cin >> val1;
			sym1 = Factory::CreateEl1(id1, val1);
			cout << "Object created.\n";
			break;
		case 2:
			cout << "Enter identifier: ";
			cin >> id2;
			cout << "Enter value: ";
			cin >> val2;
			bin1 = Factory::CreateEl2(id2, val2);
			cout << "Object created.\n";
			break;
		case 3:
			if (sym1) {
				cout << "Values: " << sym1->getS() << endl;
			}
			else {
				cout << "No object created" << endl;
			}

			if (bin1) {
				cout << "Values: " << bin1->getS() << endl;
			}
			else {
				cout << "No object created" << endl;
			}
			break;
		case 4:
			if (bin1) {
				bin1->ShowBin();
			}
			else {
				cout << "No object created" << endl;
			}
			break;
		case 5:
			if (sym1) {
				cout << "Enter identifier: ";
				cin >> id1;
				cout << "Enter value: ";
				cin >> val1;
				sym2 = Factory::CreateEl1(id1, val1);
				SymString* result = new SymString("", "");
				*result = *sym1 + *sym2;

				delete sym1;
				sym1 = result;
				sym1->Show();
			}
			else
				cout << "No object created!" << endl;
			break;
		case 6:
			cout << "Enter identifier: ";
			cin >> id2;
			cout << "Enter value: ";
			cin >> val2;
			bin2 = Factory::CreateEl2(id2, val2);
			if (bin1 && bin2) {
				*bin1 = *bin1 + *bin2;
				bin1->ShowBin();
			}
			else {
				cout << "No object created or missing values." << endl;
			}
			break;
		case 7: 
			if (sym1) {
				Factory::Delete(sym1);
				sym1 = nullptr;
				cout << "Object deleted" << endl;
			}
			else {
				cout << "SymString not created yet"<< endl;
			}
			break;
		case 8: 
			if (bin1) {
				Factory::Delete(bin1);
				bin1 = nullptr;
				cout << "Object deleted" << endl;
			}
			else {
				cout << "HexString not created yet" << endl;
			}
			break;
		case 0: 
			if (sym1) {
				Factory::Delete(sym1);
			}
			if (bin1) {
				Factory::Delete(bin1);
			}
			cout << "Exiting.." << endl;
			break;
		default:
			cout << "You choose mistake value!" << endl;
		}
	}while(menu != 0);

	return 0;
}