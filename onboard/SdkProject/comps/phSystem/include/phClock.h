#ifndef PH_CLOCKS_H_
#define PH_CLOCKS_H_

#include "clock.h"

// Total number of clock configurations.
#define CLOCK_MANAGER_CONFIG_CNT 1U


// Number of peripheral clock configurations in index 0.
#define NUM_OF_PERIPHERAL_CLOCKS_0 18U

// Total number of user-defined clock callbacks.
#define CLOCK_MANAGER_CALLBACK_CNT 0U

void phClockInit(void);

#endif /* PH_CLOCKS_H_ */
