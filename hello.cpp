#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
protected:
    string name;
    string address;
    string phone_no;

public:
    void get_details() {
        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Address: ";
        getline(cin, address);

        cout << "Enter Phone Number: ";
        getline(cin, phone_no);
    }
};

class Employee : public Person {
protected:
    int eno;
    string ename;

public:
    void get_details() {
        Person::get_details();
        cout << "Enter Employee Number: ";
        cin >> eno;

        cin.ignore(); // Ignore newline left by previous input
        cout << "Enter Employee Name: ";
        getline(cin, ename);
    }
};

class Manager : public Employee {
private:
    string designation;
    string department_name;
    int basic_salary;

public:
    void get_details() {
        Employee::get_details();

        cout << "Enter Designation: ";
        getline(cin, designation);

        cout << "Enter Department Name: ";
        getline(cin, department_name);

        cout << "Enter Basic Salary: ";
        cin >> basic_salary;
    }

    int get_salary() {
        // Return the total salary of the Manager
        return basic_salary;
    }

    void display_details() {
        // Display all details of the Manager
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phone_no << endl;
        cout << "Employee Number: " << eno << endl;
        cout << "Employee Name: " << ename << endl;
        cout << "Designation: " << designation << endl;
        cout << "Department Name: " << department_name << endl;
        cout << "Basic Salary: " << basic_salary << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of Managers: ";
    cin >> n;

    vector<Manager> managers(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter Details of Manager " << i+1 << ":" << endl;
        managers[i].get_details();
    }

    int max_salary = 0;
    Manager* highest_paid_manager;

    for (auto& manager : managers) {
        if (manager.get_salary() > max_salary) {
            max_salary = manager.get_salary();
            highest_paid_manager = &manager;
        }
    }

    cout << "\nDetails of Manager with Highest Salary:" << endl;
    highest_paid_manager->display_details();

    return 0;
}
