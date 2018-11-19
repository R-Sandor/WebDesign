var buttonCount=0;
function fileClick(value, object){
	if (buttonCount ==0)
	{
		var button = document.createElement("button");
		button.innerHTML = "Close Files";
		button.setAttribute("id", "srcButton");
		object.appendChild(button);
		buttonCount++;
	}
	var br = document.createElement("br");
	br.innerHTML= "\n";
	object.appendChild(br);

	var iframe = document.createElement("iframe");
	iframe.width="500px";
iframe.height="500px";
iframe.setAttribute("src", value);
iframe.setAttribute("id" , "srcFrame");
iframe.setAttribute("scrolling", "yes");
var  objIn = document.getElementById("prjFrame");
object.appendChild(iframe);

//iframe.load("res/projects/inventory.cpp")

  document.getElementById("srcButton").addEventListener("click", myFunction);

}


function myFunction() {
    document.getElementById("projectFiles").innerHTML = "";
    buttonCount=0;
}


var prjCount=0;
function prjClick(value, object){
	if (prjCount != 0)
	{
		remover();
		prjCount=0;
	}
	if (prjCount ==0)
	{
		var button = document.createElement("button");
		button.innerHTML = "Close Project";
		button.setAttribute("id", "prjButton");
		object.appendChild(button);
		prjCount++;
	}
	
	var br = document.createElement("br");
	br.innerHTML= "\n";
	object.appendChild(br);

	var iframe = document.createElement("iframe");
	iframe.width="100%";

iframe.setAttribute("src", value);
iframe.setAttribute("id" , "prjFrame");
iframe.setAttribute("scrolling", "yes");
iframe.setAttribute("overflow-y", "visible")
iframe.setAttribute("height", "500px");
iframe.setAttribute("onload", "resizeIframe(this)");

iframe.setAttribute("frameborder", "0");
object.appendChild(iframe);
//iframe.load("res/projects/inventory.cpp")
var projYR =document.getElementsByClassName("projectYear");
var i;
for (i = 0; i < projYR.length; i++) {
    projYR[i].style.height = "300px";
} 
  document.getElementById("prjButton").addEventListener("click", closeProject);

}
  function resizeIframe(obj) {
    obj.style.height = obj.contentWindow.document.body.scrollHeight + 'px';
    
  }


function closeProject() {
var projYR =document.getElementsByClassName("projectYear");
var i;
	 for (i = 0; i < projYR.length; i++) {
    projYR[i].style.height= "auto";
    remover();
} 
}

function remover()
{
var list = document.getElementById("projectSrc");
    list.removeChild(list.firstChild);
    list.innerHTML = "";
    prjCount=0;
   
}