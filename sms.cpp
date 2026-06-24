#include <iostream>
using namespace std;

struct student {
    string name;
    int roll;
    string branch;
    float cgpa;
};

float inputCGPA() {
    float cgpa;
    while (true) {
        cout << "CGPA (0-10) : ";
        if (!(cin >> cgpa)) {
            cout << "Invalid Input! Enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (cgpa < 0 || cgpa > 10) {
            cout << "Invalid CGPA! Enter between 0 and 10.\n";
            continue;
        }
        return cgpa;
    }
}

void add(student s[], int &n) {
    if (n == 100) {
        cout << "Database Full!!\n";
        return;
    }
    int roll;
    cout << "Roll Number : ";
    cin >> roll;
    for (int i = 0; i < n; i++) {
        if (s[i].roll == roll) {
            cout << "Roll Number Already Exists!!\n";
            return;
        }
    }
    s[n].roll = roll;
    cout << "\nEnter Student " << n + 1 << " Details :-\n";
    cout << "Name : ";
    getline(cin >> ws, s[n].name);
    cout << "Branch : ";
    getline(cin >> ws, s[n].branch);
    s[n].cgpa = inputCGPA();
    n++;
    cout << "Student Added Successfully!!\n";
}

void display(const student s[], int n) {
    if (n == 0) {
        cout << "No Students Found!!\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << " Details :-\n";
        printStudent(s[i]);
        cout << "\n------------------------\n";
    }
}

void searchByRoll(const student s[], int n) {
    if (n == 0) {
        cout << "No Students Found!!\n";
        return;
    }
    int key;
    cout << "Enter Student Roll Number : ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (s[i].roll == key) {
            cout << "\nStudent Found :-\n";
            printStudent(s[i]);
            cout << "\n------------------------\n";
            return;
        }
    }
    cout << "Student Not Found!!\n";
}

void searchByName(const student s[], int n) {
    if (n == 0) {
        cout << "No Students Found!!\n";
        return;
    }

    string key;

    cout << "Enter Student Name : ";
    getline(cin >> ws, key);

    for (int i = 0; i < n; i++) {
        if (s[i].name == key) {
            cout << "\nStudent Found :-\n";
            printStudent(s[i]);
            cout << "\n------------------------\n";
            return;
        }
    }

    cout << "Student Not Found!!\n";
}


void update(student s[], int n) {
    if (n == 0) {
        cout << "No Students Found!!\n";
        return;
    }
    int key;
    cout << "Enter Student Roll Number : ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (s[i].roll == key) {
            cout << "\nCurrent Details :-\n";
            printStudent(s[i]);
            cout << "\n\nEnter New Details :-\n";
            cout << "Name : ";
            getline(cin >> ws, s[i].name);
            int newRoll;
            cout << "New Roll Number : ";
            cin >> newRoll;
            for (int j = 0; j < n; j++) {
                if (j != i && s[j].roll == newRoll) {
                    cout << "Roll Number Already Exists!!\n";
                    return;
                }
            }
            s[i].roll = newRoll;
            cout << "Branch : ";
            getline(cin >> ws, s[i].branch);
            s[i].cgpa = inputCGPA();
            cout << "Student Data Updated Successfully!!\n";
            return;
        }
    }
    cout << "Student Not Found!!\n";
}

void del(student s[], int &n) {
    if (n == 0) {
        cout << "No Students Found!!\n";
        return;
    }
    int key;
    cout << "Enter Student Roll Number : ";
    cin >> key;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (s[i].roll == key) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "Student Not Found!!\n";
        return;
    }
    char confirm;
    cout << "Are you sure you want to delete this record? (Y/N) : ";
    cin >> confirm;
    if (confirm != 'Y' && confirm != 'y') {
        cout << "Deletion Cancelled.\n";
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        s[i] = s[i + 1];
    }
    n--;
    cout << "Record Deleted Successfully!!\n";
}

void topper(const student s[], int n) {
    if (n == 0) {
        cout << "No Students Found!!\n";
        return;
    }

    int pos = 0;

    for (int i = 1; i < n; i++) {
        if (s[i].cgpa > s[pos].cgpa)
            pos = i;
    }

    cout << "\nTopper Details :-\n";
    printStudent(s[pos]);
    cout << "\n------------------------\n";
}

int main() {
    int n = 0;
    int choice;
    student s[100];
    cout << "========================================\n";
    cout << "     STUDENT MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    while (true) {
        cout << "\nTotal Students In Database : " << n << "\n";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student By Roll Number";
        cout << "\n4. Search Student By Name";
        cout << "\n5. Update Student";
        cout << "\n6. Delete Student";
        cout << "\n7. Topper Student";
        cout << "\n8. Exit";
        cout << "\nEnter Choice : ";
        cin >> choice;
        switch (choice) {
            case 1:
                add(s, n);
                break;
            case 2:
                display(s, n);
                break;
            case 3:
                searchByRoll(s, n);
                break;
            case 4:
                searchByName(s, n);
                break;
            case 5:
                update(s, n);
                break;
            case 6:
                del(s, n);
                break;
            case 7:
                topper(s, n);
                break;
            case 8:
                cout << "Exiting Program...\n";
                return 0;
            default:
                cout << "Invalid Choice!!\n";
        }
    }
    return 0;
}
