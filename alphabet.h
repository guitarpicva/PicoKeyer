// lookup table for the Morse alphabet covers ASCII 0-127 (0x00 - 0x7f)
char* alphabet[] = { 
"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",  //unused (20)
"", "", "", "", "", "", "", "", "", "", "", " ", "", "", "", "", "", "", "", "", "", // unused (41) (SPACE is 32)
"", ".-.-.", "--..--", "-....-", "..--..", "-..-.",  // Punctuation: + (AR) , - . / (47)
"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", // 0-9 (57)
"", "", "", "-...-", "", ".-.-.-", "",// Punctuation:  = (BT) ? (64)
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I (73)
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R (82)
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", // S-Z (90)
"", "", "", "", "", "", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // a-i (105)
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // j-r (114)
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", // s-z (122)
"", "", "", "" // unsused (127)
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