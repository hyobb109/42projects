SRC =  -f ./srcs/docker-compose.yml
FLAGS = --build -d

up:
	docker compose $(SRC) up $(FLAGS)
down:
	docker compose $(SRC) down

.PHONY : up down