



# RS232 mit GPIO, Timer, und Interrupt bauen

## Notizen
* Was ist ein RS232?
* Wie kann die Schnittstelle mittels GPIO, Timer und Interrupts realisiert werden
* Was kann man alles mit einer Seriellen Verbindung machen
* Was könnte man Vorzeigen 
* RS232 Schnittstellen auf dem Nucleo Board miteinander kommunizieren lassen
* Entertainment Faktor!

## Wie funktioniert RS232
* Dienen zum Seriellen Austausch von Daten von einem PC zu ein Externen Gerät
* Wird auch COM genannt
* Einfach implementierbar und Zuverlässig
* RS = Recommended Standard
* Wortweise Datenübertragung
* Kann aus 5–9 Bits bestehen; Üblich 7-8 
* Sind in Hexadezimal nach ASCII codiert
* Verschickt 7-8 Bit lange ASCII kodierte Codewörter 
* Datenübertragung Asynchron 
* Heißt der Empfänger muss aus dem Datenfluss das Taktsignal  zurückgewinnen
* Flanken werden mittels „Samplen“ des empfangenen Signals mit einem Vielfachen der Datenrate erkannt 
* Die Synchronisationen des Empfängers wird mittels den Start/Stop Bits im Datenstrom vorgenommen 
*  Vor dem Start der Übertragung auf der Datenleitung ist dieser im Ruhezustand auf logisch „1“
* Bei beginn geht dieser auf logisch „0“ (invertierter Pegel des Start Bits)
* Dann folgen die Datenbits der Nutzdaten
* Abgeschlossen wird das ganze mit dem Stop Bit welches eine logische „1“ ist
* Die Dauer eines einzelnen Bits ist abhängig von der eingestellten Bitrate
* Der Empfänger synchronisiert sich auf die Mitte der einzelnen Datenbits ab und Tastet diese jeweils mit seiner eigen Bitrate ab
* Wie maximal erreichbare Datenrate ist jedoch zum Großteil abhängig von Hardwarefaktoren


## Port Information:
* Portanschluss ist immer als „male“ ausgelegt
* Es existieren Zwei Varianten der RS232 Ports
    * Die „klassische “e 25-Polige Sub-D-Verbinder (Zwei Kanäle)
    * Die 9-Polige Sub-D-Verbinder, In der EDV gängig da nur die 9 Pins benötigt werden (Ein Kanal)

![flusssteuerung](\pictures\rs232_flusssteuerung.png) 
![pinout Table](\pictures\rs232_pin_table.gif)   

## Verbindung
* In unserem Projekt hätten wir eine DTE-DTE Verbindung (gleiches Gerät)
* Bei dem Kabel sollten die gesendeten Pins mit den Empfangenen Pins verbunden werden 

![stecker](\pictures\rs232_pinbelegung.gif)  




## Signalpegel 
* Die logischen „1“ und „0“ Pegel können in verschieden physischen Signalpegel werte haben
    * +/- 5V
    * +/- 10V
    * +/- 12V
    * +/- 15V
* Die tatsächlich anliegenden Pegel sind abhängig von der Treiberschaltung
* Für TxD und RxD ist „0“ ein negativer Pegel und „1“ ein positiver
* Steuerleitungen RTS und CTS ist der Pegel umgekehrt
* Weil RS2323 Signalpegel höher sind Logischen Pegel von Logikbausteinen können Daten nicht direkt verarbeitet werden. Zur Anpassung benötigt man Pegelwandlerbausteine welche zwischengeschaltet werden

![signale](\pictures\rs232_signale.gif)   
[1] https://kompendium.infotip.de/rs-232-die-serielle-schnittstelle.html


Die physikalischen Pegel, die  den logischen Pegeln entsprechen, werden vom RS-232-Standard definiert. Gültige Signalpegel liegen in den Bereichen von +3V und +15V und - 3V und -15V. Pegel zwischen -3 V und +3 V sind nicht zulässig. Der Standard sieht einen maximalen Pegelhub von ± 25 V vor. Üblich sind ± 5V, ± 10V, ± 12V und ± 15V. Die tatsächlich anliegenden Pegel sind abhängig von der Treiberschaltung.
Für die Datenleitungen (TxD und RxD) ist eine logische "0" als negativer Pegel und eine logische "1" als positiver Pegel definiert (siehe Abb. 4). Steuerleitungen (RTS, CTS) haben umgekehrte Pegel: Ein aktives Signal hat einen positiven Pegel, ein inaktives Signal einen negativen Pegel.

Da die RS-232-Signalpegel höher sind als die logischen Pegel von Logikbausteinen (z.B. TTL 5V) können RS-232-Daten nicht direkt verarbeitet werden. Hier müssen zur Anpassung spezielle Pegelwandlerbausteine (siehe Abb. 14) zwischengeschaltet werden, die auch gleichzeitig die Logikbausteine vor Überspannung schützen.

Die RS-232-Signalspannungen sind asymmetrisch und sind auf Masse = 0V bezogen. Beim Verbinden mit anderen Geräten deren Masse nicht 0V ist können daher Probleme durch Erdschleifen auftreten, die die Datenübertragung stören könnten. Diese Erdschleifen werden meist durch die mit Schutzerde (Schuko, Schutzklasse I) versehenen EDV-Geräte zusammen mit den Außenleitern der abgeschirmten Kabel zwischen den Geräten verursacht.

# STM232
![stm32 pinout](\pictures\stm32_pinout_sheet.png) 
[2] https://www.mikrocontroller.net/attachment/247021/nucleo_F103RB_pinout_sheet.pdf

