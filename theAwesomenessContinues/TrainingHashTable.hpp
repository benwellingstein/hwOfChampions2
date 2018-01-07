#ifndef TrainingHashTable_hpp
#define TrainingHashTable_hpp
#include <stdio.h>
#include "DynamicArray.hpp"
#include "Hash.hpp"




class TrainingHashTable {
public:
	TrainingHashTable(int n, int* idArr, void** pArr);
	void insert(int id, void* heapP);
	bool exists(int id) const;
	//returns id of team that lost or -1 if failure
	int trainingGroupFight(int trainingGroup1, int trainingGroup2,
						   int k1, int k2);
	void addGladiator(int score, int groupID);

	
private:
	
	class TrainingGroup {
	public:
		TrainingGroup(int id, void* minHeapP, bool active);
		void addGladiator(int score);
		bool illegalK(int k);
		bool inactive();
		int power(int k);
		void disqualify();
		bool operator==(const TrainingGroup& other);
	private:
		int id;
		void* minHeapP;
		bool active;
		int gladiatorTree;
	};

	
	TrainingGroup* getGroup(int id);
	
	
	Hash hashFunc;
	DynamicArray<TrainingGroup> table;
	
};

#endif /* TrainingHashTable_hpp */
