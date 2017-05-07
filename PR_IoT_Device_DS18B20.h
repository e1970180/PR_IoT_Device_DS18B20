#ifndef PR_IoT_Device_DS18B20_h
#define PR_IoT_Device_DS18B20_h

    #include <arduino.h>
    #include <PR_IoT.h>

	#include <OneWire.h>
	#include <DallasTemperature.h> //https://milesburton.com/Dallas_Temperature_Control_Library

	#ifndef	ONE_WIRE_BUS
		#define	ONE_WIRE_BUS	12		// as D6
	#endif
	
	#ifndef	TEMPERATURE_PRECISION
		#define	TEMPERATURE_PRECISION	9		//
	#endif
	
	
class PR_IoT_DS18B20 : public PR_IoT_DeviceClass {
        public:
            PR_IoT_DS18B20(String name) : PR_IoT_DeviceClass(name) {}; 
            
            void 			announce();
            void 			update();
            virtual void 	inMsgCallback(); 
            virtual void 	setupHW();   
			virtual void	loopHW()			{}			
        protected:
    		OneWire                 *oneWire;    //for shadow  temp sensor
			DallasTemperature       *sensors;       // Pass our oneWire reference to Dallas Temperature. 
	
	};
	
#endif