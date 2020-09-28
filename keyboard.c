/** Put this in the src folder **/
#include "keyboard.h"

//--------Select input group--------
//#define MatrixKeyInput GPIOA
//#define MatrixKeyInput GPIOB
//#define MatrixKeyInput GPIOC
#define MatrixKeyInput GPIOD
//#define MatrixKeyInput GPIOE

//--------Select output group--------
#define MatrixKeyOutput GPIOA
//#define MatrixKeyOutput GPIOB
//#define MatrixKeyOutput GPIOC
//#define MatrixKeyOutput GPIOD
//#define MatrixKeyOutput GPIOE


int PinOut[4] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3};
 
int PinIn[4] = {GPIO_PIN_6, GPIO_PIN_7, GPIO_PIN_8, GPIO_PIN_9};

const char value[4][4] = 
{ {'1', '4', '7', '*'},
  {'2', '5', '8', '0' },
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'}
};


char keyboard_read(void) {
	
	for (int i = 1; i <= 4; i++) //col
  {
		HAL_GPIO_WritePin(MatrixKeyOutput, PinOut[i - 1], RESET);
		
		for (int j = 1; j <= 4; j++) //row
    {
      if (HAL_GPIO_ReadPin(MatrixKeyInput, PinIn[j - 1]) == RESET) 
      {
				return value[i - 1][j - 1];
        HAL_Delay(175);
      }
    }
		
		HAL_GPIO_WritePin(MatrixKeyOutput, PinOut[i - 1], SET);
	}
}
