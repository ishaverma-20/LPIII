//Write a program non - recursive and recursive program to calculate Fibonacci numbers and analyze their time and space complexity.

#include <iostream>
using namespace std;

class Fibonacci
{
public:
	int recursiveNth(int n)
	{
		if (n == 1)
			return 0;
		else if (n == 2)
			return 1;
		else
			return (recursiveNth(n - 1) + recursiveNth(n - 2));
	}
	void recursive(int n)
	{
		for (int i = 1; i <= n; i++)
			cout << recursiveNth(i) << ", ";
		cout << endl;
	}
	void nonRecursive(int n)
	{
		if (n == 1)
		{
			cout << "0" << endl;
		}
		else if (n == 2)
			cout << "0, 1" << endl;
		else if (n > 2)
		{
			int a = 0, b = 1, c;
			cout << "0, 1";
			for (int i = 3; i <= n; i++)
			{
				c = a + b;
				a = b;
				b = c;
				cout << ", " << c;
			}
			cout << endl;
		}
	}
};

int main()
{
	Fibonacci obj;
	int choice = -1, n;
	cout << "This program calculates n Fibonacci numbers" << endl;
	cout << "Enter 0 to exit" << endl;
	while (choice != 0)
	{
		cout << "Enter n: ";
		cin >> n;
		cout << "1. Recursive" << endl;
		cout << "2. Non-Recursive" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		if (choice == 1)
			obj.recursive(n);
		else if (choice == 2)
			obj.nonRecursive(n);
	}
}