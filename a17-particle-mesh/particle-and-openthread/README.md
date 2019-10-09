Any information that might help convert particle devices to openthread or the other way round



udp commands

Node A

> udp open                                
Done

udp send ff02::1 1234 {"name":"fred","age":"40"}
Done

Node B:

> udp open

Done

> udp bind :: 1234

Done

26 bytes from fe80:0:0:0:b459:6368:a779:b6df 49154 {"name":"fred","age":"40"}



    static const uint16_t PORT = 36969;
    
    static constexpr const char* MULTICAST_ADDR = "ff03::1:1001";
    
    static const uint16_t MAX_PACKET_LEN = 1232;



{"type":"mySendToAll","data":"1"}
