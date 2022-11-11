// lookup table for the Morse alphabet covers ASCII 0-127 (0x00 - 0x7f)
char *alphabet[] = { 
(char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""),   //unused (20)
(char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""),   //unused (20) // unused (41) (SPACE is 32)
(char *)(""), (char *)("-.--."), (char *)("--..--"), (char *)("-....-"), (char *)(".-.-.-"), (char *)("-..-."),  // Punctuation: + (KN) , - . / (47)
(char *)("-----"), (char *)(".----"), (char *)("..---"), (char *)("...--"), (char *)("....-"), (char *)("....."), (char *)("-...."), (char *)("--..."), (char *)("---.."), (char *)("----."), // 0-9 (57)
(char *)(""), (char *)(""), (char *)(""), (char *)("-...-"), (char *)(".-.-."), (char *)("..--.."), (char *)(""),// Punctuation:  = (BT) > (AR) ? . (64)
(char *)(".-"), (char *)("-..."), (char *)("-.-."), (char *)("-.."), (char *)("."), (char *)("..-."), (char *)("--."), (char *)("...."), (char *)(".."), // A-I (73)
(char *)(".---"), (char *)("-.-"), (char *)(".-.."), (char *)("--"), (char *)("-."), (char *)("---"), (char *)(".--."), (char *)("--.-"), (char *)(".-."), // J-R (82)
(char *)("..."), (char *)("-"), (char *)("..-"), (char *)("...-"), (char *)(".--"), (char *)("-..-"), (char *)("-.--"), (char *)("--.."), // S-Z (90)
(char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(""), (char *)(".-"), (char *)("-..."), (char *)("-.-."), (char *)("-.."), (char *)("."), (char *)("..-."), (char *)("--."), (char *)("...."), (char *)(".."), // a-i (105)
(char *)(".---"), (char *)("-.-"), (char *)(".-.."), (char *)("--"), (char *)("-."), (char *)("---"), (char *)(".--."), (char *)("--.-"), (char *)(".-."), // j-r (114)
(char *)("..."), (char *)("-"), (char *)("..-"), (char *)("...-"), (char *)(".--"), (char *)("-..-"), (char *)("-.--"), (char *)("--.."), // s-z (122)
(char *)(""), (char *)(""), (char *)(""), (char *)("") // unsused (127)
};

/*
Period	 . _ . _ . _
Comma	 _ _ . . _ _
Question Mark	 . . _ _ . .
Semicolon	 _ . _ . _ .
Colon	_ _ _ . . .
Dash	_ . . . . _ 
Slash	_ . . _ . 
Apostrophe	 . _ _ _ _ . 
Quotations	. _ . . _ . 
*/