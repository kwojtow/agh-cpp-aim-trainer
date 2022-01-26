W ramach projektu stworzono prostą grę służącą do ćwiczenia refleksu i celności.

Gra została stworzona w oparciu o bibliotekę SFML.

Do działania gra potrzebuje biblioteki SFML oraz sqlite3.

Aby uruchomić aplikację należy wykonać polecenie make w katalogu z aplikacją.

Gra polega na zestrzelaniu celów pojawiających się kolejno na ekranie.
Cele podzielone są na dwie grupy - czerwone i zielone. Czerwone cele należy zestrzelać lewym przyciskiem myszy, zielone prawym.
W grze dostępne są trzy poziomy trudności:
- NOOB,
- MEDIUM,
- PRO,
które różnią się szybkością powiększania celów i ich ilością na ekranie w jednej chwili.

Gra kończy się w momencie zestrzelenia określonej liczby celów.
Na podstawie wielkości celu w momencie zestrzelenia naliczane są punkty karne - im większy rozmar celu w momecie zestrzelenia tym mnijszy wynik.
Po zakończeniu rozgrywki gracz może podać swój nick i zapisać uzyskany wynik.
Na koniec wyświetlany jest rankin najlepszych wyników.
