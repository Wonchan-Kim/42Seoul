int ft_isalnum(char c){
    //check if the given character is alphanumeric or not
     if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
        return 1;
    return 0;
}
