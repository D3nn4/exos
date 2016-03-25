#!/usr/bin/php
<?php

$nom = array (
	'miawallace' => 'Naline',
	'kawai' => 'Denna',
	'indian' => 'stéphane'
	);

while (true){
	fwrite(STDOUT, "Entrez une commande: ");
	$entry = substr(fgets(STDIN), 0,-1);
	if ($entry === false){
		echo "\n";
		break;
	}
	else {
		eval($entry);
		echo "\n";
		
	}
}
	
?>