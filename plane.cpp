//
//  plane.cpp
//  tp
//
//  Created by Алина Кузнецова on 13.11.2021.
//namePlane;
//string valumePlane;
//string width;
//string height;
//string depth;
//string townsPlsne;

#include "plane.hpp"

Plane::Plane() {
    type = "Тип не найден";
    namePlane = "Наименование самолета не найдено";
    valumePlane = "Объем перевозимого груза не найден";
    townsPlane = "Города не найдены";
    width = "Ширина не найдена";
    height = "Высота не найдена";
    length = "Длина не найдена";
    cout << "[Был запущен конструктор Plane]" << endl;
    cout << endl;
}

Plane::Plane(string _type, string _namePlane, string _valumePlane, string _towns, string _width, string _height, string _length) {
    type = _type;
    namePlane = _namePlane;
    valumePlane = _valumePlane;
    townsPlane = _towns;
    width = _width;
    height = _height;
    length = _length;
    cout << "[Был запущен конструктор Plane(с параметром)]" << endl;
    cout << endl;
}

Plane::Plane(Plane &obj) {
    type = obj.type;
    namePlane = obj.namePlane;
    valumePlane = obj.valumePlane;
    townsPlane = obj.townsPlane;
    width = obj.width;
    height = obj.height;
    length = obj.length;
    cout << "[Был запущен конструктор копирования Plane]" << endl;
    cout << endl;
}

Plane::~Plane() {
    type = "";
    namePlane = "";
    valumePlane = "";
    townsPlane = "";
    width = "";
    height = "";
    length = "";
    cout << "[Был запущен деструктор Plane]" << endl;
    cout << endl;
}

void Plane::setType(string _type) {
    type = _type;
}

void Plane::setNamePlane(string _namePlane){
    namePlane = _namePlane;
}

void Plane::setValumePlane(string _valumePlane) {
    valumePlane = _valumePlane;
}

void Plane::setTownsPlane(string _townsPlane) {
    townsPlane = _townsPlane;
}

void Plane::setWidth(string _width) {
    width = _width;
}

void Plane::setHeight(string _height) {
    height = _height;
}

void Plane::setLength(string _length) {
    length = _length;
}

string Plane::getType() {
    return type;
}

string Plane::getNamePlane() {
    return namePlane;
}

string Plane::getValumePlane() {
    return valumePlane;
}

string Plane::getTownsPlane() {
    return townsPlane;
}

string Plane::getWidth() {
    return width;
}

string Plane::getHeight() {
    return height;
}

string Plane::getLength() {
    return length;
}

void Plane::editInfoObject(int id) {
    string str;
    cin.ignore(32767, '\n');
    switch (id) {
        case 1:
            cout << "Введите новый тип самолета: ";
            getline(cin, str);
            if (!numbersInStr(str)) {
                type = str;
            } else {
                cout << "Вы ввели только цифры, данные не были введены" << endl;
            }
            break;
        case 2:
            cout << "Введите новое название самолета: ";
            getline(cin, str);
            if (!numbersInStr(str)) {
                namePlane = str;
            } else {
                cout << "Вы ввели цифры, данные не были введены" << endl;
            }
            break;
        case 3:
            cout << "Ввдеите новый объем перевозмого груза: ";
            getline(cin, str);
            if (charInNumbers(str)) {
                valumePlane = str;
            } else {
                cout << "Вы ввели строку, а не число, данные не были введены" << endl;
            }
            break;
        case 4:
            cout << "Введите новый маршрут: ";
            getline(cin, str);
            if (!numbersInStr(str)) {
                townsPlane = str;
            } else {
                cout << "Вы ввели только цифры, данные не были введены" << endl;
            }
            break;
        case 5:
            cout << "Введите новую ширину самолета: ";
            getline(cin, str);
            if (charInNumbers(str)) {
                width = str;
            } else {
                cout << "Вы ввели буквы, а не число, данные не были введены" << endl;
            }
            break;
        case 6:
            cout << "Введите новую высоту самолета: ";
            getline(cin, str);
            if (charInNumbers(str)) {
                height = str;
            } else {
                cout << "Вы ввели буквы, а не число, данные не были введены" << endl;
            }
            break;
        case 7:
            cout << "Ввдетие новую длину самолета: ";
            getline(cin, str);
            if (charInNumbers(str)) {
                length = str;
            } else {
                cout << "Вы ввели буквы, а не число, данные не были введены" << endl;
            }
            break;
        default:
            cout << "Ошибка!" << endl;
            cout << endl;
            break;
    }
}

void Plane::setInfoObject() {
    string str;
    cin.ignore(32767, '\n');
    cout << "Введите тип самолета: ";
    getline(cin, str);
    type = str;
    cout << "Введите наименование самолета: ";
    getline(cin, str);
    namePlane = str;
    cout << "Введите объем перевозимого груза самолета: ";
    getline(cin, str);
    if (charInNumbers(str)) {
        valumePlane = str;
    } else {
        cout << "Вы ввели буквы, а не число, данные не были введены" << endl;
    }
    cout << "Введите города: ";
    getline(cin, str);
    if (!numbersInStr(str)) {
        townsPlane = str;
    } else {
        cout << "Вы ввели цифру, данные не были введены" << endl;
    }
    cout << "Введите ширину самолета: ";
    getline(cin, str);
    if (charInNumbers(str)) {
        width = str;
    } else {
        cout << "Вы ввели буквы, а не число, данные не были введены" << endl;
    }
    cout << "Введите высоту самолета: ";
    getline(cin, str);
    if (charInNumbers(str)) {
        height = str;
    } else {
        cout << "Вы ввели буквы, а не число, данные не были введены" << endl;
    }
    cout << "Введите длину самолета: ";
    getline(cin, str);
    if (charInNumbers(str)) {
            length = str;
    } else {
        cout << "Вы ввели буквы, а не число, данные не были введены" << endl;
    }
    cout << endl;
}

void Plane::showInfoObject() {
    cout << "1. Тип самолета: " << type << endl;
    cout << "2. Наименование самолета: " << namePlane << endl;
    cout << "3. Объем перевозимого груза самолета: " << valumePlane << endl;
    cout << "4. Города: " << townsPlane << endl;
    cout << "5. Высота самолета: " << height << endl;
    cout << "6. Ширина самолета: " << width << endl;
    cout << "7. Длина самолета: " << length << endl;
    cout << endl;
}

void Plane::saveInfoObject() {
    ofstream fileOut;
    fileOut.open("carrier.txt", ios_base::app);
    try {
        if (!fileOut.is_open()) {
           cout << endl;
            throw "Ошибка открытия файла";
        }
        else {
            fileOut << "Plane" << endl << "type:" << type << endl << "name:"  << namePlane << endl << "valume:"  << valumePlane << endl
                    << "towns:" << townsPlane   << endl
                    << "width:" << width << endl << "height:" << height << endl
                    << "length:" << length << endl;
            fileOut.close();
        }
    }
    catch (const char* exception) {
        cout << endl;
        cerr << "Error: " << exception << '\n';
        cout << endl;
    }
}
