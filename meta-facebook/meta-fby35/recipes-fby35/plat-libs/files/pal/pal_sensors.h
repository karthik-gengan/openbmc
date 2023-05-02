#ifndef __PAL_SENSORS_H__
#define __PAL_SENSORS_H__

#include <openbmc/obmc_pal_sensors.h>

#define MAX_SENSOR_NUM         (0xFF)
#define MAX_DEVICE_NAME_SIZE   (128)

//AMD1278 CMD INFO
#define PMBUS_PMON_CONFIG  (0xD4)
#define ADM1278_SLAVE_ADDR (0x80)
#define ADM1278_RSENSE     (0.5)
#define ADM1278_PEAK_IOUT  (0xD0)
#define ADM1278_PEAK_PIN   (0xDA)

//LTC4286 CMD INFO
#define LTC4286_SLAVE_ADDR (0x80)
#define LTC4286_MFR_IOUT_MAX (0xFE03)
#define LTC4286_MFR_PIN_MAX (0xFE0B)

//MP5990 CMD INFO
#define MP5990_SLAVE_ADDR  (0x80)
#define MP5990_PEAK_IOUT   (0xA6)
#define MP5990_PEAK_PIN    (0xA3)

//LTC4286 CMD INFO
#define LTC4287_MFR_IOUT_MAX (0xFE03)
#define LTC4287_MFR_PIN_MAX  (0xFE0B)

//PMBus
#define PMBUS_PAGE         (0x00)
#define PMBUS_VOUT_MODE    (0x20)
#define PMBUS_VOUT_COMMAND (0x21)
#define PMBUS_READ_VIN     (0x88)
#define PMBUS_READ_IIN     (0x89)
#define PMBUS_READ_VOUT    (0x8B)
#define PMBUS_READ_IOUT    (0x8C)
#define PMBUS_READ_TEMP1   (0x8D)
#define PMBUS_READ_TEMP2   (0x8E)
#define PMBUS_READ_POUT    (0x96)
#define PMBUS_READ_PIN     (0x97)
#define PMBUS_CMD_LEN_MAX (2)
#define PMBUS_RESP_LEN_MAX (255)

#define HSC_OUTPUT_CUR_UC_THRESHOLD 0xA7
#define HSC_INPUT_PWR_UC_THRESHOLD 0xD2

#define DPV2_EFUSE_RLOAD      14000
#define DPV2_EFUSE_SLAVE_ADDR 0x50

#define MEDUSA_HSC_LTC4282_ADDR 0x44
#define MEDUSA_HSC_ADM1272_ADDR 0x1f
#define MEDUSA_HSC_LTC4287_ADDR 0x11

#define MEDUSA_ADC_LTC2992_ADDR 0x6e
#define MEDUSA_ADC_INA238_PSU_ADDR 0x44
#define MEDUSA_ADC_INA238_GND_ADDR 0x41

#define DELTA_1_PDB_ADDR 0xC0
#define DELTA_2_PDB_ADDR 0xC2
#define RNS_PDB_ADDR 0xB4
#define FLEX_1_PDB_ADDR 0xC0
#define FLEX_2_PDB_ADDR 0xC2

#define DELTA_MFR_ID_LENGTH 6

typedef struct {
  float lnr_thresh;
  float lcr_thresh;
  float lnc_thresh;
  float unc_thresh;
  float ucr_thresh;
  float unr_thresh;
  float pos_hyst;
  float neg_hyst;
} PAL_SENSOR_THRESHOLD;

typedef struct {
  char* snr_name;
  uint8_t id;
  int (*read_sensor) (uint8_t id, float *value);
  uint8_t stby_read;
  PAL_SENSOR_THRESHOLD snr_thresh;
  uint8_t units;
} PAL_SENSOR_MAP;

struct EIN_INFO {
  uint64_t energy;
  uint64_t rollover;
  uint64_t sample;
};

typedef struct {
  uint8_t cmd;
  uint8_t ein_resp_len;
  const struct EIN_INFO wrap_info;
  uint8_t energy_offset_start;
  uint8_t rollover_offset_start;
  uint8_t sample_offset_start;
  struct EIN_INFO ein_info;
  float ein_coefficient;
} HSC_EIN_MAP;

enum {
  UNSET_UNIT = 0,
  TEMP = 1,
  CURR,
  VOLT,
  FAN,
  PERCENT,
  POWER,
};

//Sensor Table
enum {
  //BIC - temperature sensors
  BIC_SENSOR_INLET_TEMP = 0x1,
  BIC_SENSOR_OUTLET_TEMP = 0x2,
  BIC_SENSOR_FIO_TEMP = 0x3,
  BIC_SENSOR_PCH_TEMP = 0x4,
  BIC_SENSOR_CPU_TEMP = 0x5,
  BIC_SENSOR_DIMMA0_TEMP = 0x6,
  BIC_SENSOR_DIMMC0_TEMP = 0x7,
  BIC_SENSOR_DIMMD0_TEMP = 0x9,
  BIC_SENSOR_DIMME0_TEMP = 0xA,
  BIC_SENSOR_DIMMG0_TEMP = 0xB,
  BIC_SENSOR_DIMMH0_TEMP = 0xC,
  BIC_SENSOR_M2A_TEMP = 0xD,
  BIC_SENSOR_HSC_TEMP = 0xE,
  BIC_SENSOR_VCCIN_VR_TEMP = 0xF,
  BIC_SENSOR_FIVRA_VR_TEMP = 0x10,
  BIC_SENSOR_EHV_VR_TEMP = 0x11,
  BIC_SENSOR_VCCD_VR_TEMP = 0x12,
  BIC_SENSOR_FAON_VR_TEMP = 0x13,
  BIC_SENSOR_CPU_THERM_MARGIN = 0x14,
  BIC_SENSOR_CPU_TJMAX = 0x15,

