# **ONBOARD**

## 1. INTRODUCE

## 2. DATA STRUCTURE APP LAYER

| Bit 7 to 4 | Bit 3 to 0 | Byte 1 | Byte 2 + Byte 3 | Byte 4... |
|------------|------------|--------|-----------------|-----------|
|   GROUP    |   ECU ID   |   ID   |      LENGTH     |  PAYLOAD  |

---

### **Group**
- 🟢 `0b0000` – **COMMAND**
- 🔵 `0b0001` – **RESPONSE**
- 🟡 `0b0010` – **NOTIFY**

---

### **ECU ID**
- 🖥️ `0b0000` – **HOST (S32K-Dashboard)**
- 🛠️ `0b0001` – **BOARD (S32K)**
- 📡 `0b0002` – **IC (ESP32/STM32/...)**
- ➕ … (expandable)

---

### **ID**
- 🔁 `0x00` – **echo revert**
- 🆔 `0x01` – **version**
- 🔄 `0x02` – **reset soft**
- 💡 `0x03` – **led**
- … (extend more)
