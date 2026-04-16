#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
	Node *n = new Node();
	n->s = new Student(s);
	n->next = NULL;
	if (tail == NULL) {
		head = tail = n;
	} else {
		tail->next = n;
		tail = n;
	}
}

std::string StudentRoll::toString() const {
	std::string result = "[";
	Node *cur = head;
	while (cur != NULL) {
	result += cur->s->toString();
	if (cur->next != NULL) result += ",";
		cur = cur->next;
	}
	return result + "]";
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
	head  = tail = NULL;
	Node *cur = orig.head;
	while (cur != NULL) {
		insertAtTail(*cur->s);
		cur = cur->next;
	}
}

StudentRoll::~StudentRoll() {
	Node *cur = head;
        while (cur != NULL) {
                Node *next = cur->next;
                delete cur->s;
                delete cur;
		cur = next;
        }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...

	Node *curr = head;
        while (curr != NULL) {
                Node *next = curr->next;
                delete curr->s;
                delete curr;
                curr = next;
        }
	head = tail = NULL;
	curr = right.head;
	while(curr != NULL){
		insertAtTail(*curr->s);
		curr = curr->next;
	}

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