  //BIC - voltage sensors
  BIC_SENSOR_P12V_STBY_VOL = 0x20,
  BIC_SENSOR_P3V_BAT_VOL = 0x21,
  BIC_SENSOR_P3V3_STBY_VOL = 0x22,
  BIC_SENSOR_P1V8_STBY_VOL = 0x23,
  BIC_SENSOR_P1V05_PCH_STBY_VOL = 0x24,
  BIC_SENSOR_P5V_STBY_VOL = 0x25,
  BIC_SENSOR_P12V_DIMM_VOL = 0x26,
  BIC_SENSOR_P1V2_STBY_VOL = 0x27,
  BIC_SENSOR_P3V3_M2_VOL = 0x28,
  BIC_SENSOR_HSC_INPUT_VOL = 0x29,
  BIC_SENSOR_VCCIN_VR_VOL = 0x2A,
  BIC_SENSOR_FIVRA_VR_VOL = 0x2C,
  BIC_SENSOR_EHV_VR_VOL = 0x2D,
  BIC_SENSOR_VCCD_VR_VOL = 0x2E,
  BIC_SENSOR_FAON_VR_VOL = 0x2F,

  //BIC - current sensors
  BIC_SENSOR_HSC_OUTPUT_CUR = 0x30,
  BIC_SENSOR_VCCIN_VR_CUR = 0x31,
  BIC_SENSOR_FIVRA_VR_CUR = 0x32,
  BIC_SENSOR_EHV_VR_CUR = 0x33,
  BIC_SENSOR_VCCD_VR_CUR = 0x34,
  BIC_SENSOR_FAON_VR_CUR = 0x35,

  //BIC - power sensors
  BIC_SENSOR_CPU_PWR = 0x38,
  BIC_SENSOR_HSC_INPUT_PWR = 0x39,
  BIC_SENSOR_VCCIN_VR_POUT = 0x3A,
  BIC_SENSOR_HSC_INPUT_AVGPWR = 0x3B,
  BIC_SENSOR_FIVRA_VR_POUT = 0x3C,
  BIC_SENSOR_EHV_VR_POUT = 0x3D,
  BIC_SENSOR_VCCD_VR_POUT = 0x3E,
  BIC_SENSOR_FAON_VR_POUT = 0x3F,
  BIC_SENSOR_DIMMA_PMIC_Pout = 0x1E,
  BIC_SENSOR_DIMMC_PMIC_Pout = 0x1F,
  BIC_SENSOR_DIMMD_PMIC_Pout = 0x36,
  BIC_SENSOR_DIMME_PMIC_Pout = 0x37,
  BIC_SENSOR_DIMMG_PMIC_Pout = 0x42,
  BIC_SENSOR_DIMMH_PMIC_Pout = 0x47,

  //BIC - Halfdome temperature sensors
  BIC_HD_SENSOR_MB_INLET_TEMP = 0x01,
  BIC_HD_SENSOR_MB_OUTLET_TEMP = 0x02,
  BIC_HD_SENSOR_FIO_TEMP = 0x03,
  BIC_HD_SENSOR_CPU_TEMP = 0x04,
  BIC_HD_SENSOR_DIMMA_TEMP = 0x05,
  BIC_HD_SENSOR_DIMMB_TEMP = 0x06,
  BIC_HD_SENSOR_DIMMC_TEMP = 0x07,
  BIC_HD_SENSOR_DIMME_TEMP = 0x08,
  BIC_HD_SENSOR_DIMMG_TEMP = 0x09,
  BIC_HD_SENSOR_DIMMH_TEMP = 0x0A,
  BIC_HD_SENSOR_DIMMI_TEMP = 0x0B,
  BIC_HD_SENSOR_DIMMK_TEMP = 0x0C,
  BIC_HD_SENSOR_SSD_TEMP = 0x0D,
  BIC_HD_SENSOR_HSC_TEMP = 0x0E,
  BIC_HD_SENSOR_CPU0_VR_TEMP = 0x0F,
  BIC_HD_SENSOR_SOC_VR_TEMP = 0x10,
  BIC_HD_SENSOR_CPU1_VR_TEMP = 0x11,
  BIC_HD_SENSOR_PVDDIO_VR_TEMP = 0x12,
  BIC_HD_SENSOR_PVDD11_VR_TEMP = 0x13,

  //BIC - Halfdome voltage sensors
  BIC_HD_SENSOR_P12V_STBY_VOL = 0x14,
  BIC_HD_SENSOR_PVDD18_S5_VOL = 0x15,
  BIC_HD_SENSOR_P3V3_STBY_VOL = 0x16,
  BIC_HD_SENSOR_PVDD11_S3_VOL = 0x17,
  BIC_HD_SENSOR_P3V_BAT_VOL = 0x18,
  BIC_HD_SENSOR_PVDD33_S5_VOL = 0x19,
  BIC_HD_SENSOR_P5V_STBY_VOL = 0x1A,
  BIC_HD_SENSOR_P12V_MEM_1_VOL = 0x1B,
  BIC_HD_SENSOR_P12V_MEM_0_VOL = 0x1C,
  BIC_HD_SENSOR_P1V2_STBY_VOL = 0x1D,
  BIC_HD_SENSOR_P3V3_M2_VOL = 0x1E,
  BIC_HD_SENSOR_P1V8_STBY_VOL = 0x1F,
  BIC_HD_SENSOR_HSC_INPUT_VOL = 0x20,
  BIC_HD_SENSOR_CPU0_VR_VOL = 0x21,
  BIC_HD_SENSOR_SOC_VR_VOL = 0x22,
  BIC_HD_SENSOR_CPU1_VR_VOL = 0x23,
  BIC_HD_SENSOR_PVDDIO_VR_VOL = 0x24,
  BIC_HD_SENSOR_PVDD11_VR_VOL = 0x25,

  //BIC - Halfdome current sensors
  BIC_HD_SENSOR_HSC_OUTPUT_CUR = 0x26,
  BIC_HD_SENSOR_CPU0_VR_CUR = 0x27,
  BIC_HD_SENSOR_SOC_VR_CUR = 0x28,
  BIC_HD_SENSOR_CPU1_VR_CUR = 0x29,
  BIC_HD_SENSOR_PVDDIO_VR_CUR = 0x2A,
  BIC_HD_SENSOR_PVDD11_VR_CUR = 0x2B,

