class LinkedList {
private:
    struct Node {
        int val;
        Node* next;

        Node(int v) {
            val = v;
            next = nullptr;
        }
    };

    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }


    int get(int index) {
        Node* curr = head;

        for (int i = 0; i < index; i++) {
            if (curr == nullptr) return -1;
            curr = curr->next;
        }

        if (curr == nullptr) return -1;

        return curr->val;
    }
    void insertHead(int val) {
        Node *newone = new Node(val);
        if(head == nullptr){
            head = newone;
            return;
        }
        else{
            newone->next = head;
            head = newone;
        }
    }
    
    void insertTail(int val) {
        Node* newone = new Node(val);

        if (head == nullptr) {
            head = newone;
            return;
        }

        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newone;
    }

    bool remove(int index) {
        if (head == nullptr) return false;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node* curr = head;
        for (int i = 0; i < index - 1; i++) {
            if (curr == nullptr || curr->next == nullptr) return false;
            curr = curr->next;
        }

        if (curr->next == nullptr) return false;
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        return true;
    }

    vector<int> getValues() {
        vector<int> result;
        Node *curr = head;
        while(curr!=nullptr){
            result.push_back(curr->val);
            curr = curr->next;
        }
        return result;
    }
};
