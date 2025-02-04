# Sistema de Controle de Semáforo com Raspberry Pi Pico 🚦

Este projeto implementa um controle de semáforo simples usando Raspberry Pi Pico e LEDs. A lógica do semáforo alterna entre as cores vermelho, amarelo e verde com intervalos definidos, simulando um ciclo padrão.

## 📋 Descrição
O sistema utiliza a biblioteca `pico/stdlib.h` para controlar os LEDs conectados aos pinos GPIO da Raspberry Pi Pico. Um temporizador repetitivo (`repeating_timer`) é configurado para alternar entre os estados do semáforo a cada 3 segundos.

### 🔧 Funcionalidades
- **Ciclo de Semáforo**: O sistema alterna entre as cores:
  - **Vermelho**: Indica parada.
  - **Amarelo**: Indica atenção.
  - **Verde**: Indica permissão para prosseguir.
- **Temporizador Repetitivo:** Mantém o ciclo funcionando continuamente.
- Mensagens no terminal para monitoramento do estado atual.

---

## ⚙️ Hardware Necessário
- 1x Raspberry Pi Pico
- 1x LED Vermelho
- 1x LED Amarelo
- 1x LED Verde
- Resistores de 220 Ω
- Protoboard e fios jumpers

---

## 🚀 Como Usar
### 1. **Montagem do Circuito**
- Conecte os LEDs nos pinos GPIO da Raspberry Pi Pico conforme abaixo:
  - LED Vermelho -> GPIO 13
  - LED Amarelo -> GPIO 12
  - LED Verde -> GPIO 11

### 2. **Compilação e Upload**
1. Instale o SDK do Raspberry Pi Pico.
2. Compile o código usando o CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
