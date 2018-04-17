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


        AVLNode* insert(T dataIn, AVLNode* & nodeIn);

        void rotateWithLeftChild(AVLNode*& k2);
        void rotateWithRightChild(AVLNode*& k2);
        int checkBalance(AVLNode* nodeIn);

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

/*
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

*/

template<class T>
void AVLTree<T>::insert(T dataIn, AVLTree::AVLNode*& nodeIn) {

        if (nodeIn == nullptr) {

            nodeIn = new AVLNode
        }

        if (dataIn < nodeIn->element) {

            nodeIn->left  = insert(dataIn, nodeIn->left);
        } else if (dataIn > nodeIn->element) {

            nodeIn->right = insert(dataIn,nodeIn->right);
        } else {

            return nodeIn;
        }
        nodeIn->height = 1 + max(height(nodeIn->left),height(nodeIn->right));


        int balance = checkBalance(node);



        // LL Case c1
        if (balance > 1 && dataIn < nodeIn->left->element) {

            return rotateWithRightChild(nodeIn);
        }

        // LR Case c2
        if (balance > 1 && dataIn > nodeIn->left->element) {

            nodeIn->left =  rotateWithLeftChild(nodeIn->left);
            return rotateWithRightChild(nodeIn);
        }

        // RR Case c3
        if (balance < -1 && dataIn > nodeIn->right->element) {

            return rotateWithLeftChild(nodeIn);
        }

        // RL Case c4
        if (balance < -1 && key < node->right->key) {

            node->right = rightRotate(node->right);
            return leftRotate(node);
        }


        return node;
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

template<class T>
void AVLTree<T>::rotateWithRightChild(AVLTree::AVLNode*& k2) {

    AVLNode* k1 = k2->right;
    k2->right = k1->left; //1

    k1->left = k2;       //2

    k2->height = max(height(k2->right), height(k2->left))+1;
    k1->height = max(height(k1->right), height(k2));

    k2 = k1;


}

template<class T>
int AVLTree<T>::checkBalance(AVLTree::AVLNode* nodeIn) {

    if (nodeIn == nullptr) {

        return 0;
    }

    return height(nodeIn->left) - height(nodeIn->right);



}
