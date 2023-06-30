#ifndef __NEWRENO_H__
#define __NEWRENO_H__

#include "./TCPConnection.hpp"

class NewReno : public TCPConnection {
    private:
        int dup_ack_count;
        int dup_ack_threshold;
        int packet_loss_count_on_window;
        long last_partial_ack_received;
        long last_partial_ack_expected; // number of data that cause tcp reno to exit fast recovery

    public:
        NewReno();
        ~NewReno();
        void onSelectiveAck(long last_ack_sent);
        void onPacketTimeout();
        void onPacketLoss();
        void slowStart();
        void congestionAvoidance();
        void fastRecoveryWithAck();
};

#endif /* __NEWRENO_H__ */