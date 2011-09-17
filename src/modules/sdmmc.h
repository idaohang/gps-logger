/**
 * \file sdmmc.h
 * \brief Library for handling SD/MMC memory cards
 * \author Martin Matysiak
 */

#ifndef SDMMC_H
    #define SDMMC_H

    #include "global.h"
    #include "protocols/spi.h"
    
    /// The default size of a sector on memory cards
    #define SDMMC_SECTOR_SIZE 512
    
    /// CMD0 - Change from SD into SPI mode
    #define SDMMC_GO_IDLE_STATE 0
    /// CMD1 - Initialize card
    #define SDMMC_SEND_OP_COND 1
    /// CMD17 - Read a single block
    #define SDMMC_READ_SINGLE_BLOCK 17
    /// CMD24 - Write a block
    #define SDMMC_WRITE_BLOCK 24
    
    /// Precalculated Checksum for CMD0
    #define SDMMC_GO_IDLE_STATE_CRC 0x95
    
    /// Default CRC value when in SPI mode (won't be checked)
    #define SDMMC_DEFAULT_CRC 0xFF
    
    /// Macro to convert from a sector count to a byte count
    #define SECTOR_TO_BYTE(pSector) pSector << 9 // << 9 equals * 512
    

    /**
     * \brief Initializes the SD/MMC-card. Locks the processor in case of error
     */
    void sdmmc_init();

    /**
     * \brief Writes the given data to the given sector
     *
     * Please note that writing operations can only be done in 512 byte blocks
     * as one can not change the block size on a memory card.
     *
     * \param pSectorNum an integer containing the index of the sector to which
     * the data should be written
     * \param pInput a string of characters which should be written
     * \return TRUE on success, otherwise FALSE
     */
    uint8_t sdmmc_writeSector(uint32_t pSectorNum, char* pInput);
    
    /**
     * \brief Sends a command to the SD/MMC-card
     * 
     * See http://www.sandisk.com/Assets/File/OEM/Manuals/SD_SDIO_specsv1.pdf 
     * for an overview of possible commands in SD (Apendix A) and SPI (Appendix
     * B) mode.
     *
     * \param pCommand The command which should be sent
     * \param pArgument Additional data for the command
     * \param pCrc The CRC-checksum for the given command (will be ignored if in SPI mode)
     * \return TRUE on success, otherwise FALSE
     */
    uint8_t sdmmc_writeCommand(uint8_t pCommand, uint32_t pArgument, uint8_t pCrc);

    /**
     * \brief Reads a sector from the SD/MMC-card
     *
     * Please note that reading operations can only be done in 512 byte blocks
     * as one can not change the block size on a memory card.
     *
     * \param pSectorNum an integer containing the index of the sector which
     * should be read out
     * \param pOutput A buffer to which the data will be written (make sure it's
     * at least 512 bytes large)
     * \return TRUE on success, otherwise FALSE
     */
    uint8_t sdmmc_readSector(uint32_t pSectorNum, char* pOutput);
#endif


