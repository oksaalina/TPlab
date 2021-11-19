//
//  carrier.cpp
//  tp
//
//  Created by Алина Кузнецова on 13.11.2021.
//

#include "carrier.hpp"

Carrier::Carrier() {
    cout << "[Был запущен конструктор Carrier]" << endl;
    cout << endl;
}

Carrier::~Carrier() {
    cout << "[Был запущен деструктор Carrier]" << endl;
    cout << endl;
}

bool Carrier::numbersInStr(string str) {
    int i = 0;
    int found = 0;
    bool exit = false;
    while (!exit) {
        if (str[i] >= '0' && str[i] <= '9') {
            found++;
            exit = true;
        }
        i++;
    }
    if (found == 0) {
        return true;
    } else {
        return false;
    }
}

bool Carrier::charInNumbers(string str) {
    return str.find_first_not_of("0123456789") == string::npos;
}
