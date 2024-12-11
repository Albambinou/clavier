/**************************************************************************
 * Nom du Programme      : Clavier.ino
 * Auteur                : Alban de Farcy de Pontfarcy
 * Date de création      : 03/12/2024
 * Dernière modification : 11/12/2024
 * Version               : 1.5
 * Description           :
 *   Ce programme a pour but de faire fontionner un clavier avec un mot de passe défini au préalable
 *
 * Utilisation           :
 *   Instructions pour exécuter ou utiliser le programme, y compris les 
 *   dépendances nécessaires, les paramètres en ligne de commande, etc.
 *   Par exemple : Exécuter avec Python 3.9 ou plus récent : `python main.py`.
 *
 * Pré-requis            :
 * Installer la bibliothèque Keypad.h
 *
 * Copyright             :
 *   © 2024 Alban de FArcy de Pontfarcy
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
char e1 =  'E';
char e2 =  'B';
char e3 =  '6';
char e4 =  '9';

char key1;
char key2;
char key3;
char key4;

int securite = 0;

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
Serial.begin(9600);
}

void loop()
{
while (!key1)
    {
      key1 = keypad.getKey();
    }
while (!key2)
    {
      key2 = keypad.getKey();
    }  
while (!key3)
    {
      key3 = keypad.getKey();
    } 
while (!key4)
    {
     key4 = keypad.getKey();
    } 

if(key1 == e1 && key2 == e2 && key3 == e3 && key4 == e4)
  {
    analogWrite(led_V, 255);
    delay(1000);
    analogWrite(led_V, 0);
  
    key1 = 0;
    key2 = 0;
    key3 = 0;
    key4 = 0;
    securite = 0;
  }
else
  {
    Serial.print("Le code ");
    Serial.print (key1);
    Serial.print (key2);
    Serial.print (key3);
    Serial.print (key4);
    Serial.println(" n'est pas correct");
    Serial.println();

    analogWrite(led_R, 255);
    delay(500);
    analogWrite(led_R, 0);
  
    key1 = 0;
    key2 = 0;
    key3 = 0;
    key4 = 0;
    securite++;
}
if (securite == 3)
  {
    Serial.print("Vous avez effectué trop d'essais, veuillez attendre 5 secondes");
    analogWrite(led_R, 255);
    delay(5000);
    analogWrite(led_R, 0);
    securite = 0;
  }
}
