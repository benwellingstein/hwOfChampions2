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

    ASSERT_TRUE(tree.insert(71));
    ASSERT_TRUE(tree.insert(21));
    ASSERT_TRUE(tree.insert(24));
    ASSERT_TRUE(tree.insert(49));
    ASSERT_TRUE(tree.insert(4));
    ASSERT_TRUE(tree.insert(6));
    ASSERT_TRUE(tree.insert(29));
    ASSERT_TRUE(tree.insert(44));
    ASSERT_TRUE(tree.insert(34));
    ASSERT_TRUE(tree.insert(19));
    ASSERT_TRUE(tree.insert(73));
    ASSERT_TRUE(tree.insert(27));
    ASSERT_TRUE(tree.insert(25));
    ASSERT_TRUE(tree.insert(17));
    ASSERT_TRUE(tree.insert(57));
    ASSERT_TRUE(tree.insert(96));
    ASSERT_TRUE(tree.insert(64));
    ASSERT_TRUE(tree.insert(70));
    ASSERT_TRUE(tree.insert(98));
    ASSERT_TRUE(tree.insert(54));
    
    
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


    ASSERT_TRUE(tree.insert(71));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 1);
    ASSERT_TRUE(tree.totalTreeValue() == 71);

    ASSERT_TRUE(tree.insert(21));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 2);
    ASSERT_TRUE(tree.totalTreeValue() == 92);

    ASSERT_TRUE(tree.insert(24));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 3);
    ASSERT_TRUE(tree.totalTreeValue() == 116);

    ASSERT_TRUE(tree.insert(49));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 4);
    ASSERT_TRUE(tree.totalTreeValue() == 165);

    ASSERT_TRUE(tree.insert(4));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 5);
    ASSERT_TRUE(tree.totalTreeValue() == 169);

    ASSERT_TRUE(tree.insert(6));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 6);
    ASSERT_TRUE(tree.totalTreeValue() == 175);

    ASSERT_TRUE(tree.insert(29));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 7);
    ASSERT_TRUE(tree.totalTreeValue() == 204);

    
    ASSERT_TRUE(tree.insert(44));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 8);
    ASSERT_TRUE(tree.totalTreeValue() == 248);

    ASSERT_TRUE(tree.insert(34));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 9);
    ASSERT_TRUE(tree.totalTreeValue() == 282);

    ASSERT_TRUE(tree.insert(19));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 10);
    ASSERT_TRUE(tree.totalTreeValue() == 301);

    ASSERT_TRUE(tree.insert(73));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 11);
    ASSERT_TRUE(tree.totalTreeValue() == 374);

    ASSERT_TRUE(tree.insert(27));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 12);
    ASSERT_TRUE(tree.totalTreeValue() == 401);

    ASSERT_TRUE(tree.insert(25));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 13);
    ASSERT_TRUE(tree.totalTreeValue() == 426);

    ASSERT_TRUE(tree.insert(17));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 14);
    ASSERT_TRUE(tree.totalTreeValue() == 443);

    //71, 21, 24, 49, 4, 6, 29, 44, 34, 19, 73, 27, 25, 17, 57, 96, 64, 70, 98, 54
    
    ASSERT_TRUE(tree.insert(57));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 15);
    ASSERT_TRUE(tree.totalTreeValue() == 500);

    ASSERT_TRUE(tree.insert(96));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 16);
    ASSERT_TRUE(tree.totalTreeValue() == 596);

    ASSERT_TRUE(tree.insert(64));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 17);
    ASSERT_TRUE(tree.totalTreeValue() == 660);

    ASSERT_TRUE(tree.insert(70));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 18);
    ASSERT_TRUE(tree.totalTreeValue() == 730);

    ASSERT_TRUE(tree.insert(98));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 19);
    ASSERT_TRUE(tree.totalTreeValue() == 828);

    ASSERT_TRUE(tree.insert(54));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 20);
    ASSERT_TRUE(tree.totalTreeValue() == 882);

}

