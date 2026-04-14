#ifndef LED_h
#define LED_h

#include <Arduino.h>

class LED
{
  private:
       /**
       * @brief processa o desligamento temporizado.
       */
      void funcaoApagarNoTempo();

      /**
       * @brief processa a logica de piscada do LED
       */
      void funcaoPiscar();

  public:

      /**
       * @brief constroi um objeto LED.
       * @param pin Numero do pino digital onde o LED esta conectado.
       */
      LED(uint8_t pin); 

      /**
       * @brief Liga o LED continuamente.
       */
      void acender();

      /**
       * @brief liga o LED por um tempo determinado.
       * @param tempoLigado Tempo, em milissegundos, que o LED ficara ligado
       */
      void acender(uint32_t tempoLigado);

      /**
       * @brief Desliga o LED e cancela modos automaticos.
       */
      void apagar();

      /**
       * @brief Liga e desliga o LED por um determinado perido de tempo.
       */
      void piscar();

      /**
       * @brief O LED pisca de acordo sua frequencia.
       * @param freq frequencia que o LED pisca. (em hz)
       */
      void piscar(float freq);

      /**
       * @brief O LED pisca de acordo sua frequencia.
       * @param freq frequencia que o LED pisca. (em hz)
       * @param repeticoes quantidade de vez que o LED vai piscar.
       */
      void piscar(float freq, uint16_t repeticoes);

      /**
       * @brief ele liga/desliga
       */
      void alternar();

      /**
       * @brief permite mudar o estado do LED
       * @param estado - estado
       */
      void setEstado(bool estado);

      /**
       * @brief retorna o pino atual
       */
      uint8_t getPino();

      /**
       * @brief Responsavel por mundar o estdo LED e atualizar modos automaticos
       */
      void update();

};

#endif