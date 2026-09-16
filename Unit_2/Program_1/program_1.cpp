#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    int id;
    string empName;
    string dept;

public:
    Employee(int i, string n, string d)
    {
        id = i;
        empName = n;
        dept = d;
    }

    void showInfo() const
    {
        cout << "ID: " << id
             << " | Name: " << empName
             << " | Department: " << dept;
    }

    virtual double calculateSalary() const = 0;
};

class FullTimeEmployee : public Employee
{
    double monthlySalary;

public:
    FullTimeEmployee(int i, string n, string d, double salary)
        : Employee(i, n, d)
    {
        monthlySalary = salary;
    }

    double calculateSalary() const override
    {
        return monthlySalary;
    }

    void display() const
    {
        showInfo();
        cout << " | Type: Full-Time"
             << " | Salary: Rs. " << calculateSalary() << endl;
    }
};

class PartTimeEmployee : public Employee
{
    double ratePerHour;
    int totalHours;

public:
    PartTimeEmployee(int i, string n, string d, double rate, int hours)
        : Employee(i, n, d)
    {
        ratePerHour = rate;
        totalHours = hours;
    }

    double calculateSalary() const override
    {
        return ratePerHour * totalHours;
    }

    void display() const
    {
        showInfo();
        cout << " | Type: Part-Time"
             << " | Salary: Rs. " << calculateSalary() << endl;
    }
};

class Intern : public Employee
{
    double monthlyStipend;

public:
    Intern(int i, string n, string d, double stipend)
        : Employee(i, n, d)
    {
        monthlyStipend = stipend;
    }

    double calculateSalary() const override
    {
        return monthlyStipend;
    }

    void display() const
    {
        showInfo();
        cout << " | Type: Intern"
             << " | Stipend: Rs. " << calculateSalary() << endl;
    }
};

int main()
{
    FullTimeEmployee emp1(201, "Rahul", "Development", 60000);
    PartTimeEmployee emp2(202, "Priya", "Finance", 300, 100);
    Intern emp3(203, "Karan", "Testing", 12000);

    cout << "===== Employee Salary Details =====" << endl;

    emp1.display();
    emp2.display();
    emp3.display();

    return 0;
}

