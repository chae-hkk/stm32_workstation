#include "main.h"

//PA5로 LED blinking

//단계
//SYSCLK 설정하기
//A 포트 클럭 켜기
//MODE register로 핀의 모드 설정
//속도 설정
//while 문 활용, ODR로 켜고 끄기

int main(void){
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


//문제: 너무 blinking이 깔끔하지 않고 빠름