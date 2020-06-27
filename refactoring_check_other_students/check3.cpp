#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
public:
    /* attribute 'explicit' is needed to avoid calls like
            VisitPlaces({name}, places)
     * that could be misled
     */
    explicit Human(const string &name, const string &profession = "Human");

    // common realization that can be overridden (see Student class)
    virtual void Walk(const string &destination) const;

protected:
    // чтобы не дублировать 'Profession << ": "' по всем функциям
    string Entry() const { return Profession + ": "; }

public:
    const string Name;

    // возможно, название 'Type' удачнее
    const string Profession;
};

class Student : public Human {
public:
    Student(const string &name, const string &favouriteSong);

    void Learn() const;

    void Walk(const string &destination) const override;

    void SingSong() const;

public:
    const string FavouriteSong;
};

class Teacher : public Human {
public:
    Teacher(const string &name, const string &subject);

    void Teach() const;

public:
    const string Subject;
};

class Policeman : public Human {
public:
    explicit Policeman(const string &name);

    void Check(const Human &h) const;
};


Human::Human(const string &name, const string &profession) :
        Name(name),
        Profession(profession) {}

void Human::Walk(const string &destination) const {
    cout << Entry() << Name << " walks to: " << destination << endl;
}


Student::Student(const string &name, const string &favouriteSong) :
        Human(name, "Student"),
        FavouriteSong(favouriteSong) {}

void Student::Learn() const {
    cout << Entry() << Name << " learns" << endl;
}

void Student::SingSong() const {
    cout << Entry() << Name << " sings a song: " << FavouriteSong << endl;
}

void Student::Walk(const string &destination) const {
    Human::Walk(destination);
    SingSong();
}


Teacher::Teacher(const string &name, const string &subject) :
        Human(name, "Teacher"),
        Subject(subject) {}

void Teacher::Teach() const {
    cout << Entry() << Name << " teaches: " << Subject << endl;
}


Policeman::Policeman(const string &name) : Human(name, "Policeman") {}

void Policeman::Check(const Human &h) const {
    cout << Entry() << Name << " checks " << h.Profession << ". "
         << h.Profession << "'s name is: " << h.Name << endl;
}


void VisitPlaces(const Human &h, const vector<string> &places) {
    for (const auto &p : places) {
        h.Walk(p);
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
