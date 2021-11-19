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
#include "carrier.hpp"

class Car : public Carrier {
private:
    struct City {
        string name;
        string time;
        };
    string mark;
    string model;
    string yearCar;
    string valumeCar;
    City city;
public:
    Car();
    Car(string _mark, string _model, string _yearCar, string _valumeCar, string _cityes, string _times);
    Car(Car& obj);
    ~Car() override;

    void setMark(string _mark);
    void setModel(string _model);
    void setYearCar(string _year);
    void setValumeCar(string _valume);
    void setCityName(string _name);
    void setCityTime(string _time);

    string getMark();
    string getModel();
    string getYearCar();
    string getValumeCar();
    string getCityName();
    string getCityTime();

    void setInfoObject() override;
    void editInfoObject(int id) override;
    void showInfoObject() override;
    void saveInfoObject() override;
    };

#endif /* car_hpp */
