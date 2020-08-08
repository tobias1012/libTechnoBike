#pragma once

#include "SFML/Network.hpp"

class Router
{
public:
    Router();

private:
    sf::UdpSocket socket;
};