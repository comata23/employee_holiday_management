#include <iostream>
#include <stdlib.h>
#include<vector>
using namespace std;

//////////////////////////////// Date class /////////////////////////////////////

class Date{
    public:
        int day;
        int month;
        int year;

        void print_date(){
        cout << day << "." << month << "." << year;
        }

        Date(){
            day = 1;
            month = 1;
            year = 2021;
        }
        Date(int d, int m, int y){
            day = d;
            month = m;
            year = y;
        }

};

//////////////////////////////// Employee Class //////////////////////////////

class Employee{
    protected:
        string surname;
        string firstname;
        Date dateofbirth;
        int holdtaken;
        int legalholidays;
    public:
        Employee(){
            surname = "Fischer";
            firstname = "Sara";
            Date dob(1, 1, 1990);
            dateofbirth = dob;
            holdtaken = 0;
            legalholidays = 30;

        }
        Employee(string sn, string fn, Date dob){
            surname = sn;
            firstname = fn,
            dateofbirth = dob;
            holdtaken = 0;
            set_legalholidays(dob);
        }
        void print_employee(){
            cout << "First name: " << firstname << endl;
            cout << "Last name: " << surname << endl;
            cout << "date of birth: ";
            dateofbirth.print_date();
            cout << endl;
            cout << "holidays taken: " << holdtaken << " days." << endl;
            cout << "remaining holidays: " << legalholidays - holdtaken << endl;
        }
        void set_firstname(string fn){
            firstname = fn;
        }
        string get_firstname(){
            return firstname;
        }
        void set_surname(string fn){
            firstname = fn;
        }
        string get_surname(){
            return surname;
        }
        void update_holdtaken(int hd){
            holdtaken += hd;
        }
        int get_holdtaken(){
            return holdtaken;
        }
        void set_dateofbirth(Date dob){
            dateofbirth = dob;
        }
        Date get_dateofbirth(){
            return dateofbirth;
        }
        void set_legalholidays(Date dob){ //check the age of employee and set holiday based on his birthday
            if (dob.year <= 1971) //check he or she is 50 years old or greater
                legalholidays = 32;
            else
                legalholidays = 30;
        }
        int get_legalholidays(){
            return legalholidays;
        }
};

/////////////////////////////////////////////////////////////////////

///////////////////////// Hourly Employee class /////////////////////

class HourlyEmployee: public Employee{
private:
    float hourlywage;
    float hoursworked;
public:
    HourlyEmployee(){
        hourlywage = 0;
        hoursworked = 0;
    }

    HourlyEmployee(float hwage, float hwork){
        hourlywage = hwage;
        hoursworked = hwork;
    }

    HourlyEmployee(string sn, string fn, Date dob, float hwage, float hwork){
        hourlywage = hwage;
        hoursworked = hwork;
        surname = sn;
        firstname = fn;
        dateofbirth = dob;
        holdtaken = 0;
        set_legalholidays(dob);
    }
    void print_employee(){
        cout << "First name: " << firstname << endl;
        cout << "Last name: " << surname << endl;
        cout << "Date of birth: ";
        dateofbirth.print_date();
        cout << endl;
        cout << "Hourly wage: " << hourlywage << endl;
        cout << "Hours worked : " << hoursworked << endl;
        cout << "holidays taken: " << holdtaken << " days." << endl;
        cout << "remaining holidays: " << legalholidays - holdtaken << endl;
    }
    float get_hourlywage(){
        return hourlywage;
    }
    void set_hourlywage(float hwage){
        hourlywage = hwage;
    }
    float get_hoursworked(){
        return hoursworked;
    }
    void set_hoursworked(float hwork){
        hoursworked = hwork;
    }
};


//////////////////////// Salaried Employee class //////////////////

