#pragma once

#include <vector>

template<typename T>
class PriorityQueue
{
public:
	enum PriorityQueueSortType
	{
		MAX = 0, MIN
	};

public:
	PriorityQueue(PriorityQueueSortType _type = PriorityQueueSortType::MAX)
		:type(_type), size(0)
	{
		heap.push_back(0);
	}

	~PriorityQueue()
	{
	}

	void Push(T input)
	{
		size++;
		heap.push_back(input);
		int curIndex = size;
		
		while (curIndex > 1)
		{
			if (Cmp(heap[curIndex], heap[curIndex * 0.5f]))
			{
				heap[curIndex] = heap[curIndex * 0.5f];
				curIndex *= 0.5f;
				continue;
			}

			break;
		}

		heap[curIndex] = input;
	}

	void Pop()
	{
		if (!size) return;
		T last = heap[size];
		heap.pop_back();
		size--;

		int curIndex = 2;
		while (curIndex <= size)
		{
			// 한 노드의 자식 노드 중에서 더 규칙에 적합한 값의 인덱스 찾기
			if (curIndex + 1 <= size && Cmp(heap[curIndex + 1], heap[curIndex]))
			{
				curIndex++;
			}

			if (Cmp(heap[curIndex], last))
			{
				heap[curIndex * 0.5f] = heap[curIndex];
				curIndex <<= 1;
			}
			else
				break;
		}

		heap[curIndex * 0.5f] = last;
	}

	T Top()
	{
		return heap[1];
	}

	const int& Size()
	{
		return size;
	}

	const bool Empty()
	{
		return size;
	}

	void SwitchSortType()
	{
		type = static_cast<PriorityQueueSortType>((static_cast<int>(type) + 1) % 2);
	}

private:
	bool Cmp(const T& value1, const T& value2)
	{
		if (type == PriorityQueueSortType::MAX)
		{
			if (value1 > value2) return true;
			else				 return false;
		}
		else
		{
			if (value1 < value2) return true;
			else				 return false;
		}
	}

private:
	std::vector<T> heap;

	int size;

	PriorityQueueSortType type;
};