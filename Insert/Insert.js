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
    let Password = document.getElementById("password").value;
    let password_str = Password.toString(); 
    console.log(Validate_email(google_str))
}