/*
 Name: Bernice Tran
 Class: CSCI 211-32A
 Cpp file for student class.
 */

#include "student.h"

//Accessors (getters)***********************************************************

string Student::getFirstName() const
{
    return firstName;
}
string Student::getLastName() const
{
    return lastName;
}
string Student::getName() const
{
    return firstName + " " + lastName;
}
string Student::getStanding() const
{
    return standing;
}
Date Student::getDoB() const
{
    return birthday;
}
Date Student::getMatDate() const
{
    return matriculationDate;
}
double Student::getCredits() const
{
    return credits ;
}
double Student::getGPA() const
{
    return gpa;
}
int Student::getID() const
{
    return ID;
}

//Mutators (setters)************************************************************

void Student::setLastName(string last)
{
    lastName = last;
}
void Student::setFirstName(string first)
{
    firstName = first;
}

void Student::setStanding(double credits)
{
    if(credits >= 0 && credits <= 15)
        standing = "Freshman";
    if(credits >= 16 && credits <= 30)
        standing = "Upper Freshman";
    if(credits >= 31 && credits <= 45)
        standing = "Sophomore";
    if(credits >= 46 && credits <= 60)
        standing = "Upper Sophomore";
    if(credits >= 61 && credits <= 75)
        standing = "Junior";
    if(credits >= 76 && credits <= 90)
        standing = "Upper Junior";
    if(credits >= 91 && credits <= 105)
        standing = "Senior";
    if(credits >= 105)
        standing = "Upper Senior";
}

void Student::setDoB(Date bday)
{
    birthday = bday;
}
void Student::setMatDate(Date mday)
{
    matriculationDate = mday;
}
void Student::setCredits(double creds)
{
    credits = creds;
}
void Student::setGPA(double gpas)
{
    gpa = gpas;
}
void Student::setID(int id)
{
    ID = id;
}

//Equality Operators************************************************************

bool Student::operator==(const Student& rhs)
{
    if (lastName==rhs.lastName &&
        firstName==rhs.firstName &&
        ID==rhs.ID)
    {
        return true;
    }
    return false;
}

bool Student::operator!=(const Student& rhs)
{
    return !(*this==rhs);
}

bool Student::operator<(const Student& rhs)
{
    if (this->getLastName()<rhs.getLastName())
    {
        return true;
    }
    else if (this->getLastName()==rhs.getLastName() &&
             this->getFirstName()<rhs.getFirstName())
    {
        return true;
    }
    else if (this->getLastName()==rhs.getLastName() &&
             this->getFirstName()==rhs.getFirstName() &&
             this->getID()<rhs.getID())
    {
        return true;
    }
    return false;
}

bool Student::operator>(const Student& rhs)
{
    if (this->getLastName()>rhs.getLastName())
    {
        return true;
    }
    else if (this->getLastName()==rhs.getLastName() &&
             this->getFirstName()>rhs.getFirstName())
    {
        return true;
    }
    else if (this->getLastName()==rhs.getLastName() &&
             this->getFirstName()==rhs.getFirstName() &&
             this->getID()>rhs.getID())
    {
        return true;
    }
    return false;
}

bool Student::operator<=(const Student& rhs)
{
    if (this->getLastName()<=rhs.getLastName())
    {
        return true;
    }
    else if (this->getLastName()==rhs.getLastName() &&
             this->getFirstName()<=rhs.getFirstName())
    {
        return true;
    }
    else if (this->getLastName()==rhs.getLastName() &&
             this->getFirstName()==rhs.getFirstName() &&
             this->getID()<=rhs.getID())
    {
        return true;
    }
    return false;
}

bool Student::operator>=(const Student& rhs)
{
    if (this->getLastName()>=rhs.getLastName())
    {
        return true;
    }
    else if (this->getLastName()==rhs.getLastName() &&
             this->getFirstName()>=rhs.getFirstName())
    {
        return true;
    }
    else if (this->getLastName()==rhs.getLastName() &&
             this->getFirstName()==rhs.getFirstName() &&
             this->getID()>=rhs.getID())
    {
        return true;
    }
    return false;
}

//Overloaded i/o stream operators***********************************************

istream& operator>>(istream& is, Student& rhs)
{
    cout << endl << "Enter first name: ";
    is >> rhs.firstName;
    cout << "Enter last name: ";
    is >> rhs.lastName;
    cout << "Enter student ID: ";
    is >> rhs.ID;
    cout << "Enter number of credits: ";
    is >> rhs.credits;
    cout << "Enter GPA: ";
    is >> rhs.gpa;
    cout << "Enter date of birth: " << endl;
    is >> rhs.birthday;
    cout << "Enter matriculation date: " << endl;
    is >> rhs.matriculationDate;
     
    rhs.setStanding(rhs.credits);
    
    return is;
}

ostream& operator<<(ostream& os, const Student& rhs)
{
    os << rhs.lastName << ", " << rhs.firstName << endl
    << "\tID: " << rhs.ID << endl
    << "\tStanding: " << rhs.standing << endl
    << "\tCredits: " << rhs.credits << endl
    << "\tGPA: " << rhs.getGPA() << endl
    << "\tBirthday: " << rhs.birthday << endl
    << "\tMatriculation Date: " << rhs.matriculationDate << endl;
    
    return os;
}



