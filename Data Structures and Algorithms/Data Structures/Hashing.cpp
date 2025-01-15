#include <iostream>
using namespace std;

// ---------------------------- Linear Probing ----------------------------

class HashTableEntry
{
public:
    int key;
    int value;

    HashTableEntry(int k, int v) : key(k), value(v) {}
};

class HashMapTable
{
private:
    int TABLE_SIZE;
    HashTableEntry **table;
    int elementsCount;

    int HashFunc(int k)
    {
        return k % TABLE_SIZE;
    }

    double LoadFactor() const
    {
        return 1.0 * elementsCount / TABLE_SIZE;
    }

    void ResizeTable()
    {
        int newTableSize = TABLE_SIZE * 2;
        HashTableEntry **newTable = new HashTableEntry *[newTableSize]();

        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (table[i] != NULL)
            {
                int newHash = table[i]->key % newTableSize;
                while (newTable[newHash] != NULL)
                {
                    newHash = (newHash + 1) % newTableSize;
                }
                newTable[newHash] = table[i];
            }
        }
        delete[] table;
        table = newTable;
        TABLE_SIZE = newTableSize;
    }

public:
    HashMapTable() : TABLE_SIZE(10), elementsCount(0), table(new HashTableEntry *[TABLE_SIZE]) {}

    void Insert(int k, int v)
    {
        if (LoadFactor() >= 0.7)
        {
            ResizeTable();
        }

        int hash = HashFunc(k);
        while (table[hash] != NULL && table[hash]->key != k)
        {
            hash = (hash + 1) % TABLE_SIZE;
        }
        if (table[hash] != NULL)
        {
            delete table[hash];
        }
        table[hash] = new HashTableEntry(k, v);
        elementsCount++;
    }

    int SearchKey(int k)
    {
        int hash = HashFunc(k);
        while (table[hash] != NULL && table[hash]->key != k)
        {
            hash = (hash + 1) % TABLE_SIZE;
        }
        if (table[hash] == NULL)
        {
            return -1;
        }
        else
        {
            return table[hash]->value;
        }
    }

    void Remove(int k)
    {
        int hash = HashFunc(k);
        while (table[hash] != NULL)
        {
            if (table[hash]->key == k)
            {
                delete table[hash];
                table[hash] = NULL;
                elementsCount--;
                return;
            }
            hash = (hash + 1) % TABLE_SIZE;
        }
    }

    void PrintTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (table[i] != NULL)
            {
                cout << "Index " << i << ": Key=" << table[i]->key << ", Value=" << table[i]->value << endl;
            }
            else
            {
                cout << "Index " << i << ": Empty" << endl;
            }
        }
    }

    ~HashMapTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (table[i] != NULL)
            {
                delete table[i];
            }
        }
        delete[] table;
    }
};

// ---------------------------- Double Hashing ----------------------------

class HashTableEntry
{
public:
    int key;
    int value;
    bool deleted;

    HashTableEntry(int k, int v) : key(k), value(v), deleted(false) {}
};

class HashMapTable
{
private:
    static const int INITIAL_TABLE_SIZE = 11;
    int TABLE_SIZE;
    HashTableEntry **table;
    int elementsCount;

    int HashFunc1(int k)
    {
        return k % TABLE_SIZE;
    }
    int HashFunc2(int k)
    {
        return 7 - (k % 7);
    }

    double LoadFactor() const
    {
        return 1.0 * elementsCount / TABLE_SIZE;
    }

    void ResizeTable(int newSize)
    {
        HashTableEntry **newTable = new HashTableEntry *[newSize]();

        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (table[i] != nullptr && !table[i]->deleted)
            {
                int newHash = table[i]->key % newSize;
                int j = 0;
                while (newTable[newHash] != nullptr)
                {
                    j++;
                    newHash = (HashFunc1(table[i]->key) + j * HashFunc2(table[i]->key)) % newSize;
                }
                newTable[newHash] = table[i];
            }
        }
        delete[] table;
        table = newTable;
        TABLE_SIZE = newSize;
    }

