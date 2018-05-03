#include "stdafx.h"
#include <iostream>
#include <stack>

const char breckets[] = "{}<>()";

int main()
{
	setlocale(LC_ALL, "Rus");
	char ver_str[] = "{}({}(<>){})";
	//char ver_str[] = "a+b";

	std::stack <char> Stack_br;

	std::cout << ver_str << '\n';

	for (int i = 0; i < strlen(ver_str); i++)
	{
		for (int n = 0; n < strlen(breckets); n++)
		{
			if (breckets[n] == ver_str[i])
			{
				if (n % 2 == 0) { Stack_br.push(ver_str[i]); }
				else
				{
					if (!Stack_br.empty())
					{
						if (Stack_br.top() == breckets[n - 1])
						{
							//std::cout << "clear: " << Stack_br.top() << '\n';
							Stack_br.pop();
						}
						else {
							std::cout << "Ошибка: позиция " << i + 1 << " , символ " << ver_str[i] << '\n';
							std::cin.get();
							exit(0);
						}
					}
					else {
						std::cout << "Ошибка: позиция "
							<< i+1 << " , символ " << ver_str[i] << '\n';
						std::cin.get();
						exit(0);
					}
				}
				break;
			}
			else continue;
		}
	}


	if (Stack_br.empty())
	{
		if (strlen(ver_str) % 2 == 0)
		std::cout << "Все правильно " << '\n';
		else std::cout << "Количество открытых и закрытых скобок различно " << '\n';
	}
	else std::cout << "Количество открытых и закрытых скобок различно " << '\n';


	std::cin.get();
	return 0;
}

