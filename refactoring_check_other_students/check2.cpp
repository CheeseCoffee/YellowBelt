#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string& name,const string& occupation)
            : Name(name),Occupation(occupation){}
    const string Name;
    const string Occupation;
};

class Student : public Person{
public:

    Student(const string& name, const string& favouriteSong)
            : Person(name,"Student"), FavouriteSong(favouriteSong) {}

    void Learn() const{
        cout << "Student: " << Name << " learns" << endl;
    }

    void SingSong() const{
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher : public Person{
public:

    Teacher(const string& name, const string& subject)
            : Person(name,"Teacher"), Subject(subject) {}

    void Teach() const{
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }

private:
    const string Subject;
};


class Policeman : public Person{
public:
    Policeman(const string& name)
            : Person(name,"Policeman"){}

    void Check(Person& p) const{
        cout << "Policeman: " << Name << " checks "
             << p.Occupation<<". "<<p.Occupation<< "'s name is: " << p.Name << endl;
    }
};

void Walk(Person& p,const string& destination){
    cout<< p.Occupation<<": "<<p.Name<<" walks to: "<<destination<<endl;
}

void VisitPlaces(Person& person, const vector<string>& places) {
    for (const auto& p : places) {
        Walk(person,p);
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


