#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  void heapify(int idx);
  void trickleUp(int idx);
  
  PComparator comparison;
  std::vector<T> items_;
  int dary;



};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{
  comparison = c;
  dary = m;
}
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{
}
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int idx)
{
	// Takes last node puts it in the top location and then recursively swaps it until it is in its right place

  // ensure enough children
	if ((int)size() <= 1 + (idx * dary))
	{
		return;
	}
	// start with first child
	int firstChild = 1 + (idx * dary);
	// essentially right child or exists if there's more children than 2
	int betweenChild = firstChild;

	// compare to its siblings
	for (int j = 1; j < dary; j++)
	{
		if (betweenChild + j < (int)size() && comparison(items_[betweenChild + j], items_[firstChild]))
		{
			firstChild = betweenChild + j;
		}
	}
	
	if (comparison(items_[firstChild], items_[idx]))
	{
		std::swap(items_[idx], items_[firstChild]);
		heapify(firstChild);
	} 
}
template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc)
{
	int parent = (loc - 1) / dary;
	while(parent >= 0 && comparison(items_[loc], items_[parent]))
	{ 
		std::swap(items_[parent], items_[loc]);
		loc = parent;
		if(parent == 0) // parent is at the top
  	{
    	return;
  	}
		else
		{
			parent = (loc - 1) / dary;
		}
	}
}
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  items_.push_back(item);
  trickleUp(size() - 1);
}
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  if (items_.empty())
  {
    return true;
  }
  return false;
}
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
	return items_.size();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Nothing at the top!");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return items_.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Nothing to pop!");
  }
  std::swap(items_.front(),items_.back());
  items_.pop_back();
  heapify(0);
}



#endif

