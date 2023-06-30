#include <iostream>

#include "../include/TCPConnection.hpp"
#include "../include/NewReno.hpp"


#define END_TIME 500

int isPacketLoss(long cwnd)
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
    // if all acks has been sent successfully
    if (probability >= res[cwnd-2])
        return true;
    return false;
}



long RUN(NewReno &newRenoSimulator)
{
    long time = 0;

    newRenoSimulator.SendData();

    long last_ack_sent = newRenoSimulator.getCwnd();
    if(isPacketLoss(newRenoSimulator.getCwnd()))
    {
        last_ack_sent = rand() % newRenoSimulator.getCwnd() - 1;
    }
    //std::cout << "last ackckkckckc:  " << last_ack_sent << std::endl;
    newRenoSimulator.onSelectiveAck(last_ack_sent);

    long new_rtt = rand() % 5 + 5;
    newRenoSimulator.setRtt(new_rtt);
    time = newRenoSimulator.getRtt();
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
    srand(time(0));
    SimulateNewReno();
    return 0;
}