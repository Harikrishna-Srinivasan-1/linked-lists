#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "linkedlist.h"
#include "exception.h"

template <typename A>
class singly_linked_list: public linkedlist<A>
{
    private:
        size_t length;

        static typename linkedlist<A>::node *mergesort(typename linkedlist<A>::node *head);
        static typename linkedlist<A>::node *merge(typename linkedlist<A>::node *left, typename linkedlist<A>::node *right);
    public:
        singly_linked_list();

        singly_linked_list(const singly_linked_list<A> &obj);
        singly_linked_list(const std::initializer_list<A> &values);
        
        template <size_t N>
        singly_linked_list(const A (&array)[N]);
        singly_linked_list(const std::vector<A> &values);

        singly_linked_list(singly_linked_list<A> &&obj) noexcept;
        
        singly_linked_list<A> &operator=(const singly_linked_list<A> &obj);
        singly_linked_list<A> &operator=(const std::initializer_list<A> &values);
        
        template <size_t N>
        singly_linked_list<A> &operator=(const A (&array)[N]);
        singly_linked_list<A> &operator=(const singly_linked_list<A> &obj);
        singly_linked_list<A> &operator=(singly_linked_list<A> &&obj) noexcept;

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

        size_t size() const override;

        int64_t find(const A &value) const override;
        A find_min() const override;
        A find_max() const override;
        size_t count(const A &value) const override;

        void reverse() override;
        void sort() override;

        singly_linked_list<A> &copy(const singly_linked_list<A> &obj);

        A &operator[](const int64_t &index) override;
        singly_linked_list<A> operator+(const linkedlist<A> &obj);
        singly_linked_list<A> operator*(const size_t &times);
        
        bool operator>(const linkedlist<A> &obj) const override;
        bool operator<(const linkedlist<A> &obj) const override;
        bool operator>=(const linkedlist<A> &obj) const override;
        bool operator<=(const linkedlist<A> &obj) const override;
        bool operator==(const linkedlist<A> &obj) const override;
        bool operator!=(const linkedlist<A> &obj) const override;

        void show() const override;

        void clear() override;

        template <typename B>
        friend singly_linked_list<B> operator*(const size_t &times, const singly_linked_list<B> &obj);
        
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
