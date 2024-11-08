#include <iostream>
using namespace std;

class Employee {
public:
	Employee(const std::string& name,
		const std::string& ssn);
	const std::string& get_name() const;
	void print(std::ostream& out) const;
	void print(std::ostream& out, const std::string& msg) const;

protected:
	std::string m_name;
	std::string m_ssn;
private:
	int i;
};


Employee::Employee(const string& name,
	const string& ssn)
	: m_name(name), m_ssn(ssn)
{
	// initializer list sets up the values!
}

inline const std::string& Employee::get_name() const
{
	return m_name;
}
inline void Employee::print(std::ostream& out) const
{
	out << "E:" <<endl;
	out << m_name << endl;
	out << m_ssn << endl;
}
inline void Employee::print(std::ostream& out,
	const std::string& msg) const
{
	out << msg << endl;
	print(out);
}



class Manager : public Employee {
public:
	Manager(const std::string& name,
		const std::string& ssn,
		const std::string& title);
	const std::string title_name() const;
	const std::string& get_title() const;
	void print(std::ostream& out) const;
private:
	std::string m_title;
};

Manager::Manager(const string& name, const string&
	ssn, const string& title = "")
	:Employee(name, ssn), m_title(title)
{
}

inline void Manager::print(std::ostream& out) const
{
	Employee::print(out); //call the base class print
	out << m_title << endl;
}

inline const std::string& Manager::get_title() const
{
	return m_title;
}

inline const std::string Manager::title_name() const
{
	return string(m_title + ": " + m_name);
	// access base m_name
}

int main()
{
	Employee bob("Bob Jones", "555-44-0000");
	Manager bill("Bill Smith", "666-55-1234", "ImportantPerson");

	string name = bill.get_name(); // okay Manager 	inherits Employee
	//string title = bob.get_title(); // Error -- bob is an Employee!
	cout << bill.title_name() << '\n' << endl;
	bob.print(cout);
	bob.print(cout, "Employee:");
	bill.print(cout);
	//bill.print(cout, "Employee:"); // Error hidden!

	Employee* ep = &bill;
	ep->print(cout, "Employee:");
	
}



















