# Funcionalidades planejadas

Planejamento inicial registrado em 22/10/2026.

## 1. Sorteio Mega normal

- Gerar um sorteio com exatamente 6 números de 1 a 60, inclusive.
- Não repetir números dentro do mesmo sorteio.
- Apresentar os números em ordem crescente.
- Permitir realizar novos sorteios.

Exemplo de resultado válido: `03 : 12 : 24 : 35 : 46 : 60`.

A regra de não repetição se refere aos números de um resultado. Por enquanto, não há requisito de impedir que a mesma combinação apareça em sorteios diferentes.

## 2. Sorteio no escopo de possibilidades

Interpretação provisória para este planejamento:

- **Tabela:** uma combinação de 6 números distintos, organizada em ordem crescente.
- **Escopo de possibilidades:** o conjunto de todas essas combinações entre 1 e 60.
- **Identificador da tabela:** sua posição em uma enumeração fixa do escopo.

Existem `C(60, 6) = 50.063.860` combinações possíveis. A ordem dos números não cria uma combinação diferente.

A função deve sortear um identificador válido no escopo e obter a tabela correspondente. Cada combinação deve ter a mesma chance de ser escolhida.

A ordem de enumeração e a numeração inicial dos identificadores ainda precisam ser definidas. O escopo pode ser representado por cálculos; não é necessário armazenar todas as combinações na memória.

## 3. Histórico dos últimos 10 sorteios

- Guardar em memória até 10 resultados, durante a execução do programa.
- Inserir cada novo sorteio no histórico.
- Quando chegar o 11º resultado, descartar o mais antigo.
- Permitir consultar os resultados e selecionar um deles para as operações disponíveis.
- Guardar os números e informações necessárias para interpretar cada resultado, incluindo sua configuração quando for personalizado.

O salvamento em arquivo será desenvolvido em uma etapa própria (funcionalidade 7). As manipulações adicionais e a inclusão de todos os tipos de sorteio no mesmo histórico ainda precisam ser detalhadas.

## 4. Conversão entre tabela e posição no escopo

- Receber uma tabela válida e encontrar seu identificador no escopo.
- Receber um identificador válido e recuperar a tabela correspondente.
- Usar a mesma enumeração nas duas direções e no sorteio pelo escopo.
- Rejeitar números repetidos, valores fora do intervalo e identificadores inválidos.
- Garantir que converter uma tabela em identificador e voltar produza a mesma tabela.

Inicialmente, essa conversão considera apenas a regra normal: 6 números distintos entre 1 e 60.

## 5. Sorteios personalizados

A versão 1.7 já oferece opções que servirão como referência para a reescrita:

- Valor mínimo e máximo.
- Quantidade de números por sorteio.
- Permitir ou impedir repetição dentro do resultado.
- Apresentação crescente, decrescente ou na ordem de geração.

A nova implementação deve validar as entradas antes de sortear. O mínimo não pode superar o máximo, a quantidade deve ser positiva e, sem repetição, não pode exceder a quantidade de valores disponíveis no intervalo. Entradas não numéricas devem ser tratadas.

Os limites finais de valores e quantidade serão definidos durante esta etapa; os avisos da interface antiga não serão tratados como validações já implementadas.

## 6. Interface gráfica

- Disponibilizar as funções implementadas por meio de uma interface gráfica.
- Exibir resultados, histórico e mensagens de validação.
- Permitir configurar os sorteios personalizados.
- Permitir consultar tabelas e identificadores do escopo.

A biblioteca gráfica e o desenho das telas ainda serão escolhidos. A lógica dos sorteios deve ficar separada da interface, permitindo desenvolver e conferir as funções primeiro no terminal.

## 7. Salvar resultados em arquivo

- Permitir salvar os resultados dos sorteios em arquivo para consulta após encerrar o programa.
- Registrar os números sorteados e o tipo de sorteio.
- Para resultados personalizados, registrar também a configuração necessária para interpretar os números.
- Registrar o identificador no escopo quando ele estiver disponível.
- Informar se o salvamento foi concluído ou se ocorreu um erro de gravação.

O formato do arquivo, o local de salvamento, a escolha dos resultados e o modo de gravação (manual ou automático) ainda serão definidos. Também será decidido se novas gravações acrescentam resultados ao arquivo ou criam arquivos separados.

Carregar resultados de um arquivo de volta para o programa ainda não está previsto nesta função.

## Decisões em aberto

- Confirmar se “tabela” significa uma combinação e se “escopo” significa todas as combinações, como proposto acima.
- Definir a enumeração do escopo e se o primeiro identificador será 0 ou 1.
- Definir quais manipulações serão oferecidas sobre os últimos 10 sorteios.
- Definir como o histórico reúne resultados normais e personalizados.
- Definir limites dos sorteios personalizados e a biblioteca da interface gráfica.
- Definir formato, local, seleção dos resultados e modo de gravação dos arquivos.
