#include <iostream>
#include <vector>
using namespace std;

class Hostel {
private:
    string name;
    int rollNo;

    vector<Hostel> students;
    int bed = 0;

public:
    Hostel(string n = "", int r = 0) {
        name = n;
        rollNo = r;
    }

    bool bedStatus() {
        return bed < 3;
    }

    void add(string n, int r) {
        if (bedStatus()) {
            Hostel s(n, r);
            students.push_back(s);
            bed++;

            cout << "\nBed allocated successfully.\n\n";
        }
        else {
            cout << "\nHostel is full.\n\n";
        }
    }

    void remove() {
        int rn;
        cout << "Enter Roll No: ";
        cin >> rn;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].rollNo == rn) {
                students.erase(students.begin() + i);
                bed--;

                cout << "Student removed successfully.\n\n";
                return;
            }
        }

        cout << "Student not found.\n\n";
    }

    void display() {
        if (students.empty()) {
            cout << "No students in hostel.\n\n";
            return;
        }

        cout << "\nStudents List\n";
        cout << "-------------\n";

        for (int i = 0; i < students.size(); i++) {
            cout << i + 1 << ". Name: " << students[i].name << endl;
            cout << "   Roll No: " << students[i].rollNo << endl;
        }

        cout << endl;
    }
};

int main() {
    Hostel hostel;

    int choice;
    string name;
    int roll;

    while (true) {
        cout << "\n===== Hostel Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Display Students\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter Roll No: ";
            cin >> roll;

            hostel.add(name, roll);
            break;

        case 2:
            hostel.remove();
            break;

        case 3:
            hostel.display();
            break;

        case 0:
            cout << "Program Closed.\n";
            return 0;

        default:
            cout << "Invalid Choice.\n";
        }
    }
}
