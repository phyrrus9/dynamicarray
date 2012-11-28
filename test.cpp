#include "dynamicarray.h"
#include <cstring>
#include <iostream>
using namespace std;
#define p(a) a.grow(a.getsize() + 1)
int main()
{
    dynamicarray<const char *> b;
    b.set("Hello", 1);
    b.set(" ", 2);
    b.set("World!", 3);
    b.set("\n", 4);
    for (int i = 1; i < b.getsize() + 1; i++)
        cout << b.get(i);
}
