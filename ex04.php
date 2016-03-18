#!/usr/bin/php
<?php
if (count($argv) >1 ){
	$array = $argv;
	$length = count($array);
	for($i = 1; $i < $length; $i++){
		echo $array[$i] . "\n";
	}
}

?>