#include "tritset.h"
#include <gtest/gtest.h>

using namespace std;
using namespace tritspace;

///////////////
// functions //
///////////////

bool extendToCapacityTestHelper(size_t test_val) {
    size_t tmp      = extendToCapacity(test_val);
    return (tmp >= test_val)               &&
           (tmp % (sizeof(uint) * 4) == 0) &&
           (tmp <= test_val + (sizeof(uint) * 4));    
}
TEST(extendToCapacityTest, Positive) {
    EXPECT_TRUE(extendToCapacityTestHelper(1));
    EXPECT_TRUE(extendToCapacityTestHelper(12));
    EXPECT_TRUE(extendToCapacityTestHelper(123));
    EXPECT_TRUE(extendToCapacityTestHelper(1234));
    EXPECT_TRUE(extendToCapacityTestHelper(12345));
    EXPECT_TRUE(extendToCapacityTestHelper(123456));
    EXPECT_TRUE(extendToCapacityTestHelper(1234567));
    EXPECT_TRUE(extendToCapacityTestHelper(12345678));
    EXPECT_TRUE(extendToCapacityTestHelper(123456789));
    EXPECT_TRUE(extendToCapacityTestHelper(1234567890));
}

TEST(extendToCapacityTest, Zero) {
    EXPECT_EQ(0, extendToCapacity(0));
}

TEST(unknown_uintTest, general) {
    EXPECT_EQ(0, unknown_uint());
}

//////////
// Trit //
//////////

TEST(TritTest, initByInt) {
    ASSERT_EQ(_False,   Trit(-123456789).state());
    ASSERT_EQ(_False,   Trit(-1).state());
    ASSERT_EQ(_Unknown, Trit(0).state());
    ASSERT_EQ(_True,    Trit(1).state());
    ASSERT_EQ(_True,   Trit(123456789).state());
}

TEST(TritTest, initByTritenum) {
    ASSERT_EQ(_Unknown, Trit(_Unknown).state());
    ASSERT_EQ(_False,   Trit(_False).state());
    ASSERT_EQ(_True,    Trit(_True).state());
}

TEST(TritTest, CopyConstructor) {
    ASSERT_EQ(_Unknown, Trit(Unknown).state());
    ASSERT_EQ(_False,   Trit(False).state());
    ASSERT_EQ(_True,    Trit(True).state());
}

TEST(TritTest, initEmpty) {
    ASSERT_EQ(_Unknown, Trit().state());
    Trit tmp;
    ASSERT_EQ(_Unknown, tmp.state());
}

TEST(TritTest, operatorTritenum) {
    ASSERT_EQ(False.state(), Tritenum(False));
    ASSERT_EQ(Unknown.state(), Tritenum(Unknown));
    ASSERT_EQ(True.state(), Tritenum(True));
}

TEST(TritTest, operatorEqOther) {
    ASSERT_EQ(true,     True    == True);
    ASSERT_EQ(false,    True    == Unknown);
    ASSERT_EQ(false,    True    == False);
    ASSERT_EQ(false,    Unknown == True);
    ASSERT_EQ(true,     Unknown == Unknown);
    ASSERT_EQ(false,    Unknown == False);
    ASSERT_EQ(false,    False   == True);
    ASSERT_EQ(false,    False   == Unknown);
    ASSERT_EQ(true,     False   == False);
}

TEST(TritTest, operatorAssignTritenum) {
    Trit tmp;
    ASSERT_EQ(False,    tmp = _False);
    ASSERT_EQ(Unknown,  tmp = _Unknown);
    ASSERT_EQ(True,     tmp = _True);
}

TEST(TritTest, operatorAssignTrit) {
    Trit tmp;
    ASSERT_EQ(False,    tmp = False);
    ASSERT_EQ(Unknown,  tmp = Unknown);
    ASSERT_EQ(True,     tmp = True);
}

TEST(TritTest, operatorAND) {
    EXPECT_EQ(True,     True    & True);
    EXPECT_EQ(Unknown,  True    & Unknown);
    EXPECT_EQ(False,    True    & False);
    EXPECT_EQ(Unknown,  Unknown & True);
    EXPECT_EQ(Unknown,  Unknown & Unknown);
    EXPECT_EQ(False,    Unknown & False);
    EXPECT_EQ(False,    False   & True);
    EXPECT_EQ(False,    False   & Unknown);
    EXPECT_EQ(False,    False   & False);
}

