#ifndef __TCPConnection_H__
#define __TCPConnection_H__

class TCPConnection {
    private:
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
        void onPacketLoss();
        void onRTTUpdate(long new_rtt);
        void onSelectiveAck(); // for New Reno
};



#endif /* __TCPConnection_H__ */