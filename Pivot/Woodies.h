
#ifndef WOODIES_H
#define WOODIES_H
#include"ptype.h"
struct Indicator;


class Woodies :public Type {
private:

	double open, close, low, high;
public:
	Woodies();
	virtual ~Woodies();
	virtual Indicator * getIndicator();
	virtual Type* setOpen(double open);
	virtual Type*  setClose(double close);
	virtual Type*  setHigh(double high);
	virtual Type* setLow(double low);

};
#endif