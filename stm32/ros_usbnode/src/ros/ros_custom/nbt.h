/*
 * nbt.h
 *
 *  Created on: Jun 10, 2018
 *      Author: Itamar Eliakim
 */

#ifndef NBT_H_
#define NBT_H_
#include "main.h"
#include "stm32f_board_hal.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct{
	uint32_t timeout;
	uint32_t previousMillis;
}nbt_t;

void NBT_init(nbt_t * nbt, uint32_t interval);
bool NBT_handler(nbt_t * nbt);

#ifdef __cplusplus
}
#endif

#endif /* NBT_H_ */
