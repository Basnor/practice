#pragma once
#include <string>
#include <stack>
using namespace std;
//
// OrderOfBracketsChecker class
// ����� ������������ ��� �������� ������������ ������� ������ � ������ 
//
class OrderOfBracketsChecker
{
public:
	//������� ���������� ������
	bool StringChecker(string& checking_string);

private:
	stack <char> open_breckets;
};