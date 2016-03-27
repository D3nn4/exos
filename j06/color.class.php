#! usr/bin/php
<?php
class Color {
	
	public $red;
	public $green;
	public $blue;
	public static $verbose = false;

	function __construct(array $colors)
	{
		if (array_key_exists('rgb', $colors)){
			$rgb = $colors['rgb'];
			$this->red = ($rgb & 0xff0000) >> 16;
			$this->green = ($rgb & 0x00ff00) >> 8;
			$this->blue = ($rgb & 0x0000ff);
		}
		else {
			if (array_key_exists('red', $colors)){
				$this->red = $colors['red'];				
			}	
			if (array_key_exists('green', $colors)){
				$this->green = $colors['green'];
			}
			if (array_key_exists('blue', $colors)){
				$this->blue = $colors['blue'];
			}
		}		
	
		if (Color::$verbose === true){
		echo "Color( red: " . $this->red . ', green:   ' . $this->green . ', blue:  ' . $this->blue . " ) constructed.\n";
		}
	}
}





Color::$verbose = True;
$red     = new Color( array( 'red' => 0xff, 'green' => 0   , 'blue' => 0    ) );
$green   = new Color( array( 'rgb' => 255 << 8 ) );
$blue    = new Color( array( 'red' => 0   , 'green' => 0   , 'blue' => 0xff ) );
?>