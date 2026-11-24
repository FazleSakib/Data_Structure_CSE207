#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../include/Student.h"
#include "../include/StudentBST.h"

using namespace std;

int main()
{
    srand(time(0));
    StudentBST bst;
    int choice;

    while (true)
    {
        cout << "\n Student Record Management System: \n";
        cout << "1. Insert student Record\n";
        cout << "2. Search Student Record\n";
        cout << "3. Delete student Record\n";
        cout << "4. Show All student Records\n";
        cout << "5. Exit\n";
        cout << "Enter your choice:   ";

        cin >> choice;

        if (choice == 1)
        {
            string name, course;
            double totalMarks, cgpa;

            int roll = 1000 + (rand() % 9000);
            while (bst.checkRecord(roll))
            {
                roll = 1000 + (rand() % 9000);
            }

            cin.ignore();
            cout << "Enter student Name:";
            getline(cin, name);

            cout << "Enter course enrolled:";
            getline(cin, course);

            cout << "Enter total marks: ";
            cin >> totalMarks;

            cout << "Enter CGPA: ";
            cin >> cgpa;

            cout << "Roll number: " << roll << "\n";
            Student s(name, roll, course, totalMarks, cgpa);
            bst.createRecord(s);
        }

        else if (choice == 2)
        {
            int roll;
            cout << "Enter Roll Number to search: ";
            cin >> roll;
            bst.searchRecord(roll);
        }

        else if (choice == 3)
        {
            int roll;
            cout << "Enter Roll Number to delete: ";
            cin >> roll;

            int status = bst.deleteRecord(roll);
            if (status == 0)
            {
                cout << "student record with Roll " << roll << " deleted successfully\n";
            }
            else
            {
                cout << "student record with Roll " << roll << " not found\n";
            }
        }
        else if (choice == 4)
        {
            bst.showRecord();
        }
        else if (choice == 5)
        {
            cout << "end of  program\n";
            break;
        }
        else
        {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}