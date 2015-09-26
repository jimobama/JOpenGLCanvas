#include "ConsoleIndicatorWriter.h"
#include "structure.h"
#include<iostream>


ConsoleIndicatorWriter::ConsoleIndicatorWriter() {
	this->indicator = 0;
}


void  ConsoleIndicatorWriter::write(Indicator *indicator) {

	this->indicator = indicator;
	if (this->indicator != 0)
	{
			
		Indicator *trial = this->indicator;
		while (trial != 0) {
			std::cout << trial->title << "\t=" << trial->value << std::endl;
			trial = trial->next;
		}	

	}
}


ConsoleIndicatorWriter::~ConsoleIndicatorWriter()
{
	
}