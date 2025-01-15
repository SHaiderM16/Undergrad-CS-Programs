#include <iostream>
using namespace std;

// ---------------------------- SINGLY LINKED LIST ----------------------------

class SinglyNode
{
public:
    int key;
    int data;
    SinglyNode *next; // Pointer to the next node in the list

    SinglyNode(int d) : data(d), next(nullptr) {}

    SinglyNode(int k, int d) : key(k), data(d), next(nullptr) {}
};

class SinglyLinkedList
{
private:
    SinglyNode *head; // Pointer to the first node in the list
    SinglyNode *tail; // Pointer to the last node in the list

public:
    SinglyLinkedList()
    {
        head = nullptr; // Initially, the list is empty
        tail = nullptr; // No tail node in an empty list
    }

    void insertAtEnd(int data)
    {
        SinglyNode *n = new SinglyNode(data);
        if (head == nullptr)
        {
            head = n; // Set the head if the list is empty
            tail = n; // Also set tail to the new node
            cout << "Node inserted at end" << endl;
            return;
        }
        tail->next = n; // Link the current tail to the new node
        tail = n;       // Update tail to the new node
        cout << "Node inserted at end" << endl;
    }

    void insertAtStart(int data)
    {
        SinglyNode *n = new SinglyNode(data);
        n->next = head; // The new node points to the current head
        head = n;       // Update head to the new node
        if (tail == nullptr)
        {
            tail = n; // If the list was empty, set tail as well
        }
        cout << "Node inserted at start" << endl;
    }

    void insertAfter(int data, int position)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot insert after." << endl;
            return;
        }
        SinglyNode *n = new SinglyNode(data);
        SinglyNode *current = head;

        // Traverse to the specified position
        for (int i = 0; i < position && current != nullptr; i++)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Position out of bounds." << endl;
            delete n; // Free allocated memory
            return;
        }

        // Insert the new node after the previous node
        n->next = current->next; // Link new node to the next node
        current->next = n;       // Link previous node to the new node
        if (n->next == nullptr)
        {
            tail = n; // Update tail if inserted at the end
        }

        cout << "Inserted at index " << position << endl;
    }

    void display()
    {
        SinglyNode *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        SinglyNode *temp = head;

        // If only one node exists
        if (temp->next == nullptr)
        {
            delete temp;
            head = tail = nullptr; // Reset head and tail
            cout << "Last node deleted" << endl;
            return;
        }

        SinglyNode *previous = nullptr;
        // Traverse to the second last node
        while (temp->next != nullptr)
        {
            previous = temp;
            temp = temp->next;
        }

        // Update tail to point to the second last node
        tail = previous;
        tail->next = nullptr; // Set the next of the new tail to null
        delete temp;          // Deallocate memory for the deleted node
        cout << "Last node deleted" << endl;
    }

    void deleteAtStart()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        SinglyNode *temp = head; // Store the current head node
        head = head->next;       // Update head to point to the next node
        if (head == nullptr)
        {
            tail = nullptr; // Reset tail if list becomes empty
        }
        delete temp; // Deallocate memory for the old head node
        cout << "Element deleted from start" << endl;
    }

    void deleteAfter(int position)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        SinglyNode *current = head;
        SinglyNode *previous = nullptr;

        // Traverse to the specified position
        for (int i = 0; i < position && current != nullptr; i++)
        {
            previous = current;
            current = current->next;
        }

        if (previous == nullptr || current == nullptr)
        {
            cout << "Position out of bounds." << endl;
            return;
        }

        // Skip the node to be deleted
        previous->next = current->next;
        if (previous->next == nullptr)
        {
            tail = previous; // Update tail if deleted last node
        }
        delete current; // Deallocate memory for the deleted node
        cout << "Deleted element at index " << position << endl;
    }

    // Destructor to clean up memory
    ~SinglyLinkedList()
    {
        while (head != nullptr)
        {
            deleteAtStart(); // Delete all nodes
        }
    }
};

// ---------------------------- DOUBLY LINKED LIST ----------------------------

class DoublyNode
{
public:
    int key;
    int data;
    DoublyNode *next; // Pointer to the next node in the list
    DoublyNode *prev; // Pointer to the previous node in the list

    DoublyNode(int d) : data(d), next(nullptr), prev(nullptr) {}

    DoublyNode(int k, int d) : key(k), data(d), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
private:
    DoublyNode *head; // Pointer to the first node in the list
    DoublyNode *tail; // Pointer to the last node in the list

public:
    DoublyLinkedList()
    {
        head = nullptr; // Initially, the list is empty
        tail = nullptr; // No tail node in an empty list
    }

    void insertAtEnd(int data)
    {
        DoublyNode *n = new DoublyNode(data);
        if (head == nullptr)
        {
            head = n; // Set the head if the list is empty
            tail = n; // Also set tail to the new node
            cout << "Node inserted at end" << endl;
            return;
        }
        tail->next = n; // Link the current tail to the new node
        n->prev = tail; // Link new node back to the previous tail
        tail = n;       // Update tail to the new node
        cout << "Node inserted at end" << endl;
    }

