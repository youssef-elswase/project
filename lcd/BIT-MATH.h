/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------

    name:BIT-MATH
	
	layer:LIB

	by:Youssef Elswase


-------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_



#define REGISTER_SIZE 8

#define SET_BIT(reg,bit) reg|=(1<<bit) 
#define CLR_BIT(reg,bit) reg&=(~(1<<bit)) 
#define TOG_BIT(reg,bit) reg^=(1<<bit) 
#define RED_BIT(reg,bit) (reg&(1<<bit))>>bit 

#define ROR(reg,num) reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))
#define ROL(reg,num) reg= (reg>>(REGISTER_SIZE-num))|(reg<<(num))




#endif