int ft_isprint(int c){
    /*In ASCII, the printable characters are those with decimal codes in the range 32 to 126, inclusive. 
    These characters include the letters of the English alphabet, digits, punctuation marks, and other printable symbols.
    Characters with decimal codes less than 32 are control characters that are used to control various aspects of text display 
    and communication protocols. Characters with decimal codes greater than 126 are considered non-printable characters, 
    such as extended ASCII characters, Unicode characters, or special control characters.
    The isprint function in C checks whether a given character has a decimal code between 32 and 126, inclusive, 
    and returns a non-zero value if the character is printable.*/
    if(c >= 32 && c <= 126)
        return 1;
    return 0;
}
