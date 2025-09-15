
import can
import cantools
import time
import re

# ================== Default Config (NO PROMPT) ==================
PortUSB         = 'slcan'
CANchanel       = 'COM4'
TIME_OUT        = 2.0

DEFAULT_CAN_ID  = 0x123      # đổi nếu cần
DEFAULT_IS_EXT  = False      # True nếu muốn Extended ID
DEFAULT_ECU_BYTE = 0x04      # 0x04 = BOARD1 (S32K), 0x00 = IC1 (ESP32)
ECHO_PAYLOAD    = bytearray([0x11, 0x22, 0x33])  # payload cho echo
LED_VALUE       = 1          # 0 -> 7

# ===============================================================

def ConfigPortAndChanel(PortUSB, CANchanel):
    return can.interface.Bus(channel = CANchanel, interface = PortUSB)

def _parse_can_id(s: str):
    s = s.strip()
    try:
        can_id = int(s, 0)
    except ValueError:
        can_id = int(s, 16)
    if not (0 <= can_id <= 0x1FFFFFFF):
        raise ValueError("CAN ID out of range (0..0x1FFFFFFF)")
    is_ext = can_id > 0x7FF
    return can_id, is_ext

def parse_hex_bytes(s: str) -> bytearray:
    tokens = re.findall(r'0x[0-9a-fA-F]+|[0-9a-fA-F]{1,2}', s)
    vals = []
    for t in tokens:
        t = t[2:] if t.lower().startswith('0x') else t
        if len(t) == 1: t = '0' + t          # 'A' -> '0A'
        b = int(t, 16)
        if not (0 <= b <= 255):
            raise ValueError("byte out of range")
        vals.append(b)
    return bytearray(vals)

def hexstr(buf) -> str:
    return " ".join(f"{b:02X}" for b in buf)

# ================== ORIGINAL-STYLE TESTS (auto, no prompt) ==================

def echo_reverse(bus: can.Bus, can_id: int, is_ext: bool):
    frame = bytearray(5)
    frame[0] = 0x07                     # giữ nguyên như bản bạn gửi
    frame[1] = DEFAULT_ECU_BYTE         # 0x04 = BOARD1
    frame[2] = 0x00                     # id: echo_reverse
    frame[3] = 0x00
    frame[4] = 0x03                     # length = 3
    payload  = bytearray(ECHO_PAYLOAD)  # hardcode

    frame.extend(payload)

    message = can.Message(arbitration_id=can_id, is_extended_id=is_ext, dlc=len(frame), data=frame)
    bus.send(message)
    print(f"TX: {hexstr(message.data)} (ID={can_id:08X}{' Ext' if is_ext else ''}, DLC={len(frame)})")

    t_end = time.time() + TIME_OUT
    while time.time() < t_end:
        rx_msg = bus.recv(TIME_OUT)
        if rx_msg is None:
            continue
        print(f"RX: {hexstr(rx_msg.data)} (ID={rx_msg.arbitration_id:08X}{' Ext' if rx_msg.is_extended_id else ''}, DLC={rx_msg.dlc})")

        if rx_msg.data[0] != 0x07 or rx_msg.data[2] != 0x00:
            return False
        reverse    = payload[::-1]
        rx_payload = rx_msg.data[5:]
        print("Echo expect:", hexstr(reverse))
        print("Echo got   :", hexstr(rx_payload))
        return reverse == rx_payload

    print("✗ Timeout!")
    return False

def get_version(bus: can.Bus, can_id: int, is_ext: bool):
    frame = bytearray(5)
    frame[0] = 0x04           # giữ nguyên như bản bạn gửi
    frame[1] = DEFAULT_ECU_BYTE
    frame[2] = 0x01           # id: get version
    frame[3] = 0x00
    frame[4] = 0x00

    message = can.Message(arbitration_id=can_id, is_extended_id=is_ext, dlc=len(frame), data=frame)
    bus.send(message)
    print(f"TX: {hexstr(message.data)} (ID={can_id:08X}{' Ext' if is_ext else ''}, DLC={len(frame)})")

    t_end = time.time() + TIME_OUT
    while time.time() < t_end:
        rx_msg = bus.recv(TIME_OUT)
        if rx_msg is None:
            continue
        print(f"RX: {hexstr(rx_msg.data)} (ID={rx_msg.arbitration_id:08X}{' Ext' if rx_msg.is_extended_id else ''}, DLC={rx_msg.dlc})")

        if rx_msg.data[0] != 0x07 or rx_msg.data[2] != 0x01:
            return False
        if rx_msg.dlc < 8:
            return False
        print('Version: {}.{}.{}'.format(rx_msg.data[5], rx_msg.data[6], rx_msg.data[7]))
        return True

    print("✗ Timeout!")
    return False

