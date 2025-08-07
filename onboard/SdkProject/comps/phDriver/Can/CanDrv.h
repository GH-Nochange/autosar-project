#ifndef CANDRV_H_
#define CANDRV_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>
#include "ph_Types.h"
#include "flexcan_driver.h"

#define PH_CAN_MAX_DLEN 8U

    /**
     * @brief Kênh CAN hiện tại đang dùng
     */
    typedef enum
    {
        PH_CAN_CHANNEL_MAIN = 0, /**< CAN channel chính (CAN0) */
        PH_CAN_CHANNEL_NUM       /**< Tổng số lượng channel (dùng cho kiểm tra/mở rộng) */
    } phDriverCan_Channel_t;


    /**
     * @brief Hàm callback khi nhận được một CAN frame.
     *
     * Được gọi trong ISR khi có frame đến, nếu đã đăng ký trước bằng phDriverCan_Recv().
     *
     * @param id        CAN ID nhận được (Standard ID - 11-bit)
     * @param data      Con trỏ tới buffer chứa dữ liệu nhận được
     * @param len       Số byte dữ liệu nhận (0–8 byte)
     * @param userData  Dữ liệu ngữ cảnh người dùng truyền vào (nếu cần, có thể là Queue hoặc context)
     */
    typedef void (*phDriverCan_RxCallback_t)(phDriverCan_Channel_t channel,
        uint32_t id,
                                             const uint8_t *data,
                                             uint8_t len,
                                             void *userData);
                                             
    typedef struct
    {
        uint8_t instance;
        uint8_t txMbIdx;
        uint8_t rxMbIdx;

        flexcan_msgbuff_t *rxFrameBuf;

        bool initialized;
        phDriverCan_RxCallback_t callback;
        void *userData;
    } phDriverCan_Config_t;


    

    /**
     * @brief Khởi tạo module CAN và toàn bộ các kênh hỗ trợ.
     *
     * Bao gồm cấu hình baudrate, MB, chế độ hoạt động, và kích hoạt ngắt nếu cần.
     *
     * @return Mã lỗi theo kiểu PhTypes_ErrorCode_t.
     */
    PhTypes_ErrorCode_t phDriverCan_Init(void);

    /**
     * @brief Giải phóng một channel CAN cụ thể.
     *
     * Dừng hoạt động, reset MB và ngắt liên quan.
     *
     * @param channel Kênh CAN cần deinit.
     * @return Mã lỗi.
     */
    PhTypes_ErrorCode_t phDriverCan_DeInitChannel(phDriverCan_Channel_t channel);

    /**
     * @brief Giải phóng toàn bộ module CAN.
     *
     * Dùng khi không cần dùng CAN nữa. Đưa về trạng thái tiết kiệm điện hoặc shutdown hệ thống.
     *
     * @return Mã lỗi.
     */
    PhTypes_ErrorCode_t phDriverCan_DeInit(void);

    /**
     * @brief Gửi một CAN frame (Standard ID, non-blocking).
     *
     * Hàm trả về ngay sau khi yêu cầu gửi, không chờ MB gửi xong.
     * Việc gửi thành công hoặc thất bại sẽ được thông báo qua ngắt nếu có cài đặt callback.
     *
     * @param channel  Kênh CAN sử dụng.
     * @param id        CAN Standard ID (11-bit).
     * @param data      Con trỏ tới buffer chứa dữ liệu cần gửi.
     * @param len       Số byte dữ liệu (tối đa 8 byte).
     * @return Mã lỗi gửi (EER_OK nếu thành công, EER_BUSY nếu MB bận, v.v.).
     */
    PhTypes_ErrorCode_t phDriverCan_Send(phDriverCan_Channel_t channel,
                                         uint32_t id,
                                         const uint8_t *data,
                                         uint8_t len);

    /**
     * @brief Đăng ký callback nhận dữ liệu CAN qua interrupt (non-blocking).
     *
     * Sau khi gọi hàm này, mỗi khi có CAN frame mới đến (Standard ID),
     * callback đã đăng ký sẽ được gọi tự động trong ISR.
     *
     * @param channel    Kênh CAN sử dụng (hiện tại chỉ hỗ trợ PH_CAN_CHANNEL_MAIN).
     * @param callback   Hàm callback xử lý dữ liệu khi nhận được frame.
     * @param rxFrameBuffer Con trỏ tới buffer nhận dữ liệu (phải được cấp phát trước).
     * @param userData   Dữ liệu ngữ cảnh (context) người dùng muốn truyền lại trong callback.
     *
     * @return Mã lỗi (EER_OK nếu đăng ký thành công).
     */
    PhTypes_ErrorCode_t phDriverCan_Recv(phDriverCan_Channel_t channel,
                                     phDriverCan_RxCallback_t callback,
                                     flexcan_msgbuff_t *rxFrameBuffer,
                                     void *userData);

#ifdef __cplusplus
}
#endif

#endif /* CANDRV_H_ */