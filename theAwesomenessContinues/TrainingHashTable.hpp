#ifndef TrainingHashTable_hpp
#define TrainingHashTable_hpp
#include <stdio.h>
#include "DynamicArray.hpp"
#include "Hash.hpp"
#include "SplayTree.hpp"



class TrainingHashTable {
public:
	TrainingHashTable(int n, int* idArr, void** pArr);
	void insert(int id, void* heapP);
	bool exists(int id) const;
	//returns heap pointer of team that lost or -1 if failure
	void* trainingGroupFight(int trainingGroup1, int trainingGroup2,
						   int k1, int k2);
	void addGladiator(int score, int groupID);
	bool isInactive(int id);
	bool illegalK(int groupID, int k);
	
private:
	
	class TrainingGroup {
	public:
		TrainingGroup(int id, void* minHeapP, bool active);
		void addGladiator(int score);
		bool illegalK(int k);
		bool inactive();
		int power(int k);
		void disqualify();
		void* heapP();
		friend TrainingHashTable;
		friend bool operator==(const TrainingGroup& first,
							   const TrainingGroup& second);
	private:
		int id;
		void* minHeapP;
		bool active;
		SplayTree gladiatorTree;
		
	};
	
	
	TrainingGroup* getGroup(int id);

	
	Hash hashFunc;
	DynamicArray<TrainingGroup> table;

public:
	friend bool operator==(const TrainingGroup& first,
						   const TrainingGroup& second);
};



#endif /* TrainingHashTable_hpp */
