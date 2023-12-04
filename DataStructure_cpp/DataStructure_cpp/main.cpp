#include <iostream>
#include <string>
//#include <queue>
#include "DataStructures/Queue.h"
#include "DataStructures/List.h"
#include "DataStructures/HashMap.h"
#include "DataStructures/PriorityQueue.h"

using namespace std;

int main()
{
	PriorityQueue<int> pq;

	pq.Push(3);
	pq.Push(5);
	pq.Push(2);

	cout << pq.Top() << endl;

	pq.SwitchSortType();
	pq.Pop();

	cout << pq.Top() << endl;

	return EXIT_SUCCESS;
}