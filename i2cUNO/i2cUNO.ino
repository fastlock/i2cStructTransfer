//Esempio di "slave" che invia i dari solo su richiesta del master
#include <Wire.h>
#include <I2C_Anything.h>
void setup() {
  Serial.begin(9600);           //Solo per avere un feedback per l'eventuale DEBUG
  Wire.begin(8);                // Inizializzo lo slave con l'indirizzo di linea #8
  Wire.onRequest(requestEvent); // alla richiesta esegui la funzione requestEvent
}
/*
 * Questa è la struttura dati da inviare
 * qui si inserisce il prototipo del pacchetto che riceverà il master
 * ##IMPORTANTE##
 * MASTER E SLAVE DEVONO AVERE LO STESSO PROTOTIPO
 * A4 (SDA), A5 (SCL)
 */
struct SensorPacket{
    float Temp;//definisco le variabili da inviare
    float lum;
    float noise;
  };
SensorPacket myData;//creo un instanza della struttura 
void loop() {
  myData.Temp=18.24;//riempio la struttura con dei dati finti
  myData.lum=2.3;
  myData.noise=200.01;
  //delay(100);
}

/*
 * La funzione requestEvent() viene eseguita se
 * sulla linea,il master interroga l'indirizzo impostato
 * nel setup()
 */
void requestEvent() {
  int i=0;
  Serial.println("sending data");//DEBUG
    I2C_writeAnything (myData);//con questa funzione invio alla linea la struttura già preparata
  
  // as expected by master
}
