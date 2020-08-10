#pragma once

#include <vector>

#include "bike.hpp"

class BikeHandler
{
public:
    BikeHandler();

private:
    std::vector<Bike> bikes;
}