//
//  element.hpp
//  tp
//
//  Created by Алина Кузнецова on 13.11.2021.
//

#ifndef element_hpp
#define element_hpp
#include "carrier.hpp"

class Element {
public:
    Element* nextElement;
    Carrier* data;
};

#endif /* element_hpp */
