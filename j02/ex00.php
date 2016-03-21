#!/usr/bin/php
<?php
if (count($argv) >1 ){
	$str = $argv[1];
	$str = trim($str);
	$str = str_replace('\t', ' ',$str);
	while (true){
		$str1 = str_replace('  ', ' ',$str);
		if ($str1 === $str){
			break;
		}
		else{
			$str = $str1;
		}
	}
	echo $str . "\n";
}

?>