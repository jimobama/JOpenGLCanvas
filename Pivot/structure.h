
#ifndef STRUCTURE_DEF
#define STRUCTURE_DEF
struct Indicator {
	Indicator() {
		this->next = 0;
		value = 0.0;
		title = "";
	}
	Indicator *next;
	double value;
	char *title;
};

#endif