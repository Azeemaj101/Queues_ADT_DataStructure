#include <iostream>
#include <windows.h>
using namespace std;

class Queue
{
public:
    int rear, front;
    int capacity;
    int *Array;
};

class Queue_ADT
{
public:
    Queue *NewQueue = new Queue();
    Queue_ADT(int Capacity)
    {
        NewQueue->rear = -1;
        NewQueue->front = -1;
        NewQueue->capacity = Capacity;
        NewQueue->Array = new int[Capacity];
    }
    int isEmptyQueue()
    {
        return NewQueue->front == -1;
    }
    int isFullQueue()
    {
        bool a = ((NewQueue->rear + 1) % NewQueue->capacity == NewQueue->front);
        return a;
    }
    int QueueSize()
    {
        return ((NewQueue->capacity - NewQueue->front + NewQueue->rear + 1) % NewQueue->capacity);
    }
    void enQueue(int Data)
    {

        if (!NewQueue)
        {
            return;
        }
        if (isFullQueue())
        {
            cout << "Queue is Full\n";
        }
        else
        {
            NewQueue->rear = (NewQueue->rear + 1) % NewQueue->capacity;
            NewQueue->Array[NewQueue->rear] = Data;
            if (NewQueue->front == -1)
            {
                NewQueue->front = NewQueue->rear;
            }
        }
    }
    int deQueue()
    {
        int data = -1;
        if (isEmptyQueue())
        {
            return -1;
        }
        else
        {
            data = NewQueue->Array[NewQueue->front];
            if (NewQueue->front == NewQueue->rear)
            {
                NewQueue->front = -1;
                NewQueue->rear = -1;
            }
            else
            {
                NewQueue->front = (NewQueue->front + 1) % NewQueue->capacity;
            }
        }
        return data;
    }
    void DeleteQueue()
    {
        if (NewQueue)
        {
            if (NewQueue->Array)
            {
                delete NewQueue->Array;
            }
            delete NewQueue;
        }
    }
    void View(int Size)
    {
        if (!isEmptyQueue())
        {
            cout << "The Queue Data is = ";
            for (int i = 0; i <= Size; i++)
            {
                cout << NewQueue->Array[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "The Queue is Empty\n";
        }
    }
};

int main()
{
    int Size, sel, count = 0;
    bool Goto = true;
    system("color 03");
    system("CLS");
    cout << "Enter The size of Queue\n";
    cin >> Size;
    Queue_ADT Obj(Size);
    while (Goto == true)
    {
        system("CLS");
        cout << "\t\t\t\t Total Queue Size is " << Size << " & Filled is " << count << endl;
        cout << "Press 1 For Insert (enqueue) \n";
        cout << "Press 2 For Delete (dequeue) \n";
        cout << "Press 3 For Delete All Queue & Exit \n";
        cout << "Press 4 For Check  Queue is Full? \n";
        cout << "Press 5 For Check  Queue is Empty? \n";
        cout << "Press 6 For View   All   Queue \n";
        cout << "Press 7 For Exit \n";
        cin >> sel;
        switch (sel)
        {
        case 1:
        {
            int val;
            cout << "Enter value for Queue\n";
            cin >> val;
            Obj.enQueue(val);
            if (count != Size)
            {
                count++;
            }

            system("PAUSE");
            break;
        }
        case 2:
        {
            int Data = Obj.deQueue();
            if (Data != -1)
            {
                cout << "Delete First Queue (Queue Data is " << Data << " )" << endl;
                count--;
            }
            else
            {
                cout << "Queue is Empty First Insert Any Data First\n";
            }
            system("PAUSE");
            break;
        }
        case 3:
        {
            Obj.DeleteQueue();
            cout << "Deleting<< ";
            for (int i = 0; i < 30; i++)
            {
                cout << "|";
                cout.flush();
                Sleep(105);
            }
            cout << " >> Successful...\n";
            count = 0;
            Goto = false;
            break;
        }
        case 4:
        {
            if (Obj.isFullQueue())
            {
                cout << "Queue is Full!\n";
            }
            else
            {
                cout << "The Queue is not Full\n";
            }
            system("PAUSE");
            break;
        }
        case 5:
        {
            if (Obj.isEmptyQueue())
            {
                cout << "Queue is Empty\n";
            }
            else
            {
                cout << "Queue contain some Data\n";
            }
            system("PAUSE");
            break;
        }
        case 6:
        {
            Obj.View(count);
            system("PAUSE");
            break;
        }
        case 7:
        {
            Goto = false;
            break;
        }

        default:
        {
            cout << "Please press Right Key\n";
            system("PAUSE");
            break;
        }
        }
    }
}