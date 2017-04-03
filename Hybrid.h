#if !defined (HYBRID_H)
#define HYBRID_H

#include "QueueLinked.h"
using CSC2110::QueueLinked;

#include "SortedListDoublyLinked.h"

template < class T >
class Hybrid
{

   private:
      QueueLinked< DoubleNode<T> >* q;
      SortedListDoublyLinked<T>* sldl;

   public:
      Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item));
      ~Hybrid();

      bool isEmpty();
      void enqueue(T* item);
      T* dequeue();
      ListDoublyLinkedIterator<T>* iterator();

};

template < class T >
Hybrid<T>::Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item))
{
   q = new QueueLinked< DoubleNode<T> >();
   sldl = new SortedListDoublyLinked<T>(comp_items, comp_keys);
}

template < class T >
Hybrid<T>::~Hybrid()
{
   delete q;
   delete sldl;
}

template < class T >
ListDoublyLinkedIterator<T>* Hybrid<T>::iterator()
 {
   return sldl->iterator();
 }
  
template < class T >
bool Hybrid<T>::isEmpty()
{
	 return q->isEmpty();
}

//Complex Implementation

template < class T >
T* Hybrid<T>::dequeue()
{
   DoubleNode<T>* hold = q->dequeue();
   sldl->remove(hold);
}
template < class T >
void Hybrid<T>::enqueue(T* item) 
{
   DoubleNode<T>* box = sldl->addDN(item);
   q->enqueue(box);
}


/* //Easy Implementation

template < class T >
void Hybrid<T>::enqueue(T* item)
{
	q->enqueue(item);
	sldl->add(item);
}

template < class T >
 T* Hybrid<T>::dequeue()
{
	T* removed = q->dequeue();
   sldl->remove(removed->getKey());
} */
   
#endif
