#ifndef PACKET_H_
#define PACKET_H_




class Packet { 

  public:
    Packet();
    Packet(const Packet& rhs);
    ~Packet();
    
    // setters and getters

    //  


  private:
    // header 
    int m_srcID;
    int m_destID;
    int m_data;
    int m_timeTraversed;
    int m_TTL;
    int m_maxHops;
};

#endif
