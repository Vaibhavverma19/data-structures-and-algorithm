/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/

vector<pair<int, int>> findPairs(Node* head, int key)
{   vector<pair<int,int> > ans;
    Node* right=head;
    Node* left=head;
    while(right->next)
    {
        right=right->next;
    }

    while(left!=right)
    {
        if(left->data+right->data==key)
        {
           ans.push_back({left->data,right->data});
           left=left->next;
        }else{
            if(left->data+right->data<key)
            {
                left=left->next;
            }else{
                right=right->prev;
            }
        }
    }
    return ans;
}
