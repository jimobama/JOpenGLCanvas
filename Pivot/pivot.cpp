#include "pivot.h"
#include "ptype.h"
#include "standardtype.h"


Pivot::Pivot() {
	this->open = 0;
	this->close = 0;
	this->high = 0;
	this->low = 0;
	this->useType(0);
}

Pivot::~Pivot()
{
	delete this->__type;
}


Pivot* Pivot::setClose(double close)
{
	this->close = close;
	return this;
}


Pivot* Pivot::setHigh(double high)
{
	this->high = high;
	return this;
}
Pivot* Pivot::setLow(double low)
{
	this->low = low;
	return this;
}
Pivot* Pivot::setOpen(double open)
{
	this->open = open;
	return this;
}

Pivot* Pivot::useType(Type *type)
{
	if (type == 0) {
		type = new StandardType();
	}
	this->__type = type;
	return this;


}

Indicator * Pivot::getIndicator() {
	this->__type->setOpen(this->open)
		->setClose(this->close)
		->setHigh(this->high)
		->setLow(this->low);

	return this->__type->getIndicator();
}

