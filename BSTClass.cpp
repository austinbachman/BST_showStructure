// Program Information ////////////////////////////////////////////////////////
/**
 * @file BSTClass.cpp
 *
 * @brief Implementation file for BSTClass
 * 
 * @details Implements all member methods of the BSTClass
 *
 * @version 1.1
 *          Austin Bachman (12 March 2016)
 *          Updated with showBSTStructure
 *
 *          1.0
 *          Austin Bachman (6 March 2016)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef BST_CLASS_CPP
#define BST_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include "BSTClass.h"

using namespace std;

static const char EMPTY_STR[4] = "---";

/**
 * @brief Initialization BSTNode constructor
 *
 * @details Constructs BSTNode with input values
 *          
 * @pre assumes Uninitialized BSTNode object
 *
 * @post BSTNode object is initialized with input values
 *
 * @par Algorithm 
 *      Calls initializers on member data
 * 
 * @exception None
 *
 * @param [in] nodeData
 *             DataType item to be stored
 *
 * @param [in] leftPtr
 *             Pointer to left child node
 *
 * @param [in] rightPtr
 *             Pointer to right child node
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
BSTNode<DataType>::BSTNode
   (
    const DataType &nodeData,     // input: data to be stored
    BSTNode *leftPtr,             // input: pointer to left child
    BSTNode *rightPtr             // input: pointer to right child
   )
       : dataItem( nodeData ),
         left( leftPtr ),
         right( rightPtr )
{
    // Initializers used
}

/**
 * @brief BSTClass default constructor
 *
 * @details Constructs BSTClass object
 *          
 * @pre assumes Uninitialized BSTClass object
 *
 * @post Empty BSTClass object is initialized
 *
 * @par Algorithm 
 *      Initializes rootNode to NULL
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
BSTClass<DataType>::BSTClass
   (
    // no parameters
   )
       : rootNode( NULL )
{
    // Initializer used
}

/**
 * @brief Copy BSTClass constructor
 *
 * @details Constructs BSTClass as copy of input
 *          
 * @pre assumes Uninitialized BSTClass object
 *
 * @post BSTClass object is initialized as copy
 *
 * @par Algorithm 
 *      Calls copyTree method
 * 
 * @exception None
 *
 * @param [in] copied
 *             BSTClass object to be copied
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
BSTClass<DataType>::BSTClass
   (
    const BSTClass<DataType> &copied     // input: object to be copied
   )
       : rootNode( NULL )
{
    copyTree( rootNode, copied.rootNode );
}

/**
 * @brief BSTClass destructor
 *
 * @details Destructs BSTClass object
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post BSTClass object is freed
 *
 * @par Algorithm 
 *      Calls clear method
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
BSTClass<DataType>::~BSTClass
   (
    // no parameters
   )
{
    clear();
}

/**
 * @brief BSTClass assignment operator
 *
 * @details Assigns BSTClass as copy of input
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post BSTClass object is a copy
 *
 * @par Algorithm 
 *      Calls copyTree method after clearing
 * 
 * @exception None
 *
 * @param [in] rhData
 *             BSTClass object to be copied
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
const BSTClass<DataType>& BSTClass<DataType>::operator =
   (
    const BSTClass<DataType> &rhData     // input: object to be copied
   )
{
    if( this != &rhData )
    {
        clear();
        copyTree( rootNode, rhData.rootNode );
    }

    return *this;
}

/**
 * @brief Clear method
 *
 * @details Clears all data in object
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post BSTClass object is empty
 *
 * @par Algorithm 
 *      Calls clearHelper method
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
void BSTClass<DataType>::clear
   (
    // no parameters
   )
{
    clearHelper( rootNode );
    rootNode = NULL;
}

/**
 * @brief Insert method
 *
 * @details Inserts data in object
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post newData is inserted into object
 *
 * @par Algorithm 
 *      Calls insertHelper method
 * 
 * @exception None
 *
 * @param [in] newData
 *             Data to be inserted
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
void BSTClass<DataType>::insert
   (
    const DataType &newData     // input: data to be inserted
   )
{
    insertHelper( rootNode, newData );
}

/**
 * @brief Find method
 *
 * @details Finds data in object
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post Know if data exists in BST
 *
 * @par Algorithm 
 *      Calls findHelper method
 * 
 * @exception None
 *
 * @param [in] searchDataItem
 *             Data to be searched for
 *
 * @return Bool with true for success
 *
 * @note None
 */
template <class DataType>
bool BSTClass<DataType>::find
   (
    DataType &searchDataItem     // input: data to be searched for
   ) const
{
    return findHelper( rootNode, searchDataItem );
}

