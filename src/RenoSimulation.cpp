#include <iostream>

#include "../include/TCPConnection.hpp"
#include "../include/Reno.hpp"

#define END_TIME 500

long RUN(Reno &renoSimulator)
{
    // randomly choose one of the following actions
    // 1. SendData and onRTTUpdate
    // 2. onPacketLoss
    // odds of choosing action 0 is 0.9
    // odds of choosing action 1 (packet loss) is 0.1
    int action = rand() % 50;
    long time = 0;
    if(action < 45)
    {
        renoSimulator.SendData();
        time = renoSimulator.getRtt();
        // choose rtt randomly between 5 and 10
        long new_rtt = rand() % 5 + 5;
        renoSimulator.setRtt(new_rtt);
        renoSimulator.onRTTUpdate(new_rtt);
    }
    else
    {
        renoSimulator.onPacketLoss();
        time = renoSimulator.getRtt();
    }
    return time;
}

void SimulateReno()
{
    long TIME = 0;
    std::cout << "TCP Reno Simulation" << std::endl;
    std::cout << "Simulation Started!" << std::endl << std::endl;
    Reno renoSimulator = Reno();
    renoSimulator.setRtt(5);
    while(TIME < END_TIME)
    {
        TIME += RUN(renoSimulator);
    }
    std::cout << std::endl << "Simulation Ended!" << std::endl;
    
}


int main()
{
    srand(time(0));
    SimulateReno();
    return 0;
}