#ifndef __TCPCONNECTION_H__
#define __TCPCONNECTION_H__
#include <string>
#pragma once
enum Mode { SLOW_START, CONGESTION_AVOIDANCE, FAST_RECOVERY };

class TCPConnection {
    protected:
        long cwnd;
        long ssthresh;
        long rtt;
        long sending_rate;
        Mode controll_mode = Mode::SLOW_START;

    public:
        TCPConnection();
        TCPConnection(long cwnd, long ssthresh, long rtt);
        ~TCPConnection();
        void setRtt(long new_rtt);
        long getCwnd();
        long getSsthresh();
        long getRtt();
        Mode getControllMode();
        void SendData();
        void onRTTUpdate(long new_rtt);
        void printInfo();
        std::string getMode();
};



#endif /* __TCPCONNECTION_H__ */