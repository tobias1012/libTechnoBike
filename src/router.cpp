#include "router.hpp"

Router::Router()
    : reciever(&Router::recieve, this)
{
    //make the socket listen to the bikes port
    if(socket.bind(1000)) //TODO: Find correct port to bind to
    {
        throw("failed to bind!");
    }

}

BikeUpdate Router::getNextUpdate()
{

    //return update and remove
    if(bikeData.size() == 0) throw "No updates in queue";

    BikeUpdate ret = bikeData[0];
    bikeData.pop_front();

    return ret;
    
}


void Router::recieve()
{
    while(true)
    {
        unsigned short port;
        Packet temp;

        if(socket.receive(temp.buffer, PACKET_BUFFER_SIZE, temp.recieved, temp.sender, port) != sf::Socket::Done)
        {
            //error occured that needs to be handled (or not)
        }
        else
        {
            //skip if packet isn't for bikes
            if(!true) continue;

            rawPacketMutex.lock();
            rawPackets.push_back(temp);
            rawPacketMutex.unlock();
        }
    }
}

void Router::parse(Packet* packet)
{
    BikeUpdate ret;

    ret.rpm = packet->buffer[42];
    ret.sender = packet->sender;
    ret.watt = packet->buffer[42];

    bikeData.push_back(ret);

    delete packet;
}

void Router::_start()
{
    //start our packet reciever
    reciever.launch();

    while(true)
    {
        //get newest packet
        rawPacketMutex.lock();
        
        Packet temp = rawPackets[0];
        rawPackets.pop_front();

        rawPacketMutex.unlock();


        //Make sure we recieve data
        if(temp.recieved > 0)
        {
            //parse and push to array
            parse(&temp);
        }
    }
}