#ifndef __TWI_H
#define __TWI_H

#include "num_types.h"

#ifndef TWI_FREQ
#define TWI_FREQ (100000UL)
#endif

#ifndef TWI_BUFFER_LENGTH
#define TWI_BUFFER_LENGTH (32)
#endif

void twi_mtx_begin(u8 slave_addr);
void twi_mtx_write_byte(u8 data);
void twi_mtx_write_bytes(const u8* data, u8 length);
void twi_mtx_end(void);

#endif // __TWI_H

