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

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
Serial.begin(9600);
}

void loop()
{
char key = keypad.getKey();
if (key)
{
  if (key == '4')
  {
    analogWrite(led_B, 255);
    char key2 = 0;

    while (!key2)
    {
      key2 = keypad.getKey();
    }

    if (key2 == '2')
    {
      analogWrite(led_B, 0);
      analogWrite(led_V, 255);
    
    key2 = 0;
    while (!key2)
      {
        key2 = keypad.getKey();
      } 
      if (key2 == 'F')
      Serial.println("La touche 2 a été préssée !, vous pouvez entrer");
      analogWrite(led_B, 255);
      analogWrite(led_V, 255);
      delay(500);
      analogWrite(led_V, 0); 
      analogWrite(led_B, 0);
    }
    else
    {
      Serial.println("La touche 3 a été préssée !");
      analogWrite(led_B, 0);
      analogWrite(led_R, 255);
      delay(500);
      analogWrite(led_R, 0);
    }
  }
  else
  {
    Serial.print("La touche ");
    Serial.print (key);
    Serial.println(" à été préssée");
    Serial.println();
  }
}
}
