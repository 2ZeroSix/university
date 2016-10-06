#include "tritset.h"
#include <gtest/gtest.h>

using namespace std;
using namespace tritspace;

///////////////
// functions //
///////////////
class extendToCapacityTest : public testing::Test{
public:
    bool Helper(size_t test_val) {
        size_t tmp      = extendToCapacity(test_val);
        return (tmp >= test_val)               &&
               (tmp % (sizeof(uint) * 4) == 0) &&
               (tmp <= test_val + (sizeof(uint) * 4));    
    }
};

TEST_F(extendToCapacityTest, Positive) {
    EXPECT_TRUE(Helper(1));
    EXPECT_TRUE(Helper(12));
    EXPECT_TRUE(Helper(123));
    EXPECT_TRUE(Helper(1234));
    EXPECT_TRUE(Helper(12345));
    EXPECT_TRUE(Helper(123456));
    EXPECT_TRUE(Helper(1234567));
    EXPECT_TRUE(Helper(12345678));
    EXPECT_TRUE(Helper(123456789));
    EXPECT_TRUE(Helper(1234567890));
}

TEST_F(extendToCapacityTest, Zero) {
    EXPECT_EQ(0, extendToCapacity(0));
}

/////////////
// TritSet //
/////////////

class TritSetTest : public testing::Test {
public:
    TritSet& fillset(TritSet& set) {
        for(size_t i = 0; i < set.capacity(); ++i) {
            set[i] = i;
        }
        return set;
    }
private:
};

TEST_F(TritSetTest, defaultConstructor) {
    TritSet set;
    ASSERT_EQ(0, set.capacity());
    EXPECT_EQ(0, set.length());
    EXPECT_EQ(Unknown, set[0]);
    EXPECT_EQ(Unknown, set[1000]);
}

TEST_F(TritSetTest, reserveConstructor) {
    TritSet set1(10);
    ASSERT_EQ(extendToCapacity(10), set1.capacity());
    EXPECT_EQ(0, set1.length());
    EXPECT_EQ(Unknown, set1[0]);
    EXPECT_EQ(Unknown, set1[1000]);
    TritSet set2(10000);
    ASSERT_EQ(extendToCapacity(10000), set2.capacity());
    EXPECT_EQ(0, set2.length());
    EXPECT_EQ(Unknown, set2[0]);
    EXPECT_EQ(Unknown, set2[1000]);
}

TEST_F(TritSetTest, copyConstructor) {
    TritSet set1(1000);
    fillset(set1);
    TritSet set2(set1);
    EXPECT_EQ(set1, set2);
}

TEST_F(TritSetTest, TritArrayConstructor) {
    Trit* arrt = new Trit[100];
    for (size_t i = 0; i < 100; ++i) {
        arrt[i] = Trit(i%3);
    }
    TritSet set(arrt, 100);
    for (size_t i = 0; i < 100; ++i) {
        ASSERT_EQ(arrt[i], set[i]);
    }
    for (size_t i = 100; i < set.capacity(); ++i) {
        ASSERT_EQ(Unknown, set[i]);
    }
}

TEST_F(TritSetTest, InitializerListConstructor) {
    TritSet set;
    set[0] = True;
    set[1] = Unknown;
    set[2] = False;
    TritSet set3 = {True, Unknown, False};
    TritSet set4{True, Unknown, False};
    TritSet set5({True, Unknown, False});
    ASSERT_EQ(set, set3);
    ASSERT_EQ(set, set4);
    ASSERT_EQ(set, set5);
}

TEST_F(TritSetTest, resize) {
    TritSet set(100);
    fillset(set);
    TritSet copySet(set);
    ASSERT_EQ(extendToCapacity(100), set.capacity());
    ASSERT_EQ(copySet, set);
    set.resize(1000);
    ASSERT_EQ(extendToCapacity(1000), set.capacity());
    ASSERT_EQ(copySet, set);
    set.resize(12345);
    ASSERT_EQ(extendToCapacity(12345), set.capacity());
    ASSERT_EQ(copySet, set);
    set.resize(0);
    ASSERT_EQ(extendToCapacity(0), set.capacity());
}

