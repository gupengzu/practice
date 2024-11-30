 
 //按键时小灯亮，松开后小灯灭
 HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin);
    if(HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)==GPIO_PIN_RESET)
    {
      HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_SET);
    }
    else
    {
      HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_RESET);

//按键后小灯由亮变灭，由灭变亮。
      while (1)
      {
          if (HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET)
          {
              HAL_GPIO_TogglePin(LED_B_GPIO_Port, LED_B_Pin);
              while (HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == RESET)
              {

              }
          }
      }