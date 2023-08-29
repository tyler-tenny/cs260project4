#include <iostream>
#include <cstring>

using namespace std;

bool checkInt(int actual,int expected)
{
    bool ret = true;
    if (actual != expected)
    {
	cout << "Mismatch. Expected: " << expected << " got: " << actual << endl;
	ret = false;
    }
    return ret;
}

bool checkStr(const char* actual,const char* expected)
{
    bool ret = true;
    if (strcmp(actual,expected)!=0)
    {
	cout << "Mismatch. Expected: " << expected << " got: " << actual << endl;
	ret = false;
    }
    return ret;
}
