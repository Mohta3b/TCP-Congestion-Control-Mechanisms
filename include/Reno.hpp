#ifndef __RENO_H__
#define __RENO_H__

#include "./TCPConnection.hpp"

class Reno : public TCPConnection {
    private:
        int dup_ack_count;
        int dup_ack_threshold;

    public:
        Reno();
        ~Reno();
        void onPacketLoss();
        void onRTTUpdate(long new_rtt);
        void slowStart();
        void congestionAvoidance();
        void fastRecovery();
};



#endif