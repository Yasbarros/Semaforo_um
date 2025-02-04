#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"

#define LED_RED    13
#define LED_YELLOW 12
#define LED_GREEN  11

volatile int estado = 0;

void acenderLed(int led, int tempo) {
    gpio_put(led, 1);
    sleep_ms(tempo);
    gpio_put(led, 0);
}

bool repeating_timer_callback(struct repeating_timer *t) {
    gpio_put(LED_RED, 0);
    gpio_put(LED_YELLOW, 0);
    gpio_put(LED_GREEN, 0);

    switch (estado) {
        case 0:
            gpio_put(LED_RED, 1);
            printf("🚦 Semáforo: VERMELHO\n");
            break;
        case 1:
            gpio_put(LED_YELLOW, 1);
            printf("🚦 Semáforo: AMARELO\n");
            break;
        case 2:
            gpio_put(LED_GREEN, 1);
            printf("🚦 Semáforo: VERDE\n");
            break;
    }

    estado = (estado + 1) % 3;
    return true;
}

int main() {
    stdio_init_all();  // Inicializa a saída padrão

    gpio_init(LED_RED);
    gpio_init(LED_YELLOW);
    gpio_init(LED_GREEN);

    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, false, &timer);

    while (1) {
        printf("Sistema rodando!\n");
        sleep_ms(1000);
    }

    return 0;
}
