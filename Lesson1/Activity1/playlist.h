/* Copyright 2020 Ossuna  */
#pragma once

#include <memory>
#include <iostream>

namespace Playlist {

template <typename T>
struct Circular_list_node
{
    // TODO(reinaldo): change 'data' to unique_ptr
    // It's should be a good idea to use a unique_ptr here
    // You will need to overload the copy operators
    // to move 'data', since uniqueptr cant be copied
    std::shared_ptr<T> data = std::make_shared<T>();
    std::shared_ptr<Circular_list_node<T>> next = std::make_shared<Circular_list_node<T>>();
    std::shared_ptr<Circular_list_node<T>> prev = std::make_shared<Circular_list_node<T>>();

    Circular_list_node(): data(NULL), next(NULL), prev(NULL) {}
    ~Circular_list_node() = default;
};

template <typename T>
class Circular_list
{
 public:
    using node = Circular_list_node<T>;
    using node_ptr = std::shared_ptr<node>;

 private:
    node_ptr head = std::make_shared<node>();
    size_t n_;

 public:
Circular_list(): n_(0)
    {
        head->next = head;
        head->prev = head;
    }

    size_t size() const { return n_; }

    void insert(const T& value)
    {
        node_ptr new_node = std::make_shared<node>();
        new_node->data = std::make_shared<T>(value);

        node_ptr tmp = head->prev;
        tmp->next = head->prev;
        new_node->prev = tmp;

        if (tmp == head)
        {
            tmp->prev = new_node;
            new_node->next = tmp;
        } else {
            new_node->next = head;
            head->prev = new_node;
        }

        ++n_;
        head = new_node;
    }

    void erase(const T& value)
    {
        node_ptr curr = head;
        node_ptr tail = head->prev;

        while (curr != tail)
        {
            if ( *(curr->data) == value)
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;

                if (curr == head)
                {
                    head = head->next;
                }

                --n_;
                return;
            }
            curr = curr->next;
        }
        std::cout << "value: " << value << " not in the list" << std::endl;
    }

    class Circular_list_interator
    {
     private:
        node_ptr ptr;
     public:
    explicit Circular_list_interator(node_ptr p): ptr(p) {}
        T& operator*() { return *(ptr->data);}
        node_ptr get() { return ptr; }
        Circular_list_interator& operator++() { ptr = ptr->next; return *this; }
        Circular_list_interator& operator--() { ptr = ptr->prev; return *this; }
        friend bool operator==(const Circular_list_interator &it1, const Circular_list_interator &it2)
            {
            return it1.ptr == it2.ptr;
        }

        friend bool operator!=(const Circular_list_interator &it1, const Circular_list_interator &it2)
        {
        return it1.ptr != it2.ptr;
    }
    };

    Circular_list_interator begin() {return Circular_list_interator{head};}
    Circular_list_interator begin() const {return Circular_list_interator{head};}
    Circular_list_interator end() {return Circular_list_interator{head->prev};}
    Circular_list_interator end() const {return Circular_list_interator{head->prev};}

    Circular_list<T>(const Circular_list<T> &other): Circular_list()
    {
        for (const auto &i : other)
            this->insert(i);
    }
    explicit Circular_list<T>(const std::initializer_list<T> &il): head(NULL), n_(0)
    {
        for (const auto &i : il)
            this->insert(i);
    }

    ~Circular_list<T>()
    {
        while (size())
        {
            this->erase(*(head->data));
        }
    }
};

struct Playlist
{
    Circular_list<int> list;

    void insert(int song)
    {
        list.insert(song);
    }

    void erase(int song)
    {
        list.erase(song);
    }
    void loop_once()
    {
        for (auto& song : list)
            std:: cout << song << " ";
        std::cout << std::endl;
    }
};
}  // namespace Playlist
