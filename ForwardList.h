#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <limits>
#include <utility>

using usize   = std::size_t;
using ptrdiff = std::ptrdiff_t;
using intptr  = std::intptr_t;
using uintptr = std::uintptr_t;
using u8      = std::uint8_t;
using i8      = std::int8_t;
using u16     = std::uint16_t;
using i16     = std::int16_t;
using u32     = std::uint32_t;
using i32     = std::int32_t;
using u64     = std::uint64_t;
using i64     = std::int64_t;

namespace stl {
    template <typename T>
    class ForwardList
    {
    private:
        struct Node
        {
            T     obj{};
            Node* next = nullptr;

        public:
            Node() noexcept;
            Node(const T& obj) noexcept;
        };
        /* Later...
        class ConstIterator;
        class Iterator
        {
            friend class ConstIterator;

            using iterator_category = std::forward_iterator_tag;
            using difference_type   = ptrdiff;
            using value_type        = ForwardList<T>;
            using pointer           = value_type*;
            using reference         = value_type&;

        private:
            pointer m_Ptr;
            usize   m_Index;

        public:
            Iterator(pointer ptr = nullptr, const usize index = 0) noexcept : m_Ptr(ptr), m_Index(index) {}

        public:
            constexpr reference operator*() const noexcept { return m_Ptr[index]; }
            constexpr pointer   operator->() const noexcept { return m_Ptr; };
            inline Iterator&    operator++() noexcept
            {
                m_Ptr = m_Ptr->next;
                return *this;
            }
            Iterator operator++(const i32) noexcept
            {
                auto t = *this;
                ++(*this);
                return t;
            }
            constexpr ptrdiff operator-(const Iterator& other) const noexcept { return m_Ptr - other.m_Ptr; }
            inline Iterator   operator+(const uintptr disp) const noexcept
            {
                Iterator temp = *this;
                temp.m_Ptr += disp;
                return temp;
            };
            inline Iterator operator-(const uintptr disp) const noexcept
            {
                Iterator temp = *this;
                temp.m_Ptr -= disp;
                return temp;
            }

        public:
            friend bool operator==(const Iterator& lhv, const Iterator& rhv) noexcept { return lhv.m_Ptr == rhv.m_Ptr; }
            friend bool operator!=(const Iterator& lhv, const Iterator& rhv) noexcept { return !(lhv == rhv); }
        };
        */

    private:
        Node* m_Head;
        usize m_Length;

    public:
        ForwardList();
        ForwardList(const std::initializer_list<T> list);
        ForwardList(const ForwardList<T>& other);
        ForwardList(ForwardList<T>&& other) noexcept;
        ~ForwardList();

    private:
        inline void                    Drop() noexcept;
        inline std::pair<Node*, Node*> GetPreviousAndLast() noexcept;

    public:
        constexpr bool  Empty() const noexcept { return m_Length == 0; }
        constexpr usize Size() const noexcept { return m_Length; }
        constexpr usize MaxSize() const noexcept { return std::numeric_limits<usize>::max() / sizeof(Node); }

    public:
        constexpr void  Push(const T& e);
        constexpr void  PushFront(const T& e);
        inline T        Pop();
        inline T&       Frost();
        inline const T& Frost() const;
        constexpr void  Clear();
        constexpr void  Resize(const usize newSize);
        constexpr void  Swap(ForwardList<T>& other);

    public:
        inline T& operator[](const usize index) noexcept;

    public:
        friend std::ostream& operator<<(std::ostream& stream, const ForwardList<T>& other) noexcept
        {
            stream << "[ ";
            for (auto* c = other.m_Head; c; c = c->next)
            {
                if (c->next)
                    stream << c->obj << ", ";
                else
                    stream << c->obj;
            }
            stream << " ]";
            return stream;
        }
    };
} // namespace stl

// TODO: Uncomment.
// #include "ForwardList.hpp"
#endif // FORWARD_LIST_H