  //BIC - Halfdome power sensors
  BIC_HD_SENSOR_HSC_INPUT_PWR = 0x2C,
  BIC_HD_SENSOR_CPU0_VR_PWR = 0x2D,
  BIC_HD_SENSOR_SOC_VR_PWR = 0x2E,
  BIC_HD_SENSOR_CPU1_VR_PWR = 0x2F,
  BIC_HD_SENSOR_PVDDIO_VR_PWR = 0x30,
  BIC_HD_SENSOR_PVDD11_VR_PWR = 0x31,
  BIC_HD_SENSOR_CPU_PWR = 0x32,
  BIC_HD_SENSOR_DIMMA_PWR = 0x33,
  BIC_HD_SENSOR_DIMMB_PWR = 0x34,
  BIC_HD_SENSOR_DIMMC_PWR = 0x35,
  BIC_HD_SENSOR_DIMME_PWR = 0x36,
  BIC_HD_SENSOR_DIMMG_PWR = 0x37,
  BIC_HD_SENSOR_DIMMH_PWR = 0x38,
  BIC_HD_SENSOR_DIMMI_PWR = 0x39,
  BIC_HD_SENSOR_DIMMK_PWR = 0x3A,

  //BIC - greatlakes temperature sensors
  BIC_GL_SENSOR_MB_INLET_TEMP_C = 0x1,
  BIC_GL_SENSOR_MB_OUTLET_TEMP_C = 0x2,
  BIC_GL_SENSOR_FIO_FRONT_TEMP_C = 0x3,
  BIC_GL_SENSOR_MB_SOC_CPU_TEMP_C = 0x4,
  BIC_GL_SENSOR_MB_DIMMA_TEMP_C = 0x5,
  BIC_GL_SENSOR_MB_DIMMB_TEMP_C = 0x6,
  BIC_GL_SENSOR_MB_DIMMC_TEMP_C = 0x7,
  BIC_GL_SENSOR_MB_DIMMD_TEMP_C = 0x8,
  BIC_GL_SENSOR_MB_DIMME_TEMP_C = 0x9,
  BIC_GL_SENSOR_MB_DIMMF_TEMP_C = 0x0A,
  BIC_GL_SENSOR_MB_DIMMG_TEMP_C = 0x0B,
  BIC_GL_SENSOR_MB_DIMMH_TEMP_C = 0x0C,
  BIC_GL_SENSOR_MB_SSD0_TEMP_C = 0x0D,
  BIC_GL_SENSOR_MB_HSC_TEMP_C = 0x0E,
  BIC_GL_SENSOR_MB_VR_VCCIN_TEMP_C = 0x0F,
  BIC_GL_SENSOR_MB_VR_EHV_TEMP_C = 0x10,
  BIC_GL_SENSOR_MB_VR_FIVRA_TEMP_C = 0x11,
  BIC_GL_SENSOR_MB_VR_VCCINF_TEMP_C = 0x12,
  BIC_GL_SENSOR_MB_VR_VCCD0_TEMP_C = 0x13,
  BIC_GL_SENSOR_MB_VR_VCCD1_TEMP_C = 0x14,
  BIC_GL_SENSOR_MB_SOC_THERMAL_MARGIN_C = 0x15,
  BIC_GL_SENSOR_MB_SOC_TJMAX_C = 0x16,

  //BIC - greatlakes voltage sensors
  BIC_GL_SENSOR_MB_ADC_P12V_STBY_VOLT_V = 0x17,
  BIC_GL_SENSOR_MB_ADC_P3V_BAT_VOLT_V = 0x18,
  BIC_GL_SENSOR_MB_ADC_P3V3_STBY_VOLT_V = 0x19,
  BIC_GL_SENSOR_MB_ADC_P1V8_STBY_VOLT_V = 0x1A,
  BIC_GL_SENSOR_MB_ADC_P1V05_PCH_VOLT_V = 0x1B,
  BIC_GL_SENSOR_MB_HSC_INPUT_VOLT_V = 0x1C,
  BIC_GL_SENSOR_MB_VR_VCCIN_VOLT_V = 0x1D,
  BIC_GL_SENSOR_MB_VR_VCCINF_VOLT_V = 0x1E,
  BIC_GL_SENSOR_MB_VR_FIVRA_VOLT_V = 0x1F,
  BIC_GL_SENSOR_MB_VR_VCCD0_VOLT_V = 0x20,
  BIC_GL_SENSOR_MB_VR_VCCD1_VOLT_V = 0x21,
  BIC_GL_SENSOR_MB_VR_EHV_VOLT_V = 0x22,
  BIC_GL_SENSOR_MB_ADC_VNN_VOLT_V = 0x23,
  BIC_GL_SENSOR_MB_ADC_P5V_STBY_VOLT_V = 0x24,
  BIC_GL_SENSOR_MB_ADC_P12V_DIMM_VOLT_V = 0x25,
  BIC_GL_SENSOR_MB_ADC_P1V2_STBY_VOLT_V = 0x26,
  BIC_GL_SENSOR_MB_ADC_P3V3_M2_VOLT_V = 0x27,

  //BIC - greatlakes current sensors
  BIC_GL_SENSOR_MB_HSC_OUTPUT_CURR_A = 0x28,
  BIC_GL_SENSOR_MB_VR_VCCIN_CURR_A = 0x29,
  BIC_GL_SENSOR_MB_VR_EHV_CURR_A = 0x2A,
  BIC_GL_SENSOR_MB_VR_FIVRA_CURR_A = 0x2B,
  BIC_GL_SENSOR_MB_VR_VCCINF_CURR_A = 0x2C,
  BIC_GL_SENSOR_MB_VR_VCCD0_CURR_A = 0x2D,
  BIC_GL_SENSOR_MB_VR_VCCD1_CURR_A = 0x2E,

  //BIC - greatlakes power sensors
  BIC_GL_SENSOR_MB_HSC_INPUT_PWR_W = 0x2F,
  BIC_GL_SENSOR_MB_VR_VCCIN_PWR_W = 0x30,
  BIC_GL_SENSOR_MB_VR_EHV_PWR_W = 0x31,
  BIC_GL_SENSOR_MB_VR_FIVRA_PWR_W = 0x32,
  BIC_GL_SENSOR_MB_VR_VCCINF_PWR_W = 0x33,
  BIC_GL_SENSOR_MB_VR_VCCD0_PWR_W = 0x34,
  BIC_GL_SENSOR_MB_VR_VCCD1_PWR_W = 0x35,
  BIC_GL_SENSOR_MB_VR_DIMMA_PMIC_PWR_W = 0x36,
  BIC_GL_SENSOR_MB_VR_DIMMB_PMIC_PWR_W = 0x37,
  BIC_GL_SENSOR_MB_VR_DIMMC_PMIC_PWR_W = 0x38,
  BIC_GL_SENSOR_MB_VR_DIMMD_PMIC_PWR_W = 0x39,
  BIC_GL_SENSOR_MB_VR_DIMME_PMIC_PWR_W = 0x3A,
  BIC_GL_SENSOR_MB_VR_DIMMF_PMIC_PWR_W = 0x3B,
  BIC_GL_SENSOR_MB_VR_DIMMG_PMIC_PWR_W = 0x3C,
  BIC_GL_SENSOR_MB_VR_DIMMH_PMIC_PWR_W = 0x3D,

