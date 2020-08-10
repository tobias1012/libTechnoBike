#pragma once

#include "SFML/Network.hpp"

struct BikeUpdate
{
    sf::IpAddress sender;
    int rpm;
    int watt;
};

class Bike
{
public:
    Bike();
};
