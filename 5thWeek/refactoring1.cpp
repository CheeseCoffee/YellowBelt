//
// Created by akbar on 27.06.2020.
//


#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Person{
public:
    Person(const string& name, const string& profession):name_(name),profession_(profession){
    }
    virtual void Walk(const string& destination) const {
        cout << profession_ << ": " << name_ << " walks to: " << destination << endl;
    }
    virtual void Check(const Person& person) const {
    }
    virtual void Learn() const {
    }
    virtual void SingSong() const {
    }
    virtual void Teach() const {
    }
    const string name_;
    const string profession_;
};

class Student:public Person{
public:
    Student(const string& name, const string& favouriteSong):Person(name,"Student"),favouriteSong_(favouriteSong){
    }
    void Walk(const string& destination) const override {
        cout << profession_ << ": " << name_ << " walks to: " << destination << endl;
        cout << profession_ << ": " << name_ << " sings a song: " << favouriteSong_<< endl;
    }
    void Learn() const override {
        cout << profession_ << ": " << name_ << " learns" << endl;
    }
    void SingSong() const override{
        cout << profession_ << ": " << name_ << " sings a song: " << favouriteSong_ << endl;
    }
    const string favouriteSong_;
};

class Teacher:public Person{
public:
    Teacher(const string& name, const string& subject):Person(name,"Teacher"),subject_(subject){
    }
    void Teach() const override {
        cout << profession_ << ": " << name_ << " teaches: " << subject_ << endl;
    }
    const string subject_;
};

class Policeman:public Person{
public:
    Policeman(const string& name):Person(name,"Policeman"){
    }
    void Check(const Person &person) const override {
        cout << profession_ << ": " << name_ << " checks "<< person.profession_<< ". "<< person.profession_ << "'s name is: " << person.name_ << endl;
    }
    const string subject_;
};

void VisitPlaces(const Person& person, vector<string> places) {
    for (auto p : places) {
        person.Walk(p);
    }
};



int main() {
    vector <shared_ptr <Person>> people = {
            make_shared <Teacher>("Jim","Math"),
            make_shared <Policeman>("Bob"),
            make_shared <Student>("Ann","We will rock you"),
    };

    //Teacher t("Jim", "Math");
    //Policeman p("Bob");

    //VisitPlaces(t, {"Moscow", "London"});
    //p.Check(s);
    for (auto a : people) {
        if(a->profession_!="Policeman"){VisitPlaces(*a,{"Moscow", "London"});}
        else{(*a).Check(*people[2]);}
    }
    return 0;
}