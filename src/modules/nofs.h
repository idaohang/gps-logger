/**
  ########## gLogger Mini ##########
    
	Von Martin Matysiak
	    mail@k621.de
      www.k621.de

  NoFS - NoFileSystem - Eine Art, das Speichermedium im RAW-Modus
  zu beschreiben, mit automatischer Erkennung der letzten Schreib-
  position, um Datenverlust zu verhindern. Nach Au�en sind nur
  Schreib-Methoden verf�gbar, es handelt sich also um eine Art
  "WOM" (Write-Only-Memory).

  ########## Licensing ##########

  Please take a look at the LICENSE file for detailed information.
*/


#ifndef NOFS_H
  #define NOFS_H

  /// Die Gr��e des NoFS-Buffers (entspricht einer Sektorgr��e)
  #define NOFS_BUFFER_SIZE 512 
  /// Der Buffer wird nur alle N "writeString" Befehle auf SD geschrieben, um die Zellen zu schonen
  #define NOFS_WRITE_BUFFER_AFTER_NTH_COMMAND 10

  #include "global.h"
  #include "modules/sdmmc.h"
  
  uint8_t nofs_init();

  uint8_t nofs_writeString(char* pString);
#endif


