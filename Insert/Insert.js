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
function leter_or_number(str){
    var flag_gmail_contains_letter = charIsLetter(str[0]);
    var flag_gmail_contains_number = Check_First_Letter_Number(str[0]);
    var flag = flag_gmail_contains_letter || flag_gmail_contains_number;
    return flag;
}
function Validate_email(str){
    let google_str_check = '@gmail.com'
    var flag_gmail = str.includes(google_str_check);
    var flag_first_char = leter_or_number(str);
    var flag = flag_gmail && flag_first_char;
    return flag;
}

function Submit(){
    let Google = document.getElementById("google").value;
    let google_str = Google.toString();
    final_flag = Validate_email(google_str);
    return final_flag;
}
function Print_Error(){
    let is_there_error = Submit();
    if(is_there_error){
    document.getElementById("ok").innerHTML = "It's ok";
    }
    else{
    document.getElementById("error").innerHTML = "Invalid Email";
    }
}