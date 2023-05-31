int ft_isalpha(int c){
    //returns non-zero value if c, the character to be checked is an alphabetic character.
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return 1;
    return 0;
}

