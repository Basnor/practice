#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "OrderOfBracketsChecker.h"
using namespace std;

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