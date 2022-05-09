#ifndef __PAL_COMMON_DEF_H__
#define __PAL_COMMON_DEF_H__

#define BMC_DEF_SLAVE_ADDR (0x10)

#define PWR_OPTION_LIST "status, graceful-shutdown, off, on, reset, cycle"

#define FRU_EEPROM "/sys/class/i2c-dev/i2c-%d/device/%d-00%x/eeprom"
#define MAX_NUM_FRUS    (FRU_CNT-1)
#define MAX_NODES       (2)

#define LARGEST_DEVICE_NAME (120)
#define UNIT_DIV            (1000)
#define ERR_NOT_READY       (-2)
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

#define PAGE_SIZE  0x1000
#define PREPARE_FW_UPDATE_CLEAR (0x00)
#define PREPARE_FW_UPDATE_SET   (0x01)

#define READING_SKIP    (1)
#define READING_NA      (-2)

//XDP Debug PIN
#define RST_PLTRST_BMC_N "RST_PLTRST_PLD_N"
#define IRQ_BMC_PRDY_N  "FM_DBP_BMC_PRDY_N"
#define DBP_PRESENT_N "FM_BMC_DBP_PRESENT_R_N"
#define FM_JTAG_TCK_MUX_SEL "FM_JTAG_TCK_MUX_BMC_SEL" //Choice Jtag to CPU or PCH
#define FM_BMC_PREQ_N "FM_DBP_CPU_PREQ_GF_N"
#define FM_JTAG_BMC_MUX_SEL "FM_JTAG_BMC_MUX_SEL" //Choice BMC to CPLD or BMC to CPU/PCH
#define FM_BMC_CPU_PWR_DEBUG_N "FM_BMC_CPU_FBRK_OUT_N"

//NM Device Info
#define NM_IPMB_BUS_ID             (I2C_BUS_6)
#define NM_SLAVE_ADDR              (0x2C)

enum {
  FRU_ALL = 0,
  FRU_MB,
  FRU_SWB,
  FRU_NIC0,
  FRU_NIC1,
  FRU_DBG,
  FRU_BMC,
  FRU_SCM,
  FRU_PDBV,
  FRU_PDBH,
  FRU_BP0,
  FRU_BP1,
  FRU_FIO,
  FRU_FAN0,
  FRU_FAN1,
  FRU_FAN2,
  FRU_FAN3,
  FRU_FAN4,
  FRU_FAN5,
  FRU_FAN6,
  FRU_FAN7,
  FRU_FAN8,
  FRU_FAN9,
  FRU_FAN10,
  FRU_FAN11,
  FRU_FAN12,
  FRU_FAN13,
  FRU_FAN14,
  FRU_FAN15,
  FRU_CNT,
};

enum {
  REV_PO = 0,
  REV_EVT,
  REV_DVT,
  REV_PVT,
  REV_MP,
};

// Sensors Under Side Plane
enum {
  MB_SENSOR_TBD,
};

enum{
  MEZZ_SENSOR_TBD,
};

enum {
  BOOT_DEVICE_USB      = 0x0,
  BOOT_DEVICE_IPV4     = 0x1,
  BOOT_DEVICE_HDD      = 0x2,
  BOOT_DEVICE_CDROM    = 0x3,
  BOOT_DEVICE_OTHERS   = 0x4,
  BOOT_DEVICE_IPV6     = 0x9,
  BOOT_DEVICE_RESERVED = 0xff,
};

enum {
  IPMI_CHANNEL_0 = 0,
  IPMI_CHANNEL_1,
  IPMI_CHANNEL_2,
  IPMI_CHANNEL_3,
  IPMI_CHANNEL_4,
  IPMI_CHANNEL_5,
  IPMI_CHANNEL_6,
  IPMI_CHANNEL_7,
  IPMI_CHANNEL_8,
  IPMI_CHANNEL_9,
  IPMI_CHANNEL_A,
  IPMI_CHANNEL_B,
  IPMI_CHANNEL_C,
  IPMI_CHANNEL_D,
  IPMI_CHANNEL_E,
  IPMI_CHANNEL_F,
};

enum {
  I2C_BUS_0 = 0,
  I2C_BUS_1,
  I2C_BUS_2,
  I2C_BUS_3,
  I2C_BUS_4,
  I2C_BUS_5,
  I2C_BUS_6,
  I2C_BUS_7,
  I2C_BUS_8,
  I2C_BUS_9,
  I2C_BUS_10,
  I2C_BUS_11,
  I2C_BUS_12,
  I2C_BUS_13,
  I2C_BUS_14,
  I2C_BUS_15,
  I2C_BUS_16,
  I2C_BUS_17,
  I2C_BUS_18,
  I2C_BUS_19,
  I2C_BUS_20,
  I2C_BUS_21,
  I2C_BUS_22,
  I2C_BUS_23,
  I2C_BUS_24,
  I2C_BUS_25,
  I2C_BUS_26,
  I2C_BUS_27,
  I2C_BUS_28,
  I2C_BUS_29,
  I2C_BUS_30,
  I2C_BUS_31,
  I2C_BUS_32,
  I2C_BUS_33,
  I2C_BUS_34,
  I2C_BUS_35,
  I2C_BUS_36,
  I2C_BUS_37,
  I2C_BUS_38,
  I2C_BUS_39,
  I2C_BUS_40,
  I2C_BUS_41,
  I2C_BUS_42,
  I2C_BUS_43,
  I2C_BUS_44,
  I2C_BUS_45,
  I2C_BUS_46,
  I2C_BUS_47,
  I2C_BUS_48,
  I2C_BUS_49,
  I2C_BUS_50,
  I2C_BUS_51,
  I2C_BUS_52,
  I2C_BUS_53,
  I2C_BUS_54,
  I2C_BUS_55,
  I2C_BUS_56,
  I2C_BUS_57,
  I2C_BUS_58,
  I2C_BUS_59,
  I2C_BUS_60,
};

enum {
  POSTCODE_BY_BMC,
  POSTCODE_BY_HOST,
};

enum {
  CC_OEM_DEVICE_NOT_PRESENT = 0x30,
  CC_OEM_DEVICE_INFO_ERR = 0x31,
  CC_OEM_DEVICE_DESTINATION_ERR = 0x32,
  CC_OEM_DEVICE_SEND_SLAVE_RESTORE_POWER_POLICY_FAIL =0x33,
  CC_OEM_GET_SELF_ADDRESS_ERR = 0x34,
  CC_OEM_ONLY_SUPPORT_MASTER = 0x35,
};

#endif