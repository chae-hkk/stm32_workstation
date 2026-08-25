

//포인터로 레지스저 직접 제어
//주소 정의 해주기

#define GPIOA_BASE 0x50000000UL
#define RCC_BASE 0x40021000UL

//GPIO 레지스터 offset
#define GPIOA_MODER_OFFSET 0x00UL
#define GPIOA_OTYPER_OFFSET 0x04UL
#define GPIOA_OSPEEDR_OFFSET 0x08UL
#define GPIOA_PUPDR_OFFSET 0x0cUL
#define GPIOA_IDR_OFFSET 0x10UL
#define GPIOA_ODR_OFFSET 0x14UL


//RCC 레지스터 offset
#define RCC_IOPENR_OFFSET 0x34UL

//레지스터 주소 정의(포인터로 캐스팅)
#define GPIOA_MODER (*((volatile uint32_t *) (GPIOA_BASE + GPIOA_MODER_OFFSET)))
#define GPIOA_OTYPER (*((volatile uint32_t *) (GPIOA_BASE + GPIOA_OTYPER_OFFSET)))
#define GPIOA_OSPEEDR (*((volatile uint32_t *)( GPIOA_BASE + GPIOA_OSPEEDR_OFFSET)))
#define GPIOA_PUPDR (*((volatile uint32_t *)( GPIOA_BASE + GPIOA_PUDER_OFFSET)))
#define GPIOA_IDR (*((volatile uint32_t *)( GPIOA_BASE + GPIOA_IDR_OFFSET)))
#define GPIOA_ODR (*((volatile uint32_t *)( GPIOA_BASE + GPIOA_ODR_OFFSET)))

#define RCC_IOPENR (*((volatile uint32_t *)( RCC_BASE + RCC_IOPENR_OFFSET)))

typedef struct {
  volatile uint32_t MODER;
  volatile uint32_t OTYPER;
  volatile uint32_t OSPEEDR;
  volatile uint32_t PUPDR;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
} GPIOA_TypeDef;

#define GPIOA ((GPIOA_TypeDef *) GPIOA_BASE)