#include <string>
#include <sstream>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    string type;
    is>>type;
    if(type=="NEW_BUS"){
        size_t stop_count;
        q.type=QueryType::NewBus;
        is>>q.bus>>stop_count;
        q.stops.resize(stop_count);
        for(string& stop:q.stops){
            is>>stop;
        }
    }
    if(type=="BUSES_FOR_STOP"){
        q.type=QueryType::BusesForStop;
        is>>q.stop;
    }
    if(type=="STOPS_FOR_BUS"){
        q.type=QueryType::StopsForBus;
        is>>q.bus;
    }
    if(type=="ALL_BUSES"){
        q.type=QueryType::AllBuses;
    }
    return is;
}

struct BusesForStopResponse {
    // Наполните полями эту структуру
    string stop;
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    // Реализуйте эту функцию
    bool first=true;
    if(r.buses.empty()){
        os<<"No stop";
    }else{
        for(const string& bus:r.buses){
            if(!first){
                os<<" ";
            }
            first=false;
            os<<bus;
        }
    }
    return os;
}

struct StopsForBusResponse {
    // Наполните полями эту структуру
    string bus;
    vector<string> stops;
    map<string, BusesForStopResponse> buses_for_stop;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    // Реализуйте эту функцию
    bool first = true;
    bool second;
    if(r.stops.empty()){
        os<<"No bus";
    }else{
        for(const string& stop:r.stops){
            second=true;
            if(!first){
                os<<endl;
            }
            first=false;
            os<<"Stop "<<stop<<": ";
            if(r.buses_for_stop.at(stop).buses.size()==1){
                os<<"no interchange";
            }else{
                for(const string& outher_bus:r.buses_for_stop.at(stop).buses){
                    if(!second){
                        os<<" ";
                    }
                    second=false;
                    if(r.bus!=outher_bus){
                        os<<outher_bus;
                    }
                }
            }
        }
    }
    return os;
}

struct AllBusesResponse {
    // Наполните полями эту структуру
    map<string, vector<string>> buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    // Реализуйте эту функцию
    bool first=true;
    bool second=true;
    if(r.buses.empty()){
        os<<"No buses";
    }else{
        for(const auto& bus_item:r.buses){
            second=true;
            if(!first){
                os<<endl;
            }
            first=false;
            os<<"Bus "<<bus_item.first<<": ";
            for(const string& stop:bus_item.second){
                if(!second) {
                    os<<" ";
                }
                second=false;
                os<<stop;
            }
        }
    }
    return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
      // Реализуйте этот метод
      buses_to_stops[bus]=stops;
      for(const string& stop:stops){
          stops_to_buses[stop].push_back(bus);
      }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
      // Реализуйте этот метод
      vector<string>buses;
      if(stops_to_buses.count(stop)>0){
          buses=stops_to_buses.at(stop);
      }else{
          buses={};
      }
      return BusesForStopResponse{stop,buses};
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
      // Реализуйте этот метод
      vector<string>stops;
      if(buses_to_stops.count(bus)>0){
          stops=buses_to_stops.at(bus);
      }else{
          stops={};
      }
      map<string, BusesForStopResponse>buses;
      for(const string& stop:stops){
          buses[stop]=GetBusesForStop(stop);
      }
      return StopsForBusResponse{bus,stops,buses};
  }

  AllBusesResponse GetAllBuses() const {
      // Реализуйте этот метод
      map<string,vector<string>>buses;
      if(!buses_to_stops.empty()){
          buses=buses_to_stops;
      }else{
          buses={};
      }
      return AllBusesResponse{buses};
  }
private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
};

void TestGetBusesForStop(){
    BusManager bm;
    bm.AddBus("32",{"Tolstopaltsevo","Marushkino","Vnukovo"});
    assert(vector<string>{"32"}==bm.GetBusesForStop("Tolstopaltsevo").buses);
    cout<<"Test OK"<<endl;
}

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
    TestGetBusesForStop();
    return 0;
    int query_count;
    Query q;

    stringstream my_ss("10\n"
                       "ALL_BUSES\n"
                       "BUSES_FOR_STOP Marushkino\n"
                       "STOPS_FOR_BUS 32K\n"
                       "NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo\n"
                       "NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo\n"
                       "BUSES_FOR_STOP Vnukovo\n"
                       "NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo\n"
                       "NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo\n"
                       "STOPS_FOR_BUS 272\n"
                       "ALL_BUSES\n");

    //cin >> query_count;
    my_ss>>query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        //cin >> q;
        my_ss>>q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }
    return 0;
}
