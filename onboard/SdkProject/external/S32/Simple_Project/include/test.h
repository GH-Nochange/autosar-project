/*
 * test.h
 *
 *  Created on: Aug 12, 2025
 *      Author: nguye
 */

#ifndef TEST_H_
#define TEST_H_

#include <stdbool.h>
#include <stdint.h>
#include "flexcan_driver.h"
#include "phTypes.h"
#include "phComStack_Types.h"


//#define CAN

void TEST_run(void);
void Test_RxIndication(const phPduInfoType * PduInfoPtr);


#endif /* TEST_H_ */
