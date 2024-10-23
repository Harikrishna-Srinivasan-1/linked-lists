#if __cplusplus >= 201103L

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <array>

#include "./linkedlist.hpp"

template <typename A>
class singly_linked_list: public linkedlist<A>
{
    private:
        size_t *length, *ref_count;
        
        static typename linkedlist<A>::node *mergesort(typename linkedlist<A>::node *head);
        static typename linkedlist<A>::node *merge(typename linkedlist<A>::node *left, typename linkedlist<A>::node *right);
    public:
        singly_linked_list();

        singly_linked_list(singly_linked_list<A> &&obj);
        singly_linked_list(const singly_linked_list<A> &obj);
        singly_linked_list(const std::initializer_list<A> &values);
        
        template <size_t N>
        singly_linked_list(const A (&array)[N]);
        singly_linked_list(const std::vector<A> &values);

        // singly_linked_list(singly_linked_list<A> &&obj) noexcept = delete;

        singly_linked_list<A> operator=(singly_linked_list<A> &&obj);
        singly_linked_list<A> &operator=(const singly_linked_list<A> &obj);
        singly_linked_list<A> &operator=(const std::initializer_list<A> &values);
        
        template <size_t N>
        singly_linked_list<A> &operator=(const A (&array)[N]);
        singly_linked_list<A> &operator=(const std::vector<A> &values);

        // singly_linked_list<A> &operator=(singly_linked_list<A> &&obj) noexcept = delete;

        void prepend(const A &value) override;
        void append(const A &value) override;
        void insert(const int64_t &index, const A &value) override;
        void insert(const int64_t &index, const linkedlist<A> &obj) override;
        void insert(const int64_t &index, const std::initializer_list<A> &values) override;
        
        template <size_t N>
        void insert(const int64_t &index, const A (&array)[N]);
        void insert(const int64_t &index, const std::vector<A> &values) override;

        void insert_in_order(const A &value) override;
        void insert_in_order(const linkedlist<A> &obj) override;
        void insert_in_order(const std::initializer_list<A> &values) override;
        
        template <size_t N>
        void insert_in_order(const A (&array)[N]);
        void insert_in_order(const std::vector<A> &values) override;

        void extend(const linkedlist<A> &obj) override;
        void extend(const std::initializer_list<A> &values) override;

        template <size_t N>
        void extend(const A (&array)[N]);
        void extend(const std::vector<A> &values) override;

        void remove(const A &value) override;
        A pop(const int64_t &index) override;
        A pop() override;

        constexpr size_t size() const override;

        bool contains(const A &value) const override;
        int64_t index(const A &value) const override;
        size_t count(const A &value) const override;

        void reverse() override;
        void sort() override;

        singly_linked_list<A> copy() const;

        A &operator[](const int64_t &index) override;
        singly_linked_list<A> operator+(const linkedlist<A> &obj) const;
        singly_linked_list<A> operator*(const size_t &times);

        bool operator>(const linkedlist<A> &obj) const override;
        bool operator<(const linkedlist<A> &obj) const override;
        bool operator>=(const linkedlist<A> &obj) const override;
        bool operator<=(const linkedlist<A> &obj) const override;
        bool operator==(const linkedlist<A> &obj) const override;
        bool operator!=(const linkedlist<A> &obj) const override;

        template <size_t N>
        operator std::array<A, N>();
        operator A *() override;
        operator std::vector<A>() override;

        void show() override;

        void clear() override;
        
        template <typename B>
        friend std::ostream &operator<<(std::ostream &out, singly_linked_list<B> &obj);

        ~singly_linked_list();
};

template <typename A>
singly_linked_list<A> operator*(const size_t &times, singly_linked_list<A> &obj);

template <typename A>
std::ostream &operator<<(std::ostream &out, singly_linked_list<A> &obj);

#include "singly_linked_list.tpp"

#endif

#else
    #error "Requires C++11 or later.\n"

#endif
