#include <avr/io.h>
#include <avr/power.h>
#include <util/twi.h>

#include "../inc/num_types.h"
#include "../inc/twi.h"

// static u8 twi_slarw;
// static u8 twi_buffer[TWI_BUFFER_LENGTH];
// static u8 twi_buffer_length;

static void twi_enable(void);
static void twi_start(void);
static void twi_send_slarw(u8 slarw);
static void twi_stop(void);
static void twi_write(u8 data);
static void twi_disable(void);

static void twi_enable(void)
{
	// TODO Enable pullups
	power_twi_enable();			// Power up TWI module

	TWSR &= ~(_BV(TWPS0) | _BV(TWPS1)); 	// Prescaler = 1
	TWBR = ((F_CPU / TWI_FREQ) - 16) / 2; 	// Set bit rate
	// TODO Enable interrupts TWIE
	TWCR = _BV(TWEN) | _BV(TWEA); 		// Enable TWI & ACK
}

static void twi_disable(void)
{
	// TODO Disable pullups
	// TODO Disable interrupts
	TWCR &= ~(_BV(TWEN) | _BV(TWEA));	// Disable TWI & ACK
	power_twi_disable();			// Power down TWI module
}

static void twi_start(void)
{
	// Send START
	TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN) | _BV(TWEA);
	loop_until_bit_is_set(TWCR, TWINT); 	// Wait for START to complete

	if (TW_START != TW_STATUS) { 		// Ensure valid start
		// ERROR
	}
}

static void twi_send_slarw(u8 twi_slarw)
{
	TWDR = twi_slarw;  			// Prepare SLA+R/~W
	TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWEA); // Send device address
	loop_until_bit_is_set(TWCR, TWINT); 	// Wait for TX to complete

	if (TW_MT_SLA_ACK != TW_STATUS) { 	// Ensure address acknowledged
		// ERROR
	}
}

static void twi_stop(void)
{
	// Send stop
	TWCR = _BV(TWINT) | _BV(TWSTO) | _BV(TWEN) | _BV(TWEA);

	// NOTE TWINT not set after stop condition
}

static void twi_write(u8 data)
{
	TWDR = data; 				// Load data into data register
	TWCR = _BV(TWINT) | _BV(TWEN); 		// Send data
	loop_until_bit_is_set(TWCR, TWINT); 	// Wait for TX to complete

	if (TW_MT_DATA_ACK != TW_STATUS) { 	// Ensure data acknowledged
		// ERROR
	}
}

void twi_mtx_begin(u8 slave_addr)
{
	u8 twi_slarw = (slave_addr << 1) | TW_WRITE;

	twi_enable();
	twi_start();
	twi_send_slarw(twi_slarw);
}

void twi_mtx_write_byte(u8 data)
{
	twi_write(data);
}

void twi_mtx_write_bytes(const u8* data, u8 length)
{
	for (u8 i = 0; i < length; ++i) {
		twi_write(data[i]);
	}
}

void twi_mtx_end(void)
{
	twi_stop();
	twi_disable();
}

// TODO use interrupt instead of polling,
// 	or enum with parameter selection!
// ISR(TWI_vect)
// {
// }

