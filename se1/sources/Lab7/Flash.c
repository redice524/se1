#include "Flash.h"

unsigned int command[5];
unsigned int result[3];
IAP iap_entry = (IAP) IAP_LOCATION;

static unsigned int getSectorNumberFromAddr(void* Addr){
	unsigned int addr= (unsigned int) Addr;
	addr=(addr>>12)/2;
	return addr;
}

/* Apaga o conteúdo de um sector, ou de múltiplos sectores, da FLASH. Para apagar
apenas um sector, deve usar-se o mesmo número de sector para os dois parâmetros. */
unsigned int FLASH_EraseSectors(unsigned int startSector, unsigned int endSector){
	command[0]=PREPARE_SECTORS_FOR_WRITE_OPERATION;
	command[1]= startSector;
	command[2]= endSector;
	command[3]= LPC2106_CCLK/1000;
	iap_entry(command,result);
	if(result[0]== CMD_SUCESS){
		command[0]=ERASE_SECTORS;
		command[1]=startSector;
		command[2]=endSector;
		iap_entry(command,result);
	}
	return result[0];
}

/* Escreve o bloco de dados referenciado por srcAddr, de dimensão size bytes, no
endereço da FLASH referenciado por dstAddr. Pressupõe que os sectores envolvidos na
operação de escrita foram apagados previamente e que size não excede 4kB. */
unsigned int FLASH_WriteBlock( void *dstAddr, void *srcAddr, unsigned int size){
	//if(size!=256 || size!=512 || size !=1024 || size !=2048 || size!=4096) return 0;
	command[0]= PREPARE_SECTORS_FOR_WRITE_OPERATION;
	command[1]= getSectorNumberFromAddr(dstAddr);
	command[2]= getSectorNumberFromAddr(dstAddr+size);
	iap_entry(command,result);
	if(result[0]== CMD_SUCESS){
		command[0]= COPY_RAM_TO_FLASH;
		command[1]= (unsigned int)dstAddr;
		command[2]= (unsigned int)srcAddr;
		command[3]= size;
		command[4]= LPC2106_CCLK/1000;
		iap_entry(command,result);
	}
	return result[0];
}

/* Escreve o bloco de dados referenciado por srcAddr, de dimensão size bytes, no
endereço da FLASH referenciado por dstAddr. */
unsigned int FLASH_WriteData(void *dstAddr, void *srcAddr, unsigned int size){
	command[0]= PREPARE_SECTORS_FOR_WRITE_OPERATION;
	command[1]= getSectorNumberFromAddr(dstAddr);
	command[2]= getSectorNumberFromAddr(dstAddr+size);
	iap_entry(command,result);
	if(result[0]== CMD_SUCESS){
		command[0]= ERASE_SECTORS;
		command[1]= getSectorNumberFromAddr(dstAddr);
		command[2]= getSectorNumberFromAddr(dstAddr+size);
		command[3]= LPC2106_CCLK/1000;
		iap_entry(command,result);
		if(result[0]==CMD_SUCESS){	//CMD_SUCCESS
			command[0]= PREPARE_SECTORS_FOR_WRITE_OPERATION;
			command[1]= getSectorNumberFromAddr(dstAddr);
			command[2]= getSectorNumberFromAddr(dstAddr+size);
			iap_entry(command,result);
			if(result[0]== CMD_SUCESS){
				command[0]= COPY_RAM_TO_FLASH;
				command[1]= (unsigned int)dstAddr;
				command[2]= (unsigned int)srcAddr;
				command[3]= size;
				command[4]= LPC2106_CCLK/1000;
				iap_entry(command,result);
			}
		}
	}
	return result[0];
}

/* Compara o conteúdo do bloco de dados referenciado por srcAddr, de dimensão size
bytes, com o conteúdo do bloco de dados referenciado por dstAddr. */
unsigned int FLASH_VerifyData(void *dstAddr, void *srcAddr, unsigned int size){
	command[0]= COMPARE;
	command[1]= (unsigned int)dstAddr;
	command[2]= (unsigned int)srcAddr;
	command[3]= size;
	iap_entry(command,result);
	if(result[0]== COMPARE_ERROR)return result[0];
	return 0;
}


