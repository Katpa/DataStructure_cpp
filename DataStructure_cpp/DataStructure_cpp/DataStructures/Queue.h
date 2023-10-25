#pragma once

#define MAX_SIZE 2000000000

template<typename T>
class queue
{
public:
	queue()
	{
		arr = new int[MAX_SIZE];;
		qSize = 0;
		fCursor = 0;
		bCursor = 0;
	}
	~queue()
	{
		delete[] arr;
	}

	T& front() { return arr[fCursor]; }
	T& back() { return arr[bCursor]; }

	void push(T value)
	{
		arr[qSize] = value;
		bCursor = qSize++;
	}
	void pop()
	{
		for (int i = 0; i < qSize; i++)
		{
			arr[i] = arr[i + 1];
		}
		qSize--;
		bCursor--;
	}

	const int size() { return qSize; }
	bool empty() { return qSize == 0; }

private:
	T* arr;
	int qSize;
	int fCursor;
	int bCursor;
};