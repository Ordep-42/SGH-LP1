# SGH-LP1



----------
## Rodando o projeto

1. Instale o c++
2. Instale o [cmake](https://cmake.org/download/)  
3. use o script para compilar e rodar o projeto:

```bash
bash ./run.sh
```

## Desenvolvimento

- [x] Organizar arquivos 
- [x] Criar interface de paciente
    - [ ] Marcar consulta // 80% ok
    - [ ] Listar consultas // 80% ok 
    - [ ] Cancelar consulta // 0% ok 
    - [ ] Listar dados // 0%  ok
    - [ ] Atualizar dados // 0% ok
- [ ] criar função de validação de usuário
    - [ ] validateDoctor 
    - [ ] validatePatient
    - [ ] validateManager
    - [ ] validateAttendant
- [x] Criar Interface de manager 
    - [x] Criar :
        - [x] paciente
        - [x] doutor
        - [x] manager
    - [x] Listar:
        - [x] paciente
        - [x] doutor
        - [x] manager
    - [x] Deletar:
        - [x] paciente
        - [x] doutor
        - [x] manager

- [ ] Criar função createAppointment para classe HospitalDatabase
