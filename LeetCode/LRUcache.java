public class LRUCache {
    private int cap, size;
    public class Block{
        int key, value;
        Block prev, next;
        public Block(int k, int v){
            key = k;
            value = v;
            prev = next = null;
        }
    }
    private HashMap<Integer,Block> cache_map;
    private Block head, tail;
    public LRUCache(int capacity) {
        cap = capacity;
        head = new Block(-1,-1);
        tail = new Block(-1,-1);
        head.next = tail;
        tail.prev = head;
        size = 0;
        cache_map = new HashMap<Integer,Block>();
    }
    public int get(int key) {
        if(!cache_map.containsKey(key)) return -1;
        Block cur = cache_map.get(key);
        DeleteFromList(cur);
        AddToListHead(cur);
        return cur.value;
    }
    public void set(int key, int value) {
        if(cap == 0) return;
        if(get(key) == -1){
            if(size == cap){
                cache_map.remove(tail.prev.key);
                DeleteFromList(tail.prev);
                --size;
            }
            Block newblock = new Block(key,value);
            cache_map.put(key,newblock);
            AddToListHead(newblock);
            ++size;
        }
        else{
            Block cur = cache_map.get(key);
            cur.value = value;
        }
    }
    
    private void DeleteFromList(Block b){
        b.prev.next = b.next;
        b.next.prev = b.prev;
        b = null;
    }
    private void AddToListHead(Block b){
        b.next = head.next;
        head.next = b;
        b.prev = head;
        b.next.prev = b;
    }
}