function charIsLetter(char) {
    if (typeof char !== 'string') {
      return false;
    }
  
    return char.toLowerCase() !== char.toUpperCase();
}
function Check_First_Letter_Number(char){
    if (char >= '0' && char <= '9') {
        return true
    } else {
        return false
    }
}
function letter_or_number(str){
    console.log('letter_or_number')
    var flag_gmail_contains_letter = charIsLetter(str[0]);
    var flag_gmail_contains_number = Check_First_Letter_Number(str[0]);
    var flag = flag_gmail_contains_letter || flag_gmail_contains_number;
    return flag;
}
function Validate_email(str){
    console.log('Validate_email')
    let google_str_check = '@gmail.com'
    var flag_gmail = str.includes(google_str_check);
    var flag_first_char = letter_or_number(str);
    var flag = flag_gmail && flag_first_char;
    return flag;
}

function Submit_data(){
    console.log('Submit_data')
    let google = document.getElementById("google").value;
    let password = document.getElementById("password").value;
    document.getElementById("error").innerHTML = "";
    if(!password){
        document.getElementById("error").innerHTML = "Error no password given";
    }
    else if(Validate_email(google)){
        document.getElementById("error").innerHTML = "It's ok";
    }
    else{
        document.getElementById("error").innerHTML = "Invalid Email";
    }
}