def reset_ecu(bus: can.Bus, can_id: int, is_ext: bool):
    frame = bytearray(5)
    frame[0] = 0x04
    frame[1] = DEFAULT_ECU_BYTE
    frame[2] = 0x02     # id: reset
    frame[3] = 0x00
    frame[4] = 0x00

    message = can.Message(arbitration_id=can_id, is_extended_id=is_ext, dlc=len(frame), data=frame)
    bus.send(message)
    print(f"TX: {hexstr(message.data)} (ID={can_id:08X}{' Ext' if is_ext else ''}, DLC={len(frame)})")

    t_end = time.time() + TIME_OUT
    while time.time() < t_end:
        rx_msg = bus.recv(TIME_OUT)
        if rx_msg is None:
            continue
        print(f"RX: {hexstr(rx_msg.data)} (ID={rx_msg.arbitration_id:08X}{' Ext' if rx_msg.is_extended_id else ''}, DLC={rx_msg.dlc})")

        if rx_msg.data[0] != 0x05 or rx_msg.data[2] != 0x02:
            return False
        if rx_msg.dlc < 6:
            return False
        return rx_msg.data[5] == 0x00

    print("✗ Timeout!")
    return False

def set_led(bus: can.Bus, can_id: int, is_ext: bool):
    frame = bytearray(6)
    frame[0] = 0x05
    frame[1] = DEFAULT_ECU_BYTE
    frame[2] = 0x03      # id: led
    frame[3] = 0x00
    frame[4] = 0x01
    frame[5] = LED_VALUE 

    print("Set LED to", frame[5])

    message = can.Message(arbitration_id=can_id, is_extended_id=is_ext, dlc=len(frame), data=frame)
    bus.send(message)
    print(f"TX: {hexstr(message.data)} (ID={can_id:08X}{' Ext' if is_ext else ''}, DLC={len(frame)})")

    t_end = time.time() + TIME_OUT
    while time.time() < t_end:
        rx_msg = bus.recv(TIME_OUT)
        if rx_msg is None:
            continue
        print(f"RX: {hexstr(rx_msg.data)} (ID={rx_msg.arbitration_id:08X}{' Ext' if rx_msg.is_extended_id else ''}, DLC={rx_msg.dlc})")

        if rx_msg.data[0] != 0x05 or rx_msg.data[2] != 0x03:
            return False
        if rx_msg.dlc < 6:
            return False
        return rx_msg.data[5] == 0x00

    print("✗ Timeout!")
    return False

# ================== ONE-SHOT RUN (no input) ==================

def run_all_tests_once(bus: can.Bus, can_id: int, is_ext: bool):
    print("\n=== RUN ALL TESTS (no prompt) ===")
    summary = []

    ok = echo_reverse(bus, can_id, is_ext)
    print("ECHO_REVERSE:", "✓ Success" if ok else "✗ Failed")
    summary.append(("ECHO_REVERSE", ok))

    ok = get_version(bus, can_id, is_ext)
    print("GET_VERSION :", "✓ Success" if ok else "✗ Failed")
    summary.append(("GET_VERSION", ok))

    ok = reset_ecu(bus, can_id, is_ext)
    print("RESET      :", "✓ Success" if ok else "✗ Failed")
    summary.append(("RESET", ok))

    ok = set_led(bus, can_id, is_ext)
    print("SET_LED    :", "✓ Success" if ok else "✗ Failed")
    summary.append(("SET_LED", ok))

    print("\n=== SUMMARY ===")
    for name, res in summary:
        print(f"{name:12s} : {'OK' if res else 'FAIL'}")

def main():
    can_bus = ConfigPortAndChanel(PortUSB, CANchanel)
    can_id  = DEFAULT_CAN_ID
    is_ext  = DEFAULT_IS_EXT

    print(f"Using CAN ID={can_id:08X}{' (Extended)' if is_ext else ' (Standard)'} on {CANchanel}/{PortUSB}")
    run_all_tests_once(can_bus, can_id, is_ext)

    can_bus.shutdown()
    time.sleep(0.1)
    print("Done.")

if __name__ == "__main__":
    main()