TEST_F(TritSetTest, operatorAssign) {
    TritSet set1(1000);
    TritSet set2;
    fillset(set1);
    set2 = set1;
    EXPECT_EQ(set1, set2);
}

TEST_F(TritSetTest, operatorAssignInitializerList) {
    TritSet set1{True, Unknown, False};
    TritSet set2;
    set2 = {True, Unknown, False};
    EXPECT_EQ(set1, set2);
}

TEST_F(TritSetTest, operatorIndex) {
    TritSet a(1000);
    size_t limit = a.capacity();
    ASSERT_LE(limit, 1000 + sizeof(uint) * 4);
    for(size_t i = 0; i < limit; ++i) {
        a[i] = Trit(i);
    }
    TritSet b(a);
    limit = b.capacity();
    ASSERT_LE(limit, 1000 + sizeof(uint) * 4);
    for(size_t i = 0; i < limit; ++i) {
        ASSERT_EQ(Trit(i), a[i]);
        ASSERT_EQ(a[i], b[i]);
    }
    limit = extendToCapacity(a.capacity() + 200);
    ASSERT_LE(limit, 1200 + sizeof(uint) * 8);
    for(size_t i = a.capacity(); i < limit; ++i) {
        a[i] = Trit(i);
    }
    const TritSet c(a);
    limit = c.capacity();
    ASSERT_LE(limit, 1200 + sizeof(uint) * 8);
    for(size_t i = 0; i < limit; ++i) {
        EXPECT_EQ(Trit(i), a[i]);
        EXPECT_EQ(a[i], c[i]);
    }
}

TEST_F(TritSetTest, operatorEq) {
    TritSet a(1000);
    TritSet b(1000);
    TritSet c(2000);
    a[100] = True;
    b[100] = True;
    c[100] = True;
    ASSERT_EQ(a, b);
    ASSERT_EQ(a, c);
    ASSERT_EQ(b, c);
    a[1500] = Unknown;
    b[1500] = Unknown;
    c[1500] = Unknown;
    ASSERT_EQ(a, b);
    ASSERT_EQ(a, c);
    ASSERT_EQ(b, c);
    a[2500] = False;
    b[2500] = False;
    c[2500] = False;
    ASSERT_EQ(a, b);
    ASSERT_EQ(a, c);
    ASSERT_EQ(b, c);
}

TEST_F(TritSetTest, operatorNe) {
    TritSet a(1000);
    TritSet b(1000);
    TritSet c(2000);
    a[100] = True;
    b[101] = True;
    c[102] = True;
    ASSERT_NE(a, b);
    ASSERT_NE(a, c);
    ASSERT_NE(b, c);
    a[1500] = Unknown;
    b[1500] = Unknown;
    c[1500] = Unknown;
    ASSERT_NE(a, b);
    ASSERT_NE(a, c);
    ASSERT_NE(b, c);
    a[2500] = False;
    b[2500] = False;
    c[2500] = False;
    ASSERT_NE(a, b);
    ASSERT_NE(a, c);
    ASSERT_NE(b, c);
}

TEST_F(TritSetTest, length) {
    TritSet a(1000);
    TritSet b(1000);
    TritSet c(2000);
    a[100] = True;
    b[101] = True;
    c[102] = True;
    ASSERT_EQ(101, a.length());
    ASSERT_EQ(102, b.length());
    ASSERT_EQ(103, c.length());
    a[1500] = False;
    b[1500] = Unknown;
    c[1500] = True;
    ASSERT_EQ(1501, a.length());
    ASSERT_EQ(102,  b.length());
    ASSERT_EQ(1501, c.length());
    a[2500] = Unknown;
    b[2500] = True;
    c[2500] = False;
    ASSERT_EQ(1501, a.length());
    ASSERT_EQ(2501, b.length());
    ASSERT_EQ(2501, c.length());
}

TEST_F(TritSetTest, shrink) {
    TritSet set(10000);
    ASSERT_EQ(extendToCapacity(10000), set.capacity());
    set[5000] = True;
    set.shrink();
    ASSERT_EQ(extendToCapacity(5000), set.capacity());
    set[5000] = Unknown;
    set.shrink();
    EXPECT_EQ(0, set.capacity());
    set[5000] = False;
    set.shrink();
    EXPECT_EQ(extendToCapacity(5000), set.capacity());
}

