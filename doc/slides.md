---
marp: true
theme: uncover
footer: "florian biatel | fabian muehlberger"
paginate: true
headingDivider: false
style: |
    :root {
    --color-background: #fff;
    --color-background-code: #ccc;
    --color-background-paginate: rgba(128, 128, 128, 0.05);
    --color-foreground: #345;
    --color-highlight: #999;
    --color-highlight-hover: #aaf;
    --color-highlight-heading: #99c;
    --color-header: #bbb;
    --color-header-shadow: transparent;

    }
--- 

# RS232
*Florian Biatel & Fabian Mühlberger*

---

### Wozu 
*RS* **-** *recomended standard* 

* Serieller Datenaustausch
* asyncron 
* flankenerkennung mittels samples
* Wortweise übertragung 5-9 bits
* 

---

### Port

* 25 Pol Sub-D-Verbinder (2 Kanäle)
* EDV 9 Pol (1 Kanal)
![bg vertical right width:300](pictures\rs232_25pol.jpg)
![bg right width:300](pictures\rs232_9pol.jpeg)

---
![width:1000 pinout Table](\pictures\rs232_pin_table.gif)   

---

DTE-DTE Verbindung

![width:500 stecker](\pictures\rs232_pinbelegung.gif)  

![bg right width:300 verbindung ](pictures\rs232_verbindung.gif)

---



---

### Signal Pegel 

* Pegelbereich +/- 3V und +/- 15V
* max Pegelhub 25V
* Üblich: +/- 5V; +/- 12; +/- 15V
* logic **1** = negativer pegel
* TTL Pegel benötigen wandler 

---

![width:1000 signale](\pictures\rs232_signale.gif)

--- 

### quellen:
[1] https://kompendium.infotip.de/rs-232-die-serielle-schnittstelle.html
