//
//  carrier.hpp
//  tp
//
//  Created by Алина Кузнецова on 13.11.2021.
//

#ifndef carrier_hpp
#define carrier_hpp

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Carrier {
public:
    
    Carrier();
    virtual ~Carrier();
    bool numbersInStr(std::string str);
    bool charInNumbers(std::string str);
    virtual void setInfoObject() = 0;
    virtual void editInfoObject(int id) = 0;
    virtual void showInfoObject() = 0;
    virtual void saveInfoObject() = 0;
    
};

#endif /* carrier_hpp */