TEST_F(TritSetTest, trim) {
    TritSet set(1000);
    ASSERT_EQ(0, set.length());
    set[500] = True;
    ASSERT_EQ(501, set.length());
    set[1500] = False;
    ASSERT_EQ(1501, set.length());
    set.trim(1000);
    ASSERT_EQ(501, set.length());
    set.trim(500);
    ASSERT_EQ(0, set.length());
}

TEST_F(TritSetTest, cardinalityTritenum) {
    TritSet set(1001);
    for(size_t i = 0; i < set.capacity(); ++i) {
        set[i] = True;
    }
    EXPECT_EQ(set.capacity(), set.cardinality(Tritenum::True));
    EXPECT_EQ(0, set.cardinality(Tritenum::Unknown));
    EXPECT_EQ(0, set.cardinality(Tritenum::False));
    for(size_t i = set.capacity()/2; i < set.capacity(); ++i) {
        set[i] = False;
    }
    EXPECT_EQ(set.capacity()/2, set.cardinality(Tritenum::True));
    EXPECT_EQ(0, set.cardinality(Tritenum::Unknown));
    EXPECT_EQ(set.capacity()-set.capacity()/2, set.cardinality(Tritenum::False));
    for(size_t i = set.capacity()/2; i < set.capacity()*2/3; ++i) {
        set[i] = Unknown;
    }
    EXPECT_EQ(set.capacity()/2, set.cardinality(Tritenum::True));
    EXPECT_EQ(set.capacity()*2/3-set.capacity()/2, set.cardinality(Tritenum::Unknown));
    EXPECT_EQ(set.capacity()-set.capacity()*2/3, set.cardinality(Tritenum::False));
}

TEST_F(TritSetTest, cardinalityTrit) {
    TritSet set(1001);
    for(size_t i = 0; i < set.capacity(); ++i) {
        set[i] = True;
    }
    EXPECT_EQ(set.capacity(), set.cardinality(True));
    EXPECT_EQ(0, set.cardinality(Unknown));
    EXPECT_EQ(0, set.cardinality(False));
    for(size_t i = set.capacity()/2; i < set.capacity(); ++i) {
        set[i] = False;
    }
    EXPECT_EQ(set.capacity()/2, set.cardinality(True));
    EXPECT_EQ(0, set.cardinality(Unknown));
    EXPECT_EQ(set.capacity()-set.capacity()/2, set.cardinality(False));
    for(size_t i = set.capacity()/2; i < set.capacity()*2/3; ++i) {
        set[i] = Unknown;
    }
    EXPECT_EQ(set.capacity()/2, set.cardinality(True));
    EXPECT_EQ(set.capacity()*2/3-set.capacity()/2, set.cardinality(Unknown));
    EXPECT_EQ(set.capacity()-set.capacity()*2/3, set.cardinality(False));
}

TEST_F(TritSetTest, cardinalityAll) {
    TritSet set(1001);
    vector<size_t> tmp;
    for(size_t i = 0; i < set.capacity(); ++i) {
        set[i] = True;
    }
    tmp = set.cardinality();
    EXPECT_EQ(set.capacity(), tmp[size_t(Tritenum::True)]);
    EXPECT_EQ(0, tmp[size_t(Unknown)]);
    EXPECT_EQ(0, tmp[size_t(False)]);
    for(size_t i = set.capacity()/2; i < set.capacity(); ++i) {
        set[i] = False;
    }
    tmp = set.cardinality();
    EXPECT_EQ(set.capacity()/2, tmp[size_t(True)]);
    EXPECT_EQ(0, tmp[size_t(Unknown)]);
    EXPECT_EQ(set.capacity()-set.capacity()/2, tmp[size_t(False)]);
    for(size_t i = set.capacity()/2; i < set.capacity()*2/3; ++i) {
        set[i] = Unknown;
    }
    tmp = set.cardinality();
    EXPECT_EQ(set.capacity()/2, tmp[size_t(True)]);
    EXPECT_EQ(set.capacity()*2/3-set.capacity()/2, tmp[size_t(Unknown)]);
    EXPECT_EQ(set.capacity()-set.capacity()*2/3, tmp[size_t(False)]);
}

