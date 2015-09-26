
#include "camarille.h"
#include "structure.h"


Camarille::Camarille() {
	this->open = 0;
	this->close = 0;
	this->low = 0;
	this->high = 0;
}

Indicator * Camarille::getIndicator()
{
	Indicator *pivot = new Indicator();
	// standard type calculations
	pivot->value = (high + low + close) / 3;
	pivot->title = "Pivot";

	Indicator *support1 = new Indicator();
	support1->value = this->close - (high - low) * (1.1 / 12);;
	support1->title = "support 1";
	//link it to support one;
	pivot->next = support1;


	Indicator *support2 = new Indicator();
	support2->value = this->close - (high - low) * (1.1 / 6);
	support2->title = "support 2";
	support1->next = support2;

	Indicator *support3 = new Indicator();
	support3->value = this->close - (high - low) * (1.1 / 4);
	support3->title = "Support 3";
	support2->next = support3;

	Indicator *support4 = new Indicator();
	support4->value = this->close - (high - low) * (1.1 / 2);
	support4->title = "Support 4";
	support3->next = support4;


	//resistor indicator
	Indicator *resistor1 = new Indicator();
	resistor1->value = this->close + (high - low) * (1.1 / 12);
	resistor1->title = "Resistor1";
	support4->next = resistor1;

	Indicator *resistor2 = new Indicator();
	resistor2->value = this->close + (high - low) * (1.1 / 6);
	resistor2->title = "Resistor 2";
	resistor1-> next = resistor2;

	Indicator *resistor3 = new Indicator();
	resistor3->value = this->close + (high - low) * (1.1 / 4);
	resistor3->title = "Resistor 3";
	resistor2->next = resistor3;

	Indicator *resistor4 = new Indicator();
	resistor4->value = this->close + (high - low) * (1.1 / 2);
	resistor4->title = "Resistor 4";
	resistor3->next = resistor4;
	resistor4->next = 0;
	//resistors
	return pivot;
}

Type* Camarille::setOpen(double open)
{
	this->open = open;
	return this;
}
Type* Camarille::setClose(double close)
{
	this->close = close;
	return this;
}
Type * Camarille::setHigh(double high)
{
	this->high = high;
	return this;
}
Type* Camarille::setLow(double low)
{
	this->low = low;
	return this;
}


Camarille::~Camarille() {

}