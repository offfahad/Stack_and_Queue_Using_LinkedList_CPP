#include <iostream>
using namespace std;

struct node
{
    int data;
    node *ptr;
};
class Queue
{
private:
    node *next, *rear, *front, *temp;
    int count;

public:
    Queue()
    {
        next = rear = front = NULL;
        count = 0;
    }
    void display()
    {
        if (rear == NULL)
        {
            cout << "Queue is empty\n";
        }
        else
        {
            next = front;
            while (next != NULL)
            {
                cout << "| " << next->data << " |";
                next = next->ptr;
            }
        }
    }
    void Enqueue(int x)
    {
        if (rear == NULL)
        {
            next = new node;
            next->data = x;
            front = next;
            rear = next;
            rear->ptr = NULL;
            count++;
        }
        else
        {
            next = new node;
            next->data = x;
            rear->ptr = next;
            rear = next;
            rear->ptr = NULL;
            count++;
        }
    }
    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
        }
		else if (front == rear)
		{
			front = rear = NULL;	
		}
        else
        {
            temp = front;
            front = front->ptr;
            delete (temp);
            cout << "Element popped successfully.\n";
            count--;
        }
    }
    void peek()
    {
        if (rear == NULL)
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << "The top element is:\n";
            cout << rear->data << endl;
        }
    }
    bool isEmpty()
    {
        if (rear == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Queue obj;
    int data, op=-1;
    
    while (op != 7)
    {
        cout << "\n=====================================================\n";
        cout << "Queue using single linked list\n";
        cout << "=====================================================\n";
        cout << "1. Enqueue()\n2. Dequeue()\n3. Display()\n4. Peak\n5. isEmpty()\n6. Clear Screen\n7. Exit\n";
        cin >> op;
        system("CLS");
        switch (op)
        {
        case 1:
            cout << "Enter Number to enter into Queue:\n";
            cin >> data;
            obj.Enqueue(data);
            obj.display();
            cout << "\nElement enqueued successfully.\n";
            break;

        case 2:
            obj.Dequeue();
            obj.display();
            break;

        case 3:
            cout << "Queue:\n";
            obj.display();
            break;

        case 4:
            obj.peek();
            break;

        case 5:
            if (obj.isEmpty())
            {
                cout << "Queue is empty\n";
            }
            else
            {
                cout << "Queue is not empty\n";
            }
            break;

        case 6:
            system("CLS");
            break;

        default:
            cout << "Operation not recognized. Kindly choose correct option [1-5].\n";
            break;
        }
    }
    return 0;
}