TEST_F(TritSetTest, operatorAND) {
    TritSet setA(9), setB(9), setC(9);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            setA[i*3 + j] = Trit(i);
            setB[i*3 + j] = Trit(j);
            setC[i*3 + j] = Trit(i) & Trit(j);
        }
    }
    EXPECT_EQ(setC, setA & setB);
}

TEST_F(TritSetTest, operatorOR) {
    TritSet setA(9), setB(9), setC(9);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            setA[i*3 + j] = Trit(i);
            setB[i*3 + j] = Trit(j);
            setC[i*3 + j] = Trit(i) | Trit(j);
        }
    }
    EXPECT_EQ(setC, setA | setB);
}

TEST_F(TritSetTest, operatorXOR) {
    TritSet setA(9), setB(9), setC(9);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            setA[i*3 + j] = Trit(i);
            setB[i*3 + j] = Trit(j);
            setC[i*3 + j] = Trit(i) ^ Trit(j);
        }
    }
    for (size_t i = 9; i < setC.capacity() ; ++i) {
        setC[i] ^= Unknown;
    }
    EXPECT_EQ(setC, setA ^ setB);
}

TEST_F(TritSetTest, operatorFLIP) {
    TritSet setA(9), setB(9);
    for (size_t i = 0; i < 3; ++i) {
        setA[i] = Trit(i);
        setB[i] = ~Trit(i);
    }
    EXPECT_EQ(setB, ~setA);
}

TEST_F(TritSetTest, operatorAssignAND) {
    TritSet setA(9), setB(9), setC(9);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            setA[i*3 + j] = Trit(i);
            setB[i*3 + j] = Trit(j);
            setC[i*3 + j] = Trit(i) & Trit(j);
        }
    }
    EXPECT_EQ(setC, setA &= setB);
}

TEST_F(TritSetTest, operatorAssignOR) {
    TritSet setA(9), setB(9), setC(9);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            setA[i*3 + j] = Trit(i);
            setB[i*3 + j] = Trit(j);
            setC[i*3 + j] = Trit(i) | Trit(j);
        }
    }
    EXPECT_EQ(setC, setA |= setB);
}

TEST_F(TritSetTest, operatorAssignXOR) {
    TritSet setA(9), setB(9), setC(9);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            setA[i*3 + j] = Trit(i);
            setB[i*3 + j] = Trit(j);
            setC[i*3 + j] = Trit(i) ^ Trit(j);
        }
    }
    for (size_t i = 9; i < setC.capacity() ; ++i) {
        setC[i] ^= Unknown;
    }
    EXPECT_EQ(setC, setA^= setB);
}

TEST_F(TritSetTest, FLIP) {
    TritSet setA(9), setB(9);
    for (size_t i = 0; i < 3; ++i) {
        setA[i] = Trit(i);
        setB[i] = ~Trit(i);
    }
    EXPECT_EQ(setB, setA.flip());
}

TEST_F(TritSetTest, operatorStreamOut) {
    stringstream ss;
    string tmp;
    TritSet set = {True, Unknown, False};
    ss << set << " " << "word";
    ss >> tmp;
    EXPECT_EQ("210", tmp);
    ss >> tmp;
    EXPECT_EQ("word", tmp);
}

TEST_F(TritSetTest, destructor) {
    TritSet set(100);
    fillset(set);
    set.~TritSet();
    ASSERT_EQ(0, set.capacity());
    EXPECT_EQ(0, set.length());
    EXPECT_EQ(Unknown, set[0]);
    EXPECT_EQ(Unknown, set[1000]);
}



////////////////////////////////
// TritSet::[const_|]iterator //
////////////////////////////////

class TritSetIteratorsTest : public testing::Test{
public:
    TritSetIteratorsTest() {
        for (int i = 0; i < 3; ++i) {
            it.emplace_back(set, i);
            cit.emplace_back(set, i);
            ccit.emplace_back(cset, i);
            // rit.emplace_back(TritSet::iterator(set, 3 - i));
            // crit.emplace_back(TritSet::const_iterator(set, 3 - i));
            // ccrit.emplace_back(TritSet::const_iterator(cset, 3 - i));
        }
    }
    ~TritSetIteratorsTest() {}
    TritSet set{True, Unknown, False};
    const TritSet cset{True, Unknown, False};
    std::vector<TritSet::iterator>                  it;
    std::vector<TritSet::const_iterator>            cit;
    std::vector<TritSet::const_iterator>            ccit;
    // std::vector<TritSet::reverse_iterator>          rit;
    // std::vector<TritSet::const_reverse_iterator>    crit;
    // std::vector<TritSet::const_reverse_iterator>    ccrit;
};

