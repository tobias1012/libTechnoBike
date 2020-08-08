#include "router.hpp"

Router::Router()
{
    //make the socket listen to the bikes port
    if(socket.bind(1000)) //TODO: Find correct port to bind to
    {
        throw("failed to bind!");
    }
}