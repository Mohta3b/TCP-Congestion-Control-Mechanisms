#include "../include/Reno.hpp"

Reno::Reno()
{
    this->dup_ack_count = 0;
    this->dup_ack_threshold = 3;
}

Reno::~Reno()
{
}

void Reno::onPacketLoss()
{
    // TODO: not correct
    switch (this->controll_mode)
    {
    case Mode::SLOW_START:
        this->ssthresh = this->cwnd / 2;
        this->cwnd = 1;
        this->controll_mode = Mode::SLOW_START;
        break;
    case Mode::CONGESTION_AVOIDANCE:
        this->ssthresh = this->cwnd / 2;
        this->cwnd = 1;
        this->controll_mode = Mode::SLOW_START;
        break;
    case Mode::FAST_RECOVERY:
        this->ssthresh = this->cwnd / 2;
        this->cwnd = 1;
        this->controll_mode = Mode::SLOW_START;
        break;
        
    }
}

void Reno::onRTTUpdate(long new_rtt)
{
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
}

void Reno::congestionAvoidance()
{
    this->cwnd += 1;
}

void Reno::fastRecovery()
{
    this->cwnd /= 2;
    this->cwnd = this->ssthresh;
}
