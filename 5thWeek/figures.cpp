//
// Created by akbar on 25.06.2020.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <iomanip>

using namespace std;

class Figure{
public:
    virtual string Name() const=0;
    virtual long double Perimeter() const=0;
    virtual long double Area() const=0;
};

class Triangle: public Figure{
public:
    Triangle(int a,int b,int c):a_(a),b_(b),c_(c){
    }
    string Name() const override {
        return name_;
    }
    long double Perimeter() const override {
        return a_+b_+c_;
    }
    long double Area() const override {
        return sqrt(a_+b_+c_)*sqrt(b_+c_-a_)*sqrt(a_+c_-b_)*sqrt(a_+b_-c_)/4.0;
    }
private:
    const string name_="TRIANGLE";
    const int a_;
    const int b_;
    const int c_;
};

class Rect: public Figure{
public:
    Rect(int a,int b):a_(a),b_(b){
    }
    string Name() const override {
        return name_;
    }
    long double Perimeter() const override {
        return a_+a_+b_+b_;
    }
    long double Area() const override {
        return a_*b_;
    }
private:
    const string name_="RECT";
    const int a_;
    const int b_;
};

class Circle: public Figure{
public:
    Circle(int r):r_(r){
    }
    string Name() const override {
        return name_;
    }
    long double Perimeter() const override {
        return 2*3.14*r_;
    }
    long double Area() const override {
        return 3.14*r_*r_;
    }
private:
    const string name_="CIRCLE";
    const int r_;
};

shared_ptr<Figure> CreateFigure(istringstream& ss){
    string name;
    ss >> name;
    if(name=="TRIANGLE"){
        int a,b,c;
        ss>>a>>b>>c;
        return make_shared<Triangle>(a,b,c);
    }
    if(name=="RECT"){
        int a,b;
        ss>>a>>b;
        return make_shared<Rect>(a,b);
    }
    if(name=="CIRCLE"){
        int r;
        ss>>r;
        return make_shared<Circle>(r);
    }
};

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}