//
//  keeper.cpp
//  tp
//
//  Created by Алина Кузнецова on 13.11.2021.
//

#include "keeper.hpp"

using namespace std;

Keeper::Keeper() {
    head = nullptr;
    _size = 0;
    cout << "[Был запущен конструктор Keeper]" << endl;
    cout << endl;
}

Keeper::Keeper(int size) {
    head = nullptr;
    _size = size;
    cout << "[Был запущен конструктор Keeper(c параметром)]" << endl;
    cout << endl;
}

Keeper::~Keeper() {
    if (head != nullptr) {
        Element* buffer;
        while (head->nextElement != nullptr) {
            buffer = head;
            head = head->nextElement;
            buffer->data->~Carrier();
            delete(buffer);
        }
        head->data->~Carrier();
        delete(head);
    }
    cout << "[Был запущен деструктор Keeper]" << endl;
    cout << endl;
}

int Keeper::getSize() {
    return _size;
}

void Keeper::pushObject(Carrier *obj) {
    Element* newElObj;
    newElObj = new Element;
    if (_size == 0) {
        newElObj->data = obj;
        _size++;
        newElObj->nextElement = 0;
        head = newElObj;
    }
    else {
        Element *buf = head;
        while (buf->nextElement != nullptr) {
            buf = buf->nextElement;
        }
        newElObj->data = obj;
        newElObj->nextElement = 0;
        buf->nextElement = newElObj;
        _size++;
    }
}

void Keeper::saveObject() {
    ofstream fileOut;
    fileOut.open("carrier.txt", ios_base::out);
    try {
        if (!fileOut.is_open()) {
            cout << endl;
            throw "Ошибка открытия файла";
        }
        Element* buf = head;
        for (int i = 0; i < _size; i++) {
            buf->data->saveInfoObject();
            buf = buf->nextElement;
        }
    }
    catch (const char* exception) {
        cout << endl;
        cerr << "Error: " << exception << '\n';
    }
}

