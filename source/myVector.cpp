#include "../header/myVector.h"

// Because we have the template signature (template <typename ItemType>)
// in our header file, the template signature in this cpp file must also
// be the same
template <typename ItemType>
kofi::myVector<ItemType>::myVector():currentCapacity(INITIAL_CAPACITY), 
    numberOfItems(0), items(new ItemType[INITIAL_CAPACITY]){}

template <typename ItemType>
kofi::myVector<ItemType>::myVector(const myVector& otherVector):
// member initialization list (only valid for constructors)
currentCapacity(otherVector.currentCapacity), 
numOfItems(otherVector.numOfItems), 
items(new ItemType[otherVector.currentCapacity]){
    for(int i=0; i<numOfItems; i++){
        items[i] = otherVector.items[i];
    }
}

template<typename ItemTtype>
kofi::myVector<ItemTtype>::~myVector(){
    delete[] items;
}

template <typename ItemType>
kofi::myVector<ItemType>& kofi::myVector<ItemType>::
    operator=(const myVector<ItemType>& otherVector){
//References are not addresses, they are alias. Pointers are adresses. So 
// to do the comparison, you need to preceed otherVector with &
        if(this == &otherVector){
            return *this;
        }

        delete[] items;

        currentCapacity = otherVector.currentCapacity;
        numOfItems = otherVector.numOfItems;
        items = new ItemType[otherVector.currentCapacity];

        for(int i=0; i<numOfItems; i++){
            items[i] = otherVector.items[i];
        }

        return *this;
    }