/**
 * @brief Remove method
 *
 * @details Removes data from object
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post Data is removed from BST
 *
 * @par Algorithm 
 *      Calls removeHelper method
 * 
 * @exception None
 *
 * @param [in] dataItem
 *             Data to be removed
 *
 * @return Bool with true for success
 *
 * @note None
 */
template <class DataType>
bool BSTClass<DataType>::remove
   (
    const DataType &dataItem     // input: data to be removed
   )
{
    if( !isEmpty() )
    {
        return removeHelper(rootNode, dataItem);
    }

    return false;
}

/**
 * @brief isEmpty method
 *
 * @details Checks if object is empty
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post Know if BST is empty
 *
 * @par Algorithm 
 *      Checks if rootNode is NULL
 * 
 * @exception None
 *
 * @param None
 *
 * @return Bool with true if empty
 *
 * @note None
 */
template <class DataType>
bool BSTClass<DataType>::isEmpty
   (
    // no parameters
   ) const
{
    return ( rootNode == NULL );
}

/**
 * @brief Preorder Traversal
 *
 * @details Outputs list in pre-order
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post Data in BST has been output to screen
 *
 * @par Algorithm 
 *      Calls preOrderTraversalHelper method
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
void BSTClass<DataType>::preOrderTraversal
   (
    // no parameters
   ) const
{
    if( isEmpty() )
    {
        cout << "Tree is empty" << endl;
    }

    else
    {
        preOrderTraversalHelper( rootNode );
        cout << endl;   
    }
}

/**
 * @brief Inorder Traversal
 *
 * @details Outputs list in order
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post Data in BST has been output to screen
 *
 * @par Algorithm 
 *      Calls inOrderTraversalHelper method
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
void BSTClass<DataType>::inOrderTraversal
   (
    // no parameters
   ) const
{
    if( isEmpty() )
    {
        cout << "Tree is empty" << endl;
    }

    else
    {
        inOrderTraversalHelper( rootNode ); 
        cout << endl;  
    }
}

/**
 * @brief Postorder Traversal
 *
 * @details Outputs list in post-order
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post Data in BST has been output to screen
 *
 * @par Algorithm 
 *      Calls postOrderTraversalHelper method
 * 
 * @exception None
 *
 * @param None
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
void BSTClass<DataType>::postOrderTraversal
   (
    // no parameters
   ) const
{
    if( isEmpty() )
    {
        cout << "Tree is empty" << endl;
    }

    else
    {
        postOrderTraversalHelper( rootNode ); 
        cout << endl; 
    }
}

/**
 * @brief BSTClass copy method
 *
 * @details Assigns BSTClass as copy of input
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post BSTClass object is a copy
 *
 * @par Algorithm 
 *      Moves down through tree, creating new nodes and
 *      copying data from parameter tree
 * 
 * @exception None
 *
 * @param [in] workingPtr
 *             BSTClass object to be copied into
 *
 * @param [in] sourcePtr
 *             BSTClass object to be copied from
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
void BSTClass<DataType>::copyTree
   (
    BSTNode<DataType> *&workingPtr,        // input: tree to be assigned
    const BSTNode<DataType> *sourcePtr     // input: tree to be copied
   )
{
    if( sourcePtr != NULL )
    {
        workingPtr = new BSTNode<DataType>( sourcePtr->dataItem, NULL, NULL );
        copyTree( workingPtr->left, sourcePtr->left );
        copyTree( workingPtr->right, sourcePtr->right );
    }
}

/**
 * @brief Clear helper method
 *
 * @details Clears all data in object
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post BSTClass object is empty
 *
 * @par Algorithm 
 *      Recursed through nodes, freeing memory
 * 
 * @exception None
 *
 * @param [in] workingPtr
 *             node to be cleared
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
void BSTClass<DataType>::clearHelper
   (
    BSTNode<DataType> *workingPtr     // input: node to be freed
   )
{
    if( workingPtr != NULL )
    {
        clearHelper( workingPtr->left );
        clearHelper( workingPtr->right );

        delete workingPtr;
        workingPtr = NULL;
    }
}

/**
 * @brief Insert helper method
 *
 * @details Inserts data in object
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post newData is inserted into object
 *
 * @par Algorithm 
 *      Analyzes data in nodes, then either recurses
 *      or inserts to left or right
 * 
 * @exception None
 *
 * @param [in] workingPtr
 *             node to be analyzed
 *
 * @param [in] newData
 *             Data to be inserted
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
void BSTClass<DataType>::insertHelper
   (
    BSTNode<DataType> *&workingPtr,     // input: node to be checked
    const DataType &newData             // input: data to be inserted
   )
{
    if( workingPtr == NULL )
    {
        workingPtr = new BSTNode<DataType>( newData, NULL, NULL );
        return;
    }

    else
    {
        if ( newData.compareTo(workingPtr->dataItem) == 0 )
        {
            return;
        }

        else if ( newData.compareTo(workingPtr->dataItem) < 0 )
        {
            if( workingPtr->left == NULL )
            {
                workingPtr->left = new BSTNode<DataType>( newData, NULL, NULL );
                return;
            }

            else
            {
                insertHelper( workingPtr->left, newData );
            }
        }

        else if ( newData.compareTo(workingPtr->dataItem) > 0 )
        {
            if( workingPtr->right == NULL )
            {
                workingPtr->right = new BSTNode<DataType>( newData, NULL, NULL );
                return;
            }

            else
            {
                insertHelper( workingPtr->right, newData );
            }
        }
    }

    return;
}

/**
 * @brief Find helper method
 *
 * @details Finds data in object
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post Know if data exists in BST
 *
 * @par Algorithm 
 *      Recurses through tree, comparing data to input
 * 
 * @exception None
 *
 * @param [in] workingPtr
 *             Node to be checked
 *
 * @param [in] searchDataItem
 *             Data to be searched for
 *
 * @return Bool with true for success
 *
 * @note None
 */
