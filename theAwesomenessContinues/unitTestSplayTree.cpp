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


void testInsertWithDuplicatesSplayTree() {
    SplayTree tree;

    //7  1  9 12  1  5  7  1  3 10  5  2

    ASSERT_TRUE(tree.totalNumberOfNodes() == 0);
    ASSERT_TRUE(tree.totalTreeValue() == -1);

    ASSERT_TRUE(tree.insert(7)); //7
    ASSERT_TRUE(tree.totalNumberOfNodes() == 1);
    ASSERT_TRUE(tree.totalTreeValue() == 7);

    ASSERT_TRUE(tree.insert(1)); //1
    ASSERT_TRUE(tree.totalNumberOfNodes() == 2);
    ASSERT_TRUE(tree.totalTreeValue() == 8);

    ASSERT_TRUE(tree.insert(9)); //9
    ASSERT_TRUE(tree.totalNumberOfNodes() == 3);
    ASSERT_TRUE(tree.totalTreeValue() == 17);

    ASSERT_TRUE(tree.insert(12)); //12
    ASSERT_TRUE(tree.totalNumberOfNodes() == 4);
    ASSERT_TRUE(tree.totalTreeValue() == 29);

    ASSERT_TRUE(tree.insert(1)); //1
    ASSERT_TRUE(tree.totalNumberOfNodes() == 5);
    ASSERT_TRUE(tree.totalTreeValue() == 30);

    //std::stringstream out1;
    //tree.print(out1);
    //cout<<out1.str();

    ASSERT_TRUE(tree.insert(5)); //5
    ASSERT_TRUE(tree.totalNumberOfNodes() == 6);
    ASSERT_TRUE(tree.totalTreeValue() == 35);

    ASSERT_TRUE(tree.insert(7)); //7
    ASSERT_TRUE(tree.totalNumberOfNodes() == 7);
    ASSERT_TRUE(tree.totalTreeValue() == 42);

    ASSERT_TRUE(tree.insert(1)); //1
    ASSERT_TRUE(tree.totalNumberOfNodes() == 8);
    ASSERT_TRUE(tree.totalTreeValue() == 43);

    ASSERT_TRUE(tree.insert(3)); //3
    ASSERT_TRUE(tree.totalNumberOfNodes() == 9);
    ASSERT_TRUE(tree.totalTreeValue() == 46);
    
    ASSERT_TRUE(tree.insert(10)); //10
    ASSERT_TRUE(tree.totalNumberOfNodes() == 10);
    ASSERT_TRUE(tree.totalTreeValue() == 56);

    ASSERT_TRUE(tree.insert(5)); //5
    ASSERT_TRUE(tree.totalNumberOfNodes() == 11);
    ASSERT_TRUE(tree.totalTreeValue() == 61);

    ASSERT_TRUE(tree.insert(2));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 12);
    ASSERT_TRUE(tree.totalTreeValue() == 63);

    //7  1  9 12  1  5  7  1  3 10  5  2

    ASSERT_TRUE(tree.sumOfBestN(1) == 12); //12
    ASSERT_TRUE(tree.sumOfBestN(2) == 22); //10
    ASSERT_TRUE(tree.sumOfBestN(3) == 31); //9
//    cout<<"\n";
//    cout<<tree.sumOfBestN(4);
//    cout<<"\n";
    ASSERT_TRUE(tree.sumOfBestN(4) == 38); //7

    ASSERT_TRUE(tree.sumOfBestN(5) == 45);
    ASSERT_TRUE(tree.sumOfBestN(6) == 50);
    ASSERT_TRUE(tree.sumOfBestN(7) == 55);
    ASSERT_TRUE(tree.sumOfBestN(8) == 58);
    ASSERT_TRUE(tree.sumOfBestN(9) == 60);
    ASSERT_TRUE(tree.sumOfBestN(10) == 61);
    ASSERT_TRUE(tree.sumOfBestN(11) == 62);
    ASSERT_TRUE(tree.sumOfBestN(12) == 63);
    ASSERT_TRUE(tree.sumOfBestN(13) == -1);
}

