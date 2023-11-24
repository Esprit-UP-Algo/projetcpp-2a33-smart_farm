#include "DHT.h"
// Definit la broche de l'Arduino sur laquelle la 
// broche DATA du capteur est reliee 
#define DHTPIN 2
// Definit le type de capteur utilise
#define DHTTYPE DHT11
// Declare un objet de type DHT
// Il faut passer en parametre du constructeur 
// de l'objet la broche et le type de capteur
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  Serial.println("Initializing DHT sensor...");
  
  // Initialise la capteur DHT11
  dht.begin();
  
  Serial.println("DHT sensor initialized.");
}

void loop() {
  Serial.println("Reading data from DHT sensor...");

  // Recupere la temperature et l'humidite du capteur et l'affiche
  // sur le moniteur serie
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidite = ");
  Serial.print(humidity);
  Serial.println(" %");

  // Attend 10 secondes avant de reboucler
  delay(10000);
}