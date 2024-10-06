#include <iostream>
#include "OrderedArray.h"
#include "UnorderedArray.h"

using namespace std;

int main()
{
    cout << "Test 1: OrderedArray with duplicates allowed" << endl;
    OrderedArray<int> orderedArray1(3, true);

    orderedArray1.push(3);
    orderedArray1.push(53);
    orderedArray1.push(83);
    orderedArray1.push(23);
    orderedArray1.push(82);

    cout << "Ordered array (duplicates allowed) contents: ";
    for (int i = 0; i < orderedArray1.GetSize(); i++)
    {
        cout << orderedArray1[i] << " ";
    }
    cout << endl;

    cout << "\nTest 2: OrderedArray without duplicates" << endl;
    OrderedArray<int> orderedArray2(3, false);

    orderedArray2.push(3);
    orderedArray2.push(53);
    orderedArray2.push(53);
    orderedArray2.push(83);
    orderedArray2.push(23);
    orderedArray2.push(82);

    cout << "Ordered array (no duplicates) contents: ";
    for (int i = 0; i < orderedArray2.GetSize(); i++)
    {
        cout << orderedArray2[i] << " ";
    }
    cout << endl;

    cout << "\nTest 3: Expansion behavior" << endl;
    OrderedArray<int> orderedArray3(2); 
    orderedArray3.push(1);
    orderedArray3.push(2);
    orderedArray3.push(3);

    cout << "Ordered array after expansion: ";
    for (int i = 0; i < orderedArray3.GetSize(); i++)
    {
        cout << orderedArray3[i] << " ";
    }
    cout << endl;

    cout << "\nTest 4: UnorderedArray insertion" << endl;
    UnorderedArray<int> unorderedArray(3);
    unorderedArray.push(10);
    unorderedArray.push(5);
    unorderedArray.push(15);
    unorderedArray.push(25);

    cout << "Unordered array contents: ";
    for (int i = 0; i < unorderedArray.GetSize(); i++)
    {
        cout << unorderedArray[i] << " ";
    }
    cout << endl;

    cout << "\nTest 5: OrderedArray deletion" << endl;
    OrderedArray<int> orderedArray4(3);
    orderedArray4.push(10);
    orderedArray4.push(30);
    orderedArray4.push(20);
    orderedArray4.push(40);

    cout << "Ordered array before deletion: ";
    for (int i = 0; i < orderedArray4.GetSize(); i++)
    {
        cout << orderedArray4[i] << " ";
    }
    cout << endl;

    orderedArray4.remove(2); 

    cout << "Ordered array after deletion: ";
    for (int i = 0; i < orderedArray4.GetSize(); i++)
    {
        cout << orderedArray4[i] << " ";
    }
    cout << endl;

    cout << "\nTest 6: Searching in OrderedArray" << endl;
    OrderedArray<int> orderedArray5(5);
    orderedArray5.push(10);
    orderedArray5.push(20);
    orderedArray5.push(30);
    orderedArray5.push(40);
    orderedArray5.push(50);

    int searchResult = orderedArray5.search(30);  
    cout << "Search for 30 found at index: " << searchResult << endl;

    searchResult = orderedArray5.search(60);
    cout << "Search for 60 found at index: " << searchResult << endl;

    return 0;
}