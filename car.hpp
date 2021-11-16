//
//  car.hpp
//  tp
//
//  Created by Алина Кузнецова on 13.11.2021.
//год выпуска, марка, модель, в какие города
//осуществляется доставка и для каждого города определено количество часов
//доставки, объем груза.

#ifndef car_hpp
#define car_hpp

#include <stdio.h>
#include "carrier.hpp"

class Car : public Carrier {
private:
    string mark;
    string model;
    string yearCar;
    string valumeCar;

public:
    Car();
    Car(string mark, string model, string yearCar, string valumeCar);
    Car(Car& obj);
    ~Car() override;

    void setMark(string _mark);
    void setModel(string _model);
    void setYearCar(string _year);
    void setValumeCar(string _valume);

    string getMark();
    string getModel();
    string getYearCar();
    string getValumeCar();

    void setInfoObject() override;
    void editInfoObject(int id) override;
    void showInfoObject() override;
    void saveInfoObject() override;
    };

#endif /* car_hpp */
