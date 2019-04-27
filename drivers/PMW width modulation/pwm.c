void PWM_Init(void){
 int volatile delay;
 
 SYSCTL_RCC_R  &= ~(SYSCTL_RCC_USEPWMDIV); //use system clock as PWM clock
 
 SYSCTL_RCGC0_R     |= (1<<20);     //activate PWM module 0 clock
 SYSCTL_RCGC2_R     |= (1<<1);      //activate port B clock
 delay = SYSCTL_RCGC2_R;            //allow time for clock to stabalize
 GPIO_PORTB_DR4R_R  |= (1<<6);
 GPIO_PORTB_DEN_R   |= (1<<6);      //enable digital output on PB6
 GPIO_PORTB_AFSEL_R |= (1<<6);      //activate  Alternate function on PB6
 GPIO_PORTB_PCTL_R  |= (0x04000000);//set alternate peripheral to PWM
 
 PWM0_0_CTL_R   &= ~(1<<0);         //disable pwm block until ready to use
 PWM0_0_CTL_R   &= ~(1<<1);         //set count-down mode
 PWM0_0_GENA_R  |=  (0xC2);         //drive pwm low on CmpA and high on zero(low logic)
 PWM0_0_LOAD_R   =  (1000-1)        //1000 (80khz pwm)
 PWM0_0_CMPA_R   =  (500-1);        //set couter value at which CmpA triggers (any value now)
 PWM0_0_CTL_R   |=  (0x01);         //enable pwm block
 PWM0_ENABLE_R  |=  (PWM_ENABLE_PWM0EN);//Enable pwm output to M0PWM0
}