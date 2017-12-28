#include "Histogram.hpp"

Histogram::Histogram() : amountOfData(0) , data() {};


//throws HistogramBadRangeError if bad range given
void Histogram::insert(int val) {
	if (val < 0 || 100 < val) throw HistogramBadRangeError();
	data[val]++;
	amountOfData++;
}

int Histogram::size() const {
	return amountOfData;
}

int Histogram::getTop(int k) const {
	if (k>amountOfData) throw HistogramKTooBig();
	int counter = 0;
	Histogram copy(*this);
	
	int j = 100;
	for (int i=0; i<k; ++i) {
		while (copy.data[j] == 0) {
			--j;
		}
		counter+=j;
		copy.data[j]--;
	}
	
	return counter;
	
}

