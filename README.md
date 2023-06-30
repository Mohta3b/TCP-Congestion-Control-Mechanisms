# Congestion Controll Algorithms


- [Protocol](#protocol)
    - [TCP Reno](#tcp-reno)
        - [Description](#description)
        - [Test Results](#test-results) 
    - [TCP New Reno](#tcp-new-reno)
        - [Description](#description)
        - [Test Results](#test-results)
    - [BBR](#bbr)
        - [Description](#description)
        - [Test Results](#test-results)
    
- [How to use?](#how-to-use)


## Protocol

### TCP Reno
#### Description
TCP Reno is a widely used congestion control algorithm for the Transmission Control Protocol (TCP), which is the standard communication protocol used on the Internet. It is designed to manage network congestion and ensure reliable and efficient data transmission.

TCP Reno operates by using a combination of packet loss and acknowledgment (ACK) information to adjust the sending rate of data. It employs a mechanism known as "Additive Increase, Multiplicative Decrease" (AIMD) to regulate the flow of data. Initially, TCP Reno increases its sending rate linearly until it detects packet loss or congestion through the absence of ACKs. When packet loss occurs, it interprets it as a sign of network congestion and reduces its sending rate by halving the congestion window size. This reduction prevents further congestion and allows the network to recover.

Upon successful transmission and reception of packets, TCP Reno gradually increases its sending rate, adding a fixed amount to the congestion window for every ACK received. This incremental increase allows TCP Reno to probe the network for available bandwidth and maximize its utilization while avoiding congestion.

TCP Reno's adaptive nature and conservative approach make it a robust congestion control algorithm suitable for various network conditions and congestion scenarios. It has been widely deployed and forms the basis for many TCP implementations used today.

In summary, TCP Reno is a congestion control algorithm for TCP that aims to maintain efficient and reliable data transmission by dynamically adjusting the sending rate based on network conditions. Its additive increase and multiplicative decrease mechanisms help prevent congestion and optimize network performance.

#### Test Results
Start (Slow Start): TCP Reno's slow start is an initial phase where the sender gradually increases its transmission rate, probing the network for available bandwidth.
<p align="center">
<img src="https://github.com/Mohta3b/CN_CHomeworks_4/assets/86144768/c5671dbe-2442-4a70-b499-398aaaf79e77">
</p>

Congestion Avoidance: TCP Reno uses additive increase to gradually raise the sending rate, allowing for optimal bandwidth utilization while avoiding network congestion.
<p align="center">
<img src="https://github.com/Mohta3b/CN_CHomeworks_3/assets/86144768/07aa5ec7-eeab-4f72-bd21-94a50a7d4757">
</p>

Fast Recovery: In the event of packet loss, TCP Reno quickly recovers by reducing the congestion window and retransmitting lost packets, without entering a full slow start phase again.
<p align="center">
<img src="https://github.com/Mohta3b/CN_CHomeworks_4/assets/86144768/82197857-dcff-4300-87e3-e13355945a99">
</p>





### How to use?
You can run the following commands to run the program.
```text
make
./renosimulation.out
./newrenosimulation.out
./bbrsimulation.out
```
