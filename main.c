#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

const uint PIN_LED = 14;
const uint PIN_PIR = 13;

int main() {
	bi_decl(bi_program_description("This is a program to read PIR"))
	
	stdio_init_all();
	
	gpio_init(PIN_LED);
	gpio_set_dir(PIN_LED, GPIO_OUT);
	
	gpio_init(PIN_PIR);
	gpio_set_dir(PIN_PIR, GPIO_IN);
	gpio_pull_up(PIN_PIR);
	
	while(1) {
		
		if (gpio_get(PIN_PIR)) {
			printf("Motion detected!\n");
			gpio_put(PIN_LED, 1);
			sleep_ms(50);
		} else {
			printf("No detection!\n");
			gpio_put(PIN_LED, 0);
			sleep_ms(50);
		}
		
	}
}
