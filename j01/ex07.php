#!/usr/bin/php
<?php
if (count($argv) >1 ){
	$str = $argv[1];
	$str = trim($str);
	if(count(explode(" ",$str))>1){
		while (true){
			$str1 = str_replace('  ', ' ',$str);
			if ($str1 === $str){
				break;
			}
			else{
				$str = $str1;
			}
		}
		$array_str = explode(" ",$str);
		$lenght = (count($array_str));
		$array_str[$lenght] = $array_str[0];
		array_shift($array_str);
		$result = implode(" ", $array_str);
		echo $result . "\n";

	}
	else{

		echo $str . "\n";
	}
}
?>