#!/usr/bin/php
<?php
if (count($argv) == 4){
	array_shift($argv);
	for ($i = 0; $i < 3; $i++){
		$argv[$i] = trim($argv[$i]);
	}
	$str = implode($argv);
	$regex = "#^[0-9]+[\+\*/%-][0-9]+$#";
	
	if (preg_match($regex, $str)){
		if($argv[1] == "+"){
			echo  $argv[0] + $argv[2] . "\n";
		}
		if($argv[1] == "-"){
			echo  $argv[0] - $argv[2] . "\n";
		}
		if($argv[1] == "*"){
			echo  $argv[0] * $argv[2] . "\n";
		}
		if($argv[1] == "/"){
			echo  $argv[0] / $argv[2] . "\n";
		}
		if($argv[1] == "%"){
			echo  $argv[0] % $argv[2] . "\n";
		}
		
	}
	else {
		echo "Incorrect Parameters 2\n";
	}
}
else {
	echo "Incorrect Parameters\n";
}
?>