---
marp: true
theme: uncover
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


* Serieller Datenaustausch
* p2p Verbindung
* asyncron 
* flankenerkennung mittels samples
* Wortweise übertragung 5-9 bits
* negative Logik

---



### Port

* 25 Pol Sub-D-Verbinder (2 Kanäle)
* EDV 9 Pol (1 Kanal)
![bg vertical right width:300](pictures/rs232_25pol.jpg)
![bg right width:300](pictures/rs232_9pol.jpeg)

---
### Geschichte
*RS* **-** *recomended standard* 
* 1990er 
* Mainframe Text-Terminal Verbindung
* Übertragung über Telefonleitung
* Immer weniger in verwendung.
---
![width:1000 pinout Table](pictures/rs232_pin_table.gif)

---


---
### Flusssteuerung

* DTE > DTE Digital Handshake
* NUllmoduem Kabel 


![width:500 stecker](pictures/rs232_pinbelegung.gif)  

![bg right width:300 verbindung ](pictures/rs232_verbindung.gif)

---

### Uart Config

| Parameter | Values |   
|:---|:---|   
| boud | 9600|
| Bites | 8 |
| parity | none |
| stop Bit | 1 |  

---

### Signal Pegel 

* Pegelbereich +/- 3V und +/- 15V
* max Pegelhub 25V
* Üblich: +/- 5V; +/- 12; +/- 15V
* logic **1** = negativer pegel
* TTL Pegel benötigen wandler 

---

![width:1000 signale](pictures/rs232_signale.gif)

--- 

### quellen:
[1] https://kompendium.infotip.de/rs-232-die-serielle-schnittstelle.html
[2] https://de.wikipedia.org/wiki/RS-232
[3] https://www.st.com/en/evaluation-tools/nucleo-f103rb.html
