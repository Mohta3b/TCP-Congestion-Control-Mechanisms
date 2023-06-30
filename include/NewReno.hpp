#ifndef __NEWRENO_H__
#define __NEWRENO_H__

#include "./TCPConnection.hpp"

class NewReno : public TCPConnection {
    private:
        int dup_ack_count;
        int dup_ack_threshold;

    public:
        NewReno();
        ~NewReno();
        void onPacketLoss();
        void onSelectiveAck();
};

#endif /* __NEWRENO_H__ */