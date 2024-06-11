#include <iostream>
#include <string>
#include <vector>

// Following along Caleb Curry from YouTube (C++ Object Oriented Programming Crash Course - Introductions + Full Tutorial)

// Basic Vocabulary for object oriented programming
//-----------------------------------------------------------------------
// class - describes the structure
// object - a specific example of that structure (instance)
// instance - another name for object
// instantiating - creating an object from a class
// data members - variables
// methods - functions
// parent class (base class) - inherited FROM
// child class (derived class) - does the inheriting

// abstraction -- a concept where you make something easy by hiding the complicated stuff
// encapsilation -- granting access to privata data only through controlled public interfaces
// inheritance -- creating derived classes that inherit properties from their parent classes
// polymorphism -- treating multiple different objects as their base object type


//-----------------------------------------------------------------------



class Person {
    protected:
        std::string first;
        std::string last;

    public:
    Person(std::string first, std::string last): first(first), last(last) {} // Konstruktor     (more common syntax)
    Person() = default;     // allows to create a person object without putting data inside 
    void setFirstName(std::string first) { this->first = first; }           // seter (set-method)
    void setLastName(std::string last) { this->last = last; }

    std::string getName() {return first + " " + last;}                      // geter (get-method)

    void printFullName(){std::cout << first << " " << last << std::endl;}

    virtual void printInfo() {                                  // virtual and override combine together to use the appropriate function
        std::cout << "First name: " << first << std::endl;
        std::cout << "Last name: " << last << std::endl;
    }

};

class Employee : public Person{
    std::string department;
    public:
        Employee(std::string firstName, std::string lastName, std::string department)
                 : Person(firstName, lastName), department(department){}
        std::string getDepartment(){
            return department;
        }
        void setDepartment(std::string department){
            this->department = department;
        }
        void printInfo() override {
            std::cout << "First name: " << first << std::endl;      // protected instead of private allows usage of object classes in other classes
            std::cout << "Last name: " << last << std::endl;
            std::cout << "Department: " << department << std::endl;
        }
};


int main() {
    std::vector<Person*> people;
    Employee e("Stefan", "Kramperger", "Sales"); 
    Person p("Someone", "Else");

    people.push_back(&p);
    people.push_back(&e);

    for(auto person: people) {
        person->printInfo();
    }

    return 0;
}





