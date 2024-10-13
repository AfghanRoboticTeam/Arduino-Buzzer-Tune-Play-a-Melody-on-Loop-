// Pin assignment
const int buzzerPin = 8; // Buzzer connected to pin 8

// Notes for the Happy Birthday song
int melody[] = {
  262, 262, 294, 262, 349, 330, 
  262, 262, 294, 262, 392, 349, 
  262, 262, 523, 440, 349, 330, 294, 
  466, 466, 440, 349, 392, 349
};

// Note durations: 4 = quarter note, 8 = eighth note, etc.
int noteDurations[] = {
  4, 8, 4, 4, 4, 2, 
  4, 8, 4, 4, 4, 2, 
  4, 8, 4, 4, 4, 8, 8, 
  4, 8, 4, 4, 4, 2
};

void setup() {
  pinMode(buzzerPin, OUTPUT);  // Set buzzer pin as output
}

void loop() {
  playMelody();
}

void playMelody() {
  for (int i = 0; i < 25; i++) {
    int noteDuration = 1000 / noteDurations[i];
    tone(buzzerPin, melody[i], noteDuration);
    // Pause between notes
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // Stop the tone
    noTone(buzzerPin);
  }
}
