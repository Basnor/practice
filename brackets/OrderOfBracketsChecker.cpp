#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "OrderOfBracketsChecker.h"
using namespace std;

bool OrderOfBracketsChecker::StringChecker(string& checking_string)
{
	//��������� ������ ��� ��������
	static const string search_breackets = "{}<>()";
	int index;

	//���������� ������ ������ � ���������� ������
	for (unsigned int i = 0; i < checking_string.length(); i++)
	{
		//����� ������ � ����������� �� ������� � ������ search_breackets
		index = search_breackets.find(checking_string[i]);
		if (index >= 0)
		{
			if (index % 2 == 0) open_breckets.push(checking_string[i]); //���� ������ �����������
			else
			{
				if (!open_breckets.empty())
				{
					//���������� ��������� �������� ������ � �������� ����� ������� ������ 
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