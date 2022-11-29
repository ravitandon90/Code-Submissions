class RandomizedSet {
private:
    vector<int> values;
    unordered_map<int, int> valueIndices;
    
public:
    RandomizedSet() {}

    bool insert(int val) {
        if(valueIndices.count(val)) {
            return false;
        }

        valueIndices[val] = values.size();
        values.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!valueIndices.count(val)) {
            return false;
        }
        int lastValue = values.back();
        values[valueIndices[val]] = lastValue;
        values.pop_back();
        valueIndices[lastValue] = valueIndices[val];
        valueIndices.erase(val);
        return true;
    }
    
    int getRandom() {
	    return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */