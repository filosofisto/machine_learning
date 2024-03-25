#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "MachineLearning.h"

typedef struct 
{
    double carat;
    double price;
} DIAMOND;

int main(int argc, char** argv)
{
    MachineLearning<DIAMOND> ml;

    DIAMOND values[10] = {
        {300.0, 339.0}, {410.0, 561.0},
        {750.0, 2760.0}, {910.0, 2763.0},
        {1200.0, 2809.0}, {1310.0, 3697.0},
        {1500.0, 4022.0}, {1740.0, 4677.0},
        {1960.0, 6147.0}, {2210.0, 6535.0}
    };

    for (int i = 0; i < 10; ++i) {
        ml << values[i];
    }

    auto getCarat = [](const DIAMOND& diamond) { return diamond.carat; };
    double value_mean_carat = ml.mean(getCarat);
    std::cout << "Mean Carat: " << value_mean_carat << std::endl;

    auto getPrice = [](const DIAMOND& diamond) { return diamond.price; };
    double value_mean_price = ml.mean(getPrice);
    std::cout << "Mean Price: " << value_mean_price << std::endl;

    return EXIT_SUCCESS;
}

