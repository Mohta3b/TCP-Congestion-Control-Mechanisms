#include <iostream>

#include "../include/TCPConnection.hpp"
#include "../include/Reno.hpp"
#include "../include/NewReno.hpp"


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

int calcNumberofAcks(long cwnd)
{
    long res[cwnd+1];
    long cwnd_power2 = (cwnd^2);
    long prob_sum = 0;
    long temp = 0;
    for (int i = 1; i <= cwnd; i++)
    {
        temp = i^2;
        res[i-1] = temp;
        prob_sum += (temp);
    }
    long probability = rand() % prob_sum;
    for (int i = 0; i < cwnd-1; i++)
    {
        std::cout << "sum: " <<prob_sum << "  res[i] : "<< res[i] << std::endl;
        if (probability >= res[i] && probability <= res[i+1])
        {
            return i+1;
        }
    }
    return cwnd;
}

long RUN(NewReno &newRenoSimulator)
{
    // randomly choose one of the following actions
    // 1. SendData and onSelectiveAck
    // 2. onPacketTimeout
    // 3. onPacketLoss
    // odds of choosing action 0 is 0.8
    // odds of choosing action 1 is 0.1
    // odds of choosing action 2 is 0.1
    int action = rand() % 10;
    long time = 0;

    
    int number_of_acks = calcNumberofAcks(newRenoSimulator.getCwnd());
    if(action < 8)
    {
        newRenoSimulator.SendData();
        time = newRenoSimulator.getRtt();
        
        newRenoSimulator.onSelectiveAck(number_of_acks);
        // choose rtt randomly between 5 and 10
        newRenoSimulator.setRtt(rand() % 5 + 5);
    }
    else if(action == 9)
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
    long TIME = 0;
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
    // SimulateReno();
    SimulateNewReno();
    return 0;
}