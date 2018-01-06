#include <assert.h>
#include <iostream>
#include "SplayTree.hpp"
#include "unitTests.h"


using std::endl;
using std::cout;

void testMakeSplayTree() {
    //SplayTree<int> tree;
    SplayTree tree;

    //71, 21, 24, 49, 4, 6, 29, 44, 34, 19, 73, 27, 25, 17, 57, 96, 64, 70, 98, 54
    
    int* n01 = new int(71);
    int* n02 = new int(21);
    int* n03 = new int(24);
    int* n04 = new int(49);
    int* n05 = new int(4);
    int* n06 = new int(6);
    int* n07 = new int(29);
    int* n08 = new int(44);
    int* n09 = new int(34);
    int* n10 = new int(19);
    int* n11 = new int(73);
    int* n12 = new int(27);
    int* n13 = new int(25);
    int* n14 = new int(17);
    int* n15 = new int(57);
    int* n16 = new int(96);
    int* n17 = new int(64);
    int* n18 = new int(70);
    int* n19 = new int(98);
    int* n20 = new int(54);

    ASSERT_TRUE(tree.insert(n01));
    ASSERT_TRUE(tree.insert(n02));
    ASSERT_TRUE(tree.insert(n03));
    ASSERT_TRUE(tree.insert(n04));
    ASSERT_TRUE(tree.insert(n05));
    ASSERT_TRUE(tree.insert(n06));
    ASSERT_TRUE(tree.insert(n07));
    ASSERT_TRUE(tree.insert(n08));
    ASSERT_TRUE(tree.insert(n09));
    ASSERT_TRUE(tree.insert(n10));
    ASSERT_TRUE(tree.insert(n11));
    ASSERT_TRUE(tree.insert(n12));
    ASSERT_TRUE(tree.insert(n13));
    ASSERT_TRUE(tree.insert(n14));
    ASSERT_TRUE(tree.insert(n15));
    ASSERT_TRUE(tree.insert(n16));
    ASSERT_TRUE(tree.insert(n17));
    ASSERT_TRUE(tree.insert(n18));
    ASSERT_TRUE(tree.insert(n19));
    ASSERT_TRUE(tree.insert(n20));
    
    
    std::stringstream out1;
    tree.print(out1);
    //cout<<out1.str();
    ASSERT_TRUE(out1.str() == "54 49 24 17 6 4 19 21 27 25 34 29 44 96 70 57 64 71 73 98 |4 6 17 19 21 24 25 27 29 34 44 49 54 57 64 70 71 73 96 98 |4 6 21 19 17 25 29 44 34 27 24 49 64 57 73 71 70 98 96 54 |");

}

