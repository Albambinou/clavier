/**************************************************************************
 * Nom du Programme      : Clavier.ino
 * Auteur                : Alban de Farcy de Pontfarcy
 * Date de création      : 17/12/2024
 * Dernière modification : 17/12/2024
 * Version               : 1.5
 * Description           :
 *   Ce programme a pour but de trouver le code avec comme seul indication, le texte sur l'écran. exemple : 3 bon caractères dont 1 au bon endroit
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
char mdp [4] = {'E','B','6','9'};
char key[4];
int nombre = 0;
int endroit = 0;
int erreur = 10;

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
Serial.begin(9600);
Serial.println("Début du jeu ");
Serial.println();
}

void loop()
{
  for (int i = 0; i < 4; i++)
  {
    while (!key[i])
    {
      key[i] = keypad.getKey();
    }
    analogWrite(led_B, 255);
    delay(100);
    analogWrite(led_B, 0);
  }
for (int j = 0; j < 4; j++)
{
    for (int i = 0; i < 4; i++)
    {
      if(key[i] == mdp[i])
      {
        endroit++;
      }
      if (key[j] == mdp[i])
      {
        nombre++;
      }
  }
}
endroit = endroit / 4;
  
  if(endroit == 4)
  {
    Serial.print("Tu a gagné, le code était EB69");
    delay(50000);
  }
  
  else
  {
    erreur--;
    Serial.print("Il y a ");
    Serial.print(nombre);
    Serial.print(" bon caractère dont ");
    Serial.print(endroit);
    Serial.println("  au bon endroit");
    Serial.print("Il te reste ");
    Serial.print(erreur);
    Serial.println(" essais");
    Serial.println();
    
    for (int i = 0; i < 4; i++)
    {
      key[i] = 0;
    }
  nombre = 0;
  endroit = 0;
}
if (erreur == 0)
{
  Serial.println ("Tu a perdu !!!!!");
  delay(50000);
}
}
