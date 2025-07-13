#ifndef __PORTMACRO_H__
#define __PORTMACRO_H__ 

#include "stdint.h"
#include "stddef.h"
#include "FreeRTOSConfig.h"

/*重定义基本类型*/

#define portCHAR       char
#define portFLOAT      float
#define portDOUBLE     double
#define portSHORT      short
#define portLONG       long
#define portSTACK_TYPE uint32_t
#define portBASE_TYPE  long
	
typedef portSTACK_TYPE StackType_t;
typedef long           BaseType_t;
typedef unsigned long  UBaseType_t;


#if ( configUSE_16_BIT_TICKS == 1 )
    typedef uint16_t TickType_t;
    #define portMAX_DELAY  0XFFFF
#else
    typedef uint32_t TickType_t;
    #define portMAX_DELAY  0XFFFFFFFFUL
#endif

#endif






