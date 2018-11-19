<?php
$flag=0;
$subject = $_REQUEST['subject'];
$dateTime = date("d/m/y : H:i:s", time());

$name = $_REQUEST['name'];
$email = $_REQUEST['email'];
$comments = $_REQUEST['comments'];

if ($name == ""){
	$flag =1;
	echo "You must provide a name.";
}
if ($email == ""){
	$flag =1;
	echo "Please Provide an email address";
}

if ($comments == ""){
	$flag = 1;
	echo "Please provide a comment";
}
if($flag==0) {
echo "Your entry: <br>";
echo "$subject<br>";
echo $dateTime."<br>";
echo "$name<br>";
echo "$email<br>";
echo "$comments<br>";

 	
  	$file = fopen("comments.txt", "a") or die("unable to open file!");
 	 $data = "$subject, $dateTime, $name, $email, $comments \r\n";

     fwrite($file, $data) or die("Couldn't write values to file!");
    fclose($file);   //close the data file
     echo "Saved to $file successfully! ";
 }



