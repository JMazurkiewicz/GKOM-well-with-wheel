# Studnia z kołowrotkiem

## Zrzuty ekranów

### Zdjęcie modelowanej studni

![img](docs/pics/studnia.png)

### Zdjęcie gotowej studni

![img](docs/pics/well-done.png)

## Poruszanie

Kontrola kamery:

* WASD - zmiana pozycji
* Mysz - poruszanie widokiem
* Ctrl/Spacja - ruch dół/góra

Kontrola koła:

* Strzałka w lewo - rozwijanie
* Strzałka w prawo - zwijanie

## Opis modułów

1. `Controler` - moduł zawierający obsługę zdarzeń i kontrolery obiektów na scenie

2. `GlModel` - moduł zawierający model obiektu, który może być wyświetlony na scenie

3. `Graphics` - moduł zawierający podstawowe klasy do obsługi grafiki (np. `Shader`, `Vertex`)

4. `LibraryExceptions` - moduł zawierający klasy wyjątków rzucanych przez biblioteki graficzne

5. `Model` - moduł zawierający parametryczne modele obiektów znajdujących się na scenie

6. `ModelGeneration.BasicGenerators` - moduł zawierający generatory podstawowych kształtów (np. walców, prostopadłościanów)

7. `ModelGeneration.WellGeneration` - moduł zawierający generatory elementów, z których składa się studnia

8. `Startup` - moduł zawierający klasy/metody odpowiedzialne za prawidłowe załadowanie i wykonanie programu

9. `System` - moduł zawierający klasy charakterystyczne dla platformy

10. `View` - moduł zawierający klasy odpowiedzialne za wyświetlanie obiektów na scenie

## Podział pracy

* Jakub Mazurkiewicz - generowanie modeli, architektura programu
* Damian Piotrowski - oświetlenie, tekstury
* Jan Such - praca kamery

## Milestones (wszystkie ukończone)

* Uruchomienie wersji przykładowej
* Stworzenie uproszczonych modeli testowych i oświetlenia
* Praca kamery (`Controler.Camera`)
* Model studni (`ModelGeneration.WellGeneration`)
* Dopracowanie oświetlenia / kamery
* Interaktywność - kołowrót (`Controler.WheelControler`)
* Zaprezentowanie skończonego projektu (25/30)