  //BIC 1OU VF Sensors
  BIC_1OU_VF_SENSOR_NUM_T_MB_OUTLET_TEMP_T = 0x50,
  BIC_1OU_VF_SENSOR_NUM_V_12_AUX = 0x51,
  BIC_1OU_VF_SENSOR_NUM_V_12_EDGE = 0x52,
  BIC_1OU_VF_SENSOR_NUM_V_3_3_AUX = 0x53,
  BIC_1OU_VF_SENSOR_NUM_V_HSC_IN = 0x54,
  BIC_1OU_VF_SENSOR_NUM_I_HSC_OUT = 0x55,
  BIC_1OU_VF_SENSOR_NUM_P_HSC_IN = 0x56,
  BIC_1OU_VF_SENSOR_NUM_T_HSC = 0x57,
  BIC_1OU_VF_SENSOR_NUM_V_1_2_STBY = 0x58,
  BIC_1OU_VF_SENSOR_NUM_INA231_PWR_M2A = 0x60,
  BIC_1OU_VF_SENSOR_NUM_INA231_VOL_M2A = 0x61,
  BIC_1OU_VF_SENSOR_NUM_NVME_TEMP_M2A = 0x62,
  BIC_1OU_VF_SENSOR_NUM_ADC_12V_VOL_M2A = 0x63,
  BIC_1OU_VF_SENSOR_NUM_ADC_3V3_VOL_M2A = 0x64,
  BIC_1OU_VF_SENSOR_NUM_INA231_PWR_M2B = 0x68,
  BIC_1OU_VF_SENSOR_NUM_INA231_VOL_M2B = 0x69,
  BIC_1OU_VF_SENSOR_NUM_NVME_TEMP_M2B = 0x6A,
  BIC_1OU_VF_SENSOR_NUM_ADC_12V_VOL_M2B = 0x6B,
  BIC_1OU_VF_SENSOR_NUM_ADC_3V3_VOL_M2B = 0x6C,
  BIC_1OU_VF_SENSOR_NUM_INA231_PWR_M2C = 0x70,
  BIC_1OU_VF_SENSOR_NUM_INA231_VOL_M2C = 0x71,
  BIC_1OU_VF_SENSOR_NUM_NVME_TEMP_M2C = 0x72,
  BIC_1OU_VF_SENSOR_NUM_ADC_12V_VOL_M2C = 0x73,
  BIC_1OU_VF_SENSOR_NUM_ADC_3V3_VOL_M2C = 0x74,
  BIC_1OU_VF_SENSOR_NUM_INA231_PWR_M2D = 0x78,
  BIC_1OU_VF_SENSOR_NUM_INA231_VOL_M2D = 0x79,
  BIC_1OU_VF_SENSOR_NUM_NVME_TEMP_M2D = 0x7A,
  BIC_1OU_VF_SENSOR_NUM_ADC_12V_VOL_M2D = 0x7B,
  BIC_1OU_VF_SENSOR_NUM_ADC_3V3_VOL_M2D = 0x7C,

  // BIC Rainbow Falls Sensors
  BIC_1OU_RF_INLET_TEMP = 0x50,
  BIC_1OU_RF_CXL_TEMP = 0x51,
  BIC_1OU_RF_CXL_CNTR_TEMP = 0x52,
  BIC_1OU_RF_DIMM_A_TEMP = 0x53,
  BIC_1OU_RF_DIMM_B_TEMP = 0x54,
  BIC_1OU_RF_DIMM_C_TEMP = 0x55,
  BIC_1OU_RF_DIMM_D_TEMP = 0x57,
  BIC_1OU_RF_P0V9A_SPS_TEMP = 0x58,
  BIC_1OU_RF_P0V8A_SPS_TEMP = 0x59,
  BIC_1OU_RF_P0V8D_SPS_TEMP = 0x5A,
  BIC_1OU_RF_PVDDQ_AB_SPS_TEMP = 0x5B,
  BIC_1OU_RF_PVDDQ_CD_SPS_TEMP = 0x5C,
  BIC_1OU_RF_P12V_STBY_VOL = 0x5D,
  BIC_1OU_RF_P3V3_STBY_VOL = 0x5E,
  BIC_1OU_RF_P5V_STBY_VOL =  0x5F,
  BIC_1OU_RF_P1V2_STBY_VOL = 0x60,
  BIC_1OU_RF_P1V8_ASIC_VOL = 0x61,
  BIC_1OU_RF_P0V9_ASIC_A_VOL = 0x62,
  BIC_1OU_RF_P0V8_ASIC_A_VOL = 0x64,
  BIC_1OU_RF_P0V8_ASIC_D_VOL = 0x65,
  BIC_1OU_RF_PVDDQ_AB_VOL = 0x66,
  BIC_1OU_RF_PVDDQ_CD_VOL = 0x67,
  BIC_1OU_RF_PVPP_AB_VOL = 0x68,
  BIC_1OU_RF_PVPP_CD_VOL = 0x69,
  BIC_1OU_RF_PVTT_AB_VOL = 0x6A,
  BIC_1OU_RF_PVTT_CD_VOL = 0x6B,
  BIC_1OU_RF_P12V_STBY_CUR = 0x6C,
  BIC_1OU_RF_P3V3_STBY_CUR = 0x6D,
  BIC_1OU_RF_P0V9A_VR_CUR = 0x6E,
  BIC_1OU_RF_P0V8A_VR_CUR = 0x6F,
  BIC_1OU_RF_P0V8D_VR_CUR = 0x70,
  BIC_1OU_RF_PVDDQ_VR_CUR = 0x71,
  BIC_1OU_RF_PVDDQV_VR_CUR = 0x72,
  BIC_1OU_RF_P12V_STBY_PWR = 0x73,
  BIC_1OU_RF_P3V3_STBY_PWR = 0x74,
  BIC_1OU_RF_P0V9A_SPS_PWR = 0x75,
  BIC_1OU_RF_P0V8A_SPS_PWR = 0x76,
  BIC_1OU_RF_P0V8D_SPS_PWR = 0x77,
  BIC_1OU_RF_PVDDQ_AB_SPS_PWR = 0x78,
  BIC_1OU_RF_PVDDQ_CD_SPS_PWR = 0x79,