void testBestNSplayTree() {
    SplayTree tree;

    //71, 21, 24, 49, 4, 6, 29, 44, 34, 19, 73, 27, 25, 17, 57, 96, 64, 70, 98, 54

    ASSERT_TRUE(tree.insert(71));
    ASSERT_TRUE(tree.insert(21));
    ASSERT_TRUE(tree.insert(24));
    ASSERT_TRUE(tree.insert(49));
    ASSERT_TRUE(tree.insert(4));
    ASSERT_TRUE(tree.insert(6));
    ASSERT_TRUE(tree.insert(29));
    ASSERT_TRUE(tree.insert(44));
    ASSERT_TRUE(tree.insert(34));
    ASSERT_TRUE(tree.insert(19));
    ASSERT_TRUE(tree.insert(73));
    ASSERT_TRUE(tree.insert(27));
    ASSERT_TRUE(tree.insert(25));
    ASSERT_TRUE(tree.insert(17));
    ASSERT_TRUE(tree.insert(57));
    ASSERT_TRUE(tree.insert(96));
    ASSERT_TRUE(tree.insert(64));
    ASSERT_TRUE(tree.insert(70));
    ASSERT_TRUE(tree.insert(98));
    ASSERT_TRUE(tree.insert(54));

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
//
//
//void testInsertWithDuplicatesSplayTree() {
//    SplayTree tree;
//
//    //7  1  9 12  1  5  7  1  3 10  5  2
//
//    int* n01 = new int(7);
//    int* n02 = new int(1);
//    int* n03 = new int(9);
//    int* n04 = new int(12);
//    int* n05 = new int(1);
//    int* n06 = new int(5);
//    int* n07 = new int(7);
//    int* n08 = new int(1);
//    int* n09 = new int(3);
//    int* n10 = new int(10);
//    int* n11 = new int(5);
//    int* n12 = new int(2);
//
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 0);
//    ASSERT_TRUE(tree.totalTreeValue() == -1);
//
//    ASSERT_TRUE(tree.insert(n01)); //7
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 1);
//    ASSERT_TRUE(tree.totalTreeValue() == 7);
//
//    ASSERT_TRUE(tree.insert(n02)); //1
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 2);
//    ASSERT_TRUE(tree.totalTreeValue() == 8);
//
//    ASSERT_TRUE(tree.insert(n03)); //9
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 3);
//    ASSERT_TRUE(tree.totalTreeValue() == 17);
//
//    ASSERT_TRUE(tree.insert(n04)); //12
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 4);
//    ASSERT_TRUE(tree.totalTreeValue() == 29);
//
//    ASSERT_TRUE(tree.insert(n05)); //1
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 5);
//    ASSERT_TRUE(tree.totalTreeValue() == 30);
//
//    //std::stringstream out1;
//    //tree.print(out1);
//    //cout<<out1.str();
//
//    ASSERT_TRUE(tree.insert(n06)); //5
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 6);
//    ASSERT_TRUE(tree.totalTreeValue() == 35);
//
//    ASSERT_TRUE(tree.insert(n07)); //7
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 7);
//    ASSERT_TRUE(tree.totalTreeValue() == 42);
//
//    ASSERT_TRUE(tree.insert(n08)); //1
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 8);
//    ASSERT_TRUE(tree.totalTreeValue() == 43);
//
//    ASSERT_TRUE(tree.insert(n09)); //3
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 9);
//    ASSERT_TRUE(tree.totalTreeValue() == 46);
//    
//    ASSERT_TRUE(tree.insert(n10)); //10
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 10);
//    ASSERT_TRUE(tree.totalTreeValue() == 56);
//
//    ASSERT_TRUE(tree.insert(n11)); //5
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 11);
//    ASSERT_TRUE(tree.totalTreeValue() == 61);
//
//    ASSERT_TRUE(tree.insert(n12));
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 12);
//    ASSERT_TRUE(tree.totalTreeValue() == 63);
//
//    //7  1  9 12  1  5  7  1  3 10  5  2
//
//    ASSERT_TRUE(tree.sumOfBestN(1) == 12);
//    ASSERT_TRUE(tree.sumOfBestN(2) == 22);
//    ASSERT_TRUE(tree.sumOfBestN(3) == 31);
//    cout<<"\n";
//    cout<<tree.sumOfBestN(4);
//    cout<<"\n";
//    ASSERT_TRUE(tree.sumOfBestN(4) == 38);
//
//    ASSERT_TRUE(tree.sumOfBestN(5) == 45);
//    ASSERT_TRUE(tree.sumOfBestN(6) == 50);
//    ASSERT_TRUE(tree.sumOfBestN(7) == 55);
//    ASSERT_TRUE(tree.sumOfBestN(8) == 58);
//    ASSERT_TRUE(tree.sumOfBestN(9) == 60);
//    ASSERT_TRUE(tree.sumOfBestN(10) == 61);
//    ASSERT_TRUE(tree.sumOfBestN(11) == 62);
//    ASSERT_TRUE(tree.sumOfBestN(12) == 63);
//    ASSERT_TRUE(tree.sumOfBestN(13) == -1);
//}
//
//void testInsertWithDuplicatesSplayTree2() {
//    SplayTree tree;
//
//    //2  6 12  8 12 12  6  4  9  5  5  1  2  4  4
//
//    int* n01 = new int(2);
//    int* n02 = new int(6);
//    int* n03 = new int(12);
//    int* n04 = new int(8);
//    int* n05 = new int(12);
//    int* n06 = new int(12);
//    int* n07 = new int(6);
//    int* n08 = new int(4);
//    int* n09 = new int(9);
//    int* n10 = new int(5);
//    int* n11 = new int(5);
//    int* n12 = new int(1);
//    int* n13 = new int(2);
//    int* n14 = new int(4);
//    int* n15 = new int(4);
//
//
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 0);
//    ASSERT_TRUE(tree.totalTreeValue() == -1);
//
//    //2  6 12  8 12 12  6  4  9  5  5  1  2  4  4
//
//
//    ASSERT_TRUE(tree.insert(n01));
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 1);
//    ASSERT_TRUE(tree.totalTreeValue() == 2);
//
//    ASSERT_TRUE(tree.insert(n02));
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 2);
//    ASSERT_TRUE(tree.totalTreeValue() == 8);
//
//    ASSERT_TRUE(tree.insert(n03));
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 3);
//    ASSERT_TRUE(tree.totalTreeValue() == 20);
//
//    ASSERT_TRUE(tree.insert(n04));
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 4);
//    ASSERT_TRUE(tree.totalTreeValue() == 28);
//
//    ASSERT_TRUE(tree.insert(n05));
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 5);
//    ASSERT_TRUE(tree.totalTreeValue() == 40);
//
//    //std::stringstream out1;
//    //tree.print(out1);
//    //cout<<out1.str();
//
//    //2  6 12  8 12 12  6  4  9  5  5  1  2  4  4
//
//
//    ASSERT_TRUE(tree.insert(n06));
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 6);
//    ASSERT_TRUE(tree.totalTreeValue() == 52);
//
//    std::stringstream out1;
//    tree.print(out1);
//    cout<<out1.str();
//
//    ASSERT_TRUE(tree.insert(n07));
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 7);
//    ASSERT_TRUE(tree.totalTreeValue() == 58);
//
//    ASSERT_TRUE(tree.insert(n08));
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 8);
//    ASSERT_TRUE(tree.totalTreeValue() == 62);
//
//    ASSERT_TRUE(tree.insert(n09));
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 9);
//    ASSERT_TRUE(tree.totalTreeValue() == 71);
//
//
//
//    ASSERT_TRUE(tree.insert(n10));
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 10);
//    ASSERT_TRUE(tree.totalTreeValue() == 76);
//
//    ASSERT_TRUE(tree.insert(n11));
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 11);
//    ASSERT_TRUE(tree.totalTreeValue() == 81);
//
//    ASSERT_TRUE(tree.insert(n12));
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 12);
//    ASSERT_TRUE(tree.totalTreeValue() == 82);
//
//    ASSERT_TRUE(tree.insert(n13));
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 13);
//    ASSERT_TRUE(tree.totalTreeValue() == 84);
//
//    ASSERT_TRUE(tree.insert(n14));
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 14);
//    ASSERT_TRUE(tree.totalTreeValue() == 88);
//
//    ASSERT_TRUE(tree.insert(n15));
//    ASSERT_TRUE(tree.totalNumberOfNodes() == 15);
//    ASSERT_TRUE(tree.totalTreeValue() == 92);
//
//
//
//    //2  6 12  8 12 12  6  4  9  5  5  1  2  4  4
//
//    ASSERT_TRUE(tree.sumOfBestN(1) == 12);
//    ASSERT_TRUE(tree.sumOfBestN(2) == 24);
//    ASSERT_TRUE(tree.sumOfBestN(3) == 36);
//    ASSERT_TRUE(tree.sumOfBestN(4) == 45);
//    ASSERT_TRUE(tree.sumOfBestN(5) == 53);
//    ASSERT_TRUE(tree.sumOfBestN(6) == 59);
//    ASSERT_TRUE(tree.sumOfBestN(7) == 65);
//    ASSERT_TRUE(tree.sumOfBestN(8) == 70);
//    ASSERT_TRUE(tree.sumOfBestN(9) == 75);
//    ASSERT_TRUE(tree.sumOfBestN(10) == 79);
//    ASSERT_TRUE(tree.sumOfBestN(11) == 83);
//    ASSERT_TRUE(tree.sumOfBestN(12) == 87);
//    ASSERT_TRUE(tree.sumOfBestN(13) == 89);
//    ASSERT_TRUE(tree.sumOfBestN(14) == 91);
//    ASSERT_TRUE(tree.sumOfBestN(15) == 92);
//    ASSERT_TRUE(tree.sumOfBestN(16) == -1);
//}


int main() {
    cout << "-------MIN HEAP TESTS-----------" << endl;
    RUN_TEST(testMakeSplayTree);
    RUN_TEST(testInsertSplayTree);
    RUN_TEST(testBestNSplayTree);
    //RUN_TEST(testInsertWithDuplicatesSplayTree);
    //RUN_TEST(testInsertWithDuplicatesSplayTree2);


    return 0;
}



