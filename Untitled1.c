#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
# define TAMANHOCHAR 255

enum TipoEmpresaEnum { FORNECEDOR, FABRICANTE, RECICLAGEM, AGENCIA };
enum TipoComponenteEnum { PROCESSADOR, MEMORIA, DISCO, PLACA_VIDEO, TECLADO, MONITOR, COMPUTADOR };
enum CondicaoEnum { NOVO, UTILIZADO };
enum StatusEnum { ATIVO, DESATIVADO };
enum TipoOperacaoEnum { SAIDA, ENTRADA };
int main(){
	setlocale(LC_ALL, "portuguese");
	/*typedef struct{
		int id;
		char nome[TAMANHOCHAR];
		
	}TipoFornecedor;
	
	typedef struct{
		int id;
		char nome[TAMANHOCHAR];
	}TipoFabricante;*/
	
	typedef struct{
		int id;
		char nome[TAMANHOCHAR];
		enum TipoEmpresaEnum tipo;
		char contacto[TAMANHOCHAR];
	}TipoEmpresa;
	
	typedef struct {
		int id;
		char nome[TAMANHOCHAR];
		char funcao[TAMANHOCHAR];
		char descricao[TAMANHOCHAR];
	}TipoFuncionario;
	
	typedef struct{
		int id;
		char  nome[TAMANHOCHAR];
		char local[TAMANHOCHAR];
		char seccao[TAMANHOCHAR];
		char descricao[TAMANHOCHAR];
		TipoFuncionario funcionario;
	}TipoPostoTrabalho;
	
	typedef struct{
		int id;
		char designacao[TAMANHOCHAR];
		char numeroSerie[TAMANHOCHAR];
		char dataAquisicao[TAMANHOCHAR];
		char garantia[TAMANHOCHAR];
		/*TipoFornecedor forncedor;
		TipoFabricante fabricante;*/
		enum TipoComponenteEnum tipo;
    enum CondicaoEnum condicao;
		TipoPostoTrabalho postoTrabalho;
		char observacoes[TAMANHOCHAR];
		enum StatusEnum status;
	}TipoComponente;
	
	typedef struct{
		int idInterno;
		int idExterno;
		TipoPostoTrabalho posto;
		TipoComponente componente;
		TipoEmpresa empresa;
		enum TipoOperacaoEnum operacao;
		char dataSaida[TAMANHOCHAR];
		char dataChegada[TAMANHOCHAR];
		char dataPrevistaChegada[TAMANHOCHAR];
		TipoFuncionario funcionarioResponsavel;
		char dataOperacao[TAMANHOCHAR];
		int montante;
		char observacoes[TAMANHOCHAR];
		
	}TipoFicha;
	int n1,n2,n3,funcionarioId,campo,componenteId,condicaoFuncionarioId=0,condicaoPostoId=0,postoTrabalhoId=0;
	n3=1;
	TipoFuncionario funcionario;
	TipoFuncionario funcionarios[120];
	TipoComponente componentes[120];
	TipoComponente componente;
	TipoPostoTrabalho postosTrabalho[120];
	TipoPostoTrabalho postoTrabalho;
	TipoComponente componentesPorApagar[120];
	TipoEmpresa empresas[120];
	TipoEmpresa empresa;

	int tamanho=sizeof(funcionarios)/sizeof(funcionarios[0]);
	int tamanhoComponente=sizeof(componentes)/sizeof(componentes[0]);
	int tamanhoPostoTrabalho=sizeof(postosTrabalho)/sizeof(postosTrabalho[0]);
	int tamanhoEmpresa=sizeof(empresas)/sizeof(empresas[0]);

	

	int tamanho1,escolhaTipoComponente=0,escolhaCondicaoComponente=0,escolhaConsultaComponente=0,escolhaCampoComponente=0,escolhaCampoPosto=0,encontradoPostoTrabalho=0,quantidadePostoComponententesApagar=0,resApagarPosto=0,escolhaTipoEmpresa=0,i=0,encontradoEmpresa=0,empresaId=0,escolhaCampoEmpresa=0;
	char consulta[TAMANHOCHAR],numeroSerieConsulta[TAMANHOCHAR],dataAquisicaoConsulta[TAMANHOCHAR],garantiaConsulta[TAMANHOCHAR],postoTrabalhoConsulta[TAMANHOCHAR],empresaConsulta[TAMANHOCHAR];
	
	while (n3==1){
		printf("\n1-Componentes\n2-Funcionáros\n3-Posto De Trabalho\n4-Operações\n5-Empresas\n6-Sair\n");
		
				scanf("%d",&n1);
		switch(n1){
				
				case 1:
					printf("1-listar\n2-Criar\n3-Pesquisar\n4-Editar\n5-Excluir\n6-Voltar");
					scanf("%d",&n2);
					switch(n2){
						case 1:
							printf("listando Componentes:\n ");
							printf("Id..........|Designacao..........|NumeroSerie...........|DataAquisicao..............|garantia................|Tipo...............|Condicao................|Observacoes...............|Status...................|\n");

							for  (int i=0;i<tamanhoComponente;i++){
							if(componentes[i].designacao[0] == '\0'){
								i=tamanhoComponente;

								
							}
							
							printf("%d|%s|%s|%s|%s|%d|%d|%s|%d\n",i,componentes[i].designacao,componentes[i].numeroSerie,componentes[i].dataAquisicao,componentes[i].garantia,componentes[i].tipo,componentes[i].condicao,componentes[i].observacoes,componentes[i].status);
							
						}
							break;
						case 2:
						
							if(postosTrabalho[0].nome[0] == '\0'){	
							printf("impossivel criar um componente sem ter pelo menos um posto de trabalho criado\n");
							break;
							}
							else{
							
							
						
						printf("criar\n");
						printf("digite a designacao do componente:\n");
						fflush(stdin);
						gets(componente.designacao);
						printf("digite o numero de serie:\n");
						fflush(stdin);
						gets(componente.numeroSerie);
						printf("digite a data de aquisicao:\n");
						fflush(stdin);
						gets(componente.dataAquisicao);
						printf("digite a garantia:\n");
						fflush(stdin);
						gets(componente.garantia);
						printf("digite o tipo do componente:(1)Processador(2)Memoria(3)Disco(4)Placa de Video(5)Teclado(6)Monitor(7)Computador:\n");
						while(escolhaTipoComponente==0 || escolhaTipoComponente>7){
						scanf("%d",&escolhaTipoComponente);

							
						if(escolhaTipoComponente==0 || escolhaTipoComponente>7){
							printf("opcao digitada incorreta\nDigite outra op��o correta");
							
						}
						else{
						
						
						switch(escolhaTipoComponente){
							case 1:
								componente.tipo=PROCESSADOR;
								break;
							case 2:
								componente.tipo=MEMORIA;
								break;
							case 3:
								componente.tipo=DISCO;
								break;
							case 4:
								componente.tipo=PLACA_VIDEO;
								break;
							case 5:
								componente.tipo=TECLADO;
								break;
							case 6:
								componente.tipo=MONITOR;
								break;
							case 7:
								componente.tipo=COMPUTADOR;
								break;
						
							
							
						}	
						}	
						}
						printf("digite a condicao do componente (1)Novo(2)Usado:\n");
						while(escolhaCondicaoComponente==0 || escolhaCondicaoComponente>2){
							scanf("%d",&escolhaCondicaoComponente);
							if(escolhaCondicaoComponente==0 || escolhaCondicaoComponente>2){
								printf("opcao digitada incorreta\nDigite outra op��o correta");
							}
							else{
								switch(escolhaCondicaoComponente){
									case 1:
										componente.condicao=NOVO;
										break;
									case 2:
										componente.condicao=UTILIZADO;
										break;
									
								}
							}
						}
						escolhaTipoComponente = 0;
						escolhaCondicaoComponente = 0;
						printf("digite alguma observacao do produto\n");
						fflush(stdin);
						gets(componente.observacoes);
						componente.status=ATIVO;
						printf("listando postos de trabalho");
						printf("Id..........|Nome..........|Local...........|Seccao..............|Descricao......................|FuncionarioResponsavel(Id)\n");
			
						for  (int i=0;i<tamanhoPostoTrabalho;i++){
							if(postosTrabalho[i].nome[0] == '\0'){									
								i=tamanhoPostoTrabalho;	
							}
							printf("%d|%s|%s|%s|%s|%s(%d)\n",i,postosTrabalho[i].nome,postosTrabalho[i].local,postosTrabalho[i].seccao,postosTrabalho[i].descricao,postosTrabalho[i].funcionario.nome,postosTrabalho[i].funcionario.id);
			
						}
						while(condicaoPostoId==0){
							scanf("%d",&postoTrabalhoId);
							for  (int i=0;i<tamanhoPostoTrabalho;i++){
								if(postosTrabalho[i].id == postoTrabalhoId){
									componente.postoTrabalho=postosTrabalho[i];	
									condicaoPostoId=1;				
									i=tamanhoPostoTrabalho;	
									break;
			
							}
							if(condicaoPostoId==0){
								printf("id digitado inv�lido.Digite outro id novamente:\n");

							}
						}}
						condicaoPostoId=0;
						for  (int i=0;i<tamanhoComponente;i++){
							if(componentes[i].designacao[0] == '\0'){
								componente.id=i;
								componentes[i]=componente;
								i=tamanhoComponente;

								
							}
						}}
						printf("Componente Criado com sucesso:%s\n",componente.designacao);
						break;	
						case 3:
						printf("deseja consultar o componente pelo?(1)NumeroSerie(2)DataAquisicao(3)TipoComponente(4)PostoDeTrabalho:\n");
						scanf("%d",&escolhaConsultaComponente);
						switch(escolhaConsultaComponente){
							case 1:
								printf("Digite o numero de serie do dispositivo:\n");
								gets(numeroSerieConsulta);
								for  (int i=0;i<tamanhoComponente;i++){
								if((strcmp(componentes[i].numeroSerie,numeroSerieConsulta))==0){
									printf("%d|%s|%s|%s|%s|%d|%d|%s|%d\n",i,componentes[i].designacao,componentes[i].numeroSerie,componentes[i].dataAquisicao,componentes[i].garantia,componentes[i].tipo,componentes[i].condicao,componentes[i].observacoes,componentes[i].status);
									//i=tamanhoComponente;
								}
								}
								break;
							case 2:
								printf("Digite a data de aquisicao:\n ");
								gets(dataAquisicaoConsulta);
								for  (int i=0;i<tamanhoComponente;i++){
								if((strcmp(componentes[i].dataAquisicao,dataAquisicaoConsulta))==0){
									printf("%d|%s|%s|%s|%s|%d|%d|%s|%d\n",i,componentes[i].designacao,componentes[i].numeroSerie,componentes[i].dataAquisicao,componentes[i].garantia,componentes[i].tipo,componentes[i].condicao,componentes[i].observacoes,componentes[i].status);
									//i=tamanhoComponente;
								}
								}
								
								break;
							case 3:
								printf("digite o tipo de componentes que deseja pesquisar (1)Processador(2)Memoria(3)Disco(4)Placa de Video(5)Teclado(6)Monitor(7)Computador:\n");
								while(escolhaTipoComponente==0 || escolhaTipoComponente>7){
									scanf("%d",&escolhaTipoComponente);
			
										
									if(escolhaTipoComponente==0 || escolhaTipoComponente>7){
										printf("opcao digitada incorreta\nDigite outra op��o correta");
										
									}
									else{
									
									
									switch(escolhaTipoComponente){
										case 1:
											for  (int i=0;i<tamanhoComponente;i++){
												if(componentes[i].tipo==PROCESSADOR){
													printf("%d|%s|%s|%s|%s|%d|%d|%s|%d\n",i,componentes[i].designacao,componentes[i].numeroSerie,componentes[i].dataAquisicao,componentes[i].garantia,componentes[i].tipo,componentes[i].condicao,componentes[i].observacoes,componentes[i].status);
													//i=tamanhoComponente;
												}
											}
											break;
										case 2:
											for  (int i=0;i<tamanhoComponente;i++){
												if(componentes[i].tipo==MEMORIA){
													printf("%d|%s|%s|%s|%s|%d|%d|%s|%d\n",i,componentes[i].designacao,componentes[i].numeroSerie,componentes[i].dataAquisicao,componentes[i].garantia,componentes[i].tipo,componentes[i].condicao,componentes[i].observacoes,componentes[i].status);
													//i=tamanhoComponente;
												}
											}
											break;
										case 3:
											for  (int i=0;i<tamanhoComponente;i++){
												if(componentes[i].tipo==DISCO){
													printf("%d|%s|%s|%s|%s|%d|%d|%s|%d\n",i,componentes[i].designacao,componentes[i].numeroSerie,componentes[i].dataAquisicao,componentes[i].garantia,componentes[i].tipo,componentes[i].condicao,componentes[i].observacoes,componentes[i].status);
													//i=tamanhoComponente;
												}
											}
											break;
										case 4:
											for  (int i=0;i<tamanhoComponente;i++){
												if(componentes[i].tipo==PLACA_VIDEO){
													printf("%d|%s|%s|%s|%s|%d|%d|%s|%d\n",i,componentes[i].designacao,componentes[i].numeroSerie,componentes[i].dataAquisicao,componentes[i].garantia,componentes[i].tipo,componentes[i].condicao,componentes[i].observacoes,componentes[i].status);
													//i=tamanhoComponente;
												}
											}
											break;
										case 5:
											for  (int i=0;i<tamanhoComponente;i++){
												if(componentes[i].tipo==TECLADO){
													printf("%d|%s|%s|%s|%s|%d|%d|%s|%d\n",i,componentes[i].designacao,componentes[i].numeroSerie,componentes[i].dataAquisicao,componentes[i].garantia,componentes[i].tipo,componentes[i].condicao,componentes[i].observacoes,componentes[i].status);
													//i=tamanhoComponente;
												}
											}
											break;
										case 6:
											for  (int i=0;i<tamanhoComponente;i++){
												if(componentes[i].tipo==MONITOR){
													printf("%d|%s|%s|%s|%s|%d|%d|%s|%d\n",i,componentes[i].designacao,componentes[i].numeroSerie,componentes[i].dataAquisicao,componentes[i].garantia,componentes[i].tipo,componentes[i].condicao,componentes[i].observacoes,componentes[i].status);
													//i=tamanhoComponente;
												}
											}
											break;
										case 7:
											for  (int i=0;i<tamanhoComponente;i++){
												if(componentes[i].tipo==COMPUTADOR){
													printf("%d|%s|%s|%s|%s|%d|%d|%s|%d\n",i,componentes[i].designacao,componentes[i].numeroSerie,componentes[i].dataAquisicao,componentes[i].garantia,componentes[i].tipo,componentes[i].condicao,componentes[i].observacoes,componentes[i].status);
													//i=tamanhoComponente;
												}
											}
											break;
										
										
									}	
									}	
									}
									escolhaTipoComponente=0;
								break;
								case 4:
									printf("listando postos de trabalho");
									printf("Id..........|Nome..........|Local...........|Seccao..............|Descricao......................|FuncionarioResponsavel(Id)\n");
			
										for  (int i=0;i<tamanhoPostoTrabalho;i++){
											if(postosTrabalho[i].nome[0] == '\0'){									
												i=tamanhoPostoTrabalho;	
											}
											printf("%d|%s|%s|%s|%s|%s(%d)\n",i,postosTrabalho[i].nome,postosTrabalho[i].local,postosTrabalho[i].seccao,postosTrabalho[i].descricao,postosTrabalho[i].funcionario.nome,postosTrabalho[i].funcionario.id);
			
										}
										condicaoPostoId=0;
										while(condicaoPostoId==0){
											scanf("%d",&postoTrabalhoId);
											for  (int i=0;i<tamanhoPostoTrabalho;i++){
											if(postosTrabalho[i].id == postoTrabalhoId){	
												condicaoPostoId=1;				
												i=tamanhoPostoTrabalho;	
												break;
											}
			
										}}
										if(condicaoPostoId==0){
										printf("id digitado inv�lido.Digite outro id novamente:\n");
										}else{
										
									

										
											for  (int i=0;i<tamanhoComponente;i++){
													if(componentes[i].postoTrabalho.id==postoTrabalhoId && componentes[i].designacao[0]!='\0'){
														printf("%d|%s|%s|%s|%s|%d|%d|%s|%d\n",i,componentes[i].designacao,componentes[i].numeroSerie,componentes[i].dataAquisicao,componentes[i].garantia,componentes[i].tipo,componentes[i].condicao,componentes[i].observacoes,componentes[i].status);
														//i=tamanhoComponente;
													}
													
												}
											
											}
									
									
									break;
								
						}
						break;
									
						case 4:
						//devo listar os funcion�rios no momento da edi��o para pooder ser escolhido o id do funcion�rio para o edit
						printf("listando Componentes:\n ");
							printf("Id..........|Designacao..........|NumeroSerie...........|DataAquisicao..............|garantia................|Tipo...............|Condicao................|Observacoes...............|Status...................|\n");

							for  (int i=0;i<tamanhoComponente;i++){
							if(componentes[i].designacao[0] == '\0'){
								i=tamanhoComponente;
								break;

								
							}
							
							printf("%d|%s|%s|%s|%s|%d|%d|%s|%d\n",i,componentes[i].designacao,componentes[i].numeroSerie,componentes[i].dataAquisicao,componentes[i].garantia,componentes[i].tipo,componentes[i].condicao,componentes[i].observacoes,componentes[i].status);
							
						}
						printf("qual componente deseja  editar?\n");
						scanf("%d",&componenteId);
						printf("Id..........|1-Designacao..........|2-NumeroSerie...........|3-DataAquisicao..............|4-garantia................|5-Tipo...............|6-Condicao................|7-Observacoes...............|8-Status...................|PostoTrabalho\n");
						printf("%d|%s|%s|%s|%s|%d|%d|%s|%d|%s\n",componenteId,componentes[componenteId].designacao,componentes[componenteId].numeroSerie,componentes[componenteId].dataAquisicao,componentes[componenteId].garantia,componentes[componenteId].tipo,componentes[componenteId].condicao,componentes[componenteId].observacoes,componentes[componenteId].status,componentes[componenteId].postoTrabalho.nome);
						while(escolhaCampoComponente==0 || escolhaCampoComponente>8){
									scanf("%d",&escolhaCampoComponente);
			
										
									if(escolhaCampoComponente==0 || escolhaCampoComponente>9){
										printf("opcao digitada incorreta\nDigite outra op��o correta");
										
									}
									else{
									
									
									switch(escolhaCampoComponente){
										case 1:
											printf("digite a nova designacao :\n");
											fflush(stdin);
											gets(componentes[componenteId].designacao);
											break;
										case 2:
											printf("digite o novo numero de serie:\n");
											fflush(stdin);
											gets(componentes[componenteId].numeroSerie);
											break;
										case 3:
											printf("digite a nova data de aquisicao:\n");
											fflush(stdin);
											gets(componentes[componenteId].dataAquisicao);
											break;
										case 4:
											printf("digite a nova garantia:\n");
											fflush(stdin);
											gets(componentes[componenteId].garantia);
											break;
										
										case 5:
											printf("digite o tipo do componente:(1)Processador(2)Memoria(3)Disco(4)Placa de Video(5)Teclado(6)Monitor(7)Computador:\n");
											while(escolhaTipoComponente==0 || escolhaTipoComponente>7){
												scanf("%d",&escolhaTipoComponente);
						
													
												if(escolhaTipoComponente==0 || escolhaTipoComponente>7){
													printf("opcao digitada incorreta\nDigite outra op��o correta");
													
												}
												else{
												
												
												switch(escolhaTipoComponente){
													case 1:
														componentes[componenteId].tipo=PROCESSADOR;
														break;
													case 2:
														componentes[componenteId].tipo=MEMORIA;
														break;
													case 3:
														componentes[componenteId].tipo=DISCO;
														break;
													case 4:
														componentes[componenteId].tipo=PLACA_VIDEO;
														break;
													case 5:
														componentes[componenteId].tipo=TECLADO;
														break;
													case 6:
														componentes[componenteId].tipo=MONITOR;
														break;
													case 7:
														componentes[componenteId].tipo=COMPUTADOR;
														break;
													
													
												}	
												}	
												}
											escolhaTipoComponente = 0;
											break;
										case 6:
											printf("digite a condicao do componente (1)Novo(2)Usado:\n");
												while(escolhaCondicaoComponente==0 || escolhaCondicaoComponente>2){
													scanf("%d",&escolhaCondicaoComponente);
													if(escolhaCondicaoComponente==0 || escolhaCondicaoComponente>2){
														printf("opcao digitada incorreta\nDigite outra op��o correta");
													}
													else{
														switch(escolhaCondicaoComponente){
															case 1:
																componentes[componenteId].condicao=NOVO;
																break;
															case 2:
																componentes[componenteId].condicao=UTILIZADO;
																break;
															
														}
													}
												}
												escolhaCondicaoComponente = 0;
											break;
										case 7:
											printf("digite uma nova observacao:\n");
											gets(componentes[componenteId].observacoes);
											break;
										case 8:
											if(componentes[componenteId].status==ATIVO){
												componentes[componenteId].status=DESATIVADO;
											}else{
												componentes[componenteId].status=ATIVO;

											}
											
											break;
										case 9:
											printf("listando postos de trabalho");
											printf("Id..........|Nome..........|Local...........|Seccao..............|Descricao......................|FuncionarioResponsavel(Id)\n");
					
												for  (int i=0;i<tamanhoPostoTrabalho;i++){
													if(postosTrabalho[i].nome[0] == '\0'){									
														i=tamanhoPostoTrabalho;	
													}
													printf("%d|%s|%s|%s|%s|%s(%d)\n",i,postosTrabalho[i].nome,postosTrabalho[i].local,postosTrabalho[i].seccao,postosTrabalho[i].descricao,postosTrabalho[i].funcionario.nome,postosTrabalho[i].funcionario.id);
					
												}
												condicaoPostoId=0;
												while(condicaoPostoId==0){
													scanf("%d",&postoTrabalhoId);
													for  (int i=0;i<tamanhoPostoTrabalho;i++){
													if(postosTrabalho[i].id == postoTrabalhoId){	
														condicaoPostoId=1;				
														i=tamanhoPostoTrabalho;
														componentes[componenteId].postoTrabalho=postosTrabalho[i];	
														break;
													}
					
												}}
												if(condicaoPostoId==0){
												printf("id digitado inv�lido.Digite outro id novamente:\n");
												}
											
											
											break;
										
										
									}	
									}	
									}
									escolhaCampoComponente=0;

						
						
						break;	
						case 5:
							printf("listando Componentes:\n ");
							printf("Id..........|Designacao..........|NumeroSerie...........|DataAquisicao..............|garantia................|Tipo...............|Condicao................|Observacoes...............|Status...................|\n");

							for  (int i=0;i<tamanhoComponente;i++){
							if(componentes[i].designacao[0] == '\0'){
								i=tamanhoComponente;

								
							}
							
							printf("%d|%s|%s|%s|%s|%d|%d|%s|%d\n",i,componentes[i].designacao,componentes[i].numeroSerie,componentes[i].dataAquisicao,componentes[i].garantia,componentes[i].tipo,componentes[i].condicao,componentes[i].observacoes,componentes[i].status);
							
						}
							printf("qual componente deseja excluir");
							scanf("%d",&componenteId);
							for  (int i=componenteId;i<tamanhoComponente-1;i++){
							
							componentes[i]=componentes[i+1];
								
							}
														


							break;
							
						case 6:
							printf("voltando...");
							
							break;
							
							
						
					}
					break;
				case 2:
					printf("1-listar\n2-Criar\n3-Pesquisar\n4-Editar\n5-Excluir\n6-Voltar");
					scanf("%d",&n2);
					switch(n2){
						case 1:
							printf("listando funcion�rios:\n");
							printf("Id..........|Nome..........|Fun�ao...........|Descricao..............|\n");

							for  (int i=0;i<tamanho;i++){
							//cabe�alho Da Tabela
							if(funcionarios[i].nome[0] == '\0'){
								i=tamanho;

								
							}
							
							printf("%d|%s|%s|%s\n",i,funcionarios[i].nome,funcionarios[i].funcao,funcionarios[i].descricao);
							
						}
							break;
						case 2:
						printf("criar\n");
						printf("digite o nome do funcion�rio:\n");
						fflush(stdin);
						gets(funcionario.nome);
						printf("digite a funcao do funcion�rio:\n");
						fflush(stdin);
						gets(funcionario.funcao);
						printf("digite a descricao do funcion�rio:\n");
						fflush(stdin);
						gets(funcionario.descricao);
						tamanho1 = 0;

						for  (int i=0;i<tamanho;i++){
							if(funcionarios[i].nome[0] == '\0'){
								funcionario.id=i;
								funcionarios[i]=funcionario;
								i=tamanho;

								
							}
						}
						printf("Funcionario Criado com sucesso:%s\n",funcionario.nome);
						
						
						break;
						
						case 3:
						printf("digite o nome para a consulta");
						fflush(stdin);
						gets(consulta);
						for  (int i=0;i<tamanho;i++){
							if(funcionarios[0].nome[0] == '\0'){	
								printf("Lista de funcionarios vazia\n");
								i=tamanho;								
							}
							
							printf("aqui");
							if((strcmp(funcionarios[i].nome,consulta))==0){
								printf("Funcionario encontrado\n");
								printf("Dados do Funcionario\n");
								printf("|Nome........!Funcao.........|Descricao........\n");
								printf("%s............%s..............%s................\n",funcionarios[i].nome,funcionarios[i].funcao,funcionarios[i].descricao);
								i=tamanho;
									
								
							}
						}
						
						
						break;			
						case 4:
						//devo listar os funcion�rios no momento da edi��o para pooder ser escolhido o id do funcion�rio para o edit
						printf("listando funcion�rios:\n");
						printf("Id..........|Nome..........|Fun�ao...........|Descricao..............|\n");

						for  (int i=0;i<tamanho;i++){
							//cabe�alho Da Tabela
							if(funcionarios[i].nome[0] == '\0'){
								i=tamanho;

								
						}
							
							printf("%d|%s|%s|%s\n",i,funcionarios[i].nome,funcionarios[i].funcao,funcionarios[i].descricao);
							}
						printf("qual funcion�rio deseja  editar?(id)");
						scanf("%d",&funcionarioId);
						printf("Id..........|1-Nome..........|2-Fun�ao...........|3-Descricao..............|\n");
						printf("%d|%s|%s|%s\n",funcionarioId,funcionarios[funcionarioId].nome,funcionarios[funcionarioId].funcao,funcionarios[funcionarioId].descricao);
						printf("Qual Campo deseja alterar do funcion�rio %s ?\n",funcionarios[funcionarioId].nome);
						scanf("%d",&campo);
						switch(campo){
							case 1:
								printf("Digite o novo nome  do funcionario\n");
								fflush(stdin);
								gets(funcionarios[funcionarioId].nome);
								break;
							case 2:
								printf("Digite a nova funcao  do funcionario\n");
								fflush(stdin);
								gets(funcionarios[funcionarioId].funcao);
								break;
							case 3:
								printf("Digite a nova descricao  do funcionario\n");
								fflush(stdin);
								gets(funcionarios[funcionarioId].descricao);
								break;
								
						}
						
						

						
						
						
						break;	
						case 5:
							//devo listar os funcion�rios no momento da edi��o para pooder ser escolhido o id do funcion�rio para o edit
						printf("listando funcion�rios:\n");
						printf("Id..........|Nome..........|Fun�ao...........|Descricao..............|\n");

						for  (int i=0;i<tamanho;i++){
							//cabe�alho Da Tabela
							if(funcionarios[i].nome[0] == '\0'){
								i=tamanho;

								
						}
							
							printf("%d|%s|%s|%s\n",i,funcionarios[i].nome,funcionarios[i].funcao,funcionarios[i].descricao);
							}
						printf("qual funcion�rio deseja  excluir?(id)");
						scanf("%d",&funcionarioId);
						for  (int i=funcionarioId;i<tamanho-1;i++){
							//cabe�alho Da Tabela
							
							funcionarios[i]=funcionarios[i+1];
							
							}
							break;
							
						case 6:
							printf("voltando...");
							
							break;
							
							
						
					}
					break;
				case 3:
					printf("1-listar\n2-criar\n3-Pesquisar\n4-Editar\n5-Excluir\n6-Voltar");
					scanf("%d",&n2);
					switch(n2){
						case 1:
							printf("listando postos de trabalho");
							printf("Id..........|Nome..........|Local...........|Seccao..............|Descricao......................|FuncionarioResponsavel(Id)\n");

							for  (int i=0;i<tamanhoPostoTrabalho;i++){
								if(postosTrabalho[i].nome[0] == '\0'){									
									i=tamanhoPostoTrabalho;	
								}
								printf("%d|%s|%s|%s|%s|%s(%d)\n",i,postosTrabalho[i].nome,postosTrabalho[i].local,postosTrabalho[i].seccao,postosTrabalho[i].descricao,postosTrabalho[i].funcionario.nome,postosTrabalho[i].funcionario.id);

							}
							break;
						case 2:
						printf("criar\n");
						if(funcionarios[0].nome[0] == '\0'){
								printf("nao e possivel criar um posto de trabalho sem ter pelo menos um funcionario registrado no sistema.Crie primeiro um funcionario");
					
								break;		
						}else{
						printf("digite o nome do posto de trabalho:\n");
						fflush(stdin);
						gets(postoTrabalho.nome);
						printf("digite o local do posto de trabalho:\n");
						fflush(stdin);
						gets(postoTrabalho.local);
						printf("digite a seccao do  posto de trabalho:\n");
						fflush(stdin);
						gets(postoTrabalho.seccao);
						printf("digite uma descricao para o posto :\n");
						fflush(stdin);
						gets(postoTrabalho.descricao);
						printf("listando funcion�rios:\n");
							printf("Id..........|Nome..........|Fun�ao...........|Descricao..............|\n");

							for  (int i=0;i<tamanho;i++){
							//cabe�alho Da Tabela
							if(funcionarios[i].nome[0] == '\0'){
								i=tamanho;	
							}
							
							printf("%d|%s|%s|%s\n",i,funcionarios[i].nome,funcionarios[i].funcao,funcionarios[i].descricao);
							
						}
						printf("Qual funcionario sera o responsavel pelo posto %s?:\n",postoTrabalho.nome);
						while(condicaoFuncionarioId==0){
								scanf("%d",&funcionarioId);
								for  (int i=0;i<tamanho;i++){
									//cabe�alho Da Tabela
									if(funcionarios[i].id == funcionarioId){
										condicaoFuncionarioId=1;
										postoTrabalho.funcionario=funcionarios[i];
										i=tamanho;	
									}
								}
								if(condicaoFuncionarioId==0){
									printf("Id incorreto. Digite outro id:\n");
								}
								
							}
							for  (int i=0;i<tamanhoPostoTrabalho;i++){
								if(postosTrabalho[i].nome[0] == '\0'){
									
									postosTrabalho[i]=postoTrabalho;
									i=tamanhoPostoTrabalho;	
								}
							}
						}
						funcionarioId=0;
						condicaoFuncionarioId=0;
						
							
						break;
						case 3:
						printf("digite o nome para a consulta");
						fflush(stdin);
						gets(postoTrabalhoConsulta);
						for  (int i=0;i<tamanhoPostoTrabalho;i++){
							if(postosTrabalho[0].nome[0] == '\0'){	
								printf("Lista de postos de trabalho vazia\n");
								i=tamanhoPostoTrabalho;								
							}
							
							printf("aqui");
							if((strcmp(postosTrabalho[i].nome,postoTrabalhoConsulta))==0){
								printf("Posto de Trabalho encontrado\n");
								printf("Dados do Posto de Trabalho\n");
								printf("|Nome........!Local.........|Seccao..............|Descricao..............|FuncionarioResponsavel(Id)\n");
								printf("%s............%s..............%s..............%s..............%s(%d)\n",postosTrabalho[i].nome,postosTrabalho[i].local,postosTrabalho[i].seccao,postosTrabalho[i].descricao,postosTrabalho[i].funcionario.nome,postosTrabalho[i].funcionario.id);
								i=tamanhoPostoTrabalho;
									
								
							}
						}
						break;			
						case 4:
						//devo listar os funcion�rios no momento da edi��o para pooder ser escolhido o id do funcion�rio para o edit
						printf("listando postos de trabalho");
							printf("Id..........|1-Nome..........|2-Local...........|3-Seccao..............|4-Descricao......................|5-FuncionarioResponsavel(Id)\n");

							for  (int i=0;i<tamanhoPostoTrabalho;i++){
								if(postosTrabalho[i].nome[0] == '\0'){									
									i=tamanhoPostoTrabalho;	
								}
								printf("%d|%s|%s|%s|%s|%s(%d)\n",i,postosTrabalho[i].nome,postosTrabalho[i].local,postosTrabalho[i].seccao,postosTrabalho[i].descricao,postosTrabalho[i].funcionario.nome,postosTrabalho[i].funcionario.id);

							}
							printf("qual posto deseja editar??:");
							
							while(encontradoPostoTrabalho==0){
								scanf("%d",&postoTrabalhoId);

								if(postosTrabalho[postoTrabalhoId].nome[0] == '\0'){									
									encontradoPostoTrabalho=0;

								}
								else{
									encontradoPostoTrabalho=1;
								}	
							}
						
								printf("qual campo deseja editar?:");
							
							
							scanf("%d",&escolhaCampoPosto);
							
							while(escolhaCampoPosto==0 || escolhaCampoPosto>5){
								scanf("%d",&escolhaCampoPosto);
							}
							switch(escolhaCampoPosto){
								case 1:
									printf("Digite o novo nome do posto:");
									fflush(stdin);
									gets(postosTrabalho[postoTrabalhoId].nome);
									break;
								case 2:
									printf("digite o novo local do posto:");
									fflush(stdin);
									gets(postosTrabalho[postoTrabalhoId].local);
									break;
								case 3:
									printf("digite a nova seccao do posto:");
									fflush(stdin);
									gets(postosTrabalho[postoTrabalhoId].seccao);
									break;
								case 4:
									printf("digite uma nova descri��o para o posto de trabalho:");
									fflush(stdin);

									gets(postosTrabalho[postoTrabalhoId].descricao);
									break;
								case 5:
									printf("listando funcion�rios:\n");
									printf("Id..........|Nome..........|Fun�ao...........|Descricao..............|\n");
		
									for  (int i=0;i<tamanho;i++){
									//cabe�alho Da Tabela
									if(funcionarios[i].nome[0] == '\0'){
										i=tamanho;	
									}
									
									printf("%d|%s|%s|%s\n",i,funcionarios[i].nome,funcionarios[i].funcao,funcionarios[i].descricao);
									
								}
								printf("Qual funcionario ser� o novo responsavel pelo posto %s?:\n",postosTrabalho[postoTrabalhoId].nome);
								while(condicaoFuncionarioId==0){
										scanf("%d",&funcionarioId);
										for  (int i=0;i<tamanho;i++){
											//cabe�alho Da Tabela
											if(funcionarios[i].id == funcionarioId){
												condicaoFuncionarioId=1;
												postosTrabalho[postoTrabalhoId].funcionario=funcionarios[i];
												i=tamanho;	
											}
										}
										if(condicaoFuncionarioId==0){
											printf("Id incorreto. Digite outro id:\n");
										}
										
									}
								
									postoTrabalhoId=0;
									encontradoPostoTrabalho=0;
									break;
									
									
							}
							break;
						//printf("qual posto de trabalho deseja  editar?");
						break;	
						case 5:
							printf("listando postos de trabalho");
							printf("Id..........|1-Nome..........|2-Local...........|3-Seccao..............|4-Descricao......................|5-FuncionarioResponsavel(Id)\n");

							for  (int i=0;i<tamanhoPostoTrabalho;i++){
								if(postosTrabalho[i].nome[0] == '\0'){									
									i=tamanhoPostoTrabalho;	
								}
								printf("%d|%s|%s|%s|%s|%s(%d)\n",i,postosTrabalho[i].nome,postosTrabalho[i].local,postosTrabalho[i].seccao,postosTrabalho[i].descricao,postosTrabalho[i].funcionario.nome,postosTrabalho[i].funcionario.id);

							}
							printf("qual posto de trabalho deseja excluir");							
							while(encontradoPostoTrabalho==0){
								scanf("%d",&postoTrabalhoId);

								if(postosTrabalho[postoTrabalhoId].nome[0] == '\0'){									
									encontradoPostoTrabalho=0;

								}
								else{
									encontradoPostoTrabalho=1;
								}	
							}
							for(int i=0;i<tamanhoComponente;i++){
								if(componentes[i].postoTrabalho.id==postoTrabalhoId && componentes[i].designacao[0]!='\0'){
									componentesPorApagar[quantidadePostoComponententesApagar]=componentes[i];
									quantidadePostoComponententesApagar++;
								}
							}
							printf("O posto de trabalho %s tem %d componentes associados a ele, deseja excluir o posto de trabalho e os componentes associados a ele?(1)Sim(2)N�o\n",postosTrabalho[postoTrabalhoId].nome,quantidadePostoComponententesApagar);
							scanf("%d",&resApagarPosto);
							if(resApagarPosto==1){
								for(int i=0;i<quantidadePostoComponententesApagar;i++){
									for(int j=componentesPorApagar[i].id;j<tamanhoComponente-1;j++){
										componentes[j]=componentes[j+1];

									}
									memset(&componentes[tamanhoComponente-1], 0, sizeof(TipoComponente));

								}
							}
							for(int i=postoTrabalhoId;i<tamanhoPostoTrabalho-1;i++){
								postosTrabalho[i]=postosTrabalho[i+1];
								
							}
							memset(&postosTrabalho[tamanhoPostoTrabalho-1], 0, sizeof(TipoPostoTrabalho));
							postoTrabalhoId=0;
							encontradoPostoTrabalho=0;
							resApagarPosto=0;
							quantidadePostoComponententesApagar=0;
							break;
							
						case 6:
							printf("voltando...");
							
							break;
							
							
						
					}
					break;
				case 4:
					printf("1-listar\n2-Criar\n3-Pesquisar\n4-Editar\n5-Excluir\n6-Voltar");
					scanf("%d",&n2);
					switch(n2){
						case 1:
							printf("listando opera��es ");
							break;
						case 2:
						printf("criar");
						break;
						case 3:
						printf("digite o nome para a consulta");
						break;			
						case 4:
						//devo listar os funcion�rios no momento da edi��o para pooder ser escolhido o id do funcion�rio para o edit
						printf("qual opera��o deseja  editar?");
						break;	
						case 5:
							printf("qual opera��o deseja excluir");
							break;
							
						case 6:
							printf("voltando...");
							
							break;
							
							
						
					}
					break;
				case 5:
					printf("1-listar\n2-Criar\n3-Pesquisar\n4-Editar\n5-Excluir\n6-Voltar");
					scanf("%d",&n2);
					switch(n2){
						case 1:
							printf("listando empresas ");
							break;
						case 2:
							printf("criar\n");
							printf("digite o nome da empresa:\n");
							fflush(stdin);
							gets(empresa.nome);
							printf("digite o contacto da empresa:\n");
							fflush(stdin);
							gets(empresa.contacto);	
							//FORNECEDOR, FABRICANTE, RECICLAGEM, AGENCIA
							printf("Digite que tipo de empresa é (1)Fornecedor(2)Fabricante(3)Reciclagem(4)Agencia:\n");
							while(escolhaTipoEmpresa==0 || escolhaTipoEmpresa>4){
								scanf("%d",&escolhaTipoEmpresa);
								if(escolhaTipoEmpresa==0 || escolhaTipoEmpresa>4){
									printf("opcao digitada incorreta\nDigite outra opção correta");
								}
								else{
									switch(escolhaTipoEmpresa){
										case 1:
											empresa.tipo=FORNECEDOR;
											break;
										case 2:
											empresa.tipo=FABRICANTE;
											break;
										case 3:
											empresa.tipo=RECICLAGEM;
											break;
										case 4:
											empresa.tipo=AGENCIA;
											break;
										

									}
								}
							}
							for(i=0;i<tamanhoEmpresa;i++){
								if(empresas[i].nome[0] == '\0'){
									empresas[i]=empresa;
									i=tamanhoEmpresa;
								}
							}

							break;
						case 3:
							printf("digite o nome para a consulta");
							fflush(stdin);
							gets(empresaConsulta);
							for  (int i=0;i<tamanhoEmpresa;i++){
								if(empresas[0].nome[0] == '\0'){	
									printf("Lista de empresas vazia\n");
									i=tamanhoEmpresa;								
								}
								
								printf("aqui");
								if((strcmp(empresas[i].nome,empresaConsulta))==0){
									printf("Empresa encontrada\n");
									printf("Dados da Empresa\n");
									printf("|Nome........!Contacto.........|Tipo..............|\n");
									printf("%s............%s..............%d................\n",empresas[i].nome,empresas[i].contacto,empresas[i].tipo);
									i=tamanhoEmpresa;
										
								
								}
							}
							break;			
						case 4:
							//devo listar os funcionãrios no momento da edição para pooder ser escolhido o id do funcion�rio para o edit
							printf("qual empresa deseja  editar?");
							printf("listando empresas\n");
							printf("Id..........|Nome..........|Contacto...........|Tipo...........\n");
							for(i=0;i<tamanhoEmpresa;i++){
								printf("%d|%s|%s|%d\n",i,empresas[i].nome,empresas[i].contacto,empresas[i].tipo);
							}
								while(encontradoEmpresa==0){
								scanf("%d",&empresaId);

								if(empresas[empresaId].nome[0] == '\0'){									
									encontradoEmpresa=0;

								}
								else{
									encontradoEmpresa=1;
								}	
							}
							printf("qual campo deseja editar?:");
							scanf("%d",&escolhaCampoEmpresa);
							while(escolhaCampoEmpresa==0 || escolhaCampoEmpresa>3){
								scanf("%d",&escolhaCampoEmpresa);
							}
							switch(escolhaCampoEmpresa){
								case 1:
									printf("Digite o novo nome da empresa\n");
									fflush(stdin);
									gets(empresas[empresaId].nome);
									break;
								case 2:
									printf("Digite o novo contacto da empresa\n");
									fflush(stdin);
									gets(empresas[empresaId].contacto);
										break;
								case 3:
									printf("Digite o novo tipo da empresa (1)Fornecedor(2)Fabricante(3)Reciclagem(4)Agencia:\n");
									while(escolhaTipoEmpresa==0 || escolhaTipoEmpresa>4){
										scanf("%d",&escolhaTipoEmpresa);
										if(escolhaTipoEmpresa==0 || escolhaTipoEmpresa>4){
											printf("opcao digitada incorreta\nDigite outra opção correta");
										}
										else{
											switch(escolhaTipoEmpresa){
												case 1:
													empresas[empresaId].tipo=FORNECEDOR;
													break;
												case 2:
													empresas[empresaId].tipo=FABRICANTE;
													break;
												case 3:
													empresas[empresaId].tipo=RECICLAGEM;
													break;
												case 4:
													empresas[empresaId].tipo=AGENCIA;
													break;
												
											}
										}
									}
									escolhaTipoEmpresa=0;
									empresaId=0;
									break;
								
							}
						
						break;	
						case 5:
							printf("qual empresa deseja excluir");
								printf("listando empresas\n");
							printf("Id..........|Nome..........|Contacto...........|Tipo...........\n");
							for(i=0;i<tamanhoEmpresa;i++){
								printf("%d|%s|%s|%d\n",i,empresas[i].nome,empresas[i].contacto,empresas[i].tipo);
							}
								while(encontradoEmpresa==0){
								scanf("%d",&empresaId);

								if(empresas[empresaId].nome[0] == '\0'){									
									encontradoEmpresa=0;

								}
								else{
									encontradoEmpresa=1;
								}	
							}
							for(int i=empresaId;i<tamanhoEmpresa-1;i++){
								empresas[i]=empresas[i+1];
							}
							empresas[tamanhoEmpresa-1].nome[0] = '\0';
							empresaId=0;
							encontradoEmpresa=0;	

							break;
				case 6:
					n3=0;
					break;
				
			}
	}
	
	return 0;
}
