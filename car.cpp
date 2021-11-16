//
//  car.cpp
//  tp
//
//  Created by Алина Кузнецова on 13.11.2021.
//год выпуска, марка, модель, в какие города
//осуществляется доставка и для каждого города определено количество часов
//доставки, объем груза.

#include "car.hpp"

Car::Car() {
    mark = "Марка не найдена";
    model = "Модель не найдена";
    yearCar = "Год не найден";
    valumeCar = "Объем груза не найден";
    cout << "[Был запущен конструктор Car]" << endl;
    cout << endl;
}

Car::Car(string _mark, string _model, string _yearCar, string _valumeCar) {
    mark = _mark;
    model = _model;
    yearCar = _yearCar;
    valumeCar = _valumeCar;
    cout << "[Был запущен конструктор Car(с параметром)]" << endl;
    cout << std::endl;
}

Car::Car(Car &obj) {
    mark = obj.mark;
    model = obj.model;
    yearCar = obj.yearCar;
    valumeCar = obj.valumeCar;
    cout << "[Был запущен конструктор копирования Car]" << endl;
    cout << endl;
}

Car::~Car() {
    mark = "";
    model = "";
    yearCar = "";
    valumeCar = "";
    cout << "[Был запущен деструктор Car]" << endl;
    cout << std::endl;
}

void Car::setMark(string _mark) {
    mark = _mark;
}

void Car::setModel(string _model) {
    model = _model;
}

void Car::setYearCar(string _year) {
    yearCar = _year;
}

void Car::setValumeCar(string _valume) {
    valumeCar = _valume;
}

string Car::getMark() {
    return mark;
}

string Car::getModel() {
    return model;
}

string Car::getYearCar() {
    return yearCar;
}

string Car::getValumeCar() {
    return valumeCar;
}

void Car::editInfoObject(int id) {
    string str;
    cin.ignore(32767, '\n');
    switch (id) {
        case 1:
            cout << "Введите новую марку автомобиля: ";
            getline(cin, str);
            if (!numbersInStr(str)) {
                mark = str;
            } else {
                cout << "Введите число, а не строку" << endl;
            }
            break;
        case 2:
            cout << "Введите новую модель автомобиля: ";
            getline(cin, str);
            model = str;
            break;
        case 3:
            cout << "Введите новый год выпуска автомобиля: ";
            cin >> str;
            if (charInNumbers(str)) {
                yearCar = str;
            } else {
               cout << "Введите число, а не строку" << endl;
            }
            break;
        case 4:
            cout << "Введите новый объем груза автомобиля: ";
            cin >> str;
            if (charInNumbers(str)) {
                valumeCar = str;
            } else {
               cout << "Введите число, а не строку" << endl;
            }
            break;
        default:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка" << endl;
            cout << endl;
            break;
    }
}

void Car::setInfoObject() {
    string str;
    cin.ignore(32767, '\n');
    cout << "Введите марку автомобиля: ";
    getline(cin, str);
    if (!charInNumbers(str)) {
        mark = str;
    } else {
        cout << "Вы ввели цифру, данные не были введены" << endl;
    }
    cout << "Введите модель автомобиля: ";
    getline(cin, str);
    model = str;
    cout << "Введите год выпуска автомобиля: ";
    getline(cin, str);
    if (charInNumbers(str)) {
        yearCar = str;
    } else {
       cout << "Вы ввели букву, а не число, данные не были введены" << endl;
    }
    cout << "Введите объем перевозимого груза автомобиля: ";
    getline(cin, str);
    if (charInNumbers(str)) {
        yearCar = str;
    } else {
       cout << "Вы ввели букву, а не число, данные не были введены" << endl;
    }
    cout << endl;
}

void Car::showInfoObject() {
    cout << "1. Марка автомобиля: " << mark << endl;
    cout << "2. Модель автомобиля: " << model << endl;
    cout << "3. Год выпуска автомобиля: " << yearCar << endl;
    cout << "4. Объем перевозимого груза автомобиля: " << valumeCar << endl;
    cout << endl;
}

void Car::saveInfoObject() {
    ofstream fileOut;
    fileOut.open("carrier.txt", ios_base::app);
    try {
        if (!fileOut.is_open()) {
           cout << endl;
            throw "Ошибка открытия файла";
           // std::cout << std::endl;
        }
        else {
            fileOut << "Car" << endl << "mark:"  << mark << endl << "model:" << model << endl << "year:" << yearCar << endl << "valume:"  << valumeCar << endl << endl;
            fileOut.close();
        }
    }
    catch (const char* exception) {
        cout << endl;
        cerr << "Error: " << exception << '\n';
        cout << endl;
    }
}
