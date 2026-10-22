# Sorteio Mega

Projeto em C para gerar sorteios e explorar suas possibilidades. O código será refeito aos poucos, acrescentando funções por etapas.

## Código existente

- `1.0/` e `1.5/`: versões anteriores.
- `1.7/`: versão mais recente encontrada, com sorteio normal, múltiplos sorteios pelo teclado e sorteio personalizado.

A documentação organiza a próxima implementação. Uma função existir na versão antiga não significa que sua reescrita esteja concluída.

## Documentação

- [Funcionalidades e regras](docs/FUNCIONALIDADES.md): comportamento esperado e pontos ainda em aberto.
- [Progresso da reescrita](docs/PROGRESSO.md): etapas, tarefas e critérios de conclusão.

## Como acompanhar

Marcar uma tarefa com `[x]` quando estiver implementada e conferida. Atualizar o status da etapa e registrar uma nota no histórico ao concluir uma entrega.

## Compilação da versão 1.7

O código usa `conio.h` e `windows.h` e foi escrito para Windows. Com GCC disponível (por exemplo, MinGW), na raiz do repositório:

```powershell
gcc -std=c99 projetos/sorteio_mega/1.7/sorteiomega.c -o projetos/sorteio_mega/1.7/sorteiomega.exe
.\projetos\sorteio_mega\1.7\sorteiomega.exe
```

A compilação não foi validada nesta organização inicial. As versões históricas foram incluídas como referência; a reescrita ainda está planejada.
