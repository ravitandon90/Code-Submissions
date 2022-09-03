<?php

    class Day1ProductOfArrayExceptItself {

        protected $baseArray = [];

        protected $finalArray = [];

        protected $initial = 1;

        /**
         * Class constructor.
         */
        public function __construct() {
            $this->baseArray = ['1', '2', '3'];
        }

        /**
         * Find actual product except itself
         */
        public function prodArray(array $base, int $n){            
            foreach($base as $key => $value){
                $this->initial = $this->initial * $base[$key];
            }
            
            for ($i=0; $i < $n; $i++) { 
                $this->finalArray[$i] = $this->initial / $base[$i];
            }
        }

        /**
         * Print ount the results
         */
        public function get() {
            foreach($this->finalArray as $value) {
                echo $value. " ";
            }
            
            echo "</br>";

            foreach($this->baseArray as $value){
                echo $value. " ";
            }
        }
        
        /**
         * Initialize the process
         */
        public function index(){
          $n = count($this->baseArray);

          $this->prodArray($this->baseArray, $n);

          return $this->get();
        }
    }

    $day1 = new Day1ProductOfArrayExceptItself();
    $day1->index();