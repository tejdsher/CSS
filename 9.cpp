#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main() {
    int choice;
    string filename, data, line;

    do {
        cout << "\n1. Create and Write File";
        cout << "\n2. Read File";
        cout << "\n4. Delete File";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter filename: ";
                cin >> filename;

                ofstream fout(filename);

                if (!fout) {
                    cout << "File creation failed\n";
                    break;
                }

                cout << "Enter data: ";
                cin.ignore();
                getline(cin, data);

                fout << data;
                fout.close();

                cout << "File created and written successfully\n";
                break;
            }

            case 2: {
                cout << "Enter filename: ";
                cin >> filename;

                ifstream fin(filename);

                if (!fin) {
                    cout << "File not found\n";
                    break;
                }

                cout << "\nFile contents:\n";

                while (getline(fin, line))
                    cout << line << endl;

                fin.close();
                break;
            }

            case 3: {
                cout << "Enter filename: ";
                cin >> filename;

                if (remove(filename.c_str()) == 0)
                    cout << "File deleted successfully\n";
                else
                    cout << "Unable to delete file\n";

                break;
            }

            case 5:
                cout << "Exiting\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}