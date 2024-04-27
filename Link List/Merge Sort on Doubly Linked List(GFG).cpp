/*
    Merge Sort on Doubly Linked List

    Given Pointer/Reference to the head of a doubly linked list of n nodes, the task is to Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing order.

*/

class Solution
{
public:
    Node *getMiddle(Node *head)
    {
        if (!head)
            return nullptr;

        Node *slow = head;
        Node *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node *merge(Node *left, Node *right)
    {
        if (!left) // if left is nullptr, return right
            return right;
        if (!right) // if right is nullptr,
            return left;

        Node *dummy = new Node(-1); // dummy node
        Node *ptr = dummy; // pointer to the dummy node 

        while (left && right) // merge the two sorted halves
        {
            if (left->data <= right->data) // if left data is less than or equal to right data
            {
                ptr->next = left; // connect the left node to the merged list
                left->prev = ptr; // set the prev pointer of the left node to ptr
                left = left->next; // move left to the next node
            }
            else
            {
                ptr->next = right; // connect the right node to the merged list
                right->prev = ptr; // set the prev pointer of the right node to ptr
                right = right->next; // move right to the next node
            }
            ptr = ptr->next; // move ptr to the next node
        }

        if (left) // if left is not nullptr
        {
            ptr->next = left;
            left->prev = ptr;
        }
        if (right) // if right is not nullptr
        {
            ptr->next = right;
            right->prev = ptr;
        }

        Node *mergedList = dummy->next; // merged list
        delete dummy;

        return mergedList;
    }

    Node *sortDoubly(Node *head)
    {
        if (!head || !head->next)
            return head;

        Node *mid = getMiddle(head); // get the middle of the list
        Node *left = head; // left half of the list
        Node *right = mid->next; // right half of the list

        mid->next = nullptr; // break the list into two halves
        if (right) // if the right half exists
            right->prev = nullptr;

        left = sortDoubly(left); // sort the left half
        right = sortDoubly(right); // sort the right half

        Node *mergedList = merge(left, right); // merge the two sorted halves

        // Find the tail of the merged list
        Node *tail = mergedList;
        while (tail->next)
        {
            tail = tail->next;
        }

        // Set the prev pointer of the head and the next pointer of the tail to nullptr
        mergedList->prev = nullptr;  // yeh step yaad rakhna ma bhul jata hu
        tail->next = nullptr; // yeh step yaad rakhna ma bhul jata hu

        return mergedList;
    }
};

/*
    Algorithm:
    1. Find the middle of the list using the slow and fast pointer technique.
    2. Divide the list into two halves.
    3. Recursively sort the two halves.
    4. Merge the two sorted halves.
    5. Return the merged list.
*/

// time complexity : O(nlogn)
// space complexity : O(1)