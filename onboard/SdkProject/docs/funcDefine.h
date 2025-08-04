/* ----------------------------------------------------------------------------------------- */
typedef struct
{
    ...
} phDriverGpio_PinConfig_t;
typedef struct
{
    ...
} phDriverGpio_PinLevel_t;
typedef struct
{
    ...
} phDriverGpio_IrqConfig_t;

void phDriverGpio_Init(phDriverGpio_PinConfig_t pinConfig);
void phDriverGpio_DeInit(phDriverGpio_PinConfig_t pinConfig);
void phDriverGpio_SetPinLevel(phDriverGpio_PinConfig_t pinConfig, phDriverGpio_PinLevel_t pinLevel);
phDriverGpio_PinLevel_t phDriverGpio_GetPinLevel(phDriverGpio_PinConfig_t pinConfig);
void phDriverGpio_SetInterrupt(phDriverGpio_PinConfig_t pinConfig, phDriverGpio_IrqConfig_t irqConfig);
void phDriverGpio_ClearInterrupt(phDriverGpio_IrqConfig_t irqConfig);


/* ----------------------------------------------------------------------------------------- */
typedef struct
{
    ...
} phDriverSpi_Config_t;

phTypes_ErrorCode_t phDriverSpi_Init(const uint32_t instance, const phDriverSpi_Config_t * const spiConfig);
phTypes_ErrorCode_t phDriverSpi_DeInit(const uint32_t instance);
phTypes_ErrorCode_t phDriverSpi_StartRecv(const uint32_t instance);
phTypes_ErrorCode_t phDriverSpi_Recv(const uint32_t instance, uint8_t * const recvData, const uint16_t transferLength);
phTypes_ErrorCode_t phDriverSpi_StopRecv(const uint32_t instance);
phTypes_ErrorCode_t phDriverSpi_StartTransmit(const uint32_t instance);
phTypes_ErrorCode_t phDriverSpi_Transmit(const uint32_t instance, const uint8_t * const sendData, const uint16_t transferLength);
phTypes_ErrorCode_t phDriverSpi_StopTransmit(const uint32_t instance);
phTypes_ErrorCode_t phDriverSpi_AbortTransfer(const uint32_t instance);
phTypes_ErrorCode_t phDriverSpi_SetDelay(const uint32_t instance, const uint32_t betweenByteTransfer, const uint32_t sckToPcs, const uint32_t pcsToSck);


/* Optional----------------------------------------------------------------------------------------- */
phTypes_ErrorCode_t phDriverCanTrcv_Init(void);
phTypes_ErrorCode_t phDriverCanTrcv_DeInit(void);


/* ----------------------------------------------------------------------------------------- */
typedef struct
{
    ...
} phDriverCan_Config_t;

phTypes_ErrorCode_t phDriverCan_Init(const uint32_t instance, const phDriverCan_Config_t * const canConfig);
phTypes_ErrorCode_t phDriverCan_DeInit(const uint32_t instance);
phTypes_ErrorCode_t phDriverCan_Recv(const uint32_t instance, uint8_t * const recvData);
phTypes_ErrorCode_t phDriverCan_Send(const uint32_t instance, const uint32_t msgId, const uint8_t * const sendData, const uint8_t length);

/* SF,FF,FC,CF----------------------------------------------------------------------------------------- */
phTypes_ErrorCode_t phCanTp_Init(void);
phTypes_ErrorCode_t phCanTp_DeInit(void);
phTypes_ErrorCode_t phCanTp_IncomingData(uint8_t **output);
phTypes_ErrorCode_t phCanTp_NotifyHost(uint8_t *input);
phTypes_ErrorCode_t phCanTp_ReadyToNotifyHost(void);

/* Send via CAN/SPI----------------------------------------------------------------------------------------- */
phTypes_ErrorCode_t phPduR_Init(void);
phTypes_ErrorCode_t phPduR_DeInit(void);
phTypes_ErrorCode_t phPduR_Send(uint8_t **output);
phTypes_ErrorCode_t phPduR_NotifyHost(uint8_t *input);
phTypes_ErrorCode_t phPduR_ReadyToNotifyHost(void);

/* COM----------------------------------------------------------------------------------------- */
// Send: check readyToSend? -> get queueSend -> PduRsend
// Recv: checkComingDta -> get queueRecv -> return output
