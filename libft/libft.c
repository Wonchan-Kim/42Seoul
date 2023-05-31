/*
ft_substr
Function name ft_substr
Prototype char *ft_substr(char const *s, unsigned int start,
size_t len);
Turn in files -

Parameters s: The string from which to create the substring.
start: The start index of the substring in the string ’s’.

len: The maximum length of the substring.

Return value The substring.

NULL if the allocation fails.

External functs. malloc

Description Allocates (with malloc(3)) and returns a substring
from the string ’s’.

The substring begins at index ’start’ and is of
maximum size ’len’.

*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>



void *calloc(size_t num, size_t size) {
    // Calculate the total size required
    size_t total_size = num * size;

    // Allocate memory using malloc
    void *ptr = malloc(total_size);

    // Check if memory allocation was successful
    if (ptr != NULL) {
        // Clear the allocated memory by setting all bytes to zero
        // using the memset function from the string.h header
        memset(ptr, 0, total_size);
    }

    return ptr;
}
/*difference between malloc and calloc
 1. parameter difference : calloc func recieves two params elt_count and elt_size, number of elements to be recieved and size of elemetns each.
 2. value of memory : calloc sets allocated memory to zero while malloc does not alter the memory.
*/
char *strdup(const char *string){
    int i = 0;
    int j = 0;
    while(string[i] != '\0'){
        i++;
    }
    if(i == 0)
        return NULL;
    char *string_copy = (char*)malloc(sizeof(char) * (i + 1));
    while(string[j] != '\0'){
        string_copy[j] = string[j];
        j++;
    }
    string_copy[j] = '\0';
    return string_copy;
}

int isalpha(int c){
    //returns non-zero value if c, the character to be checked is an alphabetic character.
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return 1;
    return 0;
}

int isdigit(char c){
    if(c >= 48 && c <= 57)
        return 1;
    return 0;
}

int isalnum(char c){
    //check if the given character is alphanumeric or not
     if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
        return 1;
    return 0;
}

int isascii(int c){
    if(c >= 0 && c <= 127)
        return 1;
    return 0;
}

