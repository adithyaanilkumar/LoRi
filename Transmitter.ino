
  

 
Interfacing SX1278 (Ra-02) LoRa Module with Arduino
ARDUINO
ByAswinth Raj Feb 20, 201910
Interfacing SX1278 (Ra-02) LoRa Module with Arduino
It is expected that by 2020 we will have 25 Billion devices connected to the internet. To give you an idea that is more than three times the population of earth today. With the concepts of IoT and Industry 4.0, Connected Vehicles and Smart Cities spreading rapidly, this is most likely to happen. We already have a handful of wireless protocols like BLE, Wi-Fi, Cellular etc, but these technologies were not ideal for IoT sensor nodes since they needed to transmit information to long distance without using much power. This lead to the rise of LoRa Technology, which can perform very-long range transmission with low power consumption.


 

As ESP modules become synonyms for Wi-Fi applications, this LoRa technology also has caliber to build a vast network like Internet. We previously build many IoT Based projects using ESP8266 and Arduino, here in this article we will learn about LoRa and how to use it with Arduino Development Platform.

 

What is LoRa?
The term LoRa stands for Long Range. It is a wireless Radio frequency technology introduced by a company called Semtech. This LoRa technology can be used to transmit bi-directional information to long distance without consuming much power. This property can be used by remote sensors which have to transmit its data by just operating on a small battery.

Typically Lora can achieve a distance of 15-20km (will talk more on this later) and can work on battery for years. Remember that LoRa, LoRaWAN and LPWAN are three different terminologies and should not be confused with one another. We will discuss them briefly later in this article.

 

Understanding LoRa Technology
In any typical IoT solution provided for warehouse management or field monitoring, there will hundreds of Sensors nodes deployed on the field which will monitor the vital parameters and send it to the could for processing. But these sensors should be wireless and should operate on a small battery so that it is portable. Wireless solutions like RF can send data to long distance but requires more power to do so thus cannot be battery operated, while BLE on the other hand can work with very little power but cannot send data to long distance. So this is what brings in the need for LoRa.

In LoRa we can achieve high distance communication without using much power, thus overcoming the drawback of Wi-Fi and BLE communication. But how is it possible? If that is the case why do BLE and RF still exist?  

That is because LoRa comes with its own drawbacks. In order to achieve high distance with Low power LoRa compromises on Bandwidth, it operates on very low bandwidth. The maximum bandwidth for Lora is around 5.5 kbps, this means that you will be able to send only small amount of data through LoRa. So, you cannot send Audio or Video through this technology, it works great only for transmitting less information like sensor values. The below chart shows where LoRa lies compared with Wi-Fi, Bluetooth and Cellular devices.


 

Many people compare LoRa with Wi-Fi or Bluetooth, but these two do not stand anywhere near LoRa. Bluetooth is used to transfer information between two Bluetooth devices and Wi-Fi is used to transfer information between an Access Point (Router) and Station (Mobile). But LoRa technology was primarily not invented to transmit data between two LoRa modules.

You can think of LoRa to be more like cellular communication. Signal from one LoRa Node reaches another Node through a LoRa Gateway as shown in the image below.


 

These Gateways then take the information to the internet and finally to the end user through an application interface. Similarly the data from the user will also reach the node through the network server and the Gateway.

A LoRa Node usually operates on a Battery and consists of a Radio Module and Microprocessor. The Microprocessor is used to read the data from the senor and send it in the air through the Radio module which will then be picked up by a LoRa Gateway. The LoRa Gateway also has a Radio Module and a Microprocessor but is normally operated over AC mains since they require more power. A single LoRa Gateway could listen to multiple LoRa nodes, while a single LoRa node could also send information to multiple gateways, this way the information from the node will be picked up gateway without it being lost. When information id is sent from the node to the gateway it is called as uplink and when it is sent from gateway to node it is called as down link.

 

LoRa falls under the category of LPWAN, where LPWAN stands for Low Power Wide Area Network. It is not just LoRa that can operate on LPWAN, but we also have other technologies like Narrow Band IoT (NB-IOT), Sigfox etc. which are capable of operating in the same LPWAN. Once the technology of LoRa was introduced, it needed certain set of protocols to be followed by all manufactures, so the LoRa alliance was formed which then introduced the LoRaWAN.  LoRaWAN is a modified form of LPWAN which specifies the protocol on how LoRa in a physical layer should be used to send and receive data among the nodes, gateways and to the internet.

 

How much distances can I communicate with LoRa?

The Official Information on LoRa claims that it could achieve a distance of 715km line of sight. That is when there is no obstacle between the Node and Gateway. Few people have even practically achieved communication between 212km Ground to Ground and even upto 702km using weather Balloon.

 

LoRa SX1278 with Arduino
Enough theory lets actually build it ourselves and check how it is working.  Remember the part where I told you that two LoRa modules cannot communicate with each other? Well I lied… Yes, the LoRaWAN Protocol does not allow communication between two LoRa modules, but there is technique called the Radio Head Packet Method which does follow the LoRaWAN protocol but allows us to communicate with two LoRa modules cool right!!. So let’s use two LoRa modules and two Arduino Boards to send data from one board and receive it on the other. We will use Arduino Uno at transmitter side and Arduino Nano at receiving side.

 

The LoRa module that I am using here is the SX1278 Ra-02 which operates on 433MHz. I am from India and here the unlicensed Frequency range is from 865MHz to 867MHz, so I am not legally allowed to use the 433MHz frequency module for a long time other than for educational purpose. Similarly check the allowed Ranges in your country and make sure you are allowed to use the particular frequency range. LoRa modules do come in different frequency ranges, the most common being the 433MHz, 915MHz and 868MHz. The frequency at which your module works will be mentioned at the back of the module. Also you can either buy LoRa as a module or just the chip. If you are planning to get only the chip then make sure your soldering skills are good since its a delicate job to solder wires to the LoRa chip. I have both the Module and Chip version soldered with wires as shown below.


 

Next important thing to have with your LoRa module is your Antenna. Remember that it is mandatory to operate the LoRa module only with an antenna, else the output transmitting power will damage the Module. I am using a 433Mhz Lora module so my antennas are also rated for 433MHz, you have to select your antenna accordingly. My LoRa module along with antenna is shown below.


 

Transmitting Side- Connecting LoRa SX1278 with Arduino UNO
For the transmitting side we will use an Arduino UNO with our LoRa module. The circuit diagram to connect the Arduino UNO with LoRa is shown below



 
 

The LoRa module consists of 16 pins with 8 pins on each side. Out of these 16 pins, six are used by GPIO pins ranging from DIO0 to DIO5 and four are used by Ground pins. The module operates in 3.3V and hence the 3.3V pin on LoRa is connected to the 3.3v pin on the Arduino UNO board. Then we connect the SPI pin on the LoRa to the SPI pins on Arduino Board as shown above. You can also use the table below to make sure the connection is done correctly

LoRa SX1278 Module

Arduino UNO Board

3.3V

3.3V

Gnd

Gnd

En/Nss

D10

G0/DIO0

D2

SCK

D13

MISO

D12

MOSI

D11

RST

D9

 

I have used connecting wires to make my connection between Arduino UNO and LoRa Module. The setup looks something like this shown below. The whole set-up can is powered by a power bank to make it portable to test the range.


 

Receiving Side- Connecting LoRa SX1278 with Arduino Nano
For the Receiving side we will use an Arduino Nano with LoRa module. You can use any Arduino board that you have for transmitter and receiver, but make sure you connect them accordingly. The circuit diagram to connect the Arduino Nano with LoRa is shown below


 

The connections almost remain the same except for one subtle change. The 3.3V pin of the LoRa module is not powered by the Arduino Nano but with an external 3.3V regulator. This is because the on-board regulator on Arduino Nano cannot provide enough current for the LoRa module to operate. Other than this the connections remain the same. I am also pasting a similar table below for your reference.

LoRa SX1278 Module

Arduino Nano Board

3.3V

-

Gnd

Gnd

En/Nss

D10

G0/DIO0

D2

SCK

D13

MISO

D12

MOSI

D11

RST

D9

 

I made the connection on a breadboard and used my trusty old breadboard power supply that we built earlier. Also note that the LoRa modules that I used are not breadboard friendly hence I have used two small breadboard to make the connections as shown below.


 

Preparing the Arduino IDE for LoRa Wireless Communication
Once the hardware is ready we can move on to the Arduino IDE. To work with LoRa module using Arduino, we already have a well-built LoRa library by Sandeep Mistry.  In this article we will just include the Library to our Arduino IDE and use the example sketches with slight modifications to make our LoRa modules communicate between them.

To add the library, open you Arduino IDE and follow Sketch -> Include Library -> Manage Libraries. Then search for “LoRa Radio” and look for the library that was made by Sandeep Mistry and click on install. Wait for the installation to complete and you should see something like this in the end


 

Now restart the Arduino IDE and open the LoRa Example program by using File -> Example -> LoRa and then open both LoRa Receiver and LoRa Sender Program as shown below.


 

Both the programs are also given at the bottom of the page for your reference. The complete program is self explanatory. The Sender program sends a “hello” for every 5 seconds with a value of counter being incremented. The receiver then receives this and prints on the Serial monitor with the RSSI value.

One important line where you have to make change is the LoRa.begin() function. By default the program has “LoRa.begin(915E6)” meaning it sets the LoRa module to work at 915MHz. That is okay if your module is actually 915MHz, but mine here works on 433MHz frequency as I told earlier, so you have to change it as shown below

LoRa.begin(433E6)
 

You can visit the library documentation to know what each function in the Library means and how to change it.  

Similarly the frequency has to be changed on the Receiver program also. Once the program is ready upload the program on the respective boards after making sure the connections are correct and the antenna is connected to the LoRa module.  

 

LoRa Wireless Communication with Arduino
Once the program is uploaded, open the Serial monitor of both the Arduino boards. The Serial monitor of Sender should show the value that is being sent while the receiver will receive it display it on its serial monitor. The screen should look something like this.


 

You should also notice the RSSI value of each message received by the LoRa module. The term RSSI  stands for Received Signal Strength Indicator. The value will always be in negative, in our case it is around -68. The closer this value is to zero the stronger your signal strength is. For instance if I move both the devices far apart the signal strength will go down.

With this set-up I was able to receive the signal for about 500m with obstacles in between. The value should defiantly be high for Line of sight communication and better antennas. The working can also be found at the video below. Hope you understood the project and enjoyed building something out of it, if you have any problem in getting it to work leave your questions in the comment section and I will try my best answering them.


 
Code
LORA code for Transmitting Side

#include <SPI.h>
#include <LoRa.h>

int counter = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  LoRa.setTxPower(20);
  
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("help needed  at ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(5000);
}

 
