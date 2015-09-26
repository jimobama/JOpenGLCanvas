#ifndef INDICATOR_INTERFACE_WRITER_H
#define INDICATOR_INTERFACE_WRITER_H
struct Indicator;
class IIndicatorWriter
{
public:
	//interface methods
	 virtual void write(Indicator *indicator)=0;
};

#endif