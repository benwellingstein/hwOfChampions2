
#include "TrainingHashTable.hpp"


//---------------Training Group Functions-----------------------------------
TrainingHashTable::TrainingGroup::TrainingGroup(int id, void* minHeapP,
												bool active) :
					id(id),minHeapP(minHeapP), active(true), gladiatorTree() {}

void TrainingHashTable::TrainingGroup::addGladiator(int score) {
	gladiatorTree.insert(score);
}


bool TrainingHashTable::TrainingGroup::illegalK(int k) {
	return gladiatorTree.sumOfBestN(k) == -1;
}

int TrainingHashTable::TrainingGroup::power(int k) {

	return gladiatorTree.sumOfBestN(k);
}

void TrainingHashTable::TrainingGroup::disqualify() {
	active = false;
}

bool TrainingHashTable::TrainingGroup::inactive() {
	return active == false;
}


bool operator==(const TrainingHashTable::TrainingGroup& first,
				const TrainingHashTable::TrainingGroup& second) {
	return first.id == second.id;
}

void* TrainingHashTable::TrainingGroup::heapP() {
	return minHeapP;
}


//---------------TrainingHashTable Public Functions-----------------------------------

TrainingHashTable::TrainingHashTable(int n, int* idArr, void** pArr) :
													hashFunc(n), table(n) {
	for (int i = 0; i < n ; ++i) {
		TrainingGroup* newGroup = new TrainingGroup(idArr[i], pArr[i], true);
		table.insert(newGroup, hashFunc(idArr[i]));
	}
}
void TrainingHashTable::insert(int id, void* heapP) {
	if (exists(id)) return;
	TrainingGroup* newGroup = new TrainingGroup(id, heapP, true);
	if (table.insert(newGroup,hashFunc(id))) hashFunc.update();
}

bool TrainingHashTable::exists(int id) const {
	TrainingGroup tempGroup(id, nullptr, true);
	return table.exists(&tempGroup, hashFunc(id));
}

bool TrainingHashTable::isInactive(int id)  {
	return !exists(id) ||
		   getGroup(id)->inactive();
	
}

void TrainingHashTable::addGladiator(int score, int groupID) {
	if (!exists(groupID)) return;
	TrainingGroup* group = getGroup(groupID);
	//TODO connect
	group->addGladiator(score);
}


//returns heap pointer of team that lost or -1 if failure
void* TrainingHashTable::trainingGroupFight(int trainingGroup1, int trainingGroup2,
										  int k1, int k2) {
	
	if (trainingGroup1 == trainingGroup2) return NULL;
	if (!exists(trainingGroup1) || !exists(trainingGroup2)) return NULL;
	TrainingGroup* group1 = getGroup(trainingGroup1);
	TrainingGroup* group2 = getGroup(trainingGroup2);
	
	
	if (group1->inactive() || group2->inactive()) return NULL;
	if (group1->illegalK(k1) || group2->illegalK(k2)) return NULL;
	
	int group1Power = group1->power(k1);
	int group2Power = group2->power(k2);
	
	//if tie lower id wins - return higher id
	if (group1Power == group2Power){
		if (trainingGroup1 < trainingGroup2) {
			group2->disqualify();
			return group2->heapP();
		} else {
			group1->disqualify();
			return group1->heapP();
		}
	}
	//return loosing team
	if (trainingGroup1 < trainingGroup2) {
		group1->disqualify();
		return group1->heapP();
	} else {
		group2->disqualify();
		return group2->heapP();
	}
}

bool TrainingHashTable::illegalK(int groupID, int k){
	return getGroup(groupID)->illegalK(k);
}

//-----------------private helper functions--------------------------

TrainingHashTable::TrainingGroup* TrainingHashTable::getGroup(int id) {
	TrainingGroup tempGroup(id, nullptr, true);
	return table.getGroup( &tempGroup, hashFunc(id) );
}

