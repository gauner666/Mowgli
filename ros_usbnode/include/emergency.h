#ifndef __EMERGENCY_H
#define __EMERGENCY_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint8_t Emergency_State(void);
void Emergency_SetState(uint8_t new_emergency_state);
int Emergency_Tilt(void);
int Emergency_StopButtonYellow(void);
int Emergency_StopButtonWhite(void);
int Emergency_WheelLiftBlue(void);
int Emergency_WheelLiftRed(void);
int Emergency_LowZAccelerometer(void);
void EmergencyController(void);
void Emergency_Init(void);

#ifdef __cplusplus
}
#endif

#endif  /* __EMERGENCY_H */