#pragma once
#define PACKET_BUFFER_SIZE 1024


#include "SFML/Network.hpp"

struct Packet
{
    char buffer[PACKET_BUFFER_SIZE];
    sf::IpAddress sender;
    size_t recieved;
    
};