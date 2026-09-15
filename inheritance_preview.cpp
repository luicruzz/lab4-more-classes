/*
 * Course: COEN 2220 - Programming 2
 * Name: Luis D. Cruz Medina
 * Lab: Lab 4 - Object-Oriented Programming, Part 2
 * Description: Preview of inheritance and runtime polymorphism
 * Due date: [9/15/26]
 */

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;

public:
    Person(string n)
    {
        name = n;
    }

    string getName() const
    {
        return name;
    }

    virtual void introduce() const
    {
        cout << "Person: " << name << endl;
    }
};

class Student : public Person
{
private:
    string major;

public:
    Student(string n, string m) : Person(n)
    {
        major = m;
    }

    void introduce() const override
    {
        cout << "Student: " << getName()
             << ", Major: " << major << endl;
    }
};

int main()
{
    Person visitor("Jordan Lee");
    Student student("Taylor Morgan", "Computer Engineering");

    Person *people[] = {&visitor, &student};

    for (int i = 0; i < 2; i++)
    {
        people[i]->introduce();
    }

    return 0;
}