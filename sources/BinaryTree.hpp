#pragma once
#include <string> // string
#include <map>    // for the map data base
#include <iostream>
#include <vector>    // vector
#include <fstream>   // file
#include <exception> // hold the exeptions
namespace ariel
{
    const std::string NOT_FOUND = "did not found the correct value to set his son";
    template <typename T>
    class BinaryTree
    {

    public:
        class TreeNode
        {
        private:
            T val;
            TreeNode *prev;
            TreeNode *left;
            TreeNode *right;

        public:
            TreeNode(const T &val, TreeNode *prev_temp) : val(val), left(nullptr), right(nullptr), prev(prev_temp) {}
            ~TreeNode()
            {
            }
            T &get_val()
            {
                return val;
            }
            void set_val(const T &val_temp)
            {
                val = val_temp;
            }
            void add_left_child(const T &p)
            {
                /*
            if (left == nullptr)
            {
                TreeNode<T>node_n = new TreeNode<T>(p, this);
                left = node_n;
            }
            else
            {
                this->left->set_val(p);
            }
            */
            }
            void add_right_child(const T &p)
            {
                /*
            if (right == nullptr)
            {
                TreeNode<T> node_n = new TreeNode<T>(p, this);
                right = node_n;
            }
            else
            {
                this->right->set_val(p);
            }
            */
            }
            TreeNode *get_left() { return (left); }
            TreeNode *get_right() { return (right); }
            TreeNode *get_prev() { return (prev); }
        };

        class iterator_preorder
        {
        public:
            TreeNode *cur_node;

            iterator_preorder(TreeNode *v) : cur_node(v){};
            iterator_preorder &operator++()
            {
                return *this;
            }
            T &operator*()
            {
                return cur_node->get_val();
            }
            bool operator!=(const iterator_preorder &other) const
            {
                return cur_node != other.cur_node;
            }
            T *operator->()
            {
                return nullptr;
            }
        };

        class iterator_inorder
        {
        public:
            TreeNode *cur_node;
            iterator_inorder(TreeNode *v) : cur_node(v){};
            iterator_inorder &operator++()
            {
                return *this;
            }
            T &operator*()
            {
                return cur_node->get_val();
            }
            bool operator!=(const iterator_inorder &other) const 
            {
                return cur_node != other.cur_node;
            }
            T *operator->()
            {
                return nullptr;
            }
        };

        class iterator_postorder
        {
        public:
            TreeNode *cur_node;
            iterator_postorder(TreeNode *v) : cur_node(v){};
            iterator_postorder &operator++()
            {
                return *this;
            }
            T &operator*()
            {

                return cur_node->get_val();
            }
            bool operator!=(const iterator_postorder &other) const 
            {
                return cur_node != other.cur_node;
            }
            T *operator->()
            {
                return nullptr;
            }
        };
        BinaryTree()
        {
            root = nullptr;
        }
        BinaryTree &add_root(T val)
        {
            /*
            if (root == nullptr)
            {
                ariel::TreeNode<T> temp_nude = *(new ariel::TreeNode<T>(val, nullptr));
                root = &temp_nude;
            }
            else
            {
                root->set_val(val);
            }
            */
            return *this;
        }
        BinaryTree &add_left(T current, T left_son)
        { /*
            find = false;
            if (!edit_son(1, current, left_son, root))
            {
                throw std::invalid_argument(NOT_FOUND);
            }
            */
            return *this;
        }
        BinaryTree &add_right(T current, T right_son)
        {
            /*
            find = false;
            if (!edit_son(0, current, right_son, root))
            {
                throw std::invalid_argument(NOT_FOUND);
            }
            */
            return *this;
        }
        iterator_inorder begin()
        {
            return begin_inorder();
        }
        iterator_inorder end()
        {
            return end_inorder();
        }
        iterator_preorder begin_preorder()
        {
            return iterator_preorder{root};
        }
        iterator_preorder end_preorder()
        {
            return iterator_preorder{nullptr};
        }
        iterator_inorder begin_inorder()
        {
            return iterator_inorder{get_first_inorder(root)};
        }
        iterator_inorder end_inorder()
        {
            return iterator_inorder{nullptr};
        }
        iterator_postorder begin_postorder()
        {
            return iterator_postorder{get_first_postorder(root)};
        }
        iterator_postorder end_postorder()
        {
            return iterator_postorder{nullptr};
        }
        friend std::ostream &operator<<(std::ostream &out, BinaryTree<T> &btree)
        {
            return out;
        }

    private:
        TreeNode *root;
        bool find;
        bool edit_son(int son, T val_exist, T val_n, TreeNode *current)
        {
            if (find == true || current == nullptr)
            {
                return false;
            }
            if ((*current).get_val() == val_exist)
            {
                if (son == 1)
                {
                    (*current).add_left_child(val_n);
                }
                else
                {
                    (*current).add_right_child(val_n);
                }
                return true;
            }
            else
            {
                if (edit_son(1, val_exist, val_n, (*current).get_left()) || edit_son(0, val_exist, val_n, (*current).get_right()))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        TreeNode *get_first_inorder(TreeNode *node_cur)
        {
            if(node_cur == nullptr)
            return nullptr;
            if ((*node_cur).get_left() != nullptr)
            {
                return get_first_inorder((*node_cur).get_left());
            }
            else
            {
                return node_cur;
            }
        }
        TreeNode *get_first_postorder(TreeNode *node_cur)
        {
            if(node_cur == nullptr)
            return nullptr;
            if ((*node_cur).get_left() != nullptr)
            {
                return get_first_postorder((*node_cur).get_left());
            }
            else if ((*node_cur).get_right() != nullptr)
            {
                return get_first_postorder((*node_cur).get_right());
            }
            else
            {
                return node_cur;
            }
        }
    };

}
