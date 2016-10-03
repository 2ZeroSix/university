#include "trit.h"
#include <gtest/gtest.h>
#include <sstream>
using namespace std;
using namespace tritspace;

//////////
// Trit //
//////////

TEST(TritTest, intConstructor) {
    ASSERT_EQ(Tritenum::False,   Trit(0).state());
    ASSERT_EQ(Tritenum::False,   Trit(3).state());
    ASSERT_EQ(Tritenum::Unknown, Trit(1).state());
    ASSERT_EQ(Tritenum::Unknown, Trit(4).state());
    ASSERT_EQ(Tritenum::True,    Trit(2).state());
    ASSERT_EQ(Tritenum::True,    Trit(5).state());
}

TEST(TritTest, TritenumConstructor) {
    ASSERT_EQ(Tritenum::Unknown, Trit(Tritenum::Unknown).state());
    ASSERT_EQ(Tritenum::False,   Trit(Tritenum::False).state());
    ASSERT_EQ(Tritenum::True,    Trit(Tritenum::True).state());
}

TEST(TritTest, copyConstructor) {
    ASSERT_EQ(Tritenum::Unknown, Trit(Unknown).state());
    ASSERT_EQ(Tritenum::False,   Trit(False).state());
    ASSERT_EQ(Tritenum::True,    Trit(True).state());
}

TEST(TritTest, defaultConstructor) {
    ASSERT_EQ(Tritenum::Unknown, Trit().state());
    Trit tmp;
    ASSERT_EQ(Tritenum::Unknown, tmp.state());
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

TEST(TritTest, operatorNeOther) {
    ASSERT_EQ(false,    True    != True);
    ASSERT_EQ(true,     True    != Unknown);
    ASSERT_EQ(true,     True    != False);
    ASSERT_EQ(true,     Unknown != True);
    ASSERT_EQ(false,    Unknown != Unknown);
    ASSERT_EQ(true,     Unknown != False);
    ASSERT_EQ(true,     False   != True);
    ASSERT_EQ(true,     False   != Unknown);
    ASSERT_EQ(false,    False   != False);
}

TEST(TritTest, operatorAssignTritenum) {
    Trit tmp;
    ASSERT_EQ(False,    tmp = Tritenum::False);
    ASSERT_EQ(Unknown,  tmp = Tritenum::Unknown);
    ASSERT_EQ(True,     tmp = Tritenum::True);
}

TEST(TritTest, operatorAssignTrit) {
    Trit tmp = False;
    ASSERT_EQ(False,    tmp);
    tmp = Unknown;
    ASSERT_EQ(Unknown,  tmp);
    tmp = True;
    ASSERT_EQ(True,     tmp);
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

TEST(TritTest, operatorFLIP) {
    EXPECT_EQ(False,    ~True);
    EXPECT_EQ(Unknown,  ~Unknown);
    EXPECT_EQ(True,     ~False);
}

TEST(TritTest, operatorAssignAND) {
    Trit tmp = True;
    EXPECT_EQ(True,    tmp &= True);
    tmp = True;
    EXPECT_EQ(Unknown, tmp &= Unknown);
    tmp = True;
    EXPECT_EQ(False,   tmp &= False);
    tmp = Unknown;
    EXPECT_EQ(Unknown, tmp &= True);
    tmp = Unknown;
    EXPECT_EQ(Unknown, tmp &= Unknown);
    tmp = Unknown;
    EXPECT_EQ(False,   tmp &= False);
    tmp = False;
    EXPECT_EQ(False,   tmp &= True);
    tmp = False;
    EXPECT_EQ(False,   tmp &= Unknown);
    tmp = False;
    EXPECT_EQ(False,   tmp &= False);
}

TEST(TritTest, operatorAssignOR) {
    Trit tmp = True;
    EXPECT_EQ(True,    tmp |= True);
    tmp = True;
    EXPECT_EQ(True,    tmp |= Unknown);
    tmp = True;
    EXPECT_EQ(True,    tmp |= False);
    tmp = Unknown;
    EXPECT_EQ(True,    tmp |= True);
    tmp = Unknown;
    EXPECT_EQ(Unknown, tmp |= Unknown);
    tmp = Unknown;
    EXPECT_EQ(Unknown, tmp |= False);
    tmp = False;
    EXPECT_EQ(True,    tmp |= True);
    tmp = False;
    EXPECT_EQ(Unknown, tmp |= Unknown);
    tmp = False;
    EXPECT_EQ(False,   tmp |= False);
}

TEST(TritTest, operatorAssignXOR) {
    Trit tmp = True;
    EXPECT_EQ(Unknown, tmp ^= True);
    tmp = True;
    EXPECT_EQ(False,   tmp ^= Unknown);
    tmp = True;
    EXPECT_EQ(True,    tmp ^= False);
    tmp = Unknown;
    EXPECT_EQ(False,   tmp ^= True);
    tmp = Unknown;
    EXPECT_EQ(True,    tmp ^= Unknown);
    tmp = Unknown;
    EXPECT_EQ(Unknown, tmp ^= False);
    tmp = False;
    EXPECT_EQ(True,    tmp ^= True);
    tmp = False;
    EXPECT_EQ(Unknown, tmp ^= Unknown);
    tmp = False;
    EXPECT_EQ(False,   tmp ^= False);
}

TEST(TritTest, FLIP) {
    EXPECT_EQ(False,    Trit(Tritenum::True).flip());
    EXPECT_EQ(Unknown,  Trit(Tritenum::Unknown).flip());
    EXPECT_EQ(True,     Trit(Tritenum::False).flip());   
}

TEST(TritTest, to_string) {
    EXPECT_EQ("False",  False.to_string());
    EXPECT_EQ("Unknown",Unknown.to_string());
    EXPECT_EQ("True",   True.to_string());
}

TEST(TritTest, operatorStreamOut) {
    stringstream ss;
    string tmp;
    ss << True;
    ss >> tmp;
    EXPECT_EQ("True", tmp);
    ss = stringstream();
    ss << Unknown;
    ss >> tmp;
    EXPECT_EQ("Unknown", tmp);
    ss = stringstream();
    ss << False;
    ss >> tmp;
    EXPECT_EQ("False", tmp);
    ss = stringstream();
    ss << True << " " << Unknown << " " << False;
    ss >> tmp;
    EXPECT_EQ("True", tmp);
    ss >> tmp;
    EXPECT_EQ("Unknown", tmp);
    ss >> tmp;
    EXPECT_EQ("False", tmp);
}

TEST(TritTest, destructor) {
    Trit trit(True);
    trit.~Trit();
    EXPECT_EQ(Unknown.state(), trit.state());
}
