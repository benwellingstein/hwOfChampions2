#include <assert.h>
#include <iostream>
#include "Colosseum.hpp"
#include "unitTests.h"
using std::endl;
using std::cout;

int IdArr[] = {1,2,3,4,5};


#define ADD_GLADIATORS	col.addGladiator(11, 100, 1);\
						col.addGladiator(12, 10, 1);\
						col.addGladiator(13, 10, 1);\
						col.addGladiator(14, 10, 1);\
						col.addGladiator(15, 10, 1);\
						\
						col.addGladiator(21, 1000, 2);\
						col.addGladiator(22, 10, 2);\
						col.addGladiator(23, 10, 2);\
						col.addGladiator(24, 10, 2);\
						col.addGladiator(25, 10, 2);\
						\
						col.addGladiator(31, 10000, 3);\
						col.addGladiator(32, 10, 3);\
						col.addGladiator(33, 10, 3);\
						col.addGladiator(34, 10, 3);\
						col.addGladiator(35, 10, 3);\


/* Description:   Creates a new Colosseum
 * Input:		  n - number of training groups
 * 				  trainingGroupsIDs - pointer to array of ids for groups
 * Output:        A new Colosseum.
 * Throws :	  	  badArgException - If allocation error, or if n<2,
 *				  or if one of IDs are negative, or if double instance of id,
 *				  or other error
 * Complexity:	  O((n)), n - number of groups in Colosseum
 */
void testInit() {
	
	ASSERT_THROWS(badArgException, Colosseum(1, IdArr));
	ASSERT_THROWS(badArgException, Colosseum(0, IdArr));
	ASSERT_THROWS(badArgException, Colosseum(-1, IdArr));
	
	int BadIdArr1[] = {1,-2,3,4,5};
	int BadIdArr2[] = {1,2,3,4,-5};
//	int BadIdArr3[] = {0,1,2,3,4,5,6,7,8,9,0};
//	int BadIdArr4[] = {0,10,2,3,4,50,6,7,80,9,100,2};
	ASSERT_THROWS(badArgException, Colosseum(5,BadIdArr1));
	ASSERT_THROWS(badArgException, Colosseum(5,BadIdArr2));
//	ASSERT_THROWS(badArgException, Colosseum(11,BadIdArr3));
//	ASSERT_THROWS(badArgException, Colosseum(12,BadIdArr4));
	
	int ZeroIdArr1[] = {0,1,2,3,4};
	ASSERT_NO_THROW(Colosseum(5, ZeroIdArr1));
	ASSERT_NO_THROW(Colosseum(5, IdArr));
}


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
void testAddTrainingGroup() {
	Colosseum col(5,IdArr);
	ASSERT_EQUALS(col.addTrainingGroup(-1), INVALID_INPUT);
	ASSERT_EQUALS(col.addTrainingGroup(0), SUCCESS);
	ASSERT_EQUALS(col.addTrainingGroup(0), FAILURE);
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
void testAddGladiator() {
	Colosseum col(5,IdArr);
	ASSERT_EQUALS(col.addGladiator(-1, 90, 3), INVALID_INPUT);
	ASSERT_EQUALS(col.addGladiator(1337, 90, -10), INVALID_INPUT);
	ASSERT_EQUALS(col.addGladiator(1337, -1, 5), INVALID_INPUT);
	
	ASSERT_EQUALS(col.addGladiator(10, 90, 2), SUCCESS);
	ASSERT_EQUALS(col.addGladiator(0, 90, 3), SUCCESS);
	col.addTrainingGroup(0);
	ASSERT_EQUALS(col.addGladiator(666, 90, 0), SUCCESS);
	ASSERT_EQUALS(col.addGladiator(1, 100, 1), SUCCESS);
	ASSERT_EQUALS(col.addGladiator(2, 0, 1), SUCCESS);

	ASSERT_EQUALS(col.addGladiator(2, 0, 1), FAILURE);
	ASSERT_EQUALS(col.addGladiator(2, 0, 12345), FAILURE);
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
void testTrainingGroupFight() {
	Colosseum col(5,IdArr);
	ASSERT_EQUALS(col.trainingGroupFight(-2, 3, 10, 20), INVALID_INPUT);
	ASSERT_EQUALS(col.trainingGroupFight(2, -3, 10, 20), INVALID_INPUT);
	ASSERT_EQUALS(col.trainingGroupFight(2, 3, 0, 20), INVALID_INPUT);
	ASSERT_EQUALS(col.trainingGroupFight(2, 3, -1, 20), INVALID_INPUT);
	ASSERT_EQUALS(col.trainingGroupFight(2, 3, 10, 0), INVALID_INPUT);
	ASSERT_EQUALS(col.trainingGroupFight(2, 3, 10, -20), INVALID_INPUT);

	/* Adds gladiators
	 * 5 gladiators in teams 1 2 3
	 * one strong one in every group, team power is 1 < 2 < 3
	 */
	ADD_GLADIATORS;
	
	
	//test bad k1/k2 sizes
	ASSERT_EQUALS(col.trainingGroupFight(1, 2, 100, 3), FAILURE);
	ASSERT_EQUALS(col.trainingGroupFight(1, 2, 3, 100), FAILURE);
	
	//test not in colosseum
	ASSERT_EQUALS(col.trainingGroupFight(10, 2, 3, 3), FAILURE);
	ASSERT_EQUALS(col.trainingGroupFight(1, 20, 3, 3), FAILURE);

	//not able to fight
	ASSERT_EQUALS(col.trainingGroupFight(1, 2, 5, 5), SUCCESS);
	ASSERT_EQUALS(col.trainingGroupFight(1, 3, 1, 1), FAILURE);
}

/* Description:   Finds lowest ID of a still active training group
 * Input:		  trainingGroup - pointer to return answer with
 * Output:        ID of training group.
 * Return Values: INVALID_INPUT - if trainingGroup == NULL
 *                FAILURE - In case of error.
 *                SUCCESS - Otherwise.
 * Complexity:	  O(1),
 */
void getMinTrainingGroup() {
	Colosseum col(5,IdArr);
	ASSERT_EQUALS(col.getMinTrainingGroup(NULL), INVALID_INPUT);
	
	//good run - all teams are active and 1 is the smallest
	int ans = -1;
	ASSERT_EQUALS(col.getMinTrainingGroup(&ans), SUCCESS);
	ASSERT_EQUALS(ans, 1);
	
	/* Adds gladiators
	 * 5 gladiators in teams 1 2 3
	 * one strong one in every group, team power is 1 < 2 < 3
	 */
	ADD_GLADIATORS;
	
	//make group 1 loose and get 2 as answer
	col.trainingGroupFight(1, 2, 5, 5);
	ASSERT_EQUALS(col.getMinTrainingGroup(&ans), SUCCESS);
	ASSERT_EQUALS(ans, 2);
}

int main() {
	cout << "-------COLOSSEUM TESTS-----------" << endl;
	RUN_TEST(testInit);
	RUN_TEST(testAddTrainingGroup);
	RUN_TEST(testAddGladiator);
	RUN_TEST(testTrainingGroupFight);
	RUN_TEST(getMinTrainingGroup);
	
	return 0;
}

