#include "LED.h"

LED::LED(uint8_t pin) :
  pino(pin),
  estado(LOW),
  apagarNoTempo(false),
  apagarNoMomento(false),
  estadoPiscar(false),
  tempoEspera(0),
  tempoAnteriorPiscar(0),
  repeticoes(0)

{
 
  pinMode(pino, OUTPUT);
}

void LED::acender()
{
  estado = HIGH;
  apagarNoTempo=false;
  estadoPiscar=false;
}

void LED::acender(uint32_t tempoLigado)
{
  estado = HIGH;
  apagarNoTempo = true;
  apagarNoMomento = millis() + tempoLigado;
  estadoPiscar=false;
}

void LED::apagar()
{
  estado = LOW;
  apagarNoTempo=false;
  estadoPiscar=false;
}

void LED::alternar()
{
  estado = !estado;
   apagarNoTempo=false;
  estadoPiscar=false;
}

void LED::setEstado(bool estado)
{
  this->estado = estado;
  apagarNoTempo=false;
  estadoPiscar=false;
}

uint8_t LED::getPino()
{
  return pino;
  apagarNoTempo=false;
  estadoPiscar=false;
}

void LED::update()
{
    if(apagarNoTempo)  funcaoApagarNoTempo();
    if (estadoPiscar)  funcaoPiscar();
    

  digitalWrite(pino, estado);
}

void LED::piscar()
{
  estadoPiscar = true;
  tempoEspera = 500;
  tempoAnteriorPiscar = millis();
  estado = HIGH;
   apagarNoTempo=false;
   repeticoes = -1;
}

void LED::piscar(float freq)
{
   estadoPiscar = true;
  tempoEspera = (1000.0f / (2.0f * freq));
  tempoAnteriorPiscar = millis();
  estado = HIGH;
   apagarNoTempo=false;
   repeticoes = -1;
}

void LED::piscar(float freq, uint16_t repeticoes)
{
   estadoPiscar = true;
  tempoEspera = (1000.0f / (2.0f * freq));
  tempoAnteriorPiscar = millis();
  estado = HIGH;
  this -> repeticoes = repeticoes * 2 ;
   apagarNoTempo=false;
   
}

void LED::funcaoApagarNoTempo()
{
  if (apagarNoTempo)
  {
    if (millis() >= apagarNoMomento)
    {
      estado = LOW;
      apagarNoMomento = false;
    }
  }
}

void LED::funcaoPiscar()
{
  if (millis() - tempoAnteriorPiscar >= tempoEspera)
      {
        estado = ! estado;
        tempoAnteriorPiscar = millis();
        if (repeticoes > 0)
        {
           repeticoes --;
           if (repeticoes == 0)
           {
             estadoPiscar = false;
             estado = LOW;

           }
           
        }
        
      }
}
