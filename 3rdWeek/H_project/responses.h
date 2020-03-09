//
// Created by Akbar on 08.03.2020.
//
#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

struct BusesForStopResponse {
    // Наполните полями эту структуру
    string stop;
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
    // Наполните полями эту структуру
    string bus;
    vector<string> stops;
    map<string, BusesForStopResponse> buses_for_stop;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
    // Наполните полями эту структуру
    map<string, vector<string>> buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);