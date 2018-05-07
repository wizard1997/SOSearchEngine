/** Owner: Addison Kimball **/

#pragma once
#include <iostream>
#include <fstream>

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
        size_t count;



        void insert(const T& dataIn, AVLNode *&nodeIn, AVLNode*& returnNode);

        void rotateWithLeftChild(AVLNode*& k2);
        void rotateWithRightChild(AVLNode*& k2);
        int checkBalance(AVLNode* nodeIn);
        void getElement(AVLNode*&, const T&,AVLNode*& returnNode);

        void deleteNode(AVLNode* nodeIn);
        void printInOrder(AVLNode*& nodeIn);
        void printFile(std::ofstream& outStream, AVLNode*& nodeIn);



    public:

        AVLTree();
        ~AVLTree();

        int height(AVLNode* node);

        T& insert(const T& dataIn);
        T& access(const T& dataIn);

        int max(const int& int1, const int& int2) const {return (int1 > int2) ? int1 : int2; }
        void printInOrder();
        void printFile(std::ofstream& outStream);

        AVLNode* getRoot() const {return root; }
        void setRoot(AVLNode* value);
        size_t getCount() const;
        void setCount(const size_t& value);
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
T& AVLTree<T>::insert(const T& dataIn) {

    AVLTree::AVLNode* temp = nullptr;
    insert(dataIn,root,temp);

    return temp->element;
}

template<class T>
T& AVLTree<T>::access(const T& dataIn) {

    AVLTree::AVLNode* current = root;
    while (current != nullptr && current->element != dataIn) {

        if(current->element > dataIn) {

            current = current->left;
        } else {

            current = current->right;
        }
    }

    if (current == nullptr) {

        std::cout << "\nThe element does not exist in the tree\n";
    } else {

        return current->element;
    }


}

template<class T>
void AVLTree<T>::printInOrder(AVLNode*& nodeIn) {

    if (nodeIn != nullptr) {

        printInOrder(nodeIn->left);
        std::cout << nodeIn->element << "  ";
        printInOrder(nodeIn->right);

    }


}

template<class T>
void AVLTree<T>::printFile(std::ofstream& outStream, AVLTree::AVLNode*& nodeIn) {

    if (nodeIn != nullptr) {

        printFile(outStream,nodeIn->left);
        outStream << nodeIn->element.getWordStr() << " ";
        for (auto& d: nodeIn->element.questionData) {


            outStream << d.second << " " << d.first << " ";

        }
        outStream << std::endl;
        printFile(outStream,nodeIn->right);

    }

}

template<class T>
void AVLTree<T>::printInOrder() {

    printInOrder(root);

}

template<class T>
void AVLTree<T>::printFile(std::ofstream& outStream) {

    printFile(outStream,root);

}

template<class T>
void AVLTree<T>::setRoot(AVLNode* value) {

    root = value;
}

template<class T>
size_t AVLTree<T>::getCount() const
{

    return count;
}

template<class T>
void AVLTree<T>::setCount(const size_t& value)
{

    count = value;
}

template<class T>
void AVLTree<T>::insert(const T& dataIn, AVLTree::AVLNode*& nodeIn, AVLNode*& returnNode) {


    if (nodeIn == nullptr) {

        nodeIn = new AVLNode(dataIn,nullptr,nullptr);
        returnNode = nodeIn;
        count++;

    } else if (dataIn < nodeIn->element) {


        insert(dataIn,nodeIn->left,returnNode);

        if (height(nodeIn->left) - height(nodeIn->right) == 2) {


            if (dataIn < nodeIn->left->element) {


                rotateWithLeftChild(nodeIn); //c1
            } else {

                rotateWithRightChild(nodeIn->left);
                rotateWithLeftChild(nodeIn);//c2
            }

        }

    } else if (nodeIn->element < dataIn) {


        insert(dataIn,nodeIn->right,returnNode);

        if (height(nodeIn->right) - height(nodeIn->left) == 2) {


            if (dataIn < nodeIn->right->element) {


                rotateWithLeftChild(nodeIn->right);
                rotateWithRightChild(nodeIn);//c3
            } else {

                rotateWithRightChild(nodeIn); //c4
            }

        }


    } else {

        returnNode = nodeIn;

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
void AVLTree<T>::getElement(AVLTree::AVLNode*& nodeIn, const T& keyIn, AVLTree::AVLNode*& returnObj) {

    if (nodeIn == nullptr) {

        return;

    } else if (keyIn < nodeIn->element) {

        getElement(nodeIn->left, keyIn, returnObj);

    } else if (keyIn > nodeIn->element) {

        getElement(nodeIn->right, keyIn, returnObj);
    } else if (keyIn == nodeIn->element) {

        returnObj = nodeIn;
        return;
    }

    return;

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
    count = 0;

}

template<class T>
AVLTree<T>::~AVLTree() {


    deleteNode(root);
}
