
#include "standardtype.h"
#include "structure.h"


StandardType::StandardType() {

	this->open = 0;
	this->close = 0;
	this->low = 0;
	this->high = 0;
}

Indicator * StandardType::getIndicator()
{
	// standard type calculations
	Indicator *pivot = new Indicator();
	pivot->value = (high + low + close) / 3;
	pivot->title = "Pivot";

	Indicator *s1 = new Indicator();
	s1->value = (double)((pivot->value * 2) - this->high);
	s1->title = "Support 1";
	pivot->next=s1;

	Indicator *s2 = new Indicator();
	s2->value = pivot->value - (high - low);
	s2->title = "support 2";
	s1->next = s2;
	Indicator *r1 = new Indicator();
	r1->value = (pivot->value * 2) - low;
	r1->title = "Resistor 1";
	s2->next = r1;

	Indicator *r2 = new Indicator();
	r2->value = (double)(pivot->value + (high - low));
	r2->title = "Resistor 2";
	r1->next = r2;	
	r2->next = 0;
	
	return pivot;
}
Type* StandardType::setOpen(double open)
{
	this->open = open;
	return this;
}
Type* StandardType::setClose(double close)
{
	this->close = close;
	return this;
}
Type  *StandardType::setHigh(double high)
{
	this->high = high;
	return this;
}
Type* StandardType::setLow(double low)
{
	this->low = low;
	return this;
}

StandardType::~StandardType() {
	
}