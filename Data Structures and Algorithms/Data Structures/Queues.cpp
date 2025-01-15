#include <iostream>
using namespace std;

// ---------------------------- Linear Queue Using Array ----------------------------

class Queue
{
public:
    unsigned int capacity; // Maximum number of elements in the queue
    int size;              // Current number of elements in the queue
    int front;             // Index of the front element
    int rear;              // Index of the rear element
    int *array;            // Array to store the queue elements

    Queue(unsigned int capa)
    {
        capacity = capa;
        size = 0;
        front = 0;
        rear = -1;                 // Rear starts at -1 for an empty queue
        array = new int[capacity]; // Allocate memory for the array
    }
    ~Queue()
    {
        delete[] array; // Free allocated memory for array
    }

    bool isFull()
    {
        return (size == capacity);
    }
    bool isEmpty()
    {
        return (size == 0);
    }

    void enqueue(int insertVal)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        // Move rear forward and insert the value
        rear++;
        array[rear] = insertVal;
        size++;
        cout << insertVal << " enqueued" << endl;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        // Storing element to be removed
        int temp = array[front];
        // Move front forward
        front++;
        size--;

        return temp; // Return the removed value
    }

    void forwardDisplayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue (forward): ";
        for (int i = front; i <= rear; i++)
        {
            cout << array[i] << " "; // Display elements from front to rear
        }
        cout << endl;
    }
    void backwardDisplayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue (backward): ";
        for (int i = rear; i >= front; i--)
        {
            cout << array[i] << " "; // Display elements from rear to front
        }
        cout << endl;
    }
};

// ---------------------------- Circular Queue Using Array ----------------------------

class Queue
{
public:
    unsigned int capacity; // Maximum number of elements in the queue
    int size;              // Current number of elements in the queue
    int front;             // Index of the front element
    int rear;              // Index of the rear element
    int *array;            // Array to store the queue elements

    Queue(unsigned int capa)
    {
        capacity = capa;
        size = 0;
        front = 0;
        rear = capa - 1;           // Rear starts at capa - 1 for an empty queue
        array = new int[capacity]; // Allocate memory for the array
    }
    ~Queue()
    {
        delete[] array; // Free allocated memory for the array
    }

    bool isFull()
    {
        return (size == capacity);
    }
    bool isEmpty()
    {
        return (size == 0);
    }

