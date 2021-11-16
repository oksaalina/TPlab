//
//  main.cpp
//  tp
//
//  Created by Алина Кузнецова on 13.11.2021.
//


#include <iostream>
#include "kepeer.hpp"
#include "carrier.hpp"
#include "plane.hpp"
#include "train.hpp"
#include "car.hpp"

using namespace std;

int main() {
    int variant;
    int _variant;
    int id;
    int _id;
    bool exit = false;
    string value;
    Keeper keep;
    Carrier* carrier;
    do {
        cout << "Основное меню" << endl;
        cout << "1. Добавить объект" << endl;
        cout << "2. Изменить объект" << endl;
        cout << "3. Удалить объект" << endl;
        cout << "4. Выгрузить из файла" << endl;
        cout << "5. Вывести данные на экран" << endl;
        cout << "6. Сохранить в файл" << endl;
        cout << "0. Выход" << endl;
        cout << "" << endl;
        cout << "Ваш выбор: ";
        if ((cin >> variant)) {
            switch (variant) {
                case 1: //add
                    cout << "1. Самолет" << endl;
                    cout << "2. Поезд" << endl;
                    cout << "3. Автомобиль" << endl;
                    cout << "Ваш выбор: ";
                    if ((cin >> _variant)) {
                        switch (_variant) {
                            case 1:
                                Plane* plane;
                                plane = new Plane();
                                carrier = plane;
                                plane->setInfoObject();
                                keep.pushObject(carrier);
                                break;
                            case 2:
                                Train* train;
                                train = new Train();
                                carrier = train;
                                train->setInfoObject();
                                keep.pushObject(carrier);
                                break;
                            case 3:
                                Car* car;
                                car = new Car();
                                carrier = car;
                                car->setInfoObject();
                                keep.pushObject(carrier);
                                break;
                            default:
                                cout << endl;
                                cout << "Ошибка!" << endl;
                                cout << endl;
                                break;
                        }
                    } else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << endl;
                        cout << "Ошибка ввода, попробуйте еще раз" << endl;
                        cout << endl;
                    }
                    break;
                case 2:
                    if (keep.getSize() == 0) {
                        cout << "Пусто! Для начала введите объект" << endl;
                        cout << endl;
                    } else {
                        cout << endl;
                        for (int i = 0; i < keep.getSize(); i++) {
                            cout << "Объект №: " << (i) << endl;
                            keep[i]->showInfoObject();
                        }
                        cout << "Введите номер объекта: ";
                        if ((cin >> id)) {
                           // id = id + 1;
                            if (id < 0 || id > (keep.getSize() - 1)) {
                                cout << "Ошибка ввода, попробуйте еще раз" << endl;
                                cout << endl;
                            } else {
                                cout << endl;
                                cin.ignore(32767, '\n');
                                keep[id]->showInfoObject();
                                cout << "Изменить данные №: ";
                                cin >> _id;
                                cout << endl;
                                keep[id]->editInfoObject(_id);
                            }
                        } else {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << endl;
                            cout << "Ошибка ввода, попробуйте еще раз" << endl;
                            cout << endl;
                        }
                    }
                    break;
                case 3:
                    if (keep.getSize() == 0) {
                        cout << "Пусто! Для начала введите объект" << endl;
                        cout << endl;
                    } else {
                        cout << endl;
                        for (int i = 0; i < keep.getSize(); i++) {
                            cout << "Объект: " << i << endl;
                            keep[i]->showInfoObject();
                        }
                        cout << "Введите номер объекта: ";
                        if ((cin >> id)) {
                            if (id < 0 || id > (keep.getSize() - 1)) {
                                cout << "Ошибка ввода, попробуйте еще раз" << endl;
                                cout << endl;
                            } else {
                                cin.ignore(32767, '\n');
                                keep.popObject(id);
                                cout << "Объект № " << id << " был удален" << endl;
                                cout << endl;
                            }
                        } else {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << endl;
                            cout << "Ошибка ввода, попробуйте еще раз" << endl;
                            cout << endl;
                        }
                    }
                    break;
                case 4:
                    keep.loadObject();
                    //cout << "Сохранено" << endl;
                    break;
                case 5:
                    
                    if (keep.getSize() == 0) {
                        cout << "Пусто! Для начала введите объект" << endl;
                        cout << endl;
                    } else {
                        cout << endl;
                        for (int i = 0; i < keep.getSize(); i++) {
                            keep[i]->showInfoObject();
                        }
                    }
                    break;
                case 6:
                    if (keep.getSize() == 0) {
                        cout << "Пусто! Для начала введите объект" << endl;
                        cout << endl;
                    } else {
                        keep.saveObject();
                        cout << "Сохранено" << endl;
                        cout << endl;
                    }
                    break;
                 
                case 0:
                    exit = true;
                    break;
                default:
                    cout << endl;
                    cout << "Ошибка ввода, попробуйте еще раз" << endl;
                    cout << endl;
                    break;
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << endl;
            cout << "Ошибка ввода, попробуйте еще раз" << endl;
            cout << endl;
        }
    } while (!exit);
}

        
        


