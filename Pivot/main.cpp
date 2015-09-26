#include <iostream>
#include "pivot.h"
#include "structure.h"
#include "standardtype.h"
#include "IIndicatorWriter.h"
#include "ConsoleIndicatorWriter.h"
#include "Camarille.h"
#include "fibonacci.h"
#include "Woodies.h"

using namespace std;

int main()
{
	Pivot  *calculator = new Pivot();
	calculator->setOpen(1.11250)//done
		->setLow(1.11045)//done
		->setClose(1.12278)
		->setHigh(1.12952)//done
		->useType(new StandardType());

	Indicator * id = calculator->getIndicator();

	std::cerr << " \n*********** Standard Pivot Points *********\n";

	IIndicatorWriter *writer = new ConsoleIndicatorWriter();
	writer->write(id);
	std::cerr << " \n*********** Camarille Pivot Points *********\n";

	calculator->useType(new Camarille());
	id = calculator->getIndicator();
	writer->write(id);

	std::cerr << " \n*********** Fibonacci  Pivot Points *********\n";
	calculator->useType(new Fibonacci());
	id = calculator->getIndicator();
	writer->write(id);

	std::cerr << " \n*********** Woodies Pivot Points *********\n";
	calculator->useType(new Woodies());
	id = calculator->getIndicator();
	writer->write(id);

	getchar();
	return 0;
}

