#include <iostream>

#include "../include/TCPConnection.hpp"
#include "../include/Reno.hpp"

#define END_TIME 1000

void Simulate()
{
    // TODO
    int TIME = 0;
    std::cout << "Simulate Started" << std::endl;
    Reno renoSimulator = Reno();
    renoSimulator.setRtt(5);
    while(TIME < END_TIME)
    {
        
        
        
    }
    
}

int main()
{
    Simulate();
    return 0;
}