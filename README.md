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
- [Questions]
    - [Question 1](#question-1)
    - [Question 2](#question-2)
    - [Question 3](#question-3)
    - [Question 4](#question-4)
    - [Question 5](#question-5)
    - [Question 6](#question-6)

    
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


### TCP New Reno
#### Description
TCP New Reno is a modification of TCP Reno that improves its performance in the event of multiple packet losses. It is designed to address the problem of "retransmission ambiguity" in TCP Reno, where the sender cannot distinguish between a timeout and multiple packet losses. This ambiguity causes TCP Reno to enter a full slow start phase, which can significantly reduce network performance.

TCP New Reno solves this problem by using a mechanism known as "Fast Recovery" to quickly recover from multiple packet losses. It does this by maintaining a "partial ACK" counter that tracks the number of ACKs received for the same sequence number. When the counter reaches three, TCP New Reno assumes that the receiver has received all packets up to that sequence number and retransmits the next packet. This allows TCP New Reno to recover from multiple packet losses without entering a full slow start phase.

#### Test Results
Start (Slow Start): TCP New Reno's slow start is an initial phase where the sender gradually increases its transmission rate, probing the network for available bandwidth.
<p align="center">
<img src="https://github.com/Mohta3b/CN_CHomeworks_4/assets/86144768/05965545-104f-406f-8f95-d05d65643dfd">
</p>

Congestion Avoidance: TCP New Reno uses additive increase to gradually raise the sending rate, allowing for optimal bandwidth utilization while avoiding network congestion.
<p align="center">
<img src="https://github.com/Mohta3b/CN_CHomeworks_4/assets/86144768/58f950e5-3b39-4333-84a0-78ea7a733809">
</p>

Fast Recovery: In the event of packet loss, TCP New Reno quickly recovers by retransmitting lost packets, without entering a full slow start phase again.
<p align="center">
<img src="https://github.com/Mohta3b/CN_CHomeworks_4/assets/86144768/8692b23f-9005-4f3d-a815-33e32a30c777">
</p>

More test results is shown in the following images.
![image](https://github.com/Mohta3b/CN_CHomeworks_4/assets/86144768/2712b363-b3b6-4ab0-ad88-9bcaff399a69)
![image](https://github.com/Mohta3b/CN_CHomeworks_4/assets/86144768/9da511e1-9451-4bc6-b574-c59c0033c490)


### BBR
#### Description
BBR is a congestion control algorithm for TCP that aims to maximize network utilization and minimize queuing delay. It is designed to address the problem of "bufferbloat", where large buffers cause excessive queuing delay and reduce network performance.

BBR uses a combination of packet loss and round-trip time (RTT) information to adjust the sending rate of data. It employs a mechanism known as "Model-Based Control" to regulate the flow of data. Initially, BBR increases its sending rate linearly until it detects packet loss or congestion through the absence of ACKs. When packet loss occurs, it interprets it as a sign of network congestion and reduces its sending rate by halving the congestion window size. This reduction prevents further congestion and allows the network to recover.

Upon successful transmission and reception of packets, BBR gradually increases its sending rate, adding a fixed amount to the congestion window for every ACK received. This incremental increase allows BBR to probe the network for available bandwidth and maximize its utilization while avoiding congestion.

#### Test Results
Initialization: BBR's initialization phase is an initial phase where the sender gradually increases its transmission rate, probing the network for available bandwidth.
<p align="center">
<img src="">
</p>

Startup Phase: BBR's startup phase is an initial phase where the sender gradually increases its transmission rate, probing the network for available bandwidth.
<p align="center">
<img src="">
</p>

Drain Phase: BBR's drain phase is an initial phase where the sender gradually increases its transmission rate, probing the network for available bandwidth.
<p align="center">
<img src="">
</p>

Probe Bandwidth: BBR's probe bandwidth phase is an initial phase where the sender gradually increases its transmission rate, probing the network for available bandwidth.

<p align="center">
<img src="">
</p>


## Questions
### Question 1
Congestion control and flow control are two distinct concepts in networking that aim to manage data transmission within a network. Here's a summary of the differences between them:

1. Congestion Control:
Congestion control is a mechanism used to regulate the flow of data when the network becomes overloaded or congested. It prevents network congestion by ensuring that the amount of traffic sent into the network does not exceed its capacity to handle it effectively. Congestion control algorithms monitor the network conditions, such as packet loss and delays, and adjust the transmission rate accordingly to maintain optimal network performance. The objective of congestion control is to prevent or minimize congestion-related issues, such as packet loss, increased delays, and degraded network performance.

2. Flow Control:
Flow control, on the other hand, deals with regulating the data flow between a sender and receiver to ensure that the receiver can handle the incoming data at a rate it can process. It is typically implemented at the receiving end to prevent overwhelming the receiver with data that it cannot handle. Flow control mechanisms utilize techniques like buffering, acknowledgments, and sliding window protocols to manage the rate at which data is transmitted. The goal of flow control is to maintain a balance between the sender and receiver, preventing data loss and avoiding overflow or underflow of data at the receiving end.

In summary, congestion control focuses on managing network congestion by adjusting transmission rates based on network conditions, while flow control focuses on regulating the data flow between a sender and receiver to prevent overwhelming the receiver. Both mechanisms play crucial roles in optimizing network performance and ensuring reliable data transmission.

![image](https://github.com/Mohta3b/CN_CHomeworks_4/assets/86144768/ac079df9-27e1-46d7-a645-7886ed74ce5e)
### Question 2
Already described in [TCP New Reno](#tcp-new-reno) section.
![image](https://github.com/Mohta3b/CN_CHomeworks_4/assets/86144768/19dbd152-7229-49f0-8223-a49e72e3942c)
### Question 3
Already described in [BBR](#bbr) section.
![image](https://github.com/Mohta3b/CN_CHomeworks_4/assets/86144768/138485ca-6201-405a-b2ee-a177d55fa602)
![image](https://github.com/Mohta3b/CN_CHomeworks_4/assets/86144768/a6ae3c4f-0a09-4c36-8a1c-0c8cc03357da)
### Question 4
Reno and New Reno are traditional TCP congestion control algorithms that rely on packet loss and timeouts to detect and respond to network congestion. New Reno improves upon Reno's slow recovery by introducing a fast recovery mechanism. On the other hand, BBR is a newer algorithm that focuses on maximizing throughput and minimizing delays by estimating bandwidth and RTT. BBR's model-based approach allows it to be more aggressive in utilizing network capacity while maintaining low latency.



### Question 5
It can be said that NewReno is always better than Reno, but we cannot say anything seriously about comparing BBR with Reno, and we have to consider different criteria. And in different situations, one is superior to the other and is not fixed. For example, in the following images, we can see that BBR is better than Reno in terms of throughput, but in terms of delay, Reno is better than BBR.

![image](https://github.com/Mohta3b/CN_CHomeworks_4/assets/86144768/990b0e2d-527c-4dc3-a9b5-609c180e9b8f)
![image](https://github.com/Mohta3b/CN_CHomeworks_4/assets/86144768/ebc4a031-3717-46d6-9a6d-cf02fef64513)

### Question 6
1. Binary Increase Congestion control (BIC): BIC is optimized for high-speed networks with 
high latency, also known as long fat networks (LFNs). It was the default congestion 
control algorithm in Linux kernels 2.6.8 through 2.6.18 en.wikipedia.org.
2. CUBIC: This is the default congestion control algorithm in the Linux kernel starting from 
version 2.6.19. CUBIC is a less aggressive and more systematic derivative of BIC, making 
it more suitable for networks with high bandwidth and high latency en.wikipedia.org.
3. Token Bucket Algorithm: It is a control algorithm that indicates when traffic should be 
sent. This order comes based on the display of tokens in the bucket. When tokens are 
shown, a flow to transmit traffic appears in the display of tokens geeksforgeeks.org.
4. TCP Vegas: This algorithm emphasizes packet delay, rather than packet loss, as the signal 
to help detect congestion. It's designed to be more efficient and fair than algorithms that 
rely solely on packet loss en.wikipedia.org.
5. TCP Tahoe: This algorithm was one of the first congestion control algorithms 
implemented in TCP. It uses three primary mechanisms to handle congestion: slow start, 
congestion avoidance, and fast retransmit. When packet loss occurs, TCP Tahoe reduces 
the congestion window size and enters the slow start phase, effectively reducing the 
sending rate en.wikipedia.org.

### How to use?
You can run the following commands to run the program.
```text
make
./renosimulation.out
./newrenosimulation.out
./bbrsimulation.out
```
