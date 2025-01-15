#include <iostream>
using namespace std;

// ---------------------------- Stack Using Array ----------------------------

#define STACK_SIZE 100

class Stack
{
private:
    int top;               // Index of the topmost element in the stack
    int array[STACK_SIZE]; // Array to store stack elements

public:
    Stack() // Constructor to initialize the stack
    {
        top = -1; // Initialize stack as empty
    }

    void push(int val)
    {
        if (top < STACK_SIZE - 1) // Check for stack overflow
        {
            array[++top] = val; // Increment top and add value
            cout << val << " added" << endl;
        }
        else
        {
            cout << "Stack overflow: cannot add " << val << endl;
        }
    }

    int pop()
    {
        if (top != -1) // Check for stack underflow
        {
            return array[top--]; // Return the topmost value and decrement top
        }
        else
        {
            cout << "Stack underflow: cannot pop" << endl;
            return -1; // Return an error value
        }
    }

    int peek()
    {
        if (top != -1) // Check if the stack is empty
        {
            return array[top]; // Return the topmost value without removing it
        }
        else
        {
            cout << "Stack is empty: cannot peek" << endl;
            return -1; // Return an error value
        }
    }

    bool isEmpty()
    {
        return (top == -1); // Return true if stack is empty
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) // Iterate from top to bottom
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

// ---------------------------- Stack using Singly Linked List ----------------------------

struct Node
{
    int data;   // Data held by the node
    Node *next; // Pointer to the next node
};
class Stack
{
private:
    Node *top; // Pointer to the top of the stack

public:
    Stack() : top(nullptr) {}
    void push(int insertVal)
    {
        Node *temp = new Node(); // Create a new node
        if (!temp)               // If temp cannot be created, handle overflow (in practice, this would be an unusual case)
        {
            cout << "Stack is full (overflow)" << endl;
            return;
        }
        temp->data = insertVal; // Set node data
        temp->next = top;       // Point to the current top
        top = temp;             // Update top to the new node

        cout << insertVal << " inserted in stack" << endl;
    }
    int pop()
    {
        if (!top)
        { // Check for underflow
            cout << "Stack is empty (underflow)" << endl;
            return -1; // Return an error value
        }
        Node *temp = top;             // Temporary pointer to the top node
        int returnValue = temp->data; // Get the data from the top node

        top = top->next;    // Update top to the next node
        delete temp;        // Delete the old top node
        return returnValue; // Return the popped value
    }

    int peek()
    {
        if (!top)
        { // Check if the stack is empty
            cout << "Stack is empty (underflow)" << endl;
            return -1; // Return an error value
        }

        return top->data; // Return the top element
    }
    bool isEmpty()
    {
        return top == nullptr; // Return true if stack is empty
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }
        Node *current = top; // Start from the top node
        while (current != nullptr)
        {
            cout << current->data << " "; // Print the current node's data
            current = current->next;      // Move to the next node
        }
        cout << endl;
    }
    ~Stack()
    {
        while (!isEmpty())
        {
            pop(); // Pop all elements to free memory
        }
    }
};

// ---------------------------- Stack Using Doubly Linked List ----------------------------

class Node
{
public:
    int data;   // Data held by the node
    Node *next; // Pointer to the next node
    Node *prev; // Pointer to the previous node

    Node(int value) : data(value), next(nullptr), prev(nullptr) {} // Initialize data, next, and prev
};
class Stack
{
private:
    Node *top; // Pointer to the top of the stack
public:
    Stack() : top(nullptr) {}
    void push(int insertVal)
    {
        Node *newNode = new Node(insertVal); // Create a new node with the given value

        if (top)
        {                        // If stack is not empty
            newNode->prev = top; // Set the previous pointer of new node
            top->next = newNode; // Link current top node to new node
        }
        top = newNode; // Update top to the new node
        cout << insertVal << " pushed to stack" << endl;
    }
    int pop()
    {
        if (!top)
        { // Check for underflow
            cout << "Stack is empty (underflow)" << endl;
            return -1; // Return an error value
        }
        Node *temp = top;             // Temporary pointer to the top node
        int returnValue = temp->data; // Get the data from the top node

        top = top->prev; // Update top to the previous node
        delete temp;
        return returnValue; // Return the popped value
    }
    int peek()
    {
        if (!top)
        { // Check if the stack is empty
            cout << "Stack is empty (underflow)" << endl;
            return -1; // Return an error value
        }

        return top->data; // Return the top element
    }

    bool isEmpty()
    {
        return top == nullptr; // Return true if stack is empty
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements (top to bottom): ";
        Node *current = top; // Start from the top node
        while (current != nullptr)
        {
            cout << current->data << " "; // Print the current node's data
            current = current->prev;      // Move to the previous node
        }
        cout << endl;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop(); // Pop all elements to free memory
        }
    }
};