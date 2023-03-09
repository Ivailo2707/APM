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