    void insertAtStart(int data)
    {
        DoublyNode *n = new DoublyNode(data);
        n->next = head; // The new node points to the current head
        if (head != nullptr)
        {
            head->prev = n; // Link the current head back to the new node
        }
        head = n; // Update head to the new node
        if (tail == nullptr)
        {
            tail = n; // If the list was empty, set tail as well
        }
        cout << "Node inserted at start" << endl;
    }

    void insertAfter(int data, int position)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot insert after." << endl;
            return;
        }
        DoublyNode *n = new DoublyNode(data);
        DoublyNode *current = head;

        // Traverse to the specified position
        for (int i = 0; i < position && current != nullptr; i++)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Position out of bounds." << endl;
            delete n; // Free allocated memory
            return;
        }

        // Insert the new node after the current node
        n->next = current->next; // Link new node to the next node
        n->prev = current;       // Link new node back to the current node
        if (current->next != nullptr)
        {
            current->next->prev = n; // Link the next node back to the new node
        }
        current->next = n; // Link current node to the new node
        if (n->next == nullptr)
        {
            tail = n; // Update tail if inserted at the end
        }

        cout << "Inserted at index " << position << endl;
    }

    void display()
    {
        DoublyNode *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "<-->"; // Display with two-way connection
            temp = temp->next;
        }
        cout << endl;
    }

    void displayReverse()
    {
        DoublyNode *temp = tail;
        while (temp != nullptr)
        {
            cout << temp->data << "<-->"; // Display with two-way connection
            temp = temp->prev;
        }
        cout << endl;
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        DoublyNode *temp = tail;

        // If only one node exists
        if (temp->prev == nullptr)
        {
            delete temp;
            head = tail = nullptr; // Reset head and tail
            cout << "Last node deleted" << endl;
            return;
        }

        // Update tail to point to the previous node
        tail = tail->prev;
        tail->next = nullptr; // Set the next of the new tail to null
        delete temp;          // Deallocate memory for the deleted node
        cout << "Last node deleted" << endl;
    }

    void deleteAtStart()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        DoublyNode *temp = head; // Store the current head node
        head = head->next;       // Update head to point to the next node
        if (head != nullptr)
        {
            head->prev = nullptr; // Reset previous pointer of new head
        }
        else
        {
            tail = nullptr; // Reset tail if list becomes empty
        }
        delete temp; // Deallocate memory for the old head node
        cout << "Element deleted from start" << endl;
    }
    void deleteAfter(int position)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        DoublyNode *current = head;
        // Traverse to the specified position
        for (int i = 0; i < position && current != nullptr; i++)
        {
            current = current->next;
        }

        if (current == nullptr || current->next == nullptr)
        {
            cout << "Position out of bounds." << endl;
            return;
        }
        // Skip the node to be deleted
        DoublyNode *toDelete = current->next;
        current->next = toDelete->next;
        if (toDelete->next != nullptr)
        {
            toDelete->next->prev = current; // Link the next node back to current
        }
        else
        {
            tail = current; // Update tail if deleted last node
        }
        delete toDelete; // Deallocate memory for the deleted node
        cout << "Deleted element at index " << position << endl;
    }
    ~DoublyLinkedList()
    {
        while (head != nullptr)
        {
            deleteAtStart(); // Delete all nodes
        }
    }
};

// ---------------------------- SINGLY CIRCULAR LINKED LIST ----------------------------

class SinglyNode
{
public:
    int data;         // Data of the node
    SinglyNode *next; // Pointer to the next node in the list

    SinglyNode(int d)
    {
        data = d;
        next = nullptr; // Initialize the next pointer to null
    }
};

class CircularSinglyLinkedList
{
private:
    SinglyNode *head; // Pointer to the first node in the list

public:
    CircularSinglyLinkedList()
    {
        head = nullptr; // Initially, the list is empty
    }

    void insertAtEnd(int data)
    {
        SinglyNode *n = new SinglyNode(data);
        if (head == nullptr)
        {
            head = n;       // Set the head if the list is empty
            n->next = head; // Point the new node to itself (circular link)
        }
        else
        {
            SinglyNode *temp = head;
            // Traverse to the last node
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = n; // Link the last node to the new node
            n->next = head; // Make it circular
        }
        cout << "Node inserted at end" << endl;
    }

    void insertAtStart(int data)
    {
        SinglyNode *n = new SinglyNode(data);
        if (head == nullptr)
        {
            head = n;       // Set the head if the list is empty
            n->next = head; // Point the new node to itself (circular link)
        }
        else
        {
            SinglyNode *temp = head;
            // Traverse to the last node
            while (temp->next != head)
            {
                temp = temp->next;
            }
            n->next = head;    // New node points to the current head
            head = n;          // Update head to the new node
            temp->next = head; // Last node points to the new head
        }
        cout << "Node inserted at start" << endl;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        SinglyNode *temp = head;
        do
        {
            cout << temp->data << " --> "; // Display the data
            temp = temp->next;             // Move to the next node
        } while (temp != head);
        cout << "(back to head)" << endl;
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        if (head->next == head) // Only one node exists
        {
            delete head;    // Deallocate memory
            head = nullptr; // Reset head
            cout << "Last node deleted" << endl;
            return;
        }

        SinglyNode *temp = head;
        // Traverse to the second last node
        while (temp->next != head)
        {
            temp = temp->next;
        }

        delete temp->next; // Delete the last node
        temp->next = head; // Make it circular
        cout << "Last node deleted" << endl;
    }

