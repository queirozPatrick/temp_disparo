# Controle de LEDs com Temporizador One-Shot

Este projeto foi desenvolvido utilizando o microcontrolador Raspberry Pi Pico e a ferramenta educacional BitDogLab, com base em um projeto proposto pelo EmbarcaTech. O objetivo é acionar três LEDs (vermelho, azul e verde) através do acionamento de um botão, com temporização de desligamento utilizando a função `add_alarm_in_ms()` do Pico SDK.

📝 **Enunciado do Projeto**
O objetivo é criar um sistema que acenda três LEDs simultaneamente ao pressionar um botão, e os desligue de forma sequencial com intervalos de 3 segundos para cada LED.

🔧 **Componentes Utilizados**
- **Microcontrolador**: Raspberry Pi Pico
- **LED Azul**: Conectado à GPIO 12
- **LED Vermelho**: Conectado à GPIO 13
- **LED Verde**: Conectado à GPIO 11
- **Botão**: Conectado à GPIO 5
- **Resistores**: 330 Ω para os LEDs

- **Link Wokwi:**
  <https://wokwi.com/projects/421705059146424321>

🎯 **Funcionalidades do Projeto**

🔹 **Acionamento dos LEDs**
- Quando o botão é pressionado, os três LEDs acendem simultaneamente.
- Após 3 segundos, o LED azul apaga.
- Após 6 segundos, o LED vermelho apaga.
- Após 9 segundos, o LED verde apaga, permitindo um novo acionamento.

🔹 **Temporização com Função One-Shot**
- O desligamento dos LEDs ocorre de forma escalonada utilizando a função `add_alarm_in_ms()`, que cria temporizadores de execução única.

🔹 **Debounce do Botão**
- Implementado para evitar leituras falsas devido a ruídos elétricos no acionamento do botão.

📂 **Organização do Código**

📌 **Arquivos Incluídos**
- `main.c`: Código principal com a implementação do controle de LEDs, temporizadores e debounce do botão.

📋 **Requisitos do Projeto**

🔹 **Temporizador One-Shot**
- Cada LED possui um temporizador único que desliga a saída correspondente no tempo correto.

🔹 **Configuração de GPIOs**
- LEDs configurados como saída.
- Botão configurado como entrada com pull-up interno ativado.

🚀 **Como Executar o Projeto**

### **Pré-requisitos**
- Microcontrolador Raspberry Pi Pico.
- Ambiente de desenvolvimento configurado com Pico SDK.

### **Passos**
1. Clone este repositório:
   ```sh
   git clone <https://github.com/queirozPatrick/temp_disparo>
   ```
2. Compile e carregue o código no Raspberry Pi Pico.
3. Conecte os LEDs e o botão nas GPIOs correspondentes.
4. Pressione o botão e observe os LEDs acendendo e apagando em sequência.

