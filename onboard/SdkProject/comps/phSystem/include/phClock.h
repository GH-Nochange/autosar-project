#ifndef PH_CLOCKS_H_
#define PH_CLOCKS_H_

void SOSC_init_8MHz (void);
void SPLL_init_160MHz (void);
void NormalRUNmode_80MHz (void);
void WDOG_disable (void);

#endif /* PH_CLOCKS_H_ */