    void deleteAtStart()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        if (head->next == head) // Only one node exists
        {
            delete head;    // Deallocate memory
            head = nullptr; // Reset head
            cout << "Element deleted from start" << endl;
            return;
        }

        SinglyNode *temp = head;
        while (temp->next != head)
        {
            temp = temp->next; // Traverse to the last node
        }

        SinglyNode *toDelete = head; // Store the current head
        head = head->next;           // Update head to point to the next node
        temp->next = head;           // Update the last node to point to new head
        delete toDelete;             // Deallocate memory
        cout << "Element deleted from start" << endl;
    }

    ~CircularSinglyLinkedList()
    {
        while (head != nullptr)
        {
            deleteAtStart(); // Delete all nodes
        }
    }
};

// ---------------------------- DOUBLY CIRCULAR LINKED LIST ----------------------------

class DoublyNode
{
public:
    int data;         // Data of the node
    DoublyNode *next; // Pointer to the next node in the list
    DoublyNode *prev; // Pointer to the previous node in the list
    DoublyNode(int d) : data(d), next(nullptr), prev(nullptr) {}
};

class CircularDoublyLinkedList
{
private:
    DoublyNode *head; // Pointer to the first node in the list
public:
    CircularDoublyLinkedList()
    {
        head = nullptr; // Initially, the list is empty
    }

    void insertAtEnd(int data)
    {
        DoublyNode *n = new DoublyNode(data);
        if (head == nullptr)
        {
            head = n;       // Set the head if the list is empty
            n->next = head; // Point the new node to itself (circular link)
            n->prev = head; // Point the previous of new node to itself
        }
        else
        {
            DoublyNode *temp = head;
            // Traverse to the last node
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = n; // Link the last node to the new node
            n->next = head; // Make it circular
            n->prev = temp; // New node's previous points to last node
            head->prev = n; // Head's previous points to new last node
        }
        cout << "Node inserted at end" << endl;
    }
    void insertAtStart(int data)
    {
        DoublyNode *n = new DoublyNode(data);
        if (head == nullptr)
        {
            head = n;       // Set the head if the list is empty
            n->next = head; // Point the new node to itself (circular link)
            n->prev = head; // Point the previous of new node to itself (circular link)
        }
        else
        {
            DoublyNode *temp = head;
            while (temp->next != head) // Traverse to the last node
            {
                temp = temp->next;
            }
            n->next = head;    // New node points to the current head
            head->prev = n;    // Current head's previous points to new node
            head = n;          // Update head to the new node
            n->prev = temp;    // New node's previous points to last node
            temp->next = head; // Last node points to new head
        }
        cout << "Node inserted at start" << endl;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        DoublyNode *temp = head;
        do
        {
            cout << temp->data << " <--> "; // Display the data
            temp = temp->next;              // Move to the next node
        } while (temp != head);
        cout << "(back to head)" << endl;
    }

    void reverseDisplay()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        DoublyNode *temp = head->prev; // Start from the last node
        do
        {
            cout << temp->data << " <--> "; // Display the data
            temp = temp->prev;              // Move to the previous node
        } while (temp != head->prev);
        cout << "(back to tail)" << endl;
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete" << endl;
            return;
        }

        if (head->next == head) // Only one node exists
        {
            delete head;    // Deallocate memory
            head = nullptr; // Reset head
            cout << "Last node deleted" << endl;
            return;
        }

        DoublyNode *temp = head->prev; // Get the last node
        temp->prev->next = head;       // Link the second last node to head
        head->prev = temp->prev;       // Update head's prev
        delete temp;                   // Deallocate memory
        cout << "Last node deleted" << endl;
    }

    void deleteAtStart()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete" << endl;
            return;
        }

        if (head->next == head) // Only one DoublyNode exists
        {
            delete head;    // Deallocate memory
            head = nullptr; // Reset head
            cout << "Element deleted from start" << endl;
            return;
        }

        DoublyNode *toDelete = head; // Store the current head
        head = head->next;           // Update head to point to the next DoublyNode
        head->prev = toDelete->prev; // Update new head's prev pointer

        toDelete->prev->next = head; // Update the previous DoublyNode's next pointer
        delete toDelete;             // Deallocate memory
        cout << "Element deleted from start" << endl;
    }

    ~CircularDoublyLinkedList()
    {
        while (head != nullptr)
        {
            deleteAtStart(); // Delete all DoublyNodes
        }
    }
};