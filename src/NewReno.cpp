#include "../include/NewReno.hpp"
#include <iostream>

NewReno::NewReno()
{
    this->dup_ack_count = 0;
    this->dup_ack_threshold = 3;
    this->last_partial_ack_expected = this->cwnd;
    this->next_packet_to_be_sent = 0;
    this->controll_mode = Mode::SLOW_START;
}

NewReno::~NewReno()
{
}

void NewReno::onSelectiveAck(long last_ack_received_from_reciever)
{
    long last_ack_received = last_ack_received_from_reciever + this->getNextPacketToBeSent();
    this->next_packet_to_be_sent = last_ack_received;
    std::cout << "Last ACK Expected: " << last_partial_ack_expected << "  Last ACK Received:  " << last_ack_received << std::endl;
    
    if (last_ack_received >= this->last_partial_ack_expected)
    {
        this->dup_ack_count = 0;
        this->last_partial_ack_expected = last_ack_received + this->cwnd;
        this->packet_loss_count_on_window = 0;
        if (this->getControllMode() == Mode::FAST_RECOVERY)
            this->controll_mode = Mode::CONGESTION_AVOIDANCE;
    }
    else
    {
        this->dup_ack_count++;
        if (this->getControllMode() == Mode::FAST_RECOVERY)
        {
            if (this->dup_ack_count == this->dup_ack_threshold)
            {
                this->onPacketLoss();
            }
        }
        else
        {
            this->onPacketLoss();
        }
    }

    if (this->controll_mode == Mode::FAST_RECOVERY && this->packet_loss_count_on_window == 0)
    {
        this->fastRecoveryWithAck();
    }
    else if (this->controll_mode == Mode::SLOW_START)
    {
        this->slowStart();
    }
    else if (this->controll_mode == Mode::CONGESTION_AVOIDANCE)
    {
        this->congestionAvoidance();
    }
    printInfo();
    
}


void NewReno::slowStart()
{
    this->cwnd *= 2;
    if (this->cwnd >= this->ssthresh)
    {
        this->controll_mode = Mode::CONGESTION_AVOIDANCE;
        std::cout << "Congestion Avoidance mechanism activated!" << std::endl;
    }
    
}

void NewReno::congestionAvoidance()
{
    this->cwnd += 1;
    
}

void NewReno::fastRecoveryWithAck()
{
    this->cwnd /= 2;
    this->ssthresh = this->cwnd;
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
   std::cout << "Packet Timed Out!" << std::endl;
   this->printInfo();
}

void NewReno::onPacketLoss()
{
    std::cout << "\033[1;31mPacket Loss:  " << this->next_packet_to_be_sent << "\033[0m" <<std::endl;

    this->packet_loss_count_on_window++;
    if (this->controll_mode == Mode::FAST_RECOVERY)
    {
        this->cwnd /= 2;
        this->ssthresh = this->cwnd;
        this->controll_mode = Mode::CONGESTION_AVOIDANCE;
        std::cout << "Congestion mechanism activated!" << std::endl;

    }
    else if (this->controll_mode == Mode::CONGESTION_AVOIDANCE)
    {
        this->controll_mode = Mode::FAST_RECOVERY;
        std::cout << "Fast Recovery mechanism activated!" << std::endl;

    }
    else
    {
        this->ssthresh = this->cwnd/2;
        this->cwnd = 1;
        this->controll_mode = Mode::SLOW_START;
        std::cout << "Slow Start mechanism activated!" << std::endl;

    }
    this->printInfo();
}