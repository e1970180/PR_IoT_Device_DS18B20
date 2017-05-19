#include "PR_IoT_Device_DS18B20.h"

    #include <arduino.h>    
  
	void 	PR_IoT_DS18B20::announce() {
		postMsg("", "HELLO"); 
	}
	
	void 	PR_IoT_DS18B20::setupHW(uint8_t pin, uint8_t resolution) {
		
		oneWire = new OneWire(pin);    					//
		sensors = new DallasTemperature(oneWire);       // Pass our oneWire reference to Dallas Temperature. 
		sensors->begin();
		sensors->setResolution(resolution);
	}   
	
	void	PR_IoT_DS18B20::loopHW() {	
		
		if ( (IoTtime.now() - lastMeasuredTime) > TEMPERATURE_MEAS_INTERVAL ) {
			sensors->requestTemperatures();
			lastMeasuredTemp = sensors->getTempCByIndex(0);
		
			lastMeasuredTime = IoTtime.now();
		}
	}

	
	void	PR_IoT_DS18B20::update() {	
		
		postMsg("", String(lastMeasuredTemp, 1));
	}
	
	void	PR_IoT_DS18B20::inMsgCallback() {

		PR_DBGTLN("Swithc: Msg got")
		PR_DBGVLN(inMsg.payload)
		
		if (inMsg.payload == "ASK")	{
			invoke();
		}
	}
	
