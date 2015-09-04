#include <CapacitiveSensor.h>

// Send pin = 4, Receive/Signal pin = 2.
CapacitiveSensor capSensor = CapacitiveSensor( 4, 2 );

void setup() {
	capSensor.set_CS_Timeout_Millis( 1000 );
	Serial.begin( 9600 );
}

void loop() {
	long start = millis();
	long end;
	long delta;

	// Note: As stated in the documentation, the units are arbitrary,
	// so will likely be determined empirically.
	long sensed = capSensor.capacitiveSensorRaw( 30 );

	end = millis();
	delta = end - start;

	Serial.print( delta );
	Serial.print( "ms\t" );
	Serial.println( sensed );

	// delay( 200 );
}
