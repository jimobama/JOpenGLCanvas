
#include "woodies.h"
#include "structure.h"


Woodies::Woodies() {
	this->open = 0;
	this->close = 0;
	this->low = 0;
	this->high = 0;
}

Indicator * Woodies::getIndicator()
{
	// standard type calculations
	Indicator *pivot = new Indicator();
	pivot->value = (high + low + (2 * close)) / 4;
	pivot->title = "Pivot";

	Indicator *s1 = new Indicator();
	s1->value = (2 * pivot->value) - high;
	s1->title = "Support 1";
	pivot->next = s1;
	Indicator *s2 = new Indicator();
	s2->value = pivot->value - (high - low);
	s2->title = "Support 2";
	s1->next=s2;	
	Indicator *s3 = new Indicator();
	s3->value = this->low - 2 * (high - pivot->value);
	s3->title = "Support 3";
	s2->next = s3;

	Indicator *r1 = new Indicator();
	r1->value = (2 * pivot->value) - low;
	r1->title = "Resistor 1";
	s3->next=r1;
	Indicator *r2 = new Indicator();
	r2->value = pivot->value + (high - low);
	r2->title = "Resistor 2";
	r1->next = r2;
	Indicator *r3 = new Indicator();

	r3->value = this->high - 2 * (pivot->value - low);
	r3->title = "Resistor 3";
	r2->next = r3;
	r3->next = 0;
	return pivot;
}

Type* Woodies::setOpen(double open)
{
	this->open = open;
	return this;
}
Type* Woodies::setClose(double close)
{
	this->close = close;
	return this;
}
Type * Woodies::setHigh(double high)
{
	this->high = high;
	return this;
}
Type* Woodies::setLow(double low)
{
	this->low = low;
	return this;
}


Woodies::~Woodies() {
	
}