#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Person {
public:
    Person(string name_, string prof_){
        name=name_;
        prof=prof_;
    }
    void Walk(string destination) {
        cout << prof<<": " << name << " walks to: " << destination << endl;
    }
    string name;
    string prof;
    virtual ~Person(){}
};

class Student:public Person {
public:

    Student(string Name, string favouriteSong):Person(Name, "Student") {
        FavouriteSong = favouriteSong;
    }

    void Learn() {
        cout << "Student: " << name << " learns" << endl;
    }

    void SingSong() {
        cout << "Student: " << name << " sings a song: " << FavouriteSong << endl;
    }
    ~Student(){}
public:
    string FavouriteSong;
};


class Teacher:public Person {
public:

    Teacher(string name, string subject):Person(name,"Teacher") {
        Subject = subject;
    }

    void Teach() {
        cout << "Teacher: " << name << " teaches: " << Subject << endl;
    }

    ~Teacher(){}
public:
    string Subject;
};

class Policeman :public Person{
public:
    Policeman(string name):Person(name,"Policeman") {}

    void Check(Person p) {
        cout << "Policeman: " << name << " checks "<<p.prof <<". "<<p.prof<<"'s name is: " << p.name << endl;
    }

    ~Policeman(){}
};

void VisitPlaces(Student s, vector<string> places) {
    for (auto p : places) {
        s.Walk(p);
        s.SingSong();
    }
}

void VisitPlaces(Person pers, vector<string> places) {
    for (auto p : places) {
        pers.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
