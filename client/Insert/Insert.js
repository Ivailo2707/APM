function submit_data(){
  let password = document.getElementById("password").value;
  let site_name = document.getElementById("site").value;
  document.getElementById("error").innerHTML = "";
  if(!password){
      document.getElementById("error").innerHTML = "Error no password given";
  }else if(!site_name){
      document.getElementById("error").innerHTML = "Error no site given"
  }
}

function connect1(){
let arduino;
navigator.usb.requestDevice({ filters: [{ vendorId: 0x2341 }] })
.then(device => {
arduino = device
console.log(device);
return arduino.open()
})
// .then(() => arduino.selectConfiguration(1)) // Select configuration #1 for the device.
.then(() => arduino.claimInterface(0)) // Request exclusive control over interface #2.
.then((a) => {
console.log(a);
console.log(arduino);
const data = new Uint8Array([1]);
arduino.transferOut(2, data).then(t => console.log(t));
})
.catch(error => { console.error(error); });
} 