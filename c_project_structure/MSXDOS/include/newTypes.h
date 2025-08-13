// newtypes v1.2 - 21march2018
#ifndef  __NEWTYPES_H__
#define  __NEWTYPES_H__


#ifndef  NULL
#define  NULL  ((void *) 0)
#endif

// boolean
#ifndef _BOOLEAN
#define _BOOLEAN
  typedef enum {false = 0, true = 1} boolean;	// or if you prefer you can rename it to bool
#endif

#ifndef _SWITCHER
#define _SWITCHER
  typedef enum {OFF = 0, ON = 1} switcher;
#endif

#ifndef _CONFIRMATION
#define _CONFIRMATION
  typedef enum {NO = 0, YES = 1} confirmation;
#endif

//OK CANCEL


// unsigned integer
#ifndef _UINT
#define _UINT
  typedef unsigned int uint;
#endif

// unsigned char
//#ifndef _BYTE
//#define _BYTE
//  typedef unsigned char byte;
//#endif

//definiciones de A.Herrera 
//http://msx.atlantes.org/index_es.html
//#ifndef _INT8
//#define _INT8
//  typedef signed char int8;
//#endif
//typedef unsigned char uint8;
//typedef signed int int16_t;
//typedef unsigned int uint16_t;
//typedef signed long int32_t;
//typedef unsigned long uint32_t;
//typedef float float32;

#endif