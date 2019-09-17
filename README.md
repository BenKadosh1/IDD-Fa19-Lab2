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

One mistake I originally made was forgetting to connect to pin 3 of the LCD. Before connecting to a power source I double checked everything and noticed I was missing a connection. 

**d. What line of code do you need to change to make it flash your name instead of "Hello World"?**

Line54 in the built-in code for display

lcd.print("hello, world!");
 
**e. Include a copy of your Lowly Multimeter code in your lab write-up.**

[Ben's Lowly Multimeter Code](https://github.com/BenKadosh1/IDD-Fa19-Lab2/blob/master/AnalogInput_Lab2_BK.ino)


## Part C. Using a time-based digital sensor


[Working Rotary Encoder Youtube Link](https://www.youtube.com/watch?v=kgSdvbaykyE&feature=youtu.be)

## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**

Update line 36 of the code (listed below) and add a division by 2 to the end of the equation so that the note duration is divided in half making it play twice as fast.

int noteDuration = 1000 / noteDurations[thisNote];
 
**b. What song is playing?**

Star Wars - Main Title

## Part E. Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**

[Rotary Encoder Timer Youtube Link](https://www.youtube.com/watch?v=RvvwTF1TlhY&feature=youtu.be)

[Ben's Rotary Encoder Timer In Action Youtube Link](https://www.youtube.com/watch?v=xwYbmF-tFNg&feature=youtu.be)

[Ben's Rotary Encoder Timer Code](https://github.com/BenKadosh1/IDD-Fa19-Lab2/blob/master/Rotary_Encoder_Timer_BK.ino)

Commentary: I used portions of the Rotary Encoder code to allow a user to manually set how long they want the timer to run before timing out, by rotating the rotary encoder and displaying the time on the LCD. I also used LCD code to display the values being read in by the Rotary Encoder. In order to signal that the desired time was met I established a protocol of rotating clockwise while setting and then turning the Rotary counter clock wise to stop incrementing the desired time and store the variable before counting down and displaying that to the user through the LCD. 
