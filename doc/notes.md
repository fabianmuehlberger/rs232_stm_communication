# Todo

## Recherche 

## Interrupt 
* Wieso, welshalb, Warum 

## RS232 Hardware 
* Komponenten
* Zusammenbau 
* Schnittstelle/Pins


# Testprogramme:
### necleo Fab
Tastendruck (Blaue Taste D13) wird gedrückt => senden eines Signals 


### nucleo Flo
Nucleo erhält signal und LED blinkt 

### Versendetes Signal: 
* 8 Bit Daten + Start stop 
* 1 Wort = 0000 0001 = Blinken 
* 2 Wort = 0000 0000 = Nicht Blinken 

### Signal Def. 
* Logic low (0) = positiver Pegel 
* Logic high (1) = negativer Pegel 
* Pegel = +- 5V 

### Settings


| Parameter | Values |   
|---|---|   
| boud | 9600|
| number of Bites | 8 |
| parity | none |
| stop Bit | 1 |  


## Schicken eines Bits
* Definiert durch Clock:
    * Wenn 1 Zyklus vergangen setze bit 1, 
    * wenn 1 Zyclus vergangen setze bit 0
    

* Bitrate mit fester Frequenz: High Low
* Boud Rate: 

## Programmierung 

* Write Analog Write (High)
* Write Analog Write (Low)

## Flusssteuerung 
* DTE > DTE, Digital Handshake 


## Usefull Links

https://www.elektronik-labor.de/RS232/RS232_3.htm
https://www.arduino.cc/en/pmwiki.php?n=Tutorial/ArduinoSoftwareRS232
https://kompendium.infotip.de/rs-232-die-serielle-schnittstelle.html
https://electronics.stackexchange.com/questions/110478/difference-between-uart-and-rs-232   
https://www.circuitstoday.com/uart-between-microcontrollers-proteus