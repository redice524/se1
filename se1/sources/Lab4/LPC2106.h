#ifndef LPC2106_h
#define LPC2106_h

/****************************************************************************\
| BASE ADDRESS DEFINITIONS FOR LPC2106
\****************************************************************************/
#define GPIO_base 0xE0028000 
#define GPIO (*((GPIO_DSC *)GPIO_base))

/****************************************************************************\
| CLOCK DEFINITIONS FOR LPC2106
\****************************************************************************/
#define LPC2106_MAIN_OSC 14745600 // Main #000000
#define LPC2106_CCLK LPC2106_MAIN_OSC // Output PLL Clock
#define LPC2106_PCLK LPC2106_CCLK/4 // Peripheral Clock

/****************************************************************************\
| TIMER'S ADDRESS DEFINITIONS FOR LPC2106
\****************************************************************************/
#define LPC2106_BASE_TC0 ( *( (LPC210X_TC *) 0xE0004000) )
#define LPC2106_BASE_TC1 ( *( (LPC210X_TC *) 0xE0008000) )

/****************************************************************************\
| I2C ADDRESS DEFINITIONS FOR LPC2106
\****************************************************************************/
#define LPC2106_I2C ( *( (LPC210X_I2C *) 0xE001C000) )

/****************************************************************************\
| PIN SELECT ADDRESS DEFINITIONS FOR LPC2106
\****************************************************************************/
#define LPC2106_PINSEL ( *( (LPC210X_PINSEL *) 0xE002C000) )



#endif