    void enqueue(int insertVal)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }

        rear = (rear + 1) % capacity; // Move rear forward in circular manner
        array[rear] = insertVal;      // Insert value at rear
        size++;                       // Increase size
        cout << insertVal << " enqueued" << endl;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        // Storing element to be removed
        int temp = array[front];
        front = (front + 1) % capacity; // Move front forward in circular manner
        size--;                         // Decrease size
        return temp;                    // Return the removed value
    }

    void forwardDisplayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue (forward): ";
        int i = front;
        for (int count = 0; count < size; count++)
        {
            cout << array[i] << " ";
            i = (i + 1) % capacity; // Move in circular manner
        }
        cout << endl;
    }
    void backwardDisplayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue (backward): ";
        int i = (rear + 1) % capacity; // Start from the next element after rear
        for (int count = 0; count < size; count++)
        {
            i = (i - 1 + capacity) % capacity; // circular manner backward
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

// ---------------------------- Queue Using Linked List ----------------------------

struct SinglyNode
{
    int data;
    SinglyNode *next;
};

class LinearQueueSingly
{
public:
    SinglyNode *front;
    SinglyNode *rear;

    LinearQueueSingly() : front(nullptr), rear(nullptr) {}

    bool isEmpty()
    {
        return (front == nullptr);
    }

    void enqueue(int insertVal)
    {
        SinglyNode *temp = new SinglyNode();
        temp->data = insertVal;
        temp->next = nullptr;

        if (isEmpty())
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
        cout << insertVal << " inserted in linear queue" << endl;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        SinglyNode *temp = front;
        int returnValue = temp->data;

        front = front->next;
        delete temp;

        return returnValue;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        SinglyNode *current = front;
        cout << "Linear Queue elements: ";
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~LinearQueueSingly()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

struct DoublyNode
{
    int data;
    DoublyNode *next;
    DoublyNode *prev;
};

class LinearQueueDoubly
{
public:
    DoublyNode *front;
    DoublyNode *rear;

    LinearQueueDoubly() : front(nullptr), rear(nullptr) {}

    bool isEmpty()
    {
        return (front == nullptr);
    }

    void enqueue(int insertVal)
    {
        DoublyNode *temp = new DoublyNode();
        temp->data = insertVal;
        temp->next = nullptr;

        if (isEmpty())
        {
            temp->prev = nullptr;
            front = temp;
            rear = temp;
        }
        else
        {
            temp->prev = rear;
            rear->next = temp;
            rear = temp;
        }
        cout << insertVal << " inserted in linear doubly queue" << endl;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        DoublyNode *temp = front;
        int returnValue = temp->data;

        front = front->next;
        if (front)
        {
            front->prev = nullptr;
        }
        else
        {
            rear = nullptr; // Queue becomes empty
        }
        delete temp;
        return returnValue;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        DoublyNode *current = front;
        cout << "Linear Doubly Queue elements: ";
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~LinearQueueDoubly()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

class CircularQueueSingly
{
public:
    SinglyNode *front;
    SinglyNode *rear;

    CircularQueueSingly() : front(nullptr), rear(nullptr) {}

    bool isEmpty()
    {
        return (front == nullptr);
    }

    void enqueue(int insertVal)
    {
        SinglyNode *temp = new SinglyNode();
        temp->data = insertVal;

        if (isEmpty())
        {
            front = temp;
            rear = temp;
            rear->next = front; // Circular link
        }
        else
        {
            rear->next = temp;
            rear = temp;
            rear->next = front; // Maintain circularity
        }
        cout << insertVal << " inserted in circular queue" << endl;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        SinglyNode *temp = front;
        int returnValue = temp->data;
        if (front == rear)
        { // Only one element
            front = nullptr;
            rear = nullptr;
        }
        else
        {
            front = front->next;
            rear->next = front; // Maintain circularity
        }
        delete temp;
        return returnValue;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        SinglyNode *current = front;
        cout << "Circular Queue elements: ";
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);
        cout << endl;
    }

    ~CircularQueueSingly()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

class CircularQueueDoubly
{
public:
    DoublyNode *front;
    DoublyNode *rear;

    CircularQueueDoubly() : front(nullptr), rear(nullptr) {}

    bool isEmpty()
    {
        return (front == nullptr);
    }

    void enqueue(int insertVal)
    {
        DoublyNode *temp = new DoublyNode();
        temp->data = insertVal;

        if (isEmpty())
        {
            front = temp;
            rear = temp;
            rear->next = front; // Circular link
            front->prev = rear; // Circular link
        }
        else
        {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
            rear->next = front; // Maintain circularity
            front->prev = rear; // Maintain circularity
        }
        cout << insertVal << " inserted in circular doubly queue" << endl;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        DoublyNode *temp = front;
        int returnValue = temp->data;
        if (front == rear)
        { // Only one element
            front = nullptr;
            rear = nullptr;
        }
        else
        {
            front = front->next;
            rear->next = front; // Maintain circularity
            front->prev = rear; // Maintain circularity
        }
        delete temp;
        return returnValue;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        DoublyNode *current = front;
        cout << "Circular Doubly Queue elements: ";
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);
        cout << endl;
    }

    ~CircularQueueDoubly()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

// ---------------------------- Priority Queue ----------------------------

struct Node
{
    int data;
    int priority;
    Node *next;
};

class PriorityQueue
{
private:
    Node *head;

public:
    PriorityQueue() : head(NULL) {}

    void push(int data, int priority)
    {
        Node *newNode = new Node{data, priority, NULL};
        if (!head || newNode->priority < head->priority)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next && temp->next->priority <= newNode->priority)
                temp = temp->next;

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void pop()
    {
        if (!head)
        {
            cout << "Priority Queue is empty!" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    int peek()
    {
        if (!head)
        {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }
        return head->data;
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "(" << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};