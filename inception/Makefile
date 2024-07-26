SRC =  -f ./srcs/docker-compose.yml
# VOLUME = ./srcs/data/mariadb ./srcs/data/wordpress
# VOLUME = /Users/hyobicho/42projects/inception/srcs/data/mariadb /Users/hyobicho/42projects/inception/srcs/data/wordpress
VOLUME = /home/hyobicho/data/mariadb /home/hyobicho/data/wordpress

all: up

up:
	mkdir -p $(VOLUME)
	docker compose $(SRC) up --build -d

down:
	docker compose $(SRC) down

clean-volume:
	docker volume rm inception_db_vol
	docker volume rm inception_wp_vol
	rm -rf $(VOLUME)

clean:
	docker system prune -a -f
	docker network prune -f

fclean:
	make clean
	make clean-volume

re:
	make down
	make up

logs:
	docker compose $(SRC) logs

.PHONY : up down clean re