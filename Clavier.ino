/**************************************************************************
 * Nom du Programme      : Clavier.ino
 * Auteur                : Alban de Farcy de Pontfarcy
 * Date de création      : 03/12/2024
 * Dernière modification : 17/12/2024
 * Version               : 1.5
 * Description           :
 *    Ce programme a pour but de faire fontionner un clavier avec un mot de passe défini au préalable
 *
 * Pré-requis            :
 *    Installer la bibliothèque Keypad.h
 *
 * Copyright             :
 *    © 2024 Alban de Farcy de Pontfarcy
 **************************************************************************/

#include <Keypad.h>
#define COLS 4
#define ROWS 4

// Pin LED RGB
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
char k0 =  'E';
char k1 =  'B';
char k2 =  '6';
char k3 =  '9';

char key[4];
int essai = 3;

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
Serial.begin(9600);
Serial.println("Début du programme");
Serial.println("__________________");
Serial.println();
}

void loop()
{
  // Boucle pour entrer le code
  for (int i = 0; i < 4; i++)
  {
    while (!key[i])
    {
      key[i] = keypad.getKey();
    }
    analogWrite(led_B, 255);
    delay(125);
    analogWrite(led_B, 0);
  }

// Vérification du code entré
if(key[0] == k0 && key[1] == k1 && key[2] == k2 && key[3] == k3)
  {
    Serial.print("Le code");
    Serial.println(" est correct");
    Serial.println();
    
    analogWrite(led_V, 255);
    delay(1000);
    analogWrite(led_V, 0);
    
  essai = 3;
  
    for (int i = 0; i < 4; i++)
    {
      key[i] = 0;
    } 
  }
else
  {
    Serial.print("Le code ");
    
    for (int i = 0; i < 4; i++)
    {
      Serial.print (key[i]);
    }
    Serial.println(" n'est pas correct");
    essai--;
    Serial.print("Il vous reste ");
    Serial.print(essai);
    Serial.println(" essais");
    Serial.println();
    
    analogWrite(led_R, 255);
    delay(1000);
    analogWrite(led_R, 0);
    
    for (int i = 0; i < 4; i++)
    {
      key[i] = 0;
    } 
}
// Sécurité de temps d'attente si trop d'essais ont été effectués
if (essai == 0)
  {
    Serial.println("Vous avez effectué trop d'essais, veuillez attendre 5 secondes");
    
    analogWrite(led_R, 255);
    delay(5000);
    analogWrite(led_R, 0);
    
    essai = 3;
  }
}
