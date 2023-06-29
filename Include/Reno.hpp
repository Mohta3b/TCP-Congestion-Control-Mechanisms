#ifndef __RENO_H__
#define __RENO_H__

#include "./TCPConnection.hpp"
// define three modes : 1.slow start 2.congestion avoidance 3.fast recovery
enum Mode { SLOW_START, CONGESTION_AVOIDANCE, FAST_RECOVERY };

class Reno : public TCPConnection {
    private:
        int dup_ack_count;
        int dup_ack_threshold;
        Mode controll_mode = Mode::SLOW_START;

    public:
        Reno();
        ~Reno();
        void onPacketLoss();
        void onRTTUpdate(long new_rtt = -1);
        void slowStart();
        void congestionAvoidance();
        void fastRecovery();
};



#endif