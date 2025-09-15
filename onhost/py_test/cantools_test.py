from email import message
from turtle import done
import can
import cantools
import time
import re

PortUSB = 'slcan'
CANchanel = 'COM4'
TIME_OUT = 2

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

def prompt_id():
    while True:
        try:
            id = input("ID: ")
            can_id, is_ext = _parse_can_id(id)
            
            if is_ext:
                ans = input("This ID is Extended. Do you want to re-enter another ID? [y/N]: ").strip().lower()
                if ans in ("y", "yes"):
                    continue   
            return can_id, is_ext  
        except Exception as e:
            print(f"✗ Error: {e}")
    
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
 
def echo_reverse(bus: can.Bus, can_id: int, is_ext: bool):
    frame = bytearray(5)
    
    # len = input("Length: ").strip()
    frame[0] = 0x07 # PCI
    while True:
        print("\n===ECU_ID===")
        print("1) BOARD 1 (S32K)")
        print("2) IC 1 (ESP32)")
        ecu = input("Select: ").strip()
        if ecu == "1": # Group & ECU
            frame[1] = 0x04
        elif ecu == "2":
            frame[1] = 0x00
        else:
            print("Invalid selection!")
            continue
        break
    
    frame[2] = 0x00 # id: echo_reverse
    frame[3] = 0x00 # length
    frame[4] = 0x03 # length
        
    data = input("Enter payload: ")
    payload = parse_hex_bytes(data)
    frame.extend(payload)
    
    message = can.Message(arbitration_id=can_id, is_extended_id = is_ext, dlc = 8, data=frame)
    
    bus.send(message)
    print(f"Send: {message}")
    while True:
        rx_msg = bus.recv(TIME_OUT)
        if rx_msg is None:
            print("✗ Timeout!")
            return False
        if rx_msg:
            if rx_msg.data[0] != 0x07 or rx_msg.data[2] != 0x00:
                return False
            reverse = payload[::-1]
            rx_payload = rx_msg.data[5:]
            print(list(rx_payload))
            if reverse == rx_payload:
                return True
            else:
                return False
                
def get_version(bus: can.Bus, can_id: int, is_ext: bool):
    frame = bytearray(5)
    
    frame[0] = 0x04 # PCI
    while True:
        print("\n===ECU_ID===")
        print("1) BOARD 1 (S32K)")
        print("2) IC 1 (ESP32)")
        ecu = input("Select: ").strip()
        if ecu == "1": # Group & ECU
            frame[1] = 0x04
        elif ecu == "2":
            frame[1] = 0x00
        else:
            print("Invalid selection!")
            continue
        break
    
    frame[2] = 0x01 # id: get version
    frame[3] = 0x00 # length
    frame[4] = 0x00 # length
    
    message = can.Message(arbitration_id=can_id, is_extended_id = is_ext, dlc = 5, data=frame)
    
    bus.send(message)
    print(f"Send: {message}")
    while True:
        rx_msg = bus.recv(TIME_OUT)
        if rx_msg is None:
            print("✗ Timeout!")
            return False
        if rx_msg:
            if rx_msg.data[0] != 0x07 or rx_msg.data[2] != 0x01:
                return False
            print('Version: {}.{}.{}'.format(rx_msg.data[5], rx_msg.data[6], rx_msg.data[7]))
            return True
    
def reset_ecu(bus: can.Bus, can_id: int, is_ext: bool):
    frame = bytearray(5)
    
    frame[0] = 0x04 # PCI
    while True:
        print("\n===ECU_ID===")
        print("1) BOARD 1 (S32K)")
        print("2) IC 1 (ESP32)")
        ecu = input("Select: ").strip()
        if ecu == "1": # Group & ECU
            frame[1] = 0x04
        elif ecu == "2":
            frame[1] = 0x00
        else:
            print("Invalid selection!")
            continue
        break
    
    frame[2] = 0x02 # id: reset
    frame[3] = 0x00 # length
    frame[4] = 0x00 # length
    
    message = can.Message(arbitration_id=can_id, is_extended_id = is_ext, dlc = 5, data=frame)
    
    bus.send(message)
    print(f"Send: {message}")
    while True:
        rx_msg = bus.recv(TIME_OUT)
        if rx_msg is None:
            print("✗ Timeout!")
            return False
        if rx_msg:
            if rx_msg.data[0] != 0x05 or rx_msg.data[2] != 0x02:
                return False
            if rx_msg.data[5] == 0x00:
                return True
            else:
                return False

def set_led(bus: can.Bus, can_id: int, is_ext: bool):
    frame = bytearray(6)
    
    frame[0] = 0x05 # PCI
    while True:
        print("\n===ECU_ID===")
        print("1) BOARD 1 (S32K)")
        print("2) IC 1 (ESP32)")
        ecu = input("Select: ").strip()
        if ecu == "1": # Group & ECU
            frame[1] = 0x04
        elif ecu == "2":
            frame[1] = 0x00
        else:
            print("Invalid selection!")
            continue
        break
    
    frame[2] = 0x03 # id: led
    frame[3] = 0x00 # length 
    frame[4] = 0x01 # length
    frame[5] = int(input("Value: "))
    print("Set LED to", frame[5])
    
    message = can.Message(arbitration_id=can_id, is_extended_id = is_ext, dlc = 6, data=frame)
    
    bus.send(message)
    print(f"Send: {message}")
    while True:
        rx_msg = bus.recv(TIME_OUT)
        if rx_msg is None:
            print("✗ Timeout!")
            return False
        if rx_msg:
            if rx_msg.data[0] != 0x05 or rx_msg.data[2] != 0x03:
                return False
            if rx_msg.data[5] == 0x00:
                return True
            else:
                return False

def menu_loop(bus: can.Bus, can_id: int, is_ext: bool):
    result = None
    
    while True:
        print("\n=== Test Menu ===")
        print("1) ECHO_REVERSE")
        print("2) GET_VERSION")
        print("3) RESET")
        print("4) SET_LED")
        print("0) Thoát")

        choice = input("Select: ").strip()
        
        match choice:
            case "1":
                result = echo_reverse(bus, can_id, is_ext)
            case "2":
                result = get_version(bus, can_id, is_ext)
            case "3":
                result = reset_ecu(bus, can_id, is_ext)
            case "4":
                result = set_led(bus, can_id, is_ext)
            case "0" | "q" | "quit" | "exit":
                bus.shutdown()                 
                time.sleep(0.1) 
                print("Bye!")
                break
            case _:
                print("invalid selection")
        if result is True:  
            print("✓ Success")
        elif result is False:
            print("✗ Failed")

def main():
    can_bus = ConfigPortAndChanel(PortUSB, CANchanel)
    can_id, is_ext = prompt_id()
    # ID & length
    
    
    menu_loop(can_bus, can_id, is_ext)

if __name__ == "__main__":
    main()
