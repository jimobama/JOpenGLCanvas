
#ifndef CAMARILLE_H
#define  CAMARILLE_H
#include "ptype.h"
struct Indicator;

class Camarille :public Type
{
	
	double open, close, high, low;
public:
	Camarille();
	virtual ~Camarille();
	virtual Indicator * getIndicator();
	virtual Type* setOpen(double open);
	virtual Type* setClose(double close);
	virtual Type* setHigh(double high);
	virtual Type* setLow(double low);
};


#endif