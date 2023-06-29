#include "./TCPConnection.hpp"

TCPConnection::TCPConnection() {
    cwnd = 1;
    ssthresh = 65535;
    rtt = 0;
}

TCPConnection::~TCPConnection() {
}

int TCPConnection::getCwnd() {
    return cwnd;
}

long TCPConnection::getSsthresh() {
    return ssthresh;
}

long TCPConnection::getRtt() {
    return rtt;
}

void TCPConnection::SendData() {
    // TODO
}

void TCPConnection::onPacketLoss() {
    // TODO
}

void TCPConnection::onRTTUpdate(long new_rtt) {
    // TODO
}

void TCPConnection::onSelectiveAck() {
    // TODO
}