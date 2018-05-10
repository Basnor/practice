#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;

class CheckString
{
private:
	void get_result(bool result);  //вывод результата проверки
	stack <char> open_breckets;

public:
	CheckString(char checked_string[]);   //поверка по полученной строке
};

CheckString::CheckString(char checked_string[])
{
	static const char search_breackets[] = "{}<>()";
	unsigned int checked_symb;

	for (checked_symb = 0; checked_symb < strlen(checked_string); checked_symb++) //перебираем каждый символ в строке
	{
		for (unsigned int n = 0; n < strlen(search_breackets); n++)  //перебираем строку с имеющимся скобками
		{
			if (search_breackets[n] == checked_string[checked_symb])
			{
				if (n % 2 == 0) open_breckets.push(checked_string[checked_symb]); //если скобка открывающая
				else
				{
					if (!open_breckets.empty())
					{
						if (open_breckets.top() == search_breackets[n - 1]) //аналог открывающей скобки
							open_breckets.pop();
						else get_result(false);
					}
					else get_result(false);
				}
				break;
			}
			else continue;
		}
	}

	if (open_breckets.empty())
		get_result(true);
	else get_result(false);

}

void CheckString::get_result(bool result)
{
	if (result) cout << "Верно\n";
	else {
		cout << "Неверно\n";
		system("pause");
		exit(0);
	}
}


int main()
{
	setlocale(LC_ALL, "Rus");
	char checked_string[] = "{}({}(<>){})";
	cout << "Введи строку:\n";
	cin >> checked_string;

	CheckString check(checked_string);

	system("pause");
	return 0;
}