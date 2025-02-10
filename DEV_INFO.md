# Informacje o projekcie
## Struktura projektu
1. Pliki źródłowe (.c i .cpp) zapisujemy w folderze `src/`
2. Pliki nagłówkowe (.h) zapisujemy w folderze `include/`
3. Gotowe biblioteki (raylib itp.) zapisujemy w folderze `lib/`
4. W folderze `bin/` znajdują się pliki wykonywalne
5. W folderze `obj/` znajdują się pliki obiektowe

## Konwencje GIT
1. commity nazywamy po angielsku

## Konwencje w kodzie
1. TAB to 2 spacje
2. po nazwie pętli lub instrukcji warunkowej dajemy spację przed nawiasem
3. nawiasy klamrowe w tej samej lini po spacji
4. nie używamy `using namespace`

Przykład kodu:

```cpp
#include <iostream>

int main() {
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      std::cout << "Parzysta\n";
    } else {
      std::cout << "Nie parzysta\n";
    }
  }
  
  return 0;
}
```

## Uruchamianie
- `make` - kompiluje program
- `make clean` - usuwa starą kompilację
- Pilk wykonywalny gry jest w `bin/game.exe`