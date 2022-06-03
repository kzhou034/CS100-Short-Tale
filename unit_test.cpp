#ifndef __UNIT_TEST_CPP__
#define __UNIT_TEST_CPP__
#include "gtest/gtest.h"

#include "Inventory.hpp"
#include "Character.hpp"
#include "knight_tests.cpp"
#include "inventory_tests.cpp"

int main(int argc, char **argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}

#endif
