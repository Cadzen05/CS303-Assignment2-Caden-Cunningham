#pragma once

using namespace std;

template <typename Item_Type>
struct SNode {
    // Data fields
    Item_Type data;
    SNode* next;

    // Constructor
    SNode(const Item_Type& data_item, SNode* next_val = nullptr) {
        data = data_item;
        next = next_val;
    }
};

template <typename Item_Type>
class Single_Linked_List {
private:
    // Data fields
    SNode<Item_Type>* head;
    SNode<Item_Type>* tail;
    size_t num_items;

public:
    // Constructor
    Single_Linked_List() : head(nullptr), tail(nullptr), num_tems(0) {}

    // Class functions
    void push_front(const Item_Type& item) {
        // Initialize the new head with data=item and next=old head
        head = new SNode(item, head);

        // If first node in the list, set tail = head
        if (head->next == nullptr) {
            tail = head;
        }

        // Increment num_items
        num_items++;
    }

    void push_back(const Item_Type& item) {
        // If the list is not empty
        if (tail != nullptr) {
            // Have the previous tail point to the new node with data=item and next=NULL
            // set tail to the new node
            tail->next = new Snode(item, nullptr);
            tail = tail->next;

            // Increment num_items
            num_items++;
        }
        else {
            // Call push_front() if list is empty
            push_front(item);
        }
    }

    void pop_front() {
        // Check if list is empty
        if (head == nullptr) {
            throw invalid_argument("Error: cannot pop_front() on an empty list.");
        }

        // Have a pointer (removed) point at current head
        SNode* removed = head;
        // Set head to current head's next, then delete the current head
        head = head->next;
        delete removed;

        // If this was last node in list
        if (head == nullptr) {
            tail = nullptr;
        }

        // Decrement num_items
        num_items--;
    }

    void pop_back() {
        // Check if list is empty
        if (tail == nullptr) {
            throw invalid_argument("Error: cannot pop_back() on an empty list.");
        }

        // If only node in the list
        if (head == tail) {
            delete tail;
            head = nullptr;
            tail = nullptr;
        }

        // Iterate through the list with pointer (curr_node) until the nodes->next points at the tail
        SNode* curr_node = head;
        while (curr_node->next != tail) {
            curr_node = curr_node->next;
        }
        // Delete the current tail and set tail to curr_node, then set tail's next to NULL
        delete tail;
        tail = curr_node;
        tail->next = nullptr;

        // Decrement num_items
        num_items--;
    }

    const Item_Type& front() const {
        // Check if list is empty
        if (head == nullptr) {
            throw invalid_argument("Error: cannot front() on an empty list.")
        }
        // Return head data
        return head->data;
    }

    const Item_Type& back() const {
        // Check if list is empty
        if (tail == nullptr) {
            throw invalid_argument("Error: cannot back() on an empty list.")
        }
        // Return tail data
        return tail->data;
    }

    bool empty() {
        // If list is empty, return true
        // Otherwise, return false
        if (head == nullptr) {
            return true;
        }
        return false;
    }

    void insert(size_t index, const Item_Type& item) {
        // Check if index is in bounds
        if (index > num_items) {
            throw out_of_range("Error: index is out of range");
        }

        // If index is at the start, call push_front()
        if (index == 0) {
            push_front(item);
        }
        // If index is at the back, call push_back()
        else if (index == num_items) {
            push_back(item);
        }
        else {
            // Initialize the new node with data=item and next=NULL
            // Iterate through the list with pointer (prev_node), until you reach the index
            SNode* new_node = new SNode{item, nullptr};
            SNode* prev_node = head;
            for (size_t i = 0; i < (index - 1); ++i) {
                prev_node = prev_node->next;
            }

            // Set the new nodes next to the current nodes next
            // Change the current nodes next to the new node
            new_node->next = prev_node->next;
            prev_node->next = new_node;

            // Increment num_items
            num_items++;
        }
    }

    bool remove(size_t index) {
        // Return false if index is out of bounds
        if (index >= num_items) {
            return false;
        }

        // If index is at the start, call pop_front()
        if (index == 0) {
            pop_front();
        }
        // If index is at the back, call pop_back()
        else if (index == num_items - 1) {
            pop_back();
        }
        else {
            // Initialize a pointer (prev_node) that points to the head and iterate until you reach the index
            SNode* prev_node = head;
            for (size_t i = 0; i < (index - 1); ++i) {
                prev_node = prev_node->next;
            }
            // Point to the current nodes next as the node to be deleted, then have the current node point to the node after the deleted node
            // Delete the deleted node
            SNode* del_node = prev_node->next;
            prev_node->next = del_node->next;
            delete del_node;

            // Decrement num_items
            num_items--;
        }

        // Return true if a node was deleted
        return true;
    }

    size_t find(const Item_Type& item) {
        // Initialize a pointer (curr_node) that points to head
        // As well as index = 0
        SNode* curr_node = head;
        size_t index = 0;

        // Loop through list until the data == item, then return the index where it's found
        while (curr_node != nullptr) {
            if (curr_node->data == item) {
                return index;
            }
            curr_node = curr_node->next;
            index++;
        }
        // Return num_items if item not found in the list
        return num_items;
    }
};

