# Progresso da reescrita

Última atualização: 22/10/2026.

**Progresso funcional da reescrita: 0 de 7 etapas concluídas (0%).**

Este indicador conta etapas concluídas, não estima tempo nem quantidade de código. As versões antigas continuam como referência; sua funcionalidade não entra na contagem da reescrita.

Status disponíveis: **Planejado**, **Em andamento** e **Concluído**.

| Etapa | Funcionalidade | Situação na versão 1.7 | Status da reescrita |
| --- | --- | --- | --- |
| 1 | Sorteio Mega normal | Existe no código | Planejado |
| 2 | Tabela ↔ posição no escopo | Não identificado | Planejado |
| 3 | Sorteio pelo escopo | Não identificado | Planejado |
| 4 | Últimos 10 sorteios em memória | Não identificado | Planejado |
| 5 | Sorteios personalizados | Existe; validações precisam de revisão | Planejado |
| 6 | Interface gráfica | Interface principal pelo terminal, com alertas pontuais do Windows | Planejado |
| 7 | Salvar resultados em arquivo | Não identificado | Planejado |

A sequência abaixo é uma proposta de implementação. A conversão vem antes do sorteio pelo escopo porque será usada por ele.

## Etapa 1 — Sorteio Mega normal

- [ ] Separar a geração dos números da exibição no terminal.
- [ ] Gerar exatamente 6 números entre 1 e 60.
- [ ] Garantir números distintos dentro do resultado.
- [ ] Ordenar em ordem crescente.
- [ ] Conferir resultados e permitir novos sorteios.

**Concluída quando:** o novo código gera e apresenta resultados que atendem a todas as regras do sorteio normal.

## Etapa 2 — Tabela e posição no escopo

- [ ] Confirmar os conceitos de tabela e escopo descritos em FUNCIONALIDADES.md.
- [ ] Definir e documentar a enumeração e os limites dos identificadores.
- [ ] Converter tabela em identificador.
- [ ] Converter identificador em tabela.
- [ ] Validar entradas e conferir conversões de ida e volta, incluindo os extremos do escopo.

**Concluída quando:** as duas conversões são consistentes e entradas inválidas são rejeitadas.

## Etapa 3 — Sorteio pelo escopo

- [ ] Sortear um identificador válido com chances iguais entre as possibilidades.
- [ ] Recuperar a tabela usando a conversão da etapa 2.
- [ ] Exibir identificador e números da tabela.
- [ ] Conferir limites e validade dos resultados.

**Concluída quando:** o usuário consegue sortear uma posição e visualizar a combinação correspondente.

## Etapa 4 — Histórico em memória

- [ ] Definir os tipos de resultado que entram no histórico e suas informações.
- [ ] Armazenar até 10 resultados.
- [ ] Substituir o mais antigo ao exceder a capacidade.
- [ ] Listar e selecionar resultados armazenados.
- [ ] Definir e implementar as manipulações iniciais do histórico.
- [ ] Conferir o histórico vazio, com 10 resultados e após o 11º sorteio.

**Concluída quando:** os 10 resultados mais recentes podem ser consultados e usados nas manipulações definidas.

## Etapa 5 — Sorteios personalizados

- [ ] Definir limites de intervalo e quantidade.
- [ ] Configurar mínimo, máximo e quantidade de números.
- [ ] Configurar repetição e ordem de apresentação.
- [ ] Validar entradas, inclusive pedidos impossíveis sem repetição.
- [ ] Conferir as opções com e sem repetição e as três formas de apresentação.
- [ ] Integrar ao histórico conforme a regra definida na etapa 4.

**Concluída quando:** as configurações válidas funcionam e as inválidas recebem uma mensagem sem travar o programa.

## Etapa 6 — Interface gráfica

- [ ] Escolher a biblioteca gráfica.
- [ ] Definir as telas e a navegação.
- [ ] Integrar sorteio normal e sorteio pelo escopo.
- [ ] Integrar conversões entre tabela e identificador.
- [ ] Integrar histórico e sorteios personalizados.
- [ ] Conferir os fluxos e as mensagens de erro na interface.

**Concluída quando:** as funções anteriores podem ser utilizadas pela interface gráfica.

## Etapa 7 — Salvar resultados em arquivo

- [ ] Definir formato e local do arquivo.
- [ ] Definir quais resultados podem ser salvos e se a gravação será manual ou automática.
- [ ] Definir se novas gravações acrescentam resultados ou criam arquivos separados.
- [ ] Gravar os números, o tipo de sorteio e as informações de configuração aplicáveis.
- [ ] Informar sucesso e tratar falhas ao abrir ou gravar o arquivo.
- [ ] Disponibilizar o salvamento na interface gráfica.
- [ ] Conferir o conteúdo salvo após encerrar o programa e o tratamento de falhas de gravação.

**Concluída quando:** os resultados escolhidos pela regra definida são gravados corretamente e podem ser consultados no arquivo após o encerramento do programa.

## Histórico de entregas

| Data | Entrega |
| --- | --- |
| 22/10/2026 | Documentação inicial: funcionalidades, decisões em aberto e acompanhamento da reescrita. Nenhuma mudança no código. |
| 22/10/2026 | Incluído o salvamento de resultados em arquivo como sétima etapa planejada. |
