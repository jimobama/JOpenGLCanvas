
#include "fibonacci.h"
#include "structure.h"


Fibonacci::Fibonacci() {
	
	this->open = 0;
	this->close = 0;
	this->low = 0;
	this->high = 0;
}

Indicator * Fibonacci::getIndicator()
{
	Indicator *pivot= new  Indicator();
	pivot->value = (high + low + close) / 3;
	pivot->title = "Pivot";


	Indicator *s1 = new  Indicator();
	s1->value = pivot->value - 0.382 * (high - low);
	s1->title = "Support 1";
	pivot->next = s1;

	Indicator *s2 = new  Indicator();
	s2->value = pivot->value - 0.618 * (high - low);
	s2->title = "Support 2";
	s1->next = s2;

	Indicator *s3 = new  Indicator();
	s3->value = pivot->value - 1.000 * (high - low);
	s3->title = "Support 3";
	s2->next = s3;

	Indicator *r1 = new  Indicator();
	r1->value = pivot->value + 0.382 * (high - low);
	r1->title = "Resistor 1";
	s3->next = r1;

	Indicator *r2 = new  Indicator();
	r2->value = pivot->value + 0.618 * (high - low);
	r2->title = "Resistor 1";
	r1->next = r2;

	Indicator *r3 = new  Indicator();
	r3->value = pivot->value + 1.000 * (high - low);
	r3->title = "Resistor 1";
	r2->next = r3;
	r3->next = 0;


	return pivot;
}

Type* Fibonacci::setOpen(double open)
{
	this->open = open;
	return this;
}
Type* Fibonacci::setClose(double close)
{
	this->close = close;
	return this;
}
Type  *Fibonacci::setHigh(double high)
{
	this->high = high;
	return this;
}
Type* Fibonacci::setLow(double low)
{
	this->low = low;
	return this;
}


Fibonacci::~Fibonacci() {
	
}