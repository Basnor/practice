#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "OrderOfBracketsChecker.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	string checking_string;
	cout << "Введи строку:\n";
	cin >> checking_string;

	OrderOfBracketsChecker orderOfBracketsChecker;
	bool is_correct = orderOfBracketsChecker.StringChecker(checking_string);

	if (is_correct) cout << "Верно\n";
	else cout << "Неверно\n";

	system("pause");
	return 0;
}