void testInsertSplayTree() {
    SplayTree tree;
    
    //71, 21, 24, 49, 4, 6, 29, 44, 34, 19, 73, 27, 25, 17, 57, 96, 64, 70, 98, 54
    
    int* n01 = new int(71);
    int* n02 = new int(21);
    int* n03 = new int(24);
    int* n04 = new int(49);
    int* n05 = new int(4);
    int* n06 = new int(6);
    int* n07 = new int(29);
    int* n08 = new int(44);
    int* n09 = new int(34);
    int* n10 = new int(19);
    int* n11 = new int(73);
    int* n12 = new int(27);
    int* n13 = new int(25);
    int* n14 = new int(17);
    int* n15 = new int(57);
    int* n16 = new int(96);
    int* n17 = new int(64);
    int* n18 = new int(70);
    int* n19 = new int(98);
    int* n20 = new int(54);

    ASSERT_TRUE(tree.totalNumberOfNodes() == 0);
    ASSERT_TRUE(tree.totalTreeValue() == -1);

    
    ASSERT_TRUE(tree.insert(n01));

    ASSERT_TRUE(tree.totalNumberOfNodes() == 1);
    ASSERT_TRUE(tree.totalTreeValue() == 71);
    
    ASSERT_TRUE(tree.insert(n02));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 2);
    ASSERT_TRUE(tree.totalTreeValue() == 92);

    ASSERT_TRUE(tree.insert(n03));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 3);
    ASSERT_TRUE(tree.totalTreeValue() == 116);
    
    ASSERT_TRUE(tree.insert(n04));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 4);
    ASSERT_TRUE(tree.totalTreeValue() == 165);
    
    ASSERT_TRUE(tree.insert(n05));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 5);
    ASSERT_TRUE(tree.totalTreeValue() == 169);
    
    ASSERT_TRUE(tree.insert(n06));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 6);
    ASSERT_TRUE(tree.totalTreeValue() == 175);
    
    ASSERT_TRUE(tree.insert(n07));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 7);
    ASSERT_TRUE(tree.totalTreeValue() == 204);
    
    ASSERT_TRUE(tree.insert(n08));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 8);
    ASSERT_TRUE(tree.totalTreeValue() == 248);
    
    ASSERT_TRUE(tree.insert(n09));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 9);
    ASSERT_TRUE(tree.totalTreeValue() == 282);
    
    ASSERT_TRUE(tree.insert(n10));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 10);
    ASSERT_TRUE(tree.totalTreeValue() == 301);
    
    ASSERT_TRUE(tree.insert(n11));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 11);
    ASSERT_TRUE(tree.totalTreeValue() == 374);

    ASSERT_TRUE(tree.insert(n12));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 12);
    ASSERT_TRUE(tree.totalTreeValue() == 401);

    ASSERT_TRUE(tree.insert(n13));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 13);
    ASSERT_TRUE(tree.totalTreeValue() == 426);
    
    ASSERT_TRUE(tree.insert(n14));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 14);
    ASSERT_TRUE(tree.totalTreeValue() == 443);

    ASSERT_TRUE(tree.insert(n15));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 15);
    ASSERT_TRUE(tree.totalTreeValue() == 500);

    ASSERT_TRUE(tree.insert(n16));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 16);
    ASSERT_TRUE(tree.totalTreeValue() == 596);

    ASSERT_TRUE(tree.insert(n17));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 17);
    ASSERT_TRUE(tree.totalTreeValue() == 660);

    ASSERT_TRUE(tree.insert(n18));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 18);
    ASSERT_TRUE(tree.totalTreeValue() == 730);

    ASSERT_TRUE(tree.insert(n19));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 19);
    ASSERT_TRUE(tree.totalTreeValue() == 828);

    ASSERT_TRUE(tree.insert(n20));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 20);
    ASSERT_TRUE(tree.totalTreeValue() == 882);

}
void testBestNSplayTree() {
    SplayTree tree;
    
    //71, 21, 24, 49, 4, 6, 29, 44, 34, 19, 73, 27, 25, 17, 57, 96, 64, 70, 98, 54
    
    int* n01 = new int(71);
    int* n02 = new int(21);
    int* n03 = new int(24);
    int* n04 = new int(49);
    int* n05 = new int(4);
    int* n06 = new int(6);
    int* n07 = new int(29);
    int* n08 = new int(44);
    int* n09 = new int(34);
    int* n10 = new int(19);
    int* n11 = new int(73);
    int* n12 = new int(27);
    int* n13 = new int(25);
    int* n14 = new int(17);
    int* n15 = new int(57);
    int* n16 = new int(96);
    int* n17 = new int(64);
    int* n18 = new int(70);
    int* n19 = new int(98);
    int* n20 = new int(54);
    
    ASSERT_TRUE(tree.insert(n01));
    ASSERT_TRUE(tree.insert(n02));
    ASSERT_TRUE(tree.insert(n03));
    ASSERT_TRUE(tree.insert(n04));
    ASSERT_TRUE(tree.insert(n05));
    ASSERT_TRUE(tree.insert(n06));
    ASSERT_TRUE(tree.insert(n07));
    ASSERT_TRUE(tree.insert(n08));
    ASSERT_TRUE(tree.insert(n09));
    ASSERT_TRUE(tree.insert(n10));
    ASSERT_TRUE(tree.insert(n11));
    ASSERT_TRUE(tree.insert(n12));
    ASSERT_TRUE(tree.insert(n13));
    ASSERT_TRUE(tree.insert(n14));
    ASSERT_TRUE(tree.insert(n15));
    ASSERT_TRUE(tree.insert(n16));
    ASSERT_TRUE(tree.insert(n17));
    ASSERT_TRUE(tree.insert(n18));
    ASSERT_TRUE(tree.insert(n19));
    ASSERT_TRUE(tree.insert(n20));
    
    
    std::stringstream out1;
    tree.print(out1);
    ASSERT_TRUE(out1.str() == "54 49 24 17 6 4 19 21 27 25 34 29 44 96 70 57 64 71 73 98 |4 6 17 19 21 24 25 27 29 34 44 49 54 57 64 70 71 73 96 98 |4 6 21 19 17 25 29 44 34 27 24 49 64 57 73 71 70 98 96 54 |");


    ASSERT_TRUE(tree.sumOfBestN(1) == 98);
    ASSERT_TRUE(tree.sumOfBestN(2) == 194);
    ASSERT_TRUE(tree.sumOfBestN(3) == 267);
    ASSERT_TRUE(tree.sumOfBestN(4) == 338);
    ASSERT_TRUE(tree.sumOfBestN(5) == 408);
    ASSERT_TRUE(tree.sumOfBestN(6) == 472);
    ASSERT_TRUE(tree.sumOfBestN(7) == 529);
    ASSERT_TRUE(tree.sumOfBestN(8) == 583);
    ASSERT_TRUE(tree.sumOfBestN(9) == 632);
    ASSERT_TRUE(tree.sumOfBestN(10) == 676);
    ASSERT_TRUE(tree.sumOfBestN(11) == 710);
    ASSERT_TRUE(tree.sumOfBestN(12) == 739);
    ASSERT_TRUE(tree.sumOfBestN(13) == 766);
    ASSERT_TRUE(tree.sumOfBestN(14) == 791);
    ASSERT_TRUE(tree.sumOfBestN(15) == 815);
    ASSERT_TRUE(tree.sumOfBestN(16) == 836);
    ASSERT_TRUE(tree.sumOfBestN(17) == 855);
    ASSERT_TRUE(tree.sumOfBestN(18) == 872);
    ASSERT_TRUE(tree.sumOfBestN(19) == 878);
    ASSERT_TRUE(tree.sumOfBestN(20) == 882);
    ASSERT_TRUE(tree.sumOfBestN(21) == -1);
    
}


int main() {
	cout << "-------MIN HEAP TESTS-----------" << endl;
	RUN_TEST(testMakeSplayTree);
    RUN_TEST(testInsertSplayTree);
    RUN_TEST(testBestNSplayTree);

    return 0;
}