void testInsertWithDuplicatesSplayTree2() {
    SplayTree tree;

    //2  6 12  8 12 12  6  4  9  5  5  1  2  4  4


    ASSERT_TRUE(tree.totalNumberOfNodes() == 0);
    ASSERT_TRUE(tree.totalTreeValue() == -1);

    //2  6 12  8 12 12  6  4  9  5  5  1  2  4  4


    ASSERT_TRUE(tree.insert(2));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 1);
    ASSERT_TRUE(tree.totalTreeValue() == 2);

    ASSERT_TRUE(tree.insert(6));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 2);
    ASSERT_TRUE(tree.totalTreeValue() == 8);

    ASSERT_TRUE(tree.insert(12));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 3);
    ASSERT_TRUE(tree.totalTreeValue() == 20);

    ASSERT_TRUE(tree.insert(8));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 4);
    ASSERT_TRUE(tree.totalTreeValue() == 28);

    ASSERT_TRUE(tree.insert(12));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 5);
    ASSERT_TRUE(tree.totalTreeValue() == 40);

    //std::stringstream out1;
    //tree.print(out1);
    //cout<<out1.str();

    //2  6 12  8 12 12  6  4  9  5  5  1  2  4  4


    ASSERT_TRUE(tree.insert(12));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 6);
    ASSERT_TRUE(tree.totalTreeValue() == 52);

//    std::stringstream out1;
//    tree.print(out1);
//    cout<<out1.str();

    ASSERT_TRUE(tree.insert(6));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 7);
    ASSERT_TRUE(tree.totalTreeValue() == 58);

    ASSERT_TRUE(tree.insert(4));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 8);
    ASSERT_TRUE(tree.totalTreeValue() == 62);

    ASSERT_TRUE(tree.insert(9));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 9);
    ASSERT_TRUE(tree.totalTreeValue() == 71);

    ASSERT_TRUE(tree.insert(5));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 10);
    ASSERT_TRUE(tree.totalTreeValue() == 76);

    ASSERT_TRUE(tree.insert(5));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 11);
    ASSERT_TRUE(tree.totalTreeValue() == 81);

    ASSERT_TRUE(tree.insert(1));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 12);
    ASSERT_TRUE(tree.totalTreeValue() == 82);

    ASSERT_TRUE(tree.insert(2));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 13);
    ASSERT_TRUE(tree.totalTreeValue() == 84);

    ASSERT_TRUE(tree.insert(4));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 14);
    ASSERT_TRUE(tree.totalTreeValue() == 88);

    ASSERT_TRUE(tree.insert(4));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 15);
    ASSERT_TRUE(tree.totalTreeValue() == 92);

    //2  6 12  8 12 12  6  4  9  5  5  1  2  4  4

    ASSERT_TRUE(tree.sumOfBestN(1) == 12);
    ASSERT_TRUE(tree.sumOfBestN(2) == 24);
    ASSERT_TRUE(tree.sumOfBestN(3) == 36);
    ASSERT_TRUE(tree.sumOfBestN(4) == 45);
    ASSERT_TRUE(tree.sumOfBestN(5) == 53);
    ASSERT_TRUE(tree.sumOfBestN(6) == 59);
    ASSERT_TRUE(tree.sumOfBestN(7) == 65);
    ASSERT_TRUE(tree.sumOfBestN(8) == 70);
    ASSERT_TRUE(tree.sumOfBestN(9) == 75);
    ASSERT_TRUE(tree.sumOfBestN(10) == 79);
    ASSERT_TRUE(tree.sumOfBestN(11) == 83);
    ASSERT_TRUE(tree.sumOfBestN(12) == 87);
    ASSERT_TRUE(tree.sumOfBestN(13) == 89);
    ASSERT_TRUE(tree.sumOfBestN(14) == 91);
    ASSERT_TRUE(tree.sumOfBestN(15) == 92);
    ASSERT_TRUE(tree.sumOfBestN(16) == -1);
}

