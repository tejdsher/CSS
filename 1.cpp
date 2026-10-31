#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    int id;
    char name[50];
    float cgpa;
};

void bubbleSort(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(s[j].name, s[j + 1].name) > 0) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void selectionSort(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (s[j].cgpa > s[maxIndex].cgpa)
                maxIndex = j;
        }

        Student temp = s[i];
        s[i] = s[maxIndex];
        s[maxIndex] = temp;
    }
}

void linearSearch(Student s[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (s[i].id == id) {
            cout << "Student Found: " << s[i].name
                 << " " << s[i].cgpa << endl;
            return;
        }
    }
    cout << "Student Not Found\n";
}

void binarySearch(Student s[], int n, int id) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (s[mid].id == id) {
            cout << "Student Found: " << s[mid].name
                 << " " << s[mid].cgpa << endl;
            return;
        }
        else if (s[mid].id < id)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << "Student Not Found\n";
}

void display(Student s[], int n) {
    for (int i = 0; i < n; i++) {
        cout << s[i].id << " "
             << s[i].name << " "
             << s[i].cgpa << endl;
    }
}

int main() {
    int n, choice, id;

    cout << "Enter number of students: ";
    cin >> n;

    Student *s = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter ID, Name and CGPA: ";
        cin >> s[i].id >> s[i].name >> s[i].cgpa;
    }

    do {
        cout << "\n1. Display";
        cout << "\n2. Linear Search";
        cout << "\n3. Binary Search";
        cout << "\n4. Sort by Name";
        cout << "\n5. Sort by CGPA";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                display(s, n);
                break;

            case 2:
                cout << "Enter ID: ";
                cin >> id;
                linearSearch(s, n, id);
                break;

            case 3: {
                Student *temp = new Student[n];

                for (int i = 0; i < n; i++)
                    temp[i] = s[i];

                // Sort records by ID for binary search
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (temp[j].id > temp[j + 1].id) {
                            Student t = temp[j];
                            temp[j] = temp[j + 1];
                            temp[j + 1] = t;
                        }
                    }
                }

                cout << "Enter ID: ";
                cin >> id;
                binarySearch(temp, n, id);

                delete[] temp;
                break;
            }

            case 4:
                bubbleSort(s, n);
                cout << "Sorted by Name:\n";
                display(s, n);
                break;

            case 5:
                selectionSort(s, n);
                cout << "Sorted by CGPA (Descending):\n";
                display(s, n);
                break;
        }

    } while (choice != 6);

    delete[] s;
    return 0;
}