#include "main.h"

//스위치 입력 상태에 따라 LED ON/OFF 하기
//LED(PA5), push-button(PC13)


int main(void){
  RCC->IOPENR |= (1UL << 0); //portA clock 실행
  RCC->IOPENR |= (1UL << 2); //portC clock 실행

  GPIOA->MODER &= ~(3UL << (2*5)); // stm32 초기 설정11을 00으로 변경하기 위함
  GPIOC->MODER &= ~(3UL << (2*13)); //stm32초기 설정 변경&13번 register 00으로 설정

  GPIOA->MODER |= (1UL << (2*5)); //portA output Mode

  GPIOA->OSPEEDR |= (1UL << (2*5));


  GPIOC->PUPDR &= ~(3UL << (2*13)); //bit 26, 27 clear
  GPIOC->PUPDR |= (1UL << (2*13)); //13번 pin pull up 설정 (bit 26 = 1)

  while(1){ //read register & control LED
    if((GPIOC->IDR & 0x00002000) == 0){ //만약 IDR 13bit가 0이면 스위치 눌림

      GPIOA->ODR |= (1UL << 5);  //스위치 눌림 -> bit 5 = 0;

    }
    else{ //스위치 꺼짐
      GPIOA->ODR &= ~(1UL << 5);//bit 5 = 1

    }
  }
}


