/**
  *文件名: cheese_input.c
  *创建时间: 2024-03-01 16:37:48
  *作者: ZZSZSZSZZ
  *描述: cheese_ui输入库
*/

/* include */
#include "cheese_input.h"

struct Button button1;

uint8_t read_button_GPIO(uint8_t button_id)
{
	// you can share the GPIO read function with multiple Buttons
	switch(button_id)
	{
		case 0:
			return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
			break;

		default:
			return 0;
			break;
	}
}

void button_callback(void *button)
{
  uint32_t btn_event_val;
  btn_event_val = get_button_event((struct Button *)button);

  switch(btn_event_val)
  {
  case PRESS_DOWN:
    break;

  case PRESS_UP:
    break;

  case PRESS_REPEAT:
    break;

  case SINGLE_CLICK:
      Input();
    break;

  case DOUBLE_CLICK:
      // Buck();
      Jamp();
    break;

  case LONG_PRESS_START:
      // Input();
    break;

  case LONG_PRESS_HOLD:
      Buck();
    break;
  }
}

void buttonInit()
{
  button_init(&button1, read_button_GPIO, 0, 0);
  button_attach(&button1, SINGLE_CLICK, button_callback);
  button_attach(&button1, DOUBLE_CLICK, button_callback);
  button_attach(&button1, LONG_PRESS_HOLD, button_callback);
  button_start(&button1);
}

/* define */

/* variables */

/* function prototype */

