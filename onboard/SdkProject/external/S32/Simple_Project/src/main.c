#include "device_registers.h"
#include "CanDrv.h"
#include "clock_manager.h"
#include "interrupt_manager.h"
#include <string.h>
#include <stdint.h>
#include "clockMan1.h"

#define RX_MSG_BUF_SIZE 8

// ===== Clock khởi tạo cơ bản (nếu không dùng PE) =====
extern void SOSC_init_8MHz(void);
extern void SPLL_init_160MHz(void);
extern void NormalRUNmode_80MHz(void);

// ===== Buffer nhận CAN =====
static flexcan_msgbuff_t s_rxMsgBuf;
static uint8_t s_rxData[RX_MSG_BUF_SIZE];

// ===== Callback khi nhận frame CAN =====
void MyCAN_RxCallback(phDriverCan_Channel_t channel,
                      uint32_t msgId,
                      const uint8_t *data,
                      uint8_t len,
                      void *userData)
{
    // Echo lại frame nhận được
    phDriverCan_Send(channel, msgId, data, len);
}

int main(void)
{
	CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
								g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
		  CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

    // 3. Khởi tạo driver CAN
    if (phDriverCan_Init() != ERR_Ok)
    {
        while (1); // Lỗi khởi tạo → đứng lại
    }

    // 4. Gửi frame khởi động báo hiệu đã sẵn sàng
    uint8_t bootMsg[] = {0xAA, 0xBB, 0xCC};
    phDriverCan_Send(PH_CAN_CHANNEL_MAIN, 0x100, bootMsg, sizeof(bootMsg));

    // 5. Cấu hình buffer nhận và callback
    memset(&s_rxMsgBuf, 0, sizeof(s_rxMsgBuf));
    s_rxMsgBuf.dataLen = RX_MSG_BUF_SIZE;
    s_rxMsgBuf.msgId = 0x123;              // ID mong muốn nhận

    if (phDriverCan_Recv(PH_CAN_CHANNEL_MAIN, MyCAN_RxCallback, &s_rxMsgBuf, NULL) != ERR_Ok)
    {
        while (1); // Lỗi cấu hình nhận
    }

    // 6. Main loop – không cần làm gì thêm
    while (1)
    {
        // Chờ ngắt CAN gọi callback
    }
}
