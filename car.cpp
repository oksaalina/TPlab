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
    city.name = "Города не найдены";
    city.time = "Время не найдено";
    cout << "[Был запущен конструктор Car]" << endl;
    cout << endl;
}

Car::Car(string _mark, string _model, string _yearCar, string _valumeCar, string _cityes, string _times) {
    mark = _mark;
    model = _model;
    yearCar = _yearCar;
    valumeCar = _valumeCar;
    city.name = _cityes;
    city.time = _times;
    cout << "[Был запущен конструктор Car(с параметром)]" << endl;
    cout << endl;
}

Car::Car(Car &obj) {
    mark = obj.mark;
    model = obj.model;
    yearCar = obj.yearCar;
    valumeCar = obj.valumeCar;
    city.name = obj.city.name;
    city.time = obj.city.time;
    cout << "[Был запущен конструктор копирования Car]" << endl;
    cout << endl;
}

Car::~Car() {
    mark = "";
    model = "";
    yearCar = "";
    valumeCar = "";
    city.name = "";
    city.time = "";
    cout << "[Был запущен деструктор Car]" << endl;
    cout << endl;
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

void Car::setCityName(string _name) {
    city.name = _name;
}
void Car::setCityTime(string _time){
    city.time = _time;
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

string Car::getCityName() {
    return city.name;
}
string Car::getCityTime() {
    return city.time;
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
        case 5:
            cout << "Введите новый город для доставки автомобиля: ";
            cin >> str;
            if (!numbersInStr(str)) {
                city.name = str;
            } else {
               cout << "Введите строку, а не число" << endl;
            }
            break;
        case 6:
            cout << "Введите новое количество часов для доставки автомобиля: ";
            cin >> str;
            if (charInNumbers(str)) {
                city.time = str;
            } else {
               cout << "Введите число, а не строку" << endl;
            }
            break;
        default:
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
        valumeCar = str;
    } else {
       cout << "Вы ввели букву, а не число, данные не были введены" << endl;
    }
    cout << "В какое количество городов осуществляется доставка: ";
    int num = 0;
    cin >> num;
    if (num >= 0 && num <= 9) {
        cin.ignore(32767, '\n');
        city.name = "";
        city.time = "";
        string space = " ";
        string number = "№";
        string index;
        for (int i = 0; i < num; i++) {
            cout << "Введите название города №" << i << ": ";
            getline(cin, str);
            index = to_string(i);
            if (!numbersInStr(str)) {
                city.name.append(number + index + space + str + space);
                
            } else {
                cout << "Вы ввели цифру, данные не были введены" << endl;
            }
            cout << "Введите количетсво часов доставки для города №" << i << ": ";
            getline(cin, str);
            if (charInNumbers(str)) {
                city.time.append(number + index + space + str + space);
                
            } else {
                cout << "Вы ввели цифру, данные не были введены" << endl;
            }
        }
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
    cout << "5. Города для доставки автомобиля: " << city.name << endl;
    cout << "6. Количетсво часов для доставки автомобиля: " << city.time << endl;
    cout << endl;
}

void Car::saveInfoObject() {
    ofstream fileOut;
    fileOut.open("carrier.txt", ios_base::app);
    try {
        if (!fileOut.is_open()) {
            cout << endl;
            throw "Ошибка открытия файла";
        }
        else {
            fileOut << "Car" << endl << "mark:"  << mark << endl << "model:" << model << endl << "year:" << yearCar << endl << "valume:" << valumeCar << endl << "cityes:" << city.name << endl << "times:" << city.time << endl << endl;
            fileOut.close();
        }
    }
    catch (const char* exception) {
        cout << endl;
        cerr << "Error: " << exception << '\n';
        cout << endl;
    }
}
