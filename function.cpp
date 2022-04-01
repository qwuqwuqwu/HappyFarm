#include <iostream>
#include "function.h"

template <class T>
Node< T >::Node(T x,T y,T fence) :
x( x ), 
y( y ), 
fence( fence )
{
    // do nothing
}

template <class T>
T Node< T >::compare( T x,T y )
{

}

//============================================
template < class T >
LinkedList< T >::LinkedList( void ) :
first( nullptr ),
length( 0 )
{
    // do nothing
}

template class Node< int >;

template < class T >
void LinkedList< T >::insert( T x, T y, T fence )
{
    Node< int > NewNode( x, y, fence );
    Node< int > *pTempNode = nullptr;
    // exist first
    if( first ) {
        pTempNode = first;
        while( pTempNode != nullptr ) {
            // tail node is found
            if( pTempNode->next == nullptr ) {
                pTempNode->next = NewNode;
            }
            // exist next node
            else {
                pTempNode = pTempNode->next;
            }
        }
    }
    // no node in linkedlist
    {
        first = NewNode;
    }
}

template < class T >
void LinkedList< T >::deletion( T x, T y )
{
    Node< int > *pTempNode = nullptr;
    Node< int > *pNextNode = nullptr;
    Node< int > *pLastNode = nullptr;
    // exist first
    if( first ) {
        pTempNode = first;
        while( pTempNode != nullptr ) {
            // target node is found
            if( pTempNode->compare( x, y ) ) {
                pNextNode = pTempNode->next;
                pLastNode->next = pTempNode;
                return;
            }
            // exam next node
            else {
                pLastNode = pTempNode;
                pTempNode = pTempNode->next;
            }
        }
    }
    // no node in linkedlist
    {
        assert( false );
        return;
    }
}

template < class T >
void LinkedList< T >::show()
{

}

template class LinkedList< int >;

// =========================
void plant(long long x,long long y,int withFence)
{

}

void thief(long long x,long long y)
{

}

void superThief(long long x,long long y)
{

}

void display()
{

}
