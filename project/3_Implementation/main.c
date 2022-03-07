/**
 * @file main.c
 * @author pawan (pawanraj3706@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <avr/io.h>
#include <util/delay.h>
#include "project1.h"
#include "project2.h"
#include "project3.h"


int main(void)
{
    led_init();
    Init_ADC();
    TimerWave();
    UARTinit(103); 
    uint16_t temp;
    // Insert code

while(1)
    {
       if(BUTTON_SENSOR_ON) //Checking if the input bit to 7th bit of pinB is made 0 from 1 by pressing led
        {

            if(HEATER_ON) //Checking if the input bit to 6th bit of pinB is made 0 from 1 by pressing led
            {
                _delay_ms(20);
                SET_LED; //make 0th bit of port B as 1, makes led glow
                temp = Read_ADC(0);
                outputPWM(temp);
                _delay_ms(20);

            }
            else
            {
                _delay_ms(20);
                OCR1A = 0; //make PWM output 0 if switch is off
                CLEAR_LED; // make led off
            }
        }
        else
        {
                CLEAR_LED; //make led off
                OCR1A = 0; //make PWM output 0 if both switches are off
                _delay_ms(20);
        }
    }

 return 0;
}