TEST_F(TritSetIteratorsTest, defaultConstructor_operatorDereferencing) {
    TritSet::iterator               it;
    TritSet::const_iterator         cit;
    TritSet::const_iterator         ccit;
    // TritSet::reverse_iterator       rit;
    // TritSet::const_reverse_iterator crit;
    // TritSet::const_reverse_iterator ccrit;
    ASSERT_EQ(*it,   Unknown);
    ASSERT_EQ(*cit,  Unknown);
    ASSERT_EQ(*ccit,  Unknown);
    // ASSERT_EQ(*rit,  Unknown);
    // ASSERT_EQ(*crit, Unknown);
    // ASSERT_EQ(*ccrit, Unknown);
}

TEST_F(TritSetIteratorsTest, TritSetConstructor_operatorDereferencing) {
    for (int i = 0; i < 3; ++i) {
        EXPECT_EQ(*it[i],    Tritenum(2 - i));
        EXPECT_EQ(*cit[i],   Tritenum(2 - i));
        EXPECT_EQ(*ccit[i],  Tritenum(2 - i));
        // EXPECT_EQ(*rit[i],   Tritenum(i));
        // EXPECT_EQ(*crit[i],  Tritenum(i));
        // EXPECT_EQ(*ccrit[i], Tritenum(i));
    }
}

TEST_F(TritSetIteratorsTest, copyConstructor_operatorEq_operatorToConstIterator) {
    TritSet::iterator       it(set,0);
    TritSet::const_iterator ccopy(it);
    TritSet::iterator       copy(it);
    EXPECT_EQ(it, ccopy);
    EXPECT_EQ(it, copy);
    EXPECT_EQ(ccopy, copy);
}

TEST_F(TritSetIteratorsTest, operatorNe) {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if( i != j ) {
                EXPECT_NE(it[i],    it[j]);
                EXPECT_NE(cit[i],   cit[j]);
                EXPECT_NE(ccit[i],  ccit[j]);
                // EXPECT_NE(rit[i],   rit[j]);
                // EXPECT_NE(crit[i],  crit[j]);
                // EXPECT_NE(ccrit[i], ccrit[j]);
            }
        }
    }
}

TEST_F(TritSetIteratorsTest, operatorLt) {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < i; ++j) {
            EXPECT_LT(it[j],    it[i]);
            EXPECT_LT(cit[j],   cit[i]);
            EXPECT_LT(ccit[j],  ccit[i]);
            // EXPECT_LT(rit[j],   rit[i]);
            // EXPECT_LT(crit[j],  crit[i]);
            // EXPECT_LT(ccrit[j], ccrit[i]);
        }
    }
}

TEST_F(TritSetIteratorsTest, operatorLe) {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j <= i; ++j) {
            EXPECT_LE(it[j],    it[i]);
            EXPECT_LE(cit[j],   cit[i]);
            EXPECT_LE(ccit[j],  ccit[i]);
            // EXPECT_LE(rit[j],   rit[i]);
            // EXPECT_LE(crit[j],  crit[i]);
            // EXPECT_LE(ccrit[j], ccrit[i]);
        }
    }
}

TEST_F(TritSetIteratorsTest, operatorGt) {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < i; ++j) {
            EXPECT_GT(it[i],    it[j]);
            EXPECT_GT(cit[i],   cit[j]);
            EXPECT_GT(ccit[i],  ccit[j]);
            // EXPECT_GT(rit[i],   rit[j]);
            // EXPECT_GT(crit[i],  crit[j]);
            // EXPECT_GT(ccrit[i], ccrit[j]);
        }
    }
}

