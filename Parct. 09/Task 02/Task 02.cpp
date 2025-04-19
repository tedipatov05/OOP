
#include <iostream>
#include "Vector.h"

int main()
{
    Vector vector(8);

    vector.pushBack(15);
    vector.pushBack(20);
    vector.pushBack(30);
    vector.insertAt(2, 11);

    vector.clear();

    std::cout << std::boolalpha << vector.isEmpty() << std::endl;

    vector.pushBack(1);
    vector.pushBack(2);

    vector.insertAt(1, 3);


    for (unsigned i = 0; i < vector.getSize(); i++){
        std::cout << vector[i] << " ";
    }

    std::cout << std::endl;

    /*try{
        std::cout << vector.at(5);

    }catch (std::out_of_range& ex){
        std::cout << ex.what();
    }*/

    //std::cout << vector[1] << " " << vector[2];

    vector.removeAt(1);

    for (unsigned i = 0; i < vector.getSize(); i++) {
        std::cout << vector[i] << " ";
    }

}