void Keeper::loadObject() {
    if (head != nullptr) {
        Element* buffer;
        while (head->nextElement != nullptr) {
            buffer = head;
            head = head->nextElement;
            buffer->data->~Carrier();
            delete(buffer);
        }
        head->data->~Carrier();
        delete(head);
        _size = 0;
    }
    ifstream fileIn;
    string item;
    bool work = false;
    bool found = false;
    int counterObject = 0;
    Carrier* carrier;
    fileIn.open("carrier.txt");
    try {
        if (!fileIn.is_open()) {
            cout << endl;
            throw "Ошибка открытия файла";
        } else {
            if (fileIn.peek() == EOF) {
                cout << "Файл пуст(" << endl;
            } else {
                while (!fileIn.eof()) {
                    if (item == "Car" || item == "Train" || item == "Plane") {
                        work = true;
                    } else {
                        getline(fileIn, item);
                    }
                    if (item == "Car" || item == "Train" || item == "Plane") {
                        found = true;
                        if (item == "Car") {
                            string mark = "Марка не найдена";
                            string model = "Модель не найдена";
                            string yearCar = "Год выпуска не найден";
                            string valumeCar = "Объем груза не найден";
                            string cityes = "Города не найдены";
                            string times = "Время не найдено";
                            do {
                                getline(fileIn, item);
                                if (item[0] == 'm' && item[1] == 'a' && item[2] == 'r' && item[3] == 'k' && item[4] == ':') {
                                    item = item.substr(5);
                                    if (!carrier->numbersInStr(item)) {
                                        if (item == "") {
                                            mark = "Нет марки";
                                        } else {
                                            mark = item;
                                        }
                                    } else {
                                        cout << "Вы ввели цифру, когда нужно ввести строку" << endl;
                                    }
                                }
                                if (item[0] == 'm' && item[1] == 'o' && item[2] == 'd' && item[3] == 'e' && item[4] == 'l' && item[5] == ':') {
                                    item = item.substr(6);
                                    if (item == "") {
                                        model = "Нет модели";
                                    } else {
                                        model = item;
                                    }
                                }
                                if (item[0] == 'y' && item[1] == 'e' && item[2] == 'a' && item[3] == 'r' && item[4] == ':') {
                                    item = item.substr(5);
                                    if (carrier->charInNumbers(item)) {
                                        if (item == "") {
                                            yearCar = "Нет года";
                                        } else {
                                           yearCar = item;
                                        }
                                    } else {
                                        cout << "Вы ввели строку, когда нужно ввести цифру" << endl;
                                    }
                                }
                                if (item[0] == 'v' && item[1] == 'a' && item[2] == 'l' && item[3] == 'u' && item[4] == 'm' && item[5] == 'e' && item[6] == ':') {
                                    item = item.substr(7);
                                    if (carrier->charInNumbers(item)) {
                                        if (item == "") {
                                            valumeCar = "Нет объема груза";
                                        } else {
                                            valumeCar = item;
                                        }
                                    } else {
                                        cout << "Вы ввели строку, когда нужно ввести цифру" << endl;
                                    }
                                }
                                if (item[0] == 'c' && item[1] == 'i' && item[2] == 't' && item[3] == 'y' && item[4] == 'e' && item[5] == 's' && item[6] == ':') {
                                    item = item.substr(7);
                                        if (item == "") {
                                          cityes = "Нет городов";
                                        } else {
                                            cityes = item;
                                        }
                                }
                                if (item[0] == 't' && item[1] == 'i' && item[2] == 'm' && item[3] == 'e' && item[4] == 's' && item[5] == ':') {
                                    item = item.substr(6);
                                        if (item == "") {
                                            times = "Нет часов доставки";
                                        } else {
                                            times = item;
                                        }
                                }
                                if (item == "Car" || item == "Train" || item == "Plane" || fileIn.eof()) {
                                    Car* car;
                                    car = new Car(mark, model, yearCar, valumeCar, cityes, times);
                                    carrier = car;
                                    pushObject(carrier);
                                    counterObject++;
                                    break;
                                }
                            } while (true);
                        }
                    
                        if (item == "Train") {
                            string nameTrain = "Наименование поезда не найдено";
                            string yearTrain = "Год выпсука поезда не найден";
                            string route = "Маршрут не найден";
                            string number = "Число вагонов не найдено";
                            string valumeTrain = "Объем груза не найден";
                            do {
                                getline(fileIn, item);
                                if (item[0] == 'n' && item[1] == 'a' && item[2] == 'm' && item[3] == 'e' && item[4] == ':') {
                                    item = item.substr(5);
                                    if (!carrier->numbersInStr(item)) {
                                        if (item == "") {
                                            nameTrain = "Нет наименования";
                                        } else {
                                            nameTrain = item;
                                        }
                                    } else {
                                        cout << "Вы ввели цифру, когда нужно ввести строку" << endl;
                                    }
                                }
                                if (item[0] == 'y' && item[1] == 'e' && item[2] == 'a' && item[3] == 'r' && item[4] == ':') {
                                    item = item.substr(5);
                                    if (!carrier->charInNumbers(item)) {
                                        if (item == "") {
                                            yearTrain = "Нет года выпска";
                                        } else {
                                            yearTrain = item;
                                        }
                                    } else {
                                        cout << "Вы ввели строку, когда нужно ввести цифру" << endl;
                                    }
                                }
                                if (item[0] == 'r' && item[1] == 'o' && item[2] == 'u' && item[3] == 't' && item[4] == 'e' && item[5] == ':') {
                                    item = item.substr(6);
                                    if (!carrier->numbersInStr(item)) {
                                        if (item == "") {
                                            route = "Нет маршрута";
                                        } else {
                                            route = item;
                                        }
                                    } else {
                                        cout << "Вы ввели цифру, когда нужно ввести строку" << endl;
                                    }
                                }
                                if (item[0] == 'n' && item[1] == 'u' && item[2] == 'm' && item[3] == 'b' && item[4] == 'e' && item[5] == 'r' && item[6] == ':') {
                                    item = item.substr(7);
                                    if (!carrier->charInNumbers(item)) {
                                    if (item == "") {
                                        number = "Нет числа вагонов";
                                    } else {
                                        number = item;
                                    }
                                    } else {
                                       cout << "Вы ввели строку, когда нужно ввести цифру" << endl;
                                   }
                                }
                                if (item[0] == 'v' && item[1] == 'a' && item[2] == 'l' && item[3] == 'u' && item[4] == 'm' && item[5] == 'e' && item[6] == ':') {
                                    item = item.substr(7);
                                    if (!carrier->charInNumbers(item)) {
                                        if (item == "") {
                                            valumeTrain = "Нет объема груза";
                                        } else {
                                            valumeTrain = item;
                                        }
                                    } else {
                                        cout << "Вы ввели строку, когда нужно ввести цифру" << endl;
                                    }
                                }
                                if (item == "Car" || item == "Train" || item == "Plane" || fileIn.eof()) {
                                    Train* train;
                                    train = new Train(nameTrain, yearTrain, route, number, valumeTrain);
                                    carrier = train;
                                    pushObject(carrier);
                                    counterObject++;
                                    break;
                                }
                            } while (true);
                        }
                        if (item == "Plane") {
                            string type = "Тип не найден";
                            string namePlane = "Наименование не найдено";
                            string valumePlane = "Объем груза не найден";
                            string townsPlane = "Города не найдены";
                            string width = "Ширина не найдена";
                            string height = "Высота не найдена";
                            string length = "Длина не найдена";
                            do {
                                getline(fileIn, item);
                                if (item[0] == 't' && item[1] == 'y' && item[2] == 'p' && item[3] == 'e' && item[4] == ':') {
                                    item = item.substr(5);
                                        if (item == "") {
                                            type = "Нет типа";
                                        } else {
                                            type = item;
                                        }
                                }
                                if (item[0] == 'n' && item[1] == 'a' && item[2] == 'm' && item[3] == 'e' && item[4] == ':') {
                                    item = item.substr(5);
                                        if (item == "") {
                                            namePlane = "Нет наименования";
                                        } else {
                                            namePlane = item;
                                        }
                                }
                                if (item[0] == 'v' && item[1] == 'a' && item[2] == 'l' && item[3] == 'u' && item[4] == 'm' && item[5] == 'e' && item[6] == ':') {
                                    item = item.substr(7);
                                    if (carrier->charInNumbers(item)) {
                                    if (item == "") {
                                        valumePlane = "Нет объема груза";
                                    } else {
                                        valumePlane = item;
                                    }
                                    } else {
                                        cout << "Вы ввели строку, когда нужно ввести цифру" << endl;
                                    }
                                }
                                if (item[0] == 't' && item[1] == 'o' && item[2] == 'w' && item[3] == 'n' && item[4] == 's' && item[5] == ':') {
                                    item = item.substr(6);
                                    if (!carrier->numbersInStr(item)) {
                                        if (item == "") {
                                            townsPlane = "Нет городов";
                                        } else {
                                            townsPlane = item;
                                        }
                                    } else {
                                        cout << "Вы ввели цифру, когда нужно ввести строку" << endl;
                                    }
                                }
                                if (item[0] == 'w' && item[1] == 'i' && item[2] == 'd' && item[3] == 't' && item[4] == 'h' && item[5] == ':') {
                                    item = item.substr(6);
                                    if (carrier->charInNumbers(item)) {
                                        if (item == "") {
                                            width = "Нет ширины";
                                        } else {
                                            width = item;
                                        }
                                    } else {
                                        cout << "Вы ввели строку, когда нужно ввести цифру" << endl;
                                    }
                                }
                                if (item[0] == 'h' && item[1] == 'e' && item[2] == 'i' && item[3] == 'g' && item[4] == 'h' && item[5] == 't' && item[6] == ':') {
                                    item = item.substr(7);
                                    if (carrier->charInNumbers(item)) {
                                        if (item == "") {
                                            height = "Нет высоты";
                                        } else {
                                            height = item;
                                        }
                                    } else {
                                        cout << "Вы ввели строку, когда нужно ввести цифру" << endl;
                                    }
                                }
                                if (item[0] == 'l' && item[1] == 'e' && item[2] == 'n' && item[3] == 'g' && item[4] == 't' && item[5] == 'h' && item[6] == ':') {
                                    item = item.substr(7);
                                    if (carrier->charInNumbers(item)) {
                                        if (item == "") {
                                            length = "Нет длины";
                                        } else {
                                            length = item;
                                        }
                                    } else {
                                        cout << "Вы ввели строку, когда нужно ввести цифру" << endl;
                                    }
                                }
                                if (item == "Car" || item == "Train" || item == "Plane" || fileIn.eof()) {
                                    Plane* plane;
                                    plane = new Plane(type, namePlane, valumePlane, townsPlane, width, height, length);
                                    carrier = plane;
                                    pushObject(carrier);
                                    counterObject++;
                                    break;
                                }
                            } while (true);
                        }
                    }
                }
            }
        }
        if (fileIn.eof() && (item == "Car" || item == "Train" || item == "Plane")) {
            cout << "Сначала добавьте объект!" << endl;
            cout << endl;
        }
        if (!found) {
            cout << "Пусто!" << endl;
            cout << endl;
        }
        fileIn.close();
    }
    catch (const char* exception) {
        cout << endl;
        cerr << "Error: " << exception << '\n';
    }
}

void Keeper::popObject(int index) {
    Element* buf = head;
    Element* bufOne;
    if (_size == 0) {
        cout << "Пусто!" << endl;
        return;
    }
    if (((index) >= _size) || (index < 0)) {
        cout << "Индекс не найден" << endl;
    }

    else {
        if (buf->nextElement == nullptr) {
            buf->data->~Carrier();
            _size--;
            return;
        }
        if (index == 0) {
            head = buf->nextElement;
            buf->data->~Carrier();
            _size--;
            return;
        }
        for (int i = 0; i < index - 1; i++) {
            buf = buf->nextElement;
        }
        bufOne = buf->nextElement;
        buf->nextElement = bufOne->nextElement;
        bufOne->data->~Carrier();
        _size--;
    }
}

Carrier* Keeper::operator[] (const int index) {
    Element* buf = head;
    if (((index) >= _size) || (index < 0)) {
        cout << "Ошибка!" << endl;
    }
    else {
        for (int i = 0; i < index; i++) {
            buf = buf->nextElement;
        }
    }
    return (buf->data);
}
