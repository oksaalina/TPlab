//
//  train.hpp
//  tp
//
//  Created by Алина Кузнецова on 13.11.2021.
//наименование, год выпуска,
//полный маршрут следования, количество вагонов, объем перевозимого груза.

#ifndef train_hpp
#define train_hpp
#include "carrier.hpp"

class Train : public Carrier {
private:
    string nameTrain;
    string yearTrain;
    string route;
    string number;
    string valumeTrain;
public:
    Train();
    Train(string _nameTrain, string _yearTrain, string _route, string _number, string _valumeTrain);
    Train(Train& obj);
    ~Train() override;
    
    void setNameTrain (string _name);
    void setYearTrain (string _year);
    void setRoute (string _route);
    void setNumber (string _number);
    void setValumeTrain (string _valume);
    
    string getNameTrain ();
    string getYearTrain ();
    string getRoute ();
    string getNumber ();
    string getValumeTrain ();
    
    void setInfoObject() override;
    void editInfoObject(int id) override;
    void showInfoObject() override;
    void saveInfoObject() override;
};

#endif /* train_hpp */
