#include <assert.h>
#include <iostream>
#include "Histogram.hpp"
#include "unitTests.h"
using std::endl;
using std::cout;

void testInsert() {
	Histogram h;
	ASSERT_EQUALS(h.size(), 0);
	h.insert(0);
	ASSERT_EQUALS(h.size(), 1);
	h.insert(100);
	h.insert(10);
	h.insert(0);
	ASSERT_EQUALS(h.size(), 4);
	ASSERT_THROWS(HistogramBadRangeError, h.insert(101));
	ASSERT_THROWS(HistogramBadRangeError, h.insert(-1));
}


void testGetTop() {
	Histogram h;
	ASSERT_EQUALS(h.getTop(0), 0);
	ASSERT_THROWS(HistogramKTooBig, h.getTop(1));
	h.insert(0);
	h.insert(10);
	h.insert(30);
	h.insert(40);
	h.insert(50);
	h.insert(60);
	h.insert(100);
	ASSERT_EQUALS(h.getTop(0), 0);
	ASSERT_EQUALS(h.getTop(1), 100);
	ASSERT_EQUALS(h.getTop(2), 160);
	ASSERT_EQUALS(h.getTop(3), 210);
	ASSERT_EQUALS(h.getTop(4), 250);
	ASSERT_EQUALS(h.getTop(5), 280);
	ASSERT_EQUALS(h.getTop(6), 290);
	ASSERT_EQUALS(h.getTop(7), 290);
	ASSERT_THROWS(HistogramKTooBig, h.getTop(8));
}

int main() {
	cout << "-------HISTOGRAM TESTS-----------" << endl;
	RUN_TEST(testInsert);
	RUN_TEST(testGetTop);
	return 0;
}


