#include "Colosseum.hpp"



/* Description:   Creates a new Colosseum
 * Input:		  n - number of training groups
 * 				  trainingGroupsIDs - pointer to array of ids for groups
 * Output:        A new Colosseum.
 * Throws :	  	  badArgException - If allocation error, or if n<2,
 *				  or if one of IDs are negative, or if double instance of id,
 *				  or other error
 * Complexity:	  O((n)), n - number of groups in Colosseum
 */
Colosseum::Colosseum(int n, int* ID_Arr) {
	if (n<2) throw badArgException();
	for (int i =0; i < n; i++) {
		if (ID_Arr[i] < 0) throw badArgException();
	}
	void** heapPtrs = new void*[n];
	groupHeap = new MinHeap(n, ID_Arr, heapPtrs);
	trainingTable = new TrainingHashTable(n, ID_Arr, heapPtrs);
	gladiatorTree = new SplayTreeModified<int>(NULL);
}

/* Description:   Adds a new Training Group to the system.
 * Input:		  trainingGroupID - ID of the trainer Group to add.
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation erx`ror.
 *                INVALID_INPUT - if trainingGroupID <0
 *                FAILURE - If trainingGroupID is already in the Colosseum,
 *				  or other error
 *                SUCCESS - Otherwise.
 * Complexity:	  O(log(n)), n - number of groups in Colosseum
 */
StatusType Colosseum::addTrainingGroup(int trainingGroupID) {
	if (trainingGroupID < 0) return INVALID_INPUT;
	if (trainingTable->exists(trainingGroupID) ) return FAILURE;
	
	void* heapDataP = groupHeap->insert(trainingGroupID);
	trainingTable->insert(trainingGroupID, heapDataP);
	return SUCCESS;
}

/* Description:   Adds a new gladiator to the system.
 * Input:		  gladiatorID - ID of the gladiator to add
 *                score - The score of the gladiator
 *                trainingGroup - The gladiator's training group
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - if gladiatorID <0, or trainingGroup<0, or
 *				  score<0
 *                FAILURE - If gladiatorID is already in the Colosseum,
 *				  or trainingGroup isn't in the Colosseum, or other error.
 *                SUCCESS - Otherwise.
 * Complexity:	  O(log(m)), m - number of gladiators in Colosseum
 */
StatusType Colosseum::addGladiator(int gladiatorID,int score,int trainingGroup){
	if (gladiatorID < 0 || trainingGroup < 0 || score < 0)
		return INVALID_INPUT;
	if (gladiatorTree->exist(gladiatorID)) return FAILURE;
	if (!trainingTable->exists(trainingGroup)) return FAILURE;

	trainingTable->addGladiator(score, trainingGroup);
	gladiatorTree->insert(gladiatorID);
	return SUCCESS;
}
/* Description:   Simulates a training group battle
 * Input:		  trainingGroup1 - ID of the first group
 * 				  trainingGroup2 - ID of the second group
 * 				  k1 - number of gladiators from first group
 * 				  k2 - number of gladiators from second group
 * Output:        None.
 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
 *                INVALID_INPUT - if k1<=0, or k2<=0, or trainingGroup1<0,
 *                or trainingGroup2<0.
 *                FAILURE - If trainingGroup1 or trainingGroup2 are not in
 *                the Colosseum or unable to fight,
 *                or if k1 or k2 are larger than their group size
 *                or other error.
 *                SUCCESS - Otherwise.
 * Complexity:	  O(log(n)+log(m)), m - number of gladiators in Colosseum
 * 								    n - number of trainingGroups in Colosseum
 */
StatusType Colosseum::trainingGroupFight(int ID1, int ID2,
										 int k1, int k2) {
	if (k1 <= 0 || k2<=0 ||
		ID1 < 0 || ID2 < 0) return INVALID_INPUT;
	void* loosingGroup = trainingTable->trainingGroupFight(ID1, ID2, k1, k2);
	if (!loosingGroup) return FAILURE;
	groupHeap->decKey(loosingGroup, -1);
	groupHeap->delMin();
	return SUCCESS;
}

/* Description:   Finds lowest ID of a still active training group
 * Input:		  trainingGroup - pointer to return answer with
 * Output:        ID of training group.
 * Return Values: INVALID_INPUT - if trainingGroup == NULL
 *                FAILURE - In case of error.
 *                SUCCESS - Otherwise.
 * Complexity:	  O(1),
 */
StatusType Colosseum::getMinTrainingGroup(int * trainingGroup){
	if (!trainingGroup) return INVALID_INPUT;
	*trainingGroup = groupHeap->findMin();
	return SUCCESS;
}

