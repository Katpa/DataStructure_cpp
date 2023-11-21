#pragma once

template<typename Type>
class List
{
public:
	struct ListNode
	{
	public:
		Type data;
		ListNode* prev = nullptr;
		ListNode* next = nullptr;
	};

public:
	List()
		:size(0), tail(new ListNode()), head(new ListNode())
	{}

	~List()
	{
		ListNode* node = head;
		ListNode* tmp;
		while (node != nullptr)
		{
			tmp = node->next;
			delete node;
			node = tmp;
		}
	}

	void Insert(Type& inputData)
	{
		size++;

		ListNode* node = new ListNode();

		node->data = inputData;

		if (size == 1)
		{
			head = node;
			tail = node;
			return;
		}
		node->prev = tail;
		tail->next = node;
		tail = node;
	}

	void Insert(Type&& inputData)
	{
		size++;

		ListNode* node = new ListNode();

		node->data = inputData;

		if (size == 1)
		{
			head = node;
			tail = node;
			return;
		}
		tail->next = node;
		node->prev = tail;
		tail = node;
	}

	void Insert(int order, Type&& inputdata)
	{
		if (size < order - 1) return;

		size++;

		ListNode* prevNode = nullptr;
		ListNode* nextNode = head;

		for (int i = 1; i < order; i++)
			nextNode = nextNode->next;

		if (nextNode != nullptr) prevNode = nextNode->prev;

		ListNode* node = new ListNode();

		if (prevNode != nullptr)	prevNode->next = node;
		if (nextNode != nullptr)	nextNode->prev = node;

		node->next = nextNode;
		node->prev = prevNode;
		node->data = inputdata;

		if (order == 1)
			head = node;

		if (size == order)
			tail = node;
	}

	void Remove(int order = 0)
	{
		if (size <= 0) return;
		if (order > size) return;

		size--;

		ListNode* removeNode = head;

		for (int i = 1; i < order; i++)
			removeNode = removeNode->next;

		ListNode* prevNode = removeNode->prev;
		ListNode* nextNode = removeNode->next;

		prevNode->next = nextNode;
		if (nextNode != nullptr) nextNode->prev = prevNode;

		delete removeNode;
	}

	const int& Size() { return size; }

private:
	int size;
	ListNode* head;
	ListNode* tail;
};