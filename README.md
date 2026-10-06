# Automacao de Estufa com Arduino

Projeto de controle de temperatura para uma pequena estufa usando Arduino Uno, sensor TMP36, ventilacao e sinalizacao de emergencia.

## Funcionamento

O Arduino faz uma leitura do sensor TMP36 a cada segundo e calcula a temperatura em graus Celsius.

- Abaixo de `30 °C`: o motor permanece desligado.
- A partir de `30 °C`: o motor e acionado para ventilacao.
- Acima de `50 °C`: o LED vermelho e o buzzer sao acionados como alerta de emergencia.
- A temperatura calculada e enviada ao Monitor Serial em `9600 baud`.

## Componentes

| Quantidade | Componente |
| ---: | --- |
| 1 | Arduino Uno R3 |
| 1 | Sensor de temperatura TMP36 |
| 1 | Resistor de `200 ohms` |
| 1 | Resistor de `1 k ohm` |
| 1 | LED vermelho |
| 1 | Piezo/buzzer |
| 1 | Transistor NPN |
| 1 | Diodo |
| 1 | Motor CC |
| 1 | Placa de ensaio pequena |

## Pinos utilizados

| Funcao | Pino |
| --- | --- |
| Saida do TMP36 | `A0` |
| LED vermelho | `D8` |
| Buzzer | `D9` |
| Controle do motor | `D10` |

## Ligacao do motor

O motor deve ser alimentado por uma fonte adequada e acionado por um estagio de potencia com o transistor NPN. O pino `D10` deve controlar a base do transistor por meio do resistor de `1 k ohm`.

O diodo deve ser instalado em paralelo com o motor para absorver a tensao reversa gerada quando ele e desligado. O GND da fonte do motor e o GND do Arduino devem ser comuns.

Nao ligue o motor diretamente ao pino `D10`: a corrente do motor pode danificar o Arduino.

## Como usar

1. Monte o circuito conforme a tabela de pinos e o estagio de acionamento do motor.
2. Abra `estufa1.ino` na Arduino IDE.
3. Selecione a placa Arduino Uno e a porta serial correta.
4. Compile e carregue o programa.
5. Abra o Monitor Serial em `9600 baud` para acompanhar a temperatura.

## Arquivos

- `estufa1.ino`: codigo-fonte do controle da estufa.
- `bom.csv`: lista de materiais do projeto.

## Observacoes

A conversao do TMP36 assume uma referencia ADC de `5 V` e usa a relacao aproximada:

```text
temperatura = (tensao - 0,5) x 100
```

O projeto atual controla apenas temperatura e ventilacao. Ele ainda nao possui controle de umidade, aquecimento ou irrigacao.