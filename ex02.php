#!/usr/bin/php
<?php

function is_Pair()
{
fwrite(STDOUT, "Entrez un nombre: ");
$entry = substr(fgets(STDIN), 0,-1);


if ((is_numeric($entry)) == true) {
	$nbr = intval($entry);
	if (is_float($nbr/2) == false) {
		echo "Le chiffre " . $nbr . " est Pair\n";
	}
	else {
		echo "Le chiffre " . $nbr . " est Impair\n";		
	}
}
else {
	echo "'" . $entry . "' n'est pas un chiffre\n";
}
is_pair();
}

is_Pair();
?>