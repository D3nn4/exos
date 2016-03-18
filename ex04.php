#!/usr/bin/php
<?php

$array = $argv;
$length = count($array);
for($i = 1; $i < $length; $i++){
	echo $array[$i] . "\n";
}

?>