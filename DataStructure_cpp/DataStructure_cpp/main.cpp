#include <iostream>
#include <string>
//#include <queue>
#include "DataStructures/Queue.h"
#include "DataStructures/List.h"

using namespace std;

int main()
{
	List<int> list;

	list.Insert(5);
	list.Insert(1);
	list.Insert(2);
	list.Insert(1, 3);

	list.Remove(2);

	//cout << list.Size() << endl;

	return EXIT_SUCCESS;
}