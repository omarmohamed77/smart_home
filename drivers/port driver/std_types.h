/*
 * std_types.h
 * Describes the basic data types implemented in ARM C
 *  Created on: Mar 10, 2019
 *      Author: omar
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_
enum Port_PinDirectionType {PORT_PIN_IN,PORT_PIN_OUT};
enum Dio_LevelType {STD_LOW,STD_HIGH};
typedef unsigned char       uint8;   /* 0 to 255*/
typedef char                sint8;   /* -128 to 127*/
typedef unsigned short      uint16;  /* 0 to 65535*/
typedef short               sint16;  /* –32,768 to 32,767*/
typedef unsigned long       uint32;  /* 0 to 4,294,967,295*/
typedef signed long         sint32;  /* –2,147,483,648 to 2,147,483,647*/
typedef unsigned long long  uint64;
typedef signed long long    sint64;
typedef float               float32; /* floating point numbers 32bit*/
typedef double              float64;  /* floating point numbers 64bit*/
#endif /* STD_TYPES_H_ */