template <class DataType>
bool BSTClass<DataType>::findHelper
   (
    BSTNode<DataType> *workingPtr,     // input: node to be checked
    DataType &searchDataItem           // input: data to be searched for
   ) const
{
    if( workingPtr != NULL )
    {
        if( searchDataItem.compareTo(workingPtr->dataItem) == 0 )
        {
            return true;
        }

        else if( searchDataItem.compareTo(workingPtr->dataItem) < 0 )
        {
            return findHelper( workingPtr->left, searchDataItem );
        }

        else if( searchDataItem.compareTo(workingPtr->dataItem) > 0 )
        {
            return findHelper( workingPtr->right, searchDataItem );
        }        
    }

    return false;
}

/**
 * @brief Remove helper method
 *
 * @details Removes data from object
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post Data is removed from BST
 *
 * @par Algorithm 
 *      Checks for number of children of node, then either removes data,
 *      recurses, or both, depending on 0, 1, or 2 children
 * 
 * @exception None
 *
 * @param [in] workingPtr
 *             Node to be checked
 *
 * @param [in] removeDataItem
 *             Data to be removed
 *
 * @return Bool with true for success
 *
 * @note None
 */
template <class DataType>
bool BSTClass<DataType>::removeHelper
   (
    BSTNode<DataType> *&workingPtr,    // input: node to be checked
    const DataType &removeDataItem     // input: data to be removed
   )
{
    BSTNode<DataType>* tmp = NULL;
    if( workingPtr->dataItem.compareTo(removeDataItem) == 0 )
    {
        if( workingPtr->left == NULL && workingPtr->right == NULL )
        {
            delete workingPtr;
            workingPtr = NULL;
            return true;
        }

        else if( workingPtr->left == NULL)
        {
            tmp = workingPtr;
            workingPtr = workingPtr->right;
            delete tmp;
            tmp = NULL;
            return true;
        }

        else if( workingPtr->right == NULL)
        {
            tmp = workingPtr;
            workingPtr = workingPtr->left;
            delete tmp;
            tmp = NULL;
            return true;
        }

        else
        {
            tmp = workingPtr->left;
            while(tmp->right != NULL)
            {
                tmp = tmp->right;
            }
            workingPtr->dataItem = tmp->dataItem;
            return removeHelper( workingPtr->left, tmp->dataItem );
        }
        
        return false;
    }

    else if( workingPtr->dataItem.compareTo(removeDataItem) > 0 )
    {
        return removeHelper( workingPtr->left, removeDataItem );
    }

    else
    {
        return removeHelper( workingPtr->right, removeDataItem );
    }
}

