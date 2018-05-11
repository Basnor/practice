#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
using namespace std;


//
// OrderOfBracketsChecker class
// Класс предназначен для проверки правильности порядка скобок в строке 
//
class OrderOfBracketsChecker
{
public:
	//прверка полученной строки
	bool StringChecker(string& checking_string);

private:
	stack <char> open_breckets;
};

bool OrderOfBracketsChecker::StringChecker(string& checking_string)
{
	//возможные скобки для проверки
	static const string search_breackets = "{}<>()";
	int index;

	//перебираем каждый символ в полученной строке
	for (unsigned int i = 0; i < checking_string.length(); i++)
	{
		//поиск скобок и определение их индекса в строке search_breackets
		index = search_breackets.find(checking_string[i]); 
		if (index >= 0)
		{
			if (index % 2 == 0) open_breckets.push(checking_string[i]); //если скобка открывающая
			else
			{
				if (!open_breckets.empty())
				{
					//сравниваем последнюю открытую скобку с открытыт типом текущей скобки 
					if (open_breckets.top() == search_breackets[index - 1])
						open_breckets.pop();
					else return 0;
				}
				else return 0;
			}
		}
		else continue;
	}

	if (open_breckets.empty())
		return 1;
	else return 0;
}


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