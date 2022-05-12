/*
 * I2C_program.c
 *
 *  Created on: Aug 29, 2021
 *      Author: Radwa
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include"DIO_reg.h"
#include"DIO_interface.h"
#include"I2C_reg.h"
#include"I2C_interface.h"



void I2C_voidMasterInit(void)
{
	TWBR = 0x02;
	TWCR = (1<<TWEN);
	TWSR = 0x00;
}


void I2C_voidSlaveInit(u8 SlaveAddress)
{
	TWAR=SlaveAddress;		             /* Assign Address in TWI address register */
	TWCR=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);/* Enable TWI, Enable ack generation */
}


u8 I2C_u8StartCondition(u8 write_address)
{
	    u8 status;		/* Declare variable */
	    TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT); /* Enable TWI, generate START */
	    while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
	    status=TWSR&0xF8;		/* Read TWI status register */
	    if(status!=0x08)		/* Check weather START transmitted or not? */
	    return 0;			/* Return 0 to indicate start condition fail */
	    TWDR=write_address;		/* Write SLA+W in TWI data register */
	    TWCR=(1<<TWEN)|(1<<TWINT);	/* Enable TWI & clear interrupt flag */
	    while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
	    status=TWSR&0xF8;		/* Read TWI status register */
	    if(status==0x18)		/* Check for SLA+W transmitted &ack received */
	    return 1;			/* Return 1 to indicate ack received */
	    if(status==0x20)		/* Check for SLA+W transmitted &nack received */
	    return 2;			/* Return 2 to indicate nack received */
	    else
	    return 3;			/* Else return 3 to indicate SLA+W failed */
}


void I2C_voidWriteSLA(u8 SlaveAddress)
{
	TWDR = SlaveAddress;
	TWCR = TWCR=(1<<TWEN)|(1<<TWINT);
	while(GET_BIT(TWCR,TWINT)==0);
}


u8 I2C_u8WriteData(u8 data)
{
    u8 status;		/* Declare variable */
    TWDR=data;			/* Copy data in TWI data register */
    TWCR=(1<<TWEN)|(1<<TWINT);	/* Enable TWI and clear interrupt flag */
    while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
    status=TWSR&0xF8;		/* Read TWI status register */
    if(status==0x28)		/* Check for data transmitted &ack received */
    return 0;			/* Return 0 to indicate ack received */
    if(status==0x30)		/* Check for data transmitted &nack received */
    return 1;			/* Return 1 to indicate nack received */
    else
    return 2;			/* Else return 2 for data transmission failure */
}


void I2C_voidStop(void)
{
    TWCR=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN); /* Enable TWI, generate stop */
    while(TWCR&(1<<TWSTO));	              /* Wait until stop condition execution */
}


u8 I2C_u8ReadAck(void)
{
    TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA); /* Enable TWI, generation of ack */
    while(!(TWCR&(1<<TWINT)));	         /* Wait until TWI finish its current job */
    return TWDR;			             /* Return received data */
}
