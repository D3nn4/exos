#!/usr/bin/php
<?php
if (count($argv) >1 ){
	array_shift($argv);
	$str = implode(" ",$argv);
	$str = trim($str);
	while (true){
		$str1 = str_replace('  ', ' ',$str);
		if ($str1 === $str){
			break;
		}
		else{
			$str = $str1;
		}
	}
	$array = explode(" ",$str);
	sort($array);
	$lenght = count($array);
	for($i = 0; $i < $lenght; $i++){
		echo $array[$i] . "\n";
	}
}

?>