<h1 align="center" style="color:white; background-color:black">TAL</h1>
<h2 align="center" style="color:white; background-color:black">Tupã Abstraction Layer</h2>

<h4 align="center">Classes genéricas utilizadas por todos os microcontroladores</h4>

<p align="center">
    <a href="https://tupa.eesc.usp.br//">
    <img src="https://img.shields.io/badge/Tupã-Generics-black?style=for-the-badge"/>
    </a>
    <a href="https://eesc.usp.br/">
    <img src="https://img.shields.io/badge/Linked%20to-EESC--USP-black?style=for-the-badge"/>
    </a>
</p>
<p align="center">
    <a href="https://github.com/EESC-USP-TUPA/Generics/issues">
    <img src="https://img.shields.io/github/issues/EESC-USP-TUPA/Generics?style=for-the-badge"/>
    </a>
    <a href="https://github.com/EESC-USP-TUPA/Generics/commits/main">
    <img src="https://img.shields.io/github/commit-activity/m/EESC-USP-TUPA/Generics?style=for-the-badge">
    </a>
    <a href="https://github.com/EESC-USP-TUPA/Generics/graphs/contributors">
    <img src="https://img.shields.io/github/contributors/EESC-USP-TUPA/Generics?style=for-the-badge"/>
    </a>
    <br>
    <a href="https://github.com/EESC-USP-TUPA/Generics/commits/main">
    <img src="https://img.shields.io/github/last-commit/EESC-USP-TUPA/Generics?style=for-the-badge"/>
    </a>
    <a href="https://github.com/EESC-USP-TUPA/Generics/issues">
    <img src="https://img.shields.io/github/issues-raw/EESC-USP-TUPA/Generics?style=for-the-badge" />
    </a>
    <a href="https://github.com/EESC-USP-TUPA/Generics/pulls">
    <img src = "https://img.shields.io/github/issues-pr-raw/EESC-USP-TUPA/Generics?style=for-the-badge">
    </a>
</p>

## Objetivo

O objetivo deste repositório é armazenar classes relativas aos diferentes protocolos de comunicação utilizados no projeto.

É ideal que as classes sejam capazes de abstrair ainda mais a HAL (Hardware Abstraction Layer) para que esta não seja necessária ao usuário final.

A implementação destas classes permite uma padronização no código de todos os microcontroladores, bem como garante que sempre se estará utilizando
funções que foram previamente testadas e validadas.

## Escopo

São implementadas como classes genéricas:

- ADC
- GPIO
- CAN
- I2C
- UART/USART
- SPI
- Filtros Digitais

## Complementos

[Documentação](https://docs.google.com/document/d/1eUKlfLGgAHjWBRXNp35zcnhgNHb5ZKfJx6TLp2YPtLc/edit)
