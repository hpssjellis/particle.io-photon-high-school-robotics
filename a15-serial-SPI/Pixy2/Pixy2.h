#include "TPixy2.h"
// #include "SPI.h" // ilo
#include "Arduino.h" // ilo

#define PIXY_SPI_CLOCKRATE       2000000

class Link2SPI
{
public:
  int8_t open(uint32_t arg)
  {
    SPI.begin();
    SPI.beginTransaction(SPISettings(PIXY_SPI_CLOCKRATE, MSBFIRST, SPI_MODE3));
	return 0;
  }
	
  void close()
  {
    SPI.endTransaction();
  }
    
  int16_t recv(uint8_t *buf, uint8_t len, uint16_t *cs=NULL)
  {
    uint8_t i;
    if (cs)
      *cs = 0;
    for (i=0; i<len; i++)
    {
      buf[i] = SPI.transfer(0x00);
      if (cs)
        *cs += buf[i];
    }
    return len;
  }
    
  int16_t send(uint8_t *buf, uint8_t len)
  {
    uint8_t i;
    for (i=0; i<len; i++)
      SPI.transfer(buf[i]);
    return len;
  }
};


typedef TPixy2<Link2SPI> Pixy2;

#endif
