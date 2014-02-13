class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        auto it = item_map.find(key);
        if (it != item_map.end()) {
            item_list.splice(item_list.begin(), item_list, it->second);
            return item_list.front().second;
        }
        else {
            return -1;
        }
    }

    void set(int key, int value) {
        auto it = item_map.find(key);
        if (it != item_map.end()) {
            item_list.splice(item_list.begin(), item_list, it->second);
            item_list.front().second = value;
        }
        else {
            if (item_list.size() == capacity) {
                item_map.erase(item_list.back().first);
                item_list.pop_back();
            }
            item_list.push_front(make_pair(key, value));
            item_map[key] = item_list.begin();
        }
    }
private:
    list<pair<int, int> > item_list;
    unordered_map<int, list<pair<int, int> >::iterator> item_map;
    int capacity;
};