/**
 * @brief Preorder Traversal helper
 *
 * @details Outputs list in pre-order
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post Data in BST has been output to screen
 *
 * @par Algorithm 
 *      Traverses tree recursively in preorder
 * 
 * @exception None
 *
 * @param [in] workingPtr
 *             node to be output and recursed on
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
void BSTClass<DataType>::preOrderTraversalHelper
   (
    BSTNode<DataType> *workingPtr     // input: node to be output
   ) const
{
    char string[ STD_STR_LEN ];
    if( workingPtr != NULL )
    {
        workingPtr->dataItem.toString(string);
        cout << string << endl;
        preOrderTraversalHelper( workingPtr->left );
        preOrderTraversalHelper( workingPtr->right );
    }
}

/**
 * @brief Inorder Traversal helper
 *
 * @details Outputs list in order
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post Data in BST has been output to screen
 *
 * @par Algorithm 
 *      Traverses tree recursively in order
 * 
 * @exception None
 *
 * @param [in] workingPtr
 *             node to be output and recursed on
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
void BSTClass<DataType>::inOrderTraversalHelper
   (
    BSTNode<DataType> *workingPtr     // input: node to be output
   ) const
{
    char string[ STD_STR_LEN ];
    if( workingPtr != NULL )
    {
        workingPtr->dataItem.toString(string);
        inOrderTraversalHelper( workingPtr->left );
        cout << string << endl;
        inOrderTraversalHelper( workingPtr->right );
    }  
}

/**
 * @brief Postorder Traversal helper
 *
 * @details Outputs list in post-order
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post Data in BST has been output to screen
 *
 * @par Algorithm 
 *      Traverses tree recursively in postorder
 * 
 * @exception None
 *
 * @param [in] workingPtr
 *             node to be output and recursed on
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
void BSTClass<DataType>::postOrderTraversalHelper
   (
    BSTNode<DataType> *workingPtr     // input: node to be output
   ) const
{
    char string[ STD_STR_LEN ];
    if( workingPtr != NULL )
    {
        workingPtr->dataItem.toString(string);
        postOrderTraversalHelper( workingPtr->left );
        postOrderTraversalHelper( workingPtr->right );
        cout << string << endl;
    }
}

/**
 * @brief get height of node
 *
 * @details returns height of node from lowest leaf
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post Height of node has been returned
 *
 * @par Algorithm 
 *      Compares left and right heights and recursively adds
 * 
 * @exception None
 *
 * @param [in] workintPtr
 *             node to find height of
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
int BSTClass<DataType>::getHeight
   (
    BSTNode<DataType> *workingPtr     // input: node to find height of
   )
{
    int leftH, rightH;

    if( workingPtr == NULL )
    {
        return 0;
    }

    leftH = getHeight( workingPtr->left );
    rightH = getHeight( workingPtr->right );

    if( rightH > leftH )
    {
        return rightH + 1;
    }

    else
    {
        return leftH + 1;
    }
}

/**
 * @brief show BST structure helper
 *
 * @details Displays structure of BST
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post Data in BST has been output to screen
 *
 * @par Algorithm 
 *      if node is in correct row, displays spaces before data
 *      based on row #, then outputs node data
 * 
 * @exception None
 *
 * @param [in] workingPtr
 *             pointer to node to be tested and displayed
 *
 * @param [in] callerHeight
 *             height of row being printed
 *
 * @param [in] thisHeight
 *             height of workingPtr node
 *
 * @param [in] leftMost
 *             bool denoting if farthest left item of row
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
void BSTClass<DataType>::structureHelper
   (
    BSTNode<DataType> *workingPtr,     // input: node to print
    int callerHeight,                  // input: height of row to pring
    int thisHeight,                    // input: height of current node
    bool leftMost                      // input: node left most of row
   )
{
    char string[ STD_STR_LEN ];
    int numStartSpaces = pow( 2, thisHeight ) - 1;
    int numSepSpaces = pow( 2, thisHeight + 1 ) - 3;
    int index = 0;


    if( callerHeight == thisHeight )
    {
        if( leftMost == true )
        { 
            for( ; index < numStartSpaces; index++ )
            {
                cout << ' ';
            }
        }

        else
        {
            for( ; index < numSepSpaces; index++ )
            {
                cout << ' ';
            }
        }

        if( workingPtr != NULL )
        {
            workingPtr->dataItem.toString( string );
            cout << string;
        }

        else
        {
            cout << EMPTY_STR;
        }
    }

    if( thisHeight > 1 )
    {
        if( workingPtr != NULL )
        {
            structureHelper( workingPtr->left, callerHeight, thisHeight-1, leftMost );
            structureHelper( workingPtr->right, callerHeight, thisHeight-1, false );
        }  

        else
        {
            structureHelper( NULL, callerHeight, thisHeight-1, leftMost );
            structureHelper( NULL, callerHeight, thisHeight-1, false );            
        }
    }

}

/**
 * @brief show BST structure
 *
 * @details Displays structure of BST
 *          
 * @pre assumes Initialized BSTClass object
 *
 * @post Data in BST has been output to screen
 *
 * @par Algorithm 
 *      Calls structureHelper method height times
 * 
 * @exception None
 *
 * @param [in] ID
 *             char to denote ID of tree being displayed
 *
 * @return None
 *
 * @note None
 */
template <class DataType>
void BSTClass<DataType>::showBSTStructure
   (
    char ID     // input: id of tree to show
   )
{
    int height = getHeight( rootNode );
    int max = height;

    cout << "BST ID " << ID << ":" << endl;

    for(  ; height > 0; height-- )
    {
        structureHelper( rootNode, height, max, true );
        cout << endl;
    }

    cout << endl;
}


#endif  // define BST_CLASS_CPP