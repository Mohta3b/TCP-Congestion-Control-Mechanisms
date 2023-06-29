#ifndef __BRR_H__
#define __BRR_H__

#include "./TCPConnection.hpp"

class BBR : public TCPConnection {
    private:
        int dup_ack_count;
        int dup_ack_threshold;

    public:
        BBR();
        ~BBR();
        void onPacketLoss();
        void onSelectiveAck();
};

#endif