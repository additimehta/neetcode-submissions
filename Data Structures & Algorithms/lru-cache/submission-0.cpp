class Node{
    public:
        int key;
        int value;
        Node *next;
        Node *prev;
        Node(int key, int value){
            this->key = key;
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};


class LRUCache {

private:
    int capacity;
    unordered_map<int, Node*> mp;
    Node *tail;
    Node *head;


    // <tail(1,2) > ---  <node 2 (2,3)> < --- > <node3 (3,4)> --- ><head (5,6) >  <NEW NODE> - > nullptr


public:

// head <--- > tail
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->tail = new Node(0,0);
        this->head = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        
    }
    
    int get(int key) {
        if(mp.count(key)){
            Node *node = mp[key];
            int value = node->value;
            remove(node);
            insert(node);
            return value;
        }else{
            return -1;
        }
    }

    // head <---> node 1 < --> node 2 <---> tail


    void remove(Node *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node *node){
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node *node = mp[key];
            node->value = value;
            remove(node);
            insert(node);
            return;

            // remove Node
            // insert Node 

        }

        if(mp.size() >= capacity){
            Node *lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }


        Node *node = new Node(key, value);
        insert(node);
        mp[key] = node;
    }
};
