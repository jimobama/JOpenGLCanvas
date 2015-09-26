
#ifndef PIVOT_TYPE_CALULATOR
#define PIVOT_TYPE_CALULATOR

struct Indicator;
class Type {
public:
	virtual Indicator * getIndicator() = 0;
	virtual Type* setOpen(double open)=0;
	virtual Type* setClose(double close)=0;
	virtual Type *setHigh(double high)=0;
	virtual Type* setLow(double low)=0;

};
#endif