  // BIC Olympic Sensors
  BIC_OP_1OU_TEMP_C = 0x40,
  BIC_OP_1OU_E1S_SSD0_P12V_VOLT_V = 0x41,
  BIC_OP_1OU_E1S_SSD1_P12V_VOLT_V = 0x42,
  BIC_OP_1OU_E1S_SSD2_P12V_VOLT_V = 0x43,
  BIC_OP_1OU_P12V_EDGE_VOLT_V = 0x46,
  BIC_OP_1OU_E1S_SSD0_P3V3_ADC_VOLT_V = 0x47,
  BIC_OP_1OU_E1S_SSD1_P3V3_ADC_VOLT_V = 0x48,
  BIC_OP_1OU_E1S_SSD2_P3V3_ADC_VOLT_V = 0x49,
  BIC_OP_1OU_P3V3_STBY_ADC_VOLT_V = 0x4C,
  BIC_OP_1OU_P1V8_ADC_VOLT_V = 0x4D,
  BIC_OP_1OU_P0V9_ADC_VOLT_V = 0x4E,
  BIC_OP_1OU_P1V2_ADC_VOLT_V = 0x4F,
  BIC_OP_1OU_E1S_SSD0_P12V_CURR_A = 0x50,
  BIC_OP_1OU_E1S_SSD1_P12V_CURR_A = 0x51,
  BIC_OP_1OU_E1S_SSD2_P12V_CURR_A = 0x52,
  BIC_OP_1OU_P12V_EDGE_CURR_A = 0x55,
  BIC_OP_1OU_E1S_SSD0_P12V_PWR_W = 0x56,
  BIC_OP_1OU_E1S_SSD1_P12V_PWR_W = 0x57,
  BIC_OP_1OU_E1S_SSD2_P12V_PWR_W = 0x58,
  BIC_OP_1OU_P12V_EDGE_PWR_W = 0x5B,
  BIC_OP_1OU_RE_TIMER_TEMP_C = 0x61,
  BIC_OP_1OU_E1S_SSD0_TEMP_C = 0x5C,
  BIC_OP_1OU_E1S_SSD1_TEMP_C = 0x5D,
  BIC_OP_1OU_E1S_SSD2_TEMP_C = 0x5E,
  BIC_OP_2OU_TEMP_C = 0x70,
  BIC_OP_2OU_E1S_SSD0_P12V_VOLT_V = 0x71,
  BIC_OP_2OU_E1S_SSD1_P12V_VOLT_V = 0x72,
  BIC_OP_2OU_E1S_SSD2_P12V_VOLT_V = 0x73,
  BIC_OP_2OU_E1S_SSD3_P12V_VOLT_V = 0x74,
  BIC_OP_2OU_E1S_SSD4_P12V_VOLT_V = 0x75,
  BIC_OP_2OU_MAIN_P12V_VOLT_V = 0x76,
  BIC_OP_2OU_E1S_SSD0_P3V3_ADC_VOLT_V = 0x77,
  BIC_OP_2OU_E1S_SSD1_P3V3_ADC_VOLT_V = 0x78,
  BIC_OP_2OU_E1S_SSD2_P3V3_ADC_VOLT_V = 0x79,
  BIC_OP_2OU_E1S_SSD3_P3V3_ADC_VOLT_V = 0x7A,
  BIC_OP_2OU_E1S_SSD4_P3V3_ADC_VOLT_V = 0x7B,
  BIC_OP_2OU_P3V3_STBY_ADC_VOLT_V = 0x7C,
  BIC_OP_2OU_P1V8_STBY_ADC_VOLT_V = 0x7D,
  BIC_OP_2OU_P1V2_STBY_ADC_VOLT_V = 0x7F,
  BIC_OP_2OU_E1S_SSD0_P12V_CURR_A = 0x80,
  BIC_OP_2OU_E1S_SSD1_P12V_CURR_A = 0x81,
  BIC_OP_2OU_E1S_SSD2_P12V_CURR_A = 0x82,
  BIC_OP_2OU_E1S_SSD3_P12V_CURR_A = 0x83,
  BIC_OP_2OU_E1S_SSD4_P12V_CURR_A = 0x84,
  BIC_OP_2OU_MAIN_P12V_CURR_A = 0x85,
  BIC_OP_2OU_E1S_SSD0_P12V_PWR_W = 0x86,
  BIC_OP_2OU_E1S_SSD1_P12V_PWR_W = 0x87,
  BIC_OP_2OU_E1S_SSD2_P12V_PWR_W = 0x88,
  BIC_OP_2OU_E1S_SSD3_P12V_PWR_W = 0x89,
  BIC_OP_2OU_E1S_SSD4_P12V_PWR_W = 0x8A,
  BIC_OP_2OU_MAIN_P12V_PWR_W = 0x8B,
  BIC_OP_2OU_E1S_SSD0_TEMP_C = 0x8C,
  BIC_OP_2OU_E1S_SSD1_TEMP_C = 0x8D,
  BIC_OP_2OU_E1S_SSD2_TEMP_C = 0x8E,
  BIC_OP_2OU_E1S_SSD3_TEMP_C = 0x8F,
  BIC_OP_2OU_E1S_SSD4_TEMP_C = 0x90,
  BIC_OP_3OU_TEMP_C = 0xA0,
  BIC_OP_3OU_E1S_SSD0_P12V_VOLT_V = 0xA1,
  BIC_OP_3OU_E1S_SSD1_P12V_VOLT_V = 0xA2,
  BIC_OP_3OU_E1S_SSD2_P12V_VOLT_V = 0xA3,
  BIC_OP_3OU_P12V_EDGE_VOLT_V = 0xA6,
  BIC_OP_3OU_E1S_SSD0_P3V3_ADC_VOLT_V = 0xA7,
  BIC_OP_3OU_E1S_SSD1_P3V3_ADC_VOLT_V = 0xA8,
  BIC_OP_3OU_E1S_SSD2_P3V3_ADC_VOLT_V = 0xA9,
  BIC_OP_3OU_P3V3_STBY_ADC_VOLT_V = 0xAC,
  BIC_OP_3OU_P1V8_ADC_VOLT_V = 0xAD,
  BIC_OP_3OU_P0V9_ADC_VOLT_V = 0xAE,
  BIC_OP_3OU_P1V2_ADC_VOLT_V = 0xAF,
  BIC_OP_3OU_E1S_SSD0_P12V_CURR_A = 0xB0,
  BIC_OP_3OU_E1S_SSD1_P12V_CURR_A = 0xB1,
  BIC_OP_3OU_E1S_SSD2_P12V_CURR_A = 0xB2,
  BIC_OP_3OU_P12V_EDGE_CURR_A = 0xB5,
  BIC_OP_3OU_E1S_SSD0_P12V_PWR_W = 0xB6,
  BIC_OP_3OU_E1S_SSD1_P12V_PWR_W = 0xB7,
  BIC_OP_3OU_E1S_SSD2_P12V_PWR_W = 0xB8,
  BIC_OP_3OU_P12V_EDGE_PWR_W = 0xBB,
  BIC_OP_3OU_RE_TIMER_TEMP_C = 0xC1,
  BIC_OP_3OU_E1S_SSD0_TEMP_C = 0xBC,
  BIC_OP_3OU_E1S_SSD1_TEMP_C = 0xBD,
  BIC_OP_3OU_E1S_SSD2_TEMP_C = 0xBE,
  BIC_OP_4OU_TEMP_C = 0xD0,
  BIC_OP_4OU_E1S_SSD0_P12V_VOLT_V = 0xD1,
  BIC_OP_4OU_E1S_SSD1_P12V_VOLT_V = 0xD2,
  BIC_OP_4OU_E1S_SSD2_P12V_VOLT_V = 0xD3,
  BIC_OP_4OU_E1S_SSD3_P12V_VOLT_V = 0xD4,
  BIC_OP_4OU_E1S_SSD4_P12V_VOLT_V = 0xD5,
  BIC_OP_4OU_MAIN_P12V_VOLT_V = 0xD6,
  BIC_OP_4OU_E1S_SSD0_P3V3_ADC_VOLT_V = 0xD7,
  BIC_OP_4OU_E1S_SSD1_P3V3_ADC_VOLT_V = 0xD8,
  BIC_OP_4OU_E1S_SSD2_P3V3_ADC_VOLT_V = 0xD9,
  BIC_OP_4OU_E1S_SSD3_P3V3_ADC_VOLT_V = 0xDA,
  BIC_OP_4OU_E1S_SSD4_P3V3_ADC_VOLT_V = 0xDB,
  BIC_OP_4OU_P3V3_STBY_ADC_VOLT_V = 0xDC,
  BIC_OP_4OU_P1V8_STBY_ADC_VOLT_V = 0xDD,
  BIC_OP_4OU_P1V2_STBY_ADC_VOLT_V = 0xDF,
  BIC_OP_4OU_E1S_SSD0_P12V_CURR_A = 0xE0,
  BIC_OP_4OU_E1S_SSD1_P12V_CURR_A = 0xE1,
  BIC_OP_4OU_E1S_SSD2_P12V_CURR_A = 0xE2,
  BIC_OP_4OU_E1S_SSD3_P12V_CURR_A = 0xE3,
  BIC_OP_4OU_E1S_SSD4_P12V_CURR_A = 0xE4,
  BIC_OP_4OU_MAIN_P12V_CURR_A = 0xE5,
  BIC_OP_4OU_E1S_SSD0_P12V_PWR_W = 0xE6,
  BIC_OP_4OU_E1S_SSD1_P12V_PWR_W = 0xE7,
  BIC_OP_4OU_E1S_SSD2_P12V_PWR_W = 0xE8,
  BIC_OP_4OU_E1S_SSD3_P12V_PWR_W = 0xE9,
  BIC_OP_4OU_E1S_SSD4_P12V_PWR_W = 0xEA,
  BIC_OP_4OU_MAIN_P12V_PWR_W = 0xEB,
  BIC_OP_4OU_E1S_SSD0_TEMP_C = 0xEC,
  BIC_OP_4OU_E1S_SSD1_TEMP_C = 0xED,
  BIC_OP_4OU_E1S_SSD2_TEMP_C = 0xEE,
  BIC_OP_4OU_E1S_SSD3_TEMP_C = 0xEF,
  BIC_OP_4OU_E1S_SSD4_TEMP_C = 0xF0,

