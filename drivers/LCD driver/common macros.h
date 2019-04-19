/*
 * common macros.h
 *
 *  Created on: Mar 10, 2019
 *      Author: omar
 */

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))  /* Set a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))  /* Clear a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))  /* Toggle a certain bit in any register */


#endif /* COMMON_MACROS_H_ */
