#ifndef LED_h
#define LED_h

#include <Arduino.h>

class LED
{
  private:
      uint8_t pino;
      bool estado;

      bool apagarNoTempo;
      uint32_t apagarNoMomento;
      bool estadoPiscar;

      uint32_t tempoEspera;
      uint32_t tempoAnteriorPiscar;
      uint16_t repeticoes;

      void funcaoApagarNoTempo();
      void funcaoPiscar();

  public:
      LED(uint8_t pin); // Metodo construtor

      void acender();
      void acender(uint32_t tempoLigado);

      void apagar();

      void piscar();
      void piscar(float freq);
      void piscar(float freq, uint16_t repeticoes);

      void alternar();

      void setEstado(bool estado);

      uint8_t getPino();

      void update();

};

#endif