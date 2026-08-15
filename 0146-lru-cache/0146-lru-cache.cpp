class LRUCache {
public:

   struct node {
    int key ; 
    int value ; 
    node* prev ; node* next ;

    node( int k , int v){
        key = k ; 
        value = v ;
        prev = nullptr ;
        next = nullptr ;
    }
   };

   int capacityy ;

   unordered_map<int , node*> mpp ; 

   node* head ; node* tail ;

   //adding new node right after head and 

   void add_front(node* nodee){

    nodee -> next = head ->next ;
    nodee-> prev = head ;

    head->next->prev = nodee ;
    head->next = nodee ;

   }

   // removal of the node from the current posn 

   void remove( node* nodee){
    nodee->prev ->next = nodee->next ;
    nodee->next -> prev  = nodee-> prev ;
   }



   LRUCache(int capacity) {

    capacityy = capacity ;

    head = new node( -1 , -1 );
    tail = new node( - 1 , -1 );

    head -> next = tail ;
    tail -> prev = head ; 


    }
    
    int get(int key) {

        // if key dosent exist in mpp 

        if( mpp.find(key) == mpp.end()) return - 1;

        // find the node 

        node* nodee = mpp[key];

        remove(nodee);
        add_front(nodee);

        return nodee->value ;
        
    }
    
    void put(int key, int value) {

        // is key exists update 

        if(mpp.find(key) != mpp.end()){

            node* nodee = mpp[key];

            nodee -> value = value ;

            remove(nodee);
            add_front(nodee);

            return ;
        }

        // if new node 

        node* nodee = new node(key , value);

        mpp[key] = nodee ;

        add_front(nodee);

        if(mpp.size() > capacityy){
            node* lru = tail -> prev ;
            // remove from the hash mpp
            mpp.erase(lru->key);

            remove(lru); // deleted node 

            delete lru ;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */