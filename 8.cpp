#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

struct Contact {
    string name;
    string phone;
    int status;
};

Contact table[SIZE];

int hashFunction(string name) {
    int sum = 0;

    for (int i = 0; i < name.length(); i++)
        sum += name[i];

    return sum % SIZE;
}

void insertContact() {
    string name, phone;

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter phone number: ";
    cin >> phone;

    int index = hashFunction(name);

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (table[pos].status == 1 &&
            table[pos].name == name) {
            table[pos].phone = phone;
            cout << "Contact updated\n";
            return;
        }

        if (table[pos].status != 1) {
            table[pos].name = name;
            table[pos].phone = phone;
            table[pos].status = 1;

            cout << "Contact inserted\n";
            return;
        }
    }

    cout << "Hash table is full\n";
}

void searchContact() {
    string name;

    cout << "Enter name to search: ";
    cin >> name;

    int index = hashFunction(name);

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (table[pos].status == 0)
            break;

        if (table[pos].status == 1 &&
            table[pos].name == name) {
            cout << "Phone Number: "
                 << table[pos].phone << endl;
            return;
        }
    }

    cout << "Contact not found\n";
}

void deleteContact() {
    string name;

    cout << "Enter name to delete: ";
    cin >> name;

    int index = hashFunction(name);

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (table[pos].status == 0)
            break;

        if (table[pos].status == 1 &&
            table[pos].name == name) {
            table[pos].status = 2;

            cout << "Contact deleted\n";
            return;
        }
    }

    cout << "Contact not found\n";
}

void display() {
    cout << "\nTelephone Directory:\n";

    for (int i = 0; i < SIZE; i++) {
        if (table[i].status == 1) {
            cout << table[i].name << " : "
                 << table[i].phone << endl;
        }
    }
}

int main() {
    int choice;

    for (int i = 0; i < SIZE; i++)
        table[i].status = 0;

    do {
        cout << "\n1. Insert Contact";
        cout << "\n2. Search Contact";
        cout << "\n3. Delete Contact";
        cout << "\n4. Display Directory";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertContact();
                break;

            case 2:
                searchContact();
                break;

            case 3:
                deleteContact();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}