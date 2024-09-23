#include <gtest/gtest.h>

#include "../singly_linked_list.h"

class my_class
{
    private:
        int my_var;
    public:
        my_class() = default;

        my_class(int var)
        {
            this->my_var = var;
        }

        bool operator<(const my_class &obj) const
        {
            return this->my_var < obj.my_var;
        }

        bool operator>(const my_class &obj) const
        {
            return this->my_var > obj.my_var;
        }

        bool operator<=(const my_class &obj) const
        {
            return this->my_var <= obj.my_var;
        }

        bool operator>=(const my_class &obj) const
        {
            return this->my_var >= obj.my_var;
        }

        bool operator==(const my_class &obj) const
        {
            return this->my_var == obj.my_var;
        }

        bool operator!=(const my_class &obj) const
        {
            return this->my_var != obj.my_var;
        }
};

TEST(SinglyLinkedListTest, DefaultConstructor) {
    singly_linked_list<int> list;
    EXPECT_TRUE(list.size() == 0);
}

TEST(SinglyLinkedListTest, InitializerListConstructor) {
    singly_linked_list<int> list = {21, 45, 37};
    EXPECT_EQ(list.size(), 3);
}

TEST(SinglyLinkedListTest, CopyConstructor) {
    singly_linked_list<int> original = {10, 20, 30};
    singly_linked_list<int> copy(original);
    EXPECT_EQ(copy.size(), 3);
    EXPECT_EQ(copy, original);
}

TEST(SinglyLinkedListTest, MoveConstructor) {
    singly_linked_list<int> original = {1, 2, 3};
    singly_linked_list<int> moved(std::move(original));
    EXPECT_EQ(moved.size(), 3);
    EXPECT_TRUE(original.isempty());
}

TEST(SinglyLinkedListTest, VectorConstructor) {
    std::vector<my_class> vec = {my_class(1), my_class(2)};
    singly_linked_list<my_class> list(vec);
    EXPECT_EQ(list.size(), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
