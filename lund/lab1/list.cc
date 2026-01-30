#include "list.h"
#include <iostream>

List::List() : first(nullptr) {}

List::~List() {}

bool List::exists(int d) const {
  Node *curr = first;
  while (curr != nullptr && curr->next != nullptr) {
    if (curr->value == d) {
      return true;
    }
    curr = curr->next;
  }
  return false;
}

int List::size() const {
  int size = 0;
  Node *curr = first;
  while (curr != nullptr && curr->next != nullptr) {
    size++;
    curr = curr->next;
  }
  return size;
}

bool List::empty() const { return first == nullptr; }

void List::insertFirst(int d) {
  if (first == nullptr) {
    first = new Node(d, nullptr);
    return;
  }
  Node *newNode = new Node(d, this->first);
  this->first = newNode;
}

bool List::compare(int a, int b, List::DeleteFlag df) {
  switch (df) {
  case List::DeleteFlag::EQUAL:
    return a == b;
  case List::DeleteFlag::GREATER:
    return a > b;
  case List::DeleteFlag::LESS:
    return a < b;
  }
}

void List::remove(int d, DeleteFlag df) {
  if (first == nullptr) {
    return;
  }
  Node *prev = nullptr;
  Node *curr = first;
  while (curr->next != nullptr) {
    if (compare(curr->value, d, df)) {
      if (curr->next == nullptr) {
        curr = nullptr;
        return;
      }
      if (prev == nullptr) {
        first = curr->next;
        curr = nullptr;
        return;
      }
      prev->next = curr->next;
    }
    prev = curr;
    curr = curr->next;
  }
}

void List::print() const {
  std::cout << "[";
  Node *curr = first;
  while (curr != nullptr && curr->next != nullptr) {
    std::cout << curr->value;
    if (curr->next->next != nullptr) {
      std::cout << ", ";
    }
    curr = curr->next;
  }
  std::cout << "]";
  return;
}
