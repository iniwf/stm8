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

#ifndef  _LED_H
#define  _LED_H

#define  LEDPort  GPIOC
#define  LEDPin   (1 << 2) 



void LED_Init(void);
void LED_ON(void);
void LED_OFF(void);


#endif