class SalariedEmployee: public Employee{
    private:
        float annualsalary;
    public:
        SalariedEmployee(){
            annualsalary = 200000;
        }
        SalariedEmployee(float salary){
            annualsalary = salary;
        }
        SalariedEmployee(string sn, string fn, Date dob, float salary){
            annualsalary = salary;
            surname = sn;
            firstname = fn;
            dateofbirth = dob;
            holdtaken = 0;
            set_legalholidays(dob);
        }
        void print_employee(){
            cout << "First name: " << firstname << endl;
            cout << "Last name: " << surname << endl;
            cout << "Date of birth: ";
            dateofbirth.print_date();
            cout << endl;
            cout << "annual salary is: " << annualsalary << endl;
            cout << "holidays taken: " << holdtaken << " days." << endl;
            cout << "remaining holidays: " << legalholidays - holdtaken << endl;
        }
};

///////////////////////////// Manager ////////////////////////////
class Manager: public Employee{
    private:
        float profitsharing;
    public:
        Manager(){
            profitsharing = 10;
        }
        Manager(float proshare){
            profitsharing = proshare;
        }
        Manager(string sn, string fn, Date dob, float proshare){
            surname = sn;
            firstname = fn;
            dateofbirth = dob;
            holdtaken = 0;
            set_legalholidays(dob);
        }
        void print_employee(){
            cout << "First name: " << firstname << endl;
            cout << "Last name: " << surname << endl;
            cout << "Date of birth: ";
            dateofbirth.print_date();
            cout << endl;
            cout << "profit sharing is: " << profitsharing << endl;
            cout << "holidays taken: " << holdtaken << " days." << endl;
            cout << "remaining holidays: " << legalholidays - holdtaken << endl;
        }
};

//void creating_employee(vector<Employee> &emp_list); //create a new employee
//void deleting_employee(); //delete an existing employee
//void insert_newholiday(vector<Employee> Employee); //update the holidays of an employee
//int search_employee(vector<Employee>, string, string); //search for an employee with his/her name and show data
//void list_all_employee(vector<Employee> &emp_list);
//void display_employee(vector <Employee> &emp_list);


int search_employee(vector<Employee> &emp_list, string fn, string sn){
    int count = emp_list.size();
    int index = 0;
	if(count == 0){
		cout<<"We do not have this Employee\n";
	}

	vector<Employee> :: iterator find_employee = emp_list.begin();
	vector<Employee> :: iterator it;
	for(it = emp_list.begin() ; it != emp_list.end() ; it++){
        index++;
		if((*it).get_firstname() == fn && (*it).get_surname() == sn){
			find_employee = it;
			break;
		}
	}
	if(find_employee != emp_list.end()){
        cout<<"Employee Found!!!\n" << endl;
        return (index-1);
	}
	else{
		cout<<"Employee NOT Found !!!!!\n";
		return -1;
	}
}


void creating_employee(vector<Employee> &emp_list){
    string fn, sn;
    int d, m, y;
    int type = 0;
    float ansalary, hourwg, hourwork, profitshare;
    cout << "Enter employee's first name: " << endl;
    cin >> fn;
    cout << "Enter employee's last name: " << endl;
    cin >> sn;
    cout << "Enter employee's birth date: (like 1 1 1990)" << endl;
    cin >> d;
    cin >> m;
    cin >> y;
    Date dob(d, m, y);

    cout << "Which group does this Employee belong?" << endl;
    cout << " 1. Hourly Employee \n 2. Salaried Employee \n 3. Manager \n 4. Other " <<endl;
    cin >> type;

    switch(type){
        case 1:
            {cout << "Please enter the hourly wage: " << endl;
            cin >> hourwg;
            cout << "Please enter the hours worked: " << endl;
            cin >> hourwork;
            HourlyEmployee emp (sn, fn, dob, hourwg, hourwork);
            emp_list.push_back(emp);
            break;}
        case 2:{
            cout << "Please enter the annual salary: " << endl;
            cin >> ansalary;
            SalariedEmployee emp(sn, fn, dob, ansalary);
            emp_list.push_back(emp);
            break;}
        case 3:{
            cout << "Please enter the profit sharing value: " << endl;
            cin >> profitshare;
            Manager emp(sn, fn, dob, profitshare);
            emp_list.push_back(emp);
            break;}
        case 4:{
            Employee emp (sn, fn, dob); // the constructor of Employee is called to create new Employee.
            emp_list.push_back(emp);
            break;}
    }


    //cout << "The new employee " << emp.get_firstname() << " " << emp.get_surname() << " is created. " << endl;
}

