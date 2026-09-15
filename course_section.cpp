/*
 * Course: COEN 2220 - Programming 2
 * Name: Luis D. Cruz Medina
 * Lab: Lab 4 - Object-Oriented Programming, Part 2
 * Description: Aggregation practice with CourseSection
 * Due date: [9/15/26]
 */

#include <iostream>
#include <string>
using namespace std;

class Instructor
{
private:
    string name;

public:
    Instructor()
    {
        name = "";
    }

    void setName(string n)
    {
        name = n;
    }

    string getName() const
    {
        return name;
    }
};

class TextBook
{
private:
    string title;

public:
    TextBook()
    {
        title = "";
    }

    void setTitle(string t)
    {
        title = t;
    }

    string getTitle() const
    {
        return title;
    }
};

class CourseSection
{
private:
    string sectionId;
    Instructor instructor;
    TextBook textbook;

public:
    CourseSection(string id, string instructorName, string bookTitle)
    {
        sectionId = id;
        instructor.setName(instructorName);
        textbook.setTitle(bookTitle);
    }

    void printInfo() const
    {
        cout << "Section: " << sectionId << endl;
        cout << "Instructor: " << instructor.getName() << endl;
        cout << "Textbook: " << textbook.getTitle() << endl;
    }
};

int main()
{
    CourseSection section("COEN 2220-01", "Alex Rivera", "C++ Programming");

    section.printInfo();

    return 0;
}