#include <stdint.h>
#include "miros.h"
#include "bsp.h"

uint32_t stack_blinky1[40];
OSThread blinky1;
void main_blinky1() {
    while (1) {
			  BSP_ledRedOff();
        BSP_ledBlueOff();
        BSP_ledGreenOn();
    }
}

uint32_t stack_blinky2[40];
OSThread blinky2;
void main_blinky2() {
    while (1) {
				BSP_ledRedOff();
        BSP_ledBlueOn();
			  BSP_ledGreenOff();
    }
}

uint32_t stack_blinky3[40];
OSThread blinky3;
void main_blinky3() {
    while (1) {
        BSP_ledGreenOff();
        BSP_ledRedOn();
			  BSP_ledBlueOff();
    }
}

uint32_t stack_idleThread[40];

int main() {
    BSP_init();
    OS_init(stack_idleThread, sizeof(stack_idleThread));

    /* start blinky1 thread */
    OSThread_start(&blinky1,
                    20, 2, 5,
                   &main_blinky1,
                   stack_blinky1, sizeof(stack_blinky1));

    /* start blinky2 thread */
    OSThread_start(&blinky2,
                    5, 3, 4,
                   &main_blinky2,
                   stack_blinky2, sizeof(stack_blinky2));

    /* start blinky3 thread */
    OSThread_start(&blinky3,
									  2, 6, 9,
                   &main_blinky3,
                   stack_blinky3, sizeof(stack_blinky3));

    /* transfer control to the RTOS to run the threads */
    OS_run();

    //return 0;
}