void deleting_employee(vector<Employee> &emp_list){
    int emp_list_size = emp_list.size();
    if (emp_list_size == 0){
        cout << "There is no employee in the database. please create a new employee first." << endl << endl;
    }
    else{
        string fn, sn;
        cout << "Enter employee's first name: " << endl;
        cin >> fn;
        cout << "Enter employee's last name: " << endl;
        cin >> sn;

        int index = search_employee(emp_list, fn, sn);

        if (index != -1) {
            emp_list.erase(emp_list.begin() + index);
            cout << "The employee was deleted. " << endl;
        }
    }
}


void list_all_employee(vector<Employee> &emp_list){

    int emp_list_size = emp_list.size();
    if (emp_list.empty())
        cout << "There is no employee in the database. please create a new employee first." << endl;
    else{
        for (int i = 0; i < emp_list_size ; i++){
            cout << "-----------" << endl << i + 1 << "." << endl;
            emp_list[i].print_employee();
            cout << "-----------" << endl;
        }
    }
}

void insert_newholiday(vector<Employee> &emp_list){
    string fn, sn, ans;
    int index = -1;
    int num_holdays;
    bool key = true;

	cout << "Enter the first name of employee: " << endl;
	cin >> fn;
	cout << "Enter the surname of employee: " << endl;
	cin >> sn;
	index = search_employee(emp_list, fn, sn);// find the employee

	if (index!= -1){ // check the employee exist
        while(key){
            cout << "legal holidays: " << emp_list[index].get_legalholidays() << endl;
            cout << "How many days she/ he wants to take holiday?" << endl;
            cin >> num_holdays;
            //check whether the considered holidays is greater than legal holidays
            if (emp_list[index].get_holdtaken() + num_holdays > emp_list[index].get_legalholidays())
                    cout << "Sorry, she/he reached the maximum taken holiday." << endl;
            else{
                emp_list[index].update_holdtaken(num_holdays); //update taken holiday

                cout << "The taken holidays updated. " << endl;
                cout << "Number of her/ his taken holidays: " << emp_list[index].get_holdtaken() << endl;
            }
            cout << "Does she/he want to take another date? (Enter y/n)";
            cin >> ans;
            if (ans == "n")
                key = false;
        }
	}
}

void display_employee(vector <Employee> &emp_list){
    string fn, sn;
    cout << "Enter first name of Employee: " << endl;
    cin >> fn;
    cout << "Enter last name of Employee: " << endl;
    cin >> sn;
    int index = search_employee(emp_list, fn, sn);
    if (index != -1){ // the employee exist.
        emp_list[index].print_employee();
    }
}

int first_page(){

    int service = 0;
    cout << "**** Welcome to Holiday Taken Management ****" << endl;
    cout << endl << endl;
    cout << "Please enter one service: " << endl << endl;
    cout << " 1. create an employee \n 2. Delete an employee \n 3. Display an employee \n";
    cout << " 4. Submit taking holiday for an employee. \n 5. list of all employees. " << endl;
    cout << " 0. Exit" <<endl;
    cout << endl << endl;
    cin >> service;

    return service;
}
int main()
{
    int service;
    //int service = first_page();
    int max = 500;
    vector<Employee> emp_list;
    while(service !=0 ){
        service = first_page();
        if (service == 1){
            creating_employee(emp_list);
        }
        else if (service == 2)
            deleting_employee(emp_list);
        else if ( service == 3)
            display_employee(emp_list);
        else if ( service == 4)
            insert_newholiday(emp_list);
        else if ( service == 5)
            list_all_employee(emp_list);
        else
            cout << "choose one of the above numbers" << endl;
    }

    return 0;
}
