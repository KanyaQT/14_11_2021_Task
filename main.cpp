#include <iosteam>
#include "dynamic_array+template.h"

using namespace std;

int main()
{
    DynamicArray<int> a;

    for (int i = 0; i < 10; i++)
    {
        a.append(i);
    }
}
