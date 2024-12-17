/**************************************************************************
 * Nom du Programme      : Clavier.ino
 * Auteur                : Alban de Farcy de Pontfarcy
 * Date de création      : 03/12/2024
 * Dernière modification : 11/12/2024
 * Version               : 1.5
 * Description           :
 *   Ce programme a pour but de faire fontionner un clavier avec un mot de passe défini au préalable
 *
 * Pré-requis            :
 * Installer la bibliothèque Keypad.h
 *
 * Copyright             :
 *   © 2024 Alban de Farcy de Pontfarcy
 **************************************************************************/
#include <Keypad.h>
#define COLS 4
#define ROWS 4

const int led_R = A0;
const int led_V = A1;
const int led_B = A2;

char keys[ROWS] [COLS] =
{
  {'1', '2', '3', 'F'},
  {'4', '5', '6', 'E'},
  {'7', '8', '9', 'D'},
  {'A', '0', 'B', 'C'}
};

byte rowPins[ROWS] = {8, 9, 10, 11};
byte colPins[COLS] = {3, 4, 5, 6};

// Mot de passe :
char k1 =  'E';
char k2 =  'B';
char k3 =  '6';
char k4 =  '9';

char key[5];
char key1;
char key2;
char key3;
char key4;
int securite = 0;

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
Serial.begin(9600);
Serial.println("Début du programme ");
Serial.println();
}

void loop()
{
  for (int i = 1; i < 5; i++)
  {
    while (!key[i])
    {
      key[i] = keypad.getKey();
    }
    analogWrite(led_B, 255);
    delay(100);
    analogWrite(led_B, 0);
  }

if(key[1] == k1 && key[2] == k2 && key[3] == k3 && key[4] == k4)
  {
    Serial.print("Le code");
    Serial.println(" est correct");
    Serial.println();
    
    analogWrite(led_V, 255);
    delay(1000);
    analogWrite(led_V, 0);
    
  securite = 0;
  
    for (int i = 1; i < 5; i++)
    {
      key[i] = 0;
    } 
  }
else
  {
    Serial.print("Le code ");
    
    for (int i = 1; i < 5; i++)
    {
      Serial.print (key[i]);
    } 
    Serial.println(" n'est pas correct");
    Serial.println();
    
    analogWrite(led_R, 255);
    delay(500);
    analogWrite(led_R, 0);
    
    securite++;
    for (int i = 1; i < 5; i++)
    {
      key[i] = 0;
    } 
}

if (securite == 3)
  {
    Serial.println("Vous avez effectué trop d'essais, veuillez attendre 5 secondes");
    
    analogWrite(led_R, 255);
    delay(5000);
    analogWrite(led_R, 0);
    
    securite = 0;
  }
}
