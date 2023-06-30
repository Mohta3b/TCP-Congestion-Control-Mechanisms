#include "../include/BBR.hpp"
#include <iostream>
// implement the BBR algorithm
// rate = cwnd / RTT ==> BW = rate * RTT
int maxBWCap = 1000;
const int minRTT = 10;
const int MaxRound = 100;
enum State {
    STARTUP,
    DRAIN,
    PROBE_BANDWIDTH,
    PROBE_RTT
};
class BBR
{
private:
  /* data */
  State state = STARTUP;
  int cur_rtt=10;
  int sending_rate=10;
  int bandwidth_max=0;
public:
  // startup phase:
  void startup(int cur_bw)
  {
    // increase
    if (cur_bw > bandwidth_max) {
      bandwidth_max = cur_bw;
      // Double the sending rate each round-trip time
      sending_rate *= 2;
    } 
    if(cal_bw() > maxBWCap) {
      // call drain phase
      state = DRAIN;
      drain();
    }
  }

  int cal_bw() {
    return sending_rate * cur_rtt;
  }

  // drain phase:
  void drain()
  {
    // decrease the whole cwnd and therfore the sending rate
    // approximately by 1/2 after each round-trip time
    sending_rate /= 2;
    if(cal_bw() <= maxBWCap) {
      state = PROBE_BANDWIDTH;
    }
  }
  
  // probe bandwidth phase:
  void probe_bw()
  {
    // increase the sending rate by 25% each round-trip time
    sending_rate *= 1.25;
     if(cal_bw() > maxBWCap) {
      // call drain phase
      state = DRAIN;
      drain();
     }
  }
  
  // probe RTT phase:
  void probe_rtt()
  {
    // decrease the sending rate by 1/8 each round-trip time
    sending_rate /= 8;
  }

  void run() {
    bool flag_change = false;
    int cur_bw = 0;
    for (int i = 0; i < MaxRound; i++) {
      // change Rtt and BW
      // change MaxBWCap
      if (i % 20 == 0) {
        maxBWCap = rand() % 10000;
      }
      cur_bw = cal_bw();
      switch (state) {
        case STARTUP:
          startup(cur_bw);
          break;
        case DRAIN:
          drain();
          break;
        case PROBE_BANDWIDTH:
          probe_bw();
          break;
      }

      //  probe_rtt();

    }
  }

};



int main() {
    BBR bbr;
    bbr.run();
    return 0;
}
