//
//  train.cpp
//  tp
//
//  Created by Алина Кузнецова on 13.11.2021.
// string nameTrain;
//

#include "train.hpp"

Train::Train() {
    nameTrain = "Full name not found";
    yearTrain = "Position not found";
    route = "не найден";
    number = "Address not found";
    valumeTrain = "Phone not found";
    cout << "[Был запущен конструктор Train]" << endl;
    cout << endl;
}

Train::Train(string _nameTrain, string _yearTrain, string _route, string _number, string _valumeTrain) {
    nameTrain = _nameTrain;
    yearTrain = _yearTrain;
    route = _route;
    number = _number;
    valumeTrain = _valumeTrain;
    cout << "[Был запущен конструктор Train(с параметром)]" << endl;
    cout << endl;
}

Train::Train(Train &obj) {
    nameTrain = obj.nameTrain;
    yearTrain = obj.yearTrain;
    route = obj.route;
    number = obj.number;
    valumeTrain = obj.valumeTrain;
    cout << "[Был запущен конструктор копирования Train]" << endl;
    cout << endl;
}

Train::~Train() {
    nameTrain = "";
    yearTrain = "";
    route = "";
    number = "";
    valumeTrain = "";
    cout << "[Был запущен деструктор Train]" << endl;
    cout << std::endl;
}

void Train::setNameTrain(string _name) {
    nameTrain = _name;
}

void Train::setYearTrain(string _year) {
    yearTrain = _year;
}

void Train::setRoute(string _route) {
    route = _route;
}

void Train::setNumber(string _number) {
    number = _number;
}

void Train::setValumeTrain(string _valume) {
    valumeTrain = _valume;
}

string Train::getNameTrain() {
    return nameTrain;
}

string Train::getYearTrain() {
    return yearTrain;
}

string Train::getRoute() {
    return route;
}

string Train::getNumber() {
    return number;
}

string Train::getValumeTrain () {
    return valumeTrain;
}

void Train::editInfoObject(int id) {
    string str;
    cin.ignore(32767, '\n');
    switch (id) {
        case 1:
            cout << "Введите новое наименование поезда: ";
            getline(cin, str);
            if (!numbersInStr(str)) {
                nameTrain = str;
            } else {
                cout << "Вы ввели число, данные не были введены" << endl;
            }
            break;
        case 2:
            cout << "Введите новый год выпуска поезда: ";
            getline(cin, str);
            if (numbersInStr(str)) {
                yearTrain = str;
            } else {
                cout << "Вы ввели строку, а не число, данные не были введены" << endl;
            }
            break;
        case 3:
            cout << "Введите новый маршрут следования поезда: ";
            getline(cin, str);
            if (!numbersInStr(str)) {
                route = str;
            } else {
                cout << "Вы ввели число, данные не были введены" << endl;
            }
            break;
        case 4:
            cout << "Введите новое количетсво вагонов поезда: ";
            getline(cin, str);
            if (charInNumbers(str)) {
                number = str;
            } else {
                cout << "Вы ввели строку, а не число, данные не были введены" << endl;
            }
            break;
        case 5:
            cout << "Введите новый объем перевозимого груза поезда: ";
            getline(cin, str);
            if (charInNumbers(str)) {
                valumeTrain = str;
            } else {
                cout << "Вы ввели строку, а не число, данные не были введены" << endl;
            }
            break;
        default:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка!" << endl;
            cout << endl;
            break;
    }
}

void Train::setInfoObject() {
    string str;
    cin.ignore(32767, '\n');
    cout << "Введите наименование поезда: ";
    getline(cin, str);
    nameTrain = str;
    cout << "Введите год выпуска поезда: ";
    getline(cin, str);
    if (numbersInStr(str)) {
        yearTrain = str;
    } else {
        cout << "Вы ввели строку, а не число, данные не были введены" << endl;
    }
    cout << "Введите полный маршрут следоввания поезда: ";
    getline(cin, str);
    if (!charInNumbers(str)) {
        route = str;
    } else {
        cout << "Вы ввели число, данные не были введены" << endl;
    }
    cout << "Введите число вагонов поезда: ";
    getline(cin, str);
    if (numbersInStr(str)) {
        number = str;
    } else {
        cout << "Вы ввели строку, а не число, данные не были введены" << endl;
    }
    cout << "Введите объем перевозимого груза поезда: ";
    getline(cin, str);
    if (numbersInStr(str)) {
        valumeTrain = str;
    } else {
        cout << "Вы ввели строку, а не число, данные не были введены" << endl;
    }
    cout << endl;
}

void Train::showInfoObject() {
    cout << "1. Наименование поезда: " << nameTrain << endl;
    cout << "2. Год выпуска поезда: " << yearTrain << endl;
    cout << "3. Полный маршрут следоввания поезда: " << route << endl;
    cout << "4. Число вагонов поезда: " << number << endl;
    cout << "5. Объем перевозимого груза поезда: " << valumeTrain << endl;
    cout << endl;
}

void Train::saveInfoObject() {
    ofstream fileOut;
    fileOut.open("carrier.txt", ios_base::app);
    try {
        if (!fileOut.is_open()) {
           cout << endl;
            throw "Ошибка открытия файла";
           // cout << endl;
        }
        else {
            fileOut << "Train" << endl << "name:" << nameTrain << endl << "year:"  << yearTrain << endl << "route:" << route << endl << "number:"  << number << endl << "valume:" << valumeTrain << endl << endl;
            fileOut.close();
        }
    }
    catch (const char* exception) {
        cout << endl;
        cerr << "Error: " << exception << '\n';
        cout << endl;
    }
}
