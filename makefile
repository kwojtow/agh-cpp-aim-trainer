all:
	g++ -c main.cpp Target.cpp Button.cpp LevelMenu.cpp Game.cpp TextInput.cpp ResultsScreen.cpp DatabaseService.cpp Row.cpp Table.cpp RankScreen.cpp Application.cpp
	g++ main.o Target.o Button.o LevelMenu.o Game.o TextInput.o ResultsScreen.o DatabaseService.o Row.o Table.o RankScreen.o Application.o -o main -lsfml-graphics -lsfml-window -lsfml-system -lsqlite3
	./main

