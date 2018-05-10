#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;

const char search_breackets[] = "{}<>()";

int main()
{
	setlocale(LC_ALL, "Rus");

	char checked_string[] = "{}({}(<>){})";
	cout << "Введи строку:\n";
	cin >> checked_string;

	stack <char> open_breckets;

	//проверка каждого символа введеной строки
	for (int checked_symb = 0; checked_symb < strlen(checked_string); checked_symb++)
	{
		for (int n = 0; n < strlen(search_breackets); n++)//перебор имеющихся скобок
		{
			if (search_breackets[n] == checked_string[checked_symb]) 
			{
				if (n % 2 == 0) open_breckets.push(checked_string[checked_symb]);//если скобка открывающая
				else
				{
					if (!open_breckets.empty())
					{
						if (open_breckets.top() == search_breackets[n - 1]) //аналог открывающей скобки
							open_breckets.pop();
						else {
							cout << "Неверно\n";
							system("pause");
							exit(0);
						}
					}
					else {
						cout << "Неверно\n";
						system("pause");
						exit(0);
					}
				}
				break;
			}
			else continue;
		}
	}

	if (open_breckets.empty())
		cout << "Верно " << '\n';
	else cout << "Неверно " << '\n';

	system("pause");
	return 0;
}
