class Morse
{
private:
  Morse() = delete;
  ~Morse() = delete;
  static const int delayMillis = 125;
  static void Toggle(const pin_t LED, const int onLengthMillis);
  
  static String morseLookup(const char character);
  static char morse[][7];
  
public:
  static void printMorse(const char message[], const pin_t LED);
};



String Morse::morseLookup(const char character)
{
  switch (character)
  {
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";
    case '0': return "-----";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    case ' ': return "----";
    default: return "";
  }
}

void Morse::Toggle(const pin_t LED, const int onLengthMillis)
{
  // On
  digitalWrite(LED, HIGH);
  // Wait
	delay(onLengthMillis);
  // Off
	digitalWrite(LED, LOW);
}

void Morse::printMorse(const char message[], const pin_t LED)
{
  // For each character
  for (size_t messageIndex = 0; messageIndex < strlen(message); messageIndex++)
  {
    // Store character
    const char character = message[messageIndex];
    
    // Store morse sequence
    const String morse = morseLookup(toupper(character));
    
    // Pass if the character is not in the morse lookup
    if(morse == "") continue;
    
    // For each dot/dash in the morse sequence
    for (size_t j = 0; j < strlen(morse); j++)
    {
      // Print dot or dash respectively
      if(morse[j] == '.') Toggle(LED, Morse::delayMillis);
      else Toggle(LED, Morse::delayMillis*2);
      
      // Gap between dot/dash
      delay(Morse::delayMillis);
    }
    // Gap between characters
    delay(Morse::delayMillis*2);
  }
}