void testInsertWithDuplicatesSplayTree3() {
    SplayTree tree;
    
    //3  9  1  5 10  5 14 13 10  1 15  9 11  1  1 13  3 14 13 10 12 10  4  2  6 9 10 11  2  5  6  3 15 12 12  5  7  5  1 15 11  4  7  8 12
    
    
    ASSERT_TRUE(tree.totalNumberOfNodes() == 0);
    ASSERT_TRUE(tree.totalTreeValue() == -1);
    
    ASSERT_TRUE(tree.insert(3));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 1);
    ASSERT_TRUE(tree.totalTreeValue() == 3);
    
    ASSERT_TRUE(tree.insert(9));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 2);
    ASSERT_TRUE(tree.totalTreeValue() == 12);
    
    ASSERT_TRUE(tree.insert(1));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 3);
    ASSERT_TRUE(tree.totalTreeValue() == 13);
    
    ASSERT_TRUE(tree.insert(5));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 4);
    ASSERT_TRUE(tree.totalTreeValue() == 18);
    //3  9  1  5 10  5 14 13 10  1 15  9 11  1  1 13  3 14 13 10 12 10  4  2  6 9 10 11  2  5  6  3 15 12 12  5  7  5  1 15 11  4  7  8 12

    ASSERT_TRUE(tree.insert(10));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 5);
    ASSERT_TRUE(tree.totalTreeValue() == 28);
    
    //std::stringstream out1;
    //tree.print(out1);
    //cout<<out1.str();
    
    ASSERT_TRUE(tree.insert(5));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 6);
    ASSERT_TRUE(tree.totalTreeValue() == 33);
    
    ASSERT_TRUE(tree.insert(14));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 7);
    ASSERT_TRUE(tree.totalTreeValue() == 47);
    
    ASSERT_TRUE(tree.insert(13));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 8);
    ASSERT_TRUE(tree.totalTreeValue() == 60);
    
    ASSERT_TRUE(tree.insert(10));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 9);
    ASSERT_TRUE(tree.totalTreeValue() == 70);
    
    ASSERT_TRUE(tree.insert(1));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 10);
    ASSERT_TRUE(tree.totalTreeValue() == 71);
    
    ASSERT_TRUE(tree.insert(15));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 11);
    ASSERT_TRUE(tree.totalTreeValue() == 86);

    ASSERT_TRUE(tree.insert(9));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 12);
    ASSERT_TRUE(tree.totalTreeValue() == 95);
    //3  9  1  5 10  5 14 13 10  1 15  9 11  1  1 13  3 14 13 10 12 10  4  2  6 9 10 11  2  5  6  3 15 12 12  5  7  5  1 15 11  4  7  8 12

    ASSERT_TRUE(tree.insert(11));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 13);
    ASSERT_TRUE(tree.totalTreeValue() == 106);
    
    ASSERT_TRUE(tree.insert(1));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 14);
    ASSERT_TRUE(tree.totalTreeValue() == 107);
    
    ASSERT_TRUE(tree.insert(1));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 15);
    ASSERT_TRUE(tree.totalTreeValue() == 108);
    
    
    //////////////////////////////////////////
    
    ASSERT_TRUE(tree.insert(13));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 16);
    ASSERT_TRUE(tree.totalTreeValue() == 121);
    
    ASSERT_TRUE(tree.insert(3));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 17);
    ASSERT_TRUE(tree.totalTreeValue() == 124);
    
    ASSERT_TRUE(tree.insert(14));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 18);
    ASSERT_TRUE(tree.totalTreeValue() == 138);
    
    ASSERT_TRUE(tree.insert(13));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 19);
    ASSERT_TRUE(tree.totalTreeValue() == 151);
    //3  9  1  5 10  5 14 13 10  1 15  9 11  1  1 13  3 14 13 10 12 10  4  2  6 9 10 11  2  5  6  3 15 12 12  5  7  5  1 15 11  4  7  8 12
    
    ASSERT_TRUE(tree.insert(10));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 20);
    ASSERT_TRUE(tree.totalTreeValue() == 161);
    
    ASSERT_TRUE(tree.insert(12));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 21);
    ASSERT_TRUE(tree.totalTreeValue() == 173);
    
    ASSERT_TRUE(tree.insert(10));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 22);
    ASSERT_TRUE(tree.totalTreeValue() == 183);
    
    ASSERT_TRUE(tree.insert(4));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 23);
    ASSERT_TRUE(tree.totalTreeValue() == 187);
    
    ASSERT_TRUE(tree.insert(2));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 24);
    ASSERT_TRUE(tree.totalTreeValue() == 189);
    
    ASSERT_TRUE(tree.insert(6));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 25);
    ASSERT_TRUE(tree.totalTreeValue() == 195);
    
    ASSERT_TRUE(tree.insert(9));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 26);
    ASSERT_TRUE(tree.totalTreeValue() == 204);
    
    ASSERT_TRUE(tree.insert(10));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 27);
    ASSERT_TRUE(tree.totalTreeValue() == 214);
    //3  9  1  5 10  5 14 13 10  1 15  9 11  1  1 13  3 14 13 10 12 10  4  2  6 9 10 11  2  5  6  3 15 12 12  5  7  5  1 15 11  4  7  8 12
    
    ASSERT_TRUE(tree.insert(11));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 28);
    ASSERT_TRUE(tree.totalTreeValue() == 225);
    
    ASSERT_TRUE(tree.insert(2));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 29);
    ASSERT_TRUE(tree.totalTreeValue() == 227);
    
    ASSERT_TRUE(tree.insert(5));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 30);
    ASSERT_TRUE(tree.totalTreeValue() == 232);
    
    
    //////////////////////////////////////////////////
    
    ASSERT_TRUE(tree.insert(6));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 31);
    ASSERT_TRUE(tree.totalTreeValue() == 238);
    
    ASSERT_TRUE(tree.insert(3));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 32);
    ASSERT_TRUE(tree.totalTreeValue() == 241);
    
    ASSERT_TRUE(tree.insert(15));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 33);
    ASSERT_TRUE(tree.totalTreeValue() == 256);
    
    ASSERT_TRUE(tree.insert(12));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 34);
    ASSERT_TRUE(tree.totalTreeValue() == 268);
    //3  9  1  5 10  5 14 13 10  1 15  9 11  1  1 13  3 14 13 10 12 10  4  2  6 9 10 11  2  5  6  3 15 12 12  5  7  5  1 15 11  4  7  8 12
    
    ASSERT_TRUE(tree.insert(12));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 35);
    ASSERT_TRUE(tree.totalTreeValue() == 280);
    
    //std::stringstream out1;
    //tree.print(out1);
    //cout<<out1.str();
    
    ASSERT_TRUE(tree.insert(5));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 36);
    ASSERT_TRUE(tree.totalTreeValue() == 285);
    
    ASSERT_TRUE(tree.insert(7));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 37);
    ASSERT_TRUE(tree.totalTreeValue() == 292);
    
    ASSERT_TRUE(tree.insert(7));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 38);
    ASSERT_TRUE(tree.totalTreeValue() == 299);
    
    ASSERT_TRUE(tree.insert(1));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 39);
    ASSERT_TRUE(tree.totalTreeValue() == 300);
    
    ASSERT_TRUE(tree.insert(15));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 40);
    ASSERT_TRUE(tree.totalTreeValue() == 315);
    
    ASSERT_TRUE(tree.insert(11));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 41);
    ASSERT_TRUE(tree.totalTreeValue() == 326);
    
    ASSERT_TRUE(tree.insert(4));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 42);
    ASSERT_TRUE(tree.totalTreeValue() == 330);
    //3  9  1  5 10  5 14 13 10  1 15  9 11  1  1 13  3 14 13 10 12 10  4  2  6 9 10 11  2  5  6  3 15 12 12  5  7  5  1 15 11  4  7  8 12
    
    ASSERT_TRUE(tree.insert(7));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 43);
    ASSERT_TRUE(tree.totalTreeValue() == 337);
    
    ASSERT_TRUE(tree.insert(8));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 44);
    ASSERT_TRUE(tree.totalTreeValue() == 345);
    
    ASSERT_TRUE(tree.insert(12));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 45);
    ASSERT_TRUE(tree.totalTreeValue() == 357);
    
    //15 15 15 14 14 13 13 13 12 12 12 12 11 11 11 10 10 10 10 10 9 9 9 8 7 7 6 6 5 5 5 5 4 4 3 3 3 2 2 1  1  1  1   1

    ASSERT_TRUE(tree.sumOfBestN(1) == 15);
    ASSERT_TRUE(tree.sumOfBestN(2) == 30);
    ASSERT_TRUE(tree.sumOfBestN(3) == 45);
    ASSERT_TRUE(tree.sumOfBestN(4) == 59);
    ASSERT_TRUE(tree.sumOfBestN(5) == 73);
    ASSERT_TRUE(tree.sumOfBestN(6) == 86);
    ASSERT_TRUE(tree.sumOfBestN(7) == 99);
    ASSERT_TRUE(tree.sumOfBestN(8) == 112);
    ASSERT_TRUE(tree.sumOfBestN(9) == 124);
    ASSERT_TRUE(tree.sumOfBestN(10) == 136);
    ASSERT_TRUE(tree.sumOfBestN(11) == 148);
    ASSERT_TRUE(tree.sumOfBestN(12) == 160);
    ASSERT_TRUE(tree.sumOfBestN(13) == 171);
    ASSERT_TRUE(tree.sumOfBestN(14) == 182);
    ASSERT_TRUE(tree.sumOfBestN(15) == 193);
    
    ASSERT_TRUE(tree.sumOfBestN(16) == 203);
    ASSERT_TRUE(tree.sumOfBestN(17) == 213);
    ASSERT_TRUE(tree.sumOfBestN(18) == 223);
    ASSERT_TRUE(tree.sumOfBestN(19) == 233);
    ASSERT_TRUE(tree.sumOfBestN(20) == 243);
    ASSERT_TRUE(tree.sumOfBestN(21) == 252);
    ASSERT_TRUE(tree.sumOfBestN(22) == 261);
    ASSERT_TRUE(tree.sumOfBestN(23) == 270);
    ASSERT_TRUE(tree.sumOfBestN(24) == 278);
    ASSERT_TRUE(tree.sumOfBestN(25) == 285);
    ASSERT_TRUE(tree.sumOfBestN(26) == 292);
    ASSERT_TRUE(tree.sumOfBestN(27) == 299);
    ASSERT_TRUE(tree.sumOfBestN(28) == 305);
    ASSERT_TRUE(tree.sumOfBestN(29) == 311); //6
    ASSERT_TRUE(tree.sumOfBestN(30) == 316); //5
    
    //15 15 15 14 14 13 13 13 12 12 12 12 11 11 11 10 10 10 10 10 9 9 9 8 7 7 6 6 5 5 5 5 5 4 4 3 3 3 2 2 1  1  1  1   1

    ASSERT_TRUE(tree.sumOfBestN(31) == 321); //5
    ASSERT_TRUE(tree.sumOfBestN(32) == 326); //5
    ASSERT_TRUE(tree.sumOfBestN(33) == 331); //5
    ASSERT_TRUE(tree.sumOfBestN(34) == 335); //4
    ASSERT_TRUE(tree.sumOfBestN(35) == 339); //4
    ASSERT_TRUE(tree.sumOfBestN(36) == 342); //3
    ASSERT_TRUE(tree.sumOfBestN(37) == 345); //3
    ASSERT_TRUE(tree.sumOfBestN(38) == 348); //3
    ASSERT_TRUE(tree.sumOfBestN(39) == 350); //2
    ASSERT_TRUE(tree.sumOfBestN(40) == 352); //2
    ASSERT_TRUE(tree.sumOfBestN(41) == 353); //1
    ASSERT_TRUE(tree.sumOfBestN(42) == 354); //1
    ASSERT_TRUE(tree.sumOfBestN(43) == 355); //1
    ASSERT_TRUE(tree.sumOfBestN(44) == 356); //1
    ASSERT_TRUE(tree.sumOfBestN(45) == 357); //1
    ASSERT_TRUE(tree.sumOfBestN(46) == -1);
}


