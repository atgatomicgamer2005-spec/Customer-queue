#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

string customers[MAX];
int front = 0;
int rear = -1;
int count = 0;

void addCustomer(string name) {
    if (count == MAX) {
        cout << "Queue is full!\n";
        return;
    }

    rear = (rear + 1) % MAX;
    customers[rear] = name;
    count++;

    cout << name << " added to the queue.\n";
}

void serveCustomer() {
    if (count == 0) {
        cout << "No customers are waiting.\n";
        return;
    }

    cout << "Serving customer: "
         << customers[front] << endl;

    front = (front + 1) % MAX;
    count--;
}

void displayQueue() {
    if (count == 0) {
        cout << "The queue is empty.\n";
        return;
    }

    cout << "\nCustomers waiting:\n";

    for (int i = 0; i < count; i++) {
        int index = (front + i) % MAX;
        cout << i + 1 << ". "
             << customers[index] << endl;
    }
}

int main() {
    addCustomer("Elvis");
    addCustomer("Daniel");
    addCustomer("Michael");

    displayQueue();

    serveCustomer();

    displayQueue();

    return 0;
}