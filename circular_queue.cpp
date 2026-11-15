#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int queue[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if ((rear + 1) % SIZE == front) {
            cout << "Queue is full\n";
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        queue[rear] = value;

        cout << value << " inserted\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << queue[front] << " removed\n";

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;

        while (true) {
            cout << queue[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
