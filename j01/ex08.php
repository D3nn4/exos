#!/usr/bin/php
<?php
function is_It_Sort($array)
{
	$raw_array = $array;
	$sort_array = $array;
	sort($sort_array);
	$raw = implode(" ", $raw_array);
	$sort = implode(" ", $sort_array);
	if($raw === $sort){
		return true;
	}
	else{
		return false;
	}
}

$tab = array("!?#","42","Hello World", "salut","zZZzzZZzzz");
$tab[] = "Et qu'est ce qu'on fait maintenant ?";
$tab2 = array("alpha","beta","test");

if (is_It_Sort($tab)){
	echo "Le tableau est trie\n";
}
else{
	echo "Le tableau n'est pas trie\n";
}
?>