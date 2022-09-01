<?php
    class Day2MaximumConsecutiveOnesInArray {
        protected $index = 1;
        protected $initArray = [];
        protected $consectutive = 0;

        public function __construct(array $array) {
            $this->initArray = $array;
        }

        public function reset() {
            $this->consectutive = 0;
        }

        protected function findConsecutive() {
            foreach($this->initArray as $key => $value){                
                if($value == $this->index):
                    $this->consectutive += $value;
                else:
                    $this->reset();
                endif;
            }

            return $this->consectutive;
        }

        public function index() {
            return $this->findConsecutive();
        }
    }

    $input = ['1','1','0','1','1'];

    $day2 = new Day2MaximumConsecutiveOnesInArray($input);

    echo "Input: nums = ".implode( " ", $input );
    echo "</br>";
    echo "Output: ".$day2->index();