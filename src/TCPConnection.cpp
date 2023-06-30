#include <iostream>
#include "../include/TCPConnection.hpp"

TCPConnection::TCPConnection()
{
    cwnd = 1;
    ssthresh = 65535;
    rtt = 0;
}

TCPConnection::TCPConnection(long cwnd, long ssthresh, long rtt)
{
    this->cwnd = cwnd;
    this->ssthresh = ssthresh;
    this->rtt = rtt;
}

TCPConnection::~TCPConnection()
{
}

long TCPConnection::getCwnd()
{
    return cwnd;
}

void TCPConnection::setRtt(long new_rtt)
{
    this->rtt = new_rtt; 
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
    this->sending_rate = this->getCwnd();
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
    std::cout << "controll mechanism: " << this->getMode() << std::endl;
    std::cout << "----------------------" << std::endl;
}

std::string TCPConnection::getMode(){
    if (controll_mode == Mode::SLOW_START)
        return "SLOW START";
    else if (controll_mode == Mode::CONGESTION_AVOIDANCE)
        return "CONGESTION AVOIDANCE";
    else if (controll_mode == Mode::FAST_RECOVERY)
        return "FAST RECOVERY";
    return "UNKNOWN";
}

