#include <iostream>
#include <string>
#include <vector>

// HealthPlan class definition
class HealthPlan {
public:
    std::string planName;     // Name of the health plan
    double monthlyPremium;    // Monthly premium cost

    // Constructor with default values, so it is permited for "HealthPlan plan;"
    //even without the default constructor HealthPlan(){}
    HealthPlan(const std::string& name = "Basic Plan", double premium = 100.0)
        : planName(name), monthlyPremium(premium) {}

    // Display health plan information
    void display() const {
        std::cout << "Health Plan: " << planName 
                  << ", Monthly Premium: $" << monthlyPremium << std::endl;
    }
};

// SalaryHistory class definition
class SalaryHistory {
public:
    int year;      // Year of the salary record
    double salary; // Salary amount for the specific year

    // Constructor to initialize the year and salary
    SalaryHistory(int y, double s) : year(y), salary(s) {}

    // Display salary history
    void display() const {
        std::cout << "Year: " << year << ", Salary: $" << salary << std::endl;
    }
};

// Employee class definition
class Employee {
private:
    std::string name;                          // Employee's name
    std::string address;                       // Employee's address
    HealthPlan healthPlan;                     // Employee's health plan
    std::vector<SalaryHistory> salaryHistories; // List of salary histories
    Employee* supervisor;                      // Pointer to the supervisor

public:
    // Constructor to initialize employee information
    Employee(const std::string& empName, const std::string& empAddress,
             const HealthPlan& plan = HealthPlan(), Employee* sup = nullptr)
        : name(empName), address(empAddress), healthPlan(plan), supervisor(sup) {}

    // Add a salary history record
    void addSalaryHistory(int year, double salary) {
        salaryHistories.emplace_back(year, salary);
    }

    // Display employee information
    void display() const {
        std::cout << "Employee Name: " << name << "\n"
                  << "Address: " << address << "\n";
        healthPlan.display();
        
        std::cout << "Salary Histories:\n";
        for (const auto& history : salaryHistories) {
            history.display();
        }

        // Check if the employee has a supervisor
        if (supervisor) {
            std::cout << "Supervisor: " << supervisor->name << std::endl;
        } else {
            std::cout << "No Supervisor" << std::endl;
        }
    }
};

// Main function
int main() {
    // Create a health plan and a supervisor
    HealthPlan plan("Premium Plan", 200.0);
    Employee supervisor("John Doe", "123 Main St", plan);
    
    // Create an employee with the supervisor
    Employee emp("Alice Smith", "456 Elm St", plan, &supervisor);

    // Add salary history records for the employee
    emp.addSalaryHistory(2021, 50000.0);
    emp.addSalaryHistory(2022, 55000.0);

    // Display employee information
    emp.display();

    return 0;
}
