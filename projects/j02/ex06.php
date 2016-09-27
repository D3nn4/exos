#! usr/bin.php
<?php
	$ligne = array();
	$time = array();
	$text = array();
	$handle = fopen($argv[1], "r");
	if ($handle){
		while(!feof($handle)){
			$str_ligne = fgets($handle);
			$ligne[] = $str_ligne;
			$str_time = fgets($handle);
			$time[] = $str_time;
			$str_text = fgets($handle);
			$text[$str_time] = $str_text;
			$str_blank = fgets($handle);
			
		}
		sort ($time);
		$lenght = count($ligne);
		for($i = 0; $i < $lenght; $i++){
			echo $ligne[$i] . $time[$i] . $text[$time[$i]] ;
			echo "\n";
		}


	}
	else {
		echo "wrong input\n";
	}
?>