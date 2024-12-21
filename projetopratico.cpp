#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct filosofo {
	char nome[30];
    char sexo;
    char nacionalidade[15];  // Ajuste o tamanho conforme necessário
    short anoNascimento;
    short anoFalecimento;
    char corrente[25];
    char descricao[500];
};

int main() {
   
    string linha;
    int numRegistros;
    
    ifstream arquivo_csv("entrada.csv");
    
    if (!arquivo_csv) {
        cout << "Erro ao abrir arquivo" << endl;
    } else {
        getline(arquivo_csv, linha); // descarta a linha inicial
        arquivo_csv >> numRegistros;
        arquivo_csv.ignore(); // Ignora o caractere de nova linha após o número de registros
    }
    
    filosofo *persona = new filosofo[numRegistros];

    for (int i = 0; i < numRegistros; i++) {

        // Lendo os dados com cuidado para evitar cortar palavras
        arquivo_csv.getline(persona[i].nome, 30, ',');
        arquivo_csv >> persona[i].sexo;
        arquivo_csv.ignore(); // Descartar a vírgula após o sexo
        arquivo_csv.getline(persona[i].nacionalidade, 15, ',');
        arquivo_csv >> persona[i].anoNascimento;
        arquivo_csv.ignore(); // Descartar a vírgula
        arquivo_csv >> persona[i].anoFalecimento;
        arquivo_csv.ignore(); // Descartar a vírgula
        arquivo_csv.getline(persona[i].corrente, 25, ',');
        arquivo_csv.getline(persona[i].descricao, 500, '\n'); // Lendo até a quebra de linha

        // Exibindo os dados
        cout << "----- Dados do Filosofo " << i + 1 << " -----" << endl; //(E) Ambas as linhas marcadas em (E) foram adicionadas por fins de separação entre os filosofos e estética no dispositivo de saida
        cout << persona[i].nome << " " << endl;
        cout << persona[i].sexo << " " << endl;
        cout << persona[i].nacionalidade << " " << endl;
        cout << persona[i].anoNascimento << " " << endl;
        cout << persona[i].anoFalecimento << " " << endl;
        cout << persona[i].corrente << " " << endl;
        cout << persona[i].descricao << " " << endl;
        cout << "-----------------------------------" << endl//(E) 
             << endl;
    }
	
	ofstream arquivo("arquivo.bin");
	arquivo.write((const char *)(persona), sizeof(filosofo)*numRegistros);
	
	
	//arquivo.read((char *) (&persona), sizeof(filosofo));
	
	ifstream entrada("entrada.csv");
	if (entrada) {
	entrada.seekg (0, entrada.end);		//Para mostrar o tamanho do arquivo
	int tam = entrada.tellg();				
	entrada.seekg (0, entrada.beg);
	cout << tam << endl << endl;
	ifstream arquivo2("arquivo.bin");
	arquivo2.read ((char *)persona,sizeof(filosofo)*numRegistros);
	for (int i = 0; i < numRegistros; i++) {
		cout << "----- Dados do Filosofo " << i + 1 << " -----" << endl; //(E) Ambas as linhas marcadas em (E) foram adicionadas por fins de separação entre os filosofos e estética no dispositivo de saida
        cout << persona[i].nome << " " << endl;
        cout << persona[i].sexo << " " << endl;
        cout << persona[i].nacionalidade << " " << endl;		//Ler o arquivo binario
        cout << persona[i].anoNascimento << " " << endl;
        cout << persona[i].anoFalecimento << " " << endl;
        cout << persona[i].corrente << " " << endl;
        cout << persona[i].descricao << " " << endl;
        cout << "-----------------------------------" << endl//(E) 
             << endl;
    }
	}
	else 
	cout << "arquivo não pode ser aberto!" << endl;

	delete [] persona;
	
	/*int *vetor, valor, j = 0, tamanho = 5;
	vetor = new int[tamanho];
	cin >> valor;
	while (valor != -1){
		if (j < tamanho){
			vetor[j] = valor;		(Mudar o tamanho do vetor)
			j++;
		}
		else{
			int *vetor1 = new int[tamanho+3];
			for (int i = 0; i < tamanho; i++){
				vetor1[i] = vetor[i];
				}
			delete [] persona;
			vetor = persona;
			vetor[j] = valor;
		}
		cin >> valor;
	}
	char bloco[tam];*/
	
    return 0;
}
