#pragma once
#include <string>
#include <stack>
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