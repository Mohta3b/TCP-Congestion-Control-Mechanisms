#include <iostream>
#include "./TCPConnection.hpp"

TCPConnection::TCPConnection()
{
    cwnd = 1;
    ssthresh = 65535;
    rtt = 0;
}

TCPConnection::TCPConnection(int cwnd, long ssthresh, long rtt)
{
    this->cwnd = cwnd;
    this->ssthresh = ssthresh;
    this->rtt = rtt;
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

Mode TCPConnection::getControllMode()
{
    return controll_mode;
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

void TCPConnection::printInfo()
{
    std::cout << "----------------------" << std::endl;
    std::cout << "cwnd: " << this->getCwnd() << std::endl;
    std::cout << "ssthresh: " << this->getSsthresh() << std::endl;
    std::cout << "rtt: " << this->getRtt() << std::endl;
    std::cout << "controll mechanism: " << this->getControllMode() << std::endl;
    std::cout << "----------------------" << std::endl;
}


