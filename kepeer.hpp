//
//  kepeer.hpp
//  tp
//
//  Created by Алина Кузнецова on 13.11.2021.
//

#ifndef kepeer_hpp
#define kepeer_hpp

#include <stdio.h>

#include "car.hpp"
#include "train.hpp"
#include "plane.hpp"
#include "element.hpp"

class Keeper {
private:
    Element *head;
    int _size;
public:
    Keeper();
    explicit Keeper(int size);
    ~Keeper();

    void saveObject();
    void pushObject(Carrier* obj);
    void popObject(int index);
    void loadObject();
    int getSize();

    Carrier* operator[] (int index);
};

#endif /* kepeer_hpp */