TEST(TritTest, operatorOR) {
    EXPECT_EQ(True,     True    | True);
    EXPECT_EQ(True,     True    | Unknown);
    EXPECT_EQ(True,     True    | False);
    EXPECT_EQ(True,     Unknown | True);
    EXPECT_EQ(Unknown,  Unknown | Unknown);
    EXPECT_EQ(Unknown,  Unknown | False);
    EXPECT_EQ(True,     False   | True);
    EXPECT_EQ(Unknown,  False   | Unknown);
    EXPECT_EQ(False,    False   | False);
}

TEST(TritTest, operatorXOR) {
    EXPECT_EQ(Unknown,  True    ^ True);
    EXPECT_EQ(False,    True    ^ Unknown);
    EXPECT_EQ(True,     True    ^ False);
    EXPECT_EQ(False,    Unknown ^ True);
    EXPECT_EQ(True,     Unknown ^ Unknown);
    EXPECT_EQ(Unknown,  Unknown ^ False);
    EXPECT_EQ(True,     False   ^ True);
    EXPECT_EQ(Unknown,  False   ^ Unknown);
    EXPECT_EQ(False,    False   ^ False);
}

TEST(TritTest, operatorNOT) {
    EXPECT_EQ(False,    ~True);
    EXPECT_EQ(Unknown,  ~Unknown);
    EXPECT_EQ(True,     ~False);   
}

TEST(TritTest, operatorAssignAND) {
    Trit tmp;
    EXPECT_EQ(True,     tmp = True    & True);
    EXPECT_EQ(Unknown,  tmp = True    & Unknown);
    EXPECT_EQ(False,    tmp = True    & False);
    EXPECT_EQ(Unknown,  tmp = Unknown & True);
    EXPECT_EQ(Unknown,  tmp = Unknown & Unknown);
    EXPECT_EQ(False,    tmp = Unknown & False);
    EXPECT_EQ(False,    tmp = False   & True);
    EXPECT_EQ(False,    tmp = False   & Unknown);
    EXPECT_EQ(False,    tmp = False   & False);
}

TEST(TritTest, operatorAssignOR) {
    Trit tmp;
    EXPECT_EQ(True,     tmp = True    | True);
    EXPECT_EQ(True,     tmp = True    | Unknown);
    EXPECT_EQ(True,     tmp = True    | False);
    EXPECT_EQ(True,     tmp = Unknown | True);
    EXPECT_EQ(Unknown,  tmp = Unknown | Unknown);
    EXPECT_EQ(Unknown,  tmp = Unknown | False);
    EXPECT_EQ(True,     tmp = False   | True);
    EXPECT_EQ(Unknown,  tmp = False   | Unknown);
    EXPECT_EQ(False,    tmp = False   | False);
}

TEST(TritTest, operatorAssignXOR) {
    Trit tmp;
    EXPECT_EQ(Unknown,  tmp = True    ^ True);
    EXPECT_EQ(False,    tmp = True    ^ Unknown);
    EXPECT_EQ(True,     tmp = True    ^ False);
    EXPECT_EQ(False,    tmp = Unknown ^ True);
    EXPECT_EQ(True,     tmp = Unknown ^ Unknown);
    EXPECT_EQ(Unknown,  tmp = Unknown ^ False);
    EXPECT_EQ(True,     tmp = False   ^ True);
    EXPECT_EQ(Unknown,  tmp = False   ^ Unknown);
    EXPECT_EQ(False,    tmp = False   ^ False);
}

TEST(TritTest, FLIP) {
    EXPECT_EQ(False,    Trit(_True).flip());
    EXPECT_EQ(Unknown,  Trit(_Unknown).flip());
    EXPECT_EQ(True,     Trit(_False).flip());   
}

TEST(TritTest, to_string) {
    EXPECT_EQ("False",  False.to_string());
    EXPECT_EQ("Unknown",Unknown.to_string());
    EXPECT_EQ("True",   True.to_string());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}