#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Estrutura para os pinos
typedef struct {
    uint red;
    uint yellow;
    uint green;
    uint time;
} Pin;

// Definição dos pinos globais
static Pin pins = {
    .red = 11,
    .yellow = 12,
    .green = 13,
    .time = 3000 // Tempo em milissegundos
};

// Protótipos de funções
void inicializarHardware(Pin* config);
bool repeating_timer_callback(struct repeating_timer* t);

// Variável para armazenar o estado atual do semáforo
static int current_state = 0;

// Inicializa os pinos GPIO
void inicializarHardware(Pin* config) {
    gpio_init(config->red);
    gpio_set_dir(config->red, GPIO_OUT);
    gpio_put(config->red, 0);

    gpio_init(config->yellow);
    gpio_set_dir(config->yellow, GPIO_OUT);
    gpio_put(config->yellow, 0);

    gpio_init(config->green);
    gpio_set_dir(config->green, GPIO_OUT);
    gpio_put(config->green, 0);
}

// Callback para temporizador repetitivo
bool repeating_timer_callback(struct repeating_timer* t) {
    switch (current_state) {
        case 0: // Vermelho
            gpio_put(pins.red, 1);
            gpio_put(pins.yellow, 0);
            gpio_put(pins.green, 0);
            current_state = 1;
            break;
        case 1: // Amarelo
            gpio_put(pins.red, 0);
            gpio_put(pins.yellow, 1);
            gpio_put(pins.green, 0);
            current_state = 2;
            break;
        case 2: // Verde
            gpio_put(pins.red, 0);
            gpio_put(pins.yellow, 0);
            gpio_put(pins.green, 1);
            current_state = 0;
            break;
    }
    return true; // Retorna true para continuar o temporizador
}

// Programa principal
int main() {
    stdio_init_all(); // Inicializa a comunicação serial
    inicializarHardware(&pins); // Inicializa o hardware

    // Inicializa o temporizador
    struct repeating_timer timer;
    add_repeating_timer_ms(pins.time, repeating_timer_callback, NULL, &timer);

    // Loop principal para enviar mensagens pela serial
    while (true) {
        printf("Estado atual: %d\n", current_state);
        sleep_ms(1000); // Atraso de 1 segundo
    }
}
