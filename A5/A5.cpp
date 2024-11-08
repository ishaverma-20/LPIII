//Write a program for  analysis of quick sort by using deterministic and randomized variant.
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

class QuickSort
{
	bool deterministic;
	int pass = 1;
	int Dpartition(vector<int>& arr, int low, int high)
	{
		int pivot = arr[high];
		int i = low - 1;
		for (int j = low; j < high; j++)
		{
			if (arr[j] < pivot)
			{
				i++;
				swap(arr[j], arr[i]);
			}
		}
		swap(arr[i + 1], arr[high]);

		cout << "Pass " << pass << ": " << endl;
		cout << "Pivot: " << pivot << endl;
		cout << "Array: ";
		pass++;
		return i + 1;
	}
	int NDpartition(vector<int>& arr, int low, int high)
	{
		int random_pi = low + rand() % (high - low + 1);
		swap(arr[random_pi], arr[high]);
		return Dpartition(arr, low, high);
	}
public:
	void type(bool deterministic)
	{
		this->deterministic = deterministic;
	}
	void display(vector<int>& arr)
	{
		for (int i : arr)
			cout << i << " ";
		cout << endl;
	}
	void quicksort(vector<int>& arr, int low, int high)
	{
		if(low<high)
		{
			int pi;
			if (deterministic)
				pi = Dpartition(arr, low, high);
			else
				pi = NDpartition(arr, low, high);
			display(arr);
			quicksort(arr, low, pi - 1);
			quicksort(arr, pi + 1, high);
		}
	}
};

int main()
{
	int choice;
	while (true)
	{
		cout << "Enter the number of elements: ";
		int n;
		cin >> n;
		vector<int> arr(n, 0);
		cout << "Enter the elements: " << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "Element " << i << ": ";
			cin >> arr[i];
		}
		cout << "1. Deterministic" << endl;
		cout << "2. Non-Deterministic" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		QuickSort obj;
		if (choice == 1)
			obj.type(true);
		else if (choice == 2)
			obj.type(false);
		else
			break;
		cout << "Original: " << endl;
		obj.display(arr);
		obj.quicksort(arr, 0, n - 1);
	}
	return 0;
}
