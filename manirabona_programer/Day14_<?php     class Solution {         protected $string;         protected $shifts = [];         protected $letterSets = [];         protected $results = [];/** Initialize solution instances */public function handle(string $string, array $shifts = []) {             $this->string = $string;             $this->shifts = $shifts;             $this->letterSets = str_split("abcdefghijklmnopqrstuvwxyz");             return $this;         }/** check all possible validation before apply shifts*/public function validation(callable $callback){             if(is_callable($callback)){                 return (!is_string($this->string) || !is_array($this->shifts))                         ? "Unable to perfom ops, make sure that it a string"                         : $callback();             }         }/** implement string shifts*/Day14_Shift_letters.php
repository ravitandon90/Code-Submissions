<?php
    class Solution {
        protected $string;
        protected $shifts = [];
        protected $letterSets = [];
        protected $results = [];

        /** Initialize solution instances */
        public function handle(string $string, array $shifts = []) {
            $this->string = $string;
            $this->shifts = $shifts;
            $this->letterSets = str_split("abcdefghijklmnopqrstuvwxyz");
            return $this;
        }

        /** check all possible validation before apply shifts*/
        public function validation(callable $callback){
            if(is_callable($callback)){
                return (!is_string($this->string) || !is_array($this->shifts))
                        ? "Unable to perfom ops, make sure that it a string"
                        : $callback();
            }
        }

        /** implement string shifts*/
        public function applyShifts() {
            return $this->validation(function() {
                for($i = 0; $i < strlen($this->string); $i++){
                    array_push($this->results, $this->letterSets[$this->shifts[$i]]);
                }

                return implode($this->results);
            });
        }
    }

    $solution = new Solution();
    $solution->handle("abc", [3, 5, 9]);
    echo $solution->applyShifts();
?
