<?php
	function ft_split($str)
	{
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
		$array = array_reverse(explode (" ", $str));
		return $array;

	}

print_r(ft_split("Hello     World AAA"))
?>