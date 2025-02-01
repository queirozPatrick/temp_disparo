// link wokwi: https://wokwi.com/projects/421705059146424321

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define led_blue 12
#define led_red 13
#define led_green 11
#define button 5

volatile bool timer_active = false;

// Função de callback para desligar os LEDs
int64_t turn_off_leds_1(alarm_id_t id, void *user_data) {
    gpio_put(led_blue, 0);
    return 0;
}

int64_t turn_off_leds_2(alarm_id_t id, void *user_data) {
    gpio_put(led_red, 0);
    return 0;
}

int64_t turn_off_leds_3(alarm_id_t id, void *user_data) {
    gpio_put(led_green, 0);
    timer_active = false; // Permite nova ativação do botão
    return 0;
}

// Função de debounce do botão
void debounce_button(uint gpio, uint32_t events) {
    static absolute_time_t last_press_time = 0;
    absolute_time_t now = get_absolute_time();
    if (absolute_time_diff_us(last_press_time, now) < 200000) return;
    last_press_time = now;
    
    if (!timer_active) {
        timer_active = true;
        gpio_put(led_blue, 1);
        gpio_put(led_red, 1);
        gpio_put(led_green, 1);
        add_alarm_in_ms(3000, turn_off_leds_1, NULL, false);
        add_alarm_in_ms(6000, turn_off_leds_2, NULL, false);
        add_alarm_in_ms(9000, turn_off_leds_3, NULL, false);
    }
}

int main() {
    stdio_init_all();
    
    gpio_init(led_blue);
    gpio_init(led_red);
    gpio_init(led_green);
    gpio_set_dir(led_blue, GPIO_OUT);
    gpio_set_dir(led_red, GPIO_OUT);
    gpio_set_dir(led_green, GPIO_OUT);
    
    gpio_init(button);
    gpio_set_dir(button, GPIO_IN);
    gpio_pull_up(button);
    gpio_set_irq_enabled_with_callback(button, GPIO_IRQ_EDGE_RISE, true, debounce_button);
    
    while (1) {
        tight_loop_contents();
    }
}