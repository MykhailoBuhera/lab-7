#include <iostream>
#include <string>
#include "Node.h"
#include "list.h"

using namespace std;

int main()
{
    list<int> list;
    list.push_back(15);
    list.push_back(20);

    list.print();

    cout << list.rozm();
}