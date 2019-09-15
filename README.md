# Digital Timer

## Part A. Solder your LCD panel

<img src="https://github.com/BenKadosh1/IDD-Fa19-Lab2/blob/master/IDD_LAB_2_Soldered_LCD_Panel_Ben_K.jpg" width=450 height=450>

## Part B. Writing to the LCD
 
**a. What voltage level do you need to power your display?**

If we look at the pinout and dimensions page (link below) for the LCD, on page 4 in the "DC ELECTRICAL CHARACTERISTICS" section there is a line for Operating voltage for LCD, which reads Min, Typ, Max of 4.8, 5.0, 5.2 Volts respectively. Meaning the typical voltage needed to power the LCD is 5V +/- .2V.

Link: https://cdn-shop.adafruit.com/product-files/181/p181.pdf

**b. What voltage level do you need to power the display backlight?**

Similarly to part a. above, if we look at the pinout and dimensions page for the LCD, on page 4 in the "LED BACKLIGHT CHARACTERISTICS" section it describes the backlight as white (which we will see later in the lab) and that the operating voltage is 3.2V +/-.15V, which is in line with the 3.3V being fed out of the 3.3V pin in the arduino to pin 15 in the LCD which is the power supply for the LCD's backlight. 
   
**c. What was one mistake you made when wiring up the display? How did you fix it?**

**d. What line of code do you need to change to make it flash your name instead of "Hello World"?**

Line54 in the built-in code for display

lcd.print("hello, world!");
 
**e. Include a copy of your Lowly Multimeter code in your lab write-up.**


## Part C. Using a time-based digital sensor

**Upload a video of your working rotary encoder here.**


## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**
 
**b. What song is playing?**


## Part E. Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**

**b. Post a link to the completed lab report your class hub GitHub repo.**
