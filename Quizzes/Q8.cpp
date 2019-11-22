// Purpose: Take in the text and be able to find the most common word and output
// it.
// Input: 
//   txt - String of words separated by spaces where a word consists of
//         alpha-numeric characters.
// Output: The most frequent word in the string
string most_common_word(string txt);

// Tests
// ---
// Input                        Output
// "The cat ate the food"       "the"
// "The cat ate the cat food"   "the"
// "thecatatethecatfood"        "thecatatethecatfood"
// " "                          ""
// "20 cats ate 20 biscuits"    "20"
// "dddd"                       "dddd"
// "A B C D D"                  "D"
// "Cat the cat"                "cat"
// "hello     hello cat"        "hello"

// Template
// int i = 0;
// while(i < s.length()){
//   ..s[i]..
//   i = i + 1;
// }

//Pseudo Code
//* identify words and separate them into a list.
//** until we run out of words.
//** find the last word.
//*** find the last letter.
//*** find the first letter of the last word.
//*** get the substring between the first and last letter.
//** transfer word to list.
//** chop off the last word.
//* find the most frequent word in the list of words.
//** Count the amount of times each word appears.
//** Put it in a list in the same location as the first instance of the word.
//** Go back through the list of numbers and grab the highest one.
//** Identify the word associated with that number.
string most_common_word(string txt){
	vector<string> words = split_by_word(txt);
	string word = most_frequent(words);
	return word;
}

// Identify words and separate them into a list.
vector<string> split_by_word(string txt){
	int i = txt.length() - 1;
	vector<string> words = [];
	//** until we run out of words.
	while (i >= 0){
		//*** find the last word.
		words.push_back(find_last_word())
		//**** find the last letter.
		//**** find the first letter of the last word.
		//**** get the substring between the first and last letter.
		i = i - 1;
	}
	//** transfer word to list.
	//** chop off the last word.
}
string find_last_word(string txt) {
	int i = txt.length() - 1;
	string word;
	
	while(i >= 0 && alpha_numeric(txt[i])) {
		i = i - 1;
	}
	get_substring(txt, i, txt.length());
	return word;
}
//* find the most frequent word in the list of words.
string most_frequent(vector<string> words){
	
}
//** Count the amount of times each word appears.
//** Put it in a list in the same location as the first instance of the word.
//** Go back through the list of numbers and grab the highest one.
//** Identify the word associated with that number.
