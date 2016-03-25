#!/usr/bin/php
<?php

$handle = fopen($argv[1], "r");
$nom = array();
$prenom = array();
$pseudo = array();
$ip = array();
$index = $argv[2];
if ($handle !== FALSE) {
	while(($str = fgets($handle)) !== false){
		$array_str = explode(";", $str);
		$nickname = $array_str[0];
		$name = $array_str[1];
		$first_name = $array_str[2];
		$ip_adress = $array_str[3];
			if ($index === 'nom'){
				$nom[$name] = $name;
				$prenom [$name] = $first_name;
				$pseudo [$name] = $nickname;
				$ip [$name] = $ip_adress;
			}
			if ($index === 'prenom'){
				$nom[$prenom] = $name;
				$prenom [$prenom] = $first_name;
				$pseudo [$prenom] = $nickname;
				$ip [$prenom] = $ip_adress;
			}
			if ($index === 'pseudo'){
				$nom[$pseudo] = $name;
				$prenom [$pseudo] = $first_name;
				$pseudo [$pseudo] = $nickname;
				$ip [$pseudo] = $ip_adress;
			}
			if ($index === 'ip'){
				$nom[$ip] = $name;
				$prenom [$ip] = $first_name;
				$pseudo [$ip] = $nickname;
				$ip [$ip] = $ip_adress;
			}
	}
		while (true){
		fwrite(STDOUT, "Entrez une commande: ");
		$entry = substr(fgets(STDIN), 0,-1);
			if ($entry === false){
			echo "\n";
			break;
			}
			else {
				if ((eval($entry)) !== false){
					eval($entry);
				}
				else {
					echo "Invalid entry";
				}

			echo "\n";
			}
		}
	

	fclose($handle);
	


}


?>