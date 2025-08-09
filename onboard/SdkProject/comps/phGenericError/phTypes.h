#ifndef PH_TYPES_H
#define PH_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    PH_ERR_OK = 0,
    PH_ERR_NOT_INIT,
    PH_ERR_FAILED,
    PH_ERR_INVALID_ARG,
    PH_ERR_TIMEOUT,
    PH_ERR_BUSY,
    PH_ERR_NO_RESOURCE,
    PH_ERR_UNKNOWN
} PhTypes_ErrorCode_t;



#ifdef __cplusplus
}
#endif

#endif /* PH_TYPES_H */