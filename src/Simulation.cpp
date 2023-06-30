#include <iostream>

#include "../include/TCPConnection.hpp"
#include "../include/Reno.hpp"
#include "../include/NewReno.hpp"


#define END_TIME 1000

int RUN(Reno &renoSimulator)
{
    // randomly choose one of the following actions
    // 1. SendData and onRTTUpdate
    // 2. onPacketLoss
    // odds of choosing action 0 is 0.8
    // odds of choosing action 1 is 0.2
    int action = rand() % 5;
    int time = 0;
    if(action < 4)
    {
        renoSimulator.SendData();
        time = renoSimulator.getRtt();
        // choose rtt randomly between 5 and 10
        renoSimulator.setRtt(rand() % 5 + 5);
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
    int TIME = 0;
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

int RUN(NewReno &newRenoSimulator)
{
    // randomly choose one of the following actions
    // 1. SendData and onSelectiveAck
    // 2. onPacketTimeout
    // 3. onPacketLoss
    // odds of choosing action 0 is 0.6
    // odds of choosing action 1 is 0.2
    // odds of choosing action 2 is 0.2
    int action = rand() % 5;
    int time = 0;
    if(action < 3)
    {
        newRenoSimulator.SendData();
        time = newRenoSimulator.getRtt();
        // choose rtt randomly between 5 and 10
        newRenoSimulator.setRtt(rand() % 5 + 5);
    }
    else if(action == 3)
    {
        newRenoSimulator.onPacketTimeout();
        time = newRenoSimulator.getRtt();
    }
    else
    {
        newRenoSimulator.onPacketLoss();
        time = newRenoSimulator.getRtt();
    }
    return time;
}
void SimulateNewReno()
{
    int TIME = 0;
    std::cout << "TCP NewReno Simulation" << std::endl;
    std::cout << "Simulation Started!" << std::endl << std::endl;
    NewReno newRenoSimulator = NewReno();
    newRenoSimulator.setRtt(5);
    while(TIME < END_TIME)
    {
        TIME += RUN(newRenoSimulator);
    }
    std::cout << std::endl << "Simulation Ended!" << std::endl;
}


int main()
{
    SimulateReno();
    SimulateNewReno();
    return 0;
}