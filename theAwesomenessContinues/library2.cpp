
#include <stdio.h>
#include "library2.h"
#include "Colosseum.hpp"


void* init(int n, int* trainingGroupsIDs) {
	Colosseum* DS = NULL;
	try {
	DS = new Colosseum(n, trainingGroupsIDs);
	}
	catch (const badArgException& e) {
		return NULL;
	}
	return (void*)DS;
}

StatusType   addTrainingGroup (void* DS, int trainingGroupID) {
	if (!DS) return INVALID_INPUT;
	return ((Colosseum*)DS)->addTrainingGroup(trainingGroupID);
}

StatusType addGladiator(void* DS,int gladiatorID,int score,int trainingGroup) {
	if (!DS) return INVALID_INPUT;
	return ((Colosseum*)DS)->addGladiator(gladiatorID, score, trainingGroup);
}

StatusType trainingGroupFight (void* DS, int trainingGroup1, int trainingGroup2,
							   int k1, int k2) {
	if (!DS) return INVALID_INPUT;
	return ((Colosseum*)DS)->trainingGroupFight(trainingGroup1, trainingGroup2,
												k1,k2);
}

StatusType getMinTrainingGroup (void* DS, int* trainingGroup) {
	if (!DS) return INVALID_INPUT;
	return ((Colosseum*)DS)->getMinTrainingGroup(trainingGroup);
}

void quit(void** DS) {
	delete *((Colosseum**)DS);
	*DS = NULL;
}

