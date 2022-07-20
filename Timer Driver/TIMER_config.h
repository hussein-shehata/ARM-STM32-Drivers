/*******************************************
 Author     : Taher Mohamed
 Data       : 13/11/2021
 Descrition : config file of Timer driver 
********************************************/

#ifndef _TIMER_CONFIG_H
#define _TIMER_CONFIG_H
#include "TIMER_private.h"
#include "TIMER_interface.h"

TIM_ConfigType Timer2_config= {
    /************* PeriodVal ***************/
    65000,

    /************* PrescalerVal ***************/
    0,

    /************* Update_event_State ***************/
    /*
        Disable_Update_Event
	    Enable_Update_Event
    */
    Enable_Update_Event,

    /************* AutoReloadBuffer ***************/
    /*
        Disable_ARR_Buffer
	    Enable_ARR_Buffer
    */
    Disable_ARR_Buffer,

    /************* Center_Aligned_Mode ***************/
    /*
        Edge_Aligned_Mode
	    Center_Aligned_Mode_1
	    Center_Aligned_Mode_2
	    Center_Aligned_Mode_3    
    */
    Edge_Aligned_Mode,

    /************* Counter_State ***************/
    /*
        Disable_CNT,
	    Enable_CNT
    */
    Enable_CNT,

    /************* Direction_State ***************/
    /*
        UpCounter
        DownCounter
    */
    UpCounter,

    /************* Clock_Div_Factor ***************/
    /*
        Div_1,
        Div_2,
        Div_3
    */
    Div_1,

    /************* OnePulse_Mode ***************/
    /*
        Counter_Not_stopped_Update_Event
	    Counter_stopped_Update_Event
    */
    Counter_Not_stopped_Update_Event,

    /************* UDI_State ***************/
    /*
        Disable_TIM_Update_Interrupt
	    Enable_TIM_Update_Interrupts
    */
    Enable_TIM_Update_Interrupts
};

#endif
