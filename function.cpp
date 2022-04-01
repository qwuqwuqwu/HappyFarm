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
    if( this->x == x && this->y == y) {
        return ( T )( true ); // true
    }
    else{
        return ( T )( false ); // false
    }
}

template class Node< long long >;

//============================================
template < class T >
LinkedList< T >::LinkedList( void ) :
first( nullptr ),
length( 0 )
{
    // do nothing
}

template < class T >
void LinkedList< T >::insert( T x, T y, T fence )
{
    Node< long long > *pNewNode = new Node< long long >( x, y, fence );
    pNewNode->next = nullptr;
    Node< long long > *pTempNode = nullptr;
    Node< long long > *pLastNode = nullptr;
    // exist first
    if( first != nullptr ) {
        pTempNode = first;
        while( pTempNode != nullptr ) {
            if( pTempNode->x == x ) {
                if( pTempNode->y == y ) {
                    // check fence
                    if( pTempNode->fence == 1 || fence == 1 ) {
                        pTempNode->fence = 1;
                        return;
                    }
                }
                else if( pTempNode->y > y ) {
                    // add between last and temp
                    pNewNode->next = pTempNode;
                    pLastNode->next = pNewNode;
                    length += 1;
                    return;
                }
                else {
                    // read next node
                }
            }
            else if( pTempNode-> x > x ) {
                // add betwee last and temp
                pNewNode->next = pTempNode;
                pLastNode->next = pNewNode;
                length += 1;
                return;
            }

            // read next node
            pLastNode = pTempNode;
            pTempNode = pTempNode->next;
            // // tail node is found
            // if( pTempNode->next == nullptr ) {
            //     pTempNode->next = pNewNode;
            //     legnth += 1;
            //     return;
            // }
            // // exist next node
            // else {
            //     pTempNode = pTempNode->next;
            // }
        }

        if( pTempNode == nullptr ) {
            // add to tail
            pLastNode->next = pNewNode;
            length += 1;
            return;
        }
    }
    // no node in linkedlist
    {
        first = pNewNode;
        length += 1;
    }
}

template < class T >
void LinkedList< T >::deletion( T x, T y )
{
    Node< long long > *pTempNode = nullptr;
    Node< long long > *pNextNode = nullptr;
    Node< long long > *pLastNode = nullptr;
    // exist first
    if( first != nullptr ) {
        pTempNode = first;
        while( pTempNode != nullptr ) {
            // target node is found
            if( pTempNode->compare( x, y ) ) {
                // check fence
                if( pTempNode->fence == 1 ) {
                    return;
                }
                pLastNode->next = pTempNode->next;
                delete pTempNode;
                pTempNode = NULL;
                length -= 1;
                return;
            }
            // exam next node
            else {
                if( pTempNode->x > x ) {
                    return;
                }
                pLastNode = pTempNode;
                pTempNode = pTempNode->next;
            }
        }
    }
    // no node in linkedlist
    {
        //assert( false );
        return;
    }
}

template < class T >
void LinkedList< T >::show()
{
    // print all node
    Node< long long > *pTempNode;
    pTempNode = first;
    while( pTempNode != nullptr ) {
        if( pTempNode->next == nullptr ) {
            printf( "(%lld,%lld)\n", pTempNode->x, pTempNode->y );
            return;
        }
        else {
            printf( "(%lld,%lld)\n", pTempNode->x, pTempNode->y );
            pTempNode = pTempNode->next;
        }
    }
}

template class LinkedList< long long >;

LinkedList< long long > g_Plant;

// =========================
void plant(long long x,long long y,int withFence)
{
    // insert by row, col
    g_Plant.insert( x, y, withFence );
}

void thief(long long x,long long y)
{
    long long TargetPos[ 5 ][ 2 ] = { { x, y - 1 }, { x - 1, y }, { x, y }, { x + 1, y }, { x, y + 1 } };
    for( int i = 0; i < 5; i++ ) {
        if( TargetPos[ i ][ 0 ] >= -1e10 && TargetPos[ i ][ 0 ] <= 1e10 &&
            TargetPos[ i ][ 1 ] >= -1e10 && TargetPos[ i ][ 1 ] <= 1e10 ) {
                g_Plant.deletion( TargetPos[ i ][ 0 ], TargetPos[ i ][ 1 ] );
        }
    }
}

void superThief(long long x,long long y)
{

}

void display()
{
    printf( "DISPLAY\n" );
    g_Plant.show();
}