public:
    HashMapTable() : TABLE_SIZE(INITIAL_TABLE_SIZE), elementsCount(0), table(new HashTableEntry *[TABLE_SIZE]) {}

    int DoubleHashFunc(int k, int i)
    {
        return (HashFunc1(k) + i * HashFunc2(k)) % TABLE_SIZE;
    }

    void Insert(int k, int v)
    {
        if (LoadFactor() > 0.7)
        {
            ResizeTable(TABLE_SIZE * 2);
        }

        int i = 0;
        int hash = HashFunc1(k);
        while (table[hash] != nullptr)
        {
            // If the key exists, overwrite the value
            if (!table[hash]->deleted && table[hash]->key == k)
            {
                table[hash]->value = v; // Update the value
                return;
            }
            i++;
            hash = DoubleHashFunc(k, i);
        }
        // If the key is not found, insert a new entry
        if (table[hash] == nullptr || table[hash]->deleted)
        {
            elementsCount++;
        }
        table[hash] = new HashTableEntry(k, v);
    }

    int SearchKey(int k)
    {
        int i = 0;
        int hash = HashFunc1(k);
        while (table[hash] != nullptr)
        {
            if (!table[hash]->deleted && table[hash]->key == k)
            {
                return table[hash]->value;
            }
            i++;
            hash = DoubleHashFunc(k, i);
        }
        return -1;
    }

    void Remove(int k)
    {
        int i = 0;
        int hash = HashFunc1(k);
        while (table[hash] != nullptr)
        {
            if (!table[hash]->deleted && table[hash]->key == k)
            {
                table[hash]->deleted = true;
                elementsCount--;
                return;
            }
            i++;
            hash = DoubleHashFunc(k, i);
        }
    }

    void PrintTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (table[i] != nullptr && !table[i]->deleted)
            {
                cout << "Index " << i << ": Key=" << table[i]->key << ", Value=" << table[i]->value << endl;
            }
            else
            {
                cout << "Index " << i << ": Empty" << endl;
            }
        }
    }

    ~HashMapTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (table[i] != nullptr)
            {
                delete table[i];
            }
        }
        delete[] table;
    }
};

// ---------------------------- Quadratic Probing ----------------------------

class HashTableEntry
{
public:
    int key;
    int value;

    HashTableEntry(int k, int v) : key(k), value(v) {}
};

class HashMapTable
{
private:
    int TABLE_SIZE;
    HashTableEntry **table;
    int elementsCount;

    int HashFunc(int k)
    {
        return k % TABLE_SIZE;
    }

    double LoadFactor() const
    {
        return 1.0 * elementsCount / TABLE_SIZE;
    }

    void ResizeTable()
    {
        int newTableSize = TABLE_SIZE * 2;
        HashTableEntry **newTable = new HashTableEntry *[newTableSize]();

        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (table[i] != NULL)
            {
                int hash = table[i]->key % newTableSize;
                int j = 1;
                while (newTable[hash] != NULL)
                {
                    hash = (hash + j * j) % newTableSize; // Quadratic probing
                    j++;
                }
                newTable[hash] = table[i];
            }
        }
        delete[] table;
        table = newTable;
        TABLE_SIZE = newTableSize;
    }

public:
    HashMapTable() : TABLE_SIZE(10), elementsCount(0), table(new HashTableEntry *[TABLE_SIZE]()) {}

    void Insert(int k, int v)
    {
        if (LoadFactor() >= 0.7)
        {
            ResizeTable();
        }

        int originalHash = HashFunc(k); // Store the original hash value
        int hash = originalHash;
        int i = 1;

        // Quadratic probing
        while (table[hash] != NULL && table[hash]->key != k)
        {
            hash = (originalHash + i * i) % TABLE_SIZE; // Use originalHash for quadratic probing
            i++;
        }

        if (table[hash] != NULL)
        {
            delete table[hash];
        }
        table[hash] = new HashTableEntry(k, v);
        elementsCount++;
    }

    int SearchKey(int k)
    {
        int originalHash = HashFunc(k); // Store the original hash value
        int hash = originalHash;
        int i = 1;

        // Quadratic probing
        while (table[hash] != NULL)
        {
            if (table[hash]->key == k)
            {
                return table[hash]->value;
            }
            hash = (originalHash + i * i) % TABLE_SIZE; // Use originalHash for quadratic probing
            i++;
        }
        return -1; // Key not found
    }

    void Remove(int k)
    {
        int originalHash = HashFunc(k); // Store the original hash value
        int hash = originalHash;
        int i = 1;

        // Quadratic probing
        while (table[hash] != NULL)
        {
            if (table[hash]->key == k)
            {
                delete table[hash];
                table[hash] = NULL;
                elementsCount--;
                return;
            }
            hash = (originalHash + i * i) % TABLE_SIZE; // Use originalHash for quadratic probing
            i++;
        }
    }

    void PrintTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (table[i] != NULL)
            {
                cout << "Index " << i << ": Key=" << table[i]->key << ", Value=" << table[i]->value << endl;
            }
            else
            {
                cout << "Index " << i << ": Empty" << endl;
            }
        }
    }

    ~HashMapTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (table[i] != NULL)
            {
                delete table[i];
            }
        }
        delete[] table;
    }
};

