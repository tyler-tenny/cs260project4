#include <iostream>
#include <cstring>
#include "box.h"
#include "boxtree.h"

using namespace std;

void runTest(const int numValues,const int* values,const int numRemoveValues,const int* removeValues)
{
    bool passed = true;

    BoxTree bt;
    bt.inorder();

    for (int i=0;i<numValues;i++)
    {
	bt.insert(Box(values[i],"b"));
    }

    bt.inorder();

    for (int i=0;i<numRemoveValues;i++)
    {
	bt.remove(removeValues[i]);
    }

    bt.inorder();
    if (numValues > 3)
    {
	int a = values[0];
	int b = values[1];
	if (a > b) 
	{
	    int tmp = a;
	    a = b;
	    b = tmp;
	}
    }

    cout << "Leaves:" << endl;
    bt.printLeaves();
    cout << endl;

}

int main()
{
    int numValues = 50;
    int values[] = 
	{27, 24, 181, 100, 189, 129, 95, 19, 72, 18, 118, 168, 198, 146, 131, 61, 124, 15, 115, 
	 21, 85, 82, 144, 179, 167, 145, 52, 164, 185, 101, 5, 197, 184, 123, 31, 36, 66, 3, 193, 
	 177, 103, 159, 142, 180, 149, 138, 47, 125, 194, 48};

    int numRemoveValues = 3;
    int removeValues[] =
	{21, 48, 184};

    // debugging remove
    int smallTreeNumValues = 6;
    int smallTreeValues[] = {50, 10, 70, 60, 80, 90};
    int smallTreeNumRemoveValues = 1;
    int smallTreeRemoveValues[] = {10};

    runTest(smallTreeNumValues,smallTreeValues,smallTreeNumRemoveValues,smallTreeRemoveValues);
    runTest(numValues,values,numRemoveValues,removeValues);
    return 0;
}
