DROP IF DATABASE EXISTS;
CREATE DATABASE campeonato;
USE campeonato;
CREATE TABLE jugador(
	identificador INTEGER PRIMARY KEY NOT NULL, 
	nombre TEXT NOT NULL, 
	contraseña TEXT NOT NULL, 
	puntos INTEGER PRIMARY KEY NOT NULL)ENGINE = InnoDB;

CREATE TABLE partida(
	identificador INTEGER PRIMARY KEY NOT NULL, 
	ciudad TEXT NOT NULL, 
	time INTEGER PRIMARY KEY NOT NULL,
	ganador TEXT NOT NULL)ENGINE = InnoDB;

CREATE TABLE relacion(
	Jugador INTEGER NOT NULL,
  	Partida INTEGER NOT NULL,
	Posicion INTEGER NOT NULL,
  	FOREIGN KEY (Jugador) REFERENCES jugador(identificador),
  	FOREIGN KEY (Partida) REFERENCES partida(identificador))ENGINE = InnoDB;


INSERT INTO jugador(identificador, nombre, contraseña, puntos) VALUES (1, 'Juan', 'bfd', 56);
INSERT INTO jugador(identificador, nombre, contraseña, puntos) VALUES (2, 'Felix', 'fgsfvc',556);
INSERT INTO jugador(identificador, nombre, contraseña, puntos) VALUES (3, 'Fermin', 'vcx', 96);
INSERT INTO jugador(identificador, nombre, contraseña, puntos) VALUES (4, 'Jaume', 'svacx', 06);
INSERT INTO jugador(identificador, nombre, contraseña, puntos) VALUES (5, 'Lluis', 'vdscxz', 65);

INSERT INTO partida(identificador, ciudad, time, ganador) VALUES (1, 'Barcelona',112201082024, 'Felix');
INSERT INTO partida(identificador, ciudad, time, ganador) VALUES (2, 'Madrid',112201062024, 'Jaume');
INSERT INTO partida(identificador, ciudad, time, ganador) VALUES (3, 'Bilbao',112224082024, 'Lluis');

INSERT INTO relacion(Jugador, Partida, Posicion) VALUES (1,3,3);
INSERT INTO relacion(Jugador, Partida, Posicion) VALUES (4,5,1);
INSERT INTO relacion(Jugador, Partida, Posicion) VALUES (1,1,1);