  // BIC Niagara Falls Sensors
  BIC_1OU_NF_INLET_TEMP = 0x50,
  BIC_1OU_NF_CXL_CNTR_TEMP = 0x51,
  BIC_1OU_NF_P0V85_ASIC_TEMP = 0x52,
  BIC_1OU_NF_PVDDQ_AB_TEMP = 0x53,
  BIC_1OU_NF_P0V8_ASIC_TEMP = 0x54,
  BIC_1OU_NF_PVDDQ_CD_TEMP = 0x55,
  BIC_1OU_NF_P1V2_STBY_VOL = 0x57,
  BIC_1OU_NF_P1V2_ASIC_VOL = 0x58,
  BIC_1OU_NF_P1V8_ASIC_VOL = 0x59,
  BIC_1OU_NF_PVPP_AB_VOL = 0x5A,
  BIC_1OU_NF_PVPP_CD_VOL = 0x5B,
  BIC_1OU_NF_PVTT_AB_VOL = 0x5C,
  BIC_1OU_NF_PVTT_CD_VOL = 0x5D,
  BIC_1OU_NF_P0V75_ASIC_VOL = 0x5E,
  BIC_1OU_NF_P12V_STBY_VOL = 0x5F,
  BIC_1OU_NF_P3V3_STBY_VOL = 0x60,
  BIC_1OU_NF_P0V85_ASIC_VOL = 0x61,
  BIC_1OU_NF_PVDDQ_AB_VOL = 0x62,
  BIC_1OU_NF_P0V8_ASIC_VOL = 0x63,
  BIC_1OU_NF_PVDDQ_CD_VOL = 0x64,
  BIC_1OU_NF_P12V_STBY_CUR = 0x65,
  BIC_1OU_NF_P3V3_STBY_CUR = 0x66,
  BIC_1OU_NF_P0V85_ASIC_CUR = 0x67,
  BIC_1OU_NF_PVDDQ_AB_CUR = 0x68,
  BIC_1OU_NF_P0V8_ASIC_CUR = 0x69,
  BIC_1OU_NF_PVDDQ_CD_CUR = 0x6A,
  BIC_1OU_NF_P12V_STBY_PWR = 0x6B,
  BIC_1OU_NF_P3V3_STBY_PWR = 0x6C,
  BIC_1OU_NF_P0V85_ASIC_PWR = 0x6D,
  BIC_1OU_NF_PVDDQ_AB_PWR = 0x6E,
  BIC_1OU_NF_P0V8_ASIC_PWR = 0x6F,
  BIC_1OU_NF_PVDDQ_CD_PWR = 0x70,

