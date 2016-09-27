#!/usr/bin/php
<?php

$array_date = explode(" ", $argv[1]);
$months = array(
	"janvier" => "01",
     "février" => "02",
     "mars" => "03",
     "avril" => "04",
     "mai" => "05",
     "juin" => "06",
     "juillet" => "07",
     "août" => "08",
     "septembre" => "09",
     "octobre" => "10",
     "novembre" => "11",
     "décembre" => "12"
);

$day = $array_date[1];
$month = $months[strtolower($array_date[2])];
$year = $array_date[3];
$hour = $array_date[4];
$time_In_Sec = strtotime($day."-".$month."-".$year." ".$hour);
echo $time_In_Sec . "\n";

?>