void testInsertWithDuplicatesSplayTree4() {
    SplayTree tree;
    ASSERT_TRUE(tree.insert(10));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 1);
    ASSERT_TRUE(tree.totalTreeValue() == 10);

    ASSERT_TRUE(tree.insert(10));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 2);
    ASSERT_TRUE(tree.totalTreeValue() == 20);

    ASSERT_TRUE(tree.insert(10));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 3);
    ASSERT_TRUE(tree.totalTreeValue() == 30);

    ASSERT_TRUE(tree.insert(10));
    ASSERT_TRUE(tree.totalNumberOfNodes() == 4);
    ASSERT_TRUE(tree.totalTreeValue() == 40);

    ASSERT_TRUE(tree.sumOfBestN(1) == 10);
    ASSERT_TRUE(tree.sumOfBestN(2) == 20);
    ASSERT_TRUE(tree.sumOfBestN(3) == 30);
    ASSERT_TRUE(tree.sumOfBestN(4) == 40);

    
}


int main() {
    cout << "-------MIN HEAP TESTS-----------" << endl;
    RUN_TEST(testMakeSplayTree);
    RUN_TEST(testInsertSplayTree);
    RUN_TEST(testBestNSplayTree);
    RUN_TEST(testInsertWithDuplicatesSplayTree);
    RUN_TEST(testInsertWithDuplicatesSplayTree2);
    RUN_TEST(testInsertWithDuplicatesSplayTree3);
    RUN_TEST(testInsertWithDuplicatesSplayTree4);


    return 0;
}



