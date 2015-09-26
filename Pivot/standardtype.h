
#ifndef STANDARD_PIVOT_H
#define STANDARD_PIVOT_H
#include "ptype.h"
struct Indicator;

/*Calculate using the standard formalar*/
class StandardType :public Type {
private:	
	double open, close, low, high;
public:
	StandardType();
	virtual ~StandardType();
	virtual Indicator * getIndicator();
	virtual Type* setOpen(double open);
	virtual Type* setClose(double close);
	virtual Type*  setHigh(double high);
	virtual Type* setLow(double low);

};


#endif