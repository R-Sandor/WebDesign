<html> <head> 
	<meta charset="UTF-8">
	<meta lang="eg">
	<title> output page </title></head> <body>
<?php
$first_name = $_REQUEST['first_name'];
 $last_name = $_REQUEST["last_name"];
 $email = $_REQUEST["email"];
 $address = $_REQUEST["address"];
 $business = $_REQUEST["business"];
 $org = $_REQUEST["org"];
 $city = $_REQUEST["city"];
 $country = $_REQUEST["country"];
 $state = $_REQUEST["state"];
 $zip = $_REQUEST["zip"];
 $phone = $_REQUEST["phone"];
 $comments = $_REQUEST["comments"];


 $first_name = trim($first_name);
 $last_name = trim($last_name);
 $email = trim($email);
 $address = trim($address);
 $business = trim($business);
 $org = trim($org);
 $city = trim($city);
 $country = trim($country);
 $state = trim($state);
 $zip = trim($zip);
 $phone = trim($phone);
 $comments = trim($comments);
 $flag=0;
if($first_name == ""){
 $flag =1;
 echo "firt name is required<br />";
}
if($last_name == ""){
 $flag =1;
 echo "last name is required<br />";
}
if($email == ""){
 $flag =1;
 echo "An email address is required<br />";
}
if($business == ""){
 $flag =1;
 echo "An email address is required<br />";
}
if($business =="1")
{
	if($org == "")
	{
		$flag =1;
		echo "Business must provide their organization <br />";
	}
}
if ($phone == "")
{
	echo "Please provide a phone number<br />";
}



 // the user fills out all the fields

  if($flag==0) {
 	
  	$file = fopen("data.txt", "a") or die("unable to open file!");
 	$data = "$first_name, $last_name, $email, $address, $business, $org, $city, $country,$state, $zip, $phone, $comments \r\n";
    fwrite($file, $data) or die("Couldn't write values to file!");
    fclose($file);   //close the data file
    echo "Saved to $file successfully! ";
 }
?>

</body>
</html>
