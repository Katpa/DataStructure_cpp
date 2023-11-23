#include <iostream>
#include <string>
//#include <queue>
#include "DataStructures/Queue.h"
#include "DataStructures/List.h"
#include "DataStructures/HashMap.h"

using namespace std;

int main()
{
	HashMap<string, int> hashMap;

	hashMap.Insert("AA", 213);
	hashMap.Insert("AB", 15);

	return EXIT_SUCCESS;
}