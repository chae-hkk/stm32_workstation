//HRE로 깜빡이는 속도 바꾸기
#include "main.h"

int main(void){
  RCC->CR |= (1UL << 8); //HSI on
  while((RCC->CR & 0x00000400) == 0); //0100 0000 0000 

  RCC->CFGR |= 0x00000000; //SYSCLK == HSI
  RCC->CFGR |=0x00000900; //HPRE = 4 1/4로 주파수 낮춤

  

  RCC->IOPENR |= (1UL << 0); //portA clock 실행

  GPIOA->MODER &= ~(3UL << (2*5)); // stm32 초기 설정11을 00으로 변경하기 위함
  
  GPIOA->MODER |= (1UL << (2*5)); //portA output Mode
  
  GPIOA->OSPEEDR |= (1UL << (2*5));

  while(1){ //LED Blinking Process
    GPIOA->ODR |= (1UL << 5);
    for(uint32_t i = 0; i < 1000000; i++);
    GPIOA->ODR &= ~(1UL << 5);
    for(uint32_t i = 0; i< 1000000; i++);
  }
}


