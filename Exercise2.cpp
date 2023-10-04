#include<iostream>
#include<string.h>
using namespace std;
class Person{
    private:
        string name;
        string address;
    public:
        Person(string name, string address)
        {
            this->name = name;
            this->address = address;
        }
        Person() = default;
        string getName() const { return this->name; }
        string getAddress() const { return this->address; }
        void setAddress(string address) { this->address = address; }
        string toString() const{
            return "Person[name=" + this->name + ", address=" + this->address;
        }
};
class Student:public Person{
    private:
        string program;
        int year;
        double fee;
    public:
        Student(string name, string address, string program, int year, double fee):Person(name, address){
            this->program = program;
            this->year = year;
            this->fee = fee;
        }
        ~Student(){}
        string getProgram() const { return this->program; }
        void setProgram(string program) { this->program = program;}
        int getYear() const {return this->year;}
        void setYear(int year){this->year = year;}
        double getFee() const {return this->fee;}
        void setFee(double fee){this->fee = fee;}
        string toString() const{
            string dname = this->getName();
            string daddress = this->getAddress();
            int dyear = this->getYear();
            double dfee = this->getFee();
            string sfee = to_string(dfee);
            string syear = to_string(dyear);
            return "Student[" + Person::toString() + ",program=" + this->program + ",year=" + syear + "," + "fee=" + sfee + "]";
        }
};
class Staff:public Person{
    private:
        string school;
        double pay;
    public:
        Staff(string name, string address,string school, double pay):Person(name, address){
            this->school = school;
            this->pay = pay;
        }
        string getSchool() const { return this->school; }
        void setSchool(string school) { this->school = school; }
        double getPay() const { return this->pay; }
        void setPay(double pay) {this->pay = pay;}
        string toString(){
            string spay = to_string(this->pay);
            return "Staff[" + Person::toString() + ",school=" + this->school + ", pay=" + spay + "]";
        }
};
int main()
{
    Student arr[5] = {
        Student("Mark", "123 45 St", "Computer Science", 2020, 5000.0),
        Student("Bobby", "456 60 St", "Logistic", 2017, 3400.0),
        Student("Luke", "789 55 St", "Chemistry Engineering", 2020, 4500.0),
        Student("Anakin", "101 34 St", "Biological Engineering", 2018, 4200.0),
        Student("Eva", "202 09 St", "Applied Science", 2022, 4900.0),
    };
    Staff staff("John", "333 Maple Ave", "High School", 60000.0);
    staff.setAddress("444 Elm Ave");

    for (int i = 0; i < 5; ++i) {
        arr[i].setYear(2023);
    }
    for (int i = 0; i < 5; ++i) {
        cout << "Student " << i + 1 << " Info: " << endl;
        cout << "Name: " << arr[i].getName() << endl;
        cout << "Address: " << arr[i].getAddress() << endl;
        cout << "Program: " << arr[i].getProgram() << endl;
        cout << "Year: " << arr[i].getYear() << endl;
        cout << "Fee: " << arr[i].getFee() << endl;
    }
    cout << "Staff Information: " << endl;
    cout << "Name: " << staff.getName() << endl;
    cout << "Address: " << staff.getAddress() << endl;
    cout << "School: " << staff.getSchool() << endl;
    cout << "Pay: $" << staff.getPay() << endl;
} 
