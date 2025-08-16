#ifndef PH_PDUR_H
#define PH_PDUR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "phTypes.h"
#include "phComStack_Types.h"

typedef enum
{
    PH_CAN,
} PH_PDUR_t;

typedef struct
{
    phPduIdType SrcPduId;   
    phPduIdType DestPduId;  
    uint8_t    RouteType;  
} phPduR_RoutingPathType;

typedef struct
{
    const phPduR_RoutingPathType* RoutingPaths; 
    uint16_t                      NumOfRoutes;  
} phPduR_RoutingTableType;

typedef struct 
{
    const phPduR_RoutingTableType* IfRoutingTable; 
    const phPduR_RoutingTableType* TpRoutingTable; 
} phPduR_PBConfigType;

typedef uint16_t PduR_PBConfigIdType;

typedef uint16_t phPduR_RoutingPathGroupIdType;

typedef enum
{
    PDUR_UNINIT,
    PDUR_ONLINE
} phPduR_StateType;

void phPduR_Init(const phPduR_PBConfigType *ConfigPtr);
phPduR_PBConfigType phPduR_GetConfigurationId(void);
void phPduR_DisableRouting(phPduR_RoutingPathGroupIdType id, bool initialize);


#ifdef __cplusplus
}
#endif

#endif /* PH_PDUR_H */