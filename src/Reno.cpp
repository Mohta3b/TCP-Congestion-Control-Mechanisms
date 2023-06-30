#include <iostream>
#include "../include/Reno.hpp"

Reno::Reno()
{
    this->dup_ack_count = 0;
    this->dup_ack_threshold = 3;
    this->controll_mode = Mode::SLOW_START;
    this->next_packet_to_be_sent = 0;
}

Reno::~Reno()
{
}

void Reno::onPacketLoss()
{
    switch (this->controll_mode)
    {
    case Mode::SLOW_START:
        this->ssthresh = this->cwnd / 2;
        this->cwnd = 1;
        this->controll_mode = Mode::SLOW_START;
        std::cout << "Slow start mechanism activated!" << std::endl;
        this->printInfo();
        break;
    case Mode::CONGESTION_AVOIDANCE:
        this->controll_mode = Mode::FAST_RECOVERY;
        std::cout << "Fast recovery mechanism activated!" << std::endl;
        this->printInfo();
        this->onPacketLoss();
        break;
    case Mode::FAST_RECOVERY:
        this->cwnd /= 2;
        this->ssthresh = this->cwnd;
        this->controll_mode = Mode::SLOW_START;
        std::cout << "Slow start mechanism activated!" << std::endl;
        this->printInfo();
        break;
    }
}

void Reno::onRTTUpdate(long new_rtt)
{
    this->next_packet_to_be_sent += this->getCwnd();
    this->rtt = new_rtt;
    switch (this->controll_mode)
    {
    case Mode::SLOW_START:
        this->slowStart();
        break;
    case Mode::CONGESTION_AVOIDANCE:
        this->congestionAvoidance();
        break;
    case Mode::FAST_RECOVERY:
        this->fastRecovery();
        break;
    default:
        break;
    }
}

void Reno::slowStart()
{
    this->cwnd *= 2;
    std::cout << "cwnd in slow start: " << this->cwnd << std::endl;
    if (this->cwnd >= this->ssthresh)
    {
        this->controll_mode = Mode::CONGESTION_AVOIDANCE;
        this->cwnd = this->ssthresh;
        std::cout << "Congestion avoidance mechanism activated!" << std::endl;
        this->printInfo();
    }
}

void Reno::congestionAvoidance()
{
    this->cwnd += 1;
}

void Reno::fastRecovery()
{
    this->cwnd /= 2;
    this->ssthresh = this->cwnd;
}
