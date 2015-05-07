#include "hashFunction.h"
#include "hashFunctionPolynom.h"
#include "hashFunctionSquares.h"
#include "hashFunctionSum.h"
#include "hashTable.h"

#include "hashTableTest.h"
#include "hashFunctionTest.h"
#include "listTest.h"

#include <string>
#include <iostream>

using namespace std;

enum Command
{
    addElement = 1,
    deleteElement,
    findElement,
    showStats,
    newHash,
    theEnd
};

enum Hash
{
    polynom = 1,
    sum,
    squared
};

int main()
{
    ListTest listTest;
    QTest::qExec(&listTest);

    HashTableTest hashTableTest;
    QTest::qExec(&hashTableTest);

    HashFunctionTest hashFunctionTest;
    QTest::qExec(&hashFunctionTest);

    HashTable *table = new HashTable();
    HashFunction *func = new SumHashFunction();
    table->newHash(func);

    while(true)
    {
        int command = 0;
        cout << "1. Add element to hash table\n2. Delete element from hash table\n3. Find element\n4. Show stats of this hash table\n5. New hash\n6. Exit\n";
        cin >> command;
        switch(static_cast<Command>(command))
        {
        case theEnd:
        {
            delete table;
            return 0;
        }
            break;

        case addElement:
        {
            cout << "Enter the string you want to add: " << endl;
            string str = " ";
            cin >> str;
            table->addValue(str);
        }
            break;

        case deleteElement:
        {
            cout << "Enter the string you want to delete: " << endl;
            string str = " ";
            cin >> str;
            if(!table->deleteValue(str))
                cout << "There is no such string\n";
        }
            break;

        case findElement:
        {
            cout << "Enter the string you want to find: " << endl;
            string str = " ";
            cin >> str;
            if(!table->wasAdded(str))
                cout << "There is no such string\n";
            else
                cout << "There is such string\n";
        }
            break;

        case newHash:
        {
            int hashType = 0;
            cout << "Enter new hash function :\n1. Polynomial hash\n2. Sum hash\n3. Square sum hash\n";
            cin >> hashType;

            HashFunction *func = new SquareHashFunction();
            switch(static_cast<Hash>(hashType))
            {
            case polynom:
                func = new PolynomHashFunction();
                break;

            case sum:
                func  = new SumHashFunction();
                break;
            }
            table->newHash(func);
        }
        break;

        case showStats:
            table->stats();
            break;
        }
    }

}
