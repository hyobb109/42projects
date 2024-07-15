SRC =  -f ./srcs/docker-compose.yml
VOLUME = ./srcs/data/mariadb ./srcs/data/wordpress

all: up

up:
	mkdir -p $(VOLUME)
	docker compose $(SRC) up --build -d

down:
	docker compose $(SRC) down

clean-volume:
	rm -rf $(VOLUME)

clean:
	docker system prune -a

fclean:
	make clean
	make clean-volume

re:
	make down
	make up

.PHONY : up down clean re