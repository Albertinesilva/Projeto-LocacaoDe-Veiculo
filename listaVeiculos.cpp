#include "listaVeiculos.hpp"

void insereVeiculo(vector<Veiculo> &listaVeiculos)
{
    limpaTela();
    Veiculo veiculo;

    cout << "\n\t===============INSERIR VEICULO============\n";
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
    cout << "\n\t===============LISTA DE VEICULOS============\n";
    for (auto it = listaVeiculos.begin(); it != listaVeiculos.end(); ++it)
    {
        it->mostraVeiculo();
    }
    pause();
}

void localizaVeiculo(vector<Veiculo> &listaVeiculos)
{
    string placaParaBusca;

    do
    {
        limpaTela();
        cout << "\n\t===============LOCALIZAR VEICULO============\n";
        cout << "\n\tInsira uma placa válida para fazer a busca : ";
        getline(cin, placaParaBusca);

    } while (!verificaPlaca(placaParaBusca));

    for (auto it = listaVeiculos.begin(); it != listaVeiculos.end(); it++)
    {
        if (it->placa == placaParaBusca)
        {
            limpaTela();
            cout << "\n\t===============VEICULO ENCONTRADO============\n";
            it->mostraVeiculo();
            pause();
            return;
        }
    }
}

void alteraVeiculo(vector<Veiculo> &listaVeiculos)
{
    limpaTela();
    string placaParaAlteracao;
    Data data;

    do
    {
        cout << "\n\t===============ALTERAR VEICULO============\n";
        cout << "\n\tInsira a placa do veiculo que deseja alterar dados : ";
        getline(cin, placaParaAlteracao);   

    } while (!verificaPlaca(placaParaAlteracao));

    limpaTela();
    for (auto it = listaVeiculos.begin(); it != listaVeiculos.end(); ++it)
    {
        if (it->placa == placaParaAlteracao)
        {
            int escolha;
            do
            { 
                cout << "\n\t===============VEICULO ENCONTRADO============\n";
                it->mostraVeiculo();
                pause();

                data.mostraDataAtual();
                cout << "\t========MENU ALTERAR VEICULO=========\n";
                cout << "\n\t[1] - ALTERAR RENAVAN:";
                cout << "\n\t[2] - ALTERAR PLACA:";
                cout << "\n\t[3] - ALTERAR DATA DE RETIRADA:";
                cout << "\n\t[4] - ALTERAR DATA DE ENTREGA:";
                cout << "\n\t[5] - ALTERAR LOJA DE RETIRADA:";
                cout << "\n\t[0] - SAIR";
                cout << "\n\tENTRADA ->  ";
                cin >> escolha;
                cin.get();

                switch (escolha)
                {
                case 1:
                    if (it->inserirRenavan())
                    {
                        cout << "\n\tRenavan alterado com sucesso" << endl;
                        pause();
                        break;
                    }
                    else
                    {
                        cout << "\n\tAlteração de renavan cancelada" << endl;
                        pause();
                        break;
                    }
                case 2:
                    if (it->inserirPlaca())
                    {
                        cout << "\n\tPlaca alterada com sucesso" << endl;
                        pause();
                        break;
                    }
                    else
                    {
                        cout << "\n\tAlteração de placa cancelada" << endl;
                        pause();
                        break;
                    }
                case 3:
                    if (it->inserirRetirada())
                    {
                        cout << "\n\tData de retirada alterada com sucesso" << endl;
                        pause();
                        break;
                    }
                    else
                    {
                        cout << "\n\tAlteração de data de retirada cancelada" << endl;
                        pause();
                        break;
                    }
                case 4:
                    if (it->inserirEntrega())
                    {
                        cout << "\n\tData de entrega alterada com sucesso" << endl;
                        pause();
                        break;
                    }
                    else
                    {
                        cout << "\n\tAlteração de data de entrega cancelada" << endl;
                        pause();
                        break;
                    }
                case 5:
                    if (it->inserirLoja())
                    {
                        cout << "\n\tLoja de retirada alterada com sucesso" << endl;
                        pause();
                        break;
                    }
                    else
                    {
                        cout << "\n\tAlteração de loja de retirada cancelada" << endl;
                        pause();
                        break;
                    }
                case 0:

                    pause();
                    break;

                default:
                    break;
                }
                
            } while (escolha != 0);
        }
    }
}