#include <stdio.h>
#include <stdint.h>

uint16_t MCU_TempSensorCalc(uint16_t ADCResult);

int main(void)
{
	uint16_t ADCRead[20] = 
	{ 
		4049, 	//0
		4018,	//10
		3973, 	//20
		3907,	//30
		3815,	//40
		3692,	//50
		3532,	//60
		3333,	//70
		3097,	//80
		2830,	//90
		2540,	//100
		2242,	//110
		1947,	//120
		1669,	//130	
		4035,	//5
		3943,	//25
		3758,	//45
		3438,	//65
		2687,	//95
		1805	//125
	};
	
	for(uint8_t i=0; i<20; i++)
	{
		printf("ADCResult = %d -> temprature = %d degC\n", ADCRead[i], MCU_TempSensorCalc(ADCRead[i]));
		printf("\n");
	}
}

uint16_t MCU_TempSensorCalc(uint16_t ADCResult)
{
	float divisor;
	
	if(ADCResult > 4049)
	{
		return (0);
	}

	if(ADCResult <= 4049 && ADCResult > 4018)		//0 to 9
	{
		divisor = 3.0f;
	}
	else if(ADCResult <= 4018 && ADCResult > 3973)	//10 to 19
	{
		divisor = 3.1f;
	}
	else if(ADCResult <= 3973 && ADCResult > 3907)	//20 to 29
	{
		divisor = 3.8f;
	}
	else if(ADCResult <= 3907 && ADCResult > 3815)	//30 to 39
	{
		divisor = 4.7333f;
	}
	else if(ADCResult <= 3815 && ADCResult > 3692)	//40 to 49
	{
		divisor = 5.85f;
	}
	else if(ADCResult <= 3692 && ADCResult > 3532)	//50 to 59
	{
		divisor = 7.14f;
	}
	else if(ADCResult <= 3532 && ADCResult > 3333)	//60 to 69
	{
		divisor = 8.6166f;
	}
	else if(ADCResult <= 3333 && ADCResult > 3097)	//70 to 79
	{
		divisor = 10.2285f;
	}
	else if(ADCResult <= 3097 && ADCResult > 2830)	//80 to 89
	{
		divisor = 11.9f;
	}
/*4th	else if(ADCResult <= 2830 && ADCResult > 2540)	//90 to 99
	{
		divisor = 13.5444f;
	}	*/
/*3rd	else if(ADCResult <= 2540 && ADCResult > 2242)	//100 to 109
	{
		divisor = 15.09f;
	}	*/
/*	else if(ADCResult <= 2242 && ADCResult > 1947)	//110 to 119
	{
		divisor = 16.427272;
	}	*/
/*	else if(ADCResult <= 1947 && ADCResult > 1669)	//120 and above
	{
		divisor = 18.248f;
	}	*/
/*	else 
	{
		return(130);
	}	*/

	return ((uint16_t)((4049 - ADCResult)/divisor));
}

