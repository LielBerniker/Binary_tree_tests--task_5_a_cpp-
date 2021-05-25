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
    class TreeNode
    {
    private:
        T val;
        TreeNode<T> *prev;
        TreeNode<T> *left;
        TreeNode<T> *right;

    public:
        TreeNode(const T &val, TreeNode<T> *prev_temp) : val(val), left(nullptr), right(nullptr), prev(prev_temp) {}
        ~TreeNode()
        {
          
            if (left != nullptr)
            {
                delete left;
            }
            if (right != nullptr)
            {
                delete right;
            }
            
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
            if (left == nullptr)
            {
                TreeNode<T>& node_n = *(new TreeNode<T>(p, this));
                left = &node_n;
            }
            else
            {
                this->left->set_val(p);
            }
        }
        void add_right_child(const T &p)
        {
            if (right == nullptr)
            {
                TreeNode<T> &node_n = *(new TreeNode<T>(p, this));
                right = &node_n;
            }
            else
            {
                this->right->set_val(p);
            }
        }
        TreeNode<T> *get_left() { return (left); }
        TreeNode<T> *get_right() { return (right); }
        TreeNode<T> *get_prev() { return (prev); }
    };
    template <typename T>
    class iterator_preorder
    {
    public:
        TreeNode<T> *cur_node;

        iterator_preorder(TreeNode<T> *v) : cur_node(v){};
        iterator_preorder &operator++()
        {
            return *this;
        }
        T &operator*()
        {
            return cur_node->get_val();
        }
        bool operator!=(iterator_preorder &other)
        {
            return cur_node != other.cur_node;
        }
    };
    template <typename T>
    class iterator_inorder
    {
    public:
        TreeNode<T> *cur_node;
        iterator_inorder(TreeNode<T> *v) : cur_node(v){};
        iterator_inorder &operator++()
        {
            return *this;
        }
        T &operator*()
        {
            return cur_node->get_val();
        }
        bool operator!=(iterator_inorder &other)
        {
            return cur_node != other.cur_node;
        }
    };
    template <typename T>
    class iterator_postorder
    {
    public:
        TreeNode<T> *cur_node;
        iterator_postorder(TreeNode<T> *v) : cur_node(v){};
        iterator_postorder &operator++()
        {
            return *this;
        }
        T &operator*()
        {
            return cur_node->get_val();
        }
        bool operator!=(iterator_postorder &other)
        {
            return cur_node != other.cur_node;
        }
    };
    template <typename T>
    class BinaryTree
    {
    private:
        TreeNode<T> *root;
        bool find;
        bool edit_son(int son, T val_exist, T val_n, TreeNode<T> current)
        {
            if (find == true)
            {
                return false;
            }
            if (current.get_val() == val_exist)
            {
                if (son == 1)
                {
                    current.add_left_child(val_n);
                }
                else
                {
                    current.add_right_child(val_n);
                }
                return true;
            }
            else
            {
                if (edit_son(1, val_exist, val_n, *current.get_left()) || edit_son(0, val_exist, val_n, *current.get_right()))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        TreeNode<T> *get_end_preorder(TreeNode<T> *node_cur)
        {
            if ((*node_cur).get_left() == nullptr && (*node_cur).get_right() == nullptr)
            {
                return node_cur;
            }
            if ((*node_cur).gTreeNode
            else
            {
                return get_end_preorder((*node_cur).get_left());
            }
        }
        TreeNode<T> *get_first_inorder(TreeNode<T> *node_cur)
        {
            if ((*node_cur).get_left() != nullptr)
            {
                return get_first_inorder((*node_cur).get_left());
            }
            else
            {
                return node_cur;
            }
        }
        TreeNode<T> *get_end_inorder(TreeNode<T> *node_cur)
        {
            if ((*node_cur).get_right() != nullptr)
            {
                return get_end_inorder((*node_cur).get_right());
            }
            else
            {
                return node_cur;
            }
        }
        TreeNode<T> *get_first_postorder(TreeNode<T> *node_cur)
        {
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

    public:
        BinaryTree()
        {
            root = nullptr;
        }
   ~ BinaryTree()
   {
       if(root != nullptr)
       {
           delete root;
       }
   }
        BinaryTree<T> add_root(T val)
        {
            if (root == nullptr)
            {
                TreeNode<T>&temp_nude = *(new TreeNode<T>(val, nullptr));
                root = temp_nude;
            }
            else
            {
                root->set_val(val);
            }
            return *this;
        }
        BinaryTree<T> add_left(T current, T left_son)
        {
            find = false;
            if (!edit_son(1, current, left_son, *root))
            {
                throw std::invalid_argument(NOT_FOUND);
            }
            return *this;
        }
        BinaryTree<T> add_right(T current, T right_son)
        {
            find = false;
            if (!edit_son(0, current, right_son, *root))
            {
                throw std::invalid_argument(NOT_FOUND);
            }
            return *this;
        }
        iterator_inorder<T> &begin()
        {
            return begin_inorder();
        }
        iterator_inorder<T> &end()
        {
            return end_inorder();
        }
        iterator_preorder<T> &begin_preorder()
        {
            iterator_preorder<T> &iter = *(new iterator_preorder<T>(root));
            return iter;
        }
        iterator_preorder<T> &end_preorder()
        {
            iterator_preorder<T> &iter = *(new iterator_preorder<T>(get_end_preorder(root)));
            return iter;
        }
        iterator_inorder<T> &begin_inorder()
        {
            iterator_inorder<T> &iter = *(new iterator_inorder<T>(get_first_inorder(root)));
            return iter;
        }
        iterator_inorder<T> &end_inorder()
        {
            iterator_inorder<T> &iter = *(new iterator_inorder<T>(get_end_inorder(root)));
            return iter;
        }
        iterator_postorder<T> &begin_postorder()
        {
            iterator_postorder<T> &iter = *(new iterator_postorder<T>(get_first_postorder(root)));
            return iter;
        }
        iterator_postorder<T> &end_postorder()
        {
            iterator_postorder<T> &iter = *(new iterator_postorder<T>(root));
            return iter;
        }
        friend std::ostream &operator<<(std::ostream &out, BinaryTree<T> &btree)
        {
            return out;
        }
    };

}
