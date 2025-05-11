/*
 * LDR_prog.c
 *
 *  Created on: Mar 11, 2024
 *  Author: alaa hassan
 */

#include "LDR_interface.h"
#include "LDR_private.h"
#include "LDR_config.h"

static u16 LDR_u16CalculateResistance(LDR_Config_t *Copy_pstConfig, u16 Copy_u16AdcValue)
{
    float Local_f32Voltage = (float)Copy_u16AdcValue * LDR_VOLTAGE_RESOLUTION / LDR_MAX_ADC_VALUE;
    float Local_f32RL = ((LDR_VOLTAGE_RESOLUTION - Local_f32Voltage) / Local_f32Voltage) * Copy_pstConfig->Copy_u16RL;
    return (u16)Local_f32RL;
}

LDR_ErrorStatus LDR_enumInit(LDR_Config_t *Copy_pstConfig)
{
    LDR_ErrorStatus Local_enumErrorStatus = LDR_NOK;
    
    if (Copy_pstConfig != NULL)
    {
        /* Initialize ADC */
        ADC_vInit();
        
        /* Set default values if not configured */
        if (Copy_pstConfig->Copy_u16RL == 0)
        {
            Copy_pstConfig->Copy_u16RL = LDR_DEFAULT_RL;
        }
        
        Local_enumErrorStatus = LDR_OK;
    }
    
    return Local_enumErrorStatus;
}

LDR_ErrorStatus LDR_enumGetLightIntensity(LDR_Config_t *Copy_pstConfig, u16 *Copy_pu16LightValue)
{
    LDR_ErrorStatus Local_enumErrorStatus = LDR_NOK;
    u16 Local_u16AnalogSignal = 0;
    
    if (Copy_pstConfig != NULL && Copy_pu16LightValue != NULL)
    {
        /* Get raw ADC value */
        Local_enumErrorStatus = LDR_enumGetAnalogSignal(Copy_pstConfig, &Local_u16AnalogSignal);
        
        if (Local_enumErrorStatus == LDR_OK)
        {
            /* Calculate LDR resistance */
            *Copy_pu16LightValue = LDR_u16CalculateResistance(Copy_pstConfig, Local_u16AnalogSignal);
        }
    }
    
    return Local_enumErrorStatus;
}

LDR_ErrorStatus LDR_enumGetAnalogSignal(LDR_Config_t *Copy_pstConfig, u16 *Copy_pu16AnalogSignal)
{
    LDR_ErrorStatus Local_enumErrorStatus = LDR_NOK;
    
    if (Copy_pstConfig != NULL && Copy_pu16AnalogSignal != NULL)
    {
        if (ADC_u8GetResultSync(Copy_pstConfig->Copy_u8Channel, Copy_pu16AnalogSignal) == 0)
        {
            Local_enumErrorStatus = LDR_OK;
        }
    }
    
    return Local_enumErrorStatus;
} 
/**
     * @brief Converts LDR resistance to light percentage (0-100%)
     * @param Copy_pstConfig Pointer to LDR configuration
     * @param Copy_pu16LightPercentage Output percentage value
     * @return LDR_ErrorStatus (LDR_OK or LDR_NOK)
     */
    LDR_ErrorStatus LDR_enumGetLightPercentage(LDR_Config_t *Copy_pstConfig, u16 *Copy_pu16LightPercentage)
    {
        LDR_ErrorStatus Local_enumErrorStatus = LDR_NOK;
        u16 Local_u16LightValue = 0;

        if (Copy_pstConfig != NULL && Copy_pu16LightPercentage != NULL)
        {
            /* Get raw light intensity (resistance) */
            Local_enumErrorStatus = LDR_enumGetLightIntensity(Copy_pstConfig, &Local_u16LightValue);

            if (Local_enumErrorStatus == LDR_OK)
            {
                /*
                 * Convert resistance to percentage:
                 * - Higher resistance (dark) → 0%
                 * - Lower resistance (bright light) → 100%
                 * Note: Adjust MIN_RESISTANCE and MAX_RESISTANCE based on your LDR specs.
                 */
                #define LDR_MIN_RESISTANCE  1000   // Example: Minimum resistance (bright light)
                #define LDR_MAX_RESISTANCE 10000   // Example: Maximum resistance (dark)

                /* Ensure resistance is within bounds */
                if (Local_u16LightValue > LDR_MAX_RESISTANCE)
                    Local_u16LightValue = LDR_MAX_RESISTANCE;
                else if (Local_u16LightValue < LDR_MIN_RESISTANCE)
                    Local_u16LightValue = LDR_MIN_RESISTANCE;

                /* Calculate percentage (inverse because lower resistance = more light) */
                *Copy_pu16LightPercentage = 100 - ((Local_u16LightValue - LDR_MIN_RESISTANCE) * 100) /
                                           (LDR_MAX_RESISTANCE - LDR_MIN_RESISTANCE);
            }
        }
         return Local_enumErrorStatus;
    }
    
   
