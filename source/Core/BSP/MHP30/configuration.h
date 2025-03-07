#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_
#include "Settings.h"
#include "configuration.h"
#include <stdint.h>
/**
 * Configuration.h
 * Define here your default pre settings for TS80 or TS100
 *
 */

//===========================================================================
//============================= Default Settings ============================
//===========================================================================
/**
 * Default soldering temp is 320.0 C
 * Temperature the iron sleeps at - default 150.0 C
 */

#define SLEEP_TEMP         150 // Default sleep temperature
#define BOOST_TEMP         420 // Default boost temp.
#define BOOST_MODE_ENABLED 1   // 0: Disable 1: Enable

/**
 * Blink the temperature on the cooling screen when its > 50C
 */
#define COOLING_TEMP_BLINK 0 // 0: Disable 1: Enable

/**
 * How many seconds/minutes we wait until going to sleep/shutdown.
 * Values -> SLEEP_TIME * 10; i.e. 5*10 = 50 Seconds!
 */
#define SLEEP_TIME    5  // x10 Seconds
#define SHUTDOWN_TIME 10 // Minutes

/**
 * Auto start off for safety.
 * Pissible values are:
 *  0 - none
 *  1 - Soldering Temperature
 *  2 - Sleep Temperature
 *  3 - Sleep Off Temperature
 */
#define AUTO_START_MODE 0 // Default to none

/**
 * Locking Mode
 * When in soldering mode a long press on both keys toggle the lock of the buttons
 * Possible values are:
 *  0 - Desactivated
 *  1 - Lock except boost
 *  2 - Full lock
 */
#define LOCKING_MODE 0 // Default to desactivated for safety

/**
 * OLED Orientation
 *
 */
#define ORIENTATION_MODE           0 // 0: Right 1:Left 2:Automatic - Default right
#define REVERSE_BUTTON_TEMP_CHANGE 0 // 0:Default 1:Reverse - Reverse the plus and minus button assigment for temperature change

/**
 * Temp change settings
 */
#define TEMP_CHANGE_SHORT_STEP     1  // Default temp change short step +1
#define TEMP_CHANGE_LONG_STEP      10 // Default temp change long step +10
#define TEMP_CHANGE_SHORT_STEP_MAX 50 // Temp change short step MAX value
#define TEMP_CHANGE_LONG_STEP_MAX  90 // Temp change long step MAX value

/* Power pulse for keeping power banks awake*/
#define POWER_PULSE_INCREMENT    1
#define POWER_PULSE_MAX          100 // x10 max watts
#define POWER_PULSE_WAIT_MAX     9   // 9*2.5s = 22.5 seconds
#define POWER_PULSE_DURATION_MAX 9   // 9*250ms = 2.25 seconds

#ifdef MODEL_TS100
#define POWER_PULSE_DEFAULT 0
#else
#define POWER_PULSE_DEFAULT 5
#endif
#define POWER_PULSE_WAIT_DEFAULT     4 // Default rate of the power pulse: 4*2500 = 10000 ms = 10 s
#define POWER_PULSE_DURATION_DEFAULT 1 // Default duration of the power pulse: 1*250 = 250 ms

/**
 * OLED Orientation Sensitivity on Automatic mode!
 * Motion Sensitivity <0=Off 1=Least Sensitive 9=Most Sensitive>
 */
#define SENSITIVITY 7 // Default 7

/**
 * Detailed soldering screen
 * Detailed idle screen (off for first time users)
 */
#define DETAILED_SOLDERING 0 // 0: Disable 1: Enable - Default 0
#define DETAILED_IDLE      0 // 0: Disable 1: Enable - Default 0

#define THERMAL_RUNAWAY_TIME_SEC 20
#define THERMAL_RUNAWAY_TEMP_C   20

#define CUT_OUT_SETTING          0  // default to no cut-off voltage
#define RECOM_VOL_CELL           33 // Minimum voltage per cell (Recommended 3.3V (33))
#define TEMPERATURE_INF          0  // default to 0
#define DESCRIPTION_SCROLL_SPEED 0  // 0: Slow 1: Fast - default to slow
#define ANIMATION_LOOP           1  // 0: off 1: on
#define ANIMATION_SPEED          settingOffSpeed_t::MEDIUM

#define OP_AMP_Rf_MHP30  268500 //  268.5  Kilo-ohms -> Measured
#define OP_AMP_Rin_MHP30 1600   //  1.6  Kilo-ohms -> Measured

#define OP_AMP_GAIN_STAGE_MHP30 (1 + (OP_AMP_Rf_MHP30 / OP_AMP_Rin_MHP30))
// Deriving the Voltage div:
// Vin_max = (3.3*(r1+r2))/(r2)
// vdiv = (32768*4)/(vin_max*10)

#ifndef MODEL_MHP30
#error "No model defined!"
#endif

#ifdef MODEL_MHP30
#define SOLDERING_TEMP     200                     // Default soldering temp is 200.0 °C
#define VOLTAGE_DIV        360                     // Default for MHP30
#define PID_POWER_LIMIT    65                      // Sets the max pwm power limit
#define CALIBRATION_OFFSET 0                       // the adc offset in uV - MHP compensates automagically
#define POWER_LIMIT        65                      // 65 watts default power limit
#define MAX_POWER_LIMIT    65                      //
#define POWER_LIMIT_STEPS  1                       //
#define OP_AMP_GAIN_STAGE  OP_AMP_GAIN_STAGE_MHP30 //
#define USB_PD_VMAX        20                      // Maximum voltage for PD to negotiate
#define MODEL_HAS_DCDC                             // Has inductor to current filter
#define PID_TIM_HZ         (16)                    //
#define MAX_TEMP_C         300                     // Max soldering temp selectable °C
#define MAX_TEMP_F         570                     // Max soldering temp selectable °F
#define MIN_TEMP_C         10                      // Min soldering temp selectable °C
#define MIN_TEMP_F         60                      // Min soldering temp selectable °F
#define MIN_BOOST_TEMP_C   150                     // The min settable temp for boost mode °C
#define MIN_BOOST_TEMP_F   300                     // The min settable temp for boost mode °F
#define NO_DISPLAY_ROTATE                          // Disable OLED rotation by accel
#define SLEW_LIMIT         50                      // Limit to 3.0 Watts per 64ms pid loop update rate slew rate
#define ACCEL_MSA
#define POW_PD 1
#define TEMP_NTC
#define I2C_SOFT
#define BATTFILTERDEPTH 8
#define OLED_I2CBB
#define ACCEL_EXITS_ON_MOVEMENT

#define HARDWARE_MAX_WATTAGE_X10 650
#define TIP_THERMAL_MASS         65 // TODO, needs refinement
#define TIP_RESISTANCE           60 // x10 ohms, ~6 typical
#endif

#ifdef ACCEL_EXITS_ON_MOVEMENT
#define NO_SLEEP_MODE
#endif
#endif
