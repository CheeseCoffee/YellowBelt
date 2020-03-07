//
// Created by Акбар on 08.03.2020.
//

#include <iostream>
#include "phone_number.h"

using namespace std;
int main(){
    try{
        PhoneNumber a("+7-495-1112233");
        PhoneNumber b("+7-495-111-22-33");
        PhoneNumber c("");
    }catch(exception &e) {
        cout<<e.what()<<endl;
    }
    return 0;
}