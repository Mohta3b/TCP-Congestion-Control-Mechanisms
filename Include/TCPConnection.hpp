#ifndef __TCPCONNECTION_H__
#define __TCPCONNECTION_H__

enum Mode { SLOW_START, CONGESTION_AVOIDANCE, FAST_RECOVERY };
class TCPConnection {
    protected:
        int cwnd;
        long ssthresh;
        long rtt;
        Mode controll_mode = Mode::SLOW_START;

    public:
        TCPConnection();
        TCPConnection(int cwnd, long ssthresh, long rtt);
        ~TCPConnection();
        int getCwnd();
        long getSsthresh();
        long getRtt();
        Mode getControllMode();
        void SendData();
        void onRTTUpdate(long new_rtt);
        void printInfo();
};



#endif /* __TCPCONNECTION_H__ */