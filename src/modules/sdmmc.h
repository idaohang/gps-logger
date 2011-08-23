/**
  ########## gLogger Mini ##########
    
	Von Martin Matysiak
	    mail@k621.de
      www.k621.de

  SDMMC - Eine Befehlsbibliothek zum Umgang mit Speicherkarten

  ########## Licensing ##########

  Please take a look at the LICENSE file for detailed information.
*/


#ifndef SDMMC_H
  #define SDMMC_H

  #include "global.h"
  #include "protocols/spi.h"
  
  uint8_t sdmmc_init();

  uint8_t sdmmc_writeSector(uint32_t pSectorNum, char* pInput, uint16_t pByteCount);
  uint8_t sdmmc_writeCommand(uint8_t pCommand, uint32_t pArgument, uint8_t pCrc);

  uint8_t sdmmc_readSector(uint32_t pSectorNum, char* pOutput, uint16_t pByteCount);
#endif


