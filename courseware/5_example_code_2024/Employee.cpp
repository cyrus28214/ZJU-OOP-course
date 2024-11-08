#include <string>
#include <vector>
#include <iostream>

class HealthPlan {
public:
    // ... details of the health plan ...
};

class SalaryHistory {
public:
    // ... details of the salary history, such as dates and amounts ...
};

class Employee {
private:
    std::string name;
    std::string address;
    HealthPlan healthPlan;
    std::vector<SalaryHistory> salaryHistories;
    Employee* supervisor;  // Pointer to the supervisor. Can be nullptr if no supervisor.

public:
    // Constructor
    Employee(const std::string& name, const std::string& address)
        : name(name), address(address), supervisor(nullptr) {}

    // Setters and Getters
    void setName(const std::string& n) { name = n; }
    std::string getName() const { return name; }

    void setAddress(const std::string& addr) { address = addr; }
    std::string getAddress() const { return address; }

    void setHealthPlan(const HealthPlan& plan) { healthPlan = plan; }
    HealthPlan getHealthPlan() const { return healthPlan; }

    void addSalaryHistory(const SalaryHistory& history) { salaryHistories.push_back(history); }
    std::vector<SalaryHistory> getSalaryHistories() const { return salaryHistories; }

    void setSupervisor(Employee* sup) { supervisor = sup; }
    Employee* getSupervisor() const { return supervisor; }
};

int main() {
    // Example usage
    Employee emp1("John Doe", "123 Main St");
    Employee emp2("Jane Smith", "456 Elm St");

    // Set Jane Smith as John Doe's supervisor
    emp1.setSupervisor(&emp2);

    // ... further operations ...
    std::cout << emp1.getName() <<
    "'s supervisor is " << emp1.getSupervisor()->getName() << std::endl;
}
