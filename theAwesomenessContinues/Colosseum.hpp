#ifndef Colosseum_hpp
#define Colosseum_hpp

#include <stdio.h>
#include <exception>
#include "library2.h"
#include "TrainingHashTable.hpp"
#include "MinHeap.hpp"
#include "SplayTree.hpp"

class badArgException : public std::exception {};

class Colosseum {
public:
	
	/* Description:   Creates a new Colosseum
	 * Input:		  n - number of training groups
	 * 				  trainingGroupsIDs - pointer to array of ids for groups
	 * Output:        A new Colosseum.
	 * Throws :	  	  badArgException - If allocation error, or if n<2,
	 *				  or if one of IDs are negative,or if double instance of id,
	 *				  or other error
	 * Complexity:	  O((n)), n - number of groups in Colosseum
	 */
	Colosseum(int n, int * trainingGroupsIDs);
	
	/* Description:   Adds a new Training Group to the system.
	 * Input:		  trainingGroupID - ID of the trainer Group to add.
	 * Output:        None.
	 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
	 *                INVALID_INPUT - if trainingGroupID <0
	 *                FAILURE - If trainingGroupID is already in the Colosseum,
	 *				  or other error
	 *                SUCCESS - Otherwise.
	 * Complexity:	  O(log(n)), n - number of groups in Colosseum
	 */
	StatusType addTrainingGroup(int trainingGroupID);
	
	/* Description:   Adds a new gladiator to the system.
	 * Input:		  gladiatorID - ID of the gladiator to add
	 *                score - The score of the gladiator
	 *                trainingGroup - The gladiator's training group
	 * Output:        None.
	 * Return Values: ALLOCATION_ERROR - In case of an allocation error.
	 *                INVALID_INPUT - if gladiatorID <0, or trainingGroup<0, or
	 *				  score<0, or score>100
	 *                FAILURE - If gladiatorID is already in the Colosseum,
	 *				  or trainingGroup isn't in the Colosseum, or other error.
	 *                SUCCESS - Otherwise.
	 * Complexity:	  O(log(m)), m - number of gladiators in Colosseum
	 */
	StatusType addGladiator(int gladiatorID, int score, int trainingGroup);
	
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
	StatusType trainingGroupFight(int trainingGroup1, int trainingGroup2,
								  int k1, int k2);
	
	/* Description:   Finds lowest ID of a still active training group
	 * Input:		  trainingGroup - pointer to return answer with
	 * Output:        ID of training group.
	 * Return Values: INVALID_INPUT - if trainingGroup == NULL
	 *                FAILURE - In case of error.
	 *                SUCCESS - Otherwise.
	 * Complexity:	  O(1),
	 */
	StatusType getMinTrainingGroup(int * trainingGroup);
	
private:
	MinHeap* groupHeap;
	TrainingHashTable* trainingTable;
	SplayTreeModified<int>* gladiatorTree;
};


#endif /* Colosseum_hpp */
