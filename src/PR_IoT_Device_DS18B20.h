#ifndef PR_IoT_Device_DS18B20_h
#define PR_IoT_Device_DS18B20_h

    #include <arduino.h>
    #include <PR_IoT.h>

	#include <OneWire.h>
	#include <DallasTemperature.h> //https://milesburton.com/Dallas_Temperature_Control_Library

	#ifndef	TEMPERATURE_PRECISION
		#define	TEMPERATURE_PRECISION	9		//
	#endif
	
	
class PR_IoT_DS18B20 : public PR_IoT_DeviceClass {
        public:
            PR_IoT_DS18B20(String name) : PR_IoT_DeviceClass(name) {}; 
            ~PR_IoT_DS18B20()	{	delete oneWire; oneWire = NULL; delete sensors; sensors = NULL; }
			
            void 			announce();
            void 			update();
            virtual void 	inMsgCallback(); 
            virtual void 	setupHW(uint8_t pin, uint8_t resolution = TEMPERATURE_PRECISION );   
			virtual void	loopHW()			{}
			
			float 			getTemp()			{	return lastMeasuredTemp;	}
			
        protected:
    		OneWire                 *oneWire;    //for shadow  temp sensor
			DallasTemperature       *sensors;       // Pass our oneWire reference to Dallas Temperature. 
			float 			lastMeasuredTemp;
	
	};
	
#endif