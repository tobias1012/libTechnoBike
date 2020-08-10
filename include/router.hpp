#pragma once

#include <deque>

#include "SFML/Network.hpp"
#include "SFML/System.hpp"

#include "packet.hpp"
#include "bike.hpp"

class Router
{
public:
    Router();
    void start();
    BikeUpdate getNextUpdate();

private:
    std::deque<Packet> rawPackets;
    std::deque<BikeUpdate> bikeData;
    sf::UdpSocket socket;

    //Functions
    void recieve();
    void parse(Packet* packet);
    void _start();

    //threads
    sf::Thread reciever;
    //sf::Thread router;

    //Mutexes
    sf::Mutex rawPacketMutex;
};