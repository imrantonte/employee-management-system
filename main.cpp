#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Employee {
    int id;
    string name;
    int age;
    string position;
    double salary;
};

void addEmployee();
void displayAllEmployees();
void displayEmployeeById();
void modifyEmployee();
void deleteEmployee();
void saveToFile(Employee* employees, int count);
void loadFromFile(Employee*& employees, int& count);

int main() {
    int choice;
    while (true) {
        cout << "Employee Management System\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Display Employee By ID\n";
        cout << "4. Modify Employee\n";
        cout << "5. Delete Employee\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                displayEmployeeById();
                break;
            case 4:
                modifyEmployee();
                break;
            case 5:
                deleteEmployee();
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

void addEmployee() {
    Employee* employees = NULL;
    int count = 0;
    loadFromFile(employees, count);

    Employee emp;
    cout << "Enter Employee ID: ";
    cin >> emp.id;
    cout << "Enter Employee Name: ";
    cin.ignore();
    getline(cin, emp.name);
    cout << "Enter Employee Age: ";
    cin >> emp.age;
    cout << "Enter Employee Position: ";
    cin.ignore();
    getline(cin, emp.position);
    cout << "Enter Employee Salary: ";
    cin >> emp.salary;

    Employee* newEmployees = new Employee[count + 1];
    for (int i = 0; i < count; ++i) {
        newEmployees[i] = employees[i];
    }
    newEmployees[count] = emp;
    delete[] employees;

    saveToFile(newEmployees, count + 1);
    delete[] newEmployees;

    cout << "Employee added successfully.\n";
}

void displayAllEmployees() {
    Employee* employees = NULL;
    int count = 0;
    loadFromFile(employees, count);

    if (count == 0) {
        cout << "No employees added.\n";
        return;
    }

    for (int i = 0; i < count; ++i) {
        cout << "ID: " << employees[i].id << "\n";
        cout << "Name: " << employees[i].name << "\n";
        cout << "Age: " << employees[i].age << "\n";
        cout << "Position: " << employees[i].position << "\n";
        cout << "Salary: " << employees[i].salary << "\n";
        cout << "-----------------------------\n";
    }
    delete[] employees;
}