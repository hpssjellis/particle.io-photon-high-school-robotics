<html>
<head>
<title>Particle Web Communication </title>

<font style="font-size:30px">

<!-- ********************* DO NOT MESS WITH THIS ADVANCED AJAX STUFF -->
<!-- ********************* Look at the bottom of the page for student area -->

<script type="text/javascript">
<!--
var loadingmessage = 'Processing...';
function setAjax(){
   var xmlHttp;
   try{
      xmlHttp=new XMLHttpRequest(); // Firefox, Opera 8.0+, Safari
      return xmlHttp;
   }
   catch (e){
      try{
         xmlHttp=new ActiveXObject("Msxml2.XMLHTTP"); // Internet Explorer
         return xmlHttp;
      }
      catch (e){
         try{
            xmlHttp=new ActiveXObject("Microsoft.XMLHTTP");
            return xmlHttp;
         }
         catch (e){
            alert("Your browser does not support AJAX!");
            return false;
         }
     }
   }
}
function myAjax(f, url, myDivToChange) {
   var poststr = getFormValues(f);
    postData(url, poststr, myDivToChange);
}
function postData(url, parameters, myDivToChange2){
   var xmlHttp = setAjax();
   xmlHttp.onreadystatechange =  function(){
      if(xmlHttp.readyState > 0 && xmlHttp.readyState < 4){
          document.getElementById(myDivToChange2).innerHTML=loadingmessage;
      }
      if (xmlHttp.readyState == 4) {
             // this is where the magic occcurs
             
          var myJsonObject = JSON.parse(xmlHttp.responseText);
             
             
           //document.getElementById(myDivToChange2).innerHTML=xmlHttp.responseText+' data sent was '+parameters;
         
           document.getElementById(myDivToChange2).innerHTML= myJsonObject.return_value;
         
         
         
      }
   }
   xmlHttp.open("POST", url, true);
   xmlHttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
   xmlHttp.send(parameters);
}
function getFormValues(fobj){
   var str = "";
   var valueArr = null;
   var val = "";
   var cmd = "";
   for(var i = 0;i < fobj.elements.length;i++){
      switch(fobj.elements[i].type){
         case "text":
            str += fobj.elements[i].name +"=" + escape(fobj.elements[i].value) + "&";
            break;         
         case "password":
            str += fobj.elements[i].name +"=" + escape(fobj.elements[i].value) + "&";
            break;
         case "textarea":
            str += fobj.elements[i].name +"=" + escape(fobj.elements[i].value) + "&";
            break;
         case "select-one":
             str += fobj.elements[i].name +"=" + fobj.elements[i].options[fobj.elements[i].selectedIndex].value + "&";
             break;
     }
   }
   str = str.substr(0,(str.length - 1));
   return str;
}
function sendToParticle(myIn){
    document.all.myParameter.value = myIn
    document.myForm.action = 'https://api.particle.io/v1/devices/' + document.all.myDeviceId.value + '/' + document.all.myFunctionName.value
    myAjax(document.all.myCoolForm, document.myForm.action, 'myDivId')   
    
}
//--></script>







</head>

<body onload="{
   myStorage1 = localStorage.getItem('myStoredText1')
   if(myStorage1  != null){     
      document.getElementById('myToken').value = myStorage1 
    }   
    myStorage2 = localStorage.getItem('myStoredText2')
    if(myStorage2  != null){
       document.getElementById('myDeviceId').value = myStorage2      
    }
          
}">

  

   
   
   
   
   
   
   
 

   






   <h2 align=center>Web <a href="http://particle.io">Particle.io</a> App</h2>



Device ID:<input id="myDeviceId" name="myCoreID" type=password size=50 placeholder="78dd12345678123456"> <br>
Get this from the core area when logged in<br>

<input id="myFunctionName" name="myFunction"  type=hidden size=50 value="my-main" > 

<form name="myForm" method="POST" id="myCoolForm" ><br>

<input id="myParameter" name="params" type=text  style="display:none"     size=50 placeholder="d7-send-high"> 

Access Token:<input id="myToken" name="access_token" type=password size=50 placeholder="5622ce6bba702ef6bd3456d5ed26aaa4a28d7c9"> <br>
Get this from the settings area when logged into <a href="http://particle.io/build">http://particle.io/build</a><br>




</form>



<input type="button" value="Store the Photon's Token and ID locally!" onClick="{
   localStorage.setItem('myStoredText1', document.all.myToken.value)   
   localStorage.setItem('myStoredText2', document.all.myDeviceId.value)
   alert('Device ID =' + document.all.myDeviceId.value +'\n\nAccess Token='+ document.all.myToken.value +' \n\nHas been stored')
}">






<br><br>


   
 <input type="button" value="WHOAMI" onClick="{
    sendToParticle('WHOAMI(xx,1)')
}"> 31=Raspberry PI, 6=Photon<br>  
   
 <input type="button" value="Activate Loop" onClick="{
    if (this.value == 'Activate Loop'){                                                 
        sendToParticle('loop(xx,1);') 
        this.value = 'Stop Looping'
    } else {
        sendToParticle('loop(xx,0);')  
        this.value = 'Activate Loop'
    }
}"> Direct microprocessor looped control <br><br>
   
   
   
  
<div width="400" height="200" name="myDivName" id="myDivId"> output here </div><hr>
   
   
   
<!-- ********************* END OF:       DO NOT MESS WITH THIS ADVANCED STUFF -->  



<!-- ********************* You change the following buttons as needed -->  

   
   
   
   
   

<input type="button" value="digitalWrite(D7,HIGH);" onClick="{
    sendToParticle('digitalWrite(D7,HIGH);')
}">

<input type="button" value="digitalWrite(D7,LOW);" onClick="{
    sendToParticle('digitalWrite(D7,LOW);')
}"><br> Can also use on and off or 1 and 0


<input type="button" value="digitalWrite(d7,1);" onClick="{
    sendToParticle('digitalWrite(d7,1);')
}">
<input type="button" value="digitalWrite(d7,0);" onClick="{
    sendToParticle('digitalWrite(d7,0);')
}"><br><br>

Note that Advanced users can also use the pin numbers, so D7 = pin 7 on Photon but D7 = GPIO 19 on the Raspberry PI<br><br>   
   
   
   
<input type="button" value="digitalWrite(D0,1);" onClick="{
    sendToParticle('digitalWrite(D0,1);')
}">

<input type="button" value="digitalWrite(D0,0);" onClick="{
    sendToParticle('digitalWrite(D0,0);')
}">   <br><br>


   
   
   
<input type="button" value="digitalRead(D6);" onClick="{
    sendToParticle('digitalRead(D6);')
}"><br><br>
  
   
<input type="button" value="analogRead(A0);" onClick="{
    sendToParticle('analogRead(A0);')
}">   Photon Direct Analog input, PI uses capactive Input both returns 0-4095<br>
     
   
   
   

<input type="button" value="analogWrite(A4,255);" onClick="{
    sendToParticle('analogWrite(A4,255);')
}"> Powerful
  

<input type="button" value="analogWrite(A4,100);" onClick="{
    sendToParticle('analogWrite(A4,100);')
}"> Medium
  
<input type="button" value="analogWrite(A4,0);" onClick="{
    sendToParticle('analogWrite(A4,0);')
}"> Off,  These are PWM 0-255 <br><br>
     
   
   <hr>

By Jeremy Ellis<br>
   Website <a href="">http://rocksetta.com</a><br>
   Twitter <a href="https://twitter.com/rocksetta">@rocksetta</a><br>
   
Use at your own risk<br>
</font>
</body>
</html>
