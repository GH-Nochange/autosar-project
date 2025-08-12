set(app_src nvs_config.c)
set(pri_req
    "driver"
    "log"
    "esp_common"
    "nvs_flash"
)
idf_component_register(SRCS ${app_src}
                    INCLUDE_DIRS "."
                    PRIV_REQUIRES ${pri_req}
                    REQUIRES ${pri_req}
)