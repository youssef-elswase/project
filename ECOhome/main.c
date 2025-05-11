/*
 * Main program for Garden of Eco Home System
 * This system includes:
 * - Temperature and Humidity monitoring (DHT11)
 * - Gas detection (MQ2)
 * - Soil moisture monitoring
 * - Light detection (LDR)
 * - Motion detection (PIR)
 * - Water pump control
 * - LCD display
 * - Buzzer alarm
 * - LED indicators
 * - Servo Motor control
 */

#include "lib/std_typs.h"
#include "lib/BIT_MATH.h"
#include <util/delay.h>
#include <avr/io.h>
#include "hal/CLCD_intreface.h"
#include "hal/DHT11_interface.h"
#include "hal/MQ2_interface.h"
#include "hal/BUZ_interface.h"
#include "hal/DCMOTOR_interface.h"
#include "hal/KEPD_interface.h"
#include "hal/soil moisture_interface.h"
#include "hal/MQ2_config.h"
#include "hal/LDR_interface.h"
#include "hal/LED_intreface.h"
#include "hal/Servo_Motor_interface.h"

/* PIR Sensor Pin Definitions */
#define PIR_PIN  PC2
#define PIR_PORT PORTC
#define PIR_DDR  DDRC
#define PIR_PIN_REG PIND

/* PIR Sensor Functions */
void PIR_Init() {
    CLR_BIT(PIR_DDR, PIR_PIN); // Set PIR pin as input
}

u8 PIR_Read() {
    return GET_BIT(PIR_PIN_REG, PIR_PIN); // Read PIR sensor state
}

/* System Credentials Configuration */
#define OWNER_NAME_SIZE 3
#define PASSWORD_SIZE 3

/* Owner credentials - stored in program memory */
const u8 ownerName[OWNER_NAME_SIZE] = {'A', 'B', 'C'};
const u8 ownerPass[PASSWORD_SIZE] = {'1', '2', '3'};

/* Global Variables and Configurations */
BUZ_config buzzer = {PORTD, PIN0, ACTIVE_HIGH};  // Buzzer configuration
DCMOTOR_CONFIG waterPump = {PORTD, PIN1, PIN2}; // Water pump motor configuration
DHT11_Data dhtData;                              // DHT11 sensor data structure
MQ2_Config_t mq2Config = {                       // MQ2 gas sensor configuration
    MQ2_CHANNEL_3,
    MQ2_VREF_AVCC,
    MQ2_RES_10_BIT,
    MQ2_DEFAULT_R0,
    MQ2_DEFAULT_RL
};

/* LED Configurations for light control */
LED_config led1 = {PORTC, PIN0, ACTIVE_HIGH};
LED_config led2 = {PORTC, PIN1, ACTIVE_HIGH};
LED_config led3 = {PORTC, PIN2, ACTIVE_HIGH};

/* Function Prototypes */
void displayWelcomeMessage(void);
u8 checkCredentials(u8* enteredName, u8* enteredPass);
void ownerMode(void);
void guestMode(void);
void scrollText(char* text, u8 row);

/* Main Program */
int main(void) {
    /* Initialize all system components */
    CLCD_voidInit();              // Initialize LCD
    DHT11_voidInit();             // Initialize DHT11 sensor
    MQ2_enumInit(&mq2Config);     // Initialize MQ2 sensor
    BUZ_vInit(buzzer);            // Initialize buzzer
    KPD_vInit();                  // Initialize keypad
    SoilMoisture_voidInit();      // Initialize soil moisture sensor
    SM_vInit();                   // Initialize Servo Motor

    /* Initialize LDR with default configuration */
    LDR_Config_t ldrConfig = {
    		LDR_CHANNEL,
			LDR_VOLTAGE_REFERENCE,
			LDR_ADC_RESOLUTION,
			LDR_LOAD_RESISTANCE
    };
    LDR_enumInit(&ldrConfig);

    /* Initialize LEDs */
    LED_vInit(led1);
    LED_vInit(led2);
    LED_vInit(led3);

    u8 pirState = LOW;
    u8 systemChoice = 0;
    PIR_Init();

    /* Display welcome message */
    displayWelcomeMessage();

    /* Main system loop */
    while(1) {
        /* Check PIR sensor for motion detection */
        u8 pirState = PIR_Read();

        /* Control Servo Motor based on PIR state */
        if(pirState == HIGH) {
            SM_vTimer1Degree(90);  // Move servo to 90 degrees when motion detected
        } else {
            SM_vTimer1Degree(0);   // Return servo to 0 degrees when no motion
        }

        /* Check LDR and control LEDs based on light level */
        u16 lightPercentage;
        LDR_enumGetLightPercentage(&ldrConfig, &lightPercentage);

        if(lightPercentage < 30) { // If it's dark (less than 30% light)
            LED_vTurnOn(led1);
            LED_vTurnOn(led2);
            LED_vTurnOn(led3);
        } else {
            LED_vTurnOff(led1);
            LED_vTurnOff(led2);
            LED_vTurnOff(led3);
        }

        /* If motion detected, show mode selection */
        if(pirState == HIGH) {
            CLCD_voidClearScreen();
            CLCD_voidSetPosition(1, 1);
            CLCD_voidsendString("1:Owner 2:Guest");

            /* Wait for user choice */
            while(KPD_u8GetPressed() == NOTPRESSED);
            systemChoice = KPD_u8GetPressed();

            /* Enter selected mode */
            if(systemChoice == '1') {
                ownerMode();
            } else if(systemChoice == '2') {
                guestMode();
            }
        }
        _delay_ms(200);
    }
    return 0;
}

