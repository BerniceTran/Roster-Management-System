/*
 Name: Bernice Tran
 Class: CSCI 211-32A
 Cpp file for roster class.
 */

#include "roster.h"

//Default constructor
/*Roster::Roster()
{
    lastName = "";
    firstName = "";
    courseName = "";
    courseCode = 0;
    credits = 0;
    
    students = NULL;
    capacity = 0;
    size = 0;
}*/

//Copy constructor
Roster::Roster(const Roster& rhs)
{
    lastName = rhs.lastName;
    firstName = rhs.lastName;
    courseName = rhs.courseCode;
    courseCode = rhs.courseCode;
    credits = rhs.credits;
    
    students = new Student*[capacity];
    for (int i = 0; i < size; i++)
    {
        students[i] = rhs.students[i];
    }
}

//Overloaded assignment
Roster& Roster::operator =(const Roster& rhs)
{
    if (this != &rhs)
    {
        lastName = rhs.lastName;
        firstName = rhs.lastName;
        courseName = rhs.courseCode;
        courseCode = rhs.courseCode;
        credits = rhs.credits;
        
        students = new Student*[capacity];
        for (int i = 0; i < size; i++)
        {
            students[i] = rhs.students[i];
        }
    }
    return *this;
}

//Destructor
Roster::~Roster()
{
    if (students != NULL)
    {
        for (int i = 0; i < size; i++)
            delete students[i];
    }
    delete [] students;
    students = NULL;
}


//Accessors (getters)***********************************************************

string Roster::getCourseName() const
{
    return courseName;
}

int Roster::getCourseCode() const
{
    return courseCode;
}

int Roster::getCredits() const
{
    return credits;
}

int Roster::getStudent(const Student& s)
{
    for (int i = 0; i < capacity; i++)
    {
        if (students[i] != NULL && *(students[i]) == s)
        {
            return i;
        }
    }
    return -1;
}

string Roster::getProfessorName()
{
    return firstName +  " " + lastName;
}

//Mutators (setters)************************************************************

void Roster::setCourseName(string course)
{
    courseName = course;
}

void Roster::setCourseCode(int code)
{
    courseCode = code;
}

void Roster::setCredits(int creds)
{
    credits = creds;
}

void Roster::setFirstName(string first)
{
    firstName = first;
}

void Roster::setLastName(string last)
{
    lastName = last;
}

void Roster::addStudent(Student& s)
{
    for (int i = 0; i < capacity; i++)
    {
        if (students[i] == NULL)
        {
            students[i] = &s;
            return;
        }
    }
    
    grow();
    ++size;
    students[capacity/2] = &s;
}

void Roster::grow()
{
    int new_capacity = capacity * 2;
    
    Student** newStudentList = new Student*[new_capacity];
    
    for (int i = 0; i < new_capacity; i++)
    {
        if (i < capacity)
        {
            newStudentList[i] = students[i];
        }
        else
            newStudentList[i] = NULL;
    }
    
    delete students;
    capacity = new_capacity;
    students = newStudentList;
}

bool Roster::deleteStudent(const Student& s)
{
    int i = getStudent(s);
    if (i != -1)
    {
        students[i] = NULL;
        return true;
    }
    return false;
}

bool Roster::updateStudent(const Student& s)
{
    int i = getStudent(s);
    if (i != -1)
    {
        if (*(students[i]) == s)
        {
            students[i] = NULL;
            cin >> *(students[i]);
            return true;
        }
    }
    return false;
}

//Sort *************************************************************************

void Roster::sort()
{
    int i, j, minIndex;
    for (i = 0; i < capacity-1; i++)
    {
        minIndex = i;
        for ( j = i + 1; j < capacity; j++)
        {
            if (students[j] != NULL && (students[minIndex] == NULL || *students[j] < *students[minIndex]))
            {
                minIndex = j;
            }
        }
        //swap
        Student* temp = students[i];
        students[i] = students[minIndex];
        students[minIndex] = temp;
    }
}

//Print ************************************************************************

void Roster::printStudentList()
{
    sort();
    for (int i = 0; i < capacity; i++)
    {
        if (students[i] != NULL)
        {
            cout << *(students[i]) << endl;
        }
    }
}

//Overloaded i/o stream operators***********************************************

istream& operator>>(istream& is, Roster& rhs)
{
    ++rhs.size;
    cout << endl;
    cout << "Enter the following course info." << endl
    << "\tCourse name: ";
    is >> rhs.courseName;
    cout << "\tCourse code: ";
    is >> rhs.courseCode;
    cout << "\tCourse credits: ";
    is >> rhs.credits;
    cout << "\tInstructor name: " << endl;
    cout << "\t\tFirst name: ";
    is >> rhs.firstName;
    cout << "\t\tLast Name: ";
    is >> rhs.lastName;
    cout << endl;
    
    return is;
}

ostream& operator<<(ostream& os, const Roster& rhs)
{
    os << "Course name: " << rhs.courseName << endl;
    os << "Course code: " << rhs.courseCode << endl;
    os << "Course credits: " << rhs.credits << endl;
    os << "Course instructor: " << rhs.firstName << " " << rhs.lastName << endl << endl;
    return os;
}

//Overloaded Operator **********************************************************

Student* Roster::operator[](const int index)
{
    return students[index];
}

//Saves student list under assigned roster back into roster.txt

void Roster::saveStudentList(ostream &out)
{
    sort();
    for (int i = 0; i < capacity; i++)
    {
        if (students[i] != NULL)
        {
            out << students[i]->getFirstName() << '|'
            << students[i]->getLastName() << '|'
            << students[i]->getID() << '|'
            << students[i]->getStanding() << '|'
            << students[i]->getCredits() << '|'
            << students[i]->getGPA() << '|'
            << students[i]->getDoB() << '|'
            << students[i]->getMatDate() << endl;
        }
    }
}





