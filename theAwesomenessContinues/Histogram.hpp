#ifndef Histogram_hpp
#define Histogram_hpp

#include <stdio.h>
#include <exception>

class HistogramBadRangeError : public std::exception {};
class HistogramKTooBig : public std::exception {};

class Histogram {
public:
	Histogram();
	
	//throws HistogramBadRangeError if bad range given
	void insert(int val);
	
	//throws HistogramKTooBig if bad range given
	int getTop(int k) const;
	
	int size() const;
	
private:
	int data[101];
	int amountOfData;
};



#endif /* Histogram_hpp */
