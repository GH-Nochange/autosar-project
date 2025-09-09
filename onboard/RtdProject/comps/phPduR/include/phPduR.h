#ifndef PH_PDUR_H
#define PH_PDUR_H
/**
 * @file phPduR.h
 * @brief PDU Router (PduR) core types and APIs.
 *
 * Defines routing paths, routing tables, config structures, and
 * main PduR functions for initialization and control.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "phTypes.h"
#include "phComStack_Types.h"

/**
 * @enum PH_PDUR_t
 * @brief Supported lower-layer bus types.
 */
typedef enum
{
    PH_CAN, /**< CAN bus */
} PH_PDUR_t;

/**
 * @struct phPduR_RoutingPathType
 * @brief Single routing entry mapping SrcPduId -> DestPduId.
 */
typedef struct
{
    phPduIdType SrcPduId;   /**< Source PDU ID */
    phPduIdType DestPduId;  /**< Destination PDU ID */
    uint8_t    RouteType;   /**< If/TP routing type */
} phPduR_RoutingPathType;

/**
 * @struct phPduR_RoutingTableType
 * @brief Collection of routing paths.
 */
typedef struct
{
    const phPduR_RoutingPathType* RoutingPaths; /**< Array of paths */
    uint16_t                      NumOfRoutes;  /**< Number of entries */
} phPduR_RoutingTableType;

/**
 * @struct phPduR_PBConfigType
 * @brief Post-build config holding both If and Tp routing tables.
 */
typedef struct 
{
    const phPduR_RoutingTableType* IfRoutingTable; /**< Interface routing */
    const phPduR_RoutingTableType* TpRoutingTable; /**< Transport routing */
} phPduR_PBConfigType;

/** @typedef PduR_PBConfigIdType
 *  @brief Identifier for PduR configuration. */
typedef uint16_t PduR_PBConfigIdType;

/** @typedef phPduR_RoutingPathGroupIdType
 *  @brief Identifier for a group of routing paths. */
typedef uint16_t phPduR_RoutingPathGroupIdType;

/**
 * @enum phPduR_StateType
 * @brief State of the PduR module.
 */
typedef enum
{
    PDUR_UNINIT, /**< Not initialized */
    PDUR_ONLINE  /**< Running and ready */
} phPduR_StateType;

/**
 * @brief Initialize the PduR with a given configuration.
 * @param[in] ConfigPtr Pointer to post-build config.
 */
void phPduR_Init(const phPduR_PBConfigType *ConfigPtr);

/**
 * @brief Get current PduR configuration identifier.
 * @return phPduR_PBConfigType Current config struct.
 */
phPduR_PBConfigType phPduR_GetConfigurationId(void);

/**
 * @brief Disable routing for a given path group.
 * @param[in] id          Routing path group ID.
 * @param[in] initialize  If true, re-initialize affected routes.
 */
void phPduR_DisableRouting(phPduR_RoutingPathGroupIdType id, bool initialize);

#ifdef __cplusplus
}
#endif

#endif /* PH_PDUR_H */