TEST_F(TritSetIteratorsTest, operatorGe) {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j <= i; ++j) {
            EXPECT_GE(it[i],    it[j]);
            EXPECT_GE(cit[i],   cit[j]);
            EXPECT_GE(ccit[i],  ccit[j]);
            // EXPECT_GE(rit[i],   rit[j]);
            // EXPECT_GE(crit[i],  crit[j]);
            // EXPECT_GE(ccrit[i], ccrit[j]);
        }
    }
}

TEST_F(TritSetIteratorsTest, opearatorArrow) {
    for(int i = 0; i < 3; ++i) {
        EXPECT_EQ(it[i]->state(),    Tritenum(2 - i));
        EXPECT_EQ(cit[i]->state(),   Tritenum(2 - i));
        EXPECT_EQ(ccit[i]->state(),  Tritenum(2 - i));
        // EXPECT_EQ(rit[i]->state(),   Tritenum(i));
        // EXPECT_EQ(crit[i]->state(),  Tritenum(i));
        // EXPECT_EQ(ccrit[i]->state(), Tritenum(i));
    }
}

TEST_F(TritSetIteratorsTest, operatorAdd) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j <= i; ++j) {
            EXPECT_EQ(it[i],    it[j]   + i - j);
            EXPECT_EQ(it[i],    cit[j]   + i - j);
            EXPECT_EQ(cit[i],   it[j]   + i - j);
            EXPECT_EQ(cit[i],   cit[j]  + i - j);
            EXPECT_EQ(ccit[i],  ccit[j] + i - j);
        }
    }
}

TEST_F(TritSetIteratorsTest, operatorAddAssign) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j <= i; ++j) {
            TritSet::iterator testit = it[j];
            EXPECT_EQ(it[i], testit+= i - j);
            testit = it[j];
            EXPECT_EQ(cit[i], testit+= i - j);
        }
    }
}

TEST_F(TritSetIteratorsTest, operatorPrefixIncrement) {
    for (int i = 0; i < 2; ++i) {
        TritSet::iterator testit = it[i];
        EXPECT_EQ(it[i + 1], ++testit);
        EXPECT_EQ(cit[i + 1], testit);
    }
}

TEST_F(TritSetIteratorsTest, operatorPostfixIncrement) {
    for (int i = 0; i < 3; ++i) {
        TritSet::iterator testit = it[i];
        EXPECT_EQ(it[i], testit++);
        if (i < 2) {
            EXPECT_EQ(cit[i + 1], testit);
        }
    }    
}

TEST_F(TritSetIteratorsTest, operatorSub) {    
    for (int i = 0; i < 3; ++i) {
        for (int j = 2; j >= i; --j) {
            EXPECT_EQ(it[i],    it[j]    - j + i);
            EXPECT_EQ(it[i],    cit[j]   - j + i);
            EXPECT_EQ(cit[i],   it[j]    - j + i);
            EXPECT_EQ(cit[i],   cit[j]   - j + i);
            EXPECT_EQ(ccit[i],  ccit[j]  - j + i);
        }
    }
}

TEST_F(TritSetIteratorsTest, operatorSubAssign) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 2; j >= i; --j) {
            TritSet::iterator testit = it[j];
            EXPECT_EQ(it[i], testit-= - i + j);
            testit = it[j];
            EXPECT_EQ(cit[i], testit-= - i + j);
        }
    }
}

TEST_F(TritSetIteratorsTest, operatorPrefixDecrement) {
    for (int i = 1; i < 3; ++i) {
        TritSet::iterator testit = it[i];
        EXPECT_EQ(it[i - 1], --testit);
        EXPECT_EQ(cit[i - 1], testit);
    }
}

TEST_F(TritSetIteratorsTest, operatorPostfixDecrement) {
    for (int i = 0; i < 3; ++i) {
        TritSet::iterator testit = it[i];
        EXPECT_EQ(it[i], testit--);
        if (i > 0) {
            EXPECT_EQ(cit[i - 1], testit);
        }
    }    
}

TEST_F(TritSetIteratorsTest, operatorIndex) {
    TritSet::iterator testit = begin(set);
    TritSet::const_iterator testcit = begin(cset);
    for (int i = 0; i < 3; ++i) {
        EXPECT_EQ(*it[i],    testit[i]);
        EXPECT_EQ(*cit[i],   testit[i]);
        EXPECT_EQ(*ccit[i],  testcit[i]);
    }    
}