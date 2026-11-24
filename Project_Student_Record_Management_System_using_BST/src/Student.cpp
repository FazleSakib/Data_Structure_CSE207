#include "Student.h"
#include <iostream>
using namespace std;
class Student
{
private:
    string name;
    int roll;
    string course;
    double totalMarks, cgpa;

public:
    Student()
    {
        name = "";
        roll = 0;
        course = "";
        totalMarks = 0.0;
        cgpa = 0.0;
    }

        Student(string name, int roll, string course, double totalMarks, double cgpa)
    {
        this->name = name;
        this->roll = roll;
        this->course = course;
        this->totalMarks = totalMarks;
        this->cgpa = cgpa;
    }

    string getName()
    {
        return name;
    }
    void setName(string name)
    {
        this->name = name;
    }
    int getRoll()
    {
        return roll;
    }
    void setRoll(int roll)
    {
        this->roll = roll;
    }
    string getCourse()
    {
        return course;
    }
    void setCourse(string course)
    {
        this->course = course;
    }
    double getTotalMarks()
    {
        return totalMarks;
    }
    void setTotalMarks(double totalMarks)
    {
        this->totalMarks = totalMarks;
    }
    double getCgpa()
    {
        return cgpa;
    }
    void setCgpa(double cgpa)
    {
        this->cgpa = cgpa;
    }

    void display()
    {
        cout << "Name        :     " << name << endl;
        cout << "Roll        :     " << roll << endl;
        cout << "Course      :     " << course << endl;
        cout << "Total Marks :     " << totalMarks << endl;
        cout << "CGPA        :     " << cgpa << endl;
    }
};