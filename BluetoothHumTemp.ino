#include <dht11.h> //includi libreria sensore umidità
#include <SoftwareSerial.h> //libreria di gestione del protocollo di trasmissione seriale
SoftwareSerial BT(10, 11);
dht11 DHT11; //dichiaro una variabile dell'oggetto dht11 
     
void setup() {
  BT.begin(9600); // velocita' di trasmissione sulla porta seriale emulata dalla
 
}

void loop() {
  int umidit = DHT11.read(7); //leggo i dati del sensore
  
  BT.println(DHT11.humidity);//con humidity presente nella libreria dht11 leggo l'umidità e la invio al bluetooth
  int sensorVal= analogRead(A0); //leggo la tensione sul piedo del sensore TMP36
  float temperature = ((sensorVal * 0.00488) - 0.5) / 0.01; //calcolo la temperatura 0.5 valore della tensione in uscita a 0 gradi, 
  //0.01 step di tensione ovvero la tensione deve aumentare di 10 mV per avere una variazione di 0.01 C                           
  BT.println();//invio una riga vuota al bluetooth
  BT.println(temperature); //invio il dato della temperatura al bluetooth
         
  delay(1000);  //ritardo 1 secondo per aggiornare i dati                  
}
