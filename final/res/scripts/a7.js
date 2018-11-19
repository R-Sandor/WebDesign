

function myFunction() {


   	var myDate= runDate();
   	if (myDate.getHours() < 12)
   	{
   		document.getElementById("timeOfDay").innerHTML = "Good Morning";
   	}
   	else if (myDate.getHours() <17)
   	{
   		document.getElementById("timeOfDay").innerHTML = "Good Afternoon";

  	}
  	else
  	{
  	   	document.getElementById("timeOfDay").innerHTML = "Good Evening";
   	}
}

function modal(person)
{
var modal = document.getElementById('myModal');

  


// Get the button that opens the modal

// Get the <span> element that closes the modal
var span = document.getElementsByClassName("close")[0];

// When the user clicks the button, open the modal 
    modal.style.display = "block";

// When the user clicks on <span> (x), close the modal
span.onclick = function() {
    modal.style.display = "none";
}

// When the user clicks anywhere outside of the modal, close it
window.onclick = function(event) {
    if (event.target == modal) {
        modal.style.display = "none";
    }
}
 document.getElementById("greetings").innerHTML =
   "Hello " + person + "!";

}

function runDate()
{
	var d = new Date();
	document.getElementById("date").innerHTML =
        formatDate(d);
    return d;
    }

function formatDate(date) {
  var monthNames = [
    "January", "February", "March",
    "April", "May", "June", "July",
    "August", "September", "October",
    "November", "December"
  ];

  var day = date.getDate();
  var monthIndex = date.getMonth();
  var year = date.getFullYear();

  return day + ' ' + monthNames[monthIndex] + ' ' + year;
}

function validEmail(email) {
			invalidChars = " /:,;"
	
			if (email == "") {						// cannot be empty
				return false
			}
			for (i=0; i<invalidChars.length; i++) {	// does it contain any invalid characters?
				badChar = invalidChars.charAt(i)
				if (email.indexOf(badChar,0) > -1) {
					return false
				}
			}
			atPos = email.indexOf("@",1)			// there must be one "@" symbol
			if (atPos == -1) {
				return false
			}
			if (email.indexOf("@",atPos+1) != -1) {	// and only one "@" symbol
				return false
			}
			periodPos = email.indexOf(".",atPos)
			if (periodPos == -1) {					// and at least one "." after the "@"
				return false
			}
			if (periodPos+3 > email.length)	{		// must be at least 2 characters after the "."
				return false
			}
			return true
		}

		function isNum(passedVal) {					// Is this a number?
			if (passedVal == "") {
				return false
			}
			for (i=0; i<passedVal.length; i++) {
				if (passedVal.charAt(i) < "0") {
					return false
				}
				if (passedVal.charAt(i) > "9") {
					return false
				}
			}
			return true
		}

		function phoneNum(passedVal) {					// Is this a number?
			if (passedVal == "") {
				return false
			}
			if (passedVal.length != 10 )
				return false
			for (i=0; i<passedVal.length; i++) {
				if (passedVal.charAt(i) < "0") {
					return false
				}
				if (passedVal.charAt(i) > "9") {
					return false
				}
			}
			return true
		}

		function validZip(inZip) {					// Is this a valid Zip code?
			if (inZip == "") {
				return false
			}
			if (isNum(inZip)) {						// Check if Zip is numeric
				return true
			}
			return false
		}



	function submitIt(feedbackForm) {

			var first_name = feedbackForm.first_name;

			if (first_name.value == "")
			{
				alert("Please provide a first name.");
				return false;
			}
			var last_name = feedbackForm.last_name;
			if (last_name.value == "")
			{
				alert("Please provide a last name.");
				return false;
			}

			if (first_name.value.length < 3 )
			{
				alert("Please provide a name.");
				return false;
			}
			if (last_name.value.length < 3 )
			{
				alert("Please provide a name.");
				return false;
			}
			if (isNum(first_name.value))
			{
				alert("This is not an name. Name must contain characters");
				return false;
			}
			if (isNum(last_name.value))
			{
				alert("This is not an name. Name must contain characters");
				return false;
			}


			var email = feedbackForm.email.value;
			if (!validEmail(email)) {
				alert("Invalid email address")
				
				return false
			}
		

			var state = feedbackForm.state.value;
			if (state == "")
			{
				alert("please select a state");
				return false;
			} 

			
			var city = feedbackForm.city.value;
			var org = feedbackForm.org.value;
			var country = feedbackForm.country.value;
			if (city == "")
			{
				alert("Provide in a city.");
				return false;
			} 

			var business =feedbackForm.business[0];
			var isBusiness = -1;
			if (feedbackForm.business[0].checked)
			{
				isBusiness=1;

			}
			else
			{
				isBusiness=2;
			}
			if (isBusiness==-1)
			{
				alert("Check one of the check boxes");
				return false;
			}
			if (isBusiness ==1)
			{
				console.log(isBusiness)
				if (org == "")
				{
				alert("Provide an organization.");
				return false;
				} 
			}

			if(validZip(feedbackForm.zip.value) ==false)
			{
				alert("Invalid zipcode");
				return false;
			}
			if(phoneNum(feedbackForm.phone.value) ==false)
			{
				alert("Invalid phone number");
				return false;
			}
			if (country == "")
			{
				alert("Provide in a country.");
				return false;
			} 

			
		}

		