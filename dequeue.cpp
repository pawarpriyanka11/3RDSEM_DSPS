 


#include <iostream>
#define MAX 10
using namespace std;

class Dequeue {
    int q[MAX];
    int front, rear;

public:
    Dequeue() : front(-1), rear(-1) {}

    // Insert at the rear
    void insertRear() {
        int value;
        cout << "\nEnter number to be inserted at rear: ";
        cin >> value;

        if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
            cout << "\nOverflow";
            return;
        }

        if (front == -1) { // First element
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0; // Wrap around
        } else {
            rear++;
        }

        q[rear] = value;
    }

    // Insert at the front
    void insertFront() {
        int value;
        cout << "\nEnter number to be inserted at front: ";
        cin >> value;

        if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
            cout << "\nOverflow";
            return;
        }

        if (front == -1) { // First element
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1; // Wrap around
        } else {
            front--;
        }

        q[front] = value;
    }

    // Delete from the front
    void deleteFront() {
        if (front == -1) {
            cout << "\nUnderflow";
            return;
        }

        cout << "\nDeleted number from front: " << q[front];
        if (front == rear) { // Queue becomes empty
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0; // Wrap around
        } else {
            front++;
        }
    }

    // Delete from the rear
    void deleteRear() {
        if (rear == -1) {
            cout << "\nUnderflow";
            return;
        }

        cout << "\nDeleted number from rear: " << q[rear];
        if (front == rear) { // Queue becomes empty
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1; // Wrap around
        } else {
            rear--;
        }
    }

    // Display the deque
    void display() {
        if (front == -1) {
            cout << "\nQueue is empty!";
            return;
        }

        cout << "\nQueue elements: ";
        int i = front;
        while (true) {
            cout << q[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    Dequeue dq;
    int choice;

    do {
        cout << "\nMenu:\n1. Insert at rear\n2. Insert at front\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                dq.insertRear();
                break;
            case 2:
                dq.insertFront();
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                dq.display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
