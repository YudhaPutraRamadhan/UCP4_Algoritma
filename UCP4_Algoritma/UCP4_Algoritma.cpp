#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node* next;
};
// Queue class1

class Queue
{
private:
    Node* front;
    Node* rear;

public:
    // Constructor to initialize the queue
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // 1. Allocate memory for the new node.
    // 2. Assign value to the data field of the new node.
    // 3. Make the next field of the new node point to NULL.
    // 4. If the queue is empty, execute the following steps:
    // a. Make FRONT point to the new node
    // b. Make REAR  point to the new node
    // d. Exit
    // 5. Make the next field of REAR point to the new node.
    // 6. Make REAR point to the new node.

    // LENGKAPI FUNGSI INI SESUAI ALOGORITMA DIATAS
    void insert()
    {
        int value;
        cout << "Enter value to enqueue: ";
        cin >> value;

        Node* newNode = new Node(); 
        newNode->data = value; 
        newNode->next = NULL;

        if (isEmpty())
        {
            front = newNode;
            rear = newNode;

        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }


    }

    //1. If the queue is empty: // FRONT = NULL
        // a. Display “Queue empty”
        // b. Exit
    //2. Mark the node marked FRONT as current
    //3. Make FRONT point to the next node in its sequence
    //4. Release the memory for the node marked as current

    // LENGKAPI FUNGSI INI SESUAI ALOGORITMA DIATAS
    void deleteQueue()
    {
        if (isEmpty())
        {
            cout << " antrian kosong" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        delete temp;
    }

    // Function to display all elements of the queue
    void display()
    {
        if (isEmpty()) // step 1
        {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == NULL && rear == NULL;
    }
};

int main()
{
    Queue q;
    int choice;

    do
    {
        cout << "\nQueue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            q.insert();
            break;
        case 2:
            q.deleteQueue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, please try again\n";
        }
    } while (choice != 7);

    return 0;
}