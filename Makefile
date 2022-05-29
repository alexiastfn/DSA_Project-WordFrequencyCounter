build: 
	gcc -o tema1 word_list.c over_lenght_list.c tabela_hash.c main.c
run:
	./tema1
clean:
	rm -rf tema1