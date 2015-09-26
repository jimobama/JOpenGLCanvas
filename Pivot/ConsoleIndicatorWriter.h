#pragma once
#include"IIndicatorWriter.h"
struct Indicator;
class ConsoleIndicatorWriter:public IIndicatorWriter
{
private:
	Indicator *indicator;
public:
	ConsoleIndicatorWriter();
	virtual ~ConsoleIndicatorWriter();
	virtual void write(Indicator *indicator);

protected:
	

};
