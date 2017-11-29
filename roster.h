/*
 Name: Bernice Tran
 Class: CSCI 211-32A
 Header file for roster class.
 */

#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
#include <iostream>
#include <string>

using namespace std;

class Roster
{
private:
    string lastName, firstName, courseName;
    Student **students;
    int courseCode;
    int credits;
    int capacity = 10;
    int size;
    
    //Functions
    void sort();
    void grow();
    
public:
    
    //Constructors******************************************************************
    
    //Roster();
    
    Roster(string course_name = "Computer Science", int course_code = 211, int course_credits = 3) : courseName(course_name), courseCode(course_code), credits(course_credits)
    {
        students = new Student*[capacity];
        for (int i = 0; i < capacity; i++)
        {
            students[i] = NULL;
        }
    }
    
    //Copy constructor
    Roster(const Roster& rhs);
    
    //Overloaded assignment
    Roster& operator =(const Roster& rhs);
    
    //Destructor
    ~Roster();
    
    //Accessors (getters)***********************************************************
    
    string getCourseName() const;
    int getCourseCode() const;
    int getCredits() const;
    int getStudent(const Student& s);
    string getProfessorName();
    
    //Mutators (setters)************************************************************
    
    void setCourseName(string course);
    void setCourseCode(int code);
    void setCredits(int creds);
    void setFirstName(string first);
    void setLastName(string last);
    void addStudent(Student& s);
    bool deleteStudent(const Student& s);
    bool updateStudent(const Student& s);
    
    //Input*************************************************************************
    
    void dataInput();
    
    //Output************************************************************************
    
    void printStudentList();
    
    //Overloaded i/o stream operators***********************************************
    
    friend ostream& operator<<(ostream&, const Roster&);
    friend istream& operator>>(istream&, Roster&);
    
    //Overloaded Operator **********************************************************
    
    Student* operator[](const int index);
    
    void saveStudentList(ostream &out);
    
};

#endif /* Roster_h */
