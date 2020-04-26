//
// Created by Akbar on 27.04.2020.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

enum class Gender {
    FEMALE,
    MALE
};

struct Person {
    int age;  // возраст
    Gender gender;  // пол
    bool is_employed;  // имеет ли работу
};

// Это пример функции, его не нужно отправлять вместе с функцией PrintStats
template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
    if (range_begin == range_end) {
        return 0;
    }
    vector<typename InputIt::value_type> range_copy(range_begin, range_end);
    auto middle = begin(range_copy) + range_copy.size() / 2;
    nth_element(
            begin(range_copy), middle, end(range_copy),
            [](const Person& lhs, const Person& rhs) {
                return lhs.age < rhs.age;
            }
    );
    return middle->age;
}

void PrintStats(vector<Person> persons){
    cout<<ComputeMedianAge(persons.begin(),persons.end())<<endl;
    auto it=partition(persons.begin(),persons.end(),[](const Person& person){ return person.gender==Gender::FEMALE;});
    cout<<ComputeMedianAge(persons.begin(),it)<<endl;
    it=partition(persons.begin(),persons.end(),[](const Person& person){ return person.gender==Gender::MALE;});
    cout<<ComputeMedianAge(persons.begin(),it)<<endl;
    it=partition(persons.begin(),persons.end(),[](const Person& person){ return person.gender==Gender::FEMALE && person.is_employed==1;});
    cout<<ComputeMedianAge(persons.begin(),it)<<endl;
    it=partition(persons.begin(),persons.end(),[](const Person& person){ return person.gender==Gender::FEMALE && person.is_employed==0;});
    cout<<ComputeMedianAge(persons.begin(),it)<<endl;
    it=partition(persons.begin(),persons.end(),[](const Person& person){ return person.gender==Gender::MALE && person.is_employed==1;});
    cout<<ComputeMedianAge(persons.begin(),it)<<endl;
    it=partition(persons.begin(),persons.end(),[](const Person& person){ return person.gender==Gender::MALE && person.is_employed==0;});
    cout<<ComputeMedianAge(persons.begin(),it)<<endl;
};

int main() {
    vector<Person> persons = {
            {31, Gender::MALE, false},
            {40, Gender::FEMALE, true},
            {24, Gender::MALE, true},
            {20, Gender::FEMALE, true},
            {80, Gender::FEMALE, false},
            {78, Gender::MALE, false},
            {10, Gender::FEMALE, false},
            {55, Gender::MALE, true},
    };
    PrintStats(persons);
    return 0;
}
