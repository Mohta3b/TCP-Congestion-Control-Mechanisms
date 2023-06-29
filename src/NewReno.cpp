#include "../include/NewReno.hpp"

NewReno::NewReno()
{
    this->dup_ack_count = 0;
    this->dup_ack_threshold = 3;
}

NewReno::~NewReno()
{
}

void NewReno::onPacketLoss()
{
    this->dup_ack_count = 0;
    this->dup_ack_threshold = 3;
    this->cwnd = this->ssthresh / 2;
    this->ssthresh = this->cwnd;
}

void NewReno::onSelectiveAck()
{
    this->dup_ack_count = 0;
    this->dup_ack_threshold = 3;
    this->cwnd = this->ssthresh;
}