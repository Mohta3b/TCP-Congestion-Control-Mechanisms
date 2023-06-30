#ifndef __NEWRENO_H__
#define __NEWRENO_H__

#include "./TCPConnection.hpp"

class NewReno : public TCPConnection {
    private:
        int dup_ack_count;
        int dup_ack_threshold;
        int packet_loss_count_on_window;

    public:
        NewReno();
        ~NewReno();
        void onSelectiveAck(int num_of_acks);
        void onPacketTimeout();
        void onPacketLoss();
        void slowStart(int num_of_acks);
        void congestionAvoidance();
        void fastRecoveryWithAck(int num_of_acks);
};

#endif /* __NEWRENO_H__ */