/*
--------------------------------------------------
Version 1: Basic Class Object usage

class Person{
    public: 
    std::string first;
    std::string last;

    void printFullName(){
        std::cout << first << " " << last << std::endl;
    }
}

int main() {
    Person p;
    p.first = "Stefan";
    p.last = "Kramperger";

    p.printFullName();
}

--------------------------------------------------
Version 2: Encapsulation and set/get methods

class Person{
    private:
        std::string first;
        std::string last;

    public: 

        void setFirstName(std::string first) { this->first = first; }       // set-method (mutator)
        void setLastName(std::string last) { this->last = last; }           // set-method
        std::string getName(){ return first + " " * last; }                 // get-method (returns the string and doesnt't output it like printFullName does)
        void printFullName(){ std::cout << first << " " << last << std::endl; }
}

int main() {
    Person p;
    p.setFirstName("Stefan");
    p.setLastName("Kramperger");

    p.printFullName();
    std::cout << p.getName() << std::endl;

    Person p2;
    p2.setFirstName("Simon");
    p2.setLastName("Says");
    p2.printFullName();

}

--------------------------------------------------
Version 3: Constructor

class Person {
    private:        // encapsulation
        std::string first;
        std::string last;


    public:
    Person(std::string first, std::string last): first(first), last(last) {} // Konstruktor     (more common syntax)
    Person() = default;     // allows to create a person object without putting data inside 
    void setFirstName(std::string first) { this->first = first; }           // seter (set-method)
    void setLastName(std::string last) { this->last = last; }

    std::string getName() {return first + " " + last;}                      // geter (get-method)

    void printFullName(){std::cout << first << " " << last << std::endl;}

};


int main() {
    Person p("Stefan", "Kramperger");
    p.printFullName(); 
    std::cout << p.getName() << std::endl;

    Person p2("Simon", "Says");
    p2.printFullName();

    Person p3; // allowed thanks to default

    return 0;
}

--------------------------------------------------
Version 4: Inheritance: parent and child class (derived from and to)

class Person {
    private:        // encapsulation
        std::string first;
        std::string last;


    public:
    Person(std::string first, std::string last): first(first), last(last) {} // Konstruktor     (more common syntax)
    Person() = default;     // allows to create a person object without putting data inside 
    void setFirstName(std::string first) { this->first = first; }           // seter (set-method)
    void setLastName(std::string last) { this->last = last; }

    std::string getName() {return first + " " + last;}                      // geter (get-method)

    void printFullName(){std::cout << first << " " << last << std::endl;}

};

class Employee : public Person{
    std::string department;
    public:
        Employee(std::string firstName, std::string lastName, std::string department)
                 : Person(firstName, lastName), department(department){}
        std::string getDepartment(){
            return department;
        }
        void setDepartment(std::string department){
            this->department = department;
        }
        void printInfo() {
            std::cout << "Name: " + getName() << std::endl;
            std::cout << "Department: " << department << std::endl;
        }
};


int main() {

    Employee e("Stefan", "Kramperger", "Sales"); 
    e.printInfo();

    return 0;
}


--------------------------------------------------
Version 5: Protected instead of private class sections

class Person {
    protected:                      // instead of the typical private allows variable usage outside of the class
        std::string first;
        std::string last;


    public:
    Person(std::string first, std::string last): first(first), last(last) {} // Konstruktor     (more common syntax)
    Person() = default;     // allows to create a person object without putting data inside 
    void setFirstName(std::string first) { this->first = first; }           // seter (set-method)
    void setLastName(std::string last) { this->last = last; }

    std::string getName() {return first + " " + last;}                      // geter (get-method)

    void printFullName(){std::cout << first << " " << last << std::endl;}

};

class Employee : public Person{
    std::string department;
    public:
        Employee(std::string firstName, std::string lastName, std::string department)
                 : Person(firstName, lastName), department(department){}
        std::string getDepartment(){
            return department;
        }
        void setDepartment(std::string department){
            this->department = department;
        }
        void printInfo() {
            std::cout << "First name: " << first << std::endl;      // protected instead of private allows usage of object classes in other classes
            std::cout << "Last name: " << last << std::endl;
            std::cout << "Department: " << department << std::endl;
        }
};


int main() {

    Employee e("Stefan", "Kramperger", "Sales"); 
    e.printInfo();

    return 0;
}


--------------------------------------------------
Version 6: override and virtual usage

class Person {
    protected:
        std::string first;
        std::string last;

    public:
    Person(std::string first, std::string last): first(first), last(last) {} // Konstruktor     (more common syntax)
    Person() = default;     // allows to create a person object without putting data inside 
    void setFirstName(std::string first) { this->first = first; }           // seter (set-method)
    void setLastName(std::string last) { this->last = last; }

    std::string getName() {return first + " " + last;}                      // geter (get-method)

    void printFullName(){std::cout << first << " " << last << std::endl;}

    virtual void printInfo() {                                  // virtual and override combine together to use the appropriate function
        std::cout << "First name: " << first << std::endl;
        std::cout << "Last name: " << last << std::endl;
    }

};

class Employee : public Person{
    std::string department;
    public:
        Employee(std::string firstName, std::string lastName, std::string department)
                 : Person(firstName, lastName), department(department){}
        std::string getDepartment(){
            return department;
        }
        void setDepartment(std::string department){
            this->department = department;
        }
        void printInfo() override {
            std::cout << "First name: " << first << std::endl;      // protected instead of private allows usage of object classes in other classes
            std::cout << "Last name: " << last << std::endl;
            std::cout << "Department: " << department << std::endl;
        }
};


int main() {

    Employee e("Stefan", "Kramperger", "Sales"); 
    e.printInfo();
    Person e2("Someone", "Else");
    e2.printInfo();

    return 0;
}

--------------------------------------------------
Version 7: Polymorphism

#include <vector> // needs to be added for vector usage

class Person {
    protected:
        std::string first;
        std::string last;

    public:
    Person(std::string first, std::string last): first(first), last(last) {} // Konstruktor     (more common syntax)
    Person() = default;     // allows to create a person object without putting data inside 
    void setFirstName(std::string first) { this->first = first; }           // seter (set-method)
    void setLastName(std::string last) { this->last = last; }

    std::string getName() {return first + " " + last;}                      // geter (get-method)

    void printFullName(){std::cout << first << " " << last << std::endl;}

    virtual void printInfo() {                                  // virtual and override combine together to use the appropriate function
        std::cout << "First name: " << first << std::endl;
        std::cout << "Last name: " << last << std::endl;
    }

};

class Employee : public Person{
    std::string department;
    public:
        Employee(std::string firstName, std::string lastName, std::string department)
                 : Person(firstName, lastName), department(department){}
        std::string getDepartment(){
            return department;
        }
        void setDepartment(std::string department){
            this->department = department;
        }
        void printInfo() override {
            std::cout << "First name: " << first << std::endl;      // protected instead of private allows usage of object classes in other classes
            std::cout << "Last name: " << last << std::endl;
            std::cout << "Department: " << department << std::endl;
        }
};


int main() {
    std::vector<Person*> people;
    Employee e("Stefan", "Kramperger", "Sales"); 
    Person p("Someone", "Else");

    people.push_back(&p);
    people.push_back(&e);

    for(auto person: people) {
        person->printInfo();
    }

    return 0;
}

--------------------------------------------------

*/
