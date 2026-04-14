# Biblioteca LED

Essa biblioteca e uma maneira de controlar não bloqueante de LED com Arduino e ESP32

a classe "LED" 

• Ligar o LED continuamente

• Ligar o LED por tempo determinado

• Apagar

• Alternar estado

• Piscar continuamente

• piscar uma quantidade definida de vezes

O funcionamente é não bloqueante usando `millis()`.
Por isso, o metodo `update()` deve ser chamado repetidamente deve ser chamado repetidamente dentro do `loop()`.

---

## Estrutura da Biblioteca

```text
LED/
├── exemples
├── src
│    ├── LED.cpp
│    └──LED.h
├── library.json
├── LICENSE
└── README.md