int isprint(int c){
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

size_t strlen(const char *str){ 
    int i = 0;
    while(str[i] != '\0')
        i++;
    return i;
}
//size_t is an unsigned integer type defined in the 'stddef.h' header file. It is used to represent the size of the objects in bytes( > 0).


void *memset(void *ptr, int value, size_t num){
    /*
    ptr: a pointer to the block of memory to be set
    value: the value to be set (it is passed as an int but will be converted to an unsigned char)
    num: the number of bytes to be set starting from the memory location pointed to by ptr
    note that value is converted into unsigned char to alter the memory with 'byte'. 
*/
    int i = 0;
    unsigned char * ans = (unsigned char *)ptr; //the value will be converted into unsigned char, therefore the type of the pointer that will be returned should be determined.
    while(i < num){
        ans[i] = (unsigned char)value;
        i++;
    }
    return ptr;
}

void bzero(void *s, size_t n){
    size_t i = 0;
    unsigned char* str = (unsigned char*)s; //void* should be explicitly cast. 
    while(i < n){
        str[i] = 0; // do you have to explicitly cast s[i] to unsigned char or not? No, the s is set with void* datatype,
                                 // therefore the compiler does not know the exact type of the elements in the memory block. 
                                 // difference between bzero and memset is  memset expects an int value that will be cast to unsigned char explicitly, 
                                 // while bzero treats the memory block as a sequence of bytes without the need for an explicit cast since the type of s is void*.
                                 // it treats the memory block as a sequence of bytes regardless of the underlying data type.

        i++;
    }
    /*
    The reason why the data type of s[i] should be the unsigned char is, the size of other data type could be differnt dependent on the system architecture.
    for example, the size of int could be differ from 16 bits to 32 bits. However, unsigned char is always the 1 byte.
    The purpose of bzero function is used to set a block of memory to zero, which means each byte in the block must be set 0.
    Note that unsigned char is used to alter 'byte' regardelss of the system.
    */
}
void *memcpy(void *dest, const void *src, size_t n){
    if(dest == NULL || src == NULL)
        return NULL;
    size_t i = 0;
    /*consideration : 
                        1. memory overlap : 
+++++++++++++++++++++++++++++++
| 'a' | 'b' | 'c' | 'd' | 'e' |         suppose given src is a array with size of 5, and dest was assigned as 0x102 with n assigned with 3.
+++++++++++++++++++++++++++++++         

 0x100 0x101 0x102 0x103 0x104           

 if we traverse while loop from the start point, the memory overlap will happen, and result in overwring original src.

 +++++++++++++++++++++++++++++++
| 'a' | 'b' | 'a' | 'b' | 'a' |     (0x104 should be 'c' if memcpy function works without error)
+++++++++++++++++++++++++++++++
 0x100 0x101 0x102 0x103 0x104

                        Therfore, we should compare if the memory might collide during traversing, with the code 
                        if(s < d && s + n > d)
                        In this case, memory overlap could be avoided with copying in reverse order. 
    */

   unsigned char* destination = (unsigned char*) dest;
   unsigned char* source = (unsigned char*)src;
    if(destination > source && source + n > destination){
        i = n;
        while(i > 0){
            destination[i-1] = source[i-1];
            i--;
        }
    }
    else{
        while(i < n){
            destination[i] = source[i];
            i++;
        }
    }
    return (void*)dest;
}

void *memmove(void *dest, const void *src, size_t n){
    /*
    1. dest is a pointer to the destination memory location where the copied data will be stored.
    2. src is a pointer to the source memory location from where the data will be copied.
    3. n specifies the number of bytes to be copied.
    */
    /*
    Safe Overlapping Copy: If the source and destination memory regions overlap, memmove handles the copy correctly. 
    It detects the overlap and performs the copy in a way that ensures the integrity of the data.

    Byte-Level Copy: The memmove function copies the memory byte by byte. 
    It is not aware of the underlying data type and treats the memory as a sequence of bytes.

    Efficient Copy: The implementation of memmove aims to provide an efficient copy operation. 
                It takes advantage of various optimizations to improve performance.

    Portability: The memmove function is part of the C standard library and is available on most C compilers and platforms. 
                It provides a portable way to perform memory copying.
*/
 
    unsigned char* de = (unsigned char*) dest;
    unsigned char* s = (unsigned char*) src;
    if( de > s && s + n > de){
        size_t i = n;
        while( i > 0){
            de[i-1] = s[i-1];
            i--;
        }
    }
    else{
        while(i < n){
            de[i] = s[i];
            i++;
        }
    }
    return (void*)de;
}

size_t strlcpy(char *dest, const char *src, size_t size){
    /*
        safer alternative of strncpy. Used to copy a string from the source to destination buffer while ensuring proper null
        termination and avoiding buffer overflow. 
        dest: A pointer to the destination buffer where the copied string will be stored.
        src: A pointer to the source string to be copied.
        size: The size of the destination buffer, which represents the maximum number of characters that can be copied (including the null terminator).


        How does it assure the copied string ends with proper null charcter and avoids buffer overflow?
        The strlcpy function will copy characters from the source string to the destination buffer until either size-1 
        characters have been copied, or the end of the source string is reached (whichever comes first).          ------->       (1)
        It guarantees that the destination buffer is always null-terminated, regardless of whether truncation occurred. 

        Return value is the length of the source in size_t type. 
    */

    size_t i = 0;
    size_t return_val = 0;
    
    while(i < size - 1 && src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }


    dest[i] = '\0';

    while(src[return_val] != '\0')
        return_val++;
    return return_val;
}

size_t strlcat(char *dest, const char *src, size_t size){
    /*
    The strlcat function is a string concatenation function that is designed to be a safer alternative to the standard strcat function in C. 
    It provides a way to concatenate(결합) strings while ensuring proper null termination and avoiding buffer overflow.
    
    dest: A pointer to the destination buffer, which is the string where the concatenation result will be stored. 
            This buffer should be large enough to accommodate the concatenated string and its null terminator.

    src: A pointer to the source string, which is the string to be appended or concatenated to the destination.

    size: The size of the destination buffer. It represents the total size of the destination buffer, including the existing content and the null terminator.
            Before the user passes the value to the function, the user determines the size parameter in order to prevent the errors related to the memory. 

    The purpose of strlcat is to concatenate the source string (src) onto the end of the destination string (dest). 
    *It appends characters from the source to the destination until either size - strlen(dest) - 1 characters have been appended or the end of the source string is reached, whichever comes first. 
    The null terminator is always added to the destination buffer, ensuring proper null termination.

    
    */
   size_t p_of_d = 0;
   size_t p_of_src = 0;
   size_t d_len = strlen(dest);
   size_t src_len = strlen(src);
   
   while(src[p_of_src] && (p_of_src + d_len + 1 < size)){
     dest[p_of_d] = src[p_of_src];
     p_of_d++;
     p_of_src++;
   }
    dest[p_of_d] = '\0';

   /*
   Discussion over the return value

   The return value is different dpeneding on the result of the copy and the given value of size.
   (1)If the concatenation is successful and the entire source string is appended to the destination buffer without truncation
        Return value will be the sum of the original length of the destination string and the length of the source string.
        ->User can assume the entire source string was copied, and the resulting concatenated string is fully represented in destination 'buffer'.
   (2)If the concatenation is successful but the source string is truncated due to insufficient space in the destination buffer
        Return value will be the sum of the original length of the destination string and the length of the source string. 
        ->User can get the size of the string required to copy source string into destination buffer. 
   (3)If there is not enough space in the destination buffer to perform any concatenation
        Return value will be dlen + strlen(src), demonstrating the concatenation was not performed due to the memory lack of destination buffer. 
   (4)If the length of the destination buffer is equal or exceeds the size of strlen(src)
        Same as case 3.

    The return value of strlcat indicates rather the concatenation was completed successfully, or the enough space required to complete the concatenation, or
    the memory assgined to destination is not enough to complete the concatenation. 
   */
    if(d_len < size){
        return src_len + d_len;
    }
    else{
        return src_len + size;
    }
}


size_t ft_strlen(const char *string) {

    if(string == NULL)
        return 0;
    const char *ptr = string;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - string;
}

int toupper(int c){
    if(c >= 97 && c <= 122)
        c -= 32;
    else
        return c;
}

int tolower(int c){
    if(c >= 'A' && c <= 'Z')
        c += 32;
    else
        return c;
}

char *strchr(const char *str, int c) {
    int i = 0;
    while (str[i]) {
        if (str[i] == (char)c) {
            return (char *)(str + i);
        }
        i++;
    }
    return NULL;
}

char *strrchr(const char *str, int c){
    int i = strlen(str) - 1;

    while (i >= 0){
        if (str[i] == (char) c){
            return (char*) (str + i);
        }
        i--;
    }

    return NULL;
}

int strncmp(const char *str1, const char *str2, size_t n) {
    size_t i = 0;
    while (str1[i] && str2[i] && i < n) {
        if (str1[i] > str2[i])
            return 1;
        else if (str1[i] < str2[i])
            return -1;
        i++;
    }

    if (i == n)
        return 0;
    else
        return (str1[i] > str2[i]) - (str1[i] < str2[i]);
}

void *memchr(const void *ptr, int value, size_t num){
    /*
    ptr: A pointer to the block of memory to be searched.
    value: The byte value to be searched for.
    num: The number of bytes to search within the memory block.
    
    The memchr function in C is used to search for a specific byte value within a block of memory. 
    It allows you to perform a byte-level search in a given memory range, looking for a particular byte value.

    *******Question? Why does all function dealing with bytes take the parameter as 'int type', not 'char' type?
        1. Range of char type can vary depending on the implementation as it can be either signed or unsigned. By using int, both negative and positive
            values could be handled easily.
        2. Int allows function to handle EOF, usually defined as -1.
        3. int provides a wider range and ensures compatibility across different platforms and implemantations.


        The memchr function is primarily used for searching a block of memory for a specific byte value, typically within the range of 0 to 255. 
        */

   size_t i = 0;
   const unsigned char* p = ptr;
   while(i < num){
    if(p[i] == (unsigned char)value)  //unsigned char used to handle full range of byte values in a consistent and portable manner. 
        return (void*)(p+i);
    i++;
   }
   return NULL;


}

/*
#include <stdio.h>

int main() {
    unsigned char buffer[4] = {0xFF, 0x80, 0x00, 0x7F};

    // Using unsigned char
    unsigned char* p1 = (unsigned char*)buffer;
    if (p1[0] == 0xFF) {
        printf("Unsigned char comparison: Match found!\n");
    } else {
        printf("Unsigned char comparison: No match.\n");
    }

    // Using char
    char* p2 = (char*)buffer;
    if (p2[0] == 0xFF) {
        printf("Char comparison: Match found!\n");
    } else {
        printf("Char comparison: No match.\n");
    }

    return 0;
}

When using unsigned char and performing the comparison (p1[0] == 0xFF), it evaluates to true because the comparison is performed in the range of 0 to 255, 
which covers the full range of possible byte values.

However, when using char and performing the comparison (p2[0] == 0xFF), it may evaluate to false. 
This is because the char type is signed on some platforms, and the value 0xFF is interpreted as -1 when it is sign-extended. 
So the comparison becomes (char)-1 == (char)-1, which evaluates to true. 
But if the value in the array were changed to 0x80 (which is negative when interpreted as a signed char), the comparison would evaluate to false, causing unexpected results.

In case of 0x80(128) is converted into -1, so "No Match" is resulted. 
*/

int memcmp(const void *ptr1, const void *ptr2, size_t num){
    /*
    ptr1 and ptr2 are the pointers to the memory block to be compared
    num is the number of bytes to be compared
    If the memory blocks are equal, it returns 0.
    if ptr1 is greater than ptr2 it returns a positive value.
    if ptr2 is greater than ptr1 it returns a negative value.
    */
   const unsigned char* pointer1 = (const unsigned char*) ptr1; //unsigned char used to compare the byte values. 
   const unsigned char* pointer2 = (const unsigned char*) ptr2;
   size_t i = 0;
   while(pointer1[i] && pointer2[i] && i < num){
    if(pointer1[i] > pointer2[i])
        return 1;
    else if(pointer1[i] < pointer2[i])
        return -1;
    i++;
   }
   return 0;
}

char *strnstr(const char *haystack, const char *needle, size_t len){
    /*
    It is used to search for the first occurrence of a substring within a given string, limiting the search to a specified number of characters.

    haystack is a pointer to the string in which you want to search for the substring.
    needle is a pointer to the substring you want to find.
    len is the maximum number of characters to search within the haystack string.

    The strnstr function returns a pointer to the first occurrence of the needle substring within the haystack string, limited to len characters. 
    If the substring is not found, it returns NULL.
    */
   size_t needle_len = ft_strlen(needle);

   if(needle_len == 0)
    return (char *)haystack; //empty substring
   size_t i = 0;
   size_t j;
   while(i < len - needle_len){
    j = 0;
    while(j < needle_len && haystack[i+j] == needle[j])
        j++;
    if(j == needle_len)
        return (char *)(haystack+i);
    i++;
   }
    return NULL;
}

int atoi(const char *string){
    /*
    The function takes a pointer to a null-terminated string str as its argument and returns the converted int value. 
    It performs the following steps to convert the string:

    Skips any leading white space characters (spaces, tabs, newlines, etc.).
    Determines the sign of the number based on the presence of a leading positive ('+') or negative ('-') sign character.
    Converts the remaining characters in the string to an integer until a non-digit character is encountered or the end of the string is reached.
    Returns the converted int value.
    
    48~57 is the ascii code assigned for 0~9 value each.
    */
    int sign = 1;
    int ans = 0;
    int len = ft_strlen(string);
    while(str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
        i++;
    if(str[i] == '-' || str[i] == '+'){
        if(str[i] == '-')
            sign *= -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9'){
        ans += ans * 10 + str[i] - '0';
        i++;
    }

    return ans * sign;
}






/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/

char *ft_substr(char const *s, unsigned int start, size_t len){
    char* ans;
    unsigned int i;

    i = 0;
    if(s == NULL)
        return NULL;
    ans = (char*)malloc(sizeof(char) * (len+1)); //len + 1 for nul character
    if(ans == NULL)
        return NULL; 
    while(i < (unsigned int)len){
        ans[i] = s[start + i];
        i++;
    }
    ans[i]='\0';
    return ans;
}


char *ft_strjoin(char const *s1, char const *s2){
    int len1 = ft_strlen(s1);
    int len2 = ft_strlen(s2);
    int total_len = len1 + len2;
    char * ans = (char*)malloc(sizeof(char)*total_len + 1); //null termination 
    char * tmp = ans; 

    if(ans == NULL)
        return NULL;
    while(*s1 != '\0'){
        *tmp = *s1;
        tmp++;
        s1++;
    }
    while(*s2!= '\0'){
        *tmp = *s2;
        tmp++;
        s2++;
    }
    *tmp = '\0';

    return ans;
}




char *ft_strtrim(char const *s1, char const *set){
    //set is the group of the letters that must be removed from the s1.
    // abcd b
    // get start position & end position for trim
    if(set == NULL || s1 == NULL)
        return NULL;
    
    size_t len = ft_strlen(s1);
    size_t s_pos = 0;
    size_t e_pos = len - 1;

    while(s_pos < len && ft_strchr(set, s1[s_pos]) != NULL)
        s_pos++;
    while(e_pos > s_pos && ft_strchr(set, s1[e_pos]) != NULL)
        e_pos--;

    size_t ans_len = (e_pos >= s_pos) ? (e_pos - s_pos + 1) : 0;
    char* ans = malloc(ans_len + 1);
    if(ans == NULL)
        return NULL;
    
    size_t copied_len = strlcpy(ans, s1 + s_pos, ans_len + 1);
    return ans;
}

//ft_split

static int	count_words(const char *str, char c)
{
	int i;
	int in_word;

	i = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && in_word == 0)
		{
			in_word = 1;
			i++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s || !(split = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (0);
	i = 0;
	j = 0;
	index = -1; //start position of the word
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i; //first encounter the word 
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

//ft_itoa

static int	ft_num_len(int n)
{
	int len = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return len;
}

char	*ft_itoa(int n)
{
	int		len = ft_num_len(n);
	char	*x = (char *)malloc(sizeof(char) * (len + 1));
	if (!x)
		return NULL;
	x[len--] = '\0';
	if (n == 0)
		x[0] = '0';
	if (n < 0)
	{
		x[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		x[len--] = '0' + (n % 10);
		n /= 10;
	}
	return x;
}

//ft_strmapi

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int i = 0;
    char *ans;

    ans = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
    if (ans == NULL)
        return NULL;

    while (*s)
    {
        ans[i] = f(i, *s);
        i++;
        s++;
    }
    ans[i] = '\0';

    return ans;
}
//ft_striteri

void ft_striteri(char *s, void (*f)(unsigned int, char*)){
	int	i;

	i = 0;
	if (!s)
		return;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

//ft_putchar_fd
/*
    This function takes in fd as a file descriptor and a character to write. 
    File descriptopr is a process-unique identifier for a file or other input/output resource, such as pipe or network socket. 
    Typically have non-negative integer values, with negative values indicating no value or error conditions. 
    0 - stdin, 1 - stdout, 2 - stderr
    In Unix-like system, fd can refer to any Unix file type named in a file system.  
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

//ft_putstr_fd
void ft_putstr_fd(char *s, int fd){
    if(s == NULL)
        return;
    while(*s){
        write(fd, s, 1);
        s++;
    }
}

//ft_putendl_fd
/*
    Outputs the string 's' to the given file descriptor followed by a new line. 
*/
void ft_putendl_fd(char *s, int fd){
    if(s == NULL)
        return;
    while(*s){
        write(fd, s, 1);
        s++;
    }

    write(fd, '\n', 1);
}

//ft_putnbr_fd
/*
Outputs the integer ’n’ to the given file descriptor.
*/
void ft_putnbr_fd(int n, int fd){
    //possible error:  the int type holds the value from -2147483648~2147483647. if you multiply -1, overflow error occurs. 
    if (n == -2147483648)
        {
                write(fd, "-2147483648", 11);
        }
        else if (n < 0)
        {
                write(fd, "-", 1);
                ft_putnbr_fd(-n, fd);
        }
        else if (n < 10 && n >= 0)
        {
                ft_putchar_fd(n + '0', fd);
        }
        else if (n > 0)
        {
                ft_putnbr_fd(n / 10, fd);
                ft_putchar_fd(n % 10 + '0', fd);
        }
}

