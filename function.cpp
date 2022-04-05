#include <iostream>
#include "function.h"

template < class T >
Node< T >::Node( T x, T y, T fence) :
x( x ), 
y( y ), 
fence( fence )
{
    this->next = nullptr;
    // do nothing
}

template < class T >
T Node< T >::compare( T x, T y )
{
    if( this->x == x && this->y == y ) {
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
    Node< long long > *pTempNode = nullptr;
    Node< long long > *pLastNode = nullptr;
    
    // exist first
    // no node in linkedlist
    if( first == nullptr ) {
        first = pNewNode;
        length += 1;
        return;
    }

    // exist first node
    pTempNode = first;
    while( pTempNode != nullptr ) {
        // same row
        if( pTempNode->y == y ) {

            if( pTempNode->x == x ) {
                // check fence
                if( pTempNode->fence == 1 || fence == 1 ) {
                    pTempNode->fence = 1;
                }

                // delete new node
                delete pNewNode;
                pNewNode = nullptr;
                return;
            }
            else if( pTempNode->x > x ) {
                // add between last and temp
                if( pTempNode == first ) {
                    pNewNode->next = pTempNode;
                    first = pNewNode;
                }
                else {
                    pNewNode->next = pTempNode; // pTemp is next node of target node
                    pLastNode->next = pNewNode;
                }
                length += 1;
                return;
            }
            else {
                // read next node
            }
        }
        else if( pTempNode->y > y ) {
            // add betwee last and temp
            if( pTempNode == first ) {
                pNewNode->next = pTempNode;
                first = pNewNode;
            }
            else {
                pNewNode->next = pTempNode; // pTemp is next node of target node
                pLastNode->next = pNewNode;
            }
            length += 1;
            return;
        }

        // read next node
        pLastNode = pTempNode;
        pTempNode = pTempNode->next;

        // last node add to tail
        if( pTempNode == nullptr ) {
            pLastNode->next = pNewNode;
            length += 1;
            return;
        }
    }
}

template < class T >
void LinkedList< T >::deletion( T x, T y )
{
    Node< long long > *pTempNode = nullptr;
    Node< long long > *pNextNode = nullptr;
    Node< long long > *pLastNode = nullptr;

    // no data in linkedlist
    if( first == nullptr ) {
        length = 0;
        return;
    }

    pTempNode = first;
    while( pTempNode != nullptr ) {

        // target node is found
        if( pTempNode->y == y && pTempNode->x == x ) {
        //if( pTempNode->compare( x, y ) == ( long long )( true ) ) {

            // check fence
            if( pTempNode->fence == 1 ) {
                return;
            }

            // replace Temp
            if( pTempNode == first ) {
                first = first->next;
            }
            else {
                pLastNode->next = pTempNode->next;
            }
            
            delete pTempNode;
            pTempNode = NULL;
            length -= 1;
            return;
        }
        // check next node
        else {
            // skip
            if( pTempNode->y > y ) {
                return;
            }
            pLastNode = pTempNode;
            pTempNode = pTempNode->next;
        }
    }
}

template < class T >
void LinkedList< T >::show()
{
    // print all node
    Node< long long > *pTempNode;
    pTempNode = first;
    while( pTempNode != nullptr ) {
        printf( "(%lld,%lld)\n", pTempNode->x, pTempNode->y );
        if( pTempNode->next == nullptr ) {
            return;
        }
        else {
            // advance one tick
            pTempNode = pTempNode->next;
        }
    }
}

template class LinkedList< long long >;

LinkedList< long long > g_Plant;

// =========================
void plant( long long x, long long y, int withFence )
{
    // insert by row, col
    g_Plant.insert( x, y, withFence );
}

void thief( long long x, long long y )
{
    long long TargetPos[ 5 ][ 2 ] = {   { x     , y - 1 },
                                        { x - 1 , y     }, { x  , y }, { x + 1, y },
                                        { x     , y + 1 } };
    for( int i = 0; i < 5; i++ ) {
        if( TargetPos[ i ][ 0 ] > -1e10 && TargetPos[ i ][ 0 ] < 1e10 &&
            TargetPos[ i ][ 1 ] > -1e10 && TargetPos[ i ][ 1 ] < 1e10 ) {
                g_Plant.deletion( TargetPos[ i ][ 0 ], TargetPos[ i ][ 1 ] );
        }
    }
}

void superThief( long long x, long long y )
{
    long long TargetPos[ 9 ][ 2 ] = {   {   x - 1, y - 1 }, { x, y - 1 }, { x + 1, y - 1 },
                                        {   x - 1, y     }, { x, y     }, { x + 1, y     },
                                        {   x - 1, y + 1 }, { x, y + 1 }, { x + 1, y + 1 } };
    for( int i = 0; i < 9; i++ ) {
        if( TargetPos[ i ][ 0 ] > -1e10 && TargetPos[ i ][ 0 ] < 1e10 &&
            TargetPos[ i ][ 1 ] > -1e10 && TargetPos[ i ][ 1 ] < 1e10 ) {
                g_Plant.deletion( TargetPos[ i ][ 0 ], TargetPos[ i ][ 1 ] );
        }
    }
}

void display()
{
    printf( "Display\n" );
    g_Plant.show();
}
