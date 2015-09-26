

#ifndef FIBONACCI_H
#define FIBONACCI_H
#include"ptype.h"
struct Indicator;

class Fibonacci :public Type {
	double open, close, low, high;
public:
	Fibonacci();
	virtual ~Fibonacci();
	virtual Indicator * getIndicator();
	virtual Type* setOpen(double open);
	virtual Type* setClose(double close);
	virtual Type* setHigh(double high);
	virtual Type* setLow(double low);

};
#endif