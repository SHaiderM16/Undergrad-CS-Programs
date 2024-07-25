#include <iostream>
#include <vector>

using namespace std;

class User
{
protected:
    int userID;
    string password;

public:
    User(int uid, string pw) : userID(uid), password(pw) {}

    virtual void login() = 0;
    virtual void logout() = 0;
};

class Course
{
private:
    string courseCode;
    string courseDescription;
    string section;

public:
    Course(string code, string desc, string sec) : courseCode(code), courseDescription(desc), section(sec) {}

    string getCourseCode()
    {
        return courseCode;
    }
};

class Student : public User
{
private:
    vector<Course> enrolledCourses;

public:
    Student(int uid, string pw) : User(uid, pw) {}

    void login() override
    {
        int enteredID;
        string enteredPassword;

        cout << "Welcome Student" << endl;
        cout << "Enter ID: ";
        cin >> enteredID;
        cin.ignore();

        cout << "Enter password: ";
        getline(cin, enteredPassword);

        if (enteredID == userID && enteredPassword == password)
        {
            cout << "Login successful" << endl;
        }
        else
        {
            cout << "Login failed! Incorrect ID or password" << endl;
        }
    }

    void logout() override
    {
        cout << "Successfully logged out" << endl;
    }

    void addCourse(Course &course)
    {
        enrolledCourses.push_back(course);
    }

    vector<Course> getEnrolledCourses()
    {
        return enrolledCourses;
    }
};

class Advisor : public User
{
public:
    Advisor(int uid, string pw) : User(uid, pw) {}

    void login() override
    {
        int enteredID;
        string enteredPassword;

        cout << "Welcome Advisor" << endl;
        cout << "Enter ID: ";
        cin >> enteredID;
        cin.ignore();

        cout << "Enter password: ";
        getline(cin, enteredPassword);

        if (enteredID == userID && enteredPassword == password)
        {
            cout << "Login successful" << endl;
        }
        else
        {
            cout << "Login failed! Incorrect ID or password" << endl;
        }
    }

    void logout() override
    {
        cout << "Successfully logged out" << endl;
    }

    bool checkPrerequisites(string academicRecord)
    {
        string criteria = "";

        if (academicRecord == criteria)
        {
            return true;
        }

        return false;
    }

    bool approveCourse(Course &course, Student &student, string academicRecord)
    {
        if (checkPrerequisites(academicRecord))
        {
            student.addCourse(course);
            cout << "Course " << course.getCourseCode() << " has been approved and added" << endl;

            return true;
        }
        else
        {
            cout << "Course " << course.getCourseCode() << " has not been approved" << endl;

            return false;
        }
    }
};

class Registrar : public User
{
private:
    vector<Student> studentList;

public:
    Registrar(int uid, string pw) : User(uid, pw) {}

    void login() override
    {
        int enteredID;
        string enteredPassword;

        cout << "Welcome Registrar" << endl;
        cout << "Enter ID: ";
        cin >> enteredID;
        cin.ignore();

        cout << "Enter password: ";
        getline(cin, enteredPassword);

        if (enteredID == userID && enteredPassword == password)
        {
            cout << "Login successful" << endl;
        }
        else
        {
            cout << "Login failed! Incorrect ID or password" << endl;
        }
    }

    void logout() override
    {
        cout << "Successfully logged out" << endl;
    }

    void generateBillReport(vector<Course> &courses)
    {
        cout << "Bill Report for Approved Courses:" << endl;
        for (int i = 0; i < courses.size(); i++)
        {
            cout << "Course Code: " << courses[0].getCourseCode() << ", Cost: PKR" << 500 << endl;
        }

        cout << "Total Bill: PKR" << courses.size() * 500 << endl;
    }

    void addClass(Course &course)
    {
        cout << "Class of course " << course.getCourseCode() << " added" << endl;
    }

    void cancelClass(Course &course)
    {
        cout << "Class of course " << course.getCourseCode() << " cancelled" << endl;
    }

    void checkConflict(Course &course)
    {
        cout << "Conflict checked for class of course" << course.getCourseCode() << endl;
    }

    void addStudent(Student &student)
    {
        studentList.push_back(student);
        cout << "Student added" << endl;
    }
};

class Faculty : public User
{
public:
    Faculty(int uid, string pw) : User(uid, pw) {}

    void login() override
    {
        int enteredID;
        string enteredPassword;

        cout << "Welcome Faculty" << endl;
        cout << "Enter ID: ";
        cin >> enteredID;
        cin.ignore();

        cout << "Enter password: ";
        getline(cin, enteredPassword);

        if (enteredID == userID && enteredPassword == password)
        {
            cout << "Login successful" << endl;
        }
        else
        {
            cout << "Login failed! Incorrect ID or password" << endl;
        }
    }

    void logout() override
    {
        cout << "Successfully logged out" << endl;
    }

    void checkStudentEnrolment(Student &student, Course &course)
    {
        vector<Course> courses = student.getEnrolledCourses();

        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i].getCourseCode() == course.getCourseCode())
            {
                cout << "Student is enrolled" << endl;
                return;
            }
        }

        cout << "Student is not enrolled" << endl;
    }

    void getClassList(Course &course)
    {
        cout << "Class list for course " << course.getCourseCode() << " has been retrieved" << endl;
    }

    void checkStudentTranscript(Student &student)
    {
        cout << "Checked transcript for student" << endl;
    }

    void getStudentNumber(Student &student)
    {
        cout << "Retrieved phone number for student" << endl;
    }
};

int main()
{
    Student student(666, "Haider");
    Advisor advisor(667, "AdvisorPassword");
    Registrar registrar(668, "RegistrarPassword");
    Faculty faculty(669, "FacultyPassword");

    student.login();
    cout << endl;

    Course course("CL1004", "Object Oriented Programming - Lab", "D");
    if (advisor.approveCourse(course, student, ""))
    {
        student.addCourse(course);
    }
    student.logout();

    cout << endl;
    registrar.login();
    cout << endl;

    Student newStudent(102, "newStudentPassword");
    registrar.addStudent(newStudent);

    vector<Course> coursesForBilling;
    coursesForBilling.push_back(course);
    registrar.generateBillReport(coursesForBilling);
    registrar.logout();

    cout << endl;
    faculty.login();
    cout << endl;

    faculty.getClassList(course);
    faculty.checkStudentTranscript(student);
    faculty.logout();

    return 0;
}