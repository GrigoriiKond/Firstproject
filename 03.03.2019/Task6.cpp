/* Напишите программу, проверяющую последовательность скобок на корректность. В последовательности встречаются 3 вида скобок: ( ),{ },[ ].
Скобочная последовательность называется корректной, если каждая скобка закрыта соответствующей. */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool Brackets(char opening, char closing)
{
	if (opening == '(' && closing == ')') return true;
	else if (opening == '[' && closing == ']') return true;
	else if (opening == '{' && closing == '}') return true;
	return false;
}
bool Balanced(string b)
{
	stack<char> A;
	for (int i = 0; i < b.length(); i++)
	{
		if (b[i] == '(' || b[i] == '{' || b[i] == '[')
			A.push(b[i]);
		else if (b[i] == ')' || b[i] == '}' || b[i] == ']')
		{
			if (A.empty() || !Brackets(A.top(), b[i]))
				return false;
			else
				A.pop();
		}
	}
	return A.empty();
}
int main()	{	
	string c;
	cout << "Enter an expression:" << endl;
	cin >> c;
	if (Balanced(c))
		cout << "Balanced." << endl;
	else
		cout << "Not balanced." << endl;
	return 0;
}
