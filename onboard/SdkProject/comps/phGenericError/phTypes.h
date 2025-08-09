#ifndef PH_TYPES_H
#define PH_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    PH_ERR_OK = 0,             /*!< Thành công */
    PH_ERR_NOT_INIT,           /*!< Chưa khởi tạo */
    PH_ERR_FAILED,             /*!< Thất bại chung */
    PH_ERR_INVALID_ARG,        /*!< Tham số không hợp lệ */
    PH_ERR_INVALID_STATE,      /*!< Trạng thái không hợp lệ */
    PH_ERR_TIMEOUT,            /*!< Hết thời gian chờ */
    PH_ERR_BUSY,               /*!< Đang bận */
    PH_ERR_NO_RESOURCE,        /*!< Hết tài nguyên (RAM/Queue/Buffer) */
    PH_ERR_UNKNOWN,            /*!< Lỗi không xác định */

    PH_ERR_ALREADY_INIT,       /*!< Đã khởi tạo trước đó */
    PH_ERR_UNSUPPORTED,        /*!< Không được hỗ trợ */
    PH_ERR_OUT_OF_RANGE,       /*!< Vượt quá giới hạn hợp lệ */
    PH_ERR_EMPTY,              /*!< Rỗng (buffer/queue) */
    PH_ERR_FULL,               /*!< Đầy (buffer/queue) */
    PH_ERR_OVERFLOW,           /*!< Tràn dữ liệu */
    PH_ERR_UNDERFLOW,          /*!< Thiếu dữ liệu để xử lý */
    PH_ERR_ABORTED,            /*!< Thao tác bị hủy giữa chừng */
    PH_ERR_NOT_FOUND           /*!< Không tìm thấy dữ liệu/tài nguyên */
} PhTypes_ErrorCode_t;



#ifdef __cplusplus
}
#endif

#endif /* PH_TYPES_H */