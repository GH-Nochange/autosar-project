set(app_src spi.c)
set(pri_req
    "driver"
    "log"
    "freertos"
    "esp_driver_spi"
)
idf_component_register(SRCS ${app_src}
                    INCLUDE_DIRS "."
                    PRIV_REQUIRES ${pri_req}
                    REQUIRES ${pri_req}
)