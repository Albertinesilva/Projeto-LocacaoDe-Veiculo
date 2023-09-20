#include "listaVeiculos.hpp"

void insereVeiculo(vector<Veiculo> &listaVeiculos)
{
    limpaTela();
    Veiculo veiculo;

    cout << "\n\t===============INSERIR VEICULO============";
    if (veiculo.preencheVeiculo())
    {
        for (auto it = listaVeiculos.begin(); it != listaVeiculos.end(); ++it)
        {
            if (it->placa == veiculo.placa)
            {
                limpaTela();
                cout << "\n\t===============ERRO============\n";
                cout << "\tPlaca já cadastrada" << endl;
                cout << "\n\tOps, não foi possivel inserir novo veiculo";
                cin.get();
                pause();
                return;
            }
        }
        listaVeiculos.push_back(veiculo);
        cout << "\n\tVeiculo inserido com sucesso" << endl;
        pause();
    }
    else
    {
        cout << "\n\tNão foi possivel inserir novo veiculo" << endl;
        cin.get();
        pause();
    }
}

void excluiVeiculo(vector<Veiculo> &listaVeiculos)
{
    string placaParaBusca;

    do
    {
        limpaTela();
        cout << "\n\t===============REMOVER VEICULO============\n";
        cout << "\n\tInsira uma placa válida para exclusão : ";
        cin >> placaParaBusca;
    } while (!verificaPlaca(placaParaBusca));

    for (auto it = listaVeiculos.begin(); it != listaVeiculos.end(); ++it)
    {
        if (it->placa == placaParaBusca)
        {
            listaVeiculos.erase(it);
            cout << "\n\tVeiculo excluido com sucesso" << endl;
            pause();
            return;
        }
    }
    limpaTela();
    cout << "\n\tO Veiculo de placa " << placaParaBusca << " não se encontra em nosso banco de dados" << endl;
    cin.get();
    pause();
}

void listarVeiculos(vector<Veiculo> &listaVeiculos)
{
    limpaTela();
    cout << "\n\t===============LISTAR VEICULOS============\n";
    for (auto it = listaVeiculos.begin(); it != listaVeiculos.end(); ++it)
    {
        it->mostraVeiculo();
    }

    cin.get();
    pause();
}

void localizaVeiculo(vector<Veiculo> &listaVeiculos)
{
    string placaParaBusca;

    do
    {
        limpaTela();
        cout << "\n\t===============LOCALIZAR VEICULO============\n";
        cout << "\n\tInsira um cpf válido para busca : ";
        cin >> placaParaBusca;

    } while (!verificaPlaca(placaParaBusca));

    for (auto it = listaVeiculos.begin(); it != listaVeiculos.end(); ++it)
    {
        if (it->placa == placaParaBusca)
        {
            limpaTela();
            cout << "\n\t===============VEICULO ENCONTRADO============";
            it->mostraVeiculo();
            return;
        }
    }
}

void alteraVeiculo(vector<Veiculo> &listaVeiculos)
{
    string placaParaAlteracao;
    Data data;

    do
    {
        limpaTela();
        cout << "\n\t===============ALTERAR VEICULO============\n";
        cout << "\n\tInsira a placa do veiculo que deseja alterar dados : ";
        cin >> placaParaAlteracao;

    } while (!verificaPlaca(placaParaAlteracao));

    for (auto it = listaVeiculos.begin(); it != listaVeiculos.end(); ++it)
    {
        if (it->placa == placaParaAlteracao)
        {
            int escolha;
            do
            { 
                it->mostraVeiculo();
                pause();

                data.mostraDataAtual();
                cout << "\t========MENU ALTERAR VEICULO=========\n";
                cout << "\n\t[1] - ALTERAR RENAVAN:";
                cout << "\n\t[2] - ALTERAR MODELO:";
                cout << "\n\t[3] - ALTERAR COR:";
                cout << "\n\t[4] - ALTERAR PLACA:";
                cout << "\n\t[5] - ALTERAR DATA DE RETIRADA:";
                cout << "\n\t[6] - ALTERAR DATA DE ENTREGA:";
                cout << "\n\t[7] - ALTERAR LOJA DE RETIRADA:";
                cout << "\n\t[0] - SAIR";
                cout << "\n\tENTRADA ->  ";
                cin >> escolha;

                switch (escolha)
                {
                case 1:
                    if (it->inserirRenavan())
                    {
                        limpaTela();
                        cout << "\n\tRenavan alterado com sucesso" << endl;
                        pause();
                        break;
                    }
                    else
                    {
                        limpaTela();
                        cout << "\n\tAlteração de renavan cancelada" << endl;
                        pause();
                        break;
                    }
                case 2:
                    if (it->inserirPlaca())
                    {
                        limpaTela();
                        cout << "\n\tPlaca alterada com sucesso" << endl;
                        pause();
                        break;
                    }
                    else
                    {
                        limpaTela();
                        cout << "\n\tAlteração de placa cancelada" << endl;
                        pause();
                        break;
                    }
                case 3:
                    if (it->inserirRetirada())
                    {
                        limpaTela();
                        cout << "\n\tData de retirada alterada com sucesso" << endl;
                        pause();
                        break;
                    }
                    else
                    {
                        limpaTela();
                        cout << "\n\tAlteração de data de retirada cancelada" << endl;
                        pause();
                        break;
                    }
                case 4:
                    if (it->inserirEntrega())
                    {
                        limpaTela();
                        cout << "\n\tData de entrega alterada com sucesso" << endl;
                        pause();
                        break;
                    }
                    else
                    {
                        limpaTela();
                        cout << "\n\tAlteração de data de entrega cancelada" << endl;
                        pause();
                        break;
                    }
                case 5:
                    if (it->inserirLoja())
                    {
                        limpaTela();
                        cout << "\n\tLoja de retirada alterada com sucesso" << endl;
                        pause();
                        break;
                    }
                    else
                    {
                        limpaTela();
                        cout << "\n\tAlteração de loja de retirada cancelada" << endl;
                        pause();
                        break;
                    }
                case 6:
                    pause();
                    break;
                default:
                    break;
                }
            } while (escolha != 6);
        }
    }
}