/* 
Day 3 
203. Implement Trie (Prefix Tree) 
Link : https://leetcode.com/problems/implement-trie-prefix-tree/
 */


var Trie = function() {
    this.alphabets = new Array(26);
    this.flag = false;
};

/** 
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function(word) {
    let curr = this;  
    for(let i=0; i<word.length; i++){
        let index = word.charCodeAt(i) - 97;
        if(!curr.alphabets[index]){
            curr.alphabets[index] = [word[i],new Trie()];      
        }
        curr  = curr.alphabets[index][1];
    }
    curr.flag = true;
    // console.log(this);
};

/** 
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function(word) {
    let curr = this;
    for(let i=0; i<word.length; i++){
        let index = word.charCodeAt(i) - 97;
        if(!curr.alphabets[index]){
            return false;
        }
        curr  = curr.alphabets[index][1];
    }
    return curr.flag;
};

/** 
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith = function(prefix) {
    let curr = this;
    for(let i=0; i<prefix.length; i++){
        let index = prefix.charCodeAt(i) - 97;
        if(!curr.alphabets[index]){
            return false;
        }
        curr  = curr.alphabets[index][1];
    }
    return true;
};

/** 
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */
