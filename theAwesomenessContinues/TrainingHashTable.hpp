//
//  TrainingHashTable.hpp
//  theAwesomenessContinues
//
//  Created by Ben on 03/01/2018.
//  Copyright © 2018 Ben. All rights reserved.
//

#ifndef TrainingHashTable_hpp
#define TrainingHashTable_hpp
#include <stdio.h>
#include "Hash.hpp"
#include "DynamicArray.hpp"




class TrainingHashTable {
	
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
	private:
		int id;
		void* minHeapP;
		bool active;
		int gladiatorTree;
	};
	
	Hash hashFunc;
	DynamicArray<TrainingGroup> table;
	TrainingGroup* getGroup(int id);
	
};

#endif /* TrainingHashTable_hpp */
