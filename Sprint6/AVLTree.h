#pragma once
#include <iostream>

template<class T>
class AVLTree {

    private:

        class AVLNode {

            public:

                T element;
                AVLNode* left;
                AVLNode* right;
                int height;

                AVLNode(const T& data, AVLNode* leftTree = nullptr, AVLNode* rightTree = nullptr, int h = 0)
                    : element(data), left(leftTree), right(rightTree), height(h) {}

        };

        AVLNode* root;



        void insert(const T& dataIn, AVLNode *&nodeIn, AVLNode*& refNode);

        void rotateWithLeftChild(AVLNode*& k2);
        void rotateWithRightChild(AVLNode*& k2);
        int checkBalance(AVLNode* nodeIn);
        T& getWord(T);

        void deleteNode(AVLNode* nodeIn);
        void printInOrder(AVLNode* nodeIn);


    public:

        AVLTree();
        ~AVLTree();

        int height(AVLNode* node);

        T* insert(const T& dataIn);

        int max(const int& int1, const int& int2) const {return (int1 > int2) ? int1 : int2; }
        void printInOrder();


        AVLNode* getRoot() const {return root; }
        void setRoot(AVLNode* value);
};

template<class T>
int AVLTree<T>::height(AVLTree::AVLNode* nodeIn) {


    if (nodeIn == nullptr) {

        return -1;
    } else {


        return nodeIn->height;
    }

}

template<class T>
T* AVLTree<T>::insert(const T& dataIn) {

    AVLTree::AVLNode* refNode;
    insert(dataIn,root,refNode);
    return &refNode->element;
}

template<class T>
void AVLTree<T>::printInOrder(AVLNode* nodeIn) {

    if (nodeIn != nullptr) {

        printInOrder(nodeIn->left);
        std::cout << nodeIn->element << "  ";
        printInOrder(nodeIn->right);

    }


}

template<class T>
void AVLTree<T>::printInOrder() {

    printInOrder(root);

}

template<class T>
void AVLTree<T>::setRoot(AVLNode* value) {

    root = value;
}

template<class T>
void AVLTree<T>::insert(const T& dataIn, AVLTree::AVLNode*& nodeIn, AVLTree::AVLNode*& refNode) {


    if (nodeIn == nullptr) {

        nodeIn = new AVLNode(dataIn,nullptr,nullptr);
        refNode = nodeIn;

    } else if (dataIn < nodeIn->element) {


        insert(dataIn,nodeIn->left,refNode);

        if (height(nodeIn->left) - height(nodeIn->right) == 2) {


            if (dataIn < nodeIn->left->element) {


                rotateWithLeftChild(nodeIn); //c1
            } else {

                rotateWithRightChild(nodeIn->left);
                rotateWithLeftChild(nodeIn);//c2
            }

        }

    } else if (nodeIn->element < dataIn) {


        insert(dataIn,nodeIn->right,refNode);

        if (height(nodeIn->right) - height(nodeIn->left) == 2) {


            if (dataIn < nodeIn->right->element) {


                rotateWithLeftChild(nodeIn->right);
                rotateWithRightChild(nodeIn);//c3
            } else {

                rotateWithRightChild(nodeIn); //c4
            }

        }


    } else {

        //std::cout << ".";

    }

    nodeIn->height = (max(height(nodeIn->left),height(nodeIn->right))) + 1;

}




template<class T>
void AVLTree<T>::rotateWithLeftChild(AVLTree::AVLNode*& k2) {

    AVLNode* k1 = k2->left;
    k2->left = k1->right; //1

    k1->right = k2;       //2

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;

    k2 = k1;


}

template<class T>
void AVLTree<T>::rotateWithRightChild(AVLTree::AVLNode*& k2) {

    AVLNode* k1 = k2->right;
    k2->right = k1->left; //1

    k1->left = k2;       //2

    k2->height = max(height(k2->right), height(k2->left)) + 1;
    k1->height = max(height(k1->right), k2->height) + 1;

    k2 = k1;


}

template<class T>
int AVLTree<T>::checkBalance(AVLTree::AVLNode* nodeIn) {

    if (nodeIn == nullptr) {

        return 0;
    }

    return height(nodeIn->left) - height(nodeIn->right);



}

template<class T>
void AVLTree<T> :: deleteNode(AVLTree::AVLNode* nodeIn) {


  if (nodeIn != nullptr) {

    deleteNode(nodeIn->left);
    deleteNode(nodeIn->right);

    delete nodeIn;
  }


}

template<class T>
AVLTree<T>::AVLTree() {

    root = nullptr;

}

template<class T>
AVLTree<T>::~AVLTree() {


    deleteNode(root);
}
