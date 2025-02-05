# Controle de Semáforo com Temporizador - RP2040

## Tarefa: Controle de LEDs com Temporizador Repetitivo

### Descrição

Este repositório contém o código-fonte de um projeto desenvolvido em Linguagem C, utilizando o Pico SDK, para simular o funcionamento de um semáforo com LEDs conectados a um microcontrolador Raspberry Pi Pico. O projeto foi testado no simulador **Wokwi** e utiliza um temporizador repetitivo (`repeating_timer`) para alternar automaticamente entre os estados do semáforo em intervalos regulares.

A solução implementa estratégias para:  
1. Controle dos LEDs para simular o comportamento de um semáforo.  
2. Alternância automática entre os estados (vermelho, amarelo e verde).  
3. Uso de temporizadores repetitivos para intervalos definidos.  
4. Exibição de mensagens na porta serial a cada segundo.

## Funcionalidades

1. **Simulação do Semáforo**:
   - O LED **vermelho** acende por 3 segundos.  
   - O LED **amarelo** acende por 3 segundos.  
   - O LED **verde** acende por 3 segundos.  
   - O ciclo se repete continuamente.  

2. **Mensagens na Porta Serial**:
   - Exibe mensagens na porta serial a cada 1 segundo, informando o estado atual do semáforo.  

3. **Temporizador Repetitivo**:
   - Controle preciso dos intervalos de tempo para alternância entre os LEDs.  

4. **Simulação no Wokwi**:
   - Testado no simulador Wokwi para validar o funcionamento.  

## Pré-requisitos

1. **Hardware Necessário**:
   - Raspberry Pi Pico (RP2040).  
   - LEDs (vermelho, amarelo e verde).  
   - Resistores apropriados.  

2. **Ambiente de Desenvolvimento**:
   - Visual Studio Code ou outro editor compatível.  
   - Pico SDK configurado.  
   - Compilador GCC para C.  
   - Ferramentas de gravação e execução no Raspberry Pi Pico.  
   - Simulador Wokwi (https://wokwi.com) para testes virtuais.  

## Como Usar

1. **Clone o repositório**:

    ```bash
    git clone https://github.com/LuisMarioRC/tarefaTemporizador.git
    ```

2. **Navegue até o diretório do projeto**:

    ```bash
    cd tarefaTemporizador
    ```

3. **Compile o código com o Pico SDK**:
   - Certifique-se de que o Pico SDK está configurado corretamente.  
   - No terminal, execute:  
     ```bash
     mkdir build
     cd build
     cmake ..
     make
     ```

4. **Grave o programa no Raspberry Pi Pico**:
   - Conecte o Pico ao computador.  
   - Segure o botão BOOTSEL enquanto conecta para entrar no modo de armazenamento USB.  
   - Arraste o arquivo `.uf2` gerado na pasta `build` para o dispositivo.  

5. **Teste no Wokwi**:
   - Caso deseje testar no simulador Wokwi, importe o código e configure os pinos de acordo com o projeto.  

6. **Execute o programa**:
   - Conecte os LEDs ao Pico nos pinos configurados no código (vermelho, amarelo e verde).  
   - Veja o semáforo em funcionamento e acompanhe as mensagens exibidas na porta serial.  

### Líder do Projeto

- <b><a href="https://github.com/LuisMarioRC">Luis Mario</a></b>
