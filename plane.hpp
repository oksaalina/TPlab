//
//  plane.hpp
//  tp
//
//  Created by Алина Кузнецова on 13.11.2021.
//тип, наименование, объем перевозимого груза, габариты,
//какие города посещает.

#ifndef plane_hpp
#define plane_hpp
#include "carrier.hpp"

class Plane : public Carrier {
private:
    string type;
    string namePlane;
    string valumePlane;
    string width;
    string height;
    string length;
    string townsPlane;

public:
    Plane();
    Plane(string _type, string _namePlane, string _valumePlane, string _towns, string _width, string _height, string _length);
    Plane(Plane& obj);
    ~Plane() override;
    
    void setType(string _type);
    void setNamePlane(string _namePlane);
    void setValumePlane(string _valumePlane);
    void setTownsPlane(string _townsPlane);
    void setWidth(string _width);
    void setHeight(string _height);
    void setLength(string _length);

    string getType();
    string getNamePlane();
    string getValumePlane();
    string getTownsPlane();
    string getWidth();
    string getHeight();
    string getLength();

    void setInfoObject() override;
    void editInfoObject(int id) override;
    void showInfoObject() override;
    void saveInfoObject() override;
};
#endif /* plane_hpp */
