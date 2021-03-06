# Aistin WiFi board example
Ready to use example code for Aistin CPU + WiFi board + Motion sensor. With web configuration interface.

#1 Quick start
1. Attach WiFi board (& Motion sensor board) to CPU. Or use CPU with integrated WiFi.
2. Power on the device.
3. Upload code to CPU board.
4. Connect to HF-LPB100 wlan.
5. Open browser and go to http://10.10.100.254:33170/
6. Go to configuration page.
7. Current configuration should load automatically, if not click *Read config*-button.
8. Set & *save* connection settings. <br>
Saving settings reboots module and causes connected equipment to disconnect. Just reconnect to network and reload the page.
9. Click *Advanced*-button.
10. Set network mode to *client* & *connect to IP* to your Aistin server IP & *port* to 33168 & *save*.<br>
Now the controller should show on Aistin web interface as node *Aistin*.<br>
##CAUTION! after setting WiFi board to client the web interface stops working.
You can reset the board to factory defaults by:<br>
On serial: Enter AT mode(into serial:*AT*) and reset factory defaults(into serial:*AT+RELD*)<br>
[Aistin@WEB](http://iprotoxi.fi/aistin2): Select node 'Aistin'. On 'Controller - Basic'-page press 'Reset to defaults'-button.<br>
And reboot microcontroller.  

#2 Web interface
##2.1 Main page
*Get data* Starts timer requesting motion sensor data every 2s.<br>
*Stop* Stops the timer.<br>
##2.2 Config
WiFi module configuration page.<br>
**Basic** Show only basic settings.<br>
**Advanced** Show advanced settings.<br>
**Reboot** Reboots module.<br>
**Read config** Reads current settings from module.<br>
<br>
**2.2.1 Misc:**<br>
<br>
**Module mode:**<br>
*Access point* - Set module to only act as WiFi access point as defined in *Access point settings*.<br>
*Client* - Set module to only connect to WiFi network as defined in *WiFi client settings*.<br>
*Both* - Enable both access point and client mode(default).<br>
**Protocol:** *TCP* - enable tcp mode(default). *UDP* - enable udp mode.<br>
**Network mode:**<br>
*Server* - Allow connections to module(needed for web interface to work).<br>
*Client* - Module opens connection to IP specified in *Connect to IP*.<br>
**Port:** Port to use in communication with module.<br>
**Connect to IP:** In client mode module connects to this IP.<br>
<br>
**2.2.2 Access point settings:**<br>
<br>
**IP address:** Module IP address.<br>
**Subnet mask:** Define subnet mask.<br>
**DHCP:** enable/disable DHCP<br>
**Start address:** DHCP range start = network address + given IP<br>
**End address:** DHCP range end = network address + given IP<br>
**WiFi mode:** Select which standard to use.<br>
**SSID:** Module access point SSID.<br>
**Channel:** Select communication channel.<br>
**Encryption:** Select encryption method.<br>
**Key:** Encryption key.<br>
<br>
**2.2.3 WiFi client settings:**<br>
<br>
**SSID:** Access point SSID.<br>
**Encryption:** Select encryption method.<br>
**Key:** Encryption key.<br>
**Mode:** Select ip optaining method. *IP address*, *subnet mask* & *default gateway* are obtained automatically when using DHCP<br>
**IP address:** Modules IP address.<br>
**Subnet mask:** Subnet mask of connected network.<br>
**Default gateway:** IP address of the default gateway.<br>
<br>
**2.2.4 Status:**<br>
<br>
**Client IP:** Modules IP address when connected to wifi network.<br>
**Link quality:**Link quality when connected to wifi network. <br>
<br>
**2.2.5 Custom command:**<br>
<br>
Interface to send custom commands to Aistin CPU. Can be used to send AT commands & predefined commands like 'accel' to read motion sensor value. Type a command into the smaller box and press send. Response is returned to the bigger box.<br>
Eg. sending *AT+WSLQ* returns link quality.

#3 Serial control (Arduino's *Serial Monitor* or any terminal)
*AT* enters AT command mode. Wait for *AT mode* in serial<br>
*AT+&lt;COMMAND>* query command parameters. Always wait for *+ok* or *+ERR* before entering next AT command<br>
*AT+&lt;COMMAND>=&lt;PARAMETERS>* set command parameters, separated with comma.<br>
Eg. *AT+WSKEY=WPA2PSK,AES,password123* sets client mode connection settings to WPA 2, AES and password to *password123*.<br>
*AT+ENTM* disables AT mode and resumes normal operation.<br>
*AT+Z* reboots module making changes effective and disables AT mode.
#4 HTML to C array
Every HTML code line saved to char array needs to start with *"* and end with *\r\n"*. Every *\\* needs to be replaced with *\\\\*, excluding the line ending *\r\n"*.<br>
Eg. original:*&lt;title>Aistin&lt;/title>* C: *char array[]={"&lt;title>Aistin&lt;/title>\r\n"};*