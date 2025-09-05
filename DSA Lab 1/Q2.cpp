#include <iostream>
using namespace std;

/*
	Name : Muhammad Umar
	Class : CSIT Section A Batch 24
	Roll no. : CT - 24028
*/

class Student {
private:
    string name;
    double grades[5];
public:
    Student(string n, double g[]) {
        name = n;
        for (int i = 0; i < 5; i++) {
            grades[i] = g[i];
        }
    }

    double calculateGPA() {
        double sum = 0;
        int count = 0;
        for (int i = 0; i < 5; i++) {
            if (grades[i] != -1) {
                sum += grades[i];
                count++;
            }
        }
        if (count > 0) {
            return sum / count;
        } 
        return 0.0;
    }

    void display() {
        cout << name << " GPA = " << calculateGPA() << endl;
    }
};


int main() {
    string subjects[5];
    cout << "Enter names of 5 subjects:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Subject " << i + 1 << ": ";
        getline(cin, subjects[i]);
    }

    int size;
    cout << "\nEnter number of students: ";
    cin >> size;
    cin.ignore();

    Student* students[size];

    for (int i = 0; i < size; i++) {
        string name;
        double grades[5];

        cout << "\nEnter name of student " << i + 1 << ": ";
        getline(cin, name);

        cout << "Enter grades for " << name << " :\n";
        for (int j = 0; j < 5; j++) {
            cout << subjects[j] << ": ";
            cin >> grades[j];
        }
        cin.ignore();

        students[i] = new Student(name, grades);
    }

    cout << "\n--- Student GPAs ---\n";
    for (int i = 0; i < size; i++) {
        students[i]->display();
        delete students[i];
    }

    return 0;
}


