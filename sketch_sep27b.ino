#include "Adafruit_VEML6070.h"
#include <SoftwareSerial.h>
#include "SerialMP3Player.h"

#define TX 9
#define RX 10

#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
SerialMP3Player mp3(RX,TX);

int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

Adafruit_VEML6070 uv = Adafruit_VEML6070(); //uv

void setup() {

Serial.begin(9600);
mp3.begin(9600);
delay(50);

mp3.sendCommand(CMD_SEL_DEV, 0, 1);
delay(50);

pinMode(S0, OUTPUT); //Setting S0 sebagai output
pinMode(S1, OUTPUT); //Setting S1 sebagai output
pinMode(S2, OUTPUT); //Setting S2 sebagai output
pinMode(S3, OUTPUT); //Setting S3 sebagai output
pinMode(sensorOut, INPUT); //Setting Outsensor sebagai Input

uv.begin(VEML6070_1_T); // pass in the integration time constant

//Setting frequency-scaling to 20%
digitalWrite(S0,HIGH);
digitalWrite(S1,LOW);

}

void loop() {
//Setting baca merah
digitalWrite(S2,LOW);
digitalWrite(S3,LOW);
redFrequency = pulseIn(sensorOut, LOW);
Serial.print("R= ");
Serial.print(redFrequency);
Serial.print(" ");
delay(10);

//Setting baca hijau
digitalWrite(S2,HIGH);
digitalWrite(S3,HIGH);
greenFrequency = pulseIn(sensorOut, LOW);
Serial.print("G= ");
Serial.print(greenFrequency);
Serial.print(" ");
delay(10);

//Setting baca biru
digitalWrite(S2,LOW);
digitalWrite(S3,HIGH);
blueFrequency = pulseIn(sensorOut, LOW);
Serial.print("B= ");
Serial.print(blueFrequency);
Serial.println(" ");
delay(10);

Serial.print("UV: ");
Serial.println(uv.readUV());
if (redFrequency >=41 && redFrequency <=42 && greenFrequency == 52 &&
blueFrequency == 15 && uv.readUV() >=2)
{
Serial.println("100.000");
mp3.play(6);
delay(1000);
}
else if (redFrequency ==38 && greenFrequency >=43 && greenFrequency
<= 44 && blueFrequency ==13 && uv.readUV() >=2)
{
Serial.println("100.000");
mp3.play(6);
delay(1000);
}
else if (redFrequency ==54 && greenFrequency >=46 && greenFrequency
<= 47 && blueFrequency ==15 && uv.readUV() >=2)
{
Serial.println("50.000");
mp3.play(5);
delay(1000);
}
else if (redFrequency ==49 && greenFrequency >=46 && blueFrequency
==15 && uv.readUV() >=2)
{
Serial.println("50.000");
mp3.play(5);
delay(1000);
}
else if (redFrequency ==46 && greenFrequency >= 40 && greenFrequency
<=41 && blueFrequency >=13 && blueFrequency <=14 && uv.readUV() >=2)
{
Serial.println("20.000");
mp3.play(4);
delay(1000);
}
else if (redFrequency ==43 && greenFrequency ==39 && blueFrequency ==13
&& uv.readUV() >=2)
{
Serial.println("20.000");
mp3.play(4);
delay(1000);
}
else if (redFrequency ==48 && greenFrequency ==49 && blueFrequency ==14
&& uv.readUV() >=2)
{
Serial.println("10.000");
mp3.play(3);
delay(1000);
}
else if (redFrequency ==52 && greenFrequency ==57 && blueFrequency ==17
&& uv.readUV() >=2)
{
Serial.println("10.000");
mp3.play(3);
delay(1000);
}
else if (redFrequency >=37 && redFrequency <=38 && greenFrequency >= 44
&& greenFrequency <=45 && blueFrequency ==14&& uv.readUV() >=2)
{
Serial.println("5.000");
mp3.play(2);
delay(1000);
}
else if (redFrequency ==42 && greenFrequency == 47 && blueFrequency
==15&& uv.readUV() >=2)
{
Serial.println("5.000");
mp3.play(2);
delay(1000);
}
else if (redFrequency ==46 && greenFrequency == 45 && blueFrequency
==14 && uv.readUV() >=2)
{
Serial.println("2.000");
mp3.play(1);
delay(1000);
}
else if (redFrequency >=46 && redFrequency <=47 && greenFrequency == 49
&& blueFrequency ==16 && uv.readUV() >=2)
{
Serial.println("2.000");
mp3.play(1);
delay(1000);
}
else if (redFrequency ==43 && greenFrequency == 45 && blueFrequency
<=15 && blueFrequency >=14 && uv.readUV() >=2)
{
Serial.println("1.000");
mp3.play(9);
delay(1000);
}
else if (redFrequency ==48 && greenFrequency >= 52 && greenFrequency
<= 53 && blueFrequency ==16 && uv.readUV() >=2)
{
Serial.println("1.000");
mp3.play(9);
delay(1000);
}
else if (redFrequency >100 || redFrequency >100 )
{
Serial.println("masukanuang");
mp3.play(8);
delay(1000);
}
else if (redFrequency >=34 && redFrequency <=35 && greenFrequency >= 34
&& greenFrequency <= 35 && blueFrequency == 11)
{
Serial.println("masukanuang");
mp3.play(8);
delay(1000);
}
else {
Serial.println("palsu");
mp3.play(7);
delay(1000);
}
}
