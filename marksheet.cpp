#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
    int rollNo;
    int marks[5]; // 5 subjects
    int total;
    float percentage;
    char grade;

public:
    void input() {
        name = "Rahul Sharma";   // already filled
        rollNo = 101;            // already filled
        int sampleMarks[5] = {85, 78, 92, 88, 76}; // already filled

        total = 0;
        for (int i = 0; i < 5; i++) {
            marks[i] = sampleMarks[i];
            total += marks[i];
        }

        percentage = total / 5.0;
        calculateGrade();
    }

    void calculateGrade() {
        if (percentage >= 90)
            grade = 'A';
        else if (percentage >= 75)
            grade = 'B';
        else if (percentage >= 60)
            grade = 'C';
        else if (percentage >= 50)
            grade = 'D';
        else
            grade = 'F';
    }

    void display() {
        cout << "\n----- Student marksheet -----\n";
        cout << "Name       : " << name << endl;
        cout << "Roll No    : " << rollNo << endl;

        for (int i = 0; i < 5; i++) {
            cout << "Subject " << (i + 1) << " Marks: " << marks[i] << endl;
        }

        cout << "Total Marks: " << total << "/500" << endl;
        cout << "Percentage : " << percentage << "%" << endl;
        cout << "Grade      : " << grade << endl;
        cout << "-----------------------------\n";
    }
};

int main() {
    Student s;
    s.input();
    s.display();
    return 0;
}
