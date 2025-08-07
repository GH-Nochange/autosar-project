#ifndef PH_TYPES_H
#define PH_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Mã lỗi trả về chuẩn
 */
typedef enum
{
    EER_OK = 0,         /**< Không lỗi */
    EER_NOTINIT,        /**< Lỗi chưa khởi tạo */
    EER_InvalidArg,     /**< Tham số truyền vào không hợp lệ */
    EER_Timeout,        /**< Hết thời gian chờ xử lý */
    EER_BUSY,           /**< Tài nguyên đang bận */
    EER_NoResource,     /**< Thiếu tài nguyên hệ thống (bộ nhớ, MB, v.v.) */
    EER_Unknown         /**< Lỗi không rõ nguyên nhân */
} PhTypes_ErrorCode_t;


#ifdef __cplusplus
}
#endif

#endif /* PH_TYPES_H */