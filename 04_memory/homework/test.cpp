#include <gtest/gtest.h>

#include "04_memory/homework/vector.hpp"

void expectVectorsEqual(std::vector<Person> correct, PersonVector checked) {
    EXPECT_EQ(checked.size(), correct.size());
    for (int i = 0; i < (int)checked.size(); i++) {
        EXPECT_EQ(checked.get(i), correct[i]);
    }
    EXPECT_THROW(checked.get(checked.size() + 1), OutOfBoundsException);
}

TEST(VectorTest, EmptyInitialise) {
    PersonVector v(0, Person());

    EXPECT_EQ(v.size(), 0);
    EXPECT_THROW(v.get(0), OutOfBoundsException);
}

TEST(VectorTest, expectVectorsEqual) {
    Person p;
    p.first_name_ = "";
    p.last_name_ = "";
    p.age_ = 0;
    PersonVector a(3, p);
    expectVectorsEqual({p, p, p}, a);
}

TEST(VectorTest, InitialiseOnly) {
    PersonVector v(3, Person());
    expectVectorsEqual({Person(), Person(), Person()}, v);
}

TEST(VectorTest, InsertEmpty) {
    PersonVector v(0, Person());
    expectVectorsEqual({}, v);
    v.push_back(Person("John", "Smith", 25));
    expectVectorsEqual({Person("John", "Smith", 25)}, v);
}

TEST(VectorTest, InsertMultiple) {
    PersonVector v(0, Person());
    expectVectorsEqual({}, v);
    v.push_back(Person("John", "Smith", 25));
    v.push_back(Person("Jon", "Doe", 72));
    v.push_back(Person("Maria", "McDonald", 37));
    v.push_back(Person("Sofia", "Shaffer", 99));
    expectVectorsEqual(
        {
            Person("John", "Smith", 25),
            Person("Jon", "Doe", 72),
            Person("Maria", "McDonald", 37),
            Person("Sofia", "Shaffer", 99),
        },
        v);
}

TEST(VectorTest, ContainsTest) {
    PersonVector v(0, Person());
    expectVectorsEqual({}, v);
    v.push_back(Person("John", "Smith", 25));
    v.push_back(Person("Mary", "McDonald", 37));
    ASSERT_TRUE(v.contains(Person("Mary", "McDonald", 37)));
    ASSERT_FALSE(v.contains(Person("Maria", "McDonald", 37)));
    ASSERT_FALSE(v.contains(Person("Mary", "Saucedo", 37)));
    ASSERT_FALSE(v.contains(Person("Mary", "McDonald", 38)));
    ASSERT_FALSE(v.contains(Person("Maria", "Saucedo", 38)));
}

TEST(VectorTest, ReplaceTest) {
    PersonVector v(0, Person());
    expectVectorsEqual({}, v);
    v.push_back(Person("John", "Smith", 25));
    v.push_back(Person("Mary", "McDonald", 37));
    v.push_back(Person("Jon", "Doe", 72));
    expectVectorsEqual(
        {Person("John", "Smith", 25), Person("Mary", "McDonald", 37),
         Person("Jon", "Doe", 72)},
        v);
    v.replace(1, Person("Alba", "Fernandez", 33));
}

TEST(VectorTest, InsertAndRemove) {
    PersonVector v(0, Person());
    expectVectorsEqual({}, v);
    v.push_back(Person("John", "Smith", 25));
    v.push_back(Person("Jon", "Doe", 72));
    v.push_back(Person("Maria", "McDonald", 37));
    v.push_back(Person("Sofia", "Shaffer", 99));
    expectVectorsEqual(
        {
            Person("John", "Smith", 25),
            Person("Jon", "Doe", 72),
            Person("Maria", "McDonald", 37),
            Person("Sofia", "Shaffer", 99),
        },
        v);
    v.remove_back();
    expectVectorsEqual(
        {
            Person("John", "Smith", 25),
            Person("Jon", "Doe", 72),
            Person("Maria", "McDonald", 37),
        },
        v);
    v.remove_back();
    expectVectorsEqual(
        {
            Person("John", "Smith", 25),
            Person("Jon", "Doe", 72),
        },
        v);
    v.remove_back();
    expectVectorsEqual({Person("John", "Smith", 25)}, v);
}
