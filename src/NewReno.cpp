#include "../include/NewReno.hpp"
#include <iostream>

NewReno::NewReno()
{
    this->dup_ack_count = 0;
    this->dup_ack_threshold = 3;
}

NewReno::~NewReno()
{
}

void NewReno::onSelectiveAck(int num_of_acks)
{
    if (this->cwnd < num_of_acks) 
    {
        this->ssthresh = this->cwnd/2;
    }
    switch(this->controll_mode)
    {
        case Mode::SLOW_START:
            this->slowStart(num_of_acks);
            this->printInfo();
            break;
        case Mode::CONGESTION_AVOIDANCE:
            this->congestionAvoidance();
            this->printInfo();
            break;
        case Mode::FAST_RECOVERY:
            this->fastRecoveryWithAck(num_of_acks);
            this->printInfo();
            break;
        default:
            break;
    }
}


void NewReno::slowStart(int num_of_acks)
{
    this->cwnd += num_of_acks;
    if(this->cwnd >= this->ssthresh)
    {
        this->controll_mode = Mode::CONGESTION_AVOIDANCE;
        this->printInfo();
    }                       
    
}

void NewReno::congestionAvoidance()
{
    this->cwnd += 1;
}

void NewReno::fastRecoveryWithAck(int num_of_acks)
{
    this->cwnd += num_of_acks;
    if(this->cwnd >= this->ssthresh)
    {
        this->controll_mode = Mode::CONGESTION_AVOIDANCE;
        this->printInfo();
    }
}

void NewReno::onPacketTimeout()
{
   if (this->controll_mode == Mode::FAST_RECOVERY)
   {
        this->cwnd /= 2;
        this->ssthresh = this->cwnd;
        this->controll_mode = Mode::CONGESTION_AVOIDANCE;
   }
   else if (this->controll_mode == Mode::CONGESTION_AVOIDANCE)
   {
        this->cwnd = 1;
        this->ssthresh = this->cwnd;
        this->controll_mode = Mode::SLOW_START;
   }
   else
   {
        this->ssthresh = this->cwnd/2;
        this->cwnd = 1;
   }
   this->printInfo();
}

void NewReno::onPacketLoss()
{
    if (this->controll_mode == Mode::FAST_RECOVERY)
    {
        this->cwnd /= 2;
        this->ssthresh = this->cwnd;
        this->controll_mode = Mode::CONGESTION_AVOIDANCE;
    }
    else if (this->controll_mode == Mode::CONGESTION_AVOIDANCE)
    {
        this->cwnd = 1;
        this->ssthresh = this->cwnd;
        this->controll_mode = Mode::SLOW_START;
    }
    else
    {
        this->ssthresh = this->cwnd/2;
        this->cwnd = 1;
    }
    this->printInfo();
}