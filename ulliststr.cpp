#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val) {
  if (tail_ == nullptr) {
    tail_ = new Item();
    head_ = tail_;
  }

  if(tail_->last == ARRSIZE) {
    Item* temp = new Item();
    temp->prev = tail_;
    tail_->next = temp;
    tail_ = temp;
  }

  size_t index = tail_->last;
  tail_->val[index] = val;
  tail_->last++;
  size_++;
}

void ULListStr::pop_back(){
  if (tail_ == nullptr) {
    return;
  }
  if (size_ == 0) {
    return;
  }

  tail_->last--;

  if(tail_->last == tail_->first) { /*idk if there's a better way to do this
  i'm assuming b/c first is inclusive and last is exclusive this is the best
   expression for the if statement*/
    Item* temp = tail_;
    tail_ = tail_->prev;
    if (tail_ != nullptr) {
      tail_->next = nullptr;
    }
    else {
      head_ = nullptr;
    }
    delete temp;

  }
  size_--;
}

void ULListStr::pop_front() {
  if (size_ == 0) {
    return;
  }

  head_->first++;

  if (head_->first == head_->last) {
    Item* temp = head_;
    head_ = head_->next;
    if (head_ != nullptr) {
      head_->prev = nullptr;
    }
    else {
      tail_ = nullptr;
    }
    delete temp;
  }
  size_--;
}


void ULListStr::push_front(const std::string& val){
  if (head_ == nullptr) {
    head_ = tail_ = new Item();
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
  }

  else if (head_->first == 0) {
    Item* temp = new Item();

    temp->next = head_;
    head_->prev = temp;
    head_ = temp;
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;


  }

  head_->first--;
  size_t index = head_->first;
  head_->val[index] = val;
  size_++;
}

std::string const & ULListStr::back() const {

  size_t index = tail_->last - 1;
  return tail_->val[index];

}

std::string const & ULListStr::front() const {


  size_t index = head_->first;
  return head_->val[index];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) {
    return nullptr;
  }

  Item* temp = head_;
  while(temp != nullptr) {
    size_t diff = temp->last - temp->first; /* trying to iterate through nodes until i get to the 
    one that loc lies in */
    if(loc < diff) { // seeing if loc is in this node
      size_t index = temp->first + loc; //since the node starts at first adding loc to first to get the index
      return &temp->val[index];
    }
    else {
      loc -= diff;
      temp = temp->next;
    }
  }
  return nullptr;
}









void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
