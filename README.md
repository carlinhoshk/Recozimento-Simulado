# Algoritmo de Recozimento Simulado

Este repositório contém a implementação simples do **Algoritmo de Recozimento Simulado** (Simulated Annealing) para problemas de otimização. Ele utiliza o conceito de resfriamento gradual para encontrar soluções próximas do ótimo local.

Explore e modifique o código para se aprofundar nos conceitos de metaheurísticas e otimização!

![image](https://github.com/user-attachments/assets/ff662251-f0ad-4d0f-8a98-50a718c7ebb2)

# Fluxo grama do algoritimo  
```mermaid
flowchart TD
    A[Início] --> B[Inicializar solução atual e temperatura]
    B --> C[Avaliar solução atual]
    C --> D{Temperatura > temperatura mínima?}
    D -->|Sim| E[Gerar nova solução vizinha]
    E --> F[Avaliar nova solução]
    F --> G{Nova solução é melhor?}
    G -->|Sim| H[Aceitar nova solução]
    G -->|Não| I{Aceitar com probabilidade?}
    I -->|Sim| H
    I -->|Não| J[Manter solução atual]
    H --> K[Atualizar solução atual]
    J --> K
    K --> L[Reduzir temperatura]
    L --> D
    D -->|Não| M[Retornar melhor solução encontrada]
    M --> N[Fim]
