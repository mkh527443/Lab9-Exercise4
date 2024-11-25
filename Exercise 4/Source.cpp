#include<iostream>

using namespace std;

class Queue
{
private:
	int SIZE = 15;
	int* queue = new int[SIZE];
	int rear = -1;
	int value;

public:
	bool is_empty()
	{
		if (rear == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void enqueue(int value)
	{

		if (rear == SIZE - 1)
		{
			cout << "Overflow!!";
		}
		else
		{
			if (rear == -1)
			{
				rear = 0;
			}
			else
			{
				rear++;
			}
			queue[rear] = value;
		}
	}

	void dequeue()
	{
		if (rear == -1)
		{
			cout << "Underflow!!";
		}

		int minimum = 0;
		for (int i = 1; i <= rear; i++)
		{
			if (queue[i] < queue[minimum])
			{
				minimum = i;
			}
		}
		cout << "Item Dequeued: " << queue[minimum] << endl;

		for (int i = minimum; i < rear; i++)
		{
			queue[i] = queue[i + 1];
		}
		rear--;
	}

	void display()
	{
		cout << "Elements in queue are: " << endl;

		if (rear == -1)
		{
			cout << "Queue is empty";
		}
		else
		{
			for (int i = 0; i <= rear; i++)
			{
				cout << queue[i] << " ";
			}
		}
		cout << endl;
	}
};

int main()
{
	Queue q;
	q.enqueue(10);
	q.enqueue(27);
	q.enqueue(15);
	q.enqueue(35);
	q.enqueue(7);
	q.enqueue(44);
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();
	q.display();
}