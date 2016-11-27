/*************************************
              今明电子
凡在本店购买满30元，下次购买即可返还5角；
      满50元，下次购买即可返还1元；
     满100元，下次购买即可返还2元；
     满150元，下次购买即可返还4元；
      满200元，下次购买即可免邮
http://shop106001793.taobao.com/search.htm?spm=a1z10.5.w5002-3375901029.1.l1TXSl&search=y
              stm8s105
               V1.1
             2013.9.8
**************************************/

#include "PWM.h"
#include "ALL_Includes.h"


/**********************************
函数功能：PWM初始化
输入参数：无
输出参数：无
备    注：定时器2通道3 输出脚为PA3
**********************************/
void PWM_Init(void)
{
    /**********************************************************
    计数器频率 = CPU时钟 / 分频器 = 16MHZ / 16 = 1MHZ
    PWM频率 = 1MHZ / (TIM2_ARR + 1) = 1MHZ / (999 + 1) = 1KHZ
    PWM占空比 = [TIM2_CCR1/(TIM2_ARR + 1)]*100 = 50%
    ***********************************************************/   
    TIM2-> CCMR3 |= BIT(6)|BIT(5)|BIT(3);//pwm模式1、预装载使能，通道3的设置，其它通道需要修改 
    TIM2-> PSCR |= 4;//预分频器
    TIM2-> ARRH = 0x03;//装载计数值高位 
    TIM2-> ARRL = 0xE7;////装载计数值低位

    TIM2-> CCR3H = 0x01;//比较值高位，通道3的设置，其它通道需要修改 
    TIM2-> CCR3L = 0xF4;//比较值低位，通道3的设置，其它通道需要修改  
    
    TIM2-> CCER2 |= BIT(0);//输出使能,通道3的设置，其它通道需要修改
      
    TIM2-> CR1 |= BIT(0);//计数器使能
}
