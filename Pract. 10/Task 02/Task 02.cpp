// Task 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "FoodPanda.h"
#include "Restaurant.h"

int main()
{
    Restaurant res("Test1", 8);
    res.addProduct(Product("pasta"));
    res.addProduct(Product("meat"));
    res.addProduct(Product("cheese"));
    res.addProduct(Product("pizza"));

    Restaurant res2("Test2", 8);
    res2.addProduct(Product("pasta"));
    res2.addProduct(Product("meat"));
    res2.addProduct(Product("cheese"));
    res2.addProduct(Product("pizza"));


    FoodPanda foot_panda(new Restaurant[2]{ res, res2 }, 2);

    foot_panda.readOrders(std::cin);

   /* Order* orders = new Order[2];
    for (size_t i = 0; i < 2; i++){
        std::cin >> orders[i];
    }

    std::cout << orders[1].products()[1].name() << std::endl;*/



    


}