// ---------------------------- Separate Chaining ----------------------------

class HashTableEntry
{
public:
    int key;
    int value;
    HashTableEntry *next;

    HashTableEntry(int k, int v) : key(k), value(v), next(nullptr) {}
};

class HashMapTable
{
private:
    static const int INITIAL_TABLE_SIZE = 10;
    int TABLE_SIZE;
    HashTableEntry **table;
    int elementsCount;

public:
    HashMapTable() : TABLE_SIZE(INITIAL_TABLE_SIZE), elementsCount(0), table(new HashTableEntry *[TABLE_SIZE]) {}

    int HashFunc(int k)
    {
        return k % TABLE_SIZE;
    }

    double LoadFactor() const
    {
        return 1.0 * elementsCount / TABLE_SIZE;
    }

    void ResizeTable(int newSize)
    {
        HashTableEntry **newTable = new HashTableEntry *[newSize]();

        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            HashTableEntry *current = table[i];
            while (current != nullptr)
            {
                int newHash = current->key % newSize;
                HashTableEntry *next = current->next;
                current->next = newTable[newHash];
                newTable[newHash] = current;
                current = next;
            }
        }
        delete[] table;
        table = newTable;
        TABLE_SIZE = newSize;
    }

    void Insert(int k, int v)
    {
        int hash = HashFunc(k);
        HashTableEntry *current = table[hash];

        // Search for the key in the chain
        while (current != nullptr)
        {
            if (current->key == k)
            {
                // Key exists, overwrite the value
                current->value = v;
                return;
            }
            current = current->next;
        }

        // Key not found, insert a new node
        HashTableEntry *newEntry = new HashTableEntry(k, v);
        newEntry->next = table[hash];
        table[hash] = newEntry;
        elementsCount++;

        // Resize table if load factor exceeds threshold
        if (LoadFactor() > 0.7)
        {
            int newSize = TABLE_SIZE * 2;
            ResizeTable(newSize);
        }
    }

    int SearchKey(int k)
    {
        int hash = HashFunc(k);

        HashTableEntry *current = table[hash];
        while (current != nullptr)
        {
            if (current->key == k)
            {
                return current->value;
            }
            current = current->next;
        }

        return -1;
    }

    void Remove(int k)
    {
        int hash = HashFunc(k);

        HashTableEntry *current = table[hash];
        HashTableEntry *prev = nullptr;

        while (current != nullptr && current->key != k)
        {
            prev = current;
            current = current->next;
        }

        if (current != nullptr)
        {
            if (prev != nullptr)
            {
                prev->next = current->next;
            }
            else
            {
                table[hash] = current->next;
            }
            delete current;
            elementsCount--;
        }
    }

    void PrintTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            cout << "Index " << i << ": ";
            HashTableEntry *current = table[i];
            while (current != nullptr)
            {
                cout << "Key=" << current->key << ", Value=" << current->value << " -> ";
                current = current->next;
            }
            cout << "Null" << endl;
        }
    }

    ~HashMapTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            HashTableEntry *current = table[i];
            while (current != nullptr)
            {
                HashTableEntry *next = current->next;
                delete current;
                current = next;
            }
            table[i] = nullptr;
        }
        delete[] table;
    }
};