  //BIC BaseBoard Temperture Sensors
  BB_INLET_TEMP = 0xD1,
  BB_OUTLET_TEMP = 0xD2,
  BB_HSC_TEMP = 0xD3,
  //BIC BasBoard Voltage Sensors
  BB_P5V = 0xD4,
  BB_P12V = 0xD5,
  BB_P3V3_STBY = 0xD6,
  BB_P5V_USB = 0xE9,
  BB_P1V2_STBY = 0xD9,
  BB_P1V0_STBY = 0xDA,
  BB_MEDUSA_VIN = 0xDB,
  BB_MEDUSA_VOUT = 0xD7,
  BB_HSC_VIN = 0xDC,
  //BIC BasBoard Current Sensors
  BB_MEDUSA_CUR = 0xDF,
  BB_HSC_IOUT = 0xDE,
  BB_FAN_IOUT = 0xE8,
  //BIC BasBoard Power Consumption Sensors
  BB_MEDUSA_PWR = 0xD8,
  BB_HSC_PIN = 0xDD,
  //BIC BasBoard Others Sensors
  BB_HSC_EIN = 0xEA,
  BB_HSC_PEAK_IOUT = 0xEB,
  BB_HSC_PEAK_PIN = 0xEC,

  // BMC - DPv2 X8 sensors
  BMC_DPV2_SENSOR_DPV2_1_12V_VIN    = 0x8C,
  BMC_DPV2_SENSOR_DPV2_1_12V_VOUT   = 0x8D,
  BMC_DPV2_SENSOR_DPV2_1_12V_IOUT   = 0x8E,
  BMC_DPV2_SENSOR_DPV2_1_EFUSE_TEMP = 0x8F,
  BMC_DPV2_SENSOR_DPV2_1_EFUSE_PWR  = 0x90,

  // BIC - DPv2 X16 sensors
  BIC_DPV2_SENSOR_DPV2_2_12V_VIN    = 0x91,
  BIC_DPV2_SENSOR_DPV2_2_12V_VOUT   = 0x92,
  BIC_DPV2_SENSOR_DPV2_2_12V_IOUT   = 0x93,
  BIC_DPV2_SENSOR_DPV2_2_EFUSE_TEMP = 0x94,
  BIC_DPV2_SENSOR_DPV2_2_EFUSE_PWR  = 0x95,

  //BMC - sensors
  BMC_SENSOR_INLET_TEMP = 0xED,
  BMC_SENSOR_OUTLET_TEMP = 0xEE,
  NIC_SENSOR_TEMP = 0xEF,
  BMC_SENSOR_FAN0_TACH = 0xE0,
  BMC_SENSOR_FAN1_TACH = 0xE1,
  BMC_SENSOR_FAN2_TACH = 0xE2,
  BMC_SENSOR_FAN3_TACH = 0xE3,
  BMC_SENSOR_FAN4_TACH = 0xE4,
  BMC_SENSOR_FAN5_TACH = 0xE5,
  BMC_SENSOR_FAN6_TACH = 0xE6,
  BMC_SENSOR_FAN7_TACH = 0xE7,
  BMC_SENSOR_PWM0      = 0xE8,
  BMC_SENSOR_PWM1      = 0xE9,
  BMC_SENSOR_PWM2      = 0xEA,
  BMC_SENSOR_PWM3      = 0xEB,
  BMC_SENSOR_HSC_PEAK_IOUT = 0xC8,
  BMC_SENSOR_HSC_PEAK_PIN  = 0xC9,
  BMC_SENSOR_FAN_PWR = 0xCA,
  BMC_SENSOR_PDB_CL_VDELTA = 0xCC,
  BMC_SENSOR_CURR_LEAKAGE = 0xCD,
  BMC_SENSOR_PDB_BB_VDELTA = 0xCE,
  BMC_SENSOR_MEDUSA_VDELTA = 0xCF,
  BMC_SENSOR_MEDUSA_CURR = 0xD0,
  BMC_SENSOR_MEDUSA_PWR = 0xD1,
  BMC_SENSOR_NIC_P12V = 0xD2,
  BMC_SENSOR_NIC_PWR = 0xD3,
  BMC_SENSOR_P1V0_STBY = 0xD4,
  BMC_SENSOR_P0V6_STBY = 0xD5,
  BMC_SENSOR_P3V3_RGM_STBY = 0xD6,
  BMC_SENSOR_P5V_USB = 0xD7,
  BMC_SENSOR_P3V3_NIC = 0xD8,
  BMC_SENSOR_MEDUSA_VSENSE_VDELTA_MAX = 0xD9,
  BMC_SENSOR_MEDUSA_GND_SENSE_VDELTA_MAX = 0xDA,
  BMC_SENSOR_P5V = 0xF0,
  BMC_SENSOR_P12V = 0xF1,
  BMC_SENSOR_P3V3_STBY = 0xF2,
  BMC_SENSOR_P1V8_STBY = 0xF3,
  BMC_SENSOR_P1V2_BMC_STBY = 0xF4,
  BMC_SENSOR_P2V5_BMC_STBY = 0xF5,
  BMC_SENSOR_MEDUSA_VOUT = 0xF6,
  BMC_SENSOR_HSC_VIN = 0xF7,
  BMC_SENSOR_HSC_TEMP = 0xF8,
  BMC_SENSOR_HSC_PIN = 0xF9,
  BMC_SENSOR_HSC_IOUT = 0xFA,
  BMC_SENSOR_FAN_IOUT = 0xFB,
  BMC_SENSOR_NIC_IOUT = 0xFC,
  BMC_SENSOR_MEDUSA_VIN = 0xFD,
  BMC_SENSOR_NICEXP_TEMP = 0xFE,
  BMC_SENSOR_VPDB_DELTA_1_TEMP = 0xB0,
  BMC_SENSOR_VPDB_DELTA_2_TEMP = 0xB1,
  BMC_SENSOR_VPDB_WW_TEMP = 0xB2,
  BMC_SENSOR_PDB_48V_DELTA_1_VIN = 0xB3,
  BMC_SENSOR_PDB_48V_DELTA_2_VIN = 0xB4,
  BMC_SENSOR_PDB_48V_WW_VIN = 0xB5,
  BMC_SENSOR_PDB_12V_DELTA_1_VOUT = 0xB6,
  BMC_SENSOR_PDB_12V_DELTA_2_VOUT = 0xB7,
  BMC_SENSOR_PDB_12V_WW_VOUT = 0xB8,
  BMC_SENSOR_PDB_DELTA_1_IOUT = 0xB9,
  BMC_SENSOR_PDB_DELTA_2_IOUT = 0xBA,
  BMC_SENSOR_PDB_12V_WW_IOUT = 0xBB,
  BMC_SENSOR_PDB_12V_WW_PWR = 0xBC,
  BMC_SENSOR_VPDB_FLEX_1_TEMP = 0xBD,
  BMC_SENSOR_VPDB_FLEX_2_TEMP = 0xBE,
  BMC_SENSOR_PDB_48V_FLEX_1_VIN = 0xBF,
  BMC_SENSOR_PDB_48V_FLEX_2_VIN = 0xC0,
  BMC_SENSOR_PDB_12V_FLEX_1_VOUT = 0xC1,
  BMC_SENSOR_PDB_12V_FLEX_2_VOUT = 0xC2,
  BMC_SENSOR_PDB_FLEX_1_IOUT = 0xC3,
  BMC_SENSOR_PDB_FLEX_2_IOUT = 0xC4,
};

//Serverboard Discrete/SEL Sensors
enum {
  BIOS_END_OF_POST = 0x11,
  BIC_SENSOR_SYSTEM_STATUS = 0x10,
  BIC_SENSOR_PROC_FAIL = 0x65,
  BIC_SENSOR_VRHOT = 0xB2,
  ME_SENSOR_SMART_CLST = 0xB1,
  BIOS_SENSOR_PMIC_ERR = 0xB4,
  BIC_SENSOR_SSD_HOT_PLUG = 0xED,
  BB_BIC_SENSOR_POWER_DETECT = 0xE1,
  BB_BIC_SENSOR_BUTTON_DETECT = 0xE2,
  BB_BIC_SENSOR_SLOT_PRESENT = 0xCB,
};

// Aggregate sensors
enum {
  AGGREGATE_SENSOR_SYSTEM_AIRFLOW = 0x0,
};

//ADC INFO
enum {
  ADC0 = 0,
  ADC1,
  ADC2,
  ADC3,
  ADC4,
  ADC5,
  ADC6,
  ADC7,
  ADC8,
  ADC9,
  ADC10,
  ADC11,
  ADC12,
  ADC13,
  ADC14,
};

//GENERIC I2C Sensors
enum {
  TEMP_INLET = 0,
  TEMP_OUTLET,
  TEMP_NIC,
  TEMP_NICEXP_OUTLET,
  TEMP_NICEXP
};

//ADM1278 INFO
enum {
  ADM1278_VOLTAGE = 0,
  ADM1278_CURRENT,
  ADM1278_POWER,
  ADM1278_TEMP,
};

//ATTR INFO
enum {
  HSC_VOLTAGE = 0,
  HSC_CURRENT,
  HSC_POWER,
  HSC_TEMP,
};

//PDB COEFFICIENT INFO
enum {
  PDB_VOLTAGE_OUT = 0,
  PDB_VOLTAGE_IN,
  PDB_CURRENT,
  PDB_TEMP,
  PDB_POWER,
};

//PDB INFO
enum {
  PDB_DELTA_1 = 0,
  PDB_DELTA_2,
  PDB_RNS,
  PDB_FLEX_1,
  PDB_FLEX_2,
};

enum {
  DPV2_EFUSE_VIN = 0,
  DPV2_EFUSE_VOUT,
  DPV2_EFUSE_IOUT,
  DPV2_EFUSE_TEMP,
  DPV2_EFUSE_PIN,
};

typedef struct {
  float m;
  float b;
  float r;
} PAL_ATTR_INFO;

//HSC INFO
enum {
  HSC_ID0 = 0,
  HSC_ID1,
};

//I2C type
enum {
  I2C_BYTE = 0,
  I2C_WORD,
  I2C_BLOCK,
};

//HSC INFO
typedef enum {
  MEDUSA_ADC_LTC2992 = 0,
  MEDUSA_ADC_INA238_PSU,
  MEDUSA_ADC_INA238_GND,
} MEDUSA_ADC_INFO;

typedef struct {
  uint8_t slv_addr;
  uint16_t cmd_peak_iout;
  uint16_t cmd_peak_pin;
  PAL_ATTR_INFO* info;
} PAL_HSC_INFO;

typedef struct {
  float data;
} PAL_PDB_COEFFICIENT;

typedef struct {
  uint8_t target_addr;
  PAL_PDB_COEFFICIENT* coefficient;
} PAL_PDB_INFO;

typedef struct {
  uint8_t id;
  uint8_t bus;
  uint8_t slv_addr;
} PAL_I2C_BUS_INFO;

typedef struct {
  int integer :10;
  uint8_t fract :6;
} PAL_S10_6_FORMAT;

typedef struct {
  uint8_t offset;
  float m;
  float b;
  float r;
} PAL_PMBUS_INFO;

typedef struct {
  char chip_name[16];
  char driver[16];
  uint8_t target_addr;
} PAL_CHIP_INFO;

typedef struct {
  uint8_t fru: 4;
  uint8_t type: 4;
} PAL_SNR_INFO;

#endif