/* Display welcome message with scrolling effect */
void displayWelcomeMessage(void) {
    char welcomeMsg[] = "Welcome to Garden of Eco Home System";
    scrollText(welcomeMsg, CLCD_Row_1);
}

/* Scroll text on LCD display */
void scrollText(char* text, u8 row) {
    u8 i;
    u8 length = strlen(text);

    // Display text in initial position
    CLCD_voidSetPosition(row, 0);
    CLCD_voidsendString(text);

    // Add spaces to clear text after scrolling
    for(i=0; i < 16; i++) {
        CLCD_voidsendData(' ');
    }

    // Scroll text to the left
    for(i=0; i < (length + 16); i++) {
        CLCD_voidsendCommand(0x18); // Scroll left command
        _delay_ms(200);
    }
}

/* Verify owner credentials */
u8 checkCredentials(u8* enteredName, u8* enteredPass) {
    for(u8 i=0; i<OWNER_NAME_SIZE; i++) {
        if(enteredName[i] != ownerName[i]) return 0;
    }
    for(u8 i=0; i<PASSWORD_SIZE; i++) {
        if(enteredPass[i] != ownerPass[i]) return 0;
    }
    return 1;
}

/* Owner Mode Function */
void ownerMode(void) {
    u8 enteredName[OWNER_NAME_SIZE];
    u8 enteredPass[PASSWORD_SIZE];
    u8 key, index = 0;
    u16 gasValue;
    u8 soilPercent;
    u16 lightPercentage;

    /* Get owner name */
    CLCD_voidClearScreen();
    CLCD_voidSetPosition(1, 1);
    CLCD_voidsendString("Enter Name:");
    for(u8 i=0; i<OWNER_NAME_SIZE; i++) {
        while((key = KPD_u8GetPressed()) == NOTPRESSED);
        enteredName[i] = key;
        CLCD_voidsendData('*');
    }

    /* Get owner password */
    CLCD_voidClearScreen();
    CLCD_voidSetPosition(1, 1);
    CLCD_voidsendString("Enter Pass:");
    for(u8 i=0; i<PASSWORD_SIZE; i++) {
        while((key = KPD_u8GetPressed()) == NOTPRESSED);
        enteredPass[i] = key;
        CLCD_voidsendData('*');
    }

    /* Verify credentials and enter owner mode */
    if(checkCredentials(enteredName, enteredPass)) {
        CLCD_voidClearScreen();
        CLCD_voidsendString("Access Granted");
        _delay_ms(500);

        /* Main owner mode loop */
        while(1) {
            /* Read all sensors */
            DHT11_u8GetData(&dhtData);
            MQ2_enumGetGasConcentration(&mq2Config, &gasValue);
            SoilMoisture_u8GetPercentage(&soilPercent);
            LDR_enumGetLightPercentage(&ldrConfig, &lightPercentage);

            /* Display sensor readings on LCD */
            CLCD_voidClearScreen();
            CLCD_voidSetPosition(1, 1);
            CLCD_voidsendString("T:");
            CLCD_vSendIntNumber(dhtData.Temperature);
            CLCD_voidsendString("C H:");
            CLCD_vSendIntNumber(dhtData.Humidity);
            CLCD_voidsendString("%");

            CLCD_voidSetPosition(2, 1);
            CLCD_voidsendString("Soil:");
            CLCD_vSendIntNumber(soilPercent);
            CLCD_voidsendString("% L:");
            CLCD_vSendIntNumber(lightPercentage);
            CLCD_voidsendString("%");

            /* Check gas level and activate buzzer if high */
            if(gasValue > 200) { // Threshold value
                BUZ_vOn(buzzer);
            } else {
                BUZ_vOff(buzzer);
            }

            /* Check soil moisture and control water pump */
            if(soilPercent < 30) { // Dry soil threshold
                DCMOTOR_uint8Control(&waterPump, DCMOTOR_CW);
            } else {
                DCMOTOR_uint8Control(&waterPump, DCMOTOR_STOP);
            }

            _delay_ms(500);
        }
    } else {
        /* Access denied */
        CLCD_voidClearScreen();
        CLCD_voidsendString("Access Denied");
        _delay_ms(500);
    }
}

/* Guest Mode Function */
void guestMode(void) {
    u8 guestName[10];
    u8 key, index = 0;

    /* Get guest name */
    CLCD_voidClearScreen();
    CLCD_voidSetPosition(1, 1);
    CLCD_voidsendString("Enter Name:");

    /* Collect guest name */
    while(index < 9) {
        key = KPD_u8GetPressed();
        if(key != NOTPRESSED) {
            guestName[index++] = key;
            CLCD_voidsendData(key);
        }
    }
    guestName[index] = '\0';

    /* Display access request message */
    CLCD_voidClearScreen();
    CLCD_voidsendString("Req sent to owner");
    _delay_ms(500);

    /* Welcome guest */
    CLCD_voidClearScreen();
    CLCD_voidsendString("Welcome Guest!");
    _delay_ms(500);
}

