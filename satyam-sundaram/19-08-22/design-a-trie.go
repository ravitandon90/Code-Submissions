package main

import (
   "fmt"
)

type Node struct {
   // marks the end of word
   isEnd bool
   // map to store the next map
   charMap map[rune]*Node
}

func (node *Node) print() {
   fmt.Println(*node)
}

func (node *Node) put(char rune) *Node {
   // create/insert into @charMap @char
   nextNode, ok := node.charMap[char]
   if ok {
      return nextNode
   }
   nextNode = newNode(false)
   node.charMap[char] = nextNode
   return nextNode
}

func (node *Node) get(char rune) *Node {
   if nextNode, ok := node.charMap[char]; ok {
      return nextNode
   }
   return nil
}

func newNode(isEnd bool) *Node {
   return &Node{
      isEnd:   isEnd,
      charMap: make(map[rune]*Node, 0),
   }
}

type Trie struct {
   root *Node
}

func Constructor() Trie {
   return Trie{root: nil}
}

func (this *Trie) Insert(word string) {
   if this.root == nil {
      // set new root
      this.root = newNode(false)
   }
   pointer := this.root
   for _, char := range word {
      pointer = pointer.put(char)
   }
   // mark leaf node
   pointer.isEnd = true
}

func (this *Trie) getLastNode(word string) *Node {
   if this.root == nil {
      return nil
   }
   pointer := this.root
   for _, char := range word {
      pointer = pointer.get(char)
      if pointer == nil {
         return nil
      }
   }
   return pointer
}

func (this *Trie) Search(word string) bool {
   node := this.getLastNode(word)
   // empty Trie
   if node == nil {
      return false
   }
   // valid if end of word
   return node.isEnd
}

func (this *Trie) StartsWith(prefix string) bool {
   node := this.getLastNode(prefix)
   return node != nil
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */

func main() {
   t := Constructor()
   t.Insert("here")
   t.Insert("there")
   fmt.Println(t.StartsWith("he"))
}