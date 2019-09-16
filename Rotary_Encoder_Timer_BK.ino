/* Rotary encoder test code
 * Modified from http://www.circuitsathome.com/mcu/programming/reading-rotary-encoder-on-arduino by Oleg
 * Latest mod by Jessica Faruque 7/17/2013
 */
 
 // include the library code:
#include <LiquidCrystal.h>


#define ENC_A 6 //these need to be digital input pins
#define ENC_B 7

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

 
void setup()
{
  /* Setup encoder pins as inputs */
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);
 
  Serial.begin (9600);
  Serial.println("Start");

  lcd.begin(16, 2);
  lcd.print("Start");
  delay(3000);
  lcd.clear();

  int seconds;
  bool time_setter_flag = true;
  while(time_setter_flag)
  {
    static unsigned int counter4x = 0;      //the SparkFun encoders jump by 4 states from detent to detent
    static unsigned int counter = 0;
    static unsigned int prevCounter = 0;
    int tmpdata;
    tmpdata = read_encoder();
    if(tmpdata) 
    {
      counter4x += tmpdata;
      counter = counter4x/4;
      if (prevCounter != counter)
      {
        if(prevCounter > counter)
        {
          seconds = counter +1;
          time_setter_flag = false;
        }
        else
        {
          Serial.print("Counter value: ");
          Serial.println(counter);
          lcd.clear();
          lcd.print(counter);
        }
      }
    prevCounter = counter;
    }
  }
  lcd.clear();
  lcd.print("COUNTDOWN");
  lcd.setCursor(0, 1);
  for(int i = seconds; i > 0; i--)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("COUNTDOWN");
    lcd.setCursor(0, 1);
    lcd.print(i);
    delay(1000);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TIME IS UP!!!");
  for(int i = 10; i > 0; i--)
  {
    lcd.noDisplay();
    delay(500);
    // Turn on the display:
    lcd.display();
    delay(500);
  }
  
}
 
void loop()
{
  //
}
 
/* returns change in encoder state (-1,0,1) */
int read_encoder()
{
  static int enc_states[] = {
    0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0  };
  static byte ABab = 0;
  ABab *= 4;                   //shift the old values over 2 bits
  ABab = ABab%16;      //keeps only bits 0-3
  ABab += 2*digitalRead(ENC_A)+digitalRead(ENC_B); //adds enc_a and enc_b values to bits 1 and 0
  return ( enc_states[ABab]);
 
}
