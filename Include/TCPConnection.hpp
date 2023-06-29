#ifndef __TCPCONNECTION_H__
#define __TCPCONNECTION_H__

class TCPConnection {
    protected:
        int cwnd;
        long ssthresh;
        long rtt;

    public:
        TCPConnection();
        ~TCPConnection();
        int getCwnd();
        long getSsthresh();
        long getRtt();
        void SendData();
        void onRTTUpdate(long new_rtt);
};



#endif /* __TCPCONNECTION_H__ */