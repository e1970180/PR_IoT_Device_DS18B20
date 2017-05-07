#include "PR_IoT_Device_DS18B20.h"

    #include <arduino.h>    
  
	void 	PR_IoT_DS18B20::announce() {
		postMsg("temperature", "HELLO"); 
	}
	
	void 	PR_IoT_DS18B20::setupHW() {
		
		oneWire = new OneWire(ONE_WIRE_BUS);    //for shadow  temp sensor
		sensors = new DallasTemperature(oneWire);       // Pass our oneWire reference to Dallas Temperature. 
		sensors->begin();
		sensors->setResolution(TEMPERATURE_PRECISION);
	}   
			
	void	PR_IoT_DS18B20::update() {	
		
		sensors->requestTemperatures();
		float	t = sensors->getTempCByIndex(0);
		postMsg("temperature", String(t, 1));
	}
	
	void	PR_IoT_DS18B20::inMsgCallback() {

		PR_DBGTLN("Swithc: Msg got")
		PR_DBGVLN(inMsg.payload)
		
		if (inMsg.payload == "ASK")	{
			invoke();
		}
	}
	
