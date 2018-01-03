#ifndef Hash_hpp
#define Hash_hpp

#include <stdio.h>

class Hash {
public:
	explicit Hash(int size);
	void update(int newSize);
	int operator()(int input) const;
	
private:
	int size;
};

#endif /* Hash_hpp */
