#include <iostream>
#include <string>
//#include <queue>
#include "DataStructures/Queue.h"

using namespace std;

int main()
{
	queue<int> q;

	int i = 1;
	q.push(i++);
	q.push(i++);
	q.push(i++);
	q.push(i++);

	cout << q.front() << endl;
	cout << q.back() << endl;

	q.pop();

	cout << q.front() << endl;

	if (!q.empty())
		q.push(i++);

	cout << q.size() << endl;

	return EXIT_SUCCESS;
}