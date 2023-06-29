#include <iostream>
#include "./TCPConnection.hpp"

TCPConnection::TCPConnection()
{
    cwnd = 1;
    ssthresh = 65535;
    rtt = 0;
}

TCPConnection::~TCPConnection()
{
}

int TCPConnection::getCwnd()
{
    return cwnd;
}

long TCPConnection::getSsthresh()
{
    return ssthresh;
}

long TCPConnection::getRtt()
{
    return rtt;
}

void TCPConnection::SendData()
{
    int sending_rate = getCwnd() ? (getCwnd() < getSsthresh()) : getSsthresh();
    for (int i = 0; i < sending_rate; i++)
    {
        std::cout << "Sending packet " << i << std::endl;
    }
    std::cout << "Sending rate: " << sending_rate << std::endl;
}


