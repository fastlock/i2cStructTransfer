/* MASTER
 * Esempio di "Master" che legge i dati da uno "Slave"
 * il ruolo di di questa periferica è di interrogare ad un indirizzo
 *  di un altro dispositivo connesso alla linea i2c
 * ---------------------------------------------------
 * CONNESSIONI:
 * NODE MCU->ARDUINO UNO
 * SDA:D1->A4(Analog pin)
 * SCL:D2->A5(Analog pin)
 * GND->GND(il ground DEVE essere condiviso)
*/

#include <I2C_Anything.h>
#include<Wire.h>

#define SlaveAddress 8 //definisco indirizzo periferica

void setup() {
  Wire.begin(D1, D2); // inizializzo i pin sda, scl per la comunicazione
  Serial.begin(9600);  // inizializzo la comunicazione seriale solo per DEBUG
}
/*
 * Questa è la struttura dati da inviare
 * qui si inserisce il prototipo del pacchetto che riceverà il master
 * ##IMPORTANTE##
 * MASTER E SLAVE DEVONO AVERE LO STESSO PROTOTIPO
 */
struct SensorPacket{
    float Temp;
    float lum;
    float noise;
  };
SensorPacket myData;//creo instanza della struttura 

void loop(){
  
   Wire.requestFrom(SlaveAddress, sizeof(SensorPacket));    // Richiedo struttura allo slave (attenzione a come è fatta la funzione:Wire.requestFrom(indirizzo slave,byte da ricevere) 
    delay(100);
    I2C_readAnything (myData);//quello che leggo riempie la mia struttura "vuota"
    

  //DEBUG
  Serial.println("----------");
  Serial.print("TEMPERATURA:\t");
  Serial.println(myData.Temp);
  Serial.print("LUMINOSITÀ:\t");
  Serial.println(myData.lum);
  Serial.print("RUMORE:\t");
  Serial.println(myData.noise);
  Serial.println("----------");
  delay(1000);
  

}

