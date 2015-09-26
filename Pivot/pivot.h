#ifndef PIVOT_CALCULATOR
#define PIVOT_CALCULATOR
//Forward declaration
struct Indicator;
class Type;
//Create a simple class that will carry out all the calculations
class Pivot
{

public:
	Pivot();
	virtual ~Pivot();
	Pivot * setLow(double low);
	Pivot * setClose(double close);
	Pivot * setHigh(double high);
	Pivot * setOpen(double open);
	Pivot * useType(Type *type);
	Indicator  *getIndicator();

private:
	double open, close, low, high;
	Type *__type;
};




#endif // PIVOT_CALCULATOR

