# Corrida de Cavalos com Threads em C

Simulação de uma corrida de cavalos no terminal utilizando linguagem C e a biblioteca `pthreads`. Cada cavalo é representado por uma thread que avança concorrentemente na tela.

O projeto tem como foco a prática de concorrência, sincronização e manipulação de saída no terminal.


## Funcionamento

- O usuário define a quantidade de cavalos (threads)
- Cada thread representa um cavalo
- Todas aguardam em uma barreira antes de iniciar
- Os cavalos avançam no terminal simultaneamente
- Ao final, cada thread registra sua posição de chegada


## Concorrência e Sincronização

- **Mutex (`print_lock`)**: controla o acesso ao terminal para evitar sobreposição de escrita  
- **Mutex (`win_lock`)**: garante a ordem correta de chegada  
- **Barrier**: sincroniza o início da corrida


## Compilação

```
make
```

## Execução

```
make run
```
ou:
```
./horse_race
```
