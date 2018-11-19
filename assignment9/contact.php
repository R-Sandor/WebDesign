<html> <head> 
	<meta charset="UTF-8">
	<meta lang="eg">
	<title> output page </title></head> <body>
<?php
$userName = $_REQUEST['usersName'];
$email = $_REQUEST['email'];
$comments = $_REQUEST['Text1'];
$liked = $_REQUEST['liked'];
$site = $_REQUEST['site'];
$rating = $_REQUEST['rating'];
 $flag=0;
if($userName == ""){
 $flag =1;
 echo "firt name is required<br />";
}
if($comments == ""){
 $flag =1;
 echo "last name is required<br />";
}
if($email == ""){
 $flag =1;
 echo "An email address is required<br />";
}
if ($liked == ""){
	echo "Please rate our site <br/>";
	$flag = 1;
}
if ($site == ""){
	echo "Please tell us how you heard about us. <br/>";
	$flag = 1;
}
if ($rating == ""){
	echo "Please rate our site <br>";
	$flag = 1;
}


  if($flag==0) {
 	
  	$file = fopen("data.txt", "a") or die("unable to open file!");
 	$data = "$userName, $comments, $email, $liked, $site, $rating \r\n";
    fwrite($file, $data) or die("Couldn't write values to file!");
    fclose($file);   //close the data file
    echo "Saved to $file successfully!<br> ";
    
    echo "<a href='data.txt'> Data File </a>";
 }
?>


</body>
</html>
