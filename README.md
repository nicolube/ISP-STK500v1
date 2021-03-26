# ISP an Hand einer STK500v1
Diese ISP ist im grunde einer [STK500v1](http://ww1.microchip.com/downloads/en/Appnotes/doc2525.pdf) auch bekannt als [Arduino as ISP](https://www.arduino.cc/en/Tutorial/BuiltInExamples/ArduinoISP) mit der erweiteren Schnitstelle für das [ATMega32 Board](/ATMega32%20Board/ATMega32%20Board.pdf) der IHK.
## Inhaltsverzeichnis
- [ISP an Hand einer STK500v1](#isp-an-hand-einer-stk500v1)
  - [Inhaltsverzeichnis](#inhaltsverzeichnis)
- [Bedienung](#bedienung)
  - [Arduino IDE](#arduino-ide)
  - [PlatformIO](#platformio)
  - [Schnittstellen Beschreibung](#schnittstellen-beschreibung)
- [Bauteile die vernachlässicht werden können](#bauteile-die-vernachlässicht-werden-können)
- [Programmieren der ISP](#programmieren-der-isp)
  - [Flashen der Firmwahre](#flashen-der-firmwahre)
- [Bestückungsplan](#bestückungsplan)
- [Schaltplan](#schaltplan)

# Bedienung

Das Board ist wie am Anfang genant eine STK500v1 und verhält sich auch so. Es registriert sich auf der Seite des PC als COM-Port (Serielle Schnittstelle). 

Bevor Sie jedoch ihr zu Programirendes Board anschießen muss geprüft werden ob das zu programmirende Board eine eigene Spannungsversorgung hat und ob diese auf die AVR ISP Schnittstelle geführt wird. Sollte dies der Fall sein so entfernen Sie bitte JP2.

## Arduino IDE

Wählen Sie unter Tools den Port Ihrer STK500v1 und den Programmer *Arduino as ISP*.
Jetzt kann wie gewohnt ihr Programm hochgeladen werden.

Für genauere Informationen Klicken Sie [hier](https://www.arduino.cc/en/Tutorial/BuiltInExamples/ArduinoISP#program-the-bootloader) 

## PlatformIO

Bitte nutzen Sie für PlatformIO Projekt unser [Beispiel Projekt](/ISP/Beispiel).
Hier bei ist zu Beachten das in der [platform.ini](/ISP/Beispiel/platformio.ini) der *upload_port* angepasst werden muss.


## Schnittstellen Beschreibung

- SV1 und SV2 sind eine 6-, 10-Pin [AVR ISP Schittstelle](https://telecnatron.com/reference/pinouts/avr-isp/index.html).
- X1 ist ebenfalls eine ISP jedoch adoptiert auf den Parallelen Port des [ATMega32 Board](/ATMega32%20Board/ATMega32%20Board.pdf)
- X2 [USB Type B](https://static.giga.de/wp-content/uploads/2015/06/USB-2.0-A-B-Pins.png) zur Kommunikation mit dem PC.

# Bauteile die vernachlässicht werden können
Die Leiterplatte hat verschiedene Zusatzkomponenten die für die Funktion nicht zwingen benötigt werden, jedoch zusätzliche sicherheiten gewähren.

- Entstörkondensatoren USB (C8, C9)
- ESD-Schutz Diodennetzwerk (U1)
- FT232: Reset Pulldown (R5)
- FT232: 3,3V Entstörer (C7)

# Programmieren der ISP

Zum Programiren der ISP muss JP1 (1,2) und JP2 gesetzt werden.
Nun kann mittels einer 2. ISP die Firmwahre geflasht [Firmware](/ISP/Firmware/).
## Flashen der Firmwahre
1. Begeben Sie sich in den Verzeichnis des Projektes.
2. Prüfen Sie in der [platform.ini](/ISP/Firmware/platformio.ini) ob Sie den richtigen COM-Port gewählt haben.
3. Öffenen Sie nun ein Terminal / CMD die [PlatformIO CLI](https://platformio.org/install/cli) installiert hat.
4. Setzen Sie die Fuses des Mikrocontrollers mit ```pio run --target fuses```.
5. Laden Sie nun die Firmware mit ```pio run --target upload``` hoch.

>  Bitte beachten Sie das der Jumper JP1 zur normalen nutzung wieder auf JP1 (2,3) gesetzt werden muss.

# Bestückungsplan
**Siehe [Stückliste](/ISP/Eagle/Stückliste.txt) für Bauteilinformation.**

![Bestückungsplan](/ISP/Eagle/Bestückungsplan.jpg)

# Schaltplan
![Schaltplan](/ISP/Eagle/Schmatic.png)
