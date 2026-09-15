/*
 * Course: COEN 2220 - Programming 2
 * Name: Luis D. Cruz Medina
 * Lab: Lab 4 - Object-Oriented Programming, Part 2
 * Description: Guided example - static members, copies, and operators
 * Due date: [9/15/26]
 */

#include <iostream>
using namespace std;

class StudyTime
{
private:
    int minutes;
    static int objectCount;

public:
    StudyTime(int m = 0)
    {
        minutes = m;
        objectCount++;
    }

    int getMinutes() const
    {
        return minutes;
    }

    static int getObjectCount()
    {
        return objectCount;
    }

    // STEP 2 - Copy constructor
    
    StudyTime(const StudyTime &other)
    {
        minutes = other.minutes;
        objectCount++;
    }
    

    // STEP 3 - operator+
    
    StudyTime operator+(const StudyTime &other) const
    {
        return StudyTime(minutes + other.minutes);
    }

    bool operator==(const StudyTime &other) const
    {
        return minutes == other.minutes;
    }
    
};

int StudyTime::objectCount = 0;

int main()
{
    StudyTime reading(45);

    cout << "Reading: " << reading.getMinutes() << " minutes" << endl;
    cout << "Objects created: " << StudyTime::getObjectCount() << endl;

    // STEP 2 main code goes here later
    StudyTime readingCopy = reading;

    cout << "Copy: " << readingCopy.getMinutes() << " minutes" << endl;
    cout << "Objects created: " << StudyTime::getObjectCount() << endl;

    // STEP 3 main code goes here later
    StudyTime practice(30);
    StudyTime total = reading + practice;

    cout << "Total: " << total.getMinutes() << " minutes" << endl;
    cout << "Objects created: " << StudyTime::getObjectCount() << endl;

    StudyTime anotherCopy = reading;
    StudyTime assigned;

    assigned = reading;

    cout << "Another copy: " << anotherCopy.getMinutes() << " minutes" << endl;
    cout << "Assigned: " << assigned.getMinutes() << " minutes" << endl;
    cout << "Final objects created: " << StudyTime::getObjectCount() << endl;

    StudyTime time1(60);
    StudyTime time2(60);
    StudyTime time3(30);

    cout << boolalpha;
    cout << "time1 == time2: " << (time1 == time2) << endl;
    cout << "time1 == time3: " << (time1 == time3) << endl;
    return 0;
}