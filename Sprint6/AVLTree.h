#pragma once

template<class T>
class AVLTree {

    private:

        class AVLNode {

            public:

                T element;
                AVLNode* left;
                AVLNode* right;
                int height;

                AVLNode(T& data, AVLNode* leftTree, AVLNode* rightTree, int h = 0)
                    : element(data), left(leftTree), right(rightTree), height(h) {}

        };

        AVLNode* root;


        void insert(int x, AVLNode* & t);

        void rotateWithLeftChild(AVLNode*& k2);
        void rotateWithRightChild(AVLNode*& k2);

    public:

        int height(AVLNode* node);

        int max(const int& int1, const int& int2) {return a > b ? a : b; }


};

template<class T>
int AVLTree<T>::height(AVLTree::AVLNode* node) {


    if (node == nullptr) {

        return -1;
    } else {


        return node->height;
    }

}

template<class T>
void AVLTree<T>::insert(int x, AVLTree::AVLNode*& t) {


    if (t == nullptr) {

        t = new AVLNode(x,nullptr,nullptr);
    } else if (t < t->element) {


        insert(x,t->left);

        if (height(t->left) - height(t->right) == 2) {


            if (x < t->left->element) {


                rotateWithLeftChild(t); //c1
            } else {

                rotateWithRightChild(t); //c2
            }

        }


    } else if (t->element < x) {


        insert(x,t->right);

        if (height(t->right) - height(t->left) == 2) {


            if (x < t->right->element) {


                rotateWithRightChild(t); //c4
            } else {

                rotateWithLeftChild(t); //c3
            }

        }


    } else ;

    t->height = max(height(t->left),height(t->right));

}

template<class T>
void AVLTree<T>::rotateWithLeftChild(AVLTree::AVLNode*& k2) {

    AVLNode* k1 = k2->left;
    k2->left = k1->right; //1

    k1->right = k2;       //2

    k2->height = max(height(k2->left), height(k2->right))+1;
    k1->height = max(height(k1->left), height(k2));

    k2 = k1;





}
