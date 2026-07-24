class RandomizedSet {
public:

    // Hash Map:
    // Key   -> Element stored in the set
    // Value -> Index of that element in the vector
    //
    // Example:
    // Vector : [10, 20, 30]
    // Map    : {10->0, 20->1, 30->2}
    unordered_map<int, int> mp;

    // Stores all elements of the set.
    // Required because vector provides O(1) random access.
    vector<int> v;

    // Constructor
    RandomizedSet() {

    }

    // Returns true if the element exists in the set.
    bool searchElement(int val) {

        // unordered_map::find() returns iterator to element
        // if found, otherwise returns mp.end().
        if (mp.find(val) != mp.end())
            return true;

        return false;
    }

    // Inserts a new value into the set.
    bool insert(int val) {

        // Duplicate elements are not allowed.
        if (searchElement(val))
            return false;

        // Insert element at the end of vector.
        v.push_back(val);

        // Store its index in the hash map.
        //
        // Example:
        // Vector = [10,20,30]
        // Insert 40
        //
        // Vector becomes [10,20,30,40]
        // Index of 40 = 3
        mp[val] = v.size() - 1;

        return true;
    }

    // Removes an element from the set.
    bool remove(int val) {

        // Element not present.
        if (!searchElement(val))
            return false;

        // Find index of element to remove.
        auto it = mp.find(val);

        // Suppose:
        //
        // Vector = [10,20,30,40]
        // Remove 20
        //
        // Instead of shifting all elements,
        // replace 20 with last element (40).
        //
        // Vector becomes:
        // [10,40,30,40]

        v[it->second] = v.back();

        // Remove last duplicate element.
        //
        // Vector becomes:
        // [10,40,30]
        v.pop_back();

        // Update index of moved element (40).
        //
        // Map becomes:
        // 10 -> 0
        // 40 -> 1
        // 30 -> 2
        //
        // NOTE:
        // This line should be executed BEFORE erasing the removed element.
        if (it->second < v.size())
            mp[v[it->second]] = it->second;

        // Remove deleted element from hash map.
        mp.erase(val);

        return true;
    }

    // Returns a random element.
    int getRandom() {

        // rand() % v.size()
        // generates a random index between
        // 0 and v.size()-1.
        return v[rand() % v.size()];
    }
};

/*
---------------------------------------------------------
Example Walkthrough
---------------------------------------------------------

Initially:

Vector = []
Map    = {}

insert(10)

Vector = [10]
Map    = {10 -> 0}

---------------------------------------------------------

insert(20)

Vector = [10,20]
Map    = {10 -> 0,
          20 -> 1}

---------------------------------------------------------

insert(30)

Vector = [10,20,30]
Map    = {10 -> 0,
          20 -> 1,
          30 -> 2}

---------------------------------------------------------

remove(20)

Step 1:
Replace 20 with last element (30)

Vector = [10,30,30]

Step 2:
Remove last element

Vector = [10,30]

Step 3:
Update map

Map = {10 -> 0,
       30 -> 1}

---------------------------------------------------------

getRandom()

Random index:
0 -> returns 10
1 -> returns 30

Each element has equal probability.

---------------------------------------------------------

Time Complexity

insert()      : O(1) Average
remove()      : O(1) Average
searchElement(): O(1) Average
getRandom()   : O(1)

Space Complexity : O(n)
*/