#include <iostream>
#include "box.h"
#include "testutil.h"

using namespace std;

void runTest()
{
    bool passed = true;

    Box b1(1,"one");
    passed &= checkInt(b1.ID,1);
    passed &= checkStr(b1.plant,"one");

    if (passed)
    {
	cout << "Passed" << endl;
    }
    else
    {
	cout << "Failed" << endl;
    }
}

int main()
{
    runTest();
    return 0;
}
