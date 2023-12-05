#ifndef FORWARD_LIST_IMPL_H
#define FORWARD_LIST_IMPL_H

// TODO: Remove.
#include "ForwardList.h"

namespace stl {
    template <typename T>
    using Node = ForwardList<T>::Node;

    template <typename T>
    ForwardList<T>::Node::Node() noexcept = default;

    template <typename T>
    ForwardList<T>::Node::Node(const T& obj) noexcept : obj(obj)
    {
    }

    template <typename T>
    ForwardList<T>::ForwardList(const ForwardList<T>& other)
    {
        if (!other.m_Head)
            return;

        auto* current      = other.m_Head;
        m_Head             = new Node(current->obj);
        auto* this_current = m_Head;
        while (current)
        {
            this_current->next = new Node(current->obj);
            current            = current->next;
            this_current       = this_current->next;
        }
    }

    template <typename T>
    ForwardList<T>::ForwardList(ForwardList<T>&& other) noexcept
    {
        if (other.m_Head)
        {
            m_Head         = other.m_Head;
            m_Length       = other.m_Length;
            other.m_Head   = nullptr;
            other.m_Length = 0;
        }
    }

    template <typename T>
    ForwardList<T>::ForwardList() = default;

    template <typename T>
    ForwardList<T>::ForwardList(const std::initializer_list<T> list)
    {
        for (const auto& e : list)
            Push(e);
    }

    template <typename T>
    ForwardList<T>::~ForwardList()
    {
        Drop();
    }

    template <typename T>
    inline void ForwardList<T>::Drop() noexcept
    {
        auto* current = m_Head;
        while (current)
        {
            auto* temp = current;
            current    = current->next;
            delete temp;
        }
        m_Head = nullptr;
    }

    template <typename T>
    inline std::pair<Node<T>*, Node<T>*> ForwardList<T>::GetPreviousAndLast() noexcept
    {
        Node* current = m_Head;
        Node* prev    = nullptr;
        while (current)
        {
            prev    = current;
            current = current->next;
        }
        return { prev, current };
    }

    template <typename T>
    constexpr void ForwardList<T>::Push(const T& e)
    {
        if (!m_Head)
            m_Head = new Node(e);
        else
        {
            auto* current = m_Head;
            while (current->next)
                current = current->next;
            current->next = new Node(e);
        }
        ++m_Length;
    }

    template <typename T>
    constexpr void ForwardList<T>::PushFront(const T& e)
    {
        if (!m_Head)
            m_Head = new Node(e);
        else
        {
            auto* prev   = m_Head;
            m_Head       = new Node(e);
            m_Head->next = prev;
        }
        ++m_Length;
    }

    template <typename T>
    inline T& ForwardList<T>::Frost()
    {
        if (!m_Head)
            throw std::out_of_range("Tried caling Front() on an empty List.");
        return m_Head->obj;
    }

    template <typename T>
    inline const T& ForwardList<T>::Frost() const
    {
        if (!m_Head)
            throw std::out_of_range("Tried caling Front() on an empty List.");
        return m_Head->obj;
    }

    template <typename T>
    constexpr void ForwardList<T>::Clear()
    {
        Drop();
    }

    template <typename T>
    constexpr void ForwardList<T>::Resize(const usize newSize)
    {
    }

    template <typename T>
    constexpr void ForwardList<T>::Swap(ForwardList<T>& other)
    {
        std::swap(m_Head, other.m_Head);
        std::swap(m_Length, other.m_Length);
    }

    template <typename T>
    inline T& ForwardList<T>::operator[](const usize index) noexcept
    {
        usize i       = 0;
        auto* current = m_Head;
        while (current->next)
        {
            if (i++ == index)
                return current->obj;
            current = current->next;
        }
    }

    template <typename T>
    inline ForwardList<T>& ForwardList<T>::operator=(const ForwardList<T>& other)
    {
        if (&other == this || !other.m_Head)
            return *this;

        if (m_Head)
            Drop();

        auto* current      = other.m_Head;
        m_Head             = new Node(current->obj);
        auto* this_current = m_Head;
        while (current)
        {
            this_current->next = new Node(current->obj);
            current            = current->next;
            this_current       = this_current->next;
        }

        return *this;
    }

    template <typename T>
    inline ForwardList<T>& ForwardList<T>::operator=(ForwardList<T>&& other) noexcept
    {
        if (&other == this)
            return *this;

        if (m_Head)
            Drop();

        m_Head         = other.m_Head;
        m_Length       = other.m_Length;
        other.m_Head   = nullptr;
        other.m_Length = 0;
        return *this;
    }

    template <typename T>
    inline T ForwardList<T>::Pop()
    {
        auto prev_two = GetPreviousAndLast();
        auto obj      = std::move(prev_two.first);
        delete prev_two.second;
        prev_two.first->next = nullptr;
        --m_Length;
    }
} // namespace stl

#endif // FORWARD_LIST_IMPL_H
