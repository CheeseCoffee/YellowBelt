//
// Created by Акбар on 08.03.2020.
//
#include <iostream>
#include <sstream>
#include "phone_number.h"

PhoneNumber::PhoneNumber(const string &international_number){
    istringstream number_stream(international_number);
    bool ok = true;

    ok = ok && (number_stream.peek() == '+');
    number_stream.ignore(1);

    int country_code;
    ok = ok && (number_stream >> country_code);
    ok = ok && (number_stream.peek() == '-');
    number_stream.ignore(1);

    int city_code;
    ok = ok && (number_stream >> city_code);
    ok = ok && (number_stream.peek() == '-');
    number_stream.ignore(1);

    ok = ok && (number_stream >> local_number_);
    ok = ok && number_stream.eof();

    country_code_=to_string(country_code);
    city_code_=to_string(city_code);
    if (!ok) {
        throw invalid_argument("Wrong number format: " + international_number);
    }
};

string PhoneNumber::GetCountryCode() const{
    return country_code_;
};
string PhoneNumber::GetCityCode() const{
    return city_code_;
};
string PhoneNumber::GetLocalNumber() const{
    return local_number_;
};
string PhoneNumber::GetInternationalNumber() const{
    return "+"+country_code_+"-"+city_code_+"-"+local_number_;
};