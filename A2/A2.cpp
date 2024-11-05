//Write a program to implement Huffman Encoding using a greedy strategy. 
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

struct Node
{
	char value;
	int freq;
	Node* left;
	Node* right;
	Node(char v, int f)
	{
		this -> value = v;
		this -> freq = f;
		left = nullptr;
		right = nullptr;
	}
};

struct compare
{
	bool operator()(Node* operand1, Node* operand2)
	{
		return (operand1->freq > operand2->freq);
	}
};

void display(Node* top, string str)
{
	if (!top)
		return;
	if (top->value != '#')
	{
		cout << top->value << ": " << str << endl;
	}
	display(top->left, str + '0');
	display(top->right, str + '1');
}

void HuffmanCode(vector<char> values, vector<int> freqs, int n)
{
	priority_queue<Node*, vector<Node*>, compare> heap;

	for (int i = 0; i < n; i++)
	{
		Node* temp = new Node(values[i], freqs[i]);
		heap.push(temp);
	}

	Node *left = nullptr, *right = nullptr, *top = nullptr;
	while (heap.size() != 1)
	{
		left = heap.top();
		heap.pop();

		right = heap.top();
		heap.pop();

		Node* temp = new Node('#', left->freq + right->freq);
		top = temp;
		top->left = left;
		top->right = right;

		heap.push(top);
	}
	display(top, "");
}

template <typename T>
void displayVector(vector<T>& vect)
{
	for (T& i : vect)
		cout << i << " ";
	cout << endl;
}


int main()
{
	int n;
	cout << "Enter number of characters: ";
	cin >> n;
	vector<char> values(n, ' ');
	vector<int> freqs(n, -1);
	for (int i = 0; i < n; i++)
	{
		cout << "Enter value: ";
		cin >> values[i];
		cout << "Enter frequency: ";
		cin >> freqs[i];
	}
	displayVector(values);
	displayVector(freqs);
	
	HuffmanCode(values, freqs, n);
	return 0;
}