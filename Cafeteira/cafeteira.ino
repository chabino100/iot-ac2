#include <Ultrasonic.h>

HC_SR04 sensorCapsula(4, 5);
int servoCapsula = 9;			

HC_SR04 sensorTamano(2, 3);	
int servoDispenser = 10;		

void setup() {
	Serial.begin(9600);	
	pinMode(servoCapsula, OUTPUT);
	pinMode(servoDispenser, OUTPUT);
}

void loop(){
	int capsulaSensorDist = sensorCapsula.distance();
	int tamanhoSensorDist = sensorTamano.distance();	
	
	if (capsulaSensorDist < 20) {
		servoPos(servoCapsula, 90);	
		if (tamanhoSensorDist < 30) {			
			servoPos(servoDispenser, 180);	
		} else {								
			servoPos(servoDispenser, 0);		
		}
	} else {							
		servoPos(servoCapsula, 0);	
		servoPos(servoDispenser, 90);	
	}
	
	Serial.println(String("Distância cápsula: ") + capsulaSensorDist);
	Serial.println(String("Distância tamanho: ") + tamanhoSensorDist);
	
	delay(50);	
}


void servoPos (int servo, int pos)
{
  int microPulso = map(pos, 0,180,1000,2000);
  digitalWrite(servo, HIGH);
  delayMicroseconds(microPulso);
  digitalWrite(servo, LOW);
  delay(10);                   
}
