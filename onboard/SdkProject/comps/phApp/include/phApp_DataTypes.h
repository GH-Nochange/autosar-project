typedef struct {
    uint16_t id;         
    uint16_t length;                      
} phApp_DataTypes_t;

typedef struct {
    phApp_header_t id;                  
    uint8_t payload[PAYLOAD_SIZE]; 
} phApp_DataTypes_t;