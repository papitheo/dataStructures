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

// Kofi:: (::) is need to resolve the scope
// (kofi::myVector<ItemType>&) represents the type being returned and 
// (kofi::myVector<ItemType>) represents the class 
// (operator=(const myVector<ItemType>& otherVector)) is in.
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

template <typename ItemType>
ItemType& kofi::myVector<ItemType>::operator[](sizeType index){
    // Here (index < 0) is unnecessary because index is size_t which is 
    // unsigned
    if(index < 0 || index >= numOfItems){
        throw std::out_of_range ("index to operator[] is out of range");
    }
    
    return items[index];
}

template <typename ItemType>
const ItemType& kofi::myVector<ItemType>::operator[]
( sizeType index)const{
    if(index >= numOfItems){
        throw std::out_of_range("index to operator[] is out of range");
    }

    return items[index];
}

template <typename ItemType>
ItemType& kofi::myVector<ItemType>::at(sizeType index){
    if(index >= numOfItems){
        throw std::out_of_range("index to at() is out of range");
    }

    return items[index];
}

template <typename ItemType>
const ItemType& kofi::myVector<ItemType>::at(sizeType index) const {
    if(index >= numOfItems){
        throw std::out_of_range("index to at() is out of range");
    }

    return items[index];
}

template <typename ItemType>
void kofi::myVector<ItemType>::reSize(sizeType newSize){

    if(newSize < numOfItems){
        numOfItems = newSize;
    }

    else {

        if(newSize > currentCapacity){
            ItemType* newVector = new ItemType[newSize];

            for(int i=0; i<numOfItems; i++){
                newVector[i] = items[i];
            }
            
            delete[] items;
            items = newVector;
            currentCapacity = newSize;
        }

        
        for(int i=numOfItems; i<newSize; i++){
            items[i] = ItemType();
        }
        
        numOfItems = newSize;
    }

}

template <typename ItemType>
void kofi::myVector<ItemType>::reSize(sizeType newSize, ItemType value){
    if(newSize < numOfItems){
        numOfItems = newSize;  
    }
    else if(newSize > numOfItems){
        if(newSize > currentCapacity){
            ItemType* newItems = new ItemType[newSize];
            for(int i=0; i<numOfItems; i++){
                newItems[i] = items[i];
            }
            delete[] items;
            items = newItems;
            currentCapacity = newSize;
        }


        for(int i=numOfItems; i<newSize; i++){
            items[i] = value;
        }
        numOfItems = newSize;
    }
   
}