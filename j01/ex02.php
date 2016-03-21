#!/usr/bin/php
<?php

while (true){
	fwrite(STDOUT, "Entrez un nombre: ");
	$entry = substr(fgets(STDIN), 0,-1);
	if ($entry === false){
		echo "\n";
		break;
	}
	else {
		
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
	}
}
	
?>