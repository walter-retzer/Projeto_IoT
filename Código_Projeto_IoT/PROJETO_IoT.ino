
/********************************************************************
  AUTOR: WALTER DAWID RETZER
  
  PROJETO: NANO SMART AGRO PARA AGRICULTURA DE PRECISÃO
  
  VERSÃO: 4.01.35
  DATA: 14/01/2021
  HORÁRIO:13H30MIN
  ARQUIVO: PROJETO_IoT
  
*********************************************************************

  COMENTÁRIOS COM AS ALTERAÇÕES PARA REGISTRO DE CONTROLE DAS VERSÕES:
  
  VERSÃO:

  4.01.35:        ALTERADO FUNÇÃO DE ENVIO AO SERVER THINSPEAK, DEVIDO A ATUALIZAÇÃO DO PROTOCOLO MQTT3 E CONFIGURAÇÃO USADAS PELO SERVER.

  4.01.34:        ALTERADO FUNÇÃO PARA CONSULTA SALDO DO CHIP NA VIVO, DEVIDO A MUDANÇA DE NÚMERO PARA ENVIAR SMS  DE CONSULTA SALDO DA OPERADORA VIVO.
  

  4.01.33:        ALTERADO A BIBLIOTECA PUBSUBCLIENT TIME MQTT_SOCKET_TIMEOUT DE 15 PARA 60 SEGUNDOS PARA MELHORAR O TEMPO DE CONEXÃO COM O SERVER UBIDOTS.
                  ALTERADO A BIBLIOTECA PUBSUBCLIENT TIME MQTT_SOCKET_TIMEOUT DE 15 PARA 60 SEGUNDOS PARA MELHORAR O TEMPO DE CONEXÃO COM O SERVER UBIDOTS.
                  ALTERADO A BIBLIOTECA SOFTWARE SERIAL RX BUFFER DE 64 PARA 512 PARA MELHORAR A RECEPÇÃO DAS MSGS SMS E NÃO HAVER "CORTES NO TEXTO DAS MSGS".
                  CORRIGIDO A EXIBIÇÃO NO DISPLAY DO CLIENT.STATE QUANDO HOUVER ERRO DE CONEXÃO AOS SERVER IOT.                 

  
  4.01.32:        INCLUÍDO NA LÓGICA A EXIBIÇÃO DO CLIENT.STATE DOS SERVIDORES.
                  RETIRADO FUNÇÃO LÊGSM() PARA LER O STATUS DO SERVERS IoT.
                  IMPLEMENTADO OUTRA FUNÇÃO LEGSM1() PARA TESTAR O RECEBIMENTO DE SMS.
                  IMPLEMENTADO A LÓGICA PARA EXIBIR O MENU DO DISPLAY PARA SELECIONAR QUAL DESTINATÁRIO SERÁ ENVIADO UMA MENSAGEM SMS
            
 
  4.01.31:        ALTERADO LÓGICA PARA EXIBIR O MENU DO DISPLAY PARA SELECIONAR QUAL DESTINATÁRIO SERÁ ENVIADO UMA MENSAGEM SMS.
                  FALTA TESTAR:
                  **RECALIBRAR OS SENSORES DE UMIDADE DO SOLO;

  
  4.01.30:        ALTERADO LÓGICA PARA EXIBIR O ÚLTIMO COMANDO DA VARIÁVEL ÚLTIMO GSM, QUANDO FOR ENVIADO APENAS MENSAGEM SMS.
                  INCLUÍDO NA LÓGICA DE FUNCIONAMENTO, A LEITURA DA SERIAL GSM PARA TENTAR INPRIMIR O VALOR DE RETORNO DO SERVERS IoT. 
                  REVISADO FUNÇÃO LEGSM(), INSERIDO ELA POR PRIMEIRO NA EXECUÇÃO DO LOOP DO PROGRAMA PRINCIPAL.

  
  4.01.29:        ALTERADO LÓGICA PARA CÁLCULO DO PLUVIÔMETRO, INSERIDO VARIÁVEL READ_PULSOS ANTIGO PARA MANTER QUANTIDADE DE PULSOS QUANDO HOUVER "FALSOS PULSOS" NA MEDIÇÃO.
                  INCLUÍDO VARIÁVEIS PARA O ENVIO DA QUANTIDADE DE NÚMERO DE GRAVAÇÃO DO SD CARD NO CANAL DO THINGSPEAK NS*****.
                  ALTERADO EXIBIÇÃO DA TELA INICIAL DO PROTÓTIPO, INCLUIDO A MESMA TELA INICIAL, NO MENU DO TOUCH SCREEN DA EXIBIÇÃO DE DATA HORA.


  
*********************************************************************
  CONFIGURAÇÃO DOS BORNES DA PLACA DE ALIMENTAÇÃO EXTERNA DOS SENSORES:

  BORNE 01(FIO VERDE):    GND SENSOR DE UMIDADE P1
  BORNE 02(FIO AMARELO):  VCC SENSOR DE UMIDADE P1
  BORNE 03(FIO ROXO):     SINAL ANALÓGICO SENSOR DE UMIDADE P1

  BORNE 04(FIO CINZA):    SINAL ANALÓGICO SENSOR DE UMIDADE P2
  BORNE 05(FIO AZUL):     VCC SENSOR DE UMIDADE P2
  BORNE 06(FIO VERDE):    GND SENSOR DE UMIDADE P2

  BORNE 07(FIO AZUL):     VCC SENSOR DE ORVALHO/PRECIPTAÇÃO
  BORNE 08(FIO VERDE):    SINAL ANALÓGICO SENSOR DE ORVALHO/PRECIPTAÇÃO

  BORNE 09(FIO VERMELHO): A11 - ENTRADA ANALÓGICA RESERVA(FIO VERMELHO)
  BORNE 10(FIO LARANJA):  A12 - ENTRADA ANALÓGICA RESERVA(FIO LARANJA)
  BORNE 11(FIO AMARELO):  D17 - ENTRADA DIGITAL RESERVA(FIO MARROM)
  BORNE 12(FIO VERDE):    D42 - ENTRADA DIGITAL RESERVA(FIO PRETO)
  BORNE 13(FIO AZUL):     D43 - ENTRADA DIGITAL RESERVA(FIO BRANCO)

  BORNE 14(FIO LARANJA):  SINAL - ENTRADA TERMOPAR
  BORNE 15(FIO AMARELO):  SINAL + ENTRADA TERMOPAR

  BORNE 16(FIO ROXO):     SINAL ANALÓGICO SENSOR UV
  BORNE 17(FIO CINZA):    GND SENSOR UV
  BORNE 18(FIO BRANCO):   VCC SENSOR UV

  BORNE 19(FIO PRETO):    GND SENSOR UV - RESERVA
  BORNE 20(FIO CINZA):    VCC SENSOR UV - RESERVA

*********************************************************************
  BORNES DHT22 INTERN0:

  BORNE 01(FIO ROXO):     VCC SENSOR DHT22 INTERNO
  BORNE 02(FIO CINZA):    SINAL ANALÓGICO SENSOR DHT22 INTERNO
  BORNE 03(FIO BRANCO):   NÃO CONECTADO
  BORNE 04(FIO PRETO):    GND SENSOR DHT22 INTERNO

*********************************************************************
  BORNES DHT22 EXTERNO:

  BORNE 01(FIO CINZA):    VCC SENSOR DHT22 EXTERNO
  BORNE 02(FIO ROXO):     SINAL ANALÓGICO SENSOR DHT22 EXTERNO
  BORNE 03(FIO AZUL):     NÃO CONECTADO
  BORNE 04(FIO VERDE):    GND SENSOR DHT22 EXTERNO

*********************************************************************
  BORNES EXTERNOS DE ALIMENTAÇÃO BH1750:

  BORNE 01(FIO MARROM):    GND SENSOR BH1750(FIO MARROM)
  BORNE 02(FIO VERMELHO):  VCC SENSOR BH1750(FIO VERMELHO)
  BORNE 03(FIO LARANJA):   SCL SENSOR BH1750(FIO LARANJA)
  BORNE 04(FIO AMARELO):   SDA SENSOR BH1750(FIO PRETO)

*********************************************************************
  BORNES EXTERNOS DE ALIMENTAÇÃO DOS SENSOR DE VAZÃO E PLUVIÔMETRO:

  BORNE 01(FIO BRANCO):    VCC SENSOR BH1750
  BORNE 02(FIO PRETO):     GND SENSOR BH1750
  BORNE 03(FIO MARROM):    SINAL PULSO SENSOR DE VAZÃO

  BORNE 04(FIO VERMELHO):  VCC SENSOR PLUVIÔMETRO (NÃO CONECTADO!)
  BORNE 05(FIO LARANJA):   SINAL PULSO PLUVIÔMETRO (PRETO/VERDE)
  BORNE 06(FIO AMARELO):   GND PLUVIÔMETRO (AMARELO/VERMELHO)

*********************************************************************
  PINAGEM CHUVA/ORVALHO
  VCC    - 5V
  GND    - GND
  A0     - PIN A10 FIO BRANCO PLACA / BRANCO MEGA

*********************************************************************
  PINAGEM UMIDADE PONTO 1
  VCC    - 5V
  GND    - GND
  A0     - PIN A7 FIO CINZA PLACA / BRANCO MEGA

*********************************************************************
  PINAGEM SENSOR DHT22:
  VCC    - 5V
  GND    - GND
  A0     - PIN A12  FIO ROXO PLACA / AMARELO MEGA

*********************************************************************
  PINAGEM UMIDADE PONTO 2
  VCC    - 5V
  GND    - GND
  A0     - PIN A6 FIO --- PLACA / VERDE MEGA

*********************************************************************
  PINAGEM INDICE UV:
  VCC    - 5V
  GND    - GND
  AOUT   - PIN A15 FIO CINZA PLACA / FIO ROXO BORNE 16 DOS SENSORES

*********************************************************************
  FIOS DIGITAIS RESERVAS:
  FIO AMARELO  D44 MEGA
  FIO VERMELHO D43 MEGA
  FIO LARANJA  D42 MEGA

*********************************************************************
  SD CARD - MEGA
    GND  - GND
    VCC  - 5V
    MOSI - PIN 50 FIO LARANJA CD_DO LCD marrom
    MISO - PIN 51 FIO VERMELHO CD_DI LCD preto
  CSK/CLK  - PIN 52 FIO AMARELO CD_CSK LCD vermelho
    CS   - PIN 53 FIO MARROM CD_SS LCD branco

**********************************************************************
  PINAGEM SENSOR MAX 6675 - TERMPOAR TIPO K
  SENSOR   - MEGA
  GND    - GND
  VCC    - 5V
  SCK    - 45   FIO CINZA PLACA   /   CINZA MEGA
  CS     - 47   FIO BRANCO PLACA  /   BRANCO MEGA
  SO     - 46   FIO PRETO PLACA   /   PRETO MEGA

***********************************************************************
  PINAGEM SENSOR BMP 280
  SENSOR    -- MEGA
  VCC pin   -> Arduino 5V
  GND pin   -> Arduino GND
  SDA pin   -> Arduino 20 (SDA)
  SCL pin   -> Arduino 21 (SCL)
  CSB PIN   -> NC
  SDO PIN   -> VCC 5V

***********************************************************************
  MÓDULO DATA-TIME DS3231
  DS3231    -  Arduino UNO
  VCC pin   -> Arduino 5V
  GND pin   -> Arduino GND
  SDA pin   -> Arduino 20 (SDA)
  SCL pin   -> Arduino 21 (SCL)

***********************************************************************
  MÓDULO SENSOR DE NÍVEL AJ-SR04M:

  5V  PIN     ->  Arduino D13 - VCC(FIO ROXO)
  TRIGGER PIN ->  Arduino D12 - TRIGGER(CINZA)
  ECHO PIN    ->  Arduino D11 - ECHO(FIO BRANCO)
  GND PIN     ->  Arduino D10 - GND(FIO PRETO)

***********************************************************************/






// ========================================================================================================
// VARIÁVEIS PARA A FUNÇÃO TOUCH SCREEN DO DISPLAY:

#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
#include <TouchScreen.h>

//Portas de leitura das coordenadas do touchvoid
//#define YP A1 // Y+ is on Analog1
//#define XM A2 // X- is on Analog2
//#define YM 7 // Y- is on Digital7
//#define XP 6 // X+ is on Digital6

const int XP = 6, XM = A2, YP = A1, YM = 7; //ID=0x9341
const int TS_LEFT = 907, TS_RT = 136, TS_TOP = 942, TS_BOT = 139;

//objeto para manipulacao dos eventos de toque na tela
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);   //SETA AS VARIÁVEIS PARA O TOUCH SCREEN
TSPoint tp;  //FUNÇÃO PARA PEGAR OS VALORES DO TOUCH (x,y,z=pressao)!!

#define MINPRESSURE 200
#define MAXPRESSURE 1000

bool display_menu;
bool display_menu1;
unsigned long aux_display_menu;
unsigned long aux_display_menu1;

int cont1;

// ========================================================================================================
// DEFINIÇÃO DAS CORES NO DISPLAY TFT:

#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF
#define GREY            0x8410
#define ORANGE2         0xE880
#define ORANGE1         0xE800
#define ORANGE          0xFD20
#define GREENYELLOW     0xAFE5
#define LIGHTGREY       0xC618
#define DARKGREY        0x7BEF
#define OLIVE           0x7BE0
#define DARKGREEN       0x03E0
#define DARKCYAN        0x03EF
#define MARROM          0x7800
#define PURPLE          0x780F

// ========================================================================================================
// DEFINIÇÃO DE VARIAVEIS PARA AS CORES USADAS NA FUNÇÃO GAUGE NO DISPLAY TFT:

#define RED2RED 0
#define GREEN2GREEN 1
#define BLUE2BLUE 2
#define BLUE2RED 3
#define GREEN2RED 4
#define RED2GREEN 5

// cores para testar:
#define YELLOW2YELLOW 6
#define ORANGE2ORANGE 7
#define OLIVE2OLIVE 8
#define ORANGE2RED 9

#define SCALE0      0x528A      // inward pointing triangle scale segment  - color close to black 
#define SCALE1      0x3151      // outward pointing triangle scale segment - color deep blue 
//#define TEXT_COLOR  0xFFFF

int d = 0;                      // Variable used for the sinewave test waveform

//========================================================================================================
//BIBLIOTECAS:

#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <DS3231.h>
#include <max6675.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include "DHT.h"
#include <SoftwareSerial.h>

//========================================================================================================
//BIBLIOTECA PARA AUXILIAR NO ENVIO DE DADOS AO SERVER IOT DA THINGSPEAK E UBIDOTS:

#define TINY_GSM_MODEM_SIM800 //Tipo de modem que estamos usando
#include <TinyGsmClient.h>
#include <SoftwareSerial.h>
#include <PubSubClient.h>
#include <String.h>

//========================================================================================================
//BIBLIOTECA PARA O SENSOR DE LUMINOSIDADE BH1750:

#include <BH1750.h>

BH1750 lightMeter;
float lux;
float luxmax;
float luxmin;

//========================================================================================================
//SENSOR LDR
/*
  #define SensorLDR A12 // PINO DO SENSOR DE LUMINOSIDADE
  float ldr;
  float ldrmax;
  float ldrmin;
  void lcd_ldr();*/

//========================================================================================================
//BIBLIOTECA PARA O SENSOR ULTRASSÔNICO:

#include <Ultrasonic.h>

#define pinVCC_Nivel 13       // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DO SENSOR DE NÍVEL
#define pinGND_Nivel 10       // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DO SENSOR DE NÍVEL

Ultrasonic ultrasonic(12, 11);  // 12 - TRIGGER CINZA E 11 - BRANCO ECHO
int distance;

const int altura_caixa = 109;
const int c_aux = 87451;
const float pi = 3.14;
const float vol_total = 4000.00;

float volume_reservatorio;
float porcentagem_volume;

void nivel_cx();
float nivel;
float nivelMax;
float nivelMin;

void volume_cx();
float volume_res;
float volume_Min;
float volume_Max;

// ========================================================================================================
// Credenciais do SERVER UBIDOTS

char server[] = "things.ubidots.com";
char token[] = "BBFF-******************************";   // Valor do API Credentials do Default token
char clientId[] = "************************";           // Valor do ID da aba Device
const char topic[] = "/v1.6/devices/*********";         // * (Nome do Device 01)

// FUNÇÃO PARA ENVIO DE DADOS AO SERVER UBIDOTS:
void iot_ubidots();
String createJsonString();
int status_server;

unsigned int msg_counterok;
unsigned int msg_counternok;

// ========================================================================================================
// CREDENCIAIS DE ACESSO AO SERVER DA UBIDOTS

char server1[] = "things.ubidots.com";
char token1[] = "BBFF-******************************";   // Valor do API Credentials do Default token.
char clientId1[] = "************************";           // Valor do ID da aba Device
const char topic1[] = "/v1.6/devices/*********";         // * (Nome do Device 02)

// FUNÇÃO PARA ENVIO DE DADOS AO SERVER UBIDOTS:
void iot_ubidots1();
String createJsonString1();
int status_server1;

unsigned int msg_counterok1;
unsigned int msg_counternok1;


// ========================================================================================================
// CREDENCIAIS DE ACESSO AO SERVER DA MATHLAB - THINGSPEAK

// Atualização dos Parâmetros para envio ao Server ThingSpeak:
char clientIdMQTT[] = "****************";
char mqttUserName[] = "****************";
char mqttPassword[] = "****************";
const char server_T1[] = "mqtt3.thingspeak.com";

//DEVICE: 01
void iot_thingspeak();
int status_server_t;
unsigned int msg_counterok_t;
unsigned int msg_counternok_t;
String createJsonString2();
long channelID = 9999999;                       // Change to your channel ID.
//char writeAPIKey[] = "****************";      // Não é mais necessário esse parâmetro para a comunicação com o Server

//DEVICE: 02
void iot_thingspeak1();
int status_server_t1;
unsigned int msg_counterok_t1;
unsigned int msg_counternok_t1;
String createJsonString3();
long channelID1 = 8888888;                       // Change to your channel ID.
//char writeAPIKey1[] = "****************";      // Não é mais necessário esse parâmetro para a comunicação com o Server

//DEVICE: IoT - Vinhedo (PIEDADE-SP) CANAL PÚBLICO:
void iot_thingspeak2();
int status_server_t2;
unsigned int msg_counterok_t2;
unsigned int msg_counternok_t2;
String createJsonString4();
long channelID2 = 7777777;                       // Change to your channel ID.
//char writeAPIKey2[] = "****************";      // Não é mais necessário esse parâmetro para a comunicação com o Server

//========================================================================================================
// Contagem de vezes que houver falha no envio das mensagens aos Servidores IoT:

unsigned int msg_counternok_resete; //msg não enviada ubidots 0
unsigned int msg_counternok1_resete; //msg não enviada ubidots 1
unsigned int msg_counternok_t_resete; // msg não enviada ThingSpeak 0
unsigned int msg_counternok_t1_resete; // msg não enviada ThingSpeak 1
unsigned int msg_counternok_t2_resete; // msg não enviada ThingSpeak 2
unsigned int configuraGSM_nok_resete; // GSM nok

//========================================================================================================
//DEFINIÇÃO DOS PINOS DE COMUNICAÇÃO COM O MODULO GSM SIM800L

#define TX_PIN 63      // ARDUINO PINO A8 (NUMERO 63) FIO AMARELO  ---  MÓDULO SIM_RXD AMARELO
#define RX_PIN 62      // ARDUINO PINO A9 (NUMERO 62) FIO LARANJA  ---  MÓDULO SIM_TXD LARANJA

// ========================================================================================================
// Cria comunicacao serial via software nas portas digitais definidas acima

SoftwareSerial serialGSM(TX_PIN, RX_PIN);
TinyGsm modemGSM(serialGSM);
TinyGsmClient gsmClient(modemGSM);
PubSubClient client(server, 1883, gsmClient);

//========================================================================================================
// FUNÇÕES PARA ESCREVER COMANDOS E LER RESPOSTAS DO MODULO SIM800L VIA SERIAL:

String sendATSMS(String command);
String sendAT(String command);
String sendAT1(String command);

// ==============================================================================
// COMUNICAÇÃO GSM COM O MÓDULO SIM8000L PARA ENVIO DE SMS!!:

#define senhaGsm  "****************"  // senha para o SMS de valor das variaveis!
#define senhaGsm1 "****************"  // senha para o SMS de diagnostico
#define senhaGsm2 "****************"  // senha para o SMS para resete do Arduino 
#define senhaGsm3 "****************"  // senha para o SMS de envio da quantidade gravação sd card
#define senhaGsm4 "****************"  // senha para o SMS para resete do pluviômetro 
#define senhaGsm5 "****************"  // senha para o SMS para resete do Totalizador de vazão

void leGSM();
bool temSMS = false;
String telefoneSMS;
String dataHoraSMS;
String mensagemSMS;
String comandoGSM = "";
String ultimoGSM = "";

void setup_gsm_gprs();

void configuraGSM();
unsigned int configuraGSM_ok;
unsigned int configuraGSM_nok;
unsigned int modo_sms_ativado;

void enviaSMS(String telefoneSMS, String mensagem);    // envia SMS com dadso das variaveis.
void enviaSMS1(String telefoneSMS, String mensagem);   // envia SMS com dados dos diagnósticos.
void enviaSMS2(String telefoneSMS, String mensagem);   // envia SMS da Solicitacao de Resete.
void enviaSMS3(String telefoneSMS, String mensagem);   // envia SMS com dados dos diagnósticos do SD Card.
void enviaSMS4(String telefoneSMS, String mensagem);   // envia SMS da Solicitacao de Resete do Pluviômetro.
void enviaSMS5(String telefoneSMS, String mensagem);   // envia SMS da Solicitacao de Resete do Totalizador de Vazão.
void enviaSMS6(String telefoneSMS, String mensagem);   // envia SMS de Alerta de Chuva celular: +5515999999999!! 
void enviaSMS7(String telefoneSMS, String mensagem);   // envia SMS de Alerta de Precipitação maior que 1.00mm2 para o celular: +55159999999!
void enviaSMS8(String telefoneSMS, String mensagem);   // envia SMS para a Vivo para consultar Saldo!

unsigned int msg_sms_env;     // Contagem de mensagens SMS foram enviadas
unsigned int msg_sms_rec;      // Contagem de mensagens SMS foram recebidas
String str1;

// ========================================================================================================
// CONFIGURAÇÃO DE ACESSO AO APN DA VIVO:

const char apn[]      = "zap.vivo.com.br";
const char gprsUser[] = "";
const char gprsPass[] = "";

// ========================================================================================================
// VARIAVEIS DE STATUS DA BATERIA:

uint8_t  chargeState   = 0;
int8_t   chargePercent = 0;
uint16_t milliVolts    = 0;

// ========================================================================================================
// DECLARAÇÃO DE VARIAVEIS PARA QUE AS FUNÇÕES DE EXIBIÇÃO DE VARIAVEIS DO DISPLAY FUNCIONEM EM LOOP:

unsigned long lcd_init = 0;
unsigned long anterior = 0;
unsigned long anterior2 = 0;
unsigned long anterior3 = 0;
unsigned long anterior4 = 0;
unsigned long anterior5 = 0;
unsigned long anterior6 = 0;
unsigned long anterior7 = 0;
unsigned long anterior8 = 0;
unsigned long anterior9 = 0;
unsigned long anterior10 = 0;
unsigned long anterior11 = 0;
unsigned long anterior12 = 0;
unsigned long anterior13 = 0;
unsigned long anterior14 = 0;
unsigned long anterior15 = 0;
unsigned long anterior16 = 0;
unsigned long anterior17 = 0;
unsigned long anterior18 = 0;
unsigned long anterior19 = 0;
unsigned long anterior20 = 0;

unsigned long anterior30 = 0;

unsigned long intervalo = 10000;
unsigned long intervalo2 = 20000;
unsigned long intervalo3 = 30000;
unsigned long intervalo4 = 40000;
unsigned long intervalo5 = 50000;
unsigned long intervalo6 = 60000;
unsigned long intervalo7 = 70000;
unsigned long intervalo8 = 80000;
unsigned long intervalo9 = 90000;
unsigned long intervalo10 = 100000;
unsigned long intervalo11 = 110000;
unsigned long intervalo12 = 120000;
unsigned long intervalo13 = 130000;
unsigned long intervalo14 = 140000;
unsigned long intervalo15 = 150000;
unsigned long intervalo16 = 160000;
unsigned long intervalo17 = 170000;
unsigned long intervalo18 = 180000;
unsigned long intervalo19 = 190000;
unsigned long intervalo20 = 200000;

unsigned long intervalo30 = 900000;  


// ========================================================================================================
// ENTRADAS E SAIDAS DIGITAIS AUXILIARES NÃO ESTÃO SENDO USADAS PELO PROGRAMA:

#define pinVCC1 17       // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DE SENSORES
#define pinVCC2 40      // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DE SENSORES

// ==============================================================================
// SD CARD:

void printDirectory(File dir, int numTabs);
Sd2Card card;
SdVolume volume;
SdFile root;

uint32_t vol_kb;

void sd_card_testegravacao();
void teste_Sd();

File myFile;
int pinoSS = 53;

void sd_card_setup();
void gravadadosSd();
unsigned int msg_sdcard_ok;
unsigned int msg_sdcard_nok;

// ========================================================================================================
// MÓDULO DS3231: BIBLIOTECA alterada para exibir o mês e dia da semana em Português-BR:

DS3231  rtc(SDA, SCL);
Time  t;  // Init a Time-data structure
Time t2;  // VARIÁVEL PARA RESETAR OS VALORES MÁXIMOS E MÍNIMOS

void data_hora();

// ==============================================================================
// PLUVIOMETRO:

void lcdpluv();
void pulso_chuva ();
volatile unsigned int contaPulso1;         //Variável para a quantidade de pulsos
volatile unsigned int Read_Pulso1;         //Variável para a quantidade de pulsos
volatile unsigned int Read_Pulso1Antigo;   //Variável para a quantidade de pulsos anterior
float pluviometro;               //Variável para armazenar o valor do pluviometro em função dos pulsos gerados.
float pluviometro_acum;          //Variável para armazenar o valor do pluviometro acumulado em função dos pulsos gerados.
const byte Pino1 = 18;           //Pino 19 - interrupção 3 do Arduino Mega!
byte sms_pluviometro;            //Variável auxiliar para enviar SMS quando houver precipitação maior que 1.00mm

#define VCC_PLUV 37  // PINO DE ALIMENTAÇÃO VCC AUXILIAR DO PLUVIOMETRO
#define GND_PLUV 36  // PINO DE ALIMENTAÇÃO GND AUXILIAR DO PLUVIOMETRO

// ==============================================================================
//SENSOR DE VAZÃO:

#define VCC_VAZAO 39  // PINO DE ALIMENTAÇÃO VCC AUXILIAR DO PLUVIOMETRO
#define GND_VAZAO 38  // PINO DE ALIMENTAÇÃO GND AUXILIAR DO PLUVIOMETRO

static float vazao;       //Variável para armazenar o valor em L/min
float Litros;             //Variável para Quantidade de agua
float MiliLitros;         //Variavel para Conversão
const byte Pino = 19;     //Pino 19 - interrupção 2 do Arduino Mega!

float Litros_anterior;    //Variável auxiliar para que atualizar o valor do display LCD

unsigned long anteriorvazao = 0;
unsigned long atualvazao;
unsigned long intervalovazao;

void lcd_vazao();

void pulse ();
volatile unsigned long contaPulso_vazao;      //Variável para a quantidade de pulsos
volatile unsigned long contaPulsotot;   //Variavel para tota de pulsos do totalizador
unsigned int pulsos_vazao_seg;

//pinMode(19, INPUT);   // pino 19 corresponde a interrupção 2
//attachInterrupt(digitalPinToInterrupt(Pino), ISR, MODO);

//Parâmetros:
//Pino: o número do pino de interrupção do Arduino Mega;
//ISR: Sub rotina a ser chamada quando a interrupção ocorre; essa função deve não tomar nenhum parâmetro nem retornar nada.

//MODO: define quando a interrupção deve ser ativada. Quatro constantes estão predefinidas como valores válidos:
//LOW acionar a interrupção quando o estado do pino for LOW,
//CHANGE acionar a interrupção quando o sempre estado do pino mudar
//RISING acionar a interrupção quando o estado do pino for de LOW para HIGH apenas,
//FALLING acionar a interrupção quando o estado do pino for de HIGH para LOW apenas.
//HIGH acionar a interrupção quando o estado do pino for HIGH.

// ==============================================================================
//SENSOR DE UMIDADE DO SOLO PONTO 1:

#define SensorUmidadeP1 A6 // PINO DO SENSOR DE UMIDADE DO SOLO P1

//declaração das variaveis referentes a leitura do sensor de umidade:

void umid_soloP1();

float umidadeP1;
float minimoP1 = 8.00;   
float maximoP1 = 1010.50;  
float sensorP1;

float umidP1_analog;
float valorumidadeP1;

float umSmaxP1;
float umSminP1;

// ==============================================================================
//SENSOR DE UMIDADE DO SOLO PONTO 2

#define SensorUmidadeP2 A7 // PINO DO SENSOR DE UMIDADE DO SOLO P2

//declaração das variaveis referentes a leitura do sensor de umidade:

void umid_soloP2();

float umidadeP2;
float minimoP2 = 7.00;  
float maximoP2 = 1011.50;  
float sensorP2;

float umidP2_analog;
float valorumidadeP2;

float umSmaxP2;
float umSminP2;

// ==============================================================================
// SENSOR DE PRECIPTAÇÃO DE ORVALHO:

#define chuvaPIN A10 // VALOR ANALÓGICO DA CHUVA

void lcd_preciptacao();
float chuva_analog;
float minimo2 = 230.50;
float maximo2 = 941.50;
float preciptacao1;
float preciptacao;
float valor5 = 0;

float cpmin;
float cpmax;

// ========================================================================================================
// MÓDULO BMP 280:

Adafruit_BMP280 sensor_bmp;

Adafruit_Sensor *sensor_bmp_temp = sensor_bmp.getTemperatureSensor();
Adafruit_Sensor *sensor_bmp_pressure = sensor_bmp.getPressureSensor();

void lcd_alt_atm();

float alt;
float altMax;
float altMin;

float valor2;
float valoralt;

void lcd_pressao_atm();
float  valor3;
float  valorp;
float  pMin;
float  pMax;
float  p;
byte sms_prev_chuva;


// ==============================================================================
// SENSORES DTH22:

#define DHT1_PIN A14         // pino que estamos conectado sensor externo
#define DHT2_PIN A13         // pino que estamos conectado sensor interno

#define DHTTYPE DHT22      // SENSOR DHT 22

DHT dht1(DHT1_PIN, DHTTYPE);
DHT dht2(DHT2_PIN, DHTTYPE);

// SENSOR DHT22 INTERNO - DHT2_PIN A12

void lcd_temp_amb_int();
float t1_int;
float h1_int;
float t1_int_Max;
float t1_int_Min;

// SENSOR DHT22 EXTERNO - DHT1_PIN A14
double dewPoint(double celsius, double humidity);
double celsius;
double humidity;
float t1;
float h;

void lcd_dewpoint();
float   dewPointMax;
float   dewPointMin;
double dewP;

void dht_setup();
void lcd_temp_amb();
void lcd_umid_amb();

float UmaxDHT22;
float UminDHT22;
float hh;

float t1MaxDHT22;
float t1MinDHT22;
float tt1;

// ==============================================================================
// Sensor de Temperatura do Solo, Termopar Tipo K, modelo: MAX6675.

void lcd_temp_solo();

const int   thermoDO  = 46;     //Pino SO (ou DO)
const int   thermoCS  = 47;     //PINO CS
const int   thermoCLK = 45;     //Pino SCK (ou CLK)

float termoparMax;
float termoparMin;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

// ========================================================================================================
// FUNÇÃO PARA EXIBIR O INDICE UV:

void Calcula_nivel_UV();

int pino_sensorUV = A15;
int valor_sensorUV = 0;
float UV_index = 0;

float  UV_indexMax;
float  UV_indexMin;

// ========================================================================================================
// FUNÇÃO PARA TESTE DOS SENSORES COM COMINICAÇÃO I2C:

void teste_I2C();

// ========================================================================================================
// FUNÇÃO DE DIAGNÓSTICO:

void d1();
float bmp_temp;
unsigned long atual30 = 0;
unsigned long t_send = 0;

// ========================================================================================================
// FUNÇÃO DE RELATÓRIO DE ENVIO AOS SERVERS IOT:

void d2();
void d3();

// ========================================================================================================
// FUNÇÃO DE DIAGNÓSTICO PARA EXIBIR A CONFIRMAÇÃO DE RESETE DE VALORES MAX E MIN:

void d4();

// ========================================================================================================
// FUNÇÃO RESETE DO ARDUINO VIA PROGRAMAÇÃO:

void (*funcReset)() = 0;



// ========================================================================================================
// ESTADO DO LED:

#define LED 44
bool estadoLED = 1;
unsigned long TempoLED = 0;
unsigned long IntervalolLED = 250;
unsigned long TempoAtuallLED;


// ========================================================================================================
// ESTADO DO BUZZER:

#define BUZZER_VCC 26
#define BUZZER_GND 27

volatile boolean estado_buzzer = false;
volatile boolean aux_estado_buzzer = false;
//=======================================================================================================//











//=======================================================================================================//
/*********************************************************************************************************/
//=============================================FUNÇÃO SETUP==============================================//
/*********************************************************************************************************/
//=======================================================================================================//


void setup() {

  //========================================================================================================
  //iNICIALIZANDO SETUPS DOS SENSORES E SERIAL:

  //Serial.begin(9600);
  serialGSM.begin(9600);
  delay(1000);
  Wire.begin();
  delay(1000);
  dht1.begin();
  delay(1000);
  dht2.begin();
  delay(1000);
  lightMeter.begin();
  delay(1000);

  //========================================================================================================
  // PINOS DE ALIMENTAÇÃO AUXILIAR:

  pinMode(pinVCC1, OUTPUT);           // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DE SENSORES
  pinMode(pinVCC2, OUTPUT);           // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DE SENSORES

  digitalWrite(pinVCC1, true);        // aux VCC
  digitalWrite(pinVCC2, false);       // aux GND

  //========================================================================================================
  // PINOS DE ALIMENTAÇÃO AUXILIAR SENSOR DE NÍVEL:

  pinMode(pinVCC_Nivel, OUTPUT);           // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DE SENSORES
  pinMode(pinGND_Nivel, OUTPUT);           // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DE SENSORES

  digitalWrite(pinVCC_Nivel, true);        // aux VCC
  digitalWrite(pinGND_Nivel, false);       // aux GND

  //==============================================================================
  // ALIMNETAÇÃO DO PLUVIOMETRO:

  pinMode(VCC_PLUV, OUTPUT);           // Declara VCC_PLUV PINO 37 FIO BRANCO como saída  +VCC
  pinMode(GND_PLUV, OUTPUT);           // Declara GND_PLUV PINO 36 FIO PRETO COOMO SAÍDA  GND

  digitalWrite(VCC_PLUV, true);        // aux pluviometro VCC
  digitalWrite(GND_PLUV, false);       // aux pluviometro GND

  // ==============================================================================
  // ALIMENTAÇÃO DO SENSOR DE VAZÃO:

  pinMode(VCC_VAZAO, OUTPUT);           // Declara VCC_PLUV PINO 39 FIO VERMELHO como saída  +VCC
  pinMode(GND_VAZAO, OUTPUT);           // Declara GND_PLUV PINO 38 FIO AMARELO COOMO SAÍDA  GND

  digitalWrite(VCC_VAZAO, true);        // aux pluviometro VCC
  digitalWrite(GND_VAZAO, false);       // aux pluviometro GND

  // ==============================================================================
  // CONFIGURANDO BUZZER:

  pinMode(BUZZER_VCC, OUTPUT);           // Declara BUZZER como saída - PINO +VCC
  pinMode(BUZZER_GND, OUTPUT);           // Declara BUZZER como saída - PINO GND

  digitalWrite(BUZZER_GND, false);        // Reseta o BUZZER
  digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
  delay(250);
  digitalWrite(BUZZER_VCC, false);        // Reseta o BUZZER
  delay(250);
  digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
  delay(250);
  digitalWrite(BUZZER_VCC, false);        // Reseta o BUZZER
  delay(250);
  digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
  delay(250);
  digitalWrite(BUZZER_VCC, false);        // Reseta o BUZZER

  pinMode(LED_BUILTIN, OUTPUT);           // Declara LED da placa Arduino Mega como saída
  digitalWrite(LED_BUILTIN, estadoLED);   // Seta o LED

  pinMode(LED, OUTPUT);                   // Declara LED como saída
  digitalWrite(LED, estadoLED);           // Seta o LED

  pinMode(pinoSS, OUTPUT);                // Declara pinoSS como saída
  int pino53 = 53;
  pinMode(pino53, OUTPUT);

  delay(500);
  SD.begin(pino53);                       // Inicializa SD CARD
  delay(500);


  // ========================================================================================================
  // CONFIGURAÇÃO PARA A GRAVAÇÃO DA DATA E HORA AO MÓDULO DS3231.

  rtc.begin();          //Inicializa RTC

  // ========================================================================================================
  // CONFIGURAÇÃO PARA A AJUSTE DO HORÁRIO E DATA DO MÓDULO DS3231:
  // PARA O AJUSTE INICIAL DEVE-SE INCLUIR O CÓDIGO ABAIXO E APÓS O DOWNLOAD DO CÓDIGO, DEVE-SE COMENTAR O TRECHO ABAIXO E REALIZAR NOVO DOWNLOAD
  /*
      t.hour = 20;
      t.min = 54;
      t.sec = 00;
      t.year = 2021;
      t.mon = 7;
      t.date = 21;

      rtc.setDOW(SUNDAY);     // Set Day-of-Week to SUNDAY
      rtc.setTime(14,03,00);     // Set the time to 12:00:00 (24hr format)
      rtc.setDate(28,02,2021);   // Set the date to January 1st, 2014
  */
  //========================================================================================================
  // Contagem de mensagens enviadas UBIDOTS:

  msg_counterok = 0;

  //========================================================================================================
  // Contagem de mensagens não enviadas UBIDOTS:

  msg_counternok = 0;

  //========================================================================================================
  // Contagem de mensagens enviadas UBIDOTS1:

  msg_counterok1 = 0;

  //========================================================================================================
  // Contagem de mensagens não enviadas UBIDOTS1:

  msg_counternok1 = 0;

  //========================================================================================================
  // Contagem de mensagens SMS enviadas:

  msg_sms_env = 0;

  //========================================================================================================
  // Contagem de mensagens SMS foram recebidas:

  msg_sms_rec = 0;

  //========================================================================================================
  // Contagem de mensagens enviadas THINGSPEAK: CHANNEL 0

  msg_counterok_t = 0;

  //========================================================================================================
  // Contagem de mensagens não enviadas THINGSPEAK: CHANNEL 0

  msg_counternok_t = 0;

  //========================================================================================================
  // Contagem de mensagens enviadas THINGSPEAK: CHANNEL 1

  msg_counterok_t1 = 0;

  //========================================================================================================
  // Contagem de mensagens não enviadas THINGSPEAK: CHANNEL 1

  msg_counternok_t1 = 0;

  //========================================================================================================
  // Contagem de mensagens enviadas THINGSPEAK: IoT - Vinhedo (PIEDADE-SP)

  msg_counterok_t2 = 0;

  //========================================================================================================
  // Contagem de mensagens não enviadas THINGSPEAK: IoT - Vinhedo (PIEDADE-SP)

  msg_counternok_t2 = 0;

  //========================================================================================================
  // Contadores de gravação no Sd Card:

  msg_sdcard_ok = 0;
  msg_sdcard_nok = 0;

  //========================================================================================================
  // Contagem de vezes que houver falha na configuração SMS:

  configuraGSM_ok = 0;
  configuraGSM_nok = 0;

  //========================================================================================================


  //========================================================================================================
  // Contagem de vezes que houver falha no envio das mensagens aos Servidores IoT:

  msg_counternok_resete = 0; //msg não enviada Ubidots 0
  msg_counternok1_resete = 0; //msg não enviada Ubidots 1
  msg_counternok_t_resete = 0; // msg não enviada ThingSpeak 0
  msg_counternok_t1_resete = 0; // msg não enviada ThingSpeak 1
  msg_counternok_t2_resete = 0; // msg não enviada ThingSpeak 2
  configuraGSM_nok_resete = 0; // GSM nok.

  //========================================================================================================



  //==================INICIALIZANDO SENSORES PARA LEITURAS DO VALOR MAX E MIN==============================//
  /*********************************************************************************************************/
  //=======================================================================================================//


  //========================================================================================================
  // TEMPERATURA INTERNA CASÉBRE E MAXIMOS E MINIMOS DO DHT22:

  t1_int = dht2.readTemperature();

  //========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA TEMPERATURA AMBIENTE DO SENSOR DTH22:

  t1_int_Max = -100.00;
  t1_int_Min = 100.00;

  if (t1_int < t1_int_Min) {
    t1_int_Min = t1_int;
  }
  if (t1_int > t1_int_Max) {
    t1_int_Max = t1_int;
  }

  //========================================================================================================
  // UMIDADE, TEMPERATURA, SENSAÇÃO TÉRMICA E DEWPOINT MAXIMOS E MINIMOS DO DHT22:

  h = dht1.readHumidity();
  t1 = dht1.readTemperature();

  //========================================================================================================
  // UMIDADE MAXIMOS E MINIMOS DO DHT22:

  UmaxDHT22 = -100.00;
  UminDHT22 = 100.00;

  if (h < UminDHT22) {
    UminDHT22 = h;
  }
  if (h > UmaxDHT22) {
    UmaxDHT22 = h;
  }

  //========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA TEMPERATURA AMBIENTE DO SENSOR DTH22:

  t1MaxDHT22 = -100.00;
  t1MinDHT22 = 100.00;

  if (t1 < t1MinDHT22) {
    t1MinDHT22 = t1;
  }
  if (t1 > t1MaxDHT22) {
    t1MaxDHT22 = t1;
  }

  //========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DO DEW POINT DO SENSOR DTH22:

  dewPointMax = -100.00;
  dewPointMin = 100.00;

  if (dewPoint(t1, h ) < dewPointMin) {
    dewPointMin = dewPoint(t1, h );
  }
  if (dewPoint(t1, h ) > dewPointMax) {
    dewPointMax = dewPoint(t1, h );
  }

  //========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL LUMINOSIDADE EM: LUX

  lux = lightMeter.readLightLevel();
  luxmin = 5000.0;
  luxmax = -150.0;
  lux = lightMeter.readLightLevel();

  if (lux < luxmin) {
    luxmin = lux;
  }
  if (lux > luxmax) {
    luxmax = lux;
  }

  //========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL LUMINOSIDADE EM: LUX
  /*
    float sensorL1 = analogRead(SensorLDR);
    ldr = map(sensorL1, 0, 1023, 0, 100);

    ldrmin = 100.0;
    ldrmax = -100.0;

     if (ldr < ldrmin){
        ldrmin = ldr;
     }
     if (ldr > ldrmax){
        ldrmax = ldr;
     }
  */
  //========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA TEMPERATURA DO SOLO: TERMOPAR

  termoparMax = -100.00;
  termoparMin = 100.00;

  float temp_solo = thermocouple.readCelsius();

  if (thermocouple.readCelsius() < termoparMin) {
    termoparMin = thermocouple.readCelsius();
  }
  if (thermocouple.readCelsius() > termoparMax) {
    termoparMax = thermocouple.readCelsius();
  }

  //========================================================================================================
  // UMIDADE DO SOLO PONTO 1:

  umSmaxP1 = -100.00;
  umSminP1 = 100.00;

  sensorP1 = 0;
  umidP1_analog = 0;

  //========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL UMIDADE P1 DO SOLO EM %:

  for (int i = 0; i <= 200; i++) {
    sensorP1 = analogRead(SensorUmidadeP1);
    umidP1_analog = umidP1_analog + sensorP1;
  }

  //========================================================================================================
  // FILTRO PARA GARATIR UMA LEITURA MAIS ESTÁVEL COM 200 MEDIÇÕES:

  valorumidadeP1 = umidP1_analog / 200;
  //Serial.print(valorumidadeP1);
  umidadeP1 = ((valorumidadeP1 - minimoP1) / (maximoP1 - minimoP1)) * 100;
  umidadeP1 = (umidadeP1 - 100) * -1;

  umidP1_analog = 0;
  valorumidadeP1 = 0;

  //========================================================================================================
  // LÓGICA DE PARA INDICAÇÃO DOS VALORES MÁXIMOS E MÍNIMOS:

  if (umidadeP1 < umSminP1) {
    umSminP1 = umidadeP1;
  }

  if (umidadeP1 > umSmaxP1) {
    umSmaxP1 = umidadeP1;
  }

  //========================================================================================================
  // FILTRO DE PARA INDICAÇÃO DOS LIMITES MÁXIMOS E MÍNIMOS:

  if (umidadeP1 <= 0) {
    umidadeP1 = 0.00;
  }

  if (umidadeP1 >= 100.00) {
    umidadeP1 = 99.99;
  }

  //========================================================================================================
  // UMIDADE DO SOLO PONTO 2:

  umSmaxP2 = -100.00;
  umSminP2 = 100.00;

  sensorP2 = 0;
  umidP2_analog = 0;

  //========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL UMIDADE P2 DO SOLO EM %:

  for (int i = 0; i <= 200; i++) {
    sensorP2 = analogRead(SensorUmidadeP2);
    umidP2_analog = umidP2_analog + sensorP2;
  }

  //========================================================================================================
  // FILTRO PARA GARATIR UMA LEITURA MAIS ESTÁVEL COM 200 MEDIÇÕES:

  valorumidadeP2 = umidP2_analog / 200;
  //Serial.print(valorumidadeP2);
  umidadeP2 = ((valorumidadeP2 - minimoP2) / (maximoP2 - minimoP2)) * 100;
  umidadeP2 = (umidadeP2 - 100) * -1;

  umidP2_analog = 0;
  valorumidadeP2 = 0;

  //========================================================================================================
  // LÓGICA DE PARA INDICAÇÃO DOS VALORES MÁXIMOS E MÍNIMOS:

  if (umidadeP2 < umSminP2) {
    umSminP2 = umidadeP2;
  }

  if (umidadeP2 > umSmaxP2) {
    umSmaxP2 = umidadeP2;
  }

  //========================================================================================================
  // FILTRO DE PARA INDICAÇÃO DOS LIMITES MÁXIMOS E MÍNIMOS:

  if (umidadeP2 <= 0) {
    umidadeP2 = 0.00;
  }

  if (umidadeP2 >= 100.00) {
    umidadeP2 = 99.99;
  }

  //========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL PRECIPTAÇÃO EM %:

  valor5 = 0;
  preciptacao1 = 0;

  cpmin = 100.00;
  cpmax = -100.00;

  //========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL PRECIPTAÇÃO DE ORVALHO EM %:

  for (int i = 0; i <= 100; i++) {
    chuva_analog = analogRead(chuvaPIN);
    valor5 = valor5 + chuva_analog;
  }

  preciptacao1 = valor5 / 100;

  preciptacao = ((preciptacao1 - minimo2) / (maximo2 - minimo2)) * 100;
  preciptacao = (preciptacao - 100) * -1;
  valor5 = 0;
  preciptacao1 = 0;

  if (preciptacao < cpmin) {
    cpmin = preciptacao;
  }
  if (preciptacao > cpmax) {
    cpmax = preciptacao;
  }

  if (preciptacao <= 4.99) {
    preciptacao = 0.0;
  }

  if (preciptacao >= 100.00) {
    preciptacao = 99.9;
  }

  //========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA ALTITUDE - MÓDULO BMP280:

  sensor_bmp.begin();

  /* Default settings from datasheet. */
  sensor_bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                         Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                         Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                         Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                         Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */


  valor2 = 0;
  valoralt = 0;

  altMax = -1500.00;
  altMin = 1500.00;

  for (int i = 0; i <= 100; i++) {
    valoralt = sensor_bmp.readAltitude(1013.25);
    valor2 = valor2 + valoralt;
  }

  alt = valor2 / 100;
  valor2 = 0;
  valoralt = 0;

  if (alt < altMin) {
    altMin = alt;
  }

  if (alt > altMax) {
    altMax = alt;
  }

  //========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA PRESSÃO ATMOSFÉRICA - MÓDULO BMP280:

  valor3 = 0;
  valorp = 0;
  pMin = 1500;
  pMax = -1500;

  for (int i = 0; i <= 100; i++) {
    valorp = sensor_bmp.readPressure();
    valor3 = valor3 + valorp;
  }

  p = valor3 / 100;

  p = p / 100;    // transformando 1Pa em 1 mBar
  valor3 = 0;
  valorp = 0;

  if (p < pMin) {
    pMin = p;
  }

  if (p > pMax) {
    pMax = p;
  }

  sms_prev_chuva = true;
  sms_pluviometro = true;


  //========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DO DEW POINT DO SENSOR ULTRASSONICO:

  distance = ultrasonic.read();
  nivel = altura_caixa - distance;
  nivelMax = -100.00;
  nivelMin = 100.00;

  if (nivel < nivelMin) {
    nivelMin = nivel;
  }
  if (nivel > nivelMax) {
    nivelMax = nivel;
  }


  //========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DO DEW POINT DO SENSOR ULTRASSONICO:

  //c_aux = (((R1_caixa)*(R1_caixa)) + ((R2_caixa)*(R2_caixa)) + ((R1_caixa)*(R2_caixa)));
  //delay(2000);

  //distance = ultrasonic.read();
  //nivel = altura_caixa - distance;

  volume_reservatorio = (((nivel * pi) / 3) * c_aux);
  volume_reservatorio = volume_reservatorio / 1000;
  volume_reservatorio = volume_reservatorio * 2;

  volume_Max = -5000;
  volume_Min = 5000;

  if (volume_reservatorio < volume_Min) {
    volume_Min = volume_reservatorio;
  }

  if (volume_reservatorio > volume_Max) {
    volume_Max = volume_reservatorio;
  }

  volume_res = volume_reservatorio;

  //========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DO SENSOR UV:
  valor_sensorUV = analogRead(pino_sensorUV);

  //Calcula tensao em milivolts
  int tensao = (valor_sensorUV * (5.0 / 1023.0)) * 1000;

  //Compara com valores tabela UV_Index
  if (tensao > 0 && tensao < 50)
  {
    UV_index = 0;
  }
  else if (tensao > 50 && tensao <= 227)
  {
    UV_index = 0;
  }
  else if (tensao > 227 && tensao <= 318)
  {
    UV_index = 1;
  }
  else if (tensao > 318 && tensao <= 408)
  {
    UV_index = 2;
  }
  else if (tensao > 408 && tensao <= 503)
  {
    UV_index = 3;
  }
  else if (tensao > 503 && tensao <= 606)
  {
    UV_index = 4;
  }
  else if (tensao > 606 && tensao <= 696)
  {
    UV_index = 5;
  }
  else if (tensao > 696 && tensao <= 795)
  {
    UV_index = 6;
  }
  else if (tensao > 795 && tensao <= 881)
  {
    UV_index = 7;
  }
  else if (tensao > 881 && tensao <= 976)
  {
    UV_index = 8;
  }
  else if (tensao > 976 && tensao <= 1079)
  {
    UV_index = 9;
  }
  else if (tensao > 1079 && tensao <= 1170)
  {
    UV_index = 10;
  }
  else if (tensao > 1170)
  {
    UV_index = 11;
  }

  UV_indexMax = -100.00;
  UV_indexMin = 100.00;

  if (UV_index < UV_indexMin) {
    UV_indexMin = UV_index;
  }

  if (UV_index > UV_indexMax) {
    UV_indexMax = UV_index;
  }


  //========================================================================================================
  // VALORES INICIAIS DA VAZÃO:

  contaPulso_vazao = 0;     //Variável para a quantidade de pulsos++; //Incrementa a variável de pulsos
  contaPulsotot = 0; //Variável para a quantidade de pulsos++; //Incrementa a variável de pulsos
  vazao = 0.00;
  Litros = 0.00;

  //========================================================================================================
  // VALORES INICIAIS DO PLUVIOMETRO:

  Read_Pulso1 = 0;
  Read_Pulso1Antigo = 0;
  contaPulso1 = 0;
  pluviometro = 0.00;
  pluviometro_acum = 0.00;

  //========================================================================================================
  // VARIÁVEL AUXILIAR DO MENU DO DISPLAY TOUCH SCREEN QUANDO ELE É PRESSIONADO:

  cont1 = 0;

  //========================================================================================================
  // INICIANDO DISPLAY TFT 2.4":

  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(0);
  tft.fillScreen(BLACK);

  //========================================================================================================
  // ATIVANDO O LED DA PLACA DOS SENSORES:

  digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES

  //========================================================================================================
  // INICIANDO O TESTE DE LINHAS DO DISPLAY TFT 2.4":

  testLines_SD(WHITE);
  delay(1500);

  //========================================================================================================
  // INICIANDO O MENU DO NSAGRO:
  
  data_hora();
  tft.fillRect(0, 0, 240, 320, BLACK);
  delay(1000);

  //=========================INICIALIZANDO OS SETUPS DOS SENSORES E MÓDULOS================================//
  /*********************************************************************************************************/
  //=======================================================================================================//

  //========================================================================================================
  // INICIO DOS SETUPS DOS SENSORES:

  tft.fillRect(0, 0, 240, 320, BLACK);
  teste_I2C();
  delay(2000);
  tft.fillRect(0, 0, 240, 320, BLACK);

  dht_setup();
  delay(2000);
  tft.fillRect(0, 0, 240, 320, BLACK);

  //========================================================================================================
  // INICIO DO SETUP DO SD CARD:

  delay(500);
  SD.begin(pino53);
  delay(500);

  sd_card_setup();
  delay(2000);
  tft.fillRect(0, 0, 240, 320, BLACK);

  teste_Sd();
  delay(2000);
  tft.fillRect(0, 0, 240, 320, BLACK);

  sd_card_testegravacao();
  delay(2000);
  tft.fillRect(0, 0, 240, 320, BLACK);

  gravadadosSd();
  delay(2000);
  tft.fillRect(0, 0, 240, 320, BLACK);

  tft.fillRect(0, 0, 240, 30, RED);
  tft.setCursor(5, 7);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.println(F("ARQUIVOS NO SD CARD"));

  delay(1000);
  tft.drawRect(0, 30, 240, 290, YELLOW);
  delay(1000);

  tft.setCursor(0, 35);
  delay(500);
  SD.begin(pino53);
  delay(500);

  File root;
  root = SD.open("/");
  printDirectory(root, 0);
  root.close();
  delay(4000);

  tft.fillRect(0, 0, 240, 320, BLACK);
  setup_gsm_gprs();
  delay(1000);
  tft.fillRect(0, 0, 240, 320, BLACK);

  //========================================================================================================
  // FUNÇÃO PARA ENVIO DOS DADOS AOS SERVERS: TEMPO DE ENVIO DOS DADOS NO SERVER IOT A CADA 15 MINUTOS:

  anterior30 = millis();              // (t_send) tempo para sincronizar o "time" de envio a cada 15 minutos a partir desse momento!

  //digitalWrite(LED_BUILTIN, false);   // Reseta o LED DA PLACA ARDUINO
  digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, false);   // Reseta o LED DA PLACA ARDUINO
  digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, false);   // Reseta o LED DA PLACA ARDUINO
  digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES

  iot_ubidots();                     // server iot ubidots
  delay(1000);
  tft.fillRect(0, 0, 240, 320, BLACK);

  //digitalWrite(LED_BUILTIN, false);   // Reseta o LED DA PLACA ARDUINO
  digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, false);   // Reseta o LED DA PLACA ARDUINO
  digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, false);   // Reseta o LED DA PLACA ARDUINO
  digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES

  iot_ubidots1();                    // server iot ubidots
  delay(2000);
  tft.fillRect(0, 0, 240, 320, BLACK);

  //digitalWrite(LED_BUILTIN, false);   // Reseta o LED DA PLACA ARDUINO
  digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, false);   // Reseta o LED DA PLACA ARDUINO
  digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, false);   // Reseta o LED DA PLACA ARDUINO
  digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES

  iot_thingspeak();
  delay(1000);
  tft.fillRect(0, 0, 240, 320, BLACK);

  //digitalWrite(LED_BUILTIN, false);   // Reseta o LED DA PLACA ARDUINO
  digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, false);   // Reseta o LED DA PLACA ARDUINO
  digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, false);   // Reseta o LED DA PLACA ARDUINO
  digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES

  iot_thingspeak1();
  delay(1000);
  tft.fillRect(0, 0, 240, 320, BLACK);

  //digitalWrite(LED_BUILTIN, false);   // Reseta o LED DA PLACA ARDUINO
  digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, false);   // Reseta o LED DA PLACA ARDUINO
  digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, false);   // Reseta o LED DA PLACA ARDUINO
  digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES

  iot_thingspeak2();
  delay(1000);
  tft.fillRect(0, 0, 240, 320, BLACK);

  //digitalWrite(LED_BUILTIN, false);   // Reseta o LED DA PLACA ARDUINO
  digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, false);   // Reseta o LED DA PLACA ARDUINO
  digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, false);   // Reseta o LED DA PLACA ARDUINO
  digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
  delay(200);

  //digitalWrite(LED_BUILTIN, true);   // Seta o LED DA PLACA ARDUINO
  digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES

  d2();

  d3();

  tft.fillRect(0, 0, 240, 320, BLACK);
  configuraGSM();
  delay(2000);

  tft.fillRect(0, 0, 240, 320, BLACK);
  gravadadosSd();
  delay(2000);

  //========================================================================================================
  // FINALIZANDO SETUP:

  tft.fillRect(0, 0, 240, 320, BLACK);
  tft.fillRoundRect(20, 40, 200, 210, 15, RED);
  tft.drawRoundRect(20, 40, 200, 210, 15, WHITE);

  delay(1500);

  tft.setCursor(48, 56);
  tft.setTextColor(WHITE, RED);
  tft.setTextSize(6);
  tft.print(F("NANO"));

  delay(1500);

  tft.setCursor(32, 120);
  tft.print(F("SMART"));

  delay(1500);

  tft.setCursor(48, 184);
  tft.print(F("AGRO"));

  delay(1500);

  tft.fillRoundRect(5, 270, 230, 30, 5, RED);
  tft.drawRoundRect(5, 270, 230, 30, 5, WHITE);
  tft.setCursor(13, 280);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(F("INICIANDO LEITURAS"));

  delay(1000);

  //==============================INTERRUPÇÕES CONFIGURAÇÃO DOS PINOS======================================//
  /*********************************************************************************************************/
  //=======================================================================================================//

  //  attachInterrupt(digitalPinToInterrupt(Pino), ISR, MODO);
  //  Pino: o número do pino de interrupção do Arduino Mega;
  //  ISR: Sub rotina a ser chamada quando a interrupção ocorre, essa função deve não tomar nenhum parâmetro nem retornar nada.
  //  MODO: define quando a interrupção deve ser ativada.

  //  Quatro constantes estão predefinidas como valores válidos para MODO:
  //  LOW acionar a interrupção quando o estado do pino for LOW,
  //  CHANGE acionar a interrupção quando o sempre estado do pino mudar
  //  RISING acionar a interrupção quando o estado do pino for de LOW para HIGH apenas,
  //  FALLING acionar a interrupção quando o estado do pino for de HIGH para LOW apenas.
  //  HIGH acionar a interrupção quando o estado do pino for HIGH.

  //========================================================================================================
  // PINO DE INTERRUPÇÃO PARA MEDIÇÃO DE VAZÃO: FIO DE CAMPO AMARELO / FIO LARANJA DA PLACA DE SENSORES

  pinMode(19, INPUT);   // pino 19 corresponde a interrupção 2
  attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);

  contaPulso_vazao = 0;     //Variável para a quantidade de pulsos++; //Incrementa a variável de pulsos
  contaPulsotot = 0;  //Variável para a quantidade de pulsos++; //Incrementa a variável de pulsos
  vazao = 0.00;
  Litros = 0.00;
  Litros_anterior = Litros;

  //========================================================================================================
  // PINO DE INTERRUPÇÃO PARA O PLUVIOMETRO: FIO DE CAMPO PRETO / FIO VERMELHO DA PLACA DE SENSORES

  pinMode(18, INPUT);   // pino 18 corresponde a interrupção 3
  attachInterrupt(digitalPinToInterrupt(Pino1), pulso_chuva, RISING);

  Read_Pulso1 = 0;
  contaPulso1 = 0;
  pluviometro = 0.00 ;
  pluviometro_acum = 0.00;

  //========================================================================================================
  // VARIAVEIS PARA A FUNÇÃO MILLIS PARA QUE NÃO HAJA DELAY E O ENVIO DE SMS FUNCIONE MELHOR!!!

  unsigned long intervalo =  10000;
  unsigned long intervalo2 = 20000;
  unsigned long intervalo3 = 30000;
  unsigned long intervalo4 = 40000;
  unsigned long intervalo5 = 50000;
  unsigned long intervalo6 = 60000;
  unsigned long intervalo7 = 70000;
  unsigned long intervalo8 = 80000;
  unsigned long intervalo9 = 90000;
  unsigned long intervalo10 = 100000;
  unsigned long intervalo11 = 110000;
  unsigned long intervalo12 = 120000;
  unsigned long intervalo13 = 130000;
  unsigned long intervalo14 = 140000;
  unsigned long intervalo15 = 150000;
  unsigned long intervalo16 = 160000;
  unsigned long intervalo17 = 170000;
  unsigned long intervalo18 = 180000;
  unsigned long intervalo19 = 190000;
  unsigned long intervalo20 = 200000;

  unsigned long atual = millis();
  unsigned long atual2 = atual;
  unsigned long atual3 = atual2;
  unsigned long atual4 = atual3;
  unsigned long atual5 = atual4;
  unsigned long atual6 = atual5;
  unsigned long atual7 = atual6;
  unsigned long atual8 = atual7;
  unsigned long atual9 = atual8;
  unsigned long atual10 = atual9;
  unsigned long atual11 = atual10;
  unsigned long atual12 = atual11;
  unsigned long atual13 = atual12;
  unsigned long atual14 = atual13;
  unsigned long atual15 = atual14;
  unsigned long atual16 = atual15;
  unsigned long atual17 = atual16;
  unsigned long atual18 = atual17;
  unsigned long atual19 = atual18;
  unsigned long atual20 = atual19;

  anterior = atual;
  anterior2 = atual2;
  anterior3 = atual3;
  anterior4 = atual4;
  anterior5 = atual5;
  anterior6 = atual6;
  anterior7 = atual7;
  anterior8 = atual8;
  anterior9 = atual9;
  anterior10 = atual10;
  anterior11 = atual11;
  anterior12 = atual12;
  anterior13 = atual13;
  anterior14 = atual14;
  anterior15 = atual15;
  anterior16 = atual16;
  anterior17 = atual17;
  anterior18 = atual18;
  anterior19 = atual19;
  anterior20 = atual20;

  //========================================================================================================
  // Habilita interrupção do Pluviometro e sensor de vazão.

  interrupts();

  //========================================================================================================
  // Variaveis de Vazão e Pluviometro:

  anteriorvazao = millis();     //Variavel auxiliar para verificar a contagem de pulsos a cada 1 segundo
  lcd_init = millis();          //Variavel auxiliar para a exibição de Iniciando Leituras no Display
  TempoLED = millis();          //Variavel auxiliar para realizar os pulsos no LED

} // Fecha VOID SETUP









//=======================================================================================================//
/*********************************************************************************************************/
//============================================LOOP PRINCIPAL=============================================//
/*********************************************************************************************************/
//=======================================================================================================//

void loop() {

  // ========================================================================================================
  // CHECANDO RECEBIMENTO DE MENSAGENS VIA SMS:

  leGSM();

  while (temSMS) {

    detachInterrupt(digitalPinToInterrupt(Pino));   // Desabilita somente a interrupção da leitura do sensor de vazão / pino 19 corresponde a interrupção 2
    detachInterrupt(digitalPinToInterrupt(Pino1));  // Desabilita somente a interrupção da leitura do sensor pluviômetro / pino 18 corresponde a interrupção 1

    digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
    delay(250);
    digitalWrite(BUZZER_VCC, false);        // Reseta o BUZZER
    delay(250);
    digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
    delay(250);
    digitalWrite(BUZZER_VCC, false);        // Reseta o BUZZER
    delay(250);
    digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
    delay(250);
    digitalWrite(BUZZER_VCC, false);        // Reseta o BUZZER

    tft.fillRect(0, 0, 240, 320, BLACK);
    tft.fillRoundRect(0, 0, 240, 95, 15, RED);
    tft.drawRoundRect(0, 0, 240, 95, 15, WHITE);

    tft.setCursor(23, 10);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.print(F("VERIFICANDO"));

    tft.setCursor(52, 37);
    tft.print(F("CAIXA DE"));

    tft.setCursor(14, 64);
    tft.print(F("MENSAGEM SMS"));

    tft.fillRoundRect(10, 110, 220, 30, 15, YELLOW);
    tft.drawRoundRect(10, 110, 220, 30, 15, RED);
    tft.setCursor(30, 114);
    tft.setTextColor(RED);
    tft.print(F("CHEGOU SMS!"));

    // ========================================================================================================
    // CONTA QUANTAS MENSAGENS SMS FOI RECEBIDO:

    msg_sms_rec++;

    // ========================================================================================================
    // CHECANDO RECEBIMENTO DE MENSAGENS VIA SMS É IGUAL AS SENHAS CADASTRADAS:

    // ========================================================================================================
    // SE AS SENHAS FOREM DIFERENTES, EXECUTA ABAIXO:

    mensagemSMS.trim();

    // TESTA SE AS MSGS FOREEM DIFERENTES DAS SENHAS PRÉ-CONFIGURADAS:
    if (  (  (mensagemSMS.equals(senhaGsm) ) || (mensagemSMS.equals(senhaGsm1) ) || (mensagemSMS.equals(senhaGsm2) ) || (mensagemSMS.equals(senhaGsm3) ) || (mensagemSMS.equals(senhaGsm4) ) || (mensagemSMS.equals(senhaGsm5) ) ) != 1   ) {

      tft.setCursor(10, 158);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("Cel:"));
      tft.setTextColor(WHITE);
      tft.print(telefoneSMS);

      tft.setCursor(10, 178);
      tft.setTextColor(CYAN);
      tft.setTextSize(1);
      tft.print(F("Mensagem: "));

      tft.setTextColor(WHITE);
      tft.print(mensagemSMS);
      delay(2000);

      tft.setTextSize(2);
      tft.fillRect(0, 280, 240, 38, RED);
      tft.setCursor(5, 282);
      tft.setTextColor(WHITE);
      tft.print(F(" Senha Nao Correta "));
      tft.setCursor(25, 300);
      tft.println(F("SMS Nao Enviado!"));

      int pino53 = 53;
      pinMode(pino53, OUTPUT);

      delay(500);
      SD.begin(pino53);
      delay(500);

      myFile = SD.open("SMS.txt", FILE_WRITE);
      myFile.print(F("NANO SMART AGRO - Mensagem SMS Recebida"));
      myFile.print(F(";"));
      myFile.print(F(" Cel:"));
      myFile.print(telefoneSMS);
      myFile.print(F(";"));
      myFile.print(F(" Msg: "));
      myFile.print(mensagemSMS);
      myFile.print(F(";"));
      myFile.print(F(" DATA: "));
      myFile.print(t.date, DEC);
      myFile.print(F("/"));
      myFile.print(t.mon, DEC);
      myFile.print(F("/"));
      myFile.print(t.year, DEC);
      myFile.print(F(";"));
      myFile.print(F(" HORARIO: "));
      myFile.print(rtc.getTimeStr());
      myFile.print(F(";"));
      myFile.println();
      myFile.println();
      delay(1000);
      myFile.close();
      delay(1000);

      SD.end();

      // ========================================================================================================
      // SE UMA DAS SENHAS FOREM IGUAIS, EXECUTA ABAIXO:

    } else {

      tft.setCursor(10, 158);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("Data:"));
      tft.setTextColor(WHITE);
      String dataSMS = dataHoraSMS;
      dataSMS.remove(8, 12);
      tft.print(dataSMS);

      tft.setCursor(10, 178);
      tft.setTextColor(CYAN);
      tft.print(F("Hora:"));
      tft.setTextColor(WHITE);
      String horaSMS = dataHoraSMS;
      horaSMS.remove(0, 9);
      horaSMS.remove(8, 3);
      tft.print(horaSMS);

      tft.setCursor(10, 198);
      tft.setTextColor(CYAN);
      tft.print(F("Mensagem:"));
      tft.setTextColor(WHITE);
      tft.print(mensagemSMS);

      tft.setCursor(10, 218);
      tft.setTextColor(CYAN);
      tft.print(F("Remetente:"));

      if (telefoneSMS == "+551599999999") {

        tft.setTextColor(WHITE);
        tft.print(F("Walter R."));
        tft.setCursor(10, 238);
        tft.setTextColor(CYAN);
        tft.print(F("Cel:"));
        tft.setTextColor(WHITE);
        tft.print(telefoneSMS);

      } else {

        tft.setTextColor(WHITE);
        tft.print(F(" Unknown "));
        tft.setCursor(10, 238);
        tft.setTextColor(CYAN);
        tft.print(F("Cel:"));
        tft.setTextColor(WHITE);
        tft.print(telefoneSMS);

      }

      tft.setTextColor(CYAN);
      tft.setCursor(10, 258);
      tft.print(F("SMS:"));
      tft.setTextColor(WHITE);
      delay(1000);
      tft.setCursor(57, 258);
      tft.print("Senha OK!");

      // senhaGsm = "***************"  senha para enviar o SMS com os valores das variaveis!
      mensagemSMS.trim();

      if ( mensagemSMS == senhaGsm ) {

        enviaSMS(telefoneSMS, "IoT NANO SMART AGRO \nSMS Recebido e Senha OK!");          // envia SMS com os valores dos sensores;

        delay(1500);
        leGSM();
        delay(1500);
  
        tft.setTextColor(CYAN, BLACK);
        tft.setCursor(10, 278);
        tft.print(F("GSM:"));
        tft.setTextColor(WHITE, BLACK);
        delay(1000);
        ultimoGSM.trim();            // Estrutura: >+CMGS: XXX OK
        tft.print(ultimoGSM);    
        
        tft.fillRect(0, 295, 240, 45, RED);
        tft.setTextColor(WHITE, RED);
        tft.setCursor(25, 300);
        tft.print(F("     Enviando     "));
        delay(1000);
        tft.setCursor(25, 300);
        tft.print(F("SMS de Resposta!"));
        delay(1000);
        tft.setCursor(25, 300);
        tft.print(F("  SMS ENVIADO!  "));
        delay(1000);

        msg_sms_env++;
        
        int pino53 = 53;
        pinMode(pino53, OUTPUT);

        delay(500);
        SD.begin(pino53);
        delay(500);

        myFile = SD.open("SMS.txt", FILE_WRITE);
        myFile.print(F("NANO SMART AGRO - Mensagem SMS Enviada"));
        myFile.print(F(";"));
        myFile.print(F(" Senha Recebida: NSAGROV1"));
        myFile.print(F(";"));
        myFile.print(F(" Solicitacao de Valores das Variaveis"));
        myFile.print(F(";"));
        myFile.print(F(" Cel:"));
        myFile.print(telefoneSMS);
        myFile.print(F(";"));
        myFile.print(F(" SMS Enviados: "));
        myFile.print(msg_sms_env);
        myFile.print(F(";"));
        myFile.print(F(" DATA: "));
        myFile.print(t.date, DEC);
        myFile.print(F("/"));
        myFile.print(t.mon, DEC);
        myFile.print(F("/"));
        myFile.print(t.year, DEC);
        myFile.print(F(";"));
        myFile.print(F(" HORARIO: "));
        myFile.print(rtc.getTimeStr());
        myFile.print(F(";"));
        myFile.println();
        myFile.println();
        delay(1000);
        myFile.close();
        delay(1000);

        SD.end();
      } // FECHA IF DE CHECAGEM DO RECEBIMENTO DE MENSAGENS VIA SMS É IGUAL A NSAGROV1


      // senhaGsm1 = "**********"  senha para enviar o SMS com o Diagnóstico!
      if ( mensagemSMS == senhaGsm1 ) {
        
        enviaSMS1(telefoneSMS, "IoT NANO SMART AGRO \nSMS Recebido e Senha OK!");          // envia SMS com os valores dos sensores;

        delay(1500);
        leGSM();
        delay(1500);
  
        tft.setTextColor(CYAN, BLACK);
        tft.setCursor(10, 278);
        tft.print(F("GSM:"));
        tft.setTextColor(WHITE, BLACK);
        delay(1000);
        ultimoGSM.trim();            // Estrutura: >+CMGS: XXX OK
        tft.print(ultimoGSM);    
        
        tft.fillRect(0, 295, 240, 45, RED);
        tft.setTextColor(WHITE, RED);
        tft.setCursor(25, 300);
        tft.print(F("     Enviando     "));
        delay(1000);
        tft.setCursor(25, 300);
        tft.print(F("SMS de Resposta!"));
        delay(1000);
        tft.setCursor(25, 300);
        tft.print(F("  SMS ENVIADO!  "));
        delay(1000);

        msg_sms_env++;

        int pino53 = 53;
        pinMode(pino53, OUTPUT);

        delay(500);
        SD.begin(pino53);
        delay(500);

        myFile = SD.open("SMS.txt", FILE_WRITE);
        myFile.print(F("NANO SMART AGRO - Mensagem SMS Enviada"));
        myFile.print(F(";"));
        myFile.print(F(" Senha Recebida: NSAGROD1"));
        myFile.print(F(";"));
        myFile.print(F(" Solicitacao de Envio de Diagnostico"));
        myFile.print(F(";"));
        myFile.print(F(" Cel:"));
        myFile.print(telefoneSMS);
        myFile.print(F(";"));
        myFile.print(F(" SMS Enviados: "));
        myFile.print(msg_sms_env);
        myFile.print(F(";"));
        myFile.print(F(" DATA: "));
        myFile.print(t.date, DEC);
        myFile.print(F("/"));
        myFile.print(t.mon, DEC);
        myFile.print(F("/"));
        myFile.print(t.year, DEC);
        myFile.print(F(";"));
        myFile.print(F(" HORARIO: "));
        myFile.print(rtc.getTimeStr());
        myFile.print(F(";"));
        myFile.println();
        myFile.println();
        delay(1000);
        myFile.close();
        delay(1000);

        SD.end();
      } // FECHA IF DE CHECAGEM DO RECEBIMENTO DE MENSAGENS VIA SMS É IGUAL A NSAGROD1


      // senhaGsm2 = "***********"  senha para solicitação de RESETE do Arduino!
      if ( mensagemSMS == senhaGsm2 ) {
        
        enviaSMS2(telefoneSMS, "IoT NANO SMART AGRO \nSMS Recebido e Senha OK!");          // envia SMS com os valores dos sensores;

                delay(1500);
        leGSM();
        delay(1500);
  
        tft.setTextColor(CYAN, BLACK);
        tft.setCursor(10, 278);
        tft.print(F("GSM:"));
        tft.setTextColor(WHITE, BLACK);
        delay(1000);
        ultimoGSM.trim();            // Estrutura: >+CMGS: XXX OK
        tft.print(ultimoGSM);    
        
        tft.fillRect(0, 295, 240, 45, RED);
        tft.setTextColor(WHITE, RED);
        tft.setCursor(25, 300);
        tft.print(F("     Enviando     "));
        delay(1000);
        tft.setCursor(25, 300);
        tft.print(F("SMS de Resposta!"));
        delay(1000);
        tft.setCursor(25, 300);
        tft.print(F("  SMS ENVIADO!  "));
        delay(1000);

        msg_sms_env++;

        int pino53 = 53;
        pinMode(pino53, OUTPUT);

        delay(500);
        SD.begin(pino53);
        delay(500);

        myFile = SD.open("SMS.txt", FILE_WRITE);
        myFile.print(F("NANO SMART AGRO - Mensagem SMS Enviada"));
        myFile.print(F(";"));
        myFile.print(F(" Senha Recebida: NSAGROR1"));
        myFile.print(F(";"));
        myFile.print(F(" Solicitacao de RESETE do Arduino"));
        myFile.print(F(";"));
        myFile.print(F(" Cel:"));
        myFile.print(telefoneSMS);
        myFile.print(F(";"));
        myFile.print(F(" SMS Enviados: "));
        myFile.print(msg_sms_env);
        myFile.print(F(";"));
        myFile.print(F(" DATA: "));
        myFile.print(t.date, DEC);
        myFile.print(F("/"));
        myFile.print(t.mon, DEC);
        myFile.print(F("/"));
        myFile.print(t.year, DEC);
        myFile.print(F(";"));
        myFile.print(F(" HORARIO: "));
        myFile.print(rtc.getTimeStr());
        myFile.print(F(";"));
        myFile.println();
        myFile.println();
        delay(1000);
        myFile.close();
        delay(1000);

        SD.end();

        modemGSM.restart();
        delay(1000);
        funcReset();

      }// FECHA IF DE CHECAGEM DO RECEBIMENTO DE MENSAGENS VIA SMS É IGUAL A NSAGROR1


      // senhaGsm3 = "**********"  senha para envio de SMS do Relatório de Gravação do SD CARD!
      if ( mensagemSMS == senhaGsm3 ) {
        
        enviaSMS3(telefoneSMS, "IoT NANO SMART AGRO \nSMS Recebido e Senha OK!");          // envia SMS com os valores dos sensores;

        delay(1500);
        leGSM();
        delay(1500);
  
        tft.setTextColor(CYAN, BLACK);
        tft.setCursor(10, 278);
        tft.print(F("GSM:"));
        tft.setTextColor(WHITE, BLACK);
        delay(1000);
        ultimoGSM.trim();            // Estrutura: >+CMGS: XXX OK
        tft.print(ultimoGSM);    
        
        tft.fillRect(0, 295, 240, 45, RED);
        tft.setTextColor(WHITE, RED);
        tft.setCursor(25, 300);
        tft.print(F("     Enviando     "));
        delay(1000);
        tft.setCursor(25, 300);
        tft.print(F("SMS de Resposta!"));
        delay(1000);
        tft.setCursor(25, 300);
        tft.print(F("  SMS ENVIADO!  "));
        delay(1000);

        msg_sms_env++;

        int pino53 = 53;
        pinMode(pino53, OUTPUT);

        delay(500);
        SD.begin(pino53);
        delay(500);

        myFile = SD.open("SMS.txt", FILE_WRITE);
        myFile.print(F("NANO SMART AGRO - Mensagem SMS Enviada"));
        myFile.print(F(";"));
        myFile.print(F(" Senha Recebida: NSAGROC1"));
        myFile.print(F(";"));
        myFile.print(F(" Solicitacao de Envio do Relatorio de Gravacao no SD Card"));
        myFile.print(F(";"));
        myFile.print(F(" Cel:"));
        myFile.print(telefoneSMS);
        myFile.print(F(";"));
        myFile.print(F(" SMS Enviados: "));
        myFile.print(msg_sms_env);
        myFile.print(F(";"));
        myFile.print(F(" DATA: "));
        myFile.print(t.date, DEC);
        myFile.print(F("/"));
        myFile.print(t.mon, DEC);
        myFile.print(F("/"));
        myFile.print(t.year, DEC);
        myFile.print(F(";"));
        myFile.print(F(" HORARIO: "));
        myFile.print(rtc.getTimeStr());
        myFile.print(F(";"));
        myFile.println();
        myFile.println();
        delay(1000);
        myFile.close();
        delay(1000);

        SD.end();

      } // FECHA IF DE CHECAGEM DO RECEBIMENTO DE MENSAGENS VIA SMS É IGUAL A NSAGROR1


      // senhaGsm4 = "*************"  senha para resete do Pluviômetro!
      if ( mensagemSMS == senhaGsm4 ) {

        enviaSMS4(telefoneSMS, "IoT NANO SMART AGRO \nSMS Recebido e Senha OK!");          // envia SMS com os valores dos sensores;

        delay(1500);
        leGSM();
        delay(1500);
  
        tft.setTextColor(CYAN, BLACK);
        tft.setCursor(10, 278);
        tft.print(F("GSM:"));
        tft.setTextColor(WHITE, BLACK);
        delay(1000);
        ultimoGSM.trim();            // Estrutura: >+CMGS: XXX OK
        tft.print(ultimoGSM);    
        
        tft.fillRect(0, 295, 240, 45, RED);
        tft.setTextColor(WHITE, RED);
        tft.setCursor(25, 300);
        tft.print(F("     Enviando     "));
        delay(1000);
        tft.setCursor(25, 300);
        tft.print(F("SMS de Resposta!"));
        delay(1000);
        tft.setCursor(25, 300);
        tft.print(F("  SMS ENVIADO!  "));
        delay(1000);

        msg_sms_env++;

        Read_Pulso1 = 0;
        Read_Pulso1Antigo = 0;
        contaPulso1 = 0;             // RESETA PULSOS DO PLUVIÔMETRO
        pluviometro = 0;
        pluviometro_acum = 0;
        sms_pluviometro = true;

        int pino53 = 53;
        pinMode(pino53, OUTPUT);

        delay(500);
        SD.begin(pino53);
        delay(500);

        myFile = SD.open("SMS.txt", FILE_WRITE);
        myFile.print(F("NANO SMART AGRO - Mensagem SMS Enviada"));
        myFile.print(F(";"));
        myFile.print(F(" Senha Recebida: NSAGROP1"));
        myFile.print(F(";"));
        myFile.print(F(" Solicitacao de Resete do Pluviometro!"));
        myFile.print(F(";"));
        myFile.print(F(" Cel:"));
        myFile.print(telefoneSMS);
        myFile.print(F(";"));
        myFile.print(F(" SMS Enviados: "));
        myFile.print(msg_sms_env);
        myFile.print(F(";"));
        myFile.print(F(" DATA: "));
        myFile.print(t.date, DEC);
        myFile.print(F("/"));
        myFile.print(t.mon, DEC);
        myFile.print(F("/"));
        myFile.print(t.year, DEC);
        myFile.print(F(";"));
        myFile.print(F(" HORARIO: "));
        myFile.print(rtc.getTimeStr());
        myFile.print(F(";"));
        myFile.println();
        myFile.println();
        
        delay(1000);
        myFile.close();
        delay(1000);

        SD.end();

      } // FECHA IF DE CHECAGEM DO RECEBIMENTO DE MENSAGENS VIA SMS É IGUAL A NSAGROP1


      // senhaGsm5 = "**************"  senha para resete do Totalizador de Vazão
      if ( mensagemSMS == senhaGsm5 ) {
       
        enviaSMS5(telefoneSMS, "IoT NANO SMART AGRO \nSMS Recebido e Senha OK!");          // envia SMS com os valores dos sensores;

        delay(1500);
        leGSM();
        delay(1500);
  
        tft.setTextColor(CYAN, BLACK);
        tft.setCursor(10, 278);
        tft.print(F("GSM:"));
        tft.setTextColor(WHITE, BLACK);
        delay(1000);
        ultimoGSM.trim();            // Estrutura: >+CMGS: XXX OK
        tft.print(ultimoGSM);    
        
        tft.fillRect(0, 295, 240, 45, RED);
        tft.setTextColor(WHITE, RED);
        tft.setCursor(25, 300);
        tft.print(F("     Enviando     "));
        delay(1000);
        tft.setCursor(25, 300);
        tft.print(F("SMS de Resposta!"));
        delay(1000);
        tft.setCursor(25, 300);
        tft.print(F("  SMS ENVIADO!  "));
        delay(1000);

        msg_sms_env++;

        // Resetando Variáveis do Totalizador de Vazão:
        MiliLitros = 0.00;
        Litros = 0.00;
        contaPulsotot = 0;


        int pino53 = 53;
        pinMode(pino53, OUTPUT);

        delay(500);
        SD.begin(pino53);
        delay(500);

        myFile = SD.open("SMS.txt", FILE_WRITE);
        myFile.print(F("NANO SMART AGRO - Mensagem SMS Enviada"));
        myFile.print(F(";"));
        myFile.print(F(" Senha Recebida: NSAGROT1"));
        myFile.print(F(";"));
        myFile.print(F(" Solicitacao de Resete do Totalizador de Vazao"));
        myFile.print(F(";"));
        myFile.print(F(" Cel:"));
        myFile.print(telefoneSMS);
        myFile.print(F(";"));
        myFile.print(F(" SMS Enviados: "));
        myFile.print(msg_sms_env);
        myFile.print(F(";"));
        myFile.print(F(" DATA: "));
        myFile.print(t.date, DEC);
        myFile.print(F("/"));
        myFile.print(t.mon, DEC);
        myFile.print(F("/"));
        myFile.print(t.year, DEC);
        myFile.print(F(";"));
        myFile.print(F(" HORARIO: "));
        myFile.print(rtc.getTimeStr());
        myFile.print(F(";"));
        myFile.println();
        myFile.println();
        
        delay(1000);
        myFile.close();
        delay(1000);

        SD.end();

      } // FECHA IF DE CHECAGEM DO RECEBIMENTO DE MENSAGENS VIA SMS É IGUAL A NSAGROT1


    } // FECHA IF/ELSE DO TESTE SE A MENSAGEM SMS É IGUAL A UMA DAS SEBHAS CADASTRADAS

    temSMS = false;

    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);          //HABILITA NOVAMENTE A INTERRUPÇÃO PARA CÁLCULO DA VAZÃO
    attachInterrupt(digitalPinToInterrupt(Pino1), pulso_chuva, RISING);  //HABILITA NOVAMENTE A INTERRUPÇÃO PARA CÁLCULO DO PLUVIÔMETRO.

  } // FECHA WHILE QUANDO TEM A OPÇÃO TEM SMS RECEBIDO
  //========================================================================================================
  // FUNÇÃO DE VERICAÇÃO SE TOUCH SCREEN FOI TOCADO:

  tp = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {
    display_menu = true; //HABILITA LOOP WHILE QUANDO HÁ UM TOQUE NA TELA DO DISPLAY LCD
    tft.fillRect(0, 0, 240, 320, BLACK);
    cont1 ++;      //VARIAVEL AUXILIAR PARA HABILITAR O MENU DE SELEÇÃO
  }

  //========================================================================================================
  // FUNÇÃO DE EXIBIÇÃO DO MENU DO DISPLAY QUANDO O DISPLAY É TOCADO:

  while (display_menu == true) {

    aux_display_menu = millis();
    tft.fillRoundRect(5, 15, 230, 50, 15, RED);
    tft.drawRoundRect(5, 15, 230, 50, 15, WHITE);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.setCursor(15, 30);
    tft.println(F("DISPLAY MENU"));

    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(0, 80);
    tft.println(F("1-DIAGNOSTICO"));
    tft.setCursor(0, 100);
    tft.println(F("2-ARQUIVOS SD CARD"));
    tft.setCursor(0, 120);
    tft.println(F("3-ENVIA SMS"));
    tft.setCursor(0, 140);
    tft.println(F("4-RELATORIOS"));
    tft.setCursor(0, 160);
    tft.println(F("5-PROXIMO MENU"));

    tft.fillRoundRect(5, 192, 230, 30, 5, RED);
    tft.drawRoundRect(5, 192, 230, 30, 5, WHITE);
    tft.setCursor(15, 200);
    tft.println(F(" NSAGRO V:4.01.34"));

    tft.setCursor(0, 260);
    tft.print(F(" Selecione a opcao:"));
    tft.drawRoundRect(5, 282, 230, 30, 5, WHITE);

    // DESENHANDO OS BOTÕES DE APLICAÇÃO:
    tft.fillRoundRect(15, 290, 30, 30, 5, RED);
    tft.drawRoundRect(15, 290, 30, 30, 5, WHITE);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.setCursor(24, 298);
    tft.println(F("1"));

    // DESENHANDO OS BOTÕES DE APLICAÇÃO:
    tft.fillRoundRect(60, 290, 30, 30, 5, RED);
    tft.drawRoundRect(60, 290, 30, 30, 5, WHITE);
    tft.setTextColor(WHITE);
    //tft.setTextSize(2);
    tft.setCursor(69, 298);
    tft.println(F("2"));

    // DESENHANDO OS BOTÕES DE APLICAÇÃO:
    tft.fillRoundRect(105, 290, 30, 30, 5, RED);
    tft.drawRoundRect(105, 290, 30, 30, 5, WHITE);
    tft.setTextColor(WHITE);
    //tft.setTextSize(2);
    tft.setCursor(114, 298);
    tft.println(F("3"));

    // DESENHANDO OS BOTÕES DE APLICAÇÃO:
    tft.fillRoundRect(150, 290, 30, 30, 5, RED);
    tft.drawRoundRect(150, 290, 30, 30, 5, WHITE);
    tft.setTextColor(WHITE);
    //tft.setTextSize(2);
    tft.setCursor(159, 298);
    tft.println(F("4"));

    // DESENHANDO OS BOTÕES DE APLICAÇÃO:
    tft.fillRoundRect(195, 290, 30, 30, 5, RED);
    tft.drawRoundRect(195, 290, 30, 30, 5, WHITE);
    tft.setTextColor(WHITE);
    //tft.setTextSize(2);
    tft.setCursor(204, 298);
    tft.println(F("5"));

    display_menu = false;

    while (millis() - aux_display_menu < 10000) {

      tp = ts.getPoint();
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);

      if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {
        cont1 ++;      //VARIAVEL AUXILIAR PARA HABILITAR O MENU DE SELEÇÃO
      }

      if (millis() - aux_display_menu > 9000) {
        display_menu1 = false;
        display_menu = false;
        break;
      }

      //========================================================================================================
      // EXIBE O MENU SELECIONADO QUANDO OCORRER O SEGUNDO TOQUE NA TELA (CONT1 >=2):

      if (cont1 >= 2) {

        //========================================================================================================
        // EXIBE O MENU SELECIONADO QUANDO OCORRER O TOQUE NO BOTÃO 01:

        // BOTÃO 1 - DIAGNOSTICO - FUNÇÃO D1()
        if (tp.x > 225 && tp.x < 300  && tp.y > 175 && tp.y < 260) {

          // DESENHANDO OS BOTÕES DE APLICAÇÃO:
          tft.setTextColor(YELLOW);
          tft.setTextSize(2);
          tft.setCursor(0, 80);
          tft.println(F("1-DIAGNOSTICO"));
          tft.setTextColor(WHITE);
          tft.setCursor(0, 100);
          tft.fillRoundRect(15, 290, 30, 30, 5, RED);
          tft.drawRoundRect(15, 290, 30, 30, 5, YELLOW);
          tft.setTextColor(BLACK);
          //tft.setTextSize(2);
          tft.setCursor(25, 298);
          tft.println(F("X"));
          delay(2000);

          d1();
          display_menu = false;
          cont1 = 0;

          //========================================================================================================
          // Sincronizar os tempos para iniciar o loop novamente para não ter superposição de função

          anterior = millis();
          anterior2 = anterior;
          anterior3 = anterior2;
          anterior4 = anterior3;
          anterior5 = anterior4;
          anterior6 = anterior5;
          anterior7 = anterior6;
          anterior8 = anterior7;
          anterior9 = anterior8;
          anterior10 = anterior9;
          anterior11 = anterior10;
          anterior12 = anterior11;
          anterior13 = anterior12;
          anterior14 = anterior13;
          anterior15 = anterior14;
          anterior16 = anterior15;
          anterior17 = anterior16;
          anterior18 = anterior17;
          anterior19 = anterior18;
          anterior20 = anterior19;

          intervalo =  10000;
          intervalo2 = 20000;
          intervalo3 = 30000;
          intervalo4 = 40000;
          intervalo5 = 50000;
          intervalo6 = 60000;
          intervalo7 = 70000;
          intervalo8 = 80000;
          intervalo9 = 90000;
          intervalo10 = 100000;
          intervalo11 = 110000;
          intervalo12 = 120000;
          intervalo13 = 130000;
          intervalo14 = 140000;
          intervalo15 = 150000;
          intervalo16 = 160000;
          intervalo17 = 170000;
          intervalo18 = 180000;
          intervalo19 = 190000;
          intervalo20 = 200000;
          break;

        } // FECHA IF DO BOTÃO 1 SELECIONADO


        //========================================================================================================
        // EXIBE O MENU SELECIONADO QUANDO OCORRER O TOQUE NO BOTÃO 02:

        // BOTÃO 2 - ARQUIVOS GRAVADOS NO SD CARD
        if (tp.x > 370 && tp.x < 445  && tp.y > 175 && tp.y < 260) {

          //========================================================================================================
          // Sincronizar os tempos para iniciar o loop novamente para não ter superposição de função

          anterior = millis();
          anterior2 = anterior;
          anterior3 = anterior2;
          anterior4 = anterior3;
          anterior5 = anterior4;
          anterior6 = anterior5;
          anterior7 = anterior6;
          anterior8 = anterior7;
          anterior9 = anterior8;
          anterior10 = anterior9;
          anterior11 = anterior10;
          anterior12 = anterior11;
          anterior13 = anterior12;
          anterior14 = anterior13;
          anterior15 = anterior14;
          anterior16 = anterior15;
          anterior17 = anterior16;
          anterior18 = anterior17;
          anterior19 = anterior18;
          anterior20 = anterior19;

          intervalo =  10000;
          intervalo2 = 20000;
          intervalo3 = 30000;
          intervalo4 = 40000;
          intervalo5 = 50000;
          intervalo6 = 60000;
          intervalo7 = 70000;
          intervalo8 = 80000;
          intervalo9 = 90000;
          intervalo10 = 100000;
          intervalo11 = 110000;
          intervalo12 = 120000;
          intervalo13 = 130000;
          intervalo14 = 140000;
          intervalo15 = 150000;
          intervalo16 = 160000;
          intervalo17 = 170000;
          intervalo18 = 180000;
          intervalo19 = 190000;
          intervalo20 = 200000;

          tft.setTextColor(YELLOW);
          tft.setTextSize(2);
          tft.setCursor(0, 100);
          tft.println(F("2-ARQUIVOS SD CARD"));
          tft.fillRoundRect(60, 290, 30, 30, 5, RED);
          tft.drawRoundRect(60, 290, 30, 30, 5, YELLOW);
          tft.setTextColor(BLACK);
          tft.setCursor(70, 298);
          tft.println(F("X"));
          delay(2000);

          tft.fillRect(0, 0, 240, 320, BLACK);
          tft.fillRect(0, 0, 240, 30, RED);
          tft.setCursor(5, 7);
          tft.setTextColor(WHITE);
          tft.println(F("ARQUIVOS NO SD CARD"));

          delay(1000);
          tft.drawRect(0, 30, 240, 290, YELLOW);
          delay(1000);

          tft.setCursor(0, 35);
          tft.setTextColor(WHITE);

          int pino53 = 53;
          pinMode(pino53, OUTPUT);
          delay(500);
          SD.begin(pino53);
          delay(500);
          File root;
          root = SD.open("/");
          printDirectory(root, 0);
          root.close();
          display_menu = false;
          cont1 = 0;

          break;

        } // FECHA IF DO BOTÃO 2 SELECIONADO


        //========================================================================================================
        // EXIBE O MENU SELECIONADO QUANDO OCORRER O TOQUE NO BOTÃO 03:

        // BOTÃO 3 - ENVIO DE MENSAGEM SMS DE TESTE:
        if (tp.x > 484  && tp.x < 574  && tp.y > 175 && tp.y < 260) {

          tft.setTextSize(2);
          tft.setCursor(0, 120);
          tft.setTextColor(YELLOW);
          tft.println(F("3-ENVIA SMS"));
          tft.fillRoundRect(105, 290, 30, 30, 5, RED);
          tft.drawRoundRect(105, 290, 30, 30, 5, YELLOW);
          tft.setTextColor(BLACK);
          tft.setCursor(115, 298);
          tft.println(F("X"));
          delay(2000);

        //========================================================================================================
        // APÓS A SELEÇÃO DO BOTÃO NÚMERO 03, DEVE SELECIONAR A OPÇÃO DE ENVIO DE SMS:

          display_menu1 = true;
          tft.fillRect(0, 0, 240, 320, BLACK);

          tft.fillRoundRect(5, 15, 230, 50, 15, RED);
          tft.drawRoundRect(5, 15, 230, 50, 15, WHITE);
          tft.setTextColor(WHITE);
          tft.setTextSize(3);
          tft.setCursor(15, 30);
          tft.println(F("DISPLAY MENU"));

          tft.setTextColor(WHITE);
          tft.setTextSize(2);
          tft.setCursor(0, 80);
          tft.println(F("1-CONSULTA SALDO SMS"));
          tft.setCursor(0, 100);
          tft.println(F("2-ENVIO SMS TESTE"));
          tft.setCursor(0, 120);
          tft.println(F("3-CONFIRMA SALDO SMS"));
          tft.setCursor(0, 160);
          tft.println(F("5-RETORNA"));

          tft.fillRoundRect(5, 192, 230, 30, 5, RED);
          tft.drawRoundRect(5, 192, 230, 30, 5, WHITE);
          tft.setCursor(15, 200);
          tft.println(F(" NSAGRO V:4.01.34 "));

          tft.setCursor(0, 260);
          tft.print(F(" Selecione a opcao:"));
          tft.drawRoundRect(5, 282, 230, 30, 5, WHITE);

          // DESENHANDO OS BOTÕES DE APLICAÇÃO:
          tft.fillRoundRect(15, 290, 30, 30, 5, RED);
          tft.drawRoundRect(15, 290, 30, 30, 5, WHITE);
          tft.setTextColor(WHITE);
          tft.setTextSize(2);
          tft.setCursor(24, 298);
          tft.println(F("1"));
      
          // DESENHANDO OS BOTÕES DE APLICAÇÃO:
          tft.fillRoundRect(60, 290, 30, 30, 5, RED);
          tft.drawRoundRect(60, 290, 30, 30, 5, WHITE);
          tft.setTextColor(WHITE);
          tft.setCursor(69, 298);
          tft.println(F("2"));
      
          // DESENHANDO OS BOTÕES DE APLICAÇÃO:
          tft.fillRoundRect(105, 290, 30, 30, 5, RED);
          tft.drawRoundRect(105, 290, 30, 30, 5, WHITE);
          tft.setTextColor(WHITE);
          tft.setCursor(114, 298);
          tft.println(F("3"));
      
          // DESENHANDO OS BOTÕES DE APLICAÇÃO:
          tft.fillRoundRect(195, 290, 30, 30, 5, RED);
          tft.drawRoundRect(195, 290, 30, 30, 5, WHITE);
          tft.setTextColor(WHITE);
          tft.setCursor(204, 298);
          tft.println(F("5"));

          aux_display_menu1 = millis();

          //========================================================================================================
          // EXIBE O PROXIMO MENU COM AS OPÇÕES DE 6 A 10 DOS BOTÕES NO DISPLAY:

          while (display_menu1) {

            // FUNÇÃO PARA RETORNAR AO LOOP PRINCIPAL SE O TEMPO FOR MAIOR QUE 10 SEG APÓS SELECIONADO O BOTÃO 5
            if (millis() - aux_display_menu1 > 10000) {
              display_menu1 = false;
              display_menu = false;

              // ========================================================================================================
              // Sincronizar os tempos para iniciar o loop novamente para não ter superposição de função

              anterior = millis();
              anterior2 = anterior;
              anterior3 = anterior2;
              anterior4 = anterior3;
              anterior5 = anterior4;
              anterior6 = anterior5;
              anterior7 = anterior6;
              anterior8 = anterior7;
              anterior9 = anterior8;
              anterior10 = anterior9;
              anterior11 = anterior10;
              anterior12 = anterior11;
              anterior13 = anterior12;
              anterior14 = anterior13;
              anterior15 = anterior14;
              anterior16 = anterior15;
              anterior17 = anterior16;
              anterior18 = anterior17;
              anterior19 = anterior18;
              anterior20 = anterior19;

              intervalo =  10000;
              intervalo2 = 20000;
              intervalo3 = 30000;
              intervalo4 = 40000;
              intervalo5 = 50000;
              intervalo6 = 60000;
              intervalo7 = 70000;
              intervalo8 = 80000;
              intervalo9 = 90000;
              intervalo10 = 100000;
              intervalo11 = 110000;
              intervalo12 = 120000;
              intervalo13 = 130000;
              intervalo14 = 140000;
              intervalo15 = 150000;
              intervalo16 = 160000;
              intervalo17 = 170000;
              intervalo18 = 180000;
              intervalo19 = 190000;
              intervalo20 = 200000;

              return;

            } // FECHA IF DA FUNÇÃO PARA RETORNAR AO LOOP PRINCIPAL SE O TEMPO FOR MAIOR QUE 10 SEG APÓS SELECIONADO O BOTÃO 5

            // VERIFICA SE HOUVE TOQUE NA TELA E ARMEZA O PONTO SELECIONADO
            tp = ts.getPoint();
            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            // BOTÃO 1 - CONSULTA SALDO SMS NA OPERADORA VIVO:
            if (tp.x > 225 && tp.x < 300  && tp.y > 175 && tp.y < 260) {

              tft.setTextColor(YELLOW, BLACK);
              tft.setTextSize(2);
              tft.setCursor(0, 80);
              tft.println(F("1-CONSULTA SALDO SMS"));
              tft.fillRoundRect(15, 290, 30, 30, 5, RED);
              tft.drawRoundRect(15, 290, 30, 30, 5, YELLOW);
              tft.setTextColor(BLACK);
              tft.setCursor(25, 298);
              tft.println(F("X"));
              delay(2500);

              //========================================================================================================
              // Enviando SMS para consultar o Saldo do celular:
    
              tft.fillRect(0, 0, 240, 320, BLACK);
    
              digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
              delay(250);
              digitalWrite(BUZZER_VCC, false);         // Seta o BUZZER
              delay(250);
              digitalWrite(BUZZER_VCC, true);        // Seta o BUZZER
              delay(250);
              digitalWrite(BUZZER_VCC, false);        // Seta o BUZZER
              delay(250);
              digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
              delay(250);
              digitalWrite(BUZZER_VCC, false);        // Seta o BUZZER
    
              tft.fillRoundRect(0, 0, 240, 95, 15, RED);
              tft.drawRoundRect(0, 0, 240, 95, 15, WHITE);
              tft.setCursor(23, 10);
              tft.setTextColor(WHITE);
              tft.setTextSize(3);
              tft.print(F("VERIFICANDO"));
    
              tft.setCursor(52, 37);
              tft.setTextColor(WHITE);
              tft.setTextSize(3);
              tft.print(F("ENVIO DE"));
    
              tft.setCursor(14, 64);
              tft.setTextColor(WHITE);
              tft.setTextSize(3);
              tft.print(F("MENSAGEM SMS"));
    
              tft.fillRoundRect(10, 110, 220, 30, 15, YELLOW);
              tft.drawRoundRect(10, 110, 220, 30, 15, RED);
              tft.setCursor(30, 114);
              tft.setTextColor(RED);
              tft.setTextSize(3);
              tft.print(F("ENVIAR SMS!"));
    
              //========================================================================================================
              // Enviando SMS para a Operadora VIVO:
    
              tft.setCursor(10, 158);
              tft.setTextColor(CYAN);
              tft.setTextSize(2);
              tft.print(F("SMS para:"));
              tft.setTextColor(WHITE);
              tft.print(F("VIVO S.A."));
    
              tft.setCursor(10, 178);
              tft.setTextColor(CYAN);
              tft.print(F("Tel:"));
              tft.setTextColor(WHITE);
              tft.print(F(" 1058"));
    
              tft.setCursor(10, 198);
              tft.setTextColor(CYAN);
              tft.print(F("Mensagem: "));
              tft.setTextColor(WHITE);
              tft.print(F("Consulta Saldo!"));
    
              delay(2000);

              tft.fillRect(0, 280, 240, 38, RED);
              tft.setCursor(5, 282);
              tft.setTextColor(WHITE);
              tft.print(F(" Aguardando Saldo! "));
              tft.setCursor(25, 300);
              tft.print(F("  SMS Enviado!  "));
              delay(3000);
    
              msg_sms_env++;
    
              int pino53 = 53;
              pinMode(pino53, OUTPUT);
              delay(500);
              SD.begin(pino53);
              delay(500);
    
              myFile = SD.open("SMS.txt", FILE_WRITE);
              myFile.print(F("NANO SMART AGRO - Mensagem SMS Enviada"));
              myFile.print(F(";"));
              myFile.print(F(" Envio de mensagem SMS para consultar Saldo de Recarga Vivo!"));
              myFile.print(F(";"));
              myFile.print(F(" Tel: 1058"));
              myFile.print(F(";"));
              myFile.print(F(" SMS Enviados: "));
              myFile.print(msg_sms_env);
              myFile.print(F(";"));
              myFile.print(F(" DATA: "));
              myFile.print(t.date, DEC);
              myFile.print(F("/"));
              myFile.print(t.mon, DEC);
              myFile.print(F("/"));
              myFile.print(t.year, DEC);
              myFile.print(F(";"));
              myFile.print(F(" HORARIO: "));
              myFile.print(rtc.getTimeStr());
              myFile.print(F(";"));
              myFile.println();
              myFile.println();
              
              delay(1000);
              myFile.close();
              delay(1000);
              SD.end();
  
              // ========================================================================================================
              // Sincronizar os tempos para iniciar o loop novamente para não ter superposição de função

              anterior = millis();
              anterior2 = anterior;
              anterior3 = anterior2;
              anterior4 = anterior3;
              anterior5 = anterior4;
              anterior6 = anterior5;
              anterior7 = anterior6;
              anterior8 = anterior7;
              anterior9 = anterior8;
              anterior10 = anterior9;
              anterior11 = anterior10;
              anterior12 = anterior11;
              anterior13 = anterior12;
              anterior14 = anterior13;
              anterior15 = anterior14;
              anterior16 = anterior15;
              anterior17 = anterior16;
              anterior18 = anterior17;
              anterior19 = anterior18;
              anterior20 = anterior19;

              intervalo =  10000;
              intervalo2 = 20000;
              intervalo3 = 30000;
              intervalo4 = 40000;
              intervalo5 = 50000;
              intervalo6 = 60000;
              intervalo7 = 70000;
              intervalo8 = 80000;
              intervalo9 = 90000;
              intervalo10 = 100000;
              intervalo11 = 110000;
              intervalo12 = 120000;
              intervalo13 = 130000;
              intervalo14 = 140000;
              intervalo15 = 150000;
              intervalo16 = 160000;
              intervalo17 = 170000;
              intervalo18 = 180000;
              intervalo19 = 190000;
              intervalo20 = 200000;

              enviaSMS8("1058", "DADOS");          // enviaSMS para a Vivo para consultar o Saldo de Recarga

              display_menu = false;
              display_menu1 = false;
              cont1 = 0;
             
              delay(1000);
              leGSM();
              tft.setTextColor(CYAN, BLACK);
              tft.setTextSize(2);
              tft.setCursor(10, 238);
              tft.print(F("GSM: "));
              tft.setTextColor(WHITE);
              ultimoGSM.trim();            // Estrutura: >+CMGS: XXX OK
              tft.print(ultimoGSM);
              delay(1000);
              return;

            }

            // BOTÃO 2 - ENVIA SMS DE TESTE:
            if (tp.x > 370 && tp.x < 445  && tp.y > 175 && tp.y < 260) {
    
              tft.setTextColor(YELLOW);
              tft.setTextSize(2);
              tft.setCursor(0, 100);
              tft.println(F("2-ENVIO SMS TESTE"));
              tft.fillRoundRect(60, 290, 30, 30, 5, RED);
              tft.drawRoundRect(60, 290, 30, 30, 5, YELLOW);
              tft.setTextColor(BLACK);
              tft.setCursor(70, 298);
              tft.println(F("X"));
              delay(2000);

              tft.fillRect(0, 0, 240, 320, BLACK);

              digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
              delay(250);
              digitalWrite(BUZZER_VCC, false);         // Seta o BUZZER
              delay(250);
              digitalWrite(BUZZER_VCC, true);        // Seta o BUZZER
              delay(250);
              digitalWrite(BUZZER_VCC, false);        // Seta o BUZZER
              delay(250);
              digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
              delay(250);
              digitalWrite(BUZZER_VCC, false);        // Seta o BUZZER
    
              tft.fillRoundRect(0, 0, 240, 95, 15, RED);
              tft.drawRoundRect(0, 0, 240, 95, 15, WHITE);
              tft.setCursor(23, 10);
              tft.setTextColor(WHITE);
              tft.setTextSize(3);
              tft.print(F("VERIFICANDO"));
    
              tft.setCursor(52, 37);
              tft.setTextColor(WHITE);
              tft.setTextSize(3);
              tft.print(F("ENVIO DE"));
    
              tft.setCursor(14, 64);
              tft.setTextColor(WHITE);
              tft.setTextSize(3);
              tft.print(F("MENSAGEM SMS"));
    
              tft.fillRoundRect(10, 110, 220, 30, 15, YELLOW);
              tft.drawRoundRect(10, 110, 220, 30, 15, RED);
              tft.setCursor(30, 114);
              tft.setTextColor(RED);
              tft.setTextSize(3);
              tft.print(F("ENVIAR SMS!"));
    
              //========================================================================================================
              // Enviando SMS para o celular +5515999999999!
    
              tft.setCursor(10, 158);
              tft.setTextColor(CYAN);
              tft.setTextSize(2);
              tft.print(F("SMS para:"));
              tft.setTextColor(WHITE);
              tft.print(F("Walter R."));
    
              tft.setCursor(10, 178);
              tft.setTextColor(CYAN);
              //tft.setTextSize(2);
              tft.print(F("Cel:"));
              tft.setTextColor(WHITE);
              tft.print(F("+55159999999"));
    
              tft.setCursor(10, 198);
              tft.print(F("Mensagem: "));
              tft.setTextColor(WHITE);
              tft.print(F("Envio de Mensagem SMS Teste!"));
   
              tft.fillRect(0, 280, 240, 38, RED);
              tft.setCursor(5, 282);
              tft.setTextColor(WHITE);
              tft.print(F("Valor dos Sensores!"));
              tft.setCursor(25, 300);
              tft.print(F("  SMS Enviado!  "));
    
              msg_sms_env++;
    
              delay(2000);
              int pino53 = 53;
              pinMode(pino53, OUTPUT);
              delay(500);
              SD.begin(pino53);
              delay(500);
    
              myFile = SD.open("SMS.txt", FILE_WRITE);
              myFile.print(F("NANO SMART AGRO - Mensagem SMS Enviada"));
              myFile.print(F(";"));
              myFile.print(F(" Envio de mensagem SMS para teste"));
              myFile.print(F(";"));
              myFile.print(F(" Cel:"));
              myFile.print("+551599999999");
              myFile.print(F(";"));
              myFile.print(F(" SMS Enviados: "));
              myFile.print(msg_sms_env);
              myFile.print(F(";"));
              myFile.print(F(" DATA: "));
              myFile.print(t.date, DEC);
              myFile.print(F("/"));
              myFile.print(t.mon, DEC);
              myFile.print(F("/"));
              myFile.print(t.year, DEC);
              myFile.print(F(";"));
              myFile.print(F(" HORARIO: "));
              myFile.print(rtc.getTimeStr());
              myFile.print(F(";"));
              myFile.println();
              myFile.println();
              
              delay(1000);
              myFile.close();
              delay(1000);
              SD.end();

              display_menu = false;
              display_menu1 = false;
              cont1 = 0;

              // ========================================================================================================
              // Sincronizar os tempos para iniciar o loop novamente para não ter superposição de função

              anterior = millis();
              anterior2 = anterior;
              anterior3 = anterior2;
              anterior4 = anterior3;
              anterior5 = anterior4;
              anterior6 = anterior5;
              anterior7 = anterior6;
              anterior8 = anterior7;
              anterior9 = anterior8;
              anterior10 = anterior9;
              anterior11 = anterior10;
              anterior12 = anterior11;
              anterior13 = anterior12;
              anterior14 = anterior13;
              anterior15 = anterior14;
              anterior16 = anterior15;
              anterior17 = anterior16;
              anterior18 = anterior17;
              anterior19 = anterior18;
              anterior20 = anterior19;

              intervalo =  10000;
              intervalo2 = 20000;
              intervalo3 = 30000;
              intervalo4 = 40000;
              intervalo5 = 50000;
              intervalo6 = 60000;
              intervalo7 = 70000;
              intervalo8 = 80000;
              intervalo9 = 90000;
              intervalo10 = 100000;
              intervalo11 = 110000;
              intervalo12 = 120000;
              intervalo13 = 130000;
              intervalo14 = 140000;
              intervalo15 = 150000;
              intervalo16 = 160000;
              intervalo17 = 170000;
              intervalo18 = 180000;
              intervalo19 = 190000;
              intervalo20 = 200000;
    
              enviaSMS("+55159999999", "IoT NANO SMART AGRO \n**AVISO IMPORTANTE**");          // enviaSMS(telefoneSMS, o resumo de funcionamento do protótipo!
    
              delay(1000);
              leGSM();
              tft.setTextColor(CYAN, BLACK);
              tft.setTextSize(2);
              tft.setCursor(10, 238);
              tft.print(F("GSM: "));
              tft.setTextColor(WHITE);
              ultimoGSM.trim();            // Estrutura: >+CMGS: XXX OK
              tft.print(ultimoGSM);
              delay(1000);
              
              return;

            } //  FECHA IF DO BOTÃO 02 PARA ENVIO DE SMS TESTE. 


            // BOTÃO 3 - CONFIRMA SALDO SMS NA OPERADORA VIVO: 
            if (tp.x > 484  && tp.x < 574  && tp.y > 175 && tp.y < 260) {

              tft.setTextSize(2);
              tft.setCursor(0, 120);
              tft.setTextColor(YELLOW);
              tft.println(F("3-CONFIRMA SALDO SMS"));
              tft.fillRoundRect(105, 290, 30, 30, 5, RED);
              tft.drawRoundRect(105, 290, 30, 30, 5, YELLOW);
              tft.setTextColor(BLACK);
              tft.setCursor(115, 298);
              tft.println(F("X"));
              delay(2500);

              //========================================================================================================
              // Enviando SMS para consultar o Saldo do celular:
    
              tft.fillRect(0, 0, 240, 320, BLACK);
    
              digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
              delay(250);
              digitalWrite(BUZZER_VCC, false);         // Seta o BUZZER
              delay(250);
              digitalWrite(BUZZER_VCC, true);        // Seta o BUZZER
              delay(250);
              digitalWrite(BUZZER_VCC, false);        // Seta o BUZZER
              delay(250);
              digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
              delay(250);
              digitalWrite(BUZZER_VCC, false);        // Seta o BUZZER
    
              tft.fillRoundRect(0, 0, 240, 95, 15, RED);
              tft.drawRoundRect(0, 0, 240, 95, 15, WHITE);
              tft.setCursor(23, 10);
              tft.setTextColor(WHITE);
              tft.setTextSize(3);
              tft.print(F("VERIFICANDO"));
    
              tft.setCursor(52, 37);
              tft.setTextColor(WHITE);
              tft.setTextSize(3);
              tft.print(F("ENVIO DE"));
    
              tft.setCursor(14, 64);
              tft.setTextColor(WHITE);
              tft.setTextSize(3);
              tft.print(F("MENSAGEM SMS"));
    
              tft.fillRoundRect(10, 110, 220, 30, 15, YELLOW);
              tft.drawRoundRect(10, 110, 220, 30, 15, RED);
              tft.setCursor(30, 114);
              tft.setTextColor(RED);
              tft.setTextSize(3);
              tft.print(F("ENVIAR SMS!"));
    
              //========================================================================================================
              // Enviando SMS para a Opertadora Vivo:
    
              tft.setCursor(10, 158);
              tft.setTextColor(CYAN);
              tft.setTextSize(2);
              tft.print(F("SMS para:"));
              tft.setTextColor(WHITE);
              tft.print(F("VIVO S.A."));
    
              tft.setCursor(10, 178);
              tft.setTextColor(CYAN);
              tft.print(F("Tel:"));
              tft.setTextColor(WHITE);
              tft.print(F(" 1058"));
    
              tft.setCursor(10, 198);
              tft.setTextColor(CYAN);
              tft.print(F("Mensagem: "));
              tft.setTextColor(WHITE);
              tft.print(F("Confirma Saldo!"));
    
              delay(2000);

              tft.fillRect(0, 280, 240, 38, RED);
              tft.setCursor(5, 282);
              tft.setTextColor(WHITE);
              tft.print(F(" Aguardando Saldo! "));
              tft.setCursor(25, 300);
              tft.print(F("  SMS Enviado!  "));
              delay(3000);
    
              msg_sms_env++;
    
              int pino53 = 53;
              pinMode(pino53, OUTPUT);
              delay(500);
              SD.begin(pino53);
              delay(500);
    
              myFile = SD.open("SMS.txt", FILE_WRITE);
              myFile.print(F("NANO SMART AGRO - Mensagem SMS Enviada"));
              myFile.print(F(";"));
              myFile.print(F(" Envio de mensagem SMS para Confirmar Saldo de Recarga Vivo!"));
              myFile.print(F(";"));
              myFile.print(F(" Tel: 1058"));
              myFile.print(F(";"));
              myFile.print(F(" SMS Enviados: "));
              myFile.print(msg_sms_env);
              myFile.print(F(";"));
              myFile.print(F(" DATA: "));
              myFile.print(t.date, DEC);
              myFile.print(F("/"));
              myFile.print(t.mon, DEC);
              myFile.print(F("/"));
              myFile.print(t.year, DEC);
              myFile.print(F(";"));
              myFile.print(F(" HORARIO: "));
              myFile.print(rtc.getTimeStr());
              myFile.print(F(";"));
              myFile.println();
              myFile.println();
              
              delay(1000);
              myFile.close();
              delay(1000);
              SD.end();

      
              // ========================================================================================================
              // Sincronizar os tempos para iniciar o loop novamente para não ter superposição de função

              anterior = millis();
              anterior2 = anterior;
              anterior3 = anterior2;
              anterior4 = anterior3;
              anterior5 = anterior4;
              anterior6 = anterior5;
              anterior7 = anterior6;
              anterior8 = anterior7;
              anterior9 = anterior8;
              anterior10 = anterior9;
              anterior11 = anterior10;
              anterior12 = anterior11;
              anterior13 = anterior12;
              anterior14 = anterior13;
              anterior15 = anterior14;
              anterior16 = anterior15;
              anterior17 = anterior16;
              anterior18 = anterior17;
              anterior19 = anterior18;
              anterior20 = anterior19;

              intervalo =  10000;
              intervalo2 = 20000;
              intervalo3 = 30000;
              intervalo4 = 40000;
              intervalo5 = 50000;
              intervalo6 = 60000;
              intervalo7 = 70000;
              intervalo8 = 80000;
              intervalo9 = 90000;
              intervalo10 = 100000;
              intervalo11 = 110000;
              intervalo12 = 120000;
              intervalo13 = 130000;
              intervalo14 = 140000;
              intervalo15 = 150000;
              intervalo16 = 160000;
              intervalo17 = 170000;
              intervalo18 = 180000;
              intervalo19 = 190000;
              intervalo20 = 200000;

              enviaSMS8("1058", "1");          // enviaSMS para a Vivo para confirmar o Saldo de Recarga

              display_menu = false;
              display_menu1 = false;
              cont1 = 0;

              delay(1000);
              leGSM();
              tft.setTextColor(CYAN, BLACK);
              tft.setTextSize(2);
              tft.setCursor(10, 238);
              tft.print(F("GSM: "));
              tft.setTextColor(WHITE);
              ultimoGSM.trim();            // Estrutura: >+CMGS: XXX OK
              tft.print(ultimoGSM);
              delay(1000);
              return;

            }

            // BOTÃO 5 - RETORNAR AO MENU INICIAL
            if (tp.x > 800 && tp.x < 880  && tp.y > 175 && tp.y < 260) {
    
              tft.setTextColor(YELLOW, BLACK);
              tft.setTextSize(2);
              tft.setCursor(0, 160);
              tft.println(F("5-RETORNA"));
              tft.fillRoundRect(195, 290, 30, 30, 5, RED);
              tft.drawRoundRect(195, 290, 30, 30, 5, YELLOW);
              tft.setTextColor(BLACK);
              tft.setCursor(204, 298);
              tft.println(F("X"));
              delay(2500);
    
              display_menu1 = false;
              display_menu = false;
              cont1 = 0;

              // ========================================================================================================
              // Sincronizar os tempos para iniciar o loop novamente para não ter superposição de função

              anterior = millis();
              anterior2 = anterior;
              anterior3 = anterior2;
              anterior4 = anterior3;
              anterior5 = anterior4;
              anterior6 = anterior5;
              anterior7 = anterior6;
              anterior8 = anterior7;
              anterior9 = anterior8;
              anterior10 = anterior9;
              anterior11 = anterior10;
              anterior12 = anterior11;
              anterior13 = anterior12;
              anterior14 = anterior13;
              anterior15 = anterior14;
              anterior16 = anterior15;
              anterior17 = anterior16;
              anterior18 = anterior17;
              anterior19 = anterior18;
              anterior20 = anterior19;

              intervalo =  10000;
              intervalo2 = 20000;
              intervalo3 = 30000;
              intervalo4 = 40000;
              intervalo5 = 50000;
              intervalo6 = 60000;
              intervalo7 = 70000;
              intervalo8 = 80000;
              intervalo9 = 90000;
              intervalo10 = 100000;
              intervalo11 = 110000;
              intervalo12 = 120000;
              intervalo13 = 130000;
              intervalo14 = 140000;
              intervalo15 = 150000;
              intervalo16 = 160000;
              intervalo17 = 170000;
              intervalo18 = 180000;
              intervalo19 = 190000;
              intervalo20 = 200000;
              return;

            } // FECHA IF DO BOTÃO 5 PARA RETORNO AO MENU INICIAL.

          } // FECHA WHILE DAS OPÇÕES DO BOTÃO ENVIA SMS

        } // FECHA IF DO BOTÃO 03 DO MENU PRINCIPAL 

        //========================================================================================================
        // EXIBE O MENU SELECIONADO QUANDO OCORRER O TOQUE NO BOTÃO 04:

        // BOTÃO 4 - RELATORIOS DE ENVIO AOS SEVERS IOT
        if (tp.x > 650 && tp.x < 730  && tp.y > 175 && tp.y < 260) {

          tft.setTextSize(2);
          tft.setCursor(0, 140);
          tft.setTextColor(YELLOW);
          tft.println(F("4-RELATORIOS"));
          tft.fillRoundRect(150, 290, 30, 30, 5, RED);
          tft.drawRoundRect(150, 290, 30, 30, 5, YELLOW);
          tft.setTextColor(BLACK);
          //tft.setTextSize(2);
          tft.setCursor(160, 298);
          tft.println(F("X"));
          delay(2000);

          d2();

          //========================================================================================================
          // Sincronizar os tempos para iniciar o loop novamente para não ter superposição de função

          anterior = millis();
          anterior2 = anterior;
          anterior3 = anterior2;
          anterior4 = anterior3;
          anterior5 = anterior4;
          anterior6 = anterior5;
          anterior7 = anterior6;
          anterior8 = anterior7;
          anterior9 = anterior8;
          anterior10 = anterior9;
          anterior11 = anterior10;
          anterior12 = anterior11;
          anterior13 = anterior12;
          anterior14 = anterior13;
          anterior15 = anterior14;
          anterior16 = anterior15;
          anterior17 = anterior16;
          anterior18 = anterior17;
          anterior19 = anterior18;
          anterior20 = anterior19;

          intervalo =  10000;
          intervalo2 = 20000;
          intervalo3 = 30000;
          intervalo4 = 40000;
          intervalo5 = 50000;
          intervalo6 = 60000;
          intervalo7 = 70000;
          intervalo8 = 80000;
          intervalo9 = 90000;
          intervalo10 = 100000;
          intervalo11 = 110000;
          intervalo12 = 120000;
          intervalo13 = 130000;
          intervalo14 = 140000;
          intervalo15 = 150000;
          intervalo16 = 160000;
          intervalo17 = 170000;
          intervalo18 = 180000;
          intervalo19 = 190000;
          intervalo20 = 200000;

          d3();
          display_menu = false;
          cont1 = 0;
          break;

        } // FECHA IF DO BOTÃO 4 SELECIONADO

        //========================================================================================================
        // EXIBE O MENU SELECIONADO QUANDO OCORRER O TOQUE NO BOTÃO 05:

        // BOTÃO 5 - PROXIMO MENU
        if (tp.x > 800 && tp.x < 880  && tp.y > 175 && tp.y < 260) {

          tft.setTextColor(YELLOW, BLACK);
          tft.setTextSize(2);
          tft.setCursor(0, 160);
          tft.println(F("5-PROXIMO MENU"));
          tft.fillRoundRect(195, 290, 30, 30, 5, RED);
          tft.drawRoundRect(195, 290, 30, 30, 5, YELLOW);
          tft.setTextColor(BLACK);
          //tft.setTextSize(2);
          tft.setCursor(204, 298);
          tft.println(F("X"));
          delay(2500);

          display_menu1 = true;
          tft.fillRect(0, 0, 240, 320, BLACK);

          tft.fillRoundRect(5, 15, 230, 50, 15, RED);
          tft.drawRoundRect(5, 15, 230, 50, 15, WHITE);
          tft.setTextColor(WHITE);
          tft.setTextSize(3);
          tft.setCursor(15, 30);
          tft.println(F("DISPLAY MENU"));

          tft.setTextColor(WHITE);
          tft.setTextSize(2);
          tft.setCursor(0, 80);
          tft.println(F("6-RESETE PLUVIOMETRO"));
          tft.setCursor(0, 100);
          tft.println(F("7-RESETE TOTALIZADOR"));
          tft.setCursor(0, 120);
          tft.println(F("8-RESETE MAX/MIN"));
          tft.setCursor(0, 140);
          tft.println(F("9-DATA E HORA"));
          tft.setCursor(0, 160);
          tft.println(F("10-SEND IoT SERVERS"));

          tft.fillRoundRect(5, 192, 230, 30, 5, RED);
          tft.drawRoundRect(5, 192, 230, 30, 5, WHITE);
          tft.setCursor(15, 200);
          tft.println(F(" NSAGRO V:4.01.34 "));

          tft.setCursor(0, 260);
          tft.print(F(" Selecione a opcao:"));
          tft.drawRoundRect(5, 282, 230, 30, 5, WHITE);

          // DESENHANDO OS BOTÕES DE APLICAÇÃO:
          tft.fillRoundRect(15, 290, 30, 30, 5, RED);
          tft.drawRoundRect(15, 290, 30, 30, 5, WHITE);
          tft.setTextColor(WHITE);
          tft.setTextSize(2);
          tft.setCursor(24, 298);
          tft.println(F("6"));

          // DESENHANDO OS BOTÕES DE APLICAÇÃO:
          tft.fillRoundRect(60, 290, 30, 30, 5, RED);
          tft.drawRoundRect(60, 290, 30, 30, 5, WHITE);
          tft.setTextColor(WHITE);
          tft.setCursor(69, 298);
          tft.println(F("7"));

          // DESENHANDO OS BOTÕES DE APLICAÇÃO:
          tft.fillRoundRect(105, 290, 30, 30, 5, RED);
          tft.drawRoundRect(105, 290, 30, 30, 5, WHITE);
          tft.setTextColor(WHITE);
          tft.setCursor(114, 298);
          tft.println(F("8"));

          // DESENHANDO OS BOTÕES DE APLICAÇÃO:
          tft.fillRoundRect(150, 290, 30, 30, 5, RED);
          tft.drawRoundRect(150, 290, 30, 30, 5, WHITE);
          tft.setTextColor(WHITE);
          tft.setCursor(159, 298);
          tft.println(F("9"));


          // DESENHANDO OS BOTÕES DE APLICAÇÃO:
          tft.fillRoundRect(195, 290, 30, 30, 5, RED);
          tft.drawRoundRect(195, 290, 30, 30, 5, WHITE);
          tft.setTextColor(WHITE);
          tft.setCursor(198, 298);
          tft.println(F("10"));

          aux_display_menu1 = millis();

          //========================================================================================================
          // EXIBE O PROXIMO MENU COM AS OPÇÕES DE 6 A 10 DOS BOTÕES NO DISPLAY:

          while (display_menu1) {

            // FUNÇÃO PARA RETORNAR AO LOOP PRINCIPAL SE O TEMPO FOR MAIOR QUE 10 SEG APÓS SELECIONADO O BOTÃO 5
            if (millis() - aux_display_menu1 > 10000) {
              display_menu1 = false;
              display_menu = false;

              // ========================================================================================================
              // Sincronizar os tempos para iniciar o loop novamente para não ter superposição de função

              anterior = millis();
              anterior2 = anterior;
              anterior3 = anterior2;
              anterior4 = anterior3;
              anterior5 = anterior4;
              anterior6 = anterior5;
              anterior7 = anterior6;
              anterior8 = anterior7;
              anterior9 = anterior8;
              anterior10 = anterior9;
              anterior11 = anterior10;
              anterior12 = anterior11;
              anterior13 = anterior12;
              anterior14 = anterior13;
              anterior15 = anterior14;
              anterior16 = anterior15;
              anterior17 = anterior16;
              anterior18 = anterior17;
              anterior19 = anterior18;
              anterior20 = anterior19;

              intervalo =  10000;
              intervalo2 = 20000;
              intervalo3 = 30000;
              intervalo4 = 40000;
              intervalo5 = 50000;
              intervalo6 = 60000;
              intervalo7 = 70000;
              intervalo8 = 80000;
              intervalo9 = 90000;
              intervalo10 = 100000;
              intervalo11 = 110000;
              intervalo12 = 120000;
              intervalo13 = 130000;
              intervalo14 = 140000;
              intervalo15 = 150000;
              intervalo16 = 160000;
              intervalo17 = 170000;
              intervalo18 = 180000;
              intervalo19 = 190000;
              intervalo20 = 200000;

              return;

            } // FECHA IF DA FUNÇÃO PARA RETORNAR AO LOOP PRINCIPAL SE O TEMPO FOR MAIOR QUE 10 SEG APÓS SELECIONADO O BOTÃO 5

            // VERIFICA SE HOUVE TOQUE NA TELA E ARMEZA O PONTO SELECIONADO
            tp = ts.getPoint();
            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            // BOTÃO 6 - RESETE DO PLUVIOMETRO:
            if (tp.x > 225 && tp.x < 300  && tp.y > 175 && tp.y < 260) {

              tft.setTextColor(YELLOW, BLACK);
              tft.setTextSize(2);
              tft.setCursor(0, 80);
              tft.println(F("6-RESETE PLUVIOMETRO"));
              tft.fillRoundRect(15, 290, 30, 30, 5, RED);
              tft.drawRoundRect(15, 290, 30, 30, 5, YELLOW);
              tft.setTextColor(BLACK);
              //tft.setTextSize(2);
              tft.setCursor(25, 298);
              tft.println(F("X"));
              delay(2500);

              tft.fillRect(0, 0, 240, 320, BLACK);
              lcdpluv();

              // ========================================================================================================
              // VARIAVEIS DO PLUVIOMETRO QUE SERÃO RESETADAS:

              contaPulso1 = 0;   // RESETA PULSOS DO PLUVIÔMETRO
              Read_Pulso1 = 0;   // RESETA PULSOS DO PLUVIÔMETRO
              Read_Pulso1Antigo = 0;   // RESETA PULSOS DO PLUVIÔMETRO
              pluviometro = 0;
              pluviometro_acum = 0;
              sms_pluviometro = true;
  
              // ========================================================================================================
              // CÁLCULO DO VALOR GERADO PELO PLUVIÔMETRO:

              pluviometro = contaPulso1 * 0.25;                  // Variável para exibir a quantidade de chuva totalizada no dia;

              delay(2500);
              tft.fillRect(0, 0, 240, 320, BLACK);
              lcdpluv();

              display_menu = false;
              cont1 = 0;

              // ========================================================================================================
              // Sincronizar os tempos para iniciar o loop novamente para não ter superposição de função

              anterior = millis();
              anterior2 = anterior;
              anterior3 = anterior2;
              anterior4 = anterior3;
              anterior5 = anterior4;
              anterior6 = anterior5;
              anterior7 = anterior6;
              anterior8 = anterior7;
              anterior9 = anterior8;
              anterior10 = anterior9;
              anterior11 = anterior10;
              anterior12 = anterior11;
              anterior13 = anterior12;
              anterior14 = anterior13;
              anterior15 = anterior14;
              anterior16 = anterior15;
              anterior17 = anterior16;
              anterior18 = anterior17;
              anterior19 = anterior18;
              anterior20 = anterior19;

              intervalo =  10000;
              intervalo2 = 20000;
              intervalo3 = 30000;
              intervalo4 = 40000;
              intervalo5 = 50000;
              intervalo6 = 60000;
              intervalo7 = 70000;
              intervalo8 = 80000;
              intervalo9 = 90000;
              intervalo10 = 100000;
              intervalo11 = 110000;
              intervalo12 = 120000;
              intervalo13 = 130000;
              intervalo14 = 140000;
              intervalo15 = 150000;
              intervalo16 = 160000;
              intervalo17 = 170000;
              intervalo18 = 180000;
              intervalo19 = 190000;
              intervalo20 = 200000;
              return;

            } // FECHA IF DO BOTÃO 6 SELECIONADO

            //========================================================================================================
            // EXIBE O MENU SELECIONADO QUANDO OCORRER O TOQUE NO BOTÃO 07:

            // BOTÃO 7 - RESETE DO TOTALIZADOR DE VAZÃO:
            if (tp.x > 370 && tp.x < 445  && tp.y > 175 && tp.y < 260) {
              tft.setTextColor(YELLOW, BLACK);
              tft.setTextSize(2);
              tft.setCursor(0, 100);
              tft.println(F("7-RESETE TOTALIZADOR"));
              tft.fillRoundRect(60, 290, 30, 30, 5, RED);
              tft.drawRoundRect(60, 290, 30, 30, 5, YELLOW);
              tft.setTextColor(BLACK);
              tft.setCursor(70, 298);
              tft.println(F("X"));
              delay(2500);
              tft.fillRect(0, 0, 240, 320, BLACK);
              lcd_vazao();

              // ========================================================================================================
              // VARIAVEIS DO TOTALIZADOR DE VAZÃO QUE SERÃO RESETADAS:

              contaPulso_vazao = 0;     //Variável para a quantidade de pulsos++; //Incrementa a variável de pulsos
              contaPulsotot = 0;        //Variável para a quantidade de pulsos++; //Incrementa a variável de pulsos
              vazao = 0.00;
              Litros = 0.00;

              delay(2500);
              tft.fillRect(0, 0, 240, 320, BLACK);
              lcd_vazao();

              display_menu = false;
              cont1 = 0;

              // ========================================================================================================
              // Sincronizar os tempos para iniciar o loop novamente para não ter superposição de função

              anterior = millis();
              anterior2 = anterior;
              anterior3 = anterior2;
              anterior4 = anterior3;
              anterior5 = anterior4;
              anterior6 = anterior5;
              anterior7 = anterior6;
              anterior8 = anterior7;
              anterior9 = anterior8;
              anterior10 = anterior9;
              anterior11 = anterior10;
              anterior12 = anterior11;
              anterior13 = anterior12;
              anterior14 = anterior13;
              anterior15 = anterior14;
              anterior16 = anterior15;
              anterior17 = anterior16;
              anterior18 = anterior17;
              anterior19 = anterior18;
              anterior20 = anterior19;

              intervalo =  10000;
              intervalo2 = 20000;
              intervalo3 = 30000;
              intervalo4 = 40000;
              intervalo5 = 50000;
              intervalo6 = 60000;
              intervalo7 = 70000;
              intervalo8 = 80000;
              intervalo9 = 90000;
              intervalo10 = 100000;
              intervalo11 = 110000;
              intervalo12 = 120000;
              intervalo13 = 130000;
              intervalo14 = 140000;
              intervalo15 = 150000;
              intervalo16 = 160000;
              intervalo17 = 170000;
              intervalo18 = 180000;
              intervalo19 = 190000;
              intervalo20 = 200000;
              return;

            } // FECHA IF DO BOTÃO 7 SELECIONADO

            //========================================================================================================
            // EXIBE O MENU SELECIONADO QUANDO OCORRER O TOQUE NO BOTÃO 08:

            // BOTÃO 8 - QUE IRÁ RESETAR OS VALORES MÁXIMOS E MÍNIMOS DOS SENSORES
            if (tp.x > 484  && tp.x < 574  && tp.y > 175 && tp.y < 260) {
              tft.setTextColor(YELLOW, BLACK);
              tft.setTextSize(2);
              tft.setCursor(0, 120);
              tft.println(F("8-RESETE MAX/MIN"));
              tft.fillRoundRect(105, 290, 30, 30, 5, RED);
              tft.drawRoundRect(105, 290, 30, 30, 5, YELLOW);
              tft.setTextColor(BLACK);
              tft.setCursor(115, 298);
              tft.println(F("X"));
              delay(2000);

              // ========================================================================================================
              // VARIAVEIS DE REGISTRO DE VALORES MÁXIMOS E MÍNIMOS QUE SERÃO RESETADAS:

              d4();
              //delay(5000);
              display_menu = false;
              cont1 = 0;

              // ========================================================================================================
              // Sincronizar os tempos para iniciar o loop novamente para não ter superposição de função

              anterior = millis();
              anterior2 = anterior;
              anterior3 = anterior2;
              anterior4 = anterior3;
              anterior5 = anterior4;
              anterior6 = anterior5;
              anterior7 = anterior6;
              anterior8 = anterior7;
              anterior9 = anterior8;
              anterior10 = anterior9;
              anterior11 = anterior10;
              anterior12 = anterior11;
              anterior13 = anterior12;
              anterior14 = anterior13;
              anterior15 = anterior14;
              anterior16 = anterior15;
              anterior17 = anterior16;
              anterior18 = anterior17;
              anterior19 = anterior18;
              anterior20 = anterior19;

              intervalo =  10000;
              intervalo2 = 20000;
              intervalo3 = 30000;
              intervalo4 = 40000;
              intervalo5 = 50000;
              intervalo6 = 60000;
              intervalo7 = 70000;
              intervalo8 = 80000;
              intervalo9 = 90000;
              intervalo10 = 100000;
              intervalo11 = 110000;
              intervalo12 = 120000;
              intervalo13 = 130000;
              intervalo14 = 140000;
              intervalo15 = 150000;
              intervalo16 = 160000;
              intervalo17 = 170000;
              intervalo18 = 180000;
              intervalo19 = 190000;
              intervalo20 = 200000;
              return;

            } // FECHA IF DO BOTÃO 8 SELECIONADO

            //========================================================================================================
            // EXIBE O MENU SELECIONADO QUANDO OCORRER O TOQUE NO BOTÃO 09:

            // BOTÃO 9 - EXIBIÇÃO DA DATA E HORA
            if (tp.x > 650 && tp.x < 730  && tp.y > 175 && tp.y < 260) {
              tft.setTextColor(YELLOW, BLACK);
              tft.setTextSize(2);
              tft.setCursor(0, 140);
              tft.println(F("9-DATA E HORA"));
              tft.fillRoundRect(150, 290, 30, 30, 5, RED);
              tft.drawRoundRect(150, 290, 30, 30, 5, YELLOW);
              tft.setTextColor(BLACK);
              tft.setCursor(160, 298);
              tft.println(F("X"));
              delay(2500);
              tft.fillRect(0, 0, 240, 320, BLACK);

              // ========================================================================================================
              // Sincronizar os tempos para iniciar o loop novamente para não ter superposição de função

              anterior = millis();
              anterior2 = anterior;
              anterior3 = anterior2;
              anterior4 = anterior3;
              anterior5 = anterior4;
              anterior6 = anterior5;
              anterior7 = anterior6;
              anterior8 = anterior7;
              anterior9 = anterior8;
              anterior10 = anterior9;
              anterior11 = anterior10;
              anterior12 = anterior11;
              anterior13 = anterior12;
              anterior14 = anterior13;
              anterior15 = anterior14;
              anterior16 = anterior15;
              anterior17 = anterior16;
              anterior18 = anterior17;
              anterior19 = anterior18;
              anterior20 = anterior19;

              intervalo =  10000;
              intervalo2 = 20000;
              intervalo3 = 30000;
              intervalo4 = 40000;
              intervalo5 = 50000;
              intervalo6 = 60000;
              intervalo7 = 70000;
              intervalo8 = 80000;
              intervalo9 = 90000;
              intervalo10 = 100000;
              intervalo11 = 110000;
              intervalo12 = 120000;
              intervalo13 = 130000;
              intervalo14 = 140000;
              intervalo15 = 150000;
              intervalo16 = 160000;
              intervalo17 = 170000;
              intervalo18 = 180000;
              intervalo19 = 190000;
              intervalo20 = 200000;

              //========================================================================================================
              // INICIANDO O MENU DO NSAGRO:
              
              data_hora();
              display_menu = false;
              cont1 = 0;

              return;

            } // FECHA IF DO BOTÃO 9 SELECIONADO

            //========================================================================================================
            // EXIBE O MENU SELECIONADO QUANDO OCORRER O TOQUE NO BOTÃO 10:

            // BOTÃO 10 - ENVIO DE VALORES AOS SERVERS IOT:
            if (tp.x > 800 && tp.x < 880  && tp.y > 175 && tp.y < 260) {
              tft.setTextColor(YELLOW, BLACK);
              tft.setTextSize(2);
              tft.setCursor(0, 160);
              tft.println(F("10-SEND IoT SERVERS"));
              tft.fillRoundRect(195, 290, 30, 30, 5, RED);
              tft.drawRoundRect(195, 290, 30, 30, 5, YELLOW);
              tft.setTextColor(BLACK);
              tft.setCursor(205, 298);
              tft.println(F("X"));
              delay(2500);

              anterior30 = millis();

              digitalWrite(LED_BUILTIN, false);   // Seta o LED DA PLACA ARDUINO
              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
              delay(250);

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(250);

              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
              delay(250);

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(250);

              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES

              tft.fillRect(0, 0, 240, 320, BLACK);
              iot_ubidots();                      // server iot ubidots

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES


              tft.fillRect(0, 0, 240, 320, BLACK);
              iot_ubidots1();                     // server iot ubidots

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, true);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);

              tft.fillRect(0, 0, 240, 320, BLACK);
              iot_thingspeak();

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES

              tft.fillRect(0, 0, 240, 320, BLACK);
              iot_thingspeak1();

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);
              
              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES

              tft.fillRect(0, 0, 240, 320, BLACK);
              iot_thingspeak2();

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
              delay(200);
              
              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES

              d2();

              d3();

              tft.fillRect(0, 0, 240, 320, BLACK);
              configuraGSM();

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
              delay(200);

              digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
              delay(5000);


              // ========================================================================================================
              // Sincronizar os tempos para iniciar o loop novamente para não ter superposição de função

              anterior = millis();
              anterior2 = anterior;
              anterior3 = anterior2;
              anterior4 = anterior3;
              anterior5 = anterior4;
              anterior6 = anterior5;
              anterior7 = anterior6;
              anterior8 = anterior7;
              anterior9 = anterior8;
              anterior10 = anterior9;
              anterior11 = anterior10;
              anterior12 = anterior11;
              anterior13 = anterior12;
              anterior14 = anterior13;
              anterior15 = anterior14;
              anterior16 = anterior15;
              anterior17 = anterior16;
              anterior18 = anterior17;
              anterior19 = anterior18;
              anterior20 = anterior19;

              intervalo =  10000;
              intervalo2 = 20000;
              intervalo3 = 30000;
              intervalo4 = 40000;
              intervalo5 = 50000;
              intervalo6 = 60000;
              intervalo7 = 70000;
              intervalo8 = 80000;
              intervalo9 = 90000;
              intervalo10 = 100000;
              intervalo11 = 110000;
              intervalo12 = 120000;
              intervalo13 = 130000;
              intervalo14 = 140000;
              intervalo15 = 150000;
              intervalo16 = 160000;
              intervalo17 = 170000;
              intervalo18 = 180000;
              intervalo19 = 190000;
              intervalo20 = 200000;

              display_menu = false;
              delay(5000);
              cont1 = 0;
              break;

            } // FECHA IF DO BOTÃO 10 SELECIONADO
          } // FECHA WHILE DO PROXIMO MENU DO DISPLAY
        } // FECHA IF QUANDO FOR SELECIONADO O BOTÃO 5

        cont1 = 0; // RESETA VARIAVEL AUXILIAR DO TOQUE DE TELA

      } // FECHA IF QUANDO HOUVER O SEGUNDO TOQUE NA TELA DO DISPLAY
    } // FECHA WHILE DO TEMPO DE ESPERA DO MENU DISPLAY POR 10 SEGUNDOS SE NÃO HOUVER TOQUE NA TELA, IRÁ RETORNAR AO LOOP PRINCIPAL
  } // FECHA WHILE QUANDO HOUVE TOQUE NA TELA, EXIBUÇÃO DO MENU PRINCIPAL (DISPLAY_MENU == TRUE)

  serialGSM.begin(9600);
  //Serial.begin(9600);

  unsigned long atual = millis();
  unsigned long atual2 = atual;
  unsigned long atual3 = atual2;
  unsigned long atual4 = atual3;
  unsigned long atual5 = atual4;
  unsigned long atual6 = atual5;
  unsigned long atual7 = atual6;
  unsigned long atual8 = atual7;
  unsigned long atual9 = atual8;
  unsigned long atual10 = atual9;
  unsigned long atual11 = atual10;
  unsigned long atual12 = atual11;
  unsigned long atual13 = atual12;
  unsigned long atual14 = atual13;
  unsigned long atual15 = atual14;
  unsigned long atual16 = atual15;
  unsigned long atual17 = atual16;
  unsigned long atual18 = atual17;
  unsigned long atual19 = atual18;
  unsigned long atual20 = atual19;

  //========================================================================================================
  // EXIBE NO DISPLAY TFT A BARRA DE INICIALIZAÇÃO DAS VARIAVEIS:

  // ESSA INSTRUÇÃO SÓ É EXECUTADA 1 VEZ, POIS MILLIS SERA MAIOR QUE 5000 E A SOMATORIA DOS DELAYS É IGUAL A 5500MSEGUNDOS.
  if (millis() - lcd_init < 5000) {

    tft.fillRect(0, 305, 20, 6, YELLOW);
    digitalWrite(BUZZER_VCC, true);         // Reseta o BUZZER
    delay(250);
    tft.fillRect(0, 305, 40, 6, YELLOW);
    digitalWrite(BUZZER_VCC, false);         // Seta o BUZZER
    delay(250);

    tft.fillRect(0, 305, 60, 6, YELLOW);
    digitalWrite(BUZZER_VCC, true);        // Reseta o BUZZER
    delay(250);

    tft.fillRect(0, 305, 80, 6, YELLOW);
    digitalWrite(BUZZER_VCC, false);        // Seta o BUZZER
    delay(250);

    tft.fillRect(0, 305, 100, 6, YELLOW);
    digitalWrite(BUZZER_VCC, true);         // Reseta o BUZZER
    delay(250);

    tft.fillRect(0, 305, 120, 6, YELLOW);
    digitalWrite(BUZZER_VCC, false);        // Seta o BUZZER

    tft.fillRect(0, 305, 135, 6, YELLOW);
    delay(750);

    tft.fillRect(0, 305, 150, 6, YELLOW);
    delay(1000);

    tft.fillRect(0, 305, 165, 6, YELLOW);
    delay(1000);

    tft.fillRect(0, 305, 180, 6, YELLOW);
    delay(1000);

    tft.fillRect(0, 305, 195, 6, YELLOW);
    delay(1000);

    tft.fillRect(0, 305, 210, 6, YELLOW);
    delay(1000);

    tft.fillRect(0, 305, 225, 6, YELLOW);
    delay(1000);

    tft.fillRect(0, 305, 240, 6, YELLOW);
    delay(1000);
  }

  // ========================================================================================================
  // Aciona BUZZER quando houver um pulso no pluviometro!!

  aux_estado_buzzer = estado_buzzer;

  if (aux_estado_buzzer == true) {
    digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
    delay(1000);
    digitalWrite(BUZZER_VCC, false);        // Reseta o BUZZER
    estado_buzzer = false;
  }

  //========================================================================================================
  // Contadores de Falha na gravação no Sd Card:  Solicita RESETE do Arduino

  if (msg_sdcard_nok >= 50) {
    delay(1000);
    modemGSM.restart();
    delay(5000);
    funcReset();
  }

  //========================================================================================================
  // Contadores de Falha no Envio dos Dados aos Server IOT:  Solicita RESETE do Arduino

  if ( (configuraGSM_nok_resete >= 25) || (msg_counternok_t_resete >= 25) || (msg_counternok_t1_resete >= 25) || (msg_counternok_t2_resete >= 25) || (msg_counternok_resete >= 25) || (msg_counternok1_resete >= 25)) {

    tft.fillRoundRect(0, 0, 240, 95, 15, RED);
    tft.drawRoundRect(0, 0, 240, 95, 15, WHITE);
    tft.setCursor(23, 10);
    tft.setTextColor(WHITE);
    tft.setTextSize(3);
    tft.print(F("VERIFICANDO"));

    tft.setCursor(52, 37);
    tft.print(F("ENVIO DE"));

    tft.setCursor(14, 64);
    tft.print(F("MENSAGEM SMS"));

    tft.fillRoundRect(10, 110, 220, 30, 15, YELLOW);
    tft.drawRoundRect(10, 110, 220, 30, 15, RED);
    tft.setCursor(30, 114);
    tft.setTextColor(RED);
    tft.print(F("ENVIAR SMS!"));

    enviaSMS2("+5515999999999", "IoT NANO SMART AGRO \nSMS Confirmacao de Falha nos Servers IoT!!");          // enviaSMS(telefoneSMS, o resumo de funcionamento do protótipo!

    delay(3000);
    tft.fillRect(0, 280, 240, 38, RED);
    tft.setCursor(5, 282);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F(" Resete Necessario "));
    tft.setCursor(25, 300);
    tft.print(F("  SMS Enviado!  "));

    msg_sms_env++;

    int pino53 = 53;
    pinMode(pino53, OUTPUT);

    delay(500);
    SD.begin(pino53);
    delay(500);

    myFile = SD.open("SMS.txt", FILE_WRITE);
    myFile.print(F("NANO SMART AGRO - Mensagem SMS Enviada"));
    myFile.print(F(";"));
    myFile.print(F(" Falha no Envio dos Dados aos Servers IoT"));
    myFile.print(F(";"));
    myFile.print(F(" Solicitação de RESETE do Arduino"));
    myFile.print(F(";"));
    myFile.print(F(" Cel:"));
    myFile.print("+5515999999999");
    myFile.print(F(";"));
    myFile.print(F(" SMS Enviados: "));
    myFile.print(msg_sms_env);
    myFile.print(F(";"));
    myFile.print(F(" DATA: "));
    myFile.print(t.date, DEC);
    myFile.print(F("/"));
    myFile.print(t.mon, DEC);
    myFile.print(F("/"));
    myFile.print(t.year, DEC);
    myFile.print(F(";"));
    myFile.print(F(" HORARIO: "));
    myFile.print(rtc.getTimeStr());
    myFile.print(F(";"));
    myFile.println();
    myFile.println();
    delay(1000);
    myFile.close();
    delay(1000);

    SD.end();
    modemGSM.restart();
    delay(5000);
    funcReset();

  } // FECHA IF DA DE VERIFICAÇÃO DA QUANTIDADE DE FALHA DE ENVIO AOS SERVER IOT


  //========================================================================================================
  // Inverte o Estado do LED A CADA 1 SEGUNDO:

  //Verifica se o intervalo do Led Vermelho já foi atingido
  if (millis() - TempoLED >= IntervalolLED) {
    TempoLED = millis();
    estadoLED = !estadoLED;                 // Inverte o Estado do LED
    digitalWrite(LED_BUILTIN, estadoLED);   // Seta o LED DA PLACA ARDUINO
    digitalWrite(LED, estadoLED);           // Seta o LED DA PLACA DOS SENSORES
  }

  //========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL PRECIPTAÇÃO DE ORVALHO EM %:

  for (int i = 0; i <= 100; i++) {
    chuva_analog = analogRead(chuvaPIN);
    valor5 = valor5 + chuva_analog;
  }

  preciptacao1 = valor5 / 100;

  preciptacao = ((preciptacao1 - minimo2) / (maximo2 - minimo2)) * 100;
  preciptacao = (preciptacao - 100) * -1;
  valor5 = 0;
  preciptacao1 = 0;

  if (preciptacao < cpmin) {
    cpmin = preciptacao;
  }
  if (preciptacao > cpmax) {
    cpmax = preciptacao;
  }

  // ========================================================================================================
  // CÁLCULO DO VALOR GERADO PELO PLUVIÔMETRO:

  if (preciptacao >= 5.00) {

    pluviometro = contaPulso1 * 0.25;                  // Variável para exibir a quantidade de chuva totalizada no dia;
    Read_Pulso1Antigo = Read_Pulso1;                   // Variável para guardar o valor do pulso anterior.
    pluviometro_acum += pluviometro;
    
  } else {
    
    Read_Pulso1 = Read_Pulso1Antigo;        // caso haja pulsos, mas o senssor de chuva não marcar acima de 5%, o pulso será o mesmo do anterior.
    contaPulso1 = Read_Pulso1;              // Variável para a quantidade de pulsos a cada "tombo do medidor"
    
  }

  //========================================================================================================
  // LOOP DE VISUALIZAÇÃO DE ALTERNANCIA A CADA 10SEGUNDOS DAS VARIAVEIS EXIBIDAS NO DISPLAY TFT:

  // FUNÇÃO PARA EXIBIÇÃO DA TEMPERATURA AMBIENTE NO DISPLAY TFT:
  if ( atual - anterior > intervalo) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    //Calcula_nivel_UV();
    lcd_temp_amb();

    intervalo = atual;
    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  } // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DA TEMPERATURA AMBIENTE NO DISPLAY TFT:


  // FUNÇÃO PARA EXIBIÇÃO DA UMIDADE AMBIENTE NO DISPLAY TFT
  if ( atual2 - anterior2 > intervalo2) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    lcd_umid_amb();
    //volume_cx();

    intervalo = atual;
    intervalo2 = atual2;
    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  } // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DA UMIDADE AMBIENTE NO DISPLAY TFT


  // FUNÇÃO PARA EXIBIÇÃO DO DEW POINT NO DISPLAY TFT
  if ( atual3 - anterior3 > intervalo3) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    lcd_dewpoint();

    intervalo = atual;
    intervalo2 = atual2;
    intervalo3 = atual3;
    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  } // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DO DEW POINT NO DISPLAY TFT


  // FUNÇÃO PARA EXIBIÇÃO DA TEMPERATURA INTERNA NO DISPLAY TFT
  if ( atual4 - anterior4 > intervalo4) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    lcd_temp_amb_int();

    intervalo = atual;
    intervalo2 = atual2;
    intervalo3 = atual3;
    intervalo4 = atual4;
    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  } // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DA TEMPERATURA INTERNA NO DISPLAY TFT


  // FUNÇÃO PARA EXIBIÇÃO DA TEMPERATURA DO SOLO NO DISPLAY TFT
  if ( atual5 - anterior5 > intervalo5) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    lcd_temp_solo();

    intervalo = atual;
    intervalo2 = atual2;
    intervalo3 = atual3;
    intervalo4 = atual4;
    intervalo5 = atual5;
    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  } // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DA TEMPERATURA DO SOLO NO DISPLAY TFT

  // FUNÇÃO PARA EXIBIÇÃO DA UMIDADE DO SOLO DO PONTO P1 NO DISPLAY TFT
  if ( atual6 - anterior6 > intervalo6) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    umid_soloP1();

    intervalo = atual;
    intervalo2 = atual2;
    intervalo3 = atual3;
    intervalo4 = atual4;
    intervalo5 = atual5;
    intervalo6 = atual6;
    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  } // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DA UMIDADE DO SOLO NO PONTO P1 NO DISPLAY TFT


  // FUNÇÃO PARA EXIBIÇÃO DA UMIDADE DO SOLO DO PONTO P2 NO DISPLAY TFT
  if ( atual7 - anterior7 > intervalo7) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    umid_soloP2();

    intervalo = atual;
    intervalo2 = atual2;
    intervalo3 = atual3;
    intervalo4 = atual4;
    intervalo5 = atual5;
    intervalo6 = atual6;
    intervalo7 = atual7;
    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  } // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DA UMIDADE DO SOLO NO PONTO P1 NO DISPLAY TFT


  // FUNÇÃO PARA EXIBIÇÃO DA ALTITUDE APROXIMADA NO DISPLAY TFT
  if ( atual8 - anterior8 > intervalo8) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    lcd_alt_atm();

    intervalo = atual;
    intervalo2 = atual2;
    intervalo3 = atual3;
    intervalo4 = atual4;
    intervalo5 = atual5;
    intervalo6 = atual6;
    intervalo7 = atual7;
    intervalo8 = atual8;
    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  } // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DA ALTITUDE APROXIMADA NO DISPLAY TFT


  // FUNÇÃO PARA EXIBIÇÃO DA PRESSÃO ATMOSFÉRICA NO DISPLAY TFT
  if ( atual9 - anterior9 > intervalo9) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    lcd_pressao_atm();

    intervalo = atual;
    intervalo2 = atual2;
    intervalo3 = atual3;
    intervalo4 = atual4;
    intervalo5 = atual5;
    intervalo6 = atual6;
    intervalo7 = atual7;
    intervalo8 = atual8;
    intervalo9 = atual9;
    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  } // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DA PRESSÃO ATMOSFÉRICA NO DISPLAY TFT


  // FUNÇÃO PARA EXIBIÇÃO DA PRESENÇA DE ORVALHO E OU PRECIPTAÇÃO NO DISPLAY TFT
  if ( atual10 - anterior10 > intervalo10) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    lcd_preciptacao();

    intervalo = atual;
    intervalo2 = atual2;
    intervalo3 = atual3;
    intervalo4 = atual4;
    intervalo5 = atual5;
    intervalo6 = atual6;
    intervalo7 = atual7;
    intervalo8 = atual8;
    intervalo9 = atual9;
    intervalo10 = atual10;
    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  } // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DA PRESENÇA DE ORVALHO E OU PRECIPTAÇÃO NO DISPLAY TFT


  // FUNÇÃO PARA EXIBIÇÃO DO VALOR DO PLUVIÔMETRO NO DISPLAY TFT
  if ( atual11 - anterior11 > intervalo11) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    lcdpluv();


    intervalo = atual;
    intervalo2 = atual2;
    intervalo3 = atual3;
    intervalo4 = atual4;
    intervalo5 = atual5;
    intervalo6 = atual6;
    intervalo7 = atual7;
    intervalo8 = atual8;
    intervalo9 = atual9;
    intervalo10 = atual10;
    intervalo11 = atual11;
    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  }  // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DO VALOR DO PLUVIÔMETRO NO DISPLAY TFT


  // FUNÇÃO PARA EXIBIÇÃO DO VALOR DO NÍVEL DOS RESERVATÓRIOS NO DISPLAY TFT
  if ( atual12 - anterior12 > intervalo12) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    nivel_cx();

    intervalo = atual;
    intervalo2 = atual2;
    intervalo3 = atual3;
    intervalo4 = atual4;
    intervalo5 = atual5;
    intervalo6 = atual6;
    intervalo7 = atual7;
    intervalo8 = atual8;
    intervalo9 = atual9;
    intervalo10 = atual10;
    intervalo11 = atual11;
    intervalo12 = atual12;
    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  } // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DO VALOR DO NÍVEL DOS RESERVATÓRIOS NO DISPLAY TFT


  // FUNÇÃO PARA EXIBIÇÃO DO VALOR DO VOLUME DOS RESERVATÓRIOS NO DISPLAY TFT
  if ( atual13 - anterior13 > intervalo13) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    volume_cx();

    intervalo = atual;
    intervalo2 = atual2;
    intervalo3 = atual3;
    intervalo4 = atual4;
    intervalo5 = atual5;
    intervalo6 = atual6;
    intervalo7 = atual7;
    intervalo8 = atual8;
    intervalo9 = atual9;
    intervalo10 = atual10;
    intervalo11 = atual11;
    intervalo12 = atual12;
    intervalo13 = atual13;
    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  }  // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DO VALOR DO NÍVEL DOS RESERVATÓRIOS NO DISPLAY TFT


  // FUNÇÃO PARA EXIBIÇÃO DO VALOR DA VAZÃO DE SAÍDA NO DISPLAY TFT
  if ( atual14 - anterior14 > intervalo14) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    //detachInterrupt(digitalPinToInterrupt(Pino));

    lcd_vazao();

    intervalo = atual;
    intervalo2 = atual2;
    intervalo3 = atual3;
    intervalo4 = atual4;
    intervalo5 = atual5;
    intervalo6 = atual6;
    intervalo7 = atual7;
    intervalo8 = atual8;
    intervalo9 = atual9;
    intervalo10 = atual10;
    intervalo11 = atual11;
    intervalo12 = atual12;
    intervalo13 = atual13;
    intervalo14 = atual14;
    //attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  }  // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DO VALOR DA VAZÃO DE SAÍDA NO DISPLAY TFT


  // FUNÇÃO PARA EXIBIÇÃO DO VALOR DA LUMINOSIDADE AMBIENTE NO DISPLAY TFT
  if ( atual5 - anterior15 > intervalo15) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    lcd_lum_amb();

    intervalo = atual;
    intervalo2 = atual2;
    intervalo3 = atual3;
    intervalo4 = atual4;
    intervalo5 = atual5;
    intervalo6 = atual6;
    intervalo7 = atual7;
    intervalo8 = atual8;
    intervalo9 = atual9;
    intervalo10 = atual10;
    intervalo11 = atual11;
    intervalo12 = atual12;
    intervalo13 = atual13;
    intervalo14 = atual14;
    intervalo15 = atual15;
    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  } // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DO VALOR DA LUMINOSIDADE AMBIENTE NO DISPLAY TFT


  // FUNÇÃO PARA EXIBIÇÃO DO ÍNDICE UV NO DISPLAY TFT
  if ( atual16 - anterior16 > intervalo16) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    Calcula_nivel_UV();

    intervalo = atual;
    intervalo2 = atual2;
    intervalo3 = atual3;
    intervalo4 = atual4;
    intervalo5 = atual5;
    intervalo6 = atual6;
    intervalo7 = atual7;
    intervalo8 = atual8;
    intervalo9 = atual9;
    intervalo10 = atual10;
    intervalo11 = atual11;
    intervalo12 = atual12;
    intervalo13 = atual13;
    intervalo14 = atual14;
    intervalo15 = atual15;
    intervalo16 = atual16;

    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  } // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DO VALOR DO ÍNDICE UV NO DISPLAY TFT


  // FUNÇÃO PARA EXIBIÇÃO DA GRAVAÇÃO DE DADOS NO SD CARD NO DISPLAY TFT
  if ( atual17 - anterior17 > intervalo17) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    gravadadosSd();       // salva dados no sd card

    intervalo = atual;
    intervalo2 = atual2;
    intervalo3 = atual3;
    intervalo4 = atual4;
    intervalo5 = atual5;
    intervalo6 = atual6;
    intervalo7 = atual7;
    intervalo8 = atual8;
    intervalo9 = atual9;
    intervalo10 = atual10;
    intervalo11 = atual11;
    intervalo12 = atual12;
    intervalo13 = atual13;
    intervalo14 = atual14;
    intervalo15 = atual15;
    intervalo16 = atual16;
    intervalo17 = atual17;

    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  } // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DA GRAVAÇÃO DE DADOS NO SD CARD NO DISPLAY TFT


  // FUNÇÃO PARA EXIBIÇÃO DO DIAGNÓSTICO DE FUNCIONAMNETO NO DISPLAY TFT
  if ( atual18 - anterior18 > intervalo18) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    d1();

    intervalo = atual;
    intervalo2 = atual2;
    intervalo3 = atual3;
    intervalo4 = atual4;
    intervalo5 = atual5;
    intervalo6 = atual6;
    intervalo7 = atual7;
    intervalo8 = atual8;
    intervalo9 = atual9;
    intervalo10 = atual10;
    intervalo11 = atual11;
    intervalo12 = atual12;
    intervalo13 = atual13;
    intervalo14 = atual14;
    intervalo15 = atual15;
    intervalo16 = atual16;
    intervalo17 = atual17;
    intervalo18 = atual18;

    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  } // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DO DIAGNÓSTICO DE FUNCIONAMNETO NO DISPLAY TFT


  // FUNÇÃO PARA EXIBIÇÃO DO RELATÓRIO DE FUNCIONAMNETO DE ENVIO AO UBIDOTS NO DISPLAY TFT
  if ( atual19 - anterior19 > intervalo19) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    d2();

    intervalo = atual;
    intervalo2 = atual2;
    intervalo3 = atual3;
    intervalo4 = atual4;
    intervalo5 = atual5;
    intervalo6 = atual6;
    intervalo7 = atual7;
    intervalo8 = atual8;
    intervalo9 = atual9;
    intervalo10 = atual10;
    intervalo11 = atual11;
    intervalo12 = atual12;
    intervalo13 = atual13;
    intervalo14 = atual14;
    intervalo15 = atual15;
    intervalo16 = atual16;
    intervalo17 = atual17;
    intervalo18 = atual18;
    intervalo19 = atual19;

    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  } // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DO RELATÓRIO DE FUNCIONAMNETO DE ENVIO AO UBIDOTS NO DISPLAY TFT


  // FUNÇÃO PARA EXIBIÇÃO DO RELATÓRIO DE FUNCIONAMNETO DE ENVIO AO THINGSPEAK NO DISPLAY TFT
  if ( atual20 - anterior20 > intervalo20) {
    tft.fillRect(0, 0, 240, 320, BLACK);
    detachInterrupt(digitalPinToInterrupt(Pino));

    d3();

    anterior = atual;
    anterior2 = atual2;
    anterior3 = atual3;
    anterior4 = atual4;
    anterior5 = atual5;
    anterior6 = atual6;
    anterior7 = atual7;
    anterior8 = atual8;
    anterior9 = atual9;
    anterior10 = atual10;
    anterior11 = atual11;
    anterior12 = atual12;
    anterior13 = atual13;
    anterior14 = atual14;
    anterior15 = atual15;
    anterior16 = atual16;
    anterior17 = atual17;
    anterior18 = atual18;
    anterior19 = atual19;
    anterior20 = atual20;

    intervalo =  10000;
    intervalo2 = 20000;
    intervalo3 = 30000;
    intervalo4 = 40000;
    intervalo5 = 50000;
    intervalo6 = 60000;
    intervalo7 = 70000;
    intervalo8 = 80000;
    intervalo9 = 90000;
    intervalo10 = 100000;
    intervalo11 = 110000;
    intervalo12 = 120000;
    intervalo13 = 130000;
    intervalo14 = 140000;
    intervalo15 = 150000;
    intervalo16 = 160000;
    intervalo17 = 170000;
    intervalo18 = 180000;
    intervalo19 = 190000;

    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  }  // FECHA IF - FUNÇÃO PARA EXIBIÇÃO DO RELATÓRIO DE FUNCIONAMNETO DE ENVIO AO THINGSPEAK NO DISPLAY TFT

  // ========================================================================================================
  // ENVIO DOS DADOS AO SERVERS IOTs E GRAVAÇÃO DOS DADOS NO CARTÃO DE MEMÓRIA A CADA 15 MINUTOS

  if ( millis() - anterior30 > intervalo30) {

    detachInterrupt(digitalPinToInterrupt(Pino));

    anterior30 = millis();

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
    delay(250);

    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(250);

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
    delay(250);

    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(250);

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES

    tft.fillRect(0, 0, 240, 320, BLACK);

    iot_thingspeak();
    
    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(200);
    
    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES


    // ========================================================================================================
    // CÁLCULO DO VALOR GERADO PELO PLUVIÔMETRO:
  
    if (preciptacao >= 5.00) {

      pluviometro = contaPulso1 * 0.25;                  // Variável para exibir a quantidade de chuva totalizada no dia;
      Read_Pulso1Antigo = Read_Pulso1;                   // Variável para guardar o valor do pulso anterior.
      pluviometro_acum += pluviometro;                   // Variável para mostrar o valor do pluviômetro acumulado;
      
    } else {
      
      Read_Pulso1 = Read_Pulso1Antigo;        // caso haja pulsos, mas o senssor de chuva não marcar acima de 5%, o pulso será o mesmo do anterior.
      contaPulso1 = Read_Pulso1;              // Variável para a quantidade de pulsos a cada "tombo do medidor"

    }

    tft.fillRect(0, 0, 240, 320, BLACK);
    iot_ubidots(); 

    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(200);
    
    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES


    // ========================================================================================================
    // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DOS SENSORES SERÃO RESETADOS ENTRE 00H00MIN A 00H03MIN

    rtc.begin();
    t2 = rtc.getTime();

    if ((t2.hour == 0 && t2.min == 0) || (t2.hour == 0 && t2.min == 1) || (t2.hour == 0 && t2.min == 2) || (t2.hour == 0 && t2.min == 3)) {

      //========================================================================================================
      // Contagem de vezes que houver falha no envio das mensagens aos Servidores IoT:

      msg_counternok_resete = 0; //msg não enviada Ubidots 0
      msg_counternok1_resete = 0; //msg não enviada Ubidots 1
      msg_counternok_t_resete = 0; // msg não enviada ThingSpeak 0
      msg_counternok_t1_resete = 0; // msg não enviada ThingSpeak 1
      msg_counternok_t2_resete = 0; // msg não enviada ThingSpeak 2
      configuraGSM_nok_resete = 0; // GSM não Ok(resete)
      configuraGSM_nok = 0; // GSM não ok (SMS envio)

      //========================================================================================================

      t1MaxDHT22 = -100.00;
      t1MinDHT22 = 100.00;
      UmaxDHT22 = -100.00;
      UminDHT22 = 100.00;

      luxmax = -5000.00;
      luxmin = 5000.00;
      termoparMax = -100.00;
      termoparMin = 100.00;

      umSmaxP1 = -100.00;
      umSminP1 = 100.00;
      umSmaxP2 = -100.00;
      umSminP2 = 100.00;

      pMax = -1000.00;
      pMin = 1000.00;
      sms_prev_chuva = true;

      altMax = -1500, 00;
      altMin = 1500, 00;

      MiliLitros = 0.00;
      Litros = 0.00;
      contaPulsotot = 0;

      nivelMax = -100.00;
      nivelMin = 100.00;
      volume_Max = -9000;
      volume_Min = 9000;

      UV_indexMax = -100.00;
      UV_indexMin = 100.00;

      t1_int_Max = -100.00;
      t1_int_Min = 100.00;

    } // FECHA IF - VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DOS SENSORES SERÃO RESETADOS ENTRE 00H00MIN A 00H03MIN

    // ========================================================================================================
    // CÁLCULO DO VALOR GERADO PELO PLUVIÔMETRO:
  
    if (preciptacao >= 5.00) {

      pluviometro = contaPulso1 * 0.25;                  // Variável para exibir a quantidade de chuva totalizada no dia;
      Read_Pulso1Antigo = Read_Pulso1;                   // Variável para guardar o valor do pulso anterior.
      pluviometro_acum += pluviometro;                   // Variável para mostrar o valor do pluviômetro acumulado;
      
    } else {
      
      Read_Pulso1 = Read_Pulso1Antigo;        // caso haja pulsos, mas o senssor de chuva não marcar acima de 5%, o pulso será o mesmo do anterior.
      contaPulso1 = Read_Pulso1;              // Variável para a quantidade de pulsos a cada "tombo do medidor"

    }

    tft.fillRect(0, 0, 240, 320, BLACK);
    iot_thingspeak1();

    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
    delay(200);
    
    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES

    tft.fillRect(0, 0, 240, 320, BLACK);
    iot_ubidots1();

    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
    delay(200);
    
    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES

    // ========================================================================================================
    // CÁLCULO DO VALOR GERADO PELO PLUVIÔMETRO:
  
    if (preciptacao >= 5.00) {

      pluviometro = contaPulso1 * 0.25;                  // Variável para exibir a quantidade de chuva totalizada no dia;
      Read_Pulso1Antigo = Read_Pulso1;                   // Variável para guardar o valor do pulso anterior.
      pluviometro_acum += pluviometro;                   // Variável para mostrar o valor do pluviômetro acumulado;
      
    } else {
      
      Read_Pulso1 = Read_Pulso1Antigo;    // caso haja pulsos, mas o senssor de chuva não marcar acima de 5%, o pulso será o mesmo do anterior.
      contaPulso1 = Read_Pulso1;          // Variável para a quantidade de pulsos a cada "tombo do medidor"
      
    }
  
    tft.fillRect(0, 0, 240, 320, BLACK);
    
    iot_thingspeak2();

    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
    delay(200);
    
    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES

    d2();

    d3();
    
    tft.fillRect(0, 0, 240, 320, BLACK);
    configuraGSM();

    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
    delay(200);
    
    digitalWrite(LED, false);           // Reseta o LED DA PLACA DOS SENSORES
    delay(200);

    digitalWrite(LED, true);           // Seta o LED DA PLACA DOS SENSORES
    delay(5000);


    //========================================================================================================
    // Verifica se a Pressão Atmosférica indica possibilidade de chuva:

    if ( ((pMax - pMin >= 4.50) || (pMin <= 918.00)) && (sms_prev_chuva == true)) {

      // ========================================================================================================
      // Enviando SMS para o celular +551599999999
      
      enviaSMS6("+551599999999", "IoT NANO SMART AGRO \n**AVISO IMPORTANTE**");          // enviaSMS(telefoneSMS, o resumo de funcionamento do protótipo!

      // ========================================================================================================
      // Enviando SMS para o celular +55159XXXXXXXXXX
      
      enviaSMS6("+551599XXXXXXX", "IoT NANO SMART AGRO \n**AVISO IMPORTANTE**");          // enviaSMS(telefoneSMS, o resumo de funcionamento do protótipo!

      // ========================================================================================================
      // Enviando SMS para o celular +55159YYYYYYYYY

      enviaSMS6("+55159YYYYYYYYY", "IoT NANO SMART AGRO \n**AVISO IMPORTANTE**");          // enviaSMS(telefoneSMS, o resumo de funcionamento do protótipo!
      
      //========================================================================================================
      // Enviando SMS para o celular +55159ZZZZZZZZ
      
      enviaSMS6("+55159ZZZZZZZZ", "IoT NANO SMART AGRO \n**AVISO IMPORTANTE**");          // enviaSMS(telefoneSMS, o resumo de funcionamento do protótipo!

      sms_prev_chuva = false;
    } // FECHA IF - Verifica se a Pressão Atmosférica indica possibilidade de chuva:

    //========================================================================================================
    // Verifica se a houve Prepitação de chuva maior que 1.00 mm2:

    if ((pluviometro >= 1.00) && (sms_pluviometro == true)) {

      tft.fillRect(0, 0, 240, 320, BLACK);

      digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
      delay(250);
      digitalWrite(BUZZER_VCC, false);        // Reseta o BUZZER
      delay(250);
      digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
      delay(250);
      digitalWrite(BUZZER_VCC, false);        // Reseta o BUZZER
      delay(250);
      digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
      delay(250);
      digitalWrite(BUZZER_VCC, false);        // Reseta o BUZZER

      tft.fillRoundRect(0, 0, 240, 95, 15, RED);
      tft.drawRoundRect(0, 0, 240, 95, 15, WHITE);
      tft.setCursor(23, 10);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      tft.print(F("VERIFICANDO"));
      tft.setCursor(52, 37);
      tft.print(F("ENVIO DE"));
      tft.setCursor(14, 64);
      tft.print(F("MENSAGEM SMS"));

      tft.fillRoundRect(10, 110, 220, 30, 15, YELLOW);
      tft.drawRoundRect(10, 110, 220, 30, 15, RED);
      tft.setCursor(30, 114);
      tft.setTextColor(RED);
      tft.print(F("ENVIAR SMS!"));
      
      tft.setCursor(10, 158);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("SMS para:"));
      tft.setTextColor(WHITE);
      tft.print(F("Walter R."));

      tft.setCursor(10, 178);
      tft.setTextColor(CYAN);
      tft.print(F("Cel:"));
      tft.setTextColor(WHITE);
      tft.print(F("+551599999999"));

      tft.setCursor(10, 198);
      tft.setTextColor(CYAN);
      tft.print(F("Mensagem: "));
      tft.setTextColor(WHITE);
      tft.print(F("Registro de Preciptacao maior que 1.00mm!!"));

      delay(3000);

      enviaSMS7("+55159999999", "IoT NANO SMART AGRO \n**AVISO IMPORTANTE**");          // enviaSMS(telefoneSMS, o resumo de funcionamento do protótipo!

      delay(3000);
      tft.fillRect(0, 280, 240, 38, RED);
      tft.setCursor(5, 282);
      tft.setTextColor(WHITE);
      tft.print(F("Houve Preciptacao!!"));
      tft.setCursor(25, 300);
      tft.print(F("  SMS Enviado!  "));

      msg_sms_env++;

      delay(3000);

      int pino53 = 53;
      pinMode(pino53, OUTPUT);

      delay(500);
      SD.begin(pino53);
      delay(500);

      myFile = SD.open("SMS.txt", FILE_WRITE);
      myFile.print(F("NANO SMART AGRO - Mensagem SMS Enviada"));
      myFile.print(F(";"));
      myFile.print(F("Ocorrencia de chuva detectada!"));
      myFile.print(F(";"));
      myFile.print(F(" Envio do valor do Pluviometro por SMS"));
      myFile.print(F(";"));
      myFile.print(F(" Cel:"));
      myFile.print("+5515999999999");
      myFile.print(F(";"));
      myFile.print(F(" SMS Enviados: "));
      myFile.print(msg_sms_env);
      myFile.print(F(";"));
      myFile.print(F(" DATA: "));
      myFile.print(t.date, DEC);
      myFile.print(F("/"));
      myFile.print(t.mon, DEC);
      myFile.print(F("/"));
      myFile.print(t.year, DEC);
      myFile.print(F(";"));
      myFile.print(F(" HORARIO: "));
      myFile.print(rtc.getTimeStr());
      myFile.print(F(";"));
      myFile.println();
      myFile.println();
      delay(1000);
      myFile.close();
      delay(1000);

      SD.end();
      sms_pluviometro = false;

    } //FECHA IF - Verifica se a houve Prepitação de chuva maior que 1.00 mm2:

    // ========================================================================================================
    // Sincronizar os tempos para iniciar o loop novamente para não ter superposição de função

    anterior = millis();
    anterior2 = anterior;
    anterior3 = anterior2;
    anterior4 = anterior3;
    anterior5 = anterior4;
    anterior6 = anterior5;
    anterior7 = anterior6;
    anterior8 = anterior7;
    anterior9 = anterior8;
    anterior10 = anterior9;
    anterior11 = anterior10;
    anterior12 = anterior11;
    anterior13 = anterior12;
    anterior14 = anterior13;
    anterior15 = anterior14;
    anterior16 = anterior15;
    anterior17 = anterior16;
    anterior18 = anterior17;
    anterior19 = anterior18;
    anterior20 = anterior19;

    intervalo =  10000;
    intervalo2 = 20000;
    intervalo3 = 30000;
    intervalo4 = 40000;
    intervalo5 = 50000;
    intervalo6 = 60000;
    intervalo7 = 70000;
    intervalo8 = 80000;
    intervalo9 = 90000;
    intervalo10 = 100000;
    intervalo11 = 110000;
    intervalo12 = 120000;
    intervalo13 = 130000;
    intervalo14 = 140000;
    intervalo15 = 150000;
    intervalo16 = 160000;
    intervalo17 = 170000;
    intervalo18 = 180000;
    intervalo19 = 190000;
    intervalo20 = 200000;

    tft.fillRect(0, 0, 240, 320, BLACK);
    gravadadosSd();

    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  }// FECHA IF DE TESTE DE TEMPO PARA ENVIO AOS SERVER IOT A CADA 15 MINUTOS.

  //========================================================================================================
  //TEMPO DE GRAVAÇÃO SINCRONA DOS DADOS NO SERVER IOT: (A CADA 15 MINUTOS);

  atual30 = millis();
  intervalo30 = 900000;  
  t_send = (900 - ((atual30 - anterior30) / 1000)); 

  //========================================================================================================
  // CÁLCULO PARA MEDIÇÃO DE VAZÃO: SENSOR DE VAZÃO SIMOKIT 1L = 27 PULSOS // K-FACTOR = 0.45

  // Frequencia dos Pulsos (Hz) = 0.45 * Q (Litros/min)

  //      Q (Litros/min) = Frequencia dos Pulsos em Hz(pulsos por segundo)
  //                       -----------------------------------------------
  //                                       0.45  (k Factor)


  //                           Q (L/min) * tempo decorrido = 1segundo       (Frequencia dos Pulsos em Hz(pulsos por segundo) / 0.45 K-FACTOR)
  //        TOTALIZADOR    =   --------------------------------------   =   ------------------------------------------------------------------   =
  //         (LITROS)                    60 (60 segundos = 1 minuto)                             60

  // ========================================================================================================
  // CONTAGEM DOS PULSOS GERADOS PELO SENSOR DE VAZÃO A CADA 1 SEGUNDO:

  atualvazao = millis();
  intervalovazao = 1000;

  if ( atualvazao - anteriorvazao > intervalovazao) {

    detachInterrupt(digitalPinToInterrupt(Pino));   // Desabilita somente a interrupção da leitura do sensor de vazão / pino 19 corresponde a interrupção 2

    // Frequencia dos Pulsos (Hz) = 0.45 * Q,  onde  Q é a vazão em Litros/minutos
    // contaPulso_vazao (Hz) = 0.45 * vazao(Q)
    // Vazao Q(Litros/min) = contaPulso_vazao / 0.45

    vazao = contaPulso_vazao / 0.45;  //Litros/min

    // Cálculo para o totalizador em Litros da vazão
    // MiliLitros = Q (l/min) / 60 (60segundos = 1 minuto)

    MiliLitros = vazao / 60;         // VARIAVEL PARA CONTABILIZAR ML ACUMULADA
    Litros = Litros + MiliLitros;    // Litros acumulados

    pulsos_vazao_seg = contaPulso_vazao;              // CONTA OS PULSOS GERADOS EM 1 SEGUNDO
    contaPulso_vazao = 0;                             // ZERA A VARIÁVEL DO CONTADOR DE PULSOS POR SEGUNDO

    anteriorvazao = millis();

    attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);

  } // FECHA IF - CONTAGEM DOS PULSOS GERADOS PELO SENSOR DE VAZÃO A CADA 1 SEGUNDO:

  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DOS SENSORES SERÃO RESETADOS ENTRE 00H00MIN A 00H03MIN

  rtc.begin();
  t2 = rtc.getTime();

  if ((t2.hour == 0 && t2.min == 0) || (t2.hour == 0 && t2.min == 1) || (t2.hour == 0 && t2.min == 2) || (t2.hour == 0 && t2.min == 3)) {

    t1MaxDHT22 = -100.00;
    t1MinDHT22 = 100.00;
    UmaxDHT22 = -100.00;
    UminDHT22 = 100.00;

    //========================================================================================================
    // Contagem de vezes que houver falha no envio das mensagens aos Servidores IoT:

    msg_counternok_resete = 0; //msg não enviada Ubidots 0
    msg_counternok1_resete = 0; //msg não enviada Ubidots 1
    msg_counternok_t_resete = 0; // msg não enviada ThingSpeak 0
    msg_counternok_t1_resete = 0; // msg não enviada ThingSpeak 1
    msg_counternok_t2_resete = 0; // msg não enviada ThingSpeak 2
    configuraGSM_nok_resete = 0;
    configuraGSM_nok = 0; // GSM não ok (SMS envio)

    //========================================================================================================

    luxmax = -5000.00;
    luxmin = 5000.00;
    termoparMax = -100.00;
    termoparMin = 100.00;

    umSmaxP1 = -100.00;
    umSminP1 = 100.00;
    umSmaxP2 = -100.00;
    umSminP2 = 100.00;

    pMax = -1000.00;
    pMin = 1000.00;
    sms_prev_chuva = true;

    altMax = -1500, 00;
    altMin = 1500, 00;

    MiliLitros = 0.00;
    Litros = 0.00;
    contaPulsotot = 0;

    nivelMax = -100.00;
    nivelMin = 100.00;
    volume_Max = -9000;
    volume_Min = 9000;

    UV_indexMax = -100.00;
    UV_indexMin = 100.00;

    t1_int_Max = -100.00;
    t1_int_Min = 100.00;

    cpmin = 100.00;
    cpmax = -100.00;
    dewPointMax = -100.00;
    dewPointMin = 100.00;

  } // FECHA IF - VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DOS SENSORES SERÃO RESETADOS ENTRE 00H00MIN A 00H03MIN

  //========================================================================================================
  // RESETA PULSOS DO PLUVIÔMETRO NO HORÁRIO DE 23H59MIN

  if ((t2.hour == 23 && t2.min == 59)) {
    contaPulso1 = 0;   // RESETA PULSOS DO PLUVIÔMETRO NO HORÁRIO DE 23H59MIN
    Read_Pulso1 = 0;   // RESETA PULSOS DO PLUVIÔMETRO NO HORÁRIO DE 23H59MIN
    Read_Pulso1Antigo = 0;   // RESETA PULSOS DO PLUVIÔMETRO NO HORÁRIO DE 23H59MIN
    pluviometro = 0;
    sms_pluviometro = true;
  }


  

} // ENCERRA VOID LOOP PRINCIPAL








/********************************************************************************************************/
/********************************************************************************************************/

// ========================================================================================================
// SUBROTINAS DAS INTERRUPÇÕES:

/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/

// ========================================================================================================
// INTERRUPÇÃO PINO 19 - MEDIÇÃO DE VAZÃO:

void pulse ()
{
  detachInterrupt(digitalPinToInterrupt(Pino));
  detachInterrupt(digitalPinToInterrupt(Pino1));

  contaPulso_vazao++;     //Variável para a quantidade de pulsos++; //Incrementa a variável de pulsos
  contaPulsotot++;        //Variável para a quantidade de pulsos++; //Incrementa a variável de pulsos

  attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
  attachInterrupt(digitalPinToInterrupt(Pino1), pulso_chuva, RISING);
}


/********************************************************************************************************/
/********************************************************************************************************/

// ========================================================================================================
// SUBROTINA DA INTERRUPÇÃO PINO 20 - PLUVIOMETRO:

void pulso_chuva ()
{
  detachInterrupt(digitalPinToInterrupt(Pino1));
  detachInterrupt(digitalPinToInterrupt(Pino));

  delayMicroseconds(1000000);           // 1seg para corrigir o debounce;
  
  Read_Pulso1++;                        // lê os pulsos gerados, a cada "tombo do medidor" que equivale à 0,25mm de chuva, gera-se dois pulsos
  contaPulso1 = Read_Pulso1/2;            // Variável para a quantidade de pulsos a cada "tombo do medidor"
  
  estado_buzzer = true;
  contaPulso_vazao = 0;
  contaPulsotot = 0;

  attachInterrupt(digitalPinToInterrupt(Pino1), pulso_chuva, RISING);
  attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);

}







/********************************************************************************************************/
/********************************************************************************************************/

// ========================================================================================================
// FUNÇÕES DE SETUP:

/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/


// ========================================================================================================
// SETUP MÓDULOS I2C:
void teste_I2C() {

  sensor_bmp.begin();

  tft.fillRect(10, 5, 220, 70, RED);
  tft.fillRect(15, 10, 210, 60, BLACK);

  tft.setCursor(76, 15);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(F("SETUP"));
  tft.setCursor(22, 43);
  tft.print(F("MODULOS I2C"));

  tft.setCursor(5, 90);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("SCAN MODULOS I2C:"));

  tft.fillRect(210, 100, 50, 15, BLACK);
  delay(5000);

  // ========================================================================================================
  // INICIANDO O SCANNER DOS MÓDULOS I2C:

  tft.setTextColor(WHITE);
  byte error, address;
  int nDevices;
  int m = 0;
  int end[4];

  end[0] = 0x00;
  end[1] = 0x00;
  end[2] = 0x00;
  end[3] = 0x00;
  end[4] = 0x00;
  nDevices = 0;

  for (address = 1; address < 127; address++ )
  {

    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    tft.setCursor(210, 90);

    if (error == 0)
    {
      delay(200);
      if (address < 16)
        tft.setTextSize(2);
      tft.print(address, HEX);

      delay(3000);

      end[m] = address, HEX ;
      nDevices++;
      m++;
      tft.fillRect(210, 90, 50, 25, BLACK);
    }
    else if (error == 4)
    {
      tft.setCursor(5, 30);
      tft.setTextSize(2);
      tft.fillRect(115, 90, 10, 150, RED);
      tft.print(F("FALHA"));

      delay(3000);

      if (address < 16)
        tft.setCursor(5, 20);
      tft.setTextSize(2);
      tft.fillRect(115, 90, 10, 150, RED);
      tft.print(address, HEX);

      delay(3000);
    }
  }

  tft.setCursor(5, 120);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("Modulos Scanneados:"));

  tft.setTextColor(WHITE);
  tft.setCursor(0, 145);
  tft.print(F("0x"));
  tft.print(end[0], HEX);


  if (end[0] == 35) {
    tft.print(F(" - Modulo BH1750"));
  }
  if (end[0] == 87) {
    tft.print(F(" - Modulo DS3231"));
  }
  if (end[0] == 104) {
    tft.print(F(" - Modulo DS3231"));
  }
  if (end[0] == 119) {
    tft.print(F(" - Modulo BMP280"));
  }

  tft.setCursor(0, 165);
  tft.print(F("0x"));
  tft.print(end[1], HEX);

  if (end[1] == 35) {
    tft.print(F(" - Modulo BH1750"));
  }
  if (end[1] == 87) {
    tft.print(F(" - Modulo DS3231"));
  }
  if (end[1] == 104) {
    tft.print(F(" - Modulo DS3231"));
  }
  if (end[1] == 119) {
    tft.print(F(" - Modulo BMP280"));
  }

  tft.setCursor(0, 185);
  tft.print(F("0x"));
  tft.print(end[2], HEX);

  if (end[2] == 35) {
    tft.print(F(" - Modulo BH1750"));
  }
  if (end[2] == 87) {
    tft.print(F(" - Modulo DS3231"));
  }
  if (end[2] == 104) {
    tft.print(F(" - Modulo DS3231"));
  }
  if (end[2] == 119) {
    tft.print(F(" - Modulo BMP280"));
  }

  tft.setCursor(0, 205);
  tft.print(F("0x"));
  tft.print(end[3], HEX);

  if (end[3] == 35) {
    tft.print(F(" - Modulo BH1750"));
  }
  if (end[3] == 87) {
    tft.print(F(" - Modulo DS3231"));
  }
  if (end[3] == 104) {
    tft.print(F(" - Modulo DS3231"));
  }
  if (end[3] == 119) {
    tft.print(F(" - Modulo BMP280"));
  }

  tft.setCursor(41, 230);
  tft.setTextColor(WHITE);
  tft.print(nDevices);
  tft.println(F(" Modulos I2C"));
  tft.setCursor(61, 250);
  tft.print(F("Scanneados"));

  tft.fillRect(20, 280, 200, 30, RED);
  tft.setCursor(28, 285);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(F("Scan Finalizado!"));

  delay(5000);
  tft.fillRect(0, 86, 240, 320, BLACK);

  // ========================================================================================================
  // MÓDULO BH1750:

  tft.setCursor(5, 90);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("MODULOS SCANNEADOS:"));

  delay(1000);

  tft.drawRect(0, 118, 240, 100, YELLOW);
  tft.setCursor(43, 130);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("Modulo BH1750"));

  tft.setCursor(5, 160);
  tft.setTextColor(CYAN);
  tft.print(F("Endereco I2C: "));
  tft.setTextColor(WHITE);
  tft.print(F("0x23"));

  tft.setCursor(5, 190);
  tft.setTextColor(CYAN);
  tft.print(F("Status:"));

  //23 57 68 77    35 87 104 119

  if (end[0] == 35 || end[1] == 35 || end[2] == 35 || end[3] == 35 ) {
    tft.setCursor(5, 190);
    tft.setTextColor(CYAN);
    tft.print(F("Status: "));
    tft.setTextColor(WHITE);
    tft.print(F("Modulo OK!"));

  } else {
    tft.fillRect(95, 182, 125, 30, YELLOW);
    tft.setCursor(100, 190);
    tft.setTextColor(RED);
    tft.print(F("Em Falha!!"));
  }
  delay(2000);

  tft.drawRect(0, 218, 240, 100, YELLOW);
  tft.setCursor(43, 230);
  tft.print(F("Modulo BMP280"));

  tft.setCursor(5, 260);
  tft.setTextColor(CYAN);
  tft.print(F("Endereco I2C: "));
  tft.setTextColor(WHITE);
  tft.print(F("0x77"));

  tft.setCursor(5, 290);
  tft.setTextColor(CYAN);
  tft.print(F("Status:"));

  if (end[0] == 119 || end[1] == 119 || end[2] == 119 || end[3] == 119) {
    tft.setCursor(5, 290);
    tft.setTextColor(CYAN);
    tft.print(F("Status: "));
    tft.setTextColor(WHITE);
    tft.print(F("Modulo OK!"));

  } else {
    tft.fillRect(95, 282, 125, 30, YELLOW);
    tft.setCursor(100, 290);
    tft.setTextColor(RED);
    tft.print(F("Em Falha!!"));
  }

  delay(5000);

  tft.fillRect(0, 86, 240, 320, BLACK);
  tft.setCursor(5, 90);
  tft.setTextColor(CYAN);
  tft.print(F("MODULOS SCANNEADOS:"));

  delay(1000);

  tft.drawRect(0, 118, 240, 100, YELLOW);
  tft.setCursor(43, 130);
  tft.setTextColor(CYAN);
  tft.print(F("Modulo DS3231"));

  tft.setCursor(5, 160);
  tft.setTextColor(CYAN);
  tft.print(F("Endereco I2C: "));
  tft.setTextColor(WHITE);
  tft.print(F("0x57"));

  tft.setCursor(5, 190);
  tft.setTextColor(CYAN);
  tft.print(F("Status:"));

  if (end[0] == 87 || end[1] == 87 || end[2] == 87 || end[3] == 87) {
    tft.setCursor(5, 190);
    tft.setTextColor(CYAN);
    tft.print(F("Status: "));
    tft.setTextColor(WHITE);
    tft.print(F("Modulo OK!"));

  } else {
    tft.fillRect(95, 182, 125, 30, YELLOW);
    tft.setCursor(100, 190);
    tft.setTextColor(RED);
    tft.print(F("Em Falha!!"));
  }
  delay(2000);

  // ========================================================================================================
  // MÓDULO BMP280

  tft.drawRect(0, 218, 240, 100, YELLOW);
  tft.setCursor(43, 230);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("Modulo DS3231"));

  tft.setCursor(5, 260);
  tft.setTextColor(CYAN);
  tft.print(F("Endereco I2C: "));
  tft.setTextColor(WHITE);
  tft.print(F("0x68"));

  tft.setCursor(5, 290);
  tft.setTextColor(CYAN);
  tft.print(F("Status:"));

  if ((end[0] == 104 || end[1] == 104 || end[2] == 104 || end[3] == 104 )) {
    tft.setCursor(5, 290);
    tft.setTextColor(CYAN);
    tft.print(F("Status: "));
    tft.setTextColor(WHITE);
    tft.print(F("Modulo OK!"));

  } else {
    tft.fillRect(95, 282, 125, 30, YELLOW);
    tft.setCursor(100, 290);
    tft.setTextColor(RED);
    tft.print(F("Em Falha!!"));
  }

  delay(5000);

  tft.fillScreen(BLACK);
  tft.fillRect(10, 5, 220, 70, RED);
  tft.fillRect(15, 10, 210, 60, BLACK);

  tft.setCursor(76, 15);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(F("SETUP"));
  tft.setCursor(22, 43);
  tft.print(F("MODULOS I2C"));

  tft.setCursor(13, 86);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("BMP280 TEMPERATURA"));
  tft.setCursor(5, 105);
  tft.setTextColor(WHITE);
  tft.print(F("Valor Min: -40C"));
  tft.setCursor(5, 125);
  tft.print(F("Valor Max: +80C"));
  tft.setCursor(5, 145);
  tft.print(F("Temperatura: "));
  tft.print(sensor_bmp.readTemperature());
  tft.print(F("C"));

  tft.setCursor(13, 167);
  tft.setTextColor(CYAN);
  tft.print(F("BMP280 PRESSAO ATM"));
  tft.setTextColor(WHITE);
  tft.setCursor(5, 185);
  tft.print(F("Valor Min: 300mBar"));
  tft.setCursor(5, 205);
  tft.print(F("Valor Max: 1100mBar"));
  tft.setCursor(5, 225);
  tft.print(F("Pres. Atm: "));
  float bpp = (sensor_bmp.readPressure() / 100);
  tft.print(bpp, 0);
  tft.print(F("mBar"));

  tft.setCursor(5, 245);
  tft.print(F("Altura: "));
  float bpp1 = (sensor_bmp.readAltitude(1013.25));
  tft.print(bpp1, 1);
  tft.print(F("metros"));

  tft.setCursor(5, 265);
  tft.setTextColor(WHITE);
  tft.print(F("Status: "));
  if (sensor_bmp.getStatus() == 12) {
    tft.print("Ok");
  } else {
    tft.print("Falha");
  }

  tft.setCursor(13, 285);
  tft.setTextColor(CYAN);
  tft.print(F("BH1750 SENSOR LUX"));
  tft.setCursor(5, 305);
  tft.setTextColor(WHITE);
  tft.print(F("Luminosidade: "));
  lux = lightMeter.readLightLevel();
  tft.print(lux);

  delay(5000);

}// FECHA VOID SETUP I2C






// ========================================================================================================
// FUNÇÃO PARA EXIBIR A DATA E HORA:

void data_hora() {

  rtc.begin();
  t = rtc.getTime();

  tft.fillRect(0, 0, 240, 320, BLACK);
  tft.fillRoundRect(20, 40, 200, 210, 15, RED);
  tft.drawRoundRect(20, 40, 200, 210, 15, WHITE);

  delay(1500);

  tft.setCursor(48, 56);
  tft.setTextColor(WHITE);
  tft.setTextSize(6);
  tft.print(F("NANO"));

  delay(1500);

  tft.setCursor(32, 120);
  tft.print(F("SMART"));

  delay(1500);

  tft.setCursor(48, 184);
  tft.print(F("AGRO"));

  delay(1500);

  tft.fillRoundRect(10, 270, 220, 40, 5, RED);
  tft.drawRoundRect(10, 270, 220, 40, 5, WHITE);

  delay(1500);

  tft.setCursor(37, 275);
  tft.setTextColor(WHITE, RED);
  tft.setTextSize(2);
  tft.print(F("WD RETZER S.A."));

  delay(1500);

  tft.setCursor(25, 292);
  tft.print(F(" PROTOTIPO  IoT "));

  delay(3000);

  tft.setCursor(37, 275);
  tft.setTextColor(WHITE, RED);
  tft.print(F("AGRICULTURA DE"));
  tft.setCursor(25, 292);
  tft.print(F("    PRECISAO    "));

  delay(3000);

  tft.setCursor(37, 275);
  tft.print(F("  DATALLOGER  "));
  tft.setCursor(25, 292);
  tft.print(F("VERSAO: V4.01.34"));

  delay(3000);
  tft.fillRect(0, 0, 240, 320, BLACK);
  tft.fillRect(10, 5, 220, 70, RED);
  tft.fillRect(15, 10, 210, 60, BLACK);
  tft.setTextColor(WHITE);
  tft.setCursor(40, 26);
  tft.setTextSize(4);
  tft.print(F("HORARIO"));


  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO A CADA 1 SEGUNDO:

  unsigned long atualiza_lcd;
  unsigned long atualiza_lcd2;

  atualiza_lcd = millis();
  atualiza_lcd2 = millis();

  tft.fillRect(0, 90, 240, 50, RED);
  tft.fillRect(0, 170, 240, 50, RED);
  tft.fillRect(0, 250, 240, 50, RED);

  while (millis() - atualiza_lcd2 < 10000) {
    if (millis() - atualiza_lcd >= 1000) {

      atualiza_lcd = millis();
      tft.setCursor(54, 100);
      tft.setTextColor(WHITE, RED);
      tft.setTextSize(3);
      tft.print(rtc.getTimeStr());

      // ========================================================================================================
      // EXIBIÇÃO DA DATA:

      tft.setCursor(35, 180);
      char const divider = '/';
      tft.print(rtc.getDateStr(FORMAT_LONG, FORMAT_LITTLEENDIAN, divider));
      tft.print(F(" "));

      // ========================================================================================================
      // EXIBIÇÃO DO DIA DA SEMANA:

      String seg = "Segunda-Feira";
      String ter = "Terca-Feira";
      String qua = "Quarta-Feira";
      String qui = "Quinta-Feira";
      String sex = "Sexta-Feira";
      String sab = "Sabado";
      String dom = "Domingo";
      String dia1 = rtc.getDOWStr();

      if (seg.equals(dia1)) {

        tft.setTextColor(WHITE, RED);
        tft.setCursor(15, 265);
        tft.setTextSize(2);
        tft.print(F("DIA: "));
        tft.print(rtc.getDOWStr());
      }

      else if (ter.equals(dia1)) {

        tft.setTextColor(WHITE, RED);
        tft.setCursor(30, 265);
        tft.setTextSize(2);
        tft.print(F("DIA: "));
        tft.print(rtc.getDOWStr());
      }

      else if (qua.equals(dia1)) {

        tft.setTextColor(WHITE, RED);
        tft.setCursor(20, 265);
        tft.setTextSize(2);
        tft.print(F("DIA: "));
        tft.print(rtc.getDOWStr());
      }

      else if (qui.equals(dia1)) {

        tft.setTextColor(WHITE, RED);
        tft.setCursor(20, 265);
        tft.setTextSize(2);
        tft.print(F("DIA: "));
        tft.print(rtc.getDOWStr());
      }

      else if (sex.equals(dia1)) {

        tft.setTextColor(WHITE, RED);
        tft.setCursor(20, 265);
        tft.setTextSize(2);
        tft.print(F("DIA: "));
        tft.print(rtc.getDOWStr());
      }

      else if (sab.equals(dia1)) {

        tft.setTextColor(WHITE, RED);
        tft.setCursor(55, 265);
        tft.setTextSize(2);
        tft.print(F("DIA: "));
        tft.print(rtc.getDOWStr());
      }

      else if (dom.equals(dia1)) {

        tft.setTextColor(WHITE, RED);
        tft.setCursor(50, 265);
        tft.setTextSize(2);
        tft.print(F("DIA: "));
        tft.print(rtc.getDOWStr());
      }
    }
  }
  return;
}


// ========================================================================================================
// INICIANDO SETUP DO SENSOR DHT22:

void dht_setup() {

  tft.fillRect(7, 5, 228, 70, RED);
  tft.fillRect(11, 10, 220, 60, BLACK);

  tft.setCursor(76, 15);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(F("SETUP"));
  tft.setCursor(14, 43);
  tft.print(F("SENSOR DHT22"));

  tft.setCursor(25, 85);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(F("INICIANDO SETUP:"));

  tft.drawRect(0, 108, 240, 100, YELLOW);

  // ========================================================================================================
  // INICIALIZANDO SENSOR DHT22:
  dht1.begin();
  delay(1000);
  float h = dht1.readHumidity();
  float t1 = dht1.readTemperature();

  dht2.begin();
  delay(1000);
  float h_int = dht2.readHumidity();
  float t1_int = dht2.readTemperature();


  tft.setCursor(20, 120);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("TESTANDO SENSORES"));
  delay(500);
  tft.fillRect(0, 140, 60, 6, GREEN);
  delay(800);
  tft.fillRect(0, 140, 100, 6, GREEN);
  delay(1200);
  tft.fillRect(0, 140, 140, 6, GREEN);
  delay(1500);
  tft.fillRect(0, 140, 180, 6, GREEN);
  delay(1800);
  tft.fillRect(0, 140, 200, 6, GREEN);
  delay(1700);
  tft.fillRect(0, 140, 240, 6, GREEN);
  delay(1900);

  if (isnan(t1) || isnan(h)) {

    tft.fillRect(0, 154, 240, 20, YELLOW);
    tft.setCursor(6, 156);
    tft.setTextColor(RED);
    tft.setTextSize(2);
    tft.print(F("FALHA DHT22 EXTERNO"));

    tft.drawRect(0, 208, 240, 110, YELLOW);

    tft.setCursor(5, 220);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.print(F("TEMP. EXTERNA:"));
    tft.setTextColor(WHITE);
    tft.print(F("FALHA"));

    tft.setCursor(5, 240);
    tft.setTextColor(CYAN);
    tft.print(F("UMIDADE EXT.:"));
    tft.setTextColor(WHITE);
    tft.print(F("FALHA"));

    tft.setCursor(5, 260);
    tft.setTextColor(CYAN);
    tft.print(F("DEW POINT:"));
    tft.setTextColor(WHITE);
    tft.print(F("FALHA"));

  } else {

    tft.setCursor(25, 156);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("DHT22 EXTERNO OK"));
    tft.drawRect(0, 208, 240, 110, YELLOW);
    tft.setCursor(5, 220);
    tft.setTextColor(CYAN);
    tft.print(F("TEMP. EXTERNA:"));
    tft.setTextColor(WHITE);
    tft.print(t1, 0);
    tft.setCursor(200, 220);
    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    tft.print(F("O"));
    tft.setCursor(208, 220);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("C"));

    tft.setCursor(5, 240);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.print(F("UMIDADE EXTERNA:"));
    tft.setTextColor(WHITE);
    tft.print(h, 0);
    tft.print(F("%"));

    tft.setCursor(5, 260);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.print(F("DEW POINT:"));
    tft.setTextColor(WHITE);
    tft.print(dewPoint(t1, h));
    tft.setCursor(188, 260);
    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    tft.print(F("O"));
    tft.setCursor(196, 260);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("C"));
  }

  delay(1000);

  if (isnan(t1_int) || isnan(h_int)) {

    tft.fillRect(0, 178, 240, 20, YELLOW);
    tft.setCursor(6, 180);
    tft.setTextColor(RED);
    tft.setTextSize(2);
    tft.print(F("FALHA DHT22 INTERNO"));

    tft.drawRect(0, 208, 240, 110, YELLOW);

    tft.setCursor(5, 280);
    tft.setTextColor(CYAN);
    tft.print(F("TEMP. INTERNA:"));
    tft.setTextColor(WHITE);
    tft.print(F("FALHA"));

    tft.setCursor(5, 300);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.print(F("UMIDADE INT.:"));
    tft.setTextColor(WHITE);
    tft.print(F("FALHA"));
  }
  else
  {
    tft.setCursor(25, 180);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("DHT22 INTERNO OK"));
    tft.drawRect(0, 208, 240, 110, YELLOW);

    tft.setCursor(5, 280);
    tft.setTextColor(CYAN);
    tft.print(F("TEMP. INTERNA:"));
    tft.setTextColor(WHITE);
    tft.print(t1_int, 0);
    tft.setCursor(200, 280);
    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    tft.print(F("O"));
    tft.setCursor(208, 280);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("C"));

    tft.setCursor(5, 300);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.print(F("UMIDADE INTERNA:"));
    tft.setTextColor(WHITE);
    tft.print(h_int, 0);
    tft.print(F("%"));
  }
  delay(5000);
} //FECHA SETUP DHT



/********************************************************************************************************/
/********************************************************************************************************/

// ========================================================================================================
// FUNÇÕES PARA EXIBIÇÃO DO GAUGE NO DISPLAY TFT:

/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/


// ========================================================================================================
// FUNÇÃO GRÁFICA PARA EXIBIÇÃO DE GAUGE ANALÓGICO NO DISPLAY:

int ringMeter(float value, int vmin, int vmax, int x, int y, int r, char *units, byte scheme)
{

  if (value < 0) {
    value = 0;
  }

  // Minimum value of r is about 52 before value text intrudes on ring
  // drawing the text first is an option

  x += r; y += r;                                                             // calculate coordinates of center of ring
  int w = r / 3;                                                              // width of outer ring is 1/4 of radius
  int angle = 150;                                                            // half the sweep angle of the meter (300 degrees)
  int v = map(value, vmin, vmax, -angle, angle);                              // map the value to an angle v
  byte seg = 3;                                                               // segments are 3 degrees wide = 100 segments for 300 degrees
  byte inc = 6;                                                               // draw segments every 3 degrees, increase to 6 for segmented ring
  //int colour = BLUE;                                                        // variable to save "value" text color from scheme and set default
  int colour = GREEN;                                                         // variable to save "value" text color from scheme and set default

  for (int i = -angle + inc / 2; i < angle - inc / 2; i += inc)               // draw color blocks every increment degrees
  {
    float sx = cos((i - 90) * 0.0174532925);                                 // calculate pair of coordinates for segment start
    float sy = sin((i - 90) * 0.0174532925);
    uint16_t x0 = sx * (r - w) + x;
    uint16_t y0 = sy * (r - w) + y;
    uint16_t x1 = sx * r + x;
    uint16_t y1 = sy * r + y;

    float sx2 = cos((i + seg - 90) * 0.0174532925);                          // salculate pair of coordinates for segment end
    float sy2 = sin((i + seg - 90) * 0.0174532925);
    int x2 = sx2 * (r - w) + x;
    int y2 = sy2 * (r - w) + y;
    int x3 = sx2 * r + x;
    int y3 = sy2 * r + y;

    if (i < v)
    { // fill in coloured segments with 2 triangles
      switch (scheme)
      {
        case 0: colour = RED; break;                                     // fixed color
        case 1: colour = GREEN; break;                                   // fixed color
        case 2: colour = BLUE; break;                                    // fixed colour
        case 3: colour = rainbow(map(i, -angle, angle, 0, 127)); break;  // full spectrum blue to red
        case 4: colour = rainbow(map(i, -angle, angle, 70, 127)); break; // green to red (high temperature etc)
        case 5: colour = rainbow(map(i, -angle, angle, 127, 63)); break; // red to green (low battery etc)

        // cores do ring meter para serem testadas:
        case 6: colour = YELLOW; break;                                  // fixed colour
        case 7: colour = ORANGE; break;                                  // fixed colour
        case 8: colour = OLIVE; break;                                   // fixed colour
        case 9: colour = rainbow(map(i, -angle, angle, 100, 127)); break;// orange to red (uv index)

        default: colour = GREEN; break;                                   // fixed color

      }
      tft.fillTriangle(x0, y0, x1, y1, x2, y2, colour);
      tft.fillTriangle(x1, y1, x2, y2, x3, y3, colour);
    }
    else                                                                     // fill in blank segments
    {
      tft.fillTriangle(x0, y0, x1, y1, x2, y2, SCALE1);                // color of unoccupied ring scale segment triangle pointing outward
      tft.fillTriangle(x1, y1, x2, y2, x3, y3, SCALE0);                // color of unoccupied ring scale segment traiangle pointing inward
    }
  }

  char buf [10];                                                              // convert value to a string
  byte len = 3;
  if (value > 999) {
    len = 4;
    dtostrf (value, len, 0, buf);
  } else {
    dtostrf (value, len, 1, buf);
    //buf[len] = ' '; buf[len] = 0;                                               // add blanking space and terminator, helps to centre text too!
  }

  /*
       if(units == "NSA-LI-001"){
         byte len = 2;
         buf[len] = 0;
         dtostrf (value, len, 2, buf);
       }  */

  //|| units == "NSA-LI-001"
  if (units == "NSA-QI-001") {
    byte len = 2;
    buf[len] = 0;
    dtostrf (value, len, 2, buf);

    if (value < 10) // menor q 10
    {
      tft.setTextColor (colour, BLACK);
      tft.setCursor (x - 35, y - 15);
      tft.setTextSize (3);
      tft.print (buf);

    } else {

      tft.setTextColor (colour, BLACK);
      tft.setCursor (x - 45, y - 15);
      tft.setTextSize (3);
      tft.print (buf);

    }

  } else if (units == "NSA-FI-001") {
    if (value < 10) // menor q 10
    {
      tft.fillRect(74, 125, 94, 40, BLACK); //para valores abaixo de 100
      tft.fillRect(78, 120, 80, 32, BLACK); //para valores acima de 1000.
      tft.setTextColor (colour, BLACK);
      tft.setCursor (x - 35, y - 15);
      tft.setTextSize (4);
      tft.print (buf);
    }

    if (value >= 10 && value <= 100) // maior q 10 e menor ou igual a 100
    {
      tft.fillRect(74, 125, 94, 40, BLACK); //para valores abaixo de 100
      tft.fillRect(78, 120, 80, 32, BLACK); //para valores acima de 1000.
      tft.setTextColor (colour, BLACK);
      tft.setCursor (x - 45, y - 15);
      tft.setTextSize (4);
      tft.print (buf);
    }

    if (value > 100 && value <= 1000) // maior q 100
    {
      tft.fillRect(78, 120, 80, 32, BLACK); //para valores acima de 1000.
      tft.fillRect(74, 125, 94, 40, BLACK); //para valores abaixo de 100
      tft.setTextColor (colour, BLACK);
      tft.setCursor (x - 45, y - 15);
      tft.setTextSize (3);
      tft.print (buf);
    }

    if (value > 1000) // maior q 100
    {
      tft.fillRect(78, 120, 80, 32, BLACK); //para valores acima de 1000.
      tft.fillRect(74, 125, 94, 40, BLACK); //para valores abaixo de 100
      tft.setTextColor (colour, BLACK);
      tft.setCursor (x - 35, y - 15);
      tft.setTextSize (3);
      tft.print (buf);
    }

  } else {

    if (value < 10) // menor q 10
    {
      tft.setTextColor (colour, BLACK);
      tft.setCursor (x - 35, y - 15);
      tft.setTextSize (4);
      tft.print (buf);
    }

    if (value >= 10 && value <= 100) // maior q 10 e menor ou igual a 100
    {
      tft.setTextColor (colour, BLACK);
      tft.setCursor (x - 45, y - 15);
      tft.setTextSize (4);
      tft.print (buf);
    }

    if (value > 100 && value <= 1000) // maior q 100
    {
      tft.setTextColor (colour, BLACK);
      tft.setCursor (x - 45, y - 15);
      tft.setTextSize (3);
      tft.print (buf);
    }

    if (value > 1000) // maior q 100
    {
      tft.setTextColor (colour, BLACK);
      tft.setCursor (x - 35, y - 15);
      tft.setTextSize (3);
      tft.print (buf);
    }
  }


  tft.setTextColor (WHITE);
  tft.setCursor (x - 29, y + 75);
  tft.setTextSize (1);           // units position relative to scale
  tft.print (units);             // units display = celsius

  //IMPRIMINDO NA TELA A UNIDADE DAS VARIAVEIS DA MESMA COR DO GAUGE

  // UMIDADE DO SOLO PONTO 1
  if (units == "NSA-AI-001") {
    tft.setCursor(116, 186);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(3);
    tft.print(F("%"));
  }

  // UMIDADE DO SOLO PONTO 2:
  if (units == "NSA-AI-002") {
    tft.setCursor(116, 186);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(3);
    tft.print(F("%"));
  }

  // LUMINOSIDADE AMBIENTE:
  if (units == "NSA-AI-003") {
    tft.setCursor(95, 216);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(3);
    tft.print(F("lux"));
  }

  // PRESENÇA DE ORVALHO - CHUVA:
  if (units == "NSA-AI-004") {
    tft.setCursor(116, 216);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(3);
    tft.print(F("%"));
  }

  // INDICE UV:
  if (units == "NSA-AI-005") {
    tft.setCursor(112, 195);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(2);
    tft.print(F("UV"));
  }

  if (units == "NSA-AI-006") {
    tft.setCursor(117, 216);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(3);
    tft.print(F("%"));
  }

  // UMIDADE AMBIENTE:
  if (units == "NSA-MI-001") {
    tft.setCursor(117, 216);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(3);
    tft.print(F("%"));
  }

  // DEW POINT:
  if (units == "NSA-MI-002") {
    tft.setCursor(113, 216);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(1);
    tft.print("O");
    tft.setCursor(122, 216);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(3);
    tft.print(F("C"));
  }

  // PRESSÃO ATMOSFÉRICA:
  if (units == "NSA-PI-001") {
    tft.setCursor(100, 195);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(2);
    tft.print(F("mBar"));
  }

  // ALTITUDE APROXIMADA:
  if (units == "NSA-PI-002") {
    tft.setCursor(87, 225);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(2);
    tft.print(F("metros"));
  }

  //TEMPERATURA AMBIENTE EXTERNA:
  if (units == "NSA-TI-001") {
    tft.setCursor(113, 216);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(1);
    tft.print(F("O"));
    tft.setCursor(122, 216);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(3);
    tft.print(F("C"));
  }

  // TEMPERATURA DO SOLO:
  if (units == "NSA-TI-002") {
    tft.setCursor(113, 216);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(1);
    tft.print(F("O"));
    tft.setCursor(122, 216);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(3);
    tft.print(F("C"));
  }

  //TEMPERATURA AMBIENTE INTERNA:
  if (units == "NSA-TI-003") {
    tft.setCursor(113, 216);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(1);
    tft.print(F("O"));
    tft.setCursor(122, 216);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(3);
    tft.print(F("C"));
  }

  //SENSAÇÃO TÉRMICA:
  if (units == "NSA-TI-004") {
    tft.setCursor(113, 216);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(1);
    tft.print(F("O"));
    tft.setCursor(122, 216);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(3);
    tft.print(F("C"));
  }


  // VAZÃO:
  if (units == "NSA-FI-001") {
    tft.setCursor(88, 200);           //tft.setCursor(91,200);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(2);
    tft.print(F("Litros"));            //tft.print(F("L/min"));
  }


  // PLUVIOMETRO:
  if (units == "NSA-QI-001") {
    tft.setCursor(112, 220);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(2);
    tft.print(F("mm"));
  }

  // NÍVEL DOS RESERVATÓRIOS:
  if (units == "NSA-LI-001") {
    tft.setCursor(112, 220);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(2);
    tft.print(F("cm"));
  }

  // VOLUME DOS RESERVATÓRIOS:
  if (units == "NSA-LI-002") {
    tft.setCursor(88, 225);
    tft.setTextColor(colour, BLACK);
    tft.setTextSize(2);
    tft.print(F("Litros"));
  }

  return x + r;                                                               // calculate and return right hand side x coordinate
}

// ========================================================================================================
// FUNÇÃO GRÁFICA PARA EXIBIÇÃO DE GAUGE ANALÓGICO NO DISPLAY: COR DA PALHETA RAINBOW

unsigned int rainbow(byte value)                                               // value is expected to be in range 0-127
{ // value is converted to a spectrum color from 0 = blue through to 127 = red
  byte red = 0;                                                               // red is the top 5 bits of a 16 bit colour value
  byte green = 0;                                                             // green is the middle 6 bits
  byte blue = 0;                                                              // blue is the bottom 5 bits
  byte quadrant = value / 32;

  if (quadrant == 0)
  {
    blue = 31;
    green = 2 * (value % 32);
    red = 0;
  }
  if (quadrant == 1)
  {
    blue = 31 - (value % 32);
    green = 63;
    red = 0;
  }
  if (quadrant == 2)
  {
    blue = 0;
    green = 63;
    red = value % 32;
  }
  if (quadrant == 3)
  {
    blue = 0;
    green = 63 - 2 * (value % 32);
    red = 31;
  }
  return (red << 11) + (green << 5) + blue;
}


// ========================================================================================================
// FUNÇÃO GRÁFICA PARA EXIBIÇÃO DE GAUGE ANALÓGICO NO DISPLAY: FAZE DO ANGULO EM GRAUS

float sineWave(int phase)
{
  return sin(phase * 0.0174532925);
}







/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/

// ========================================================================================================
// FUNÇÕES PARA EXIBIR AS VARIAVEIS NO DISPLAY TFT:

/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/

// ========================================================================================================
// FUNÇÃO PARA EXIBIR A VARIAVEL TEMPERATURA AMBIENTE INTERNA NO DISPLAY:

void lcd_temp_amb_int() {

  rtc.begin();
  t = rtc.getTime();

  dht2.begin();

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA TEMPERATURA AMBIENTE DO SENSOR DTH22:

  t1_int = dht2.readTemperature();

  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA TEMPERATURA AMBIENTE DO SENSOR DTH22:

  if (t1_int < t1_int_Min)
  {
    t1_int_Min = t1_int;
  }
  if (t1_int > t1_int_Max)
  {
    t1_int_Max = t1_int;
  }

  tft.setCursor(35, 270);
  tft.setTextColor(RED);
  tft.setTextSize(3);
  tft.print(F("MAX"));
  tft.setCursor(26, 300);
  tft.setTextSize(2);
  tft.setTextColor (WHITE);
  tft.print(t1_int_Max, 1);
  tft.setTextSize(1);
  tft.setCursor(76, 300);
  tft.print(F("O"));
  tft.setCursor(83, 300);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(F("C"));

  tft.setCursor(154, 270);
  tft.setTextColor(BLUE);
  tft.setTextSize(3);
  tft.print(F("MIN"));

  tft.setCursor(146, 300);
  tft.setTextColor (WHITE);
  tft.setTextSize(2);
  tft.print(t1_int_Min, 1);
  tft.setTextSize(1);
  tft.setCursor(196, 300);
  tft.print(F("O"));
  tft.setCursor(203, 300);
  tft.setTextColor (WHITE);
  tft.setTextSize(2);
  tft.print(F("C"));

  tft.setCursor(20, 35);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("TEMPERATURA"));
  tft.setCursor(55, 60);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("INTERNA"));

  int xpos = 40, ypos = 90, gap = 100, radius = 80;                           // position of upper ring and proportion
  ringMeter (t1_int, 0, 40, xpos, ypos, radius, "NSA-TI-003", GREEN2RED);      // draw analog mete

  if (isnan(t1_int)) {
    tft.setCursor(77, 160);
    tft.setTextColor(GREEN);
    tft.setTextSize(3);
    tft.print(F("FALHA"));
  }
}



// ========================================================================================================
// FUNÇÃO PARA EXIBIR A VARIAVEL TEMPERATURA AMBIENTE NO DISPLAY:

void lcd_temp_amb() {

  rtc.begin();
  t = rtc.getTime();

  dht1.begin();

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA TEMPERATURA AMBIENTE DO SENSOR DTH22:

  float t1 = dht1.readTemperature();

  if (t1 < t1MinDHT22)
  {
    t1MinDHT22 = t1;
  }
  if (t1 > t1MaxDHT22)
  {
    t1MaxDHT22 = t1;
  }

  tft.setCursor(35, 270);
  tft.setTextColor(RED);
  tft.setTextSize(3);
  tft.print(F("MAX"));
  tft.setCursor(26, 300);
  tft.setTextSize(2);
  tft.setTextColor (WHITE);
  tft.print(t1MaxDHT22, 1);
  tft.setTextSize(1);
  tft.setCursor(76, 300);
  tft.print(F("O"));
  tft.setCursor(83, 300);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(F("C"));

  tft.setCursor(154, 270);
  tft.setTextColor(BLUE);
  tft.setTextSize(3);
  tft.print(F("MIN"));

  tft.setCursor(146, 300);
  tft.setTextColor (WHITE);
  tft.setTextSize(2);
  tft.print(t1MinDHT22, 1);
  tft.setTextSize(1);
  tft.setCursor(196, 300);
  tft.print(F("O"));
  tft.setCursor(203, 300);
  tft.setTextColor (WHITE);
  tft.setTextSize(2);
  tft.print(F("C"));

  tft.setCursor(20, 35);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("TEMPERATURA"));
  tft.setCursor(50, 60);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("AMBIENTE"));

  int xpos = 40, ypos = 90, gap = 100, radius = 80;                           // position of upper ring and proportion
  ringMeter (t1, 0, 40, xpos, ypos, radius, "NSA-TI-001", GREEN2RED);      // draw analog mete

  if (isnan(t1)) {
    tft.setCursor(77, 160);
    tft.setTextColor(GREEN);
    tft.setTextSize(3);
    tft.print(F("FALHA"));
  }
}



//========================================================================================================
// FUNÇÃO PARA EXIBIR A VARIAVEL UMIDADE AMBIENTE NO DISPLAY:

void lcd_umid_amb() {

  rtc.begin();
  t = rtc.getTime();

  dht1.begin();

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));
  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DE UMIDADE DO SENSOR DTH22:

  float h = dht1.readHumidity();

  if (h < UminDHT22)
  {
    UminDHT22 = h;
  }
  if (h > UmaxDHT22)
  {
    UmaxDHT22 = h;
  }

  // ========================================================================================================
  // EXIBIÇÃO DA VARIAVEL UMIDADE DO SENSOR DTH11:

  tft.setCursor(35, 270);
  tft.setTextColor(RED);
  tft.setTextSize(3);
  tft.print(F("MAX"));
  tft.setCursor(32, 300);
  tft.setTextSize(2);
  tft.setTextColor (WHITE);
  tft.print(UmaxDHT22, 1);
  tft.setTextSize(2);
  tft.setCursor(82, 300);
  tft.print(F("%"));

  tft.setCursor(154, 270);
  tft.setTextColor(BLUE);
  tft.setTextSize(3);
  tft.print(F("MIN"));

  tft.setCursor(152, 300);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(UminDHT22, 1);
  tft.setTextSize(2);
  tft.setCursor(202, 300);
  tft.print(F("%"));

  tft.setCursor(58, 35);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("UMIDADE"));
  tft.setCursor(50, 60);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("AMBIENTE"));

  int xpos = 40, ypos = 90, gap = 100, radius = 80;                           // position of upper ring and proportion
  ringMeter (h, 0, 100, xpos, ypos, radius, "NSA-MI-001", RED2GREEN);      // draw analog mete

  if (isnan(h)) {
    tft.setCursor(77, 160);
    tft.setTextColor(GREEN);
    tft.setTextSize(3);
    tft.print(F("FALHA"));
  }
}

// ========================================================================================================
// FUNÇÃO PARA CALCULAR A VARIAVEL DEW POINT NO DISPLAY:

double dewPoint(double celsius, double humidity) {

  double RATIO = 373.15 / (273.15 + celsius);
  double RHS = -7.90298 * (RATIO - 1);
  RHS += 5.02808 * log10(RATIO);
  RHS += -1.3816e-7 * (pow(10, (11.344 * (1 - 1 / RATIO ))) - 1) ;
  RHS += 8.1328e-3 * (pow(10, (-3.49149 * (RATIO - 1))) - 1) ;
  RHS += log10(1013.246);
  double VP = pow(10, RHS - 3) * humidity;
  double T = log(VP / 0.61078); // temp var
  return (241.88 * T) / (17.558 - T);

}

// ========================================================================================================
// FUNÇÃO PARA EXIBIR A VARIAVEL DEW POINT NO DISPLAY:

void lcd_dewpoint() {

  rtc.begin();
  t = rtc.getTime();

  dht1.begin();

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DE UMIDADE DO SENSOR DTH11:

  float h = dht1.readHumidity();
  float t1 = dht1.readTemperature();

  if (dewPoint(t1, h ) < dewPointMin)
  {
    dewPointMin = dewPoint(t1, h );
  }
  if (dewPoint(t1, h ) > dewPointMax)
  {
    dewPointMax = dewPoint(t1, h );
  }

  // ========================================================================================================
  // EXIBIÇÃO DA VARIAVEL UMIDADE DO SENSOR DTH11:

  tft.setCursor(35, 270);
  tft.setTextColor(RED);
  tft.setTextSize(3);
  tft.print(F("MAX"));
  tft.setCursor(26, 300);
  tft.setTextSize(2);
  tft.setTextColor (WHITE);
  tft.print(dewPointMax, 1);
  tft.setTextSize(1);
  tft.setCursor(76, 300);
  tft.print(F("O"));
  tft.setCursor(83, 300);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(F("C"));

  tft.setCursor(154, 270);
  tft.setTextColor(BLUE);
  tft.setTextSize(3);
  tft.print(F("MIN"));

  tft.setCursor(146, 300);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(dewPointMin, 1);
  tft.setTextSize(1);
  tft.setCursor(196, 300);
  tft.print(F("O"));
  tft.setCursor(203, 300);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(F("C"));

  tft.setCursor(40, 35);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("DEW POINT"));
  tft.setCursor(25, 60);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("PONTO DE ORVALHO"));

  int xpos = 40, ypos = 90, gap = 100, radius = 80;                                         // position of upper ring and proportion
  ringMeter (dewPoint(t1, h ), 0, 30, xpos, ypos, radius, "NSA-MI-002", GREEN2GREEN);      // draw analog meter

  if (isnan(t1) || isnan(h)) {
    tft.setCursor(77, 160);
    tft.setTextColor(GREEN);
    tft.setTextSize(3);
    tft.print(F("FALHA"));
  }
}


// ========================================================================================================
// FUNÇÃO PARA EXIBIR A VARIAVEL TEMPERATURA AMBIENTE NO DISPLAY:

void lcd_lum_amb() {

  lightMeter.begin();

  rtc.begin();
  t = rtc.getTime();

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));


  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL LUMINOSIDADE EM LUX:

  lux = lightMeter.readLightLevel();

  if (lux < luxmin)
  {
    luxmin = lux;
  }

  if (lux > luxmax)
  {
    luxmax = lux;
  }

  // ========================================================================================================
  // EXIBIÇÃO DA VARIAVEL LUMINOSIDADE:

  tft.setCursor(35, 270);
  tft.setTextColor(RED);
  tft.setTextSize(3);
  tft.print(F("MAX"));

  if (luxmax >= 1000.0) {
    tft.setCursor(12, 300);
    tft.setTextSize(2);
    tft.setTextColor (WHITE);
    tft.print(luxmax, 1);
    tft.print(F("lux"));
  } else {
    tft.setCursor(22, 300);
    tft.setTextSize(2);
    tft.setTextColor (WHITE);
    tft.print(luxmax, 1);
    tft.print(F("lux"));
  }

  tft.setCursor(154, 270);
  tft.setTextColor(BLUE);
  tft.setTextSize(3);
  tft.print(F("MIN"));

  if (luxmin >= 1000.0) {
    tft.setCursor(132, 300);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(luxmin, 1);
    tft.print(F("lux"));
  } else {
    tft.setCursor(142, 300);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(luxmin, 1);
    tft.print(F("lux"));
  }

  tft.setCursor(15, 35);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("LUMINOSIDADE"));
  tft.setCursor(50, 60);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("AMBIENTE"));

  int xpos = 40, ypos = 90, gap = 100, radius = 80;                           // position of upper ring and proportion
  ringMeter (lux, 0, 3000, xpos, ypos, radius, "NSA-AI-003", GREEN2GREEN);     // draw analog mete

}


// ========================================================================================================
// FUNÇÃO PARA EXIBIR A VARIAVEL LUMINOSIDADE EXTERNA NO DISPLAY:
/*
  void lcd_ldr() {

  t = rtc.getTime();

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  tft.setCursor(8,10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118,10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163,10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL LDR EM %:

  float sensorL1 = analogRead(SensorLDR);
  ldr = map(sensorL1, 0, 1023, 0, 100);

   if (ldr < ldrmin)
    {
      ldrmin = ldr;
    }

    if (ldr > ldrmax)
    {
      ldrmax = ldr;
    }

  // ========================================================================================================
  // EXIBIÇÃO DA VARIAVEL LUMINOSIDADE:

  tft.setCursor(35,270);
  tft.setTextColor(RED);
  tft.setTextSize(3);
  tft.print(F("MAX"));
  tft.setCursor(22,300);
  tft.setTextSize(2);
  tft.setTextColor (WHITE);
  tft.print(ldrmax,1);
  tft.print(F("%"));


  tft.setCursor(154,270);
  tft.setTextColor(BLUE);
  tft.setTextSize(3);
  tft.print(F("MIN"));
  tft.setCursor(142,300);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(ldrmin,1);
  tft.print(F("%"));

  tft.setCursor(15,35);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("LUMINOSIDADE"));
  tft.setCursor(56,60);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("EXTERNA"));

   int xpos = 40, ypos = 90, gap = 100, radius = 80;                           // position of upper ring and proportion
   ringMeter (ldr,0,100, xpos,ypos,radius,"NSA-AI-006",GREEN2GREEN);           // draw analog mete

  }
*/

//========================================================================================================
// FUNÇÃO PARA EXIBIR A VARIAVEL TEMPERATURA DO SOLO NO DISPLAY:

void lcd_temp_solo() {

  rtc.begin();
  t = rtc.getTime();

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ================================================================================================/========
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  // ========================================================================================================
  // TRATAMENTO DA INDICAÇÃO DA VÁRIALVEL TEEMP_SOLO, CASO HAJA FALHA NO MÓDULO ELA INDICARÁ 25.0°C!!

  float temp_solo = thermocouple.readCelsius();
  String falha = " NAN";
  String temp_solo_falha = "";
  temp_solo_falha.concat(temp_solo);

  if (temp_solo_falha == falha) {
    temp_solo = 25.0;
  }

  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA TEMPERATURA DO SOLO: TERMOPAR

  if (thermocouple.readCelsius() < termoparMin)
  {
    termoparMin = thermocouple.readCelsius();
  }
  if (thermocouple.readCelsius() > termoparMax)
  {
    termoparMax = thermocouple.readCelsius();
  }

  // ========================================================================================================
  // EXIBIÇÃO DA VARIAVEL TEMPERATURA DO SOLO:

  tft.setCursor(35, 270);
  tft.setTextColor(RED);
  tft.setTextSize(3);
  tft.print(F("MAX"));
  tft.setCursor(26, 300);
  tft.setTextSize(2);
  tft.setTextColor (WHITE);
  tft.print(termoparMax, 1);
  tft.setTextSize(1);
  tft.setCursor(76, 300);
  tft.print(F("O"));
  tft.setCursor(83, 300);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(F("C"));

  tft.setCursor(154, 270);
  tft.setTextColor(BLUE);
  tft.setTextSize(3);
  tft.print(F("MIN"));

  tft.setCursor(146, 300);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(termoparMin, 1);
  tft.setTextSize(1);
  tft.setCursor(196, 300);
  tft.print(F("O"));
  tft.setCursor(203, 300);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(F("C"));

  tft.setCursor(20, 35);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("TEMPERATURA"));
  tft.setCursor(56, 60);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("DO SOLO"));

  int xpos = 40, ypos = 90, gap = 100, radius = 80;                           // position of upper ring and proportion
  ringMeter (temp_solo, 0, 40, xpos, ypos, radius, "NSA-TI-002", GREEN2RED);      // draw analog mete
}

// ========================================================================================================
// FUNÇÃO PARA EXIBIR A VARIAVEL UMIDADE DO SOLO P1 NO DISPLAY:

void umid_soloP1() {

  rtc.begin();
  t = rtc.getTime();

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL UMIDADE P1 DO SOLO EM %:

  for (int i = 0; i <= 200; i++) {
    sensorP1 = analogRead(SensorUmidadeP1);
    umidP1_analog = umidP1_analog + sensorP1;
  }

  // FILTRO PARA GARATIR UMA LEITURA MAIS ESTÁVEL COM 200 MEDIÇÕES:

  valorumidadeP1 = umidP1_analog / 200;

  //Serial.begin(9600);
  //Serial.print(valorumidadeP1);
  umidadeP1 = ((valorumidadeP1 - minimoP1) / (maximoP1 - minimoP1)) * 100;
  umidadeP1 = (umidadeP1 - 100) * -1;

  umidP1_analog = 0;
  valorumidadeP1 = 0;

  // LÓGICA DE PARA INDICAÇÃO DOS VALORES MÁXIMOS E MÍNIMOS:

  if (umidadeP1 < umSminP1)
  {
    umSminP1 = umidadeP1;
  }

  if (umidadeP1 > umSmaxP1)
  {
    umSmaxP1 = umidadeP1;
  }

  // FILTRO DE PARA INDICAÇÃO DOS LIMITES MÁXIMOS E MÍNIMOS:

  if (umidadeP1 <= 0) {
    umidadeP1 = 0.00;
  }

  if (umidadeP1 >= 100.00) {
    umidadeP1 = 99.9;
  }

  // ========================================================================================================
  // EXIBIÇÃO DA VARIAVEL UMIDADE DO SOLO:

  tft.setCursor(35, 240);
  tft.setTextColor(RED);
  tft.setTextSize(3);
  tft.print(F("MAX"));
  tft.setCursor(32, 270);
  tft.setTextSize(2);
  tft.setTextColor (WHITE);
  tft.print(umSmaxP1, 1);
  tft.print(F("%"));

  tft.setCursor(154, 240);
  tft.setTextColor(BLUE);
  tft.setTextSize(3);
  tft.print(F("MIN"));

  tft.setCursor(152, 270);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(umSminP1, 1);
  tft.print(F("%"));

  tft.setCursor(10, 35);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("UMIDADE"));
  tft.setCursor(145, 35);
  tft.print("SOLO");
  tft.setCursor(220, 35);
  tft.print(F("1"));

  int xpos = 40, ypos = 66, gap = 100, radius = 80;                                // position of upper ring and proportion
  ringMeter (umidadeP1, 0, 100, xpos, ypos, radius, "NSA-AI-001", GREEN2RED);      // draw analog mete

  tft.fillRect(0, 295, 240, 1, YELLOW);
  tft.fillRect(0, 319, 240, 1, YELLOW);


  if (umidadeP1 <= 30.00) {
    tft.setCursor(25, 300);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("SOLO: "));
    tft.setTextColor(YELLOW);
    tft.print(F("MUITO SECO"));
  }

  if ((umidadeP1 > 30.00) && (umidadeP1 <= 50.00)) {
    tft.setCursor(20, 300);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("SOLO: "));
    tft.setTextColor(GREENYELLOW);
    tft.print(F("POUCO UMIDO"));
  }

  if ((umidadeP1 > 50.00) && (umidadeP1 <= 65.00)) {
    tft.setCursor(22, 300);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("SOLO: "));
    tft.setTextColor(WHITE);
    tft.print(F("UMIDADE OK"));
  }
  if ((umidadeP1 > 65.00) && (umidadeP1 <= 75.00)) {
    tft.setCursor(20, 300);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("SOLO: "));
    tft.setTextColor(MAGENTA);
    tft.print(F("MUITO UMIDO"));
  }

  if (umidadeP1 > 75.00) {
    tft.setCursor(15, 300);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("SOLO: "));
    tft.setTextColor(RED);
    tft.print(F("ENCHARCADO!!"));
  }

}


// ========================================================================================================
// FUNÇÃO PARA EXIBIR A VARIAVEL UMIDADE DO SOLO P2 NO DISPLAY:

void umid_soloP2() {

  rtc.begin();
  t = rtc.getTime();

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL UMIDADE P1 DO SOLO EM %:

  //Serial.begin(9600);

  for (int i = 0; i <= 200; i++) {
    sensorP2 = analogRead(SensorUmidadeP2);
    umidP2_analog = umidP2_analog + sensorP2;
  }

  // FILTRO PARA GARATIR UMA LEITURA MAIS ESTÁVEL COM 200 MEDIÇÕES:

  valorumidadeP2 = umidP2_analog / 200;

  //Serial.begin(9600);
  //Serial.print(valorumidadeP2);

  umidadeP2 = ((valorumidadeP2 - minimoP2) / (maximoP2 - minimoP2)) * 100;
  umidadeP2 = (umidadeP2 - 100) * -1;

  umidP2_analog = 0;
  valorumidadeP2 = 0;


  // LÓGICA DE PARA INDICAÇÃO DOS VALORES MÁXIMOS E MÍNIMOS:

  if (umidadeP2 < umSminP2)
  {
    umSminP2 = umidadeP2;
  }

  if (umidadeP2 > umSmaxP2)
  {
    umSmaxP2 = umidadeP2;
  }

  // FILTRO DE PARA INDICAÇÃO DOS LIMITES MÁXIMOS E MÍNIMOS:

  if (umidadeP2 <= 0) {
    umidadeP2 = 0.00;
  }

  if (umidadeP2 >= 100.00) {
    umidadeP2 = 99.9;
  }

  // ========================================================================================================
  // EXIBIÇÃO DA VARIAVEL UMIDADE DO SOLO 2:

  tft.setCursor(35, 240);
  tft.setTextColor(RED);
  tft.setTextSize(3);
  tft.print(F("MAX"));

  tft.setCursor(32, 270);
  tft.setTextSize(2);
  tft.setTextColor (WHITE);
  tft.print(umSmaxP2, 1);
  tft.print(F("%"));

  tft.setCursor(154, 240);
  tft.setTextColor(BLUE);
  tft.setTextSize(3);
  tft.print(F("MIN"));

  tft.setCursor(152, 270);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(umSminP2, 1);
  tft.print(F("%"));

  tft.setCursor(10, 35);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("UMIDADE"));
  tft.setCursor(145, 35);
  tft.print(F("SOLO"));
  tft.setCursor(220, 35);
  tft.print(F("2"));

  int xpos = 40, ypos = 66, gap = 100, radius = 80;                           // position of upper ring and proportion
  ringMeter (umidadeP2, 0, 100, xpos, ypos, radius, "NSA-AI-002", GREEN2RED);      // draw analog mete

  tft.fillRect(0, 295, 240, 1, YELLOW);
  tft.fillRect(0, 319, 240, 1, YELLOW);


  if (umidadeP2 <= 30.00) {
    tft.setCursor(25, 300);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("SOLO: "));
    tft.setTextColor(YELLOW);
    tft.print(F("MUITO SECO"));
  }

  if ((umidadeP2 > 30.00) && (umidadeP2 <= 50.00)) {
    tft.setCursor(20, 300);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("SOLO: "));
    tft.setTextColor(GREENYELLOW);
    tft.print(F("POUCO UMIDO"));
  }

  if ((umidadeP2 > 50.00) && (umidadeP2 <= 65.00)) {
    tft.setCursor(22, 300);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("SOLO: "));
    tft.setTextColor(WHITE);
    tft.print(F("UMIDADE OK"));
  }
  if ((umidadeP2 > 65.00) && (umidadeP2 <= 75.00)) {
    tft.setCursor(20, 300);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("SOLO: "));
    tft.setTextColor(MAGENTA);
    tft.print(F("MUITO UMIDO"));
  }

  if (umidadeP2 > 75.00) {
    tft.setCursor(15, 300);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("SOLO: "));
    tft.setTextColor(RED);
    tft.print(F("ENCHARCADO!!"));
  }

}


// ========================================================================================================
// FUNÇÃO PARA EXIBIR A VARIAVEL PRECIPTAÇÃO/ORVALHO NO DISPLAY:

void lcd_preciptacao() {

  rtc.begin();
  t = rtc.getTime();
  //Serial.begin(9600);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL PRECIPTAÇÃO DE ORVALHO EM %:

  for (int i = 0; i <= 100; i++) {
    chuva_analog = analogRead(chuvaPIN);
    valor5 = valor5 + chuva_analog;
  }

  preciptacao1 = valor5 / 100;

  preciptacao = ((preciptacao1 - minimo2) / (maximo2 - minimo2)) * 100;
  preciptacao = (preciptacao - 100) * -1;
  valor5 = 0;
  preciptacao1 = 0;

  if (preciptacao < cpmin)
  {
    cpmin = preciptacao;
  }
  if (preciptacao > cpmax)
  {
    cpmax = preciptacao;
  }


  if (preciptacao <= 4.99) {
    preciptacao = 0.0;
  }

  if (preciptacao >= 100.00) {
    preciptacao = 99.9;
  }

  // ========================================================================================================
  // EXIBIÇÃO DA VARIAVEL PRECIPTAÇÃO:

  tft.setCursor(35, 270);
  tft.setTextColor(RED);
  tft.setTextSize(3);
  tft.print(F("MAX"));
  tft.setCursor(32, 300);
  tft.setTextSize(2);
  tft.setTextColor (WHITE);
  tft.print(cpmax, 1);
  tft.print(F("%"));

  tft.setCursor(154, 270);
  tft.setTextColor(BLUE);
  tft.setTextSize(3);
  tft.print(F("MIN"));

  tft.setCursor(152, 300);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(cpmin, 1);
  tft.print(F("%"));

  tft.setCursor(25, 35);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("PRESENCA DE"));
  tft.setCursor(60, 60);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("ORVALHO"));

  int xpos = 40, ypos = 90, gap = 100, radius = 80;                           // position of upper ring and proportion
  ringMeter (preciptacao, 0, 100, xpos, ypos, radius, "NSA-AI-004", GREEN2RED);      // draw analog mete

}

// ========================================================================================================
// FUNÇÃO PARA EXIBIR A VARIAVEL PRESSÃO ATMOSFÉRICA NO DISPLAY:

void lcd_pressao_atm() {

  rtc.begin();
  t = rtc.getTime();
  sensor_bmp.begin();

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA PRESSÃO ATMOSFÉRICA - MÓDULO BMP280:

  valor3 = 0;
  valorp = 0;

  for (int i = 0; i <= 100; i++) {
    valorp = sensor_bmp.readPressure();
    valor3 = valor3 + valorp;
  }

  p = valor3 / 100;
  p = p / 100;  // tranformando 1Pa em 1 mili Bar
  valor3 = 0;
  valorp = 0;

  float p10 = p;

  if (p < pMin)
  {
    pMin = p;
  }

  if (p > pMax)
  {
    pMax = p;
  }

  // ========================================================================================================
  // VARIAVEL DE INDICAÇÃO DE ALERA DE POSSIBILIDADE DE CHUVA (VALOR MAXIMO - VALOR MINIMO) > REFERENCIA: CHUVA!!

  float pa10 = pMax - pMin;

  // ========================================================================================================
  // EXIBIÇÃO DA VARIAVEL PRESSÃO ATM:

  tft.setCursor(35, 240);
  tft.setTextColor(RED);
  tft.setTextSize(3);
  tft.print(F("MAX"));
  tft.setCursor(10, 270);
  tft.setTextSize(2);
  tft.setTextColor (WHITE);
  tft.print(pMax, 1);
  tft.setTextSize(2);
  tft.setCursor(70, 270);
  tft.print(F("mBar"));

  tft.setCursor(154, 240);
  tft.setTextColor(BLUE);
  tft.setTextSize(3);
  tft.print(F("MIN"));

  tft.setCursor(130, 270);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(pMin, 1);
  tft.setTextSize(2);
  tft.setCursor(190, 270);
  tft.print(F("mBar"));

  tft.setCursor(40, 35);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("BAROMETRO"));

  int xpos = 40, ypos = 70, gap = 100, radius = 80;                           // position of upper ring and proportion
  ringMeter (p, 0, 1200, xpos, ypos, radius, "NSA-PI-001", GREEN2GREEN);      // draw analog mete

  tft.fillRect(0, 295, 240, 1, YELLOW);
  tft.fillRect(0, 319, 240, 1, YELLOW);

  if (pa10 <= 4.50 || pMin >= 918.00) {
    tft.setCursor(5, 300);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.print(F("SEM ALERTA DE CHUVA"));
  } else {
    tft.setCursor(30, 300);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.setTextColor(RED);
    tft.print(F("ALERTA DE CHUVA!"));
  }
}

// ========================================================================================================
// FUNÇÃO PARA EXIBIR A VARIAVEL ALTITUDE APROXIMADA NO DISPLAY:

void lcd_alt_atm() {

  rtc.begin();
  t = rtc.getTime();
  sensor_bmp.begin();

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA ALTITUDE - MÓDULO BMP280:

  valor2 = 0;
  valoralt = 0;

  for (int i = 0; i <= 100; i++) {
    valoralt = sensor_bmp.readAltitude(1013.25);
    valor2 = valor2 + valoralt;
  }

  alt = valor2 / 100;
  valor2 = 0;
  valoralt = 0;

  if (alt < altMin)
  {
    altMin = alt;
  }

  if (alt > altMax)
  {
    altMax = alt;
  }


  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA PRESSÃO ATMOSFÉRICA - MÓDULO BMP280:

  valor3 = 0;
  valorp = 0;

  for (int i = 0; i <= 100; i++) {
    valorp = sensor_bmp.readPressure();
    valor3 = valor3 + valorp;
  }

  p = valor3 / 100;
  p = p / 100;  // tranformando 1Pa em 1 mili Bar
  valor3 = 0;
  valorp = 0;

  float p10 = p;

  if (p < pMin)
  {
    pMin = p;
  }

  if (p > pMax)
  {
    pMax = p;
  }
  // ========================================================================================================
  // VARIAVEL DE INDICAÇÃO DE ALERA DE POSSIBILIDADE DE CHUVA (VALOR MAXIMO - VALOR MINIMO) > REFERENCIA: CHUVA!!

  float pa10 = pMax - pMin;

  // ========================================================================================================
  // EXIBIÇÃO DA VARIAVEL ALTITUDE:

  tft.setCursor(50, 35);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("ALTITUDE"));
  tft.setCursor(31, 60);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("APROXIMADA"));

  int xpos = 40, ypos = 90, gap = 100, radius = 80;                           // position of upper ring and proportion
  ringMeter (alt, 0, 1000, xpos, ypos, radius, "NSA-PI-002", GREEN2GREEN);      // draw analog mete

  tft.setCursor(5, 275);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(F(" PREVISAO DO TEMPO:"));

  tft.fillRect(0, 295, 240, 1, YELLOW);
  tft.fillRect(0, 319, 240, 1, YELLOW);

  if (pa10 <= 4.50 || pMin >= 918.00) {
    tft.setCursor(5, 300);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.print(F("SEM ALERTA DE CHUVA"));
  } else {
    tft.setCursor(30, 300);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.setTextColor(RED);
    tft.print(F("ALERTA DE CHUVA!"));
  }
}

// ========================================================================================================
// FUNÇÃO PARA EXIBIR A VARIAVEL VAZAÃO INSTANTANEA APROXIMADA NO DISPLAY:

void lcd_vazao() {

  estadoLED = true;                 // Seta o Estado do LED
  digitalWrite(LED, estadoLED);     // Seta o LED DA PLACA DOS SENSORES

  rtc.begin();
  t = rtc.getTime();

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  // ========================================================================================================
  // EXIBIÇÃO DA VARIAVEL VAZÃO INSTANTANEA LITROS/MIN:

  tft.setCursor(5, 35);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F(" VAZAO SAIDA "));

  volatile unsigned long Pulso_vazao = contaPulsotot;


  detachInterrupt(digitalPinToInterrupt(Pino));
  int xpos = 40, ypos = 66, gap = 100, radius = 80;                         // position of upper ring and proportion
  ringMeter (Litros, 0, 4000, xpos, ypos, radius, "NSA-FI-001", GREEN2GREEN);  // draw analog meter
  attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);

  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO DE VAZÃO:

  tft.fillRect(0, 240, 240, 1, YELLOW);

  tft.setCursor(5, 245);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("VAZAO:"));
  tft.setTextColor(WHITE);
  tft.print(vazao, 1);
  tft.print(F("L/min "));

  tft.fillRect(0, 265, 240, 1, YELLOW);
  tft.setCursor(5, 270);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("PULSOS EM 1SEG:"));
  tft.setTextColor(WHITE);
  tft.print(pulsos_vazao_seg);

  tft.fillRect(0, 290, 240, 1, YELLOW);

  tft.setCursor(5, 295);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("PULSOS:"));
  tft.setTextColor(WHITE);
  tft.print(Pulso_vazao);

  tft.fillRect(0, 315, 240, 1, YELLOW);

  //TEMPO PARA O PRÓXIMO ENVIO DE DADOS AOS SERVERS IOT;

  unsigned long atualiza_lcd;
  unsigned long atualiza_lcd2;

  atualiza_lcd = millis();
  atualiza_lcd2 = millis();
  //TempoLED = millis();

  while ((millis() - atualiza_lcd2 < 10000)) {

  //    //Verifica se o intervalo do Led Vermelho já foi atingido
  //    if (millis() - TempoLED >= IntervalolLED)
  //    {
  //      TempoLED = millis();
  //      estadoLED = !estadoLED;                 // Inverte o Estado do LED
  //      digitalWrite(LED, estadoLED);           // Seta o LED DA PLACA DOS SENSORES
  //    }

    //atualiza o display a cada 1 segundo com as informações da Vazão:
    if ((millis() - atualiza_lcd >= 1000)) {

      estadoLED = !estadoLED;                 // Inverte o Estado do LED
      digitalWrite(LED, estadoLED);           // Seta o LED DA PLACA DOS SENSORES
      
      detachInterrupt(digitalPinToInterrupt(Pino));
      atualiza_lcd = millis();

      Pulso_vazao = contaPulsotot;
      vazao = contaPulso_vazao / 0.45;  //Litros/min

      // Cálculo para o totalizador em Litros da vazão
      // MiliLitros = Q (l/min) / 60 (60segundos = 1 minuto)

      MiliLitros = vazao / 60;         // VARIAVEL PARA CONTABILIZAR ML ACUMULADA
      Litros = Litros + MiliLitros;    // Litros acumulados
      Litros_anterior = Litros;
      pulsos_vazao_seg = contaPulso_vazao;              // CONTA OS PULSOS GERADOS EM 1 SEGUNDO
      contaPulso_vazao = 0;

      int xpos = 40, ypos = 66, gap = 100, radius = 80;                            // position of upper ring and proportion
      ringMeter (Litros, 0, 4000, xpos, ypos, radius, "NSA-FI-001", GREEN2GREEN);  // draw analog meter

      estadoLED = !estadoLED;                 // Inverte o Estado do LED
      digitalWrite(LED, estadoLED);           // Seta o LED DA PLACA DOS SENSORES

      // ========================================================================================================
      // VARIAVEIS DE INDICAÇÃO DE VAZÃO:

      tft.setCursor(5, 245);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("VAZAO:"));
      tft.setTextColor(WHITE, BLACK);
      tft.print(vazao, 1);
      tft.print(F("L/min "));

      tft.setCursor(5, 270);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("PULSOS EM 1SEG:"));
      tft.setTextColor(WHITE, BLACK);
      tft.print(pulsos_vazao_seg);

      tft.setCursor(5, 295);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("PULSOS:"));
      tft.setTextColor(WHITE, BLACK);
      tft.print(Pulso_vazao);
      attachInterrupt(digitalPinToInterrupt(Pino), pulse, RISING);
    }

  }

}

// ========================================================================================================
// FUNÇÃO PARA EXIBIR A VARIAVEL PLUVIOMETRO NO DISPLAY:

void lcdpluv() {

  rtc.begin();
  t = rtc.getTime();

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  // ========================================================================================================
  // EXIBIÇÃO DA VARIAVEL VAZÃO INSTANTANEA:

  tft.setCursor(27, 35);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("PLUVIOMETRO"));
  tft.setCursor(64, 60);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("DIGITAL"));

  int xpos = 40, ypos = 90, gap = 100, radius = 80;                            // position of upper ring and proportion
  ringMeter (pluviometro, 0, 60, xpos, ypos, radius, "NSA-QI-001", GREEN2GREEN);      // draw analog meter

  tft.fillRect(0, 265, 240, 1, YELLOW);
  tft.setCursor(5, 270);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("ACUMULADO:"));
  tft.setTextColor(WHITE);
  tft.print(pluviometro_acum, 2);
  tft.print(F("mm"));

  tft.fillRect(0, 290, 240, 1, YELLOW);
  tft.setCursor(5, 295);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("PULSOS:"));
  tft.setTextColor(WHITE);
  tft.print(contaPulso1);
  tft.fillRect(0, 315, 240, 1, YELLOW);

}



// ========================================================================================================
// FUNÇÃO PARA CÁLCULO DO NÍVEL DO RESERVATÓRIO

void nivel_cx()  {

  //Serial.begin(9600);

  pinMode(pinVCC_Nivel, OUTPUT);           // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DE SENSORES
  pinMode(pinGND_Nivel, OUTPUT);           // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DE SENSORES

  digitalWrite(pinVCC_Nivel, true);        // aux VCC
  digitalWrite(pinGND_Nivel, false);       // aux GND

  delay(1000);
  Ultrasonic ultrasonic(12, 11); // 12 - CINZA ECHO // 11 - TRIGGER BRANCO
  distance = ultrasonic.read();
  //Serial.print(distance);

  // ========================================================================================================
  // TRATAMENTO DA INDICAÇÃO DA VÁRIALVEL NIVEL, CASO HAJA FALHA NO MÓDULO ELA INDICARÁ O CM!!

  if (distance == 357) {
    nivel = 0;
    nivelMin = -1;
  } else {
    nivel = altura_caixa - distance;
  }

  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DO SENSOR ULTRASSONICO:

  if (nivel < nivelMin)
  {
    nivelMin = nivel;
  }
  if (nivel > nivelMax)
  {
    nivelMax = nivel;
  }

  rtc.begin();
  t = rtc.getTime();

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA TEMPERATURA AMBIENTE DO SENSOR DTH22:

  tft.setCursor(35, 270);
  tft.setTextColor(RED);
  tft.setTextSize(3);
  tft.print(F("MAX"));
  tft.setCursor(25, 300);
  tft.setTextSize(2);
  tft.setTextColor (WHITE);
  tft.print(nivelMax, 1);
  tft.print(F("cm"));

  tft.setCursor(154, 270);
  tft.setTextColor(BLUE);
  tft.setTextSize(3);
  tft.print(F("MIN"));

  tft.setCursor(146, 300);
  tft.setTextColor (WHITE);
  tft.setTextSize(2);
  tft.print(nivelMin, 1);
  tft.print(F("cm"));

  tft.setCursor(20, 35);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F(" NIVEL DOS "));
  tft.setCursor(5, 60);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("RESERVATORIOS"));

  int xpos = 40, ypos = 90, gap = 100, radius = 80;                           // position of upper ring and proportion
  ringMeter (nivel, 0, 90, xpos, ypos, radius, "NSA-LI-001", GREEN2RED);      // draw analog meteR

}



// ========================================================================================================
// FUNÇÃO PARA CÁLCULO DO VOLUME DOS RESERVATÓRIOS:

void volume_cx()  {

  //Serial.begin(9600);

  pinMode(pinVCC_Nivel, OUTPUT);           // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DE SENSORES
  pinMode(pinGND_Nivel, OUTPUT);           // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DE SENSORES
  digitalWrite(pinVCC_Nivel, true);        // aux VCC
  digitalWrite(pinGND_Nivel, false);       // aux GND

  delay(1000);
  Ultrasonic ultrasonic(12, 11); // 12 - CINZA ECHO // 11 - TRIGGER BRANCO
  distance = ultrasonic.read();

  //Serial.print(distance);

  // ========================================================================================================
  // TRATAMENTO DA INDICAÇÃO DA VÁRIALVEL NIVEL, CASO HAJA FALHA NO MÓDULO ELA INDICARÁ O CM!!

  if (distance == 357) {
    volume_reservatorio = 0;
    volume_Min = 0;
  } else {
    nivel = altura_caixa - distance;
    volume_reservatorio = (((nivel * pi) / 3) * c_aux);
    volume_reservatorio = volume_reservatorio / 1000;
    volume_reservatorio = volume_reservatorio * 2;
  }

  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO DO VOLUME EM %:

  porcentagem_volume = ((volume_reservatorio / vol_total) * 100);

  // ========================================================================================================
  // REGISTRO DOS VALORES MÁXIMO E MÍNIMO DO VOLUME:

  if (volume_reservatorio < volume_Min)
  {
    volume_Min = volume_reservatorio;
  }

  if (volume_reservatorio > volume_Max)
  {
    volume_Max = volume_reservatorio;
  }

  //volume_res = volume_reservatorio;

  // ========================================================================================================

  rtc.begin();
  t = rtc.getTime();

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO DO VOLUME NO DISPLAY:

  tft.setCursor(30, 35);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("VOLUME DOS"));
  tft.setCursor(5, 60);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F("RESERVATORIOS"));

  int xpos = 40, ypos = 90, gap = 100, radius = 80;                                      // position of upper ring and proportion
  ringMeter (volume_reservatorio, 0, 4000, xpos, ypos, radius, "NSA-LI-002", GREEN2RED); // draw analog mete

  tft.fillRect(0, 270, 240, 1, YELLOW);
  tft.fillRect(0, 295, 240, 1, YELLOW);
  tft.fillRect(0, 319, 240, 1, YELLOW);

  tft.setCursor(3, 300);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("CAIXAS COM:"));
  tft.setTextColor(WHITE);
  tft.print(porcentagem_volume, 1);
  tft.print(F("%"));

  tft.setCursor(2, 275);
  tft.setTextColor(RED);
  tft.setTextSize(1);
  tft.print(F("VOLUME"));
  tft.setCursor(2, 285);
  tft.print(F(" MAX: "));

  tft.setCursor(45, 275);
  tft.setTextSize(2);
  tft.setTextColor (WHITE);
  tft.print(volume_Max, 0);
  tft.print(F("L"));

  tft.setCursor(122, 275);
  tft.setTextColor(BLUE);
  tft.setTextSize(1);
  tft.print(F("VOLUME"));
  tft.setCursor(122, 285);
  tft.print(F(" MIN: "));

  tft.setCursor(165, 275);
  tft.setTextSize(2);
  tft.setTextColor (WHITE);
  tft.print(volume_Min, 0);
  tft.print(F("L"));

}


// ========================================================================================================
// FUNÇÃO PARA EXIBIR O INDICE UV:

void Calcula_nivel_UV() {

  valor_sensorUV = analogRead(pino_sensorUV);

  //Serial.begin(9600);
  //Serial.println(valor_sensorUV);

  //Calcula tensao em milivolts
  int tensao = (valor_sensorUV * (5.0 / 1023.0)) * 1000;

  //Compara com valores tabela UV_Index
  if (tensao > 0 && tensao < 50)
  {
    UV_index = 0;
  }
  else if (tensao > 50 && tensao <= 227)
  {
    UV_index = 0;
  }
  else if (tensao > 227 && tensao <= 318)
  {
    UV_index = 1;
  }
  else if (tensao > 318 && tensao <= 408)
  {
    UV_index = 2;
  }
  else if (tensao > 408 && tensao <= 503)
  {
    UV_index = 3;
  }
  else if (tensao > 503 && tensao <= 606)
  {
    UV_index = 4;
  }
  else if (tensao > 606 && tensao <= 696)
  {
    UV_index = 5;
  }
  else if (tensao > 696 && tensao <= 795)
  {
    UV_index = 6;
  }
  else if (tensao > 795 && tensao <= 881)
  {
    UV_index = 7;
  }
  else if (tensao > 881 && tensao <= 976)
  {
    UV_index = 8;
  }
  else if (tensao > 976 && tensao <= 1079)
  {
    UV_index = 9;
  }
  else if (tensao > 1079 && tensao <= 1170)
  {
    UV_index = 10;
  }
  else if (tensao > 1170)
  {
    UV_index = 11;
  }

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  rtc.begin();
  t = rtc.getTime();
  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  // ========================================================================================================
  // CÁLCULO DE MÍNIMO E MÁXIMO DO INDICE UV:

  if (UV_index < UV_indexMin)
  {
    UV_indexMin = UV_index;
  }

  if (UV_index > UV_indexMax)
  {
    UV_indexMax = UV_index;
  }

  // EXIBIÇÃO DA VARIAVEL INDICE UV:

  tft.setCursor(35, 240);
  tft.setTextColor(RED);
  tft.setTextSize(3);
  tft.print(F("MAX"));

  tft.setCursor(35, 270);
  tft.setTextSize(2);
  tft.setTextColor (WHITE);
  tft.print(UV_indexMax, 0);
  tft.setTextSize(2);
  tft.print(F(" UV"));

  tft.setCursor(154, 240);
  tft.setTextColor(BLUE);
  tft.setTextSize(3);
  tft.print(F("MIN"));

  tft.setCursor(154, 270);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(UV_indexMin, 0);
  tft.setTextSize(2);
  tft.print(F(" UV"));

  tft.setCursor(27, 35);
  tft.setTextColor(CYAN);
  tft.setTextSize(3);
  tft.print(F(" INDICE UV "));

  //UV_index = 7,00;

  int xpos = 40, ypos = 70, gap = 100, radius = 80;                                // position of upper ring and proportion
  ringMeter (UV_index, 0, 11, xpos, ypos, radius, "NSA-AI-005", GREEN2RED);      // draw analog meter

  tft.fillRect(0, 295, 240, 1, YELLOW);
  tft.fillRect(0, 319, 240, 1, YELLOW);

  if (UV_index <= 3.00) {
    tft.setCursor(5, 300);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.print(F(" INDICE UV BAIXO!! "));
  }

  else if (UV_index > 3.00 && UV_index <= 5.00) {
    tft.setCursor(5, 300);
    tft.setTextSize(2);
    tft.setTextColor(YELLOW);
    tft.print(F(" USE FILTRO SOLAR!!"));
  }

  else if (UV_index > 5.00 && UV_index <= 7.00) {
    tft.setCursor(5, 300);
    tft.setTextSize(2);
    tft.setTextColor(ORANGE);
    tft.print(F("EVITE FICAR AO SOL!"));
  }

  else if (UV_index > 7.00 && UV_index <= 11.00) {
    tft.setCursor(5, 300);
    tft.setTextSize(2);
    tft.setTextColor(RED);
    tft.print(F("EVITE FICAR AO SOL!"));
  }


}


// ========================================================================================================
// FUNÇÃO PARA A TELA DE DISGNÓSTICO DAS VARIAVEIS:

void d1() {

  tft.fillRect(0, 0, 240, 320, BLACK);
  sensor_bmp.begin();
  //SerialGSM.begin();

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  rtc.begin();
  t = rtc.getTime();
  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  float bmp_temp = sensor_bmp.readTemperature();
  float t_ds = rtc.getTemp();


  // ========================================================================================================
  // EXIBIÇÃO DAS VARIÁVEIS:

  tft.fillRect(0, 31, 240, 1, YELLOW);
  tft.fillRect(0, 32, 240, 40, RED);

  tft.setCursor(22, 40);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(F("DIAGNOSTICO"));
  tft.fillRect(0, 70, 240, 1, YELLOW);

  /*
      uint8_t  chargeState   = 0;
      int8_t   chargePercent = 0;
      uint16_t milliVolts    = 0;*/

  modemGSM.getBattStats(chargeState, chargePercent, milliVolts);

  tft.setCursor(5, 75);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("BAT:"));
  tft.setCursor(55, 75);
  tft.setTextColor(WHITE);

  //voltage =< 3,5 under voltage warning
  //voltage => 4,3 over voltage warning
  //voltage < 3,4 under voltage power down
  //voltage > 4,4 under voltage power down

  if (milliVolts <= 3500 || milliVolts >= 4300) {
    tft.setTextColor(ORANGE);
  }
  tft.print(milliVolts);
  tft.print(F(" miliVolts"));


  tft.fillRect(0, 95, 240, 1, YELLOW);

  int ss = modemGSM.getSignalQuality();
  tft.setCursor(5, 100);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("SINAL:"));

  if ( ss >= 31) {
    tft.setTextColor(RED);
  }

  if ( ss <= 30 && ss >= 20) {
    tft.setTextColor(WHITE);
  }
  if ( ss <= 19 && ss >= 15) {
    tft.setTextColor(WHITE);
  }
  if ( ss < 15 && ss >= 10) {
    tft.setTextColor(YELLOW);
  }
  if ( ss < 10) {
    tft.setTextColor(RED);
  }
  tft.print(ss);

  if ( ss >= 31) {
    tft.print(F("EM FALHA!"));
  }

  if ( ss <= 30 && ss >= 20 ) {
    tft.print(F("-Excelente"));
  }
  if ( ss <= 19 && ss >= 15) {
    tft.print(F(" (Otimo)"));
  }
  if ( ss < 15 && ss >= 10) {
    tft.print(F(" (Bom)"));
  }
  if ( ss < 10) {
    tft.print(F(" (Fraco)"));
  }

  tft.fillRect(0, 120, 240, 1, YELLOW);

  tft.setCursor(5, 125);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("TEMP. BMP280:"));
  tft.setTextColor(WHITE);
  tft.print(bmp_temp, 1);
  tft.setCursor(210, 125);
  tft.setTextSize(1);
  tft.print(F("O"));
  tft.setCursor(218, 125);
  tft.setTextSize(2);
  tft.print(F("C"));

  tft.fillRect(0, 145, 240, 1, YELLOW);

  tft.setCursor(5, 150);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("TEMP. DS3231:"));
  tft.setTextColor(WHITE);
  tft.print(t_ds, 1);
  tft.setCursor(210, 150);
  tft.setTextSize(1);
  tft.print(F("O"));
  tft.setCursor(218, 150);
  tft.setTextSize(2);
  tft.print(F("C"));

  tft.fillRect(0, 170, 240, 1, YELLOW);

  // ========================================================================================================
  // EXIBE A QUANTIDADE DE SMS ENVIADOS:

  tft.setCursor(5, 175);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("SMS SEND:"));
  tft.setTextColor(WHITE);
  tft.print(msg_sms_env);

  tft.fillRect(0, 195, 240, 1, YELLOW);

  // ========================================================================================================
  // EXIBE A QUANTIDADE DE SMS RECEBIDOS:

  tft.setCursor(5, 200);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("SMS RECEBIDOS:"));
  tft.setTextColor(WHITE);
  tft.print(msg_sms_rec);

  tft.fillRect(0, 220, 240, 1, YELLOW);

  // ========================================================================================================
  // EXIBE A QUANTIDADE DE VEZES QUE FOI GRAVADO DADOS NO SD CARD:

  tft.setCursor(5, 225);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("DADOS SD CARD:"));
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(msg_sdcard_ok);

  tft.fillRect(0, 245, 240, 1, YELLOW);

  // ========================================================================================================
  // EXIBE A QUANTIDADE DE VEZES QUE HOUVE FALHA NA GRAVAÇÃO DOS DADOS NO SD CARD:

  tft.setCursor(5, 250);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("FALHA SD CARD:"));
  tft.setTextColor(WHITE);
  tft.print(msg_sdcard_nok);

  tft.fillRect(0, 270, 240, 1, YELLOW);

  // ========================================================================================================
  // EXIBE A QUANTIDADE DE VEZES QUE NÃO HOUVE FALHA NA CONFIGURAÇÃO SMS:

  tft.setCursor(5, 275);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("MODO SMS OK:"));
  tft.setTextColor(WHITE);
  tft.print(configuraGSM_ok);

  tft.fillRect(0, 295, 240, 1, YELLOW);

  // ========================================================================================================
  // EXIBE A QUANTIDADE DE VEZES QUE HOUVE FALHA NA CONFIGURAÇÃO SMS:

  tft.setCursor(5, 300);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("FALHA MODO SMS:"));
  tft.setTextColor(WHITE);
  tft.print(configuraGSM_nok);

  tft.fillRect(0, 320, 240, 1, YELLOW);

}

// ========================================================================================================
// FUNÇÃO PARA A TELA DE DISGNÓSTICO DAS VARIAVEIS:

void d2() {

  tft.fillRect(0, 0, 240, 320, BLACK);
  //SerialGSM.begin();

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  rtc.begin();
  t = rtc.getTime();
  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  // ========================================================================================================
  // EXIBIÇÃO DAS VARIÁVEIS:

  tft.fillRect(0, 31, 240, 1, YELLOW);
  tft.fillRect(0, 32, 240, 40, RED);

  tft.setCursor(22, 40);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(F(" RELATORIO "));
  tft.fillRect(0, 70, 240, 1, YELLOW);

  tft.setCursor(5, 75);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("UBIDOTS NSAGRO-V0"));
  tft.setTextColor(WHITE);
  tft.setCursor(5, 100);
  tft.print(F("SEND:"));
  tft.print(msg_counterok);
  tft.setCursor(125, 100);
  tft.print(F("FALHA:"));
  tft.print(msg_counternok);

  tft.fillRect(0, 120, 240, 1, YELLOW);

  tft.setCursor(5, 125);
  tft.setTextColor(CYAN);
  tft.print(F("UBIDOTS NSAGRO-V1"));
  tft.setTextColor(WHITE);
  tft.setCursor(5, 150);
  tft.print(F("SEND:"));
  tft.print(msg_counterok1);
  tft.setCursor(125, 150);
  tft.print(F("FALHA:"));
  tft.print(msg_counternok1);

  tft.fillRect(0, 170, 240, 1, YELLOW);


  tft.fillRect(0, 220, 240, 1, YELLOW);

  tft.setCursor(5, 175);
  tft.setTextColor(CYAN);
  tft.print(F("ENVIO IoT: "));
  tft.setCursor(125, 175);
  tft.setTextColor(WHITE, BLACK);

  atual30 = millis();
  intervalo30 = 900000;   
  t_send = (900 - ((atual30 - anterior30) / 1000));

  tft.print(t_send);
  tft.print(F("seg."));

  //TEMPO PARA O PRÓXIMO ENVIO DE DADOS AOS SERVERS IOT;

  unsigned long atualiza_lcd;
  unsigned long atualiza_lcd2;


  atualiza_lcd = millis();
  atualiza_lcd2 = millis();
  TempoLED = millis();

  while (millis() - atualiza_lcd2 < 10000) {

    if (millis() - atualiza_lcd >= 1000) {
      atualiza_lcd = millis();
      tft.setCursor(125, 175);
      tft.setTextColor(WHITE, BLACK);

      atual30 = millis();
      intervalo30 = 900000;   //intervalo30 = 1200000; 1200000;
      t_send = (900 - ((atual30 - anterior30) / 1000)); //t_send = (1200 -((atual30-anterior30)/1000));

      tft.print(t_send);
      tft.print(F("seg. "));

    }

    //Verifica se o intervalo do Led Vermelho já foi atingido
    if (millis() - TempoLED >= IntervalolLED)
    {
      TempoLED = millis();
      estadoLED = !estadoLED;                 // Inverte o Estado do LED
      digitalWrite(LED, estadoLED);           // Seta o LED DA PLACA DOS SENSORES
    }
  }
}

// ========================================================================================================
// FUNÇÃO PARA A TELA DE DISGNÓSTICO DAS VARIAVEIS:

void d3() {

  tft.fillRect(0, 0, 240, 320, BLACK);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  rtc.begin();
  t = rtc.getTime();
  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  // ========================================================================================================
  // EXIBIÇÃO DAS VARIÁVEIS:

  tft.fillRect(0, 31, 240, 1, YELLOW);
  tft.fillRect(0, 32, 240, 40, RED);

  tft.setCursor(22, 40);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(F(" RELATORIO "));
  tft.fillRect(0, 70, 240, 1, YELLOW);

  tft.setCursor(0, 75);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("THINGSPEAK NSAGRO-P0"));
  tft.setTextColor(WHITE);
  tft.setCursor(5, 100);
  tft.print(F("SEND:"));
  tft.print(msg_counterok_t2);
  tft.setCursor(125, 100);
  tft.print(F("FALHA:"));
  tft.print(msg_counternok_t2);

  tft.fillRect(0, 120, 240, 1, YELLOW);

  tft.setCursor(0, 125);
  tft.setTextColor(CYAN);
  tft.print(F("THINGSPEAK NSAGRO-V0"));
  tft.setTextColor(WHITE);
  tft.setCursor(5, 150);
  tft.print(F("SEND:"));
  tft.print(msg_counterok_t);
  tft.setCursor(125, 150);
  tft.print(F("FALHA:"));
  tft.print(msg_counternok_t);

  tft.fillRect(0, 170, 240, 1, YELLOW);

  tft.setCursor(0, 175);
  tft.setTextColor(CYAN);
  tft.print(F("THINGSPEAK NSAGRO-V1"));
  tft.setTextColor(WHITE);
  tft.setCursor(5, 200);
  tft.print(F("SEND:"));
  tft.print(msg_counterok_t1);
  tft.setCursor(125, 200);
  tft.print(F("FALHA:"));
  tft.print(msg_counternok_t1);

  tft.fillRect(0, 220, 240, 1, YELLOW);
  tft.fillRect(0, 270, 240, 1, YELLOW);

  tft.setCursor(5, 225);
  tft.setTextColor(CYAN);
  tft.print(F("ENVIO IoT: "));
  tft.setCursor(125, 225);
  tft.setTextColor(WHITE, BLACK);

  atual30 = millis();
  intervalo30 = 900000;   
  t_send = (900 - ((atual30 - anterior30) / 1000)); 

  tft.print(t_send);
  tft.print(F("seg."));

  //TEMPO PARA O PRÓXIMO ENVIO DE DADOS AOS SERVERS IOT;

  unsigned long atualiza_lcd;
  unsigned long atualiza_lcd2;

  atualiza_lcd = millis();
  atualiza_lcd2 = millis();
  TempoLED = millis();

  while (millis() - atualiza_lcd2 < 10000) {
    if (millis() - atualiza_lcd >= 1000) {
      atualiza_lcd = millis();
      tft.setCursor(125, 225);
      tft.setTextColor(WHITE, BLACK);

      atual30 = millis();
      intervalo30 = 900000;   
      t_send = (900 - ((atual30 - anterior30) / 1000));

      tft.print(t_send);
      tft.print(F("seg. "));

    }

    //Verifica se o intervalo do Led Vermelho já foi atingido
    if (millis() - TempoLED >= IntervalolLED)
    {
      TempoLED = millis();
      estadoLED = !estadoLED;                 // Inverte o Estado do LED
      digitalWrite(LED, estadoLED);           // Seta o LED DA PLACA DOS SENSORES
    }
  }
}







void d4() {

  tft.fillRect(0, 0, 240, 320, BLACK);

  bool resete_maxmin = false;
  bool resete = true;

  // ========================================================================================================
  // VARIAVEIS DE REGISTRO DE VALORES MÁXIMOS E MÍNIMOS QUE SERÃO RESETADAS:

  if (resete == true) {

    //========================================================================================================
    // Contagem de vezes que houver falha no envio das mensagens aos Servidores IoT:
    msg_counternok_resete = 0; //msg não enviada Ubidots 0
    msg_counternok1_resete = 0; //msg não enviada Ubidots 1
    msg_counternok_t_resete = 0; // msg não enviada ThingSpeak 0
    msg_counternok_t1_resete = 0; // msg não enviada ThingSpeak 1
    msg_counternok_t2_resete = 0; // msg não enviada ThingSpeak 2
    configuraGSM_nok_resete = 0; // GSM não Ok(resete)
    configuraGSM_nok = 0; // GSM não ok (SMS envio)
    
    t1MaxDHT22 = -100.00;
    t1MinDHT22 = 100.00;
    UmaxDHT22 = -100.00;
    UminDHT22 = 100.00;

    luxmax = -1500.00;
    luxmin = 1500.00;
    termoparMax = -100.00;
    termoparMin = 100.00;

    umSmaxP1 = -100.00;
    umSminP1 = 100.00;
    umSmaxP2 = -100.00;
    umSminP2 = 100.00;

    pMax = -1000.00;
    pMin = 1000.00;
    sms_prev_chuva = true;

    altMax = -1500, 00;
    altMin = 1500, 00;

    MiliLitros = 0.00;
    Litros = 0.00;
    contaPulsotot = 0;

    nivelMax = -100.00;
    nivelMin = 100.00;
    volume_Max = -9000;
    volume_Min = 9000;

    UV_indexMax = -100.00;
    UV_indexMin = 100.00;

    t1_int_Max = -100.00;
    t1_int_Min = 100.00;

    cpmin = 100.00;
    cpmax = -100.00;
    dewPointMax = -100.00;
    dewPointMin = 100.00;

    resete_maxmin = true;
    resete = false;
  }


  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  rtc.begin();
  t = rtc.getTime();
  tft.setCursor(8, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  char const divider = '/';
  tft.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  tft.setCursor(118, 10);
  tft.print(rtc.getDOWStr(FORMAT_SHORT));

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  tft.setCursor(163, 10);
  tft.print(rtc.getTimeStr(FORMAT_SHORT));
  tft.print(F("h"));

  // ========================================================================================================
  // EXIBIÇÃO DAS VARIÁVEIS:

  tft.fillRect(0, 31, 240, 1, YELLOW);
  tft.fillRect(0, 32, 240, 40, RED);

  tft.setCursor(32, 40);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(F("  RESETE  "));
  delay(1000);

  tft.fillRect(0, 70, 240, 1, YELLOW);
  tft.fillRect(0, 95, 240, 1, YELLOW);
  tft.setCursor(5, 75);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("VALORES MAX:"));
  tft.setTextColor(WHITE);
  if (resete_maxmin == true) {
    delay(1500);
    tft.print(F(" OK"));
  } else {
    delay(1500);
    tft.setTextColor(YELLOW);
    tft.print(F(" NOK"));
  }

  delay(1000);

  tft.fillRect(0, 120, 240, 1, YELLOW);
  tft.setCursor(5, 100);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("VALORES MIN:"));
  tft.setTextColor(WHITE);
  if (resete_maxmin == true) {
    delay(1500);
    tft.print(F(" OK"));
  } else {
    delay(1500);
    tft.setTextColor(YELLOW);
    tft.print(F(" NOK"));
  }

}



/********************************************************************************************************/
// ========================================================================================================
// FUNÇÕES DE TESTE E GRAVAÇÃO DO SD CARD:
/********************************************************************************************************/

// ========================================================================================================
// FUNÇÃO DE SETUP DO SD CARD:

void sd_card_setup() {

  Sd2Card card;
  SdVolume volume;
  uint32_t volumesize;
  File root;

  tft.fillScreen(BLACK);

  tft.fillRoundRect(10, 5, 220, 70, 15, RED);
  tft.drawRoundRect(10, 5, 220, 70, 15, WHITE);
  tft.setCursor(76, 15);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(F("SETUP"));
  tft.setCursor(59, 43);
  tft.print(F("SD CARD"));

  delay(1000);

  tft.drawRect(0, 90, 240, 40, YELLOW);
  tft.setCursor(8, 95);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("ANALISANDO SD CARD:"));
  delay(500);
  tft.fillRect(0, 118, 60, 6, GREEN);
  delay(800);
  tft.fillRect(0, 118, 100, 6, GREEN);
  delay(1200);
  tft.fillRect(0, 118, 140, 6, GREEN);
  delay(1500);
  tft.fillRect(0, 118, 180, 6, GREEN);
  delay(1800);
  tft.fillRect(0, 118, 200, 6, GREEN);
  delay(1700);
  tft.fillRect(0, 118, 240, 6, GREEN);
  delay(1900);

  // Testando conexão com o SD Card!
  int pino53 = 53;
  pinMode(pino53, OUTPUT);
  delay(500);
  SD.begin(pino53);
  delay(500);

  if (!SD.begin(pino53)) {
    tft.fillRect(0, 130, 240, 36, YELLOW);
    tft.setCursor(55, 140);
    tft.setTextColor(RED);
    tft.setTextSize(2);
    tft.print(F("SEM SD CARD!"));
    delay(5000);
    return;
  } else {
    tft.drawRect(0, 128, 240, 36, YELLOW);
    tft.setCursor(14, 138);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("SD Card Detectado!"));
    delay(2500);
  }

  tft.setCursor(5, 180);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("INFORMACAO SD CARD:"));
  delay(1000);
  tft.drawRect(0, 205, 240, 105, YELLOW);

  card.init(SPI_HALF_SPEED, pino53);

  // VERIFICANDO TIPO DO CARTÃO SD:
  tft.setCursor(5, 210);
  tft.setTextColor(CYAN);
  tft.print(F("SD Card tipo: "));
  tft.setTextColor(WHITE);

  switch (card.type()) {
    case SD_CARD_TYPE_SD1:
      tft.print("SD1");
      break;
    case SD_CARD_TYPE_SD2:
      tft.print("SD2");
      break;
    case SD_CARD_TYPE_SDHC:
      tft.print("SDHC");
      break;
    default:
      tft.print("");
  }
  delay(500);

  // Testando Partição: FAT16 ou FAT32
  tft.setCursor(5, 230);
  
  if (!volume.init(card)) {
    tft.setTextColor(RED);
    tft.print("Error FAT16/FAT32");
  
  // Exibindo o tipo FAT  
  } else {
    tft.setTextColor(CYAN);
    tft.print("Arquivo tipo: ");
    tft.setTextColor(WHITE);
    tft.print("FAT");
    tft.print(volume.fatType(), DEC);
  }
  delay(500);

  // Exibindo o tamanho do SD Card:
  tft.setCursor(5, 250);
  volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
  volumesize *= volume.clusterCount();       // we'll have a lot of clusters
  volumesize /= 2;                           // SD card blocks are always 512 bytes (2 blocks are 1KB)
  volumesize /= 1024;
  vol_kb = volumesize;
  tft.setTextColor(CYAN);
  tft.print("Volume: ");
  tft.setTextColor(WHITE);
  tft.print((float)volumesize / 1024.0);
  tft.print(" Gbytes");

  delay(500);

  tft.setCursor(5, 270);
  tft.setTextColor(CYAN);
  tft.print("N. Clusters: ");
  tft.setTextColor(WHITE);
  tft.println(volume.clusterCount());

  delay(500);

  tft.setCursor(5, 290);
  tft.setTextColor(CYAN);
  tft.print("N. Blocks: ");
  tft.setTextColor(WHITE);
  tft.println(volume.blocksPerCluster() * volume.clusterCount());
  root.close();
  delay(5000);

}


// ========================================================================================================
// FUNÇÃO PARA TESTAR A GRAVAÇÃO DE ARQUIVOS NO CARTÃO SD CARD:

void sd_card_testegravacao() {

  rtc.begin();
  t = rtc.getTime();

  tft.fillScreen(BLACK);

  tft.fillRoundRect(10, 5, 220, 70, 15, RED);
  tft.drawRoundRect(10, 5, 220, 70, 15, WHITE);
  tft.setCursor(76, 15);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(F("SETUP"));
  tft.setCursor(59, 43);
  tft.print(F("SD CARD"));

  tft.drawRect(0, 90, 240, 40, YELLOW);
  tft.setCursor(13, 95);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("TESTANDO GRAVACAO:"));

  delay(1800);
  tft.fillRect(0, 118, 60, 6, GREEN);
  delay(1600);
  tft.fillRect(0, 118, 100, 6, GREEN);
  delay(1400);
  tft.fillRect(0, 118, 140, 6, GREEN);
  delay(1200);
  tft.fillRect(0, 118, 180, 6, GREEN);
  delay(1000);
  tft.fillRect(0, 118, 200, 6, GREEN);
  delay(800);
  tft.fillRect(0, 118, 240, 6, GREEN);
  delay(500);

  delay(1000);

  // ========================================================================================================
  // ROTINA DE REVERIFICAÇÃO DO FUNCIONAMENTO DO SD CARD:

  File myFile;
  int pino53 = 53;
  pinMode(pino53, OUTPUT);

  delay(500);
  SD.begin(pino53);
  delay(500);
  myFile = SD.open("SETUP.txt", FILE_WRITE);  // ABRE E GERA ARQUIVO LEITURA
  delay(500);
  if (myFile) {
    myFile.print(F("NANO SMART AGRO - SETUP SD CARD OK!"));                 // GRAVA "TESTE OK" NO ARQUIVO LEITURA DO SD CARD
    myFile.print(F(" DATA: "));
    myFile.print(t.date, DEC);
    myFile.print(F("/"));
    myFile.print(t.mon, DEC);
    myFile.print(F("/"));
    myFile.print(t.year, DEC);
    myFile.print(F(";"));
    myFile.print(F(" HORARIO: "));
    myFile.print(rtc.getTimeStr());
    myFile.println(F(" "));

    tft.drawRect(0, 128, 240, 34, YELLOW);
    tft.setCursor(14, 136);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("GRAVACAO CONCLUIDA"));

    delay(2000);
    myFile.close();

    tft.setCursor(5, 175);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.print(F("SETUP FINALIZADO EM"));

    tft.drawRect(0, 195, 240, 67, YELLOW);
    tft.setCursor(14, 200);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("DATA: "));
    char const divider = '/';
    tft.print(rtc.getDateStr(FORMAT_LONG, FORMAT_LITTLEENDIAN, divider));
    tft.setCursor(14, 220);
    tft.print(F("HORARIO: "));
    tft.print(rtc.getTimeStr());
    tft.setCursor(14, 240);
    tft.print(F("DIA: "));
    tft.print(rtc.getDOWStr());
    delay(10000);

  // SE HOUVER ERRO PARA ABRIR O ARQUIVO, IRÁ INDICAR NO DISPLAY
  } else {
    tft.fillRect(0, 130, 240, 34, YELLOW);
    tft.setCursor(5, 136);
    tft.setTextColor(RED);
    tft.setTextSize(2);
    tft.print(F("ERRO AO GRAVAR DADO"));
    delay(2500);
    return;
  }

}

// ========================================================================================================
// FUNÇÃO PARA EXIBIR OS ARQUIVOS PRESENTES NO SD CARD:

void printDirectory(File dir, int numTabs) {

  int arquivos = 0;
  int pino53 = 53;
  pinMode(pino53, OUTPUT);
  int arq = 0;
  uint32_t tamanho [9];
  tamanho[0] = 0;
  tamanho[1] = 0;
  tamanho[2] = 0;
  tamanho[3] = 0;
  tamanho[4] = 0;
  tamanho[5] = 0;
  tamanho[6] = 0;
  tamanho[7] = 0;
  tamanho[8] = 0;
  tamanho[9] = 0;

  uint32_t tamanho_soma = 0;

  delay(500);
  SD.begin(pino53);
  delay(500);

  while (true)
  {
    File entry = dir.openNextFile();
    if (!entry)
    {
      if (numTabs == 0)

      tft.setTextSize(1);
      tft.setTextColor(WHITE);
      tft.println(" ");
      tft.print("   ****  Numero de Arquivos: ");
      tft.print(arquivos);
      tft.print("  ****");
      tft.println(" ");
      tft.println("----------------------------------------");
      tft.println(" ");

      tft.setTextColor(CYAN);
      tft.print("  Tamanho: ");
      tft.setTextColor(WHITE);

      tamanho_soma = ( (tamanho[0])  + (tamanho[1]) + (tamanho[2])  + (tamanho[3]) + (tamanho[4])  + (tamanho[5]) + (tamanho[6]) + (tamanho[7]) + (tamanho[8]) + (tamanho[9]));
      tamanho_soma = tamanho_soma / 1024;
      tamanho_soma = tamanho_soma / 1000; // transformando em MB o valor dos arquivos!

      tft.print(tamanho_soma, DEC);
      tft.print("Mb ");

      tft.setTextColor(CYAN);
      tft.print("  Espaco Livre: ");
      tft.setTextColor(WHITE);

      tamanho_soma = vol_kb - tamanho_soma;  // CÁLCULO DO ESPAÇO LIVRE EM MB!! (PUXA INFORMAÇÃO DO SETUP DE INFORMAÇÕES DO CARTÃO!!)

      tft.print(tamanho_soma, DEC);
      tft.print("Mb");

      entry.close();
      root.close();
      delay(10000);
      
      return;
      
    }

    tft.setTextSize(1);
    tft.setTextColor(CYAN);
    tft.print(" Nome: ");
    tft.setTextColor(WHITE);
    tft.println(entry.name());
    tft.setTextColor(CYAN);
    tft.print(" Tamanho: ");

    tamanho[arq] = {(entry.size())};
    arq ++;

    tft.setTextColor(WHITE);
    tft.print(entry.size(), DEC);
    tft.println("Kb");
    tft.println("----------------------------------------");
    arquivos++;
    entry.close();
  }
}


// ========================================================================================================
// FUNÇÃO PARA GRAVAÇÃO DOS DADOS NO SD CARD:

void teste_Sd() {

  rtc.begin();
  delay(1000);
  t = rtc.getTime();

  File myFile;

  tft.fillRoundRect(20, 55, 200, 210, 15, RED);
  tft.drawRoundRect(20, 55, 200, 210, 15, WHITE);

  tft.setCursor(25, 80);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.print(F("SALVANDO"));
  tft.setCursor(25, 145);
  tft.print(F("DADOS NO"));
  tft.setCursor(38, 210);
  tft.print(F("SD CARD"));

  int pino53 = 53;
  pinMode(pino53, OUTPUT);

  delay(500);
  SD.begin(pino53);
  delay(500);

  if (myFile = SD.open("SETUP.txt", FILE_WRITE)) {

    // ========================================================================================================
    // GRAVAÇÃO DOS DADOS DE DIA DA SEMANA, HORÁRIO E DATA.
    myFile.print(F("TESTE GRAVACAO NO SD CARD OK"));
    myFile.print(F(";"));
    myFile.print(F(" DATA: "));
    myFile.print(t.date, DEC);
    myFile.print(F("/"));
    myFile.print(t.mon, DEC);
    myFile.print(F("/"));
    myFile.print(t.year, DEC);
    myFile.print(F(";"));

    myFile.print(F(" DIA: "));
    myFile.print(rtc.getDOWStr());
    myFile.print(F(", "));
    myFile.print(t.date, DEC);
    myFile.print(F(" de "));
    myFile.print(rtc.getMonthStr());
    myFile.print(F(" de "));
    myFile.print(t.year, DEC);
    myFile.print(F(";"));
    myFile.print(F(" HORARIO: "));
    myFile.print(rtc.getTimeStr());
    myFile.print(F(";"));

    myFile.println();
    delay(1000);
    myFile.close();
    delay(1000);

    SD.end();

    tft.fillRoundRect(0, 275, 240, 25, 10, RED);
    tft.drawRoundRect(0, 275, 240, 25, 10, WHITE);
    tft.setCursor(50, 280);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("GRAVACAO OK!"));
    delay(1000);

    // SE HOUVER ERRO PARA ABRIR O ARQUIVO, IRÁ INDICAR NO DISPLAY
  } else {
    msg_sdcard_nok++;
    tft.fillRoundRect(0, 275, 240, 25, 10, YELLOW);
    tft.drawRoundRect(0, 275, 240, 25, 10, RED);
    tft.setCursor(5, 280);
    tft.setTextColor(RED);
    tft.setTextSize(2);
    tft.print(F("DADOS NAO GRAVADOS!"));
    delay(1000);
  }

}




// ========================================================================================================
// FUNÇÃO PARA GRAVAÇÃO DOS DADOS NO SD CARD:

void gravadadosSd() {

  dht1.begin();
  sensor_bmp.begin();
  rtc.begin();
  t = rtc.getTime();
  dht2.begin();

  delay(1000);

  File myFile;

  tft.fillRoundRect(20, 55, 200, 210, 15, RED);
  tft.drawRoundRect(20, 55, 200, 210, 15, WHITE);

  tft.setCursor(25, 80);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.print(F("SALVANDO"));
  tft.setCursor(25, 145);
  tft.print(F("DADOS NO"));
  tft.setCursor(38, 210);
  tft.print(F("SD CARD"));

  int pino53 = 53;
  pinMode(pino53, OUTPUT);

  delay(500);
  SD.begin(pino53);
  delay(500);

  if (myFile = SD.open("leitura.txt", FILE_WRITE)) {

    // ========================================================================================================
    // GRAVAÇÃO DOS DADOS DE DIA DA SEMANA, HORÁRIO E DATA.

    myFile.print(F("DATA: "));
    myFile.print(t.date, DEC);
    myFile.print(F("/"));
    myFile.print(t.mon, DEC);
    myFile.print(F("/"));
    myFile.print(t.year, DEC);
    myFile.print(F(";"));

    myFile.print(F(" DATA: "));
    myFile.print(rtc.getDOWStr());
    myFile.print(F(", "));
    myFile.print(t.date, DEC);
    myFile.print(F(" de "));
    myFile.print(rtc.getMonthStr());
    myFile.print(F(" de "));
    myFile.print(t.year, DEC);
    myFile.print(F(";"));
    myFile.print(F(" HORARIO: "));
    myFile.print(rtc.getTimeStr());
    myFile.print(F(";"));

    // ========================================================================================================
    // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA TEMPERATURA AMBIENTE DO SENSOR DTH22:

    t1_int = dht2.readTemperature();

    // ========================================================================================================
    // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA TEMPERATURA AMBIENTE DO SENSOR DTH22:

    if (t1_int < t1_int_Min)
    {
      t1_int_Min = t1_int;
    }
    if (t1_int > t1_int_Max)
    {
      t1_int_Max = t1_int;
    }

    myFile.print(F(" TEMPERATURA INTERNA: "));
    myFile.print(t1_int);
    myFile.print(F("°C"));
    myFile.print(F(";"));

    myFile.print(F(" TEMPERATURA INTERNA MAX: "));
    myFile.print(t1_int_Max);
    myFile.print(F("°C"));
    myFile.print(F(";"));

    myFile.print(F(" TEMPERATURA INTERNA MIN: "));
    myFile.print(t1_int_Min);
    myFile.print(F("°C"));
    myFile.print(F(";"));


    // ========================================================================================================
    // GRAVAÇÃO DOS DADOS DE UMIDADE E TEMPERATURA DO DTH22:

    h = dht1.readHumidity();
    t1 =  dht1.readTemperature();

    if (t1 < t1MinDHT22)
    {
      t1MinDHT22 = t1;
    }
    if (t1 > t1MaxDHT22)
    {
      t1MaxDHT22 = t1;
    }

    myFile.print(F(" TEMPERATURA AMBIENTE DTH22: "));
    myFile.print(t1);
    myFile.print(F("°C"));
    myFile.print(F(";"));

    myFile.print(F(" TEMPERATURA AMBIENTE DHT22 MAX: "));
    myFile.print(t1MaxDHT22);
    myFile.print(F("°C"));
    myFile.print(F(";"));

    myFile.print(F(" TEMPERATURA AMBIENTE DHT22 MIN: "));
    myFile.print(t1MinDHT22);
    myFile.print(F("°C"));
    myFile.print(F(";"));


    if (h < UminDHT22)
    {
      UminDHT22 = h;
    }
    if (h > UmaxDHT22)
    {
      UmaxDHT22 = h;
    }

    myFile.print(F(" UMIDADE EXTERNA DHT22: "));
    myFile.print(h);
    myFile.print(F("%"));
    myFile.print(F(";"));

    myFile.print(F(" UMIDADE EXTERNA DHT22 MAX: "));
    myFile.print(UmaxDHT22);
    myFile.print(F("%"));
    myFile.print(F(";"));

    myFile.print(F(" UMIDADE EXTERNA DHT22 MIN: "));
    myFile.print(UminDHT22);
    myFile.print(F("%"));
    myFile.print(F(";"));

    if (dewPoint(t1, h ) < dewPointMin)
    {
      dewPointMin = dewPoint(t1, h );
    }
    if (dewPoint(t1, h ) > dewPointMax)
    {
      dewPointMax = dewPoint(t1, h );
    }

    myFile.print(F(" PONTO DE ORVALHO: "));
    myFile.print(dewPoint(t1, h ));
    myFile.print(F("°C"));
    myFile.print(F(";"));

    myFile.print(F(" PONTO DE ORVALHO MAX: "));
    myFile.print(t1MaxDHT22);
    myFile.print(F("°C"));
    myFile.print(F(";"));

    myFile.print(F(" PONTO DE ORVALHO MIN: "));
    myFile.print(t1MinDHT22);
    myFile.print(F("°C"));
    myFile.print(F(";"));

    // ========================================================================================================
    // CÁLCULO PARA EXIBIR A VARIÁVEL UMIDADE P1 DO SOLO EM %:

    for (int i = 0; i <= 200; i++) {
      sensorP1 = analogRead(SensorUmidadeP1);
      umidP1_analog = umidP1_analog + sensorP1;
    }

    // FILTRO PARA GARATIR UMA LEITURA MAIS ESTÁVEL COM 200 MEDIÇÕES:

    valorumidadeP1 = umidP1_analog / 200;
    umidadeP1 = ((valorumidadeP1 - minimoP1) / (maximoP1 - minimoP1)) * 100;
    umidadeP1 = (umidadeP1 - 100) * -1;

    umidP1_analog = 0;
    valorumidadeP1 = 0;


    // LÓGICA DE PARA INDICAÇÃO DOS VALORES MÁXIMOS E MÍNIMOS:

    if (umidadeP1 < umSminP1)
    {
      umSminP1 = umidadeP1;
    }

    if (umidadeP1 > umSmaxP1)
    {
      umSmaxP1 = umidadeP1;
    }

    // FILTRO DE PARA INDICAÇÃO DOS LIMITES MÁXIMOS E MÍNIMOS:

    if (umidadeP1 <= 0) {
      umidadeP1 = 0.00;
    }

    if (umidadeP1 >= 100.00) {
      umidadeP1 = 99.99;
    }


    // ========================================================================================================
    // GRAVAÇÃO DOS DADOS ANALÓGICOS DO MÓDULO DO SENSOR DE UMIDADE NO PONTO P1 NO SD CARD


    myFile.print(F(" VALOR DA UMIDADE P1: "));
    myFile.print(umidadeP1);
    myFile.print(F("%"));
    myFile.print(F(";"));

    myFile.print(F(" UMIDADE P1 MAX: "));
    myFile.print(umSmaxP1);
    myFile.print(F("%"));
    myFile.print(F(";"));

    myFile.print(F(" UMIDADE P1 MIN: "));
    myFile.print(umSminP1);
    myFile.print(F("%"));
    myFile.print(F(";"));

    myFile.print(F(" ANALOGICO UMIDADE P1: "));
    myFile.print(analogRead(SensorUmidadeP1));
    myFile.print(F(";"));

    myFile.print(F(" SOLO: "));
    if (umidadeP1 <= 30.00) {
      myFile.print(F("SECO"));
      myFile.print(F(";"));
    }

    if ((umidadeP1 > 30.00) && (umidadeP1 <= 50.00)) {
      myFile.print(F("POUCO ÚMIDO"));
      myFile.print(F(";"));
    }

    if ((umidadeP1 > 50.00) && (umidadeP1 <= 65.00)) {
      myFile.print(F("BOA UMIDADE"));
      myFile.print(F(";"));
    }
    if ((umidadeP1 > 65.00) && (umidadeP1 <= 75.00)) {
      myFile.print(F("MUITO ÚMIDO"));
      myFile.print(F(";"));
    }

    if (umidadeP1 > 75.00) {
      myFile.print(F("ENCHARCADO"));
      myFile.print(F(";"));
    }

    // ========================================================================================================
    // CÁLCULO PARA EXIBIR A VARIÁVEL UMIDADE P2 DO SOLO EM %:

    for (int i = 0; i <= 200; i++) {
      sensorP2 = analogRead(SensorUmidadeP2);
      umidP2_analog = umidP2_analog + sensorP2;
    }

    // FILTRO PARA GARATIR UMA LEITURA MAIS ESTÁVEL COM 200 MEDIÇÕES:

    valorumidadeP2 = umidP2_analog / 200;
    umidadeP2 = ((valorumidadeP2 - minimoP2) / (maximoP2 - minimoP2)) * 100;
    umidadeP2 = (umidadeP2 - 100) * -1;

    umidP2_analog = 0;
    valorumidadeP2 = 0;


    // LÓGICA DE PARA INDICAÇÃO DOS VALORES MÁXIMOS E MÍNIMOS:

    if (umidadeP2 < umSminP2)
    {
      umSminP2 = umidadeP2;
    }

    if (umidadeP2 > umSmaxP2)
    {
      umSmaxP2 = umidadeP2;
    }

    // FILTRO DE PARA INDICAÇÃO DOS LIMITES MÁXIMOS E MÍNIMOS:

    if (umidadeP2 <= 0) {
      umidadeP2 = 0.00;
    }

    if (umidadeP2 >= 100.00) {
      umidadeP2 = 99.99;
    }

    // ========================================================================================================
    // GRAVAÇÃO DOS DADOS ANALÓGICOS DO MÓDULO DO SENSOR DE UMIDADE NO PONTO P2 NO SD CARD

    myFile.print(F(" VALOR DA UMIDADE P2: "));
    myFile.print(umidadeP2);
    myFile.print(F("%"));
    myFile.print(F(";"));

    myFile.print(F(" UMIDADE P2 MAX: "));
    myFile.print(umSmaxP2);
    myFile.print(F("%"));
    myFile.print(F(";"));

    myFile.print(F(" UMIDADE P2 MIN: "));
    myFile.print(umSminP2);
    myFile.print(F("%"));
    myFile.print(F(";"));

    myFile.print(F(" ANALOGICO UMIDADE P2: "));
    myFile.print(analogRead(SensorUmidadeP2));
    myFile.print(F(";"));

    myFile.print(F(" SOLO: "));
    if (umidadeP2 <= 30.00) {
      myFile.print(F("SECO"));
      myFile.print(F(";"));
    }

    if ((umidadeP2 > 30.00) && (umidadeP2 <= 50.00)) {
      myFile.print(F("POUCO ÚMIDO"));
      myFile.print(F(";"));
    }

    if ((umidadeP2 > 50.00) && (umidadeP2 <= 65.00)) {
      myFile.print(F("BOA UMIDADE"));
      myFile.print(F(";"));
    }
    if ((umidadeP2 > 65.00) && (umidadeP2 <= 75.00)) {
      myFile.print(F("MUITO ÚMIDO"));
      myFile.print(F(";"));
    }

    if (umidadeP2 > 75.00) {
      myFile.print(F("ENCHARCADO"));
      myFile.print(F(";"));
    }

    // ========================================================================================================
    // GRAVAÇÃO DA TEMPERATURA DO MÓDULO TERMOPAR MAX 6675:

    myFile.print(F(" TEMPERATURA SOLO: "));
    myFile.print(thermocouple.readCelsius());
    myFile.print(F("°C"));
    myFile.print(F(";"));

    myFile.print(F(" TEMPERATURA MAX DO SOLO: "));
    myFile.print(termoparMax);
    myFile.print(F("°C"));
    myFile.print(F(";"));

    myFile.print(F(" TEMPERATURA MIN DO SOLO: "));
    myFile.print(termoparMin);
    myFile.print(F("°C"));
    myFile.print(F(";"));

    // ========================================================================================================
    // GRAVAÇÃO DOS DADOS DO MÓDULO BMP280

    // ========================================================================================================
    // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA PRESSÃO ATMOSFÉRICA - MÓDULO BMP280:

    valor3 = 0;
    valorp = 0;

    for (int i = 0; i <= 100; i++) {
      valorp = sensor_bmp.readPressure();
      valor3 = valor3 + valorp;
    }

    p = valor3 / 100;

    p = p / 100;  // tranformando 1Pa em 1 milibar
    valor3 = 0;
    valorp = 0;

    if (p < pMin)
    {
      pMin = p;
    }

    if (p > pMax)
    {
      pMax = p;
    }

    myFile.print(F(" PRESSAO ATMOSFERICA: "));
    myFile.print(p);
    myFile.print(F("mBar"));
    myFile.print(F(";"));

    myFile.print(F(" PRESSAO MAX: "));
    myFile.print(pMax);
    myFile.print(F("mBar"));
    myFile.print(F(";"));

    myFile.print(F(" PRESSAO MIN: "));
    myFile.print(pMin);
    myFile.print(F("mBar"));
    myFile.print(F(";"));

    // ========================================================================================================
    // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA ALTITUDE - MÓDULO BMP280:

    valor2 = 0;
    valoralt = 0;

    for (int i = 0; i <= 100; i++) {
      valoralt = sensor_bmp.readAltitude(1013.25);
      valor2 = valor2 + valoralt;
    }

    alt = valor2 / 100;
    valor2 = 0;
    valoralt = 0;

    if (alt < altMin)
    {
      altMin = alt;
    }

    if (alt > altMax)
    {
      altMax = alt;
    }

    myFile.print(F(" ALTITUDE APROX: "));
    myFile.print(alt);
    myFile.print(F("METROS"));
    myFile.print(F(";"));

    myFile.print(F(" ALTITUDE MAX: "));
    myFile.print(altMax);
    myFile.print(F("METROS"));
    myFile.print(F(";"));

    myFile.print(F(" ALTITUDE MIN: "));
    myFile.print(altMin);
    myFile.print(F("METROS"));
    myFile.print(F(";"));

    // ========================================================================================================
    // GRAVAÇÃO DA LUMINOSIDADE SENSOR BHT1750:

    myFile.print(F(" LUMINOSIDADE: "));
    myFile.print(lux);
    myFile.print(F("lux"));
    myFile.print(F(";"));

    myFile.print(F(" LUMINOSIDADE MAX: "));
    myFile.print(luxmax);
    myFile.print(F("lux"));
    myFile.print(F(";"));

    myFile.print(F(" LUMINOSIDADE MIN: "));
    myFile.print(luxmin);
    myFile.print(F("lux"));
    myFile.print(F(";"));

    // ========================================================================================================
    // GRAVAÇÃO DA PRECIPTAÇÃO DE ORVALHO:

    // ========================================================================================================
    // CÁLCULO PARA EXIBIR A VARIÁVEL PRECIPTAÇÃO DE ORVALHO EM %:

    valor5 = 0;
    preciptacao1 = 0;

    for (int i = 0; i <= 100; i++) {
      chuva_analog = analogRead(chuvaPIN);
      valor5 = valor5 + chuva_analog;
    }
    preciptacao1 = valor5 / 100;
    preciptacao = ((preciptacao1 - minimo2) / (maximo2 - minimo2)) * 100;
    preciptacao = (preciptacao - 100) * -1;
    valor5 = 0;
    preciptacao1 = 0;

    if (preciptacao < cpmin)
    {
      cpmin = preciptacao;
    }
    if (preciptacao > cpmax)
    {
      cpmax = preciptacao;
    }

    if (preciptacao <= 4.99) {
      preciptacao = 0.0;
    }

    if (preciptacao >= 100.00) {
      preciptacao = 99.9;
    }

    myFile.print(F(" ORVALHO: "));
    myFile.print(preciptacao);
    myFile.print(F("%"));
    myFile.print(F(";"));

    myFile.print(F(" ORVALHO MAX: "));
    myFile.print(cpmax);
    myFile.print(F("%"));
    myFile.print(F(";"));

    myFile.print(F(" ORVALHO MIN: "));
    myFile.print(cpmin);
    myFile.print(F("%"));
    myFile.print(F(";"));

    myFile.print(F(" PLUVIOMETRO: "));
    myFile.print(pluviometro);
    myFile.print(F("mm"));
    myFile.print(F(";"));

    myFile.print(F(" PLUVIOMETRO ACUMULADO: "));
    myFile.print(pluviometro_acum);
    myFile.print(F("mm"));
    myFile.print(F(";"));

    myFile.print(F(" PULSOS SENSOR PLUV.: "));
    myFile.print(contaPulso1);
    myFile.print(F(";"));

    myFile.print(F(" VAZAO: "));
    myFile.print(vazao);
    myFile.print(F("L/min"));
    myFile.print(F(";"));

    myFile.print(F(" TOTALIZADOR: "));
    myFile.print(Litros);
    myFile.print(F("L"));
    myFile.print(F(";"));

    myFile.print(F(" PULSOS TOT1: "));
    myFile.print(contaPulso_vazao);
    myFile.print(F(";"));

    myFile.print(F(" PULSOS TOT2: "));
    myFile.print(contaPulsotot);
    myFile.print(F(";"));

    myFile.print(F(" NIVEL DOS RESERVATORIOS: "));

    pinMode(pinVCC_Nivel, OUTPUT);           // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DE SENSORES
    pinMode(pinGND_Nivel, OUTPUT);           // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DE SENSORES
    digitalWrite(pinVCC_Nivel, true);        // aux VCC
    digitalWrite(pinGND_Nivel, false);       // aux GND

    delay(1000);
    Ultrasonic ultrasonic(12, 11); // 12 - CINZA ECHO // 11 - TRIGGER BRANCO
    distance = ultrasonic.read();

    // ========================================================================================================
    // TRATAMENTO DA INDICAÇÃO DA VÁRIALVEL NIVEL, CASO HAJA FALHA NO MÓDULO ELA INDICARÁ O CM!!

    if (distance == 357) {
      volume_reservatorio = 0;
      volume_Min = 0;
      nivel = 0;
      nivelMin = -1;
    } else {
      nivel = altura_caixa - distance;
      volume_reservatorio = (((nivel * pi) / 3) * c_aux);
      volume_reservatorio = volume_reservatorio / 1000;
      volume_reservatorio = volume_reservatorio * 2;
    }

    // ========================================================================================================
    // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DO SENSOR ULTRASSONICO:

    if (nivel < nivelMin)
    {
      nivelMin = nivel;
    }
    if (nivel > nivelMax)
    {
      nivelMax = nivel;
    }

    // ========================================================================================================
    // REGISTRO DOS VALORES MÁXIMO E MÍNIMO DO VOLUME:

    if (volume_reservatorio < volume_Min)
    {
      volume_Min = volume_reservatorio;
    }

    if (volume_reservatorio > volume_Max)
    {
      volume_Max = volume_reservatorio;
    }

    myFile.print(nivel);
    myFile.print(F("cm"));
    myFile.print(F(";"));

    myFile.print(F(" NIVEL MAX. DOS RESERVATORIOS: "));
    myFile.print(nivelMax);
    myFile.print(F("cm"));
    myFile.print(F(";"));

    myFile.print(F(" NIVEL MIN. DOS RESERVATORIOS: "));
    myFile.print(nivelMin);
    myFile.print(F("cm"));
    myFile.print(F(";"));

    myFile.print(F(" VOLUME DOS RESERVATORIOS: "));
    myFile.print(volume_res);
    myFile.print(F("Litros"));
    myFile.print(F(";"));

    myFile.print(F(" VOLUME MAX. DOS RESERVATORIOS: "));
    myFile.print(volume_Max);
    myFile.print(F("Litros"));
    myFile.print(F(";"));

    myFile.print(F(" VOLUME MIN. DOS RESERVATORIOS: "));
    myFile.print(volume_Min);
    myFile.print(F("Litros"));
    myFile.print(F(";"));

    myFile.print(F(" INDICE UV: "));
    myFile.print(UV_index);
    myFile.print(F("UV"));
    myFile.print(F(";"));

    myFile.print(F(" INDICE UV MAX.: "));
    myFile.print(UV_indexMax);
    myFile.print(F("UV"));
    myFile.print(F(";"));

    myFile.print(F(" INDICE UV MIN.: "));
    myFile.print(UV_indexMin);
    myFile.print(F("UV"));
    myFile.print(F(";"));

    myFile.print(F(" BAT: "));
    myFile.print(milliVolts);
    myFile.print(F("miliVolts"));
    myFile.print(F(";"));

    // ========================================================================================================
    // GRAVAÇÃO DA TEMPERATURA DO MÓDULO DS3231:

    myFile.print(F(" TEMPERATURA MOD. DS3231: "));
    myFile.print(rtc.getTemp());
    myFile.print(F("°C"));
    myFile.print(F(";"));


    int msgok = msg_sdcard_ok + 1;

    myFile.print(F(" GRAVACAO NUMERO: "));
    myFile.print(msgok);
    myFile.print(F(";"));

    myFile.println();
    delay(1000);
    myFile.close();
    delay(1000);

    SD.end();

    msg_sdcard_ok++;

    // SE NÃO HOUVER ERRO PARA ABRIR O ARQUIVO, IRÁ INDICAR: GRAVAÇÃO OK NO DISPLAY
    
    tft.fillRoundRect(0, 275, 240, 25, 10, RED);
    tft.drawRoundRect(0, 275, 240, 25, 10, WHITE);
    tft.setCursor(50, 280);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("GRAVACAO OK!"));

    // SE HOUVER ERRO PARA ABRIR O ARQUIVO, IRÁ INDICAR NO DISPLAY

  }  else {

    msg_sdcard_nok++;
    tft.fillRoundRect(0, 275, 240, 25, 10, YELLOW);
    tft.drawRoundRect(0, 275, 240, 25, 10, RED);
    tft.setCursor(5, 280);
    tft.setTextColor(RED);
    tft.setTextSize(2);
    tft.print(F("DADOS NAO GRAVADOS!"));

  }


}

/********************************************************************************************************/
// ========================================================================================================







/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/

// ========================================================================================================
// FUNÇÕES PARA ENVIAR COMANDO VIA SERIAL AO MODULO SIM800L E LER A RESPOSTA VIA SERIAL:

/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/


// ========================================================================================================
// FUNÇÃO PARA ENVIO DE COMANDOS AT: Envia comando AT e aguarda até que uma resposta seja obtida!!

String sendAT(String command) {

  String response = "";
  serialGSM.begin(9600);

  serialGSM.println(command);
  delay(500);

  // ========================================================================================================
  // Checa se não houver resposta do módulo, retorna "SERIAL GSM EM FALHA!": HABILITADO DIA 31/03/2021
  // MELHOR EFICIENCIA QUANDO NÃO HOUVER RETORNO DO MODULO SIM 800L, O PROGRAMA NÃO TRAVA O LOOP DE EXECUÇÃO!!

  modemGSM.waitResponse(5000, response);
  if (response.equals("")) {
    response = "Falha!";
  }

  if (command == "AT+GSMBUSY=1") {  // PROIBE TODAS AS CHAMADAS RECEBIDAS!!
    tft.setCursor(5, 60);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.print(F("GSMBUSY:"));
    delay(1000);
    response.trim();
    if (response == "Falha!") {
      tft.setCursor(100, 60);
      tft.setTextColor(RED);
      tft.println(response);
      delay(1000);

    } else {
      tft.setCursor(100, 60);
      tft.setTextColor(WHITE);
      tft.print(response);
      tft.fillRect(0, 80, 240, 320, BLACK);
      delay(1000);
    }

  }
  return response;
}

// ========================================================================================================
// FUNÇÃO PARA ENVIO DE COMANDOS AT: Envia comando AT e aguarda até que uma resposta seja obtida!!
// FUNÇÃO USADA NO SETUP DO MÓDULO GPRS SIM800L.

String sendAT1(String command) {

  String response = "";
  serialGSM.begin(9600);

  serialGSM.println(command);
  delay(500);

  // ========================================================================================================
  // Checa se não houver resposta do módulo, retorna "SERIAL GSM EM FALHA!": HABILITADO DIA 31/03/2021
  // MELHOR EFICIENCIA QUANDO NÃO HOUVER RETORNO DO MODULO SIM 800L, O PROGRAMA NÃO TRAVA O LOOP DE EXECUÇÃO!!

  modemGSM.waitResponse(5000, response);
  if (response.equals("")) {
    response = "Falha!";
  }


  // ========================================================================================================
  // Verifica qual comando foi dado e imprime a resposta num determinado lugar da tela do display

  if (command == "AT+GSMBUSY=1") {  // PROIBE TODAS AS CHAMADAS RECEBIDAS!!
    tft.setCursor(0, 80);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.print(F("PROIBE LIGACAO:"));
    response.trim();
    if (response == "Falha!") {
      tft.setCursor(180, 80);
      tft.setTextColor(RED);
      tft.println(response);
      delay(1000);

    } else {
      tft.setCursor(180, 80);
      tft.setTextColor(WHITE);
      tft.print(response);
      delay(1000);
    }

  }

  return response;
}

// ========================================================================================================
// FUNÇÃO PARA ENVIO DE COMANDOS AT: Envia comando AT e aguarda até que uma resposta seja obtida!!

String sendATSMS(String command)
{

  String response = "";
  serialGSM.begin(9600);

  serialGSM.println(command);
  delay(500);

  // ========================================================================================================
  // Checa se não houver resposta do módulo, retorna "SERIAL GSM EM FALHA!": HABILITADO DIA 31/03/2021
  // MELHOR EFICIENCIA QUANDO NÃO HOUVER RETORNO DO MODULO SIM 800L, O PROGRAMA NÃO TRAVA O LOOP DE EXECUÇÃO!!

  modemGSM.waitResponse(5000, response);
  if (response.equals("")) {
    response = "Serial GSM em Falha";
  }

  // ========================================================================================================
  // Verifica qual comando foi dado e imprime a resposta num determinado lugar da tela do display:

  if (command == "AT+GSMBUSY=1") {  // PROIBE TODAS AS CHAMADAS RECEBIDAS!!
    tft.drawRect(0, 40, 240, 1, YELLOW);
    tft.setCursor(5, 45);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.print(F("PROIBE LIGACAO:"));
    response.trim();
    if (response == "Serial GSM em Falha") {
      tft.setCursor(5, 62);
      tft.setTextColor(RED);
      tft.println(response);
      tft.drawRect(0, 80, 240, 1, YELLOW);
      modo_sms_ativado = 0;
      delay(1000);
    } else {
      tft.setCursor(5, 62);
      tft.setTextColor(WHITE);
      tft.print(F("SIM 800L: "));
      tft.print(response);
      modo_sms_ativado++;
      tft.drawRect(0, 80, 240, 1, YELLOW);
      delay(1000);
    }

  }

  if (command == "AT+CMGF=1\n") {
    tft.drawRect(0, 120, 240, 1, YELLOW);
    tft.setCursor(5, 85);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.print(F("MODO TEXTO ATIVADO:"));
    response.trim();
    if (response == "Serial GSM em Falha") {
      tft.setCursor(5, 102);
      tft.setTextColor(RED);
      tft.println(response);
      modo_sms_ativado = 0;
      delay(1000);
    } else {
      tft.setCursor(5, 102);
      tft.setTextColor(WHITE);
      tft.print(F("SIM 800L: "));
      tft.print(response);
      modo_sms_ativado++;
      delay(1000);
    }
  }

  if (command == "AT+CNMI=2,2,0,0,0\n") {
    tft.drawRect(0, 160, 240, 1, YELLOW);
    tft.setCursor(5, 125);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.print(F("CONFIGURA MODO SMS:"));
    response.trim();
    if (response == "Serial GSM em Falha") {
      tft.setCursor(5, 142);
      tft.setTextColor(RED);
      tft.println(response);
      modo_sms_ativado = 0;
      delay(1000);
    } else {
      tft.setCursor(5, 142);
      tft.setTextColor(WHITE);
      tft.print(F("SIM 800L: "));
      tft.print(response);
      modo_sms_ativado++;
      delay(1000);
    }

  }

  if (command == "ATX4\n") {
    tft.drawRect(0, 200, 240, 1, YELLOW);
    tft.setCursor(5, 165);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.print(F("ATIVANDO SCAN SMS:"));
    response.trim();
    if (response == "Serial GSM em Falha") {
      tft.setCursor(5, 182);
      tft.setTextColor(RED);
      tft.println(response);
      modo_sms_ativado = 0;
      delay(1000);
    } else {
      tft.setCursor(5, 182);
      tft.setTextColor(WHITE);
      tft.print(F("SIM 800L: "));
      tft.print(response);
      modo_sms_ativado++;
      delay(1000);
    }
  }

  if (command == "AT+COLP=1\n") {
    tft.drawRect(0, 240, 240, 1, YELLOW);
    tft.setCursor(5, 205);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.print(F("CONFIGURA CONEXAO:"));
    response.trim();
    if (response == "Serial GSM em Falha") {
      tft.setCursor(5, 222);
      tft.setTextColor(RED);
      tft.println(response);
      modo_sms_ativado = 0;
      delay(1000);
    } else {
      tft.setCursor(5, 222);
      tft.setTextColor(WHITE);
      tft.print(F("SIM 800L: "));
      tft.print(response);
      modo_sms_ativado++;
      delay(1000);
    }
  }

  if (command == "AT+CMGDA=DEL ALL\n") {
    tft.drawRect(0, 280, 240, 1, YELLOW);
    tft.setCursor(5, 245);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.print(F("APAGANDO SMS ANTIGO:"));
    response.trim();
    if (response == "Serial GSM em Falha") {
      tft.setCursor(5, 262);
      tft.setTextColor(RED);
      tft.println(response);
      modo_sms_ativado = 0;
      delay(1000);
    } else {
      tft.setCursor(5, 262);
      tft.setTextColor(WHITE);
      tft.print(F("SIM 800L: "));
      tft.print(response);
      modo_sms_ativado++;
      delay(1000);
    }
  }


  return response;
}






/********************************************************************************************************/
/********************************************************************************************************/

// ========================================================================================================
// FUNÇÕES DE SETUP DO MODO DE OPERAÇÃO DO SIM800L:

/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/




// ========================================================================================================
// FUNÇÃO PARA SETUP INICIAL DO MODULO SIM800L:

void setup_gsm_gprs() {

  //Inicia comunicacao serial com o GSM

  serialGSM.begin(9600);
  delay(1000);

  // ========================================================================================================
  //INICIANDO SETUP MODULO GSM/GPRS SIM 800L

  tft.fillRoundRect(10, 0, 220, 70, 10, RED);
  tft.drawRoundRect(10, 0, 220, 70, 10, WHITE);

  tft.setCursor(76, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(F("SETUP"));

  tft.setCursor(58, 38);
  tft.print(F("SIM800L"));

  delay(2000);
  sendAT1("AT+GSMBUSY=1");

  int sim = modemGSM.getSimStatus();

  tft.setCursor(0, 100);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("Status SIM CARD:"));
  tft.setTextColor(WHITE);
  if (sim == 1) {
    tft.print(F("OK"));
  } else {
    tft.setTextColor(RED);
    tft.print(F("NOK"));
  }

  delay(1000);

  tft.setCursor(0, 120);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("Versao:"));
  tft.setTextColor(WHITE);
  tft.print(modemGSM.getModemInfo());

  delay(1000);

  String imei = modemGSM.getIMEI();
  tft.setCursor(0, 140);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("IMEI:"));
  tft.setTextColor(WHITE);
  tft.print(imei);

  delay(1000);

  String cop = modemGSM.getOperator();
  tft.setCursor(0, 160);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("Operadora GSM:"));
  tft.setTextColor(WHITE);
  if (cop == "72410") {
    tft.print(F("VIVO"));
  }

  delay(1000);

  int simcard = modemGSM.getSimStatus();
  tft.setCursor(0, 180);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("Status SIM CARD:"));
  tft.setTextColor(WHITE);
  if (sim == 1) {
    tft.print(F("OK"));
  } else {
    tft.setTextColor(RED);
    tft.print(F("NOK"));
  }

  delay(1000);

  int ss = modemGSM.getSignalQuality();
  tft.setCursor(0, 200);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("Sinal Quality:"));

  if ( ss >= 31 ) {
    tft.setTextColor(RED);
  }
  if ( ss <= 30 && ss >= 20) {
    tft.setTextColor(WHITE);
  }
  if ( ss <= 19 && ss >= 15) {
    tft.setTextColor(WHITE);
  }
  if ( ss < 15 && ss >= 10) {
    tft.setTextColor(YELLOW);
  }
  if ( ss < 10) {
    tft.setTextColor(RED);
  }

  tft.print(modemGSM.getSignalQuality());

  delay(1000);

  tft.setCursor(0, 220);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("Sinal GSM:"));

  tft.setCursor(120, 220);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);

  if ( ss >= 31 ) {
    tft.setTextColor(RED);
    tft.print(F("EM FALHA!"));
  }

  if ( ss <= 30 && ss >= 20) {
    tft.print(F("Excelente"));
  }
  if ( ss <= 19 && ss >= 15) {
    tft.print(F("Otimo"));
  }
  if ( ss < 15 && ss >= 10) {
    tft.setTextColor(YELLOW);
    tft.print(F("Bom"));
  }
  if ( ss < 10) {
    tft.setTextColor(RED);
    tft.print(F("Fraco"));
  }

  delay(1000);

  tft.setCursor(0, 240);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("GPRS Connection:"));
  tft.setTextColor(WHITE);

  if (modemGSM.gprsConnect(apn, gprsUser, gprsPass) == 1) {
    delay(3000);    //10000(10seg)
    tft.print(F("OK"));

  } else {
    delay(3000);
    tft.setTextColor(RED);
    tft.print(F("NOK"));
  }

  delay(1000);

  bool res = modemGSM.isGprsConnected();
  tft.setCursor(0, 260);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("GPRS Status:"));
  tft.setTextColor(WHITE);

  if (res == 1) {
    tft.print("OK");
  } else {
    tft.setTextColor(RED);
    tft.print(F("NOK"));
  }

  delay(1000);

  IPAddress local = modemGSM.localIP();
  tft.setCursor(0, 280);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("IP:"));
  tft.setTextColor(WHITE);
  tft.print(local);

  delay(1000);

  modemGSM.getBattStats(chargeState, chargePercent, milliVolts);

  tft.setCursor(0, 300);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("BAT:"));
  tft.setCursor(50, 300);
  tft.setTextColor(WHITE);

  //voltage =< 3,5 under voltage warning
  //voltage => 4,3 over voltage warning
  //voltage < 3,4 under voltage power down
  //voltage > 4,4 under voltage power down

  if (milliVolts <= 3500 || milliVolts >= 4300) {
    tft.setTextColor(ORANGE);
  }

  delay(1000);
  tft.print(milliVolts);
  tft.print(F(" miliVolts"));
  delay(5000);

}


// ========================================================================================================
// FUNÇÃO VOID CONFIGURA GSM EM MODO SMS:

void configuraGSM() {

  serialGSM.begin(9600);

  tft.fillRect(0, 0, 240, 40, RED);

  tft.setCursor(22, 15);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(F("SIM800L MODO SMS"));

  modo_sms_ativado = 0;

  sendATSMS("AT+GSMBUSY=1");
  sendATSMS("AT+CMGF=1\n");
  sendATSMS("AT+CNMI=2,2,0,0,0\n");
  sendATSMS("ATX4\n");
  sendATSMS("AT+COLP=1\n");
  sendATSMS("AT+CMGDA=DEL ALL\n");

  if (modo_sms_ativado == 6) {
        
    configuraGSM_ok ++;
        
    tft.fillRect(0, 285, 240, 35, RED);
    tft.setCursor(5, 295);
    tft.setTextColor(WHITE);
    tft.setTextSize(2);
    tft.print(F("SIM800L MODO SMS OK"));

    delay(2000);

  } else {

    configuraGSM_nok++;
    configuraGSM_nok_resete++;
    
    tft.fillRect(0, 285, 240, 35, YELLOW);
    tft.setCursor(5, 295);
    tft.setTextColor(RED);
    tft.setTextSize(2);
    tft.print(F("FALHA GSM MODO SMS!"));


    digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
    delay(1500);
    digitalWrite(BUZZER_VCC, false);         // Reseta o BUZZER
    delay(2000);
    modemGSM.restart();
    delay(10000);
  }
}


// ========================================================================================================
// FUNÇÃO VOID LÊ MENSAGENS SMS RECEBIDAS:

void leGSM()
{
  serialGSM.begin(9600);
  serialGSM.listen();

  static String textoRec = "";
  static int count = 0;
  static unsigned char buffer[512];

  // Exemplo de mensagmem: [+CMGL: 1,"REC UNREAD","+5518999999999","","18/11/30,11:36:14-08"
  //                          Hello 
  //                          OK
  //                       ]
  
  if (serialGSM.available()) {
  serialGSM.flush();
    while (serialGSM.available()) {

      buffer[count++] = serialGSM.read();
      if (count == 512)break;
     
    }

    textoRec += (char*)buffer;

    for (int i = 0; i < count; i++) {
      buffer[i] = NULL;
    }
    count = 0;
  }

  delay(100);
  
  if (textoRec != "" ) {

    if ( textoRec.substring(2, 7) == "+CMT:" ) {
      temSMS = true;
    }

    if (temSMS) {

      telefoneSMS = "";
      dataHoraSMS = "";
      mensagemSMS = "";

      byte linha = 0;
      byte aspas = 0;

      for (int nL = 1; nL < textoRec.length(); nL++) {

        if (textoRec.charAt(nL) == '"') {
          aspas++;
          continue;
        }

        if ( (linha == 1) && (aspas == 1) ) {
          telefoneSMS += textoRec.charAt(nL);

        }

        if ( (linha == 1) && (aspas == 5) ) {
          dataHoraSMS += textoRec.charAt(nL);

        }

        if ( linha == 2 ) {
          mensagemSMS += textoRec.charAt(nL);

        }

        if (textoRec.substring(nL - 1, nL + 1) == "\r\n") {
          linha++;

        }
      }

    } else {
      comandoGSM = textoRec;
    }

    textoRec = "";

  }

  if (comandoGSM != "") {
    comandoGSM.trim();
    ultimoGSM = comandoGSM;
    comandoGSM = "";
  }

  if (msg_sms_env == 0) {
    ultimoGSM = "-> Ok!";
  }

}




// ========================================================================================================
// FUNÇÃO VOID QUE ENVIA MENSAGEM DE RETORNO COM OS DADOS DAS VARIAVEIS:

void enviaSMS(String telefoneSMS, String mensagem) {

  float hh = dht1.readHumidity();
  float tt1 = dht1.readTemperature();

  serialGSM.begin(9600);

  serialGSM.print("AT+CMGS=\"" + telefoneSMS + "\"\n");
  serialGSM.print(mensagem + "\n\n");
  serialGSM.print("Valores dos Sensores:""\n");

  serialGSM.print("Umidade do Solo P1: ");
  serialGSM.print(umidadeP1);
  serialGSM.print("%""\n");

  serialGSM.print("Umidade do Solo P2: ");
  serialGSM.print(umidadeP2);
  serialGSM.print("%""\n");

  serialGSM.print("Temperatura do Solo: ");
  serialGSM.print(thermocouple.readCelsius());
  serialGSM.print((char)248);
  serialGSM.print("C""\n");

  serialGSM.print("Temperatura Ambiente: ");
  serialGSM.print(tt1);
  serialGSM.print((char)248);
  serialGSM.print("C""\n");

  serialGSM.print("Umidade Ambiente: ");
  serialGSM.print(hh);
  serialGSM.print("%""\n");

  serialGSM.print("Orvalho: ");
  serialGSM.print(preciptacao);
  serialGSM.print("%""\n");

  serialGSM.print("Pluviometro: ");
  serialGSM.print(pluviometro = contaPulso1 * 0.25);  // Variável para exibir a quantidade de chuva totalizada no dia
  serialGSM.print("mm""\n");
              
  serialGSM.print((char)26);

  delay(1000);

}


// ========================================================================================================
// FUNÇÃO VOID QUE ENVIA MENSAGEM DE RETORNO COM O RELATÓRIO DE ENVIO AOS SERVERS IOT:

void enviaSMS1(String telefoneSMS, String mensagem) {
 
//========================================================================================================
// Contagem de vezes que houver falha no envio das mensagens aos Servidores IoT:

//unsigned int msg_counternok_resete; //msg não enviada ubidots 0
//unsigned int msg_counternok1_resete; //msg não enviada ubidots 1
//unsigned int msg_counternok_t_resete; // msg não enviada ThingSpeak 0
//unsigned int msg_counternok_t1_resete; // msg não enviada ThingSpeak 1
//unsigned int msg_counternok_t2_resete; // msg não enviada ThingSpeak 2
//unsigned int configuraGSM_nok_resete; // GSM nok

  serialGSM.begin(9600);

  serialGSM.print("AT+CMGS=\"" + telefoneSMS + "\"\n");
  serialGSM.print(mensagem + "\n\n");
  serialGSM.print("Relatorio de Funcionamento:""\n");
  serialGSM.print("\n");

  //========================================================================================================
  serialGSM.print("ThingSpeak Channel ID: 1062830\n");
  serialGSM.print("Dados Enviados: ");
  serialGSM.print(msg_counterok_t);
  serialGSM.print("\n");

  serialGSM.print("Dados Nao Enviados: ");
  serialGSM.print(msg_counternok_t);
  serialGSM.print("\n");

  serialGSM.print("Falhas no Dia: ");
  serialGSM.print(msg_counternok_t_resete);  //unsigned int msg_counternok_t_resete; // msg não enviada ThingSpeak 0
  serialGSM.print("\n\n");
  
  //========================================================================================================
  serialGSM.print("ThingSpeak Channel ID: 1347631\n");
  serialGSM.print("Dados Enviados: ");
  serialGSM.print(msg_counterok_t1);
  serialGSM.print("\n");

  serialGSM.print("Dados Nao Enviados: ");
  serialGSM.print(msg_counternok_t1);
  serialGSM.print("\n");

  serialGSM.print("Falhas no Dia: ");
  serialGSM.print(msg_counternok_t1_resete);  //unsigned int msg_counternok_t1_resete; // msg não enviada ThingSpeak 1
  serialGSM.print("\n\n");

  //========================================================================================================
  serialGSM.print("ThingSpeak Channel ID: 1451371\n");
  serialGSM.print("Dados Enviados: ");
  serialGSM.print(msg_counterok_t2);
  serialGSM.print("\n");

  serialGSM.print("Dados Nao Enviados:");
  serialGSM.print(msg_counternok_t2);
  serialGSM.print("\n");

  serialGSM.print("Falhas no Dia:");
  serialGSM.print(msg_counternok_t2_resete);  //unsigned int msg_counternok_t2_resete; // msg não enviada ThingSpeak 2
  serialGSM.print("\n\n");

  //========================================================================================================
  serialGSM.print("Ubidots Device NSAGRO-V0\n");
  serialGSM.print("Dados Enviados: ");
  serialGSM.print(msg_counterok);
  serialGSM.print("\n");

  serialGSM.print("Dados Nao Enviados: ");
  serialGSM.print(msg_counternok);
  serialGSM.print("\n");

  serialGSM.print("Falhas no Dia: ");
  serialGSM.print(msg_counternok_resete);   //unsigned int msg_counternok_resete; //msg não enviada ubidots 0
  serialGSM.print("\n\n");
  
  //========================================================================================================
  serialGSM.print("Ubidots Device NSAGRO-V1\n");
  serialGSM.print("Dados Enviados: ");
  serialGSM.print(msg_counterok1);
  serialGSM.print("\n");

  serialGSM.print("Dados Nao Enviados: ");
  serialGSM.print(msg_counternok1);
  serialGSM.print("\n");

  serialGSM.print("Falhas no Dia: ");
  serialGSM.print(msg_counternok1_resete);     //unsigned int msg_counternok1_resete; //msg não enviada ubidots 1
  serialGSM.print("\n\n");

  //========================================================================================================
  serialGSM.print("Modulo SIM800L\n");
  serialGSM.print("GSM modo SMS Ok: ");
  serialGSM.print(configuraGSM_ok);
  serialGSM.print("\n");

  serialGSM.print("GSM modo SMS Nok: ");
  serialGSM.print(configuraGSM_nok);
  serialGSM.print("\n");

  serialGSM.print("Falhas no Dia: ");
  serialGSM.print(configuraGSM_nok_resete);     //unsigned int configuraGSM_nok_resete; // GSM nok  serialGSM.print("GSM modo SMS Ok: ");
  serialGSM.print("\n\n");

  serialGSM.print("SMS enviados: ");
  serialGSM.print(msg_sms_env + 1); // variavel contador de sms enviados
  serialGSM.print("\n");

  serialGSM.print("SMS recebidos: ");
  serialGSM.print(msg_sms_rec);
  serialGSM.print("\n");

  //========================================================================================================
  serialGSM.print("Proximo Envio Iot: ");
  serialGSM.print(t_send);
  serialGSM.print("seg");
  serialGSM.print("\n");

  serialGSM.print((char)26);

  delay(1000);

}


// ========================================================================================================
// FUNÇÃO VOID QUE ENVIA MENSAGEM DE CONFIRMAÇÃO DE SOLICITAÇÃO DE RESETE AO NANO SMART AGRO:

void enviaSMS2(String telefoneSMS, String mensagem) {

  serialGSM.begin(9600);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  rtc.begin();
  t = rtc.getTime();

  serialGSM.print("AT+CMGS=\"" + telefoneSMS + "\"\n");
  serialGSM.print(mensagem + "\n\n");
  serialGSM.print("Solicitacao de RESETE!""\n");
  serialGSM.print("\n");

  serialGSM.print("RESETE Confirmado:""\n");

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  serialGSM.print("Data: ");
  char const divider = '/';
  serialGSM.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));
  serialGSM.print("\n");

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  serialGSM.print("Dia: ");
  serialGSM.print(rtc.getDOWStr());
  serialGSM.print("\n");

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  serialGSM.print("Horario: ");
  serialGSM.print(rtc.getTimeStr());
  serialGSM.print("hrs");
  serialGSM.print("\n");

  serialGSM.print((char)26);

  delay(1000);

}

// ========================================================================================================
// FUNÇÃO VOID QUE ENVIA MENSAGEM DO RELATÓRIO DE GRAVAÇÃO DO SD CARD:

void enviaSMS3(String telefoneSMS, String mensagem) {


  serialGSM.begin(9600);

  serialGSM.print("AT+CMGS=\"" + telefoneSMS + "\"\n");
  serialGSM.print(mensagem + "\n\n");
  serialGSM.print("Relatorio de Funcionamento""\n\n");

  serialGSM.print("SD Card gravacao ok: ");
  serialGSM.print(msg_sdcard_ok);
  serialGSM.print("\n");

  serialGSM.print("SD Card erro de gravacao: ");
  serialGSM.print(msg_sdcard_nok);
  serialGSM.print("\n");

  serialGSM.print((char)26);

  delay(1000);

}

// ========================================================================================================
// FUNÇÃO VOID QUE ENVIA MENSAGEM DE CONFIRMAÇÃO DE RESETE DO PLUVIÔMETRO:

void enviaSMS4(String telefoneSMS, String mensagem) {

  serialGSM.begin(9600);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  rtc.begin();
  t = rtc.getTime();

  serialGSM.print("AT+CMGS=\"" + telefoneSMS + "\"\n");
  serialGSM.print(mensagem + "\n\n");
  serialGSM.print("Solicitacao de RESETE do Pluviometro!""\n");
  serialGSM.print("\n");

  serialGSM.print("RESETE Confirmado:""\n");

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  serialGSM.print("Data: ");
  char const divider = '/';
  serialGSM.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));
  serialGSM.print("\n");

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  serialGSM.print("Dia: ");
  serialGSM.print(rtc.getDOWStr());
  serialGSM.print("\n");

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  serialGSM.print("Horario: ");
  serialGSM.print(rtc.getTimeStr());
  serialGSM.print("hrs");
  serialGSM.print("\n");

  serialGSM.print((char)26);

  delay(1000);

}

// ========================================================================================================
// FUNÇÃO VOID QUE ENVIA MENSAGEM DE CONFIRMAÇÃO DE RESETE DO TOTALIZADOR DE VAZÃO:

void enviaSMS5(String telefoneSMS, String mensagem) {

  serialGSM.begin(9600);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  rtc.begin();
  t = rtc.getTime();

  serialGSM.print("AT+CMGS=\"" + telefoneSMS + "\"\n");
  serialGSM.print(mensagem + "\n\n");
  serialGSM.print("Solicitacao de RESETE do Totalizador de Vazao!""\n");
  serialGSM.print("\n");

  serialGSM.print("RESETE Confirmado:""\n");

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  serialGSM.print("Data: ");
  char const divider = '/';
  serialGSM.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));
  serialGSM.print("\n");

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  serialGSM.print("Dia: ");
  serialGSM.print(rtc.getDOWStr());
  serialGSM.print("\n");

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  serialGSM.print("Horario: ");
  serialGSM.print(rtc.getTimeStr());
  serialGSM.print("hrs");
  serialGSM.print("\n");

  serialGSM.print((char)26);

  delay(1000);

}



// ========================================================================================================
// FUNÇÃO VOID QUE ENVIA MENSAGEM DE DETECÇÃO DE POSSIBILIDADE DE CHUVA:

void enviaSMS6(String telefoneSMS, String mensagem) {

  tft.fillRect(0, 0, 240, 320, BLACK);
  
  serialGSM.begin(9600);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  rtc.begin();
  t = rtc.getTime();

  digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
  delay(250);
  digitalWrite(BUZZER_VCC, false);         // Seta o BUZZER
  delay(250);
  digitalWrite(BUZZER_VCC, true);        // Seta o BUZZER
  delay(250);
  digitalWrite(BUZZER_VCC, false);        // Seta o BUZZER
  delay(250);
  digitalWrite(BUZZER_VCC, true);         // Seta o BUZZER
  delay(250);
  digitalWrite(BUZZER_VCC, false);        // Seta o BUZZER

  tft.fillRoundRect(0, 0, 240, 95, 15, RED);
  tft.drawRoundRect(0, 0, 240, 95, 15, WHITE);
  tft.setCursor(23, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(F("VERIFICANDO"));

  tft.setCursor(52, 37);
  tft.print(F("ENVIO DE"));

  tft.setCursor(14, 64);
  tft.print(F("MENSAGEM SMS"));

  tft.fillRoundRect(10, 110, 220, 30, 15, YELLOW);
  tft.drawRoundRect(10, 110, 220, 30, 15, RED);
  tft.setCursor(30, 114);
  tft.setTextColor(RED);
  tft.print(F("ENVIAR SMS!"));

  // ========================================================================================================
  // Enviando SMS para o celular +5515999999!

  tft.setCursor(10, 158);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("SMS para:"));
  tft.setTextColor(WHITE);
  if(telefoneSMS == "+5515999999999"){
      tft.print(F("Walter R."));
  }
    if(telefoneSMS == "+551599XXXXXXXX"){
      tft.print(F("Tanti"));
  }
    if(telefoneSMS == "+55159YYYYYYYYY"){
      tft.print(F("Arnaldo"));
  }
    if(telefoneSMS == "+55159ZZZZZZZZ"){
      tft.print(F("Suzana"));
  }

  tft.setCursor(10, 178);
  tft.setTextColor(CYAN);
  tft.print(F("Cel:"));
  tft.setTextColor(WHITE);
  tft.print(telefoneSMS);

  tft.setCursor(10, 198);
  tft.setTextColor(CYAN);
  tft.print(F("Mensagem: "));
  tft.setTextColor(WHITE);
  tft.print(F("Aviso de Possibilidade de Chuva!"));

  delay(3000);

  serialGSM.print("AT+CMGS=\"" + telefoneSMS + "\"\n");
  serialGSM.print(mensagem + "\n\n");
  serialGSM.print("Alerta de Possibilidade de Chuva!!""\n");
  serialGSM.print("\n");

  serialGSM.print("Pressao Atm: ");
  serialGSM.print(p);
  serialGSM.print("mBar");
  serialGSM.print("\n");

  serialGSM.print("Pressao Atm Min Abaixo de 917mBar: ");
  serialGSM.print(pMin);
  serialGSM.print("mBar");
  serialGSM.print("\n");

  serialGSM.print("Diferencial Atm: ");
  serialGSM.print((pMax - pMin));
  serialGSM.print("mBar");
  serialGSM.print("\n");
  serialGSM.print("\n");

  // ========================================================================================================
  // EXIBIÇÃO DA DATA:
  
  serialGSM.print("Aviso Confirmado em:""\n");
  serialGSM.print("Data: ");
  char const divider = '/';
  serialGSM.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));
  serialGSM.print("\n");

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  serialGSM.print("Dia: ");
  serialGSM.print(rtc.getDOWStr());
  serialGSM.print("\n");

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  serialGSM.print("Horario: ");
  serialGSM.print(rtc.getTimeStr());
  serialGSM.print("hrs");
  serialGSM.print("\n");

  serialGSM.print("\n");
  serialGSM.print("Mensagem SMS Automatica!""\n");
  serialGSM.print("Nao Responda essa Mensagem!""\n");

  serialGSM.print((char)26);

  delay(3000);
  tft.fillRect(0, 280, 240, 38, RED);
  tft.setCursor(5, 282);
  tft.setTextColor(WHITE);
  tft.print(F(" Previsao de Chuva!"));
  tft.setCursor(25, 300);
  tft.print(F("  SMS Enviado!  "));

  msg_sms_env++;

  delay(3000);

  int pino53 = 53;
  pinMode(pino53, OUTPUT);

  delay(500);
  SD.begin(pino53);
  delay(500);

  myFile = SD.open("SMS.txt", FILE_WRITE);
  myFile.print(F("NANO SMART AGRO - Mensagem SMS Enviada"));
  myFile.print(F(";"));
  myFile.print(F(" Possibilidade de chuva detectada!"));
  myFile.print(F(";"));
  myFile.print(F(" Envio de aviso de chuva por SMS"));
  myFile.print(F(";"));
  myFile.print(F(" Cel:"));
  myFile.print(telefoneSMS);
  myFile.print(F(";"));
  myFile.print(F(" SMS Enviados: "));
  myFile.print(msg_sms_env);
  myFile.print(F(";"));
  myFile.print(F(" DATA: "));
  myFile.print(t.date, DEC);
  myFile.print(F("/"));
  myFile.print(t.mon, DEC);
  myFile.print(F("/"));
  myFile.print(t.year, DEC);
  myFile.print(F(";"));
  myFile.print(F(" HORARIO: "));
  myFile.print(rtc.getTimeStr());
  myFile.print(F(";"));
  myFile.println();
  myFile.println();
  delay(1000);
  myFile.close();
  delay(1000);

  SD.end();

}


// ========================================================================================================
// FUNÇÃO VOID QUE ENVIA MENSAGEM DE DETECÇÃO DE ÍNDICE PLUVIOMETRICO MAIOR QUE 1.00MM DE CHUVA:

void enviaSMS7(String telefoneSMS, String mensagem) {

  serialGSM.begin(9600);

  // ========================================================================================================
  // EXIBIÇÃO DA DATA E HORÁRIO:

  rtc.begin();
  t = rtc.getTime();

  serialGSM.print("AT+CMGS=\"" + telefoneSMS + "\"\n");
  serialGSM.print(mensagem + "\n\n");
  serialGSM.print("Ocorrencia de Chuva maior que 1.00mm !!""\n");
  serialGSM.print("\n");

  serialGSM.print("Pluviometro: ");
  serialGSM.print(pluviometro);
  serialGSM.print("mm");
  serialGSM.print("\n");
  serialGSM.print("\n");

  serialGSM.print("Aviso Confirmado em:""\n");
  // ========================================================================================================
  // EXIBIÇÃO DA DATA:

  serialGSM.print("Data: ");
  char const divider = '/';
  serialGSM.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, divider));
  serialGSM.print("\n");

  // ========================================================================================================
  // EXIBIÇÃO DO DIA DA SEMANA:

  serialGSM.print("Dia: ");
  serialGSM.print(rtc.getDOWStr());
  serialGSM.print("\n");

  // ========================================================================================================
  // EXIBIÇÃO DO HORÁRIO:

  serialGSM.print("Horario: ");
  serialGSM.print(rtc.getTimeStr());
  serialGSM.print("hrs");
  serialGSM.print("\n");

  serialGSM.print("\n");
  serialGSM.print("Mensagem SMS Automatica!""\n");
  serialGSM.print("Nao Responda essa Mensagem!""\n");

  serialGSM.print((char)26);

  delay(1000);

}




// ========================================================================================================
// FUNÇÃO VOID QUE ENVIA MENSAGEM PARA CONSULTAR SALDO DE RECARGA DA VIVO:

void enviaSMS8(String telefoneSMS, String mensagem) {

  serialGSM.begin(9600);
  serialGSM.print("AT+CMGS=\"" + telefoneSMS + "\"\n");
  serialGSM.print(mensagem);
  serialGSM.print((char)26);

  delay(1000);
}


// ========================================================================================================
// FUNÇÕES UTEIS PARA CONFIGURAÇÃO DAS FUNÇÕES DE ENVIO AOS SERVIDORES:

//  modemGSM.restart();
//  modemGSM.init();
//  modemGSM.gprsDisconnect();
//  modemGSM.isNetworkConnected();

/********************************************************************************************************/
/********************************************************************************************************/

// ========================================================================================================
// FUNÇÕES PARA ENVIAR OS DADOS AOS SERVERS IoT:

/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/

//      msg_counternok_resete = 0; //msg não enviada Ubidots 0
//      msg_counternok1_resete = 0; //msg não enviada Ubidots 1
//      msg_counternok_t_resete = 0; // msg não enviada ThingSpeak 0
//      msg_counternok_t1_resete = 0; // msg não enviada ThingSpeak 1
//      msg_counternok_t2_resete = 0; // msg não enviada ThingSpeak 2
//      configuraGSM_nok_resete = 0; // GSM não Ok(resete)
//      configuraGSM_nok = 0; // GSM não ok (SMS envio)
//      configuraGSM_ok = 0; // GSM ok (SMS)


// ========================================================================================================
// FUNÇÃO PARA ENVIO DAS VARIAVEIS AO SERVIDOR DA UBIDOTS:

void iot_ubidots() {

  bool error_server = false;
  serialGSM.begin(9600);
  rtc.begin();
  t = rtc.getTime();

  tft.fillRect(0, 0, 240, 320, BLACK);
  tft.fillRect(0, 0, 240, 35, RED);

  tft.setCursor(22, 5);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(F("UBIDOTS IoT"));

  delay(1000);

  // ========================================================================================================
  //INICIANDO SETUP MODULO GSM/GPRS SIM 800L:

  tft.setCursor(5, 40);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("Client ID:"));
  tft.setTextColor(WHITE);
  tft.print(F("*******"));

  sendAT("AT+GSMBUSY=1");
  delay(1000);

  int sim = modemGSM.getSimStatus();

  tft.setCursor(5, 80);
  tft.setTextColor(CYAN);
  tft.print(F("Status SIM CARD:"));
  tft.setTextColor(WHITE);
  if (sim == 1) {
    tft.print(F("OK"));
  } else {
    tft.setTextColor(RED);
    tft.print(F("NOK"));

    msg_counternok++;
    msg_counternok_resete++;
    
    delay(1000);
    tft.setCursor(5, 278);
    tft.setTextColor(CYAN);
    tft.print(F("Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counterok);

    tft.setCursor(5, 298);
    tft.setTextColor(CYAN);
    tft.print(F("Nao Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counternok);
    delay(3000);

    int pino53 = 53;
    pinMode(pino53, OUTPUT);

    delay(500);
    SD.begin(pino53);
    delay(500);
    myFile = SD.open("IoT0.txt", FILE_WRITE);   
    myFile.print(F("NANO SMART AGRO - MENSAGEM NÃO ENVIADA AO SERVER UBIDOTS, DEVICE: *******"));
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Enviadas: "));
    myFile.print(msg_counterok);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas: "));
    myFile.print(msg_counternok);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas no Dia: "));
    myFile.print(msg_counternok_resete);
    myFile.print(F(";"));
    myFile.print(F(" SIM CARD NOK! "));
    myFile.print(F(";"));
    myFile.print(F(" DATA: "));
    myFile.print(t.date, DEC);
    myFile.print(F("/"));
    myFile.print(t.mon, DEC);
    myFile.print(F("/"));
    myFile.print(t.year, DEC);
    myFile.print(F(";"));
    myFile.print(F(" HORARIO: "));
    myFile.print(rtc.getTimeStr());
    myFile.println();
    delay(1000);
    myFile.close();
    delay(2000);

    return;
  }

  delay(1000);

  int ss = modemGSM.getSignalQuality();
  tft.setCursor(5, 100);
  tft.setTextColor(CYAN);
  tft.print(F("Sinal Quality:"));

  if ( ss >= 31) {
    tft.setTextColor(RED);
  }

  if ( ss <= 30 && ss >= 20) {
    tft.setTextColor(WHITE);
  }
  if ( ss <= 19 && ss >= 15) {
    tft.setTextColor(WHITE);
  }
  if ( ss < 15 && ss >= 10) {
    tft.setTextColor(YELLOW);
  }
  if ( ss < 10) {
    tft.setTextColor(RED);
  }

  tft.print(ss);
  delay(1000);

  tft.setCursor(5, 120);
  tft.setTextColor(CYAN);
  tft.print(F("Sinal GSM:"));

  tft.setCursor(125, 120);
  tft.setTextColor(WHITE);

  if ( ss >= 31) {
    tft.print(F("EM FALHA!"));
  }

  if ( ss <= 30 && ss >= 20 ) {
    tft.print(F("Excelente"));
  }
  if ( ss <= 19 && ss >= 15) {
    tft.print(F("Otimo"));
  }
  if ( ss < 15 && ss >= 10) {
    tft.print(F("Bom"));
  }
  if ( ss < 10) {
    tft.print(F("Fraco"));
  }

  client.setKeepAlive (60);
  delay(1000);

  tft.setCursor(5, 140);
  tft.setTextColor(CYAN);
  tft.print(F("GPRS Connection:"));
  tft.setTextColor(WHITE);

  bool res = modemGSM.isGprsConnected();
  if (res == 1) {
    delay(1000);
    tft.print("OK");

  } else {

    if (modemGSM.gprsConnect(apn, gprsUser, gprsPass) == 1) {
      delay(3000);
      tft.print(F("OK"));

    } else {
      delay(3000);
      tft.setTextColor(RED);
      tft.print(F("NOK"));

      msg_counternok++;
      msg_counternok_resete++;
      
      delay(1000);
      tft.setCursor(5, 278);
      tft.setTextColor(CYAN);
      tft.print(F("Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counterok);

      tft.setCursor(5, 298);
      tft.setTextColor(CYAN);
      tft.print(F("Nao Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counternok);
      delay(3000);

      int pino53 = 53;
      pinMode(pino53, OUTPUT);

      delay(500);
      SD.begin(pino53);
      delay(500);
      myFile = SD.open("IoT0.txt", FILE_WRITE);
      myFile.print(F("NANO SMART AGRO - MENSAGEM NÃO ENVIADA AO SERVER UBIDOTS, DEVICE: ********"));
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Enviadas: "));
      myFile.print(msg_counterok);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas: "));
      myFile.print(msg_counternok);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas no Dia: "));
      myFile.print(msg_counternok_resete);
      myFile.print(F(";"));
      myFile.print(F(" GPRS NOT CONNECT! "));
      myFile.print(F(";"));
      myFile.print(F(" DATA: "));
      myFile.print(t.date, DEC);
      myFile.print(F("/"));
      myFile.print(t.mon, DEC);
      myFile.print(F("/"));
      myFile.print(t.year, DEC);
      myFile.print(F(";"));
      myFile.print(F(" HORARIO: "));
      myFile.print(rtc.getTimeStr());
      myFile.print(F(";"));
      myFile.print(F(" GSM SINAL: "));
      myFile.print(ss);
      myFile.println();
      delay(1000);
      myFile.close();
      delay(2000);

      return;

    }


  }

  delay(1000);

  IPAddress local = modemGSM.localIP();
  tft.setCursor(5, 160);
  tft.setTextColor(CYAN);
  tft.print(F("IP:"));
  tft.setTextColor(WHITE);
  tft.print(local);

  delay(1000);
  client.setServer(server, 1883);

  while (!!!client.connect(clientId, token, "")) {
    tft.setCursor(5, 180);
    tft.setTextColor(WHITE);
    tft.print(F("ID:"));
    tft.setTextColor(RED);
    tft.print(F("SEM CONEXAO!"));

    tft.setCursor(5, 200);
    tft.setTextColor(WHITE);
    tft.print(F("ERROR MQTT SERVER: "));
    tft.setCursor(5, 220);
    tft.setTextColor(RED);

    status_server = client.state();
    
    if(status_server == -4){
      tft.print(F("CONNECTION_TIMEOUT"));
    }
    if(status_server == -3){
      tft.print(F("CONNECTION_LOST"));
    }
    if(status_server == -2){
      tft.print(F("CONNECTION_FAILED"));
    }
    if(status_server == -1){
      tft.print(F("MQTT_DISCONNECTED"));
    }
    if(status_server == 1){
      tft.print(F("BAD_PROTOCOL"));
    }
    if(status_server == 2){
      tft.print(F("BAD_CLIENT_ID"));
    }
    if(status_server == 3){
      tft.print(F("CONNECT_UNAVAILABLE"));
    }
    if(status_server == 4){
      tft.print(F("CONNECT_BAD_CREDENTIALS"));
    }
    if(status_server == 5){
      tft.print(F("CONNECT_UNAUTHORIZED"));
    }

    msg_counternok++;
    msg_counternok_resete++;
    
    delay(1000);
    error_server = true;

    tft.setCursor(5, 278);
    tft.setTextColor(CYAN);
    tft.print(F("Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counterok);

    tft.setCursor(5, 298);
    tft.setTextColor(CYAN);
    tft.print(F("Nao Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counternok);

    // ========================================================================================================
    //ENCERRANDO CONEXÃO COM O SERVER:

    client.disconnect();
    delay(5000);
    
    //modemGSM.gprsDisconnect();
    //delay(5000);
    
    break;

  }

  if (error_server == true) {
    int pino53 = 53;
    pinMode(pino53, OUTPUT);

    delay(500);
    SD.begin(pino53);
    delay(500);
    myFile = SD.open("IoT0.txt", FILE_WRITE);
    myFile.print(F("NANO SMART AGRO - MENSAGEM NÃO ENVIADA AO SERVER UBIDOTS, DEVICE: *************"));
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Enviadas: "));
    myFile.print(msg_counterok);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas: "));
    myFile.print(msg_counternok);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas no Dia: "));
    myFile.print(msg_counternok_resete);
    myFile.print(F(";"));
    myFile.print(F(" DATA: "));
    myFile.print(t.date, DEC);
    myFile.print(F("/"));
    myFile.print(t.mon, DEC);
    myFile.print(F("/"));
    myFile.print(t.year, DEC);
    myFile.print(F(";"));
    myFile.print(F(" HORARIO: "));
    myFile.print(rtc.getTimeStr());
    myFile.print(F(";"));
    myFile.print(F(" CLIENT ERROR: "));
    myFile.print(status_server);
    myFile.print(F(";"));
    myFile.print(F(" GSM SINAL: "));
    myFile.print(ss);
    myFile.print(F(";"));
    myFile.print(F(" IP:"));
    myFile.print(local);
    myFile.println();
    delay(1000);
    myFile.close();
    delay(4000);

    return;


  } else {

    status_server = client.state();

    tft.setCursor(5, 180);
    tft.setTextColor(CYAN);
    tft.print(F("ID:"));
    if (status_server == 0) {
      tft.setTextColor(WHITE);
      tft.print(F("Conectado"));
    }

    String msg = createJsonString();

    tft.drawRect(0, 200, 240, 1, YELLOW);
    tft.setCursor(5, 206);
    tft.setTextColor(CYAN);
    tft.setTextSize(1);
    tft.print(F("STRING:"));
    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    tft.print(msg);
    tft.drawRect(0, 255, 240, 1, YELLOW);

    bool status_public = client.publish(topic, msg.c_str());

    if (status_public) {

      msg_counterok ++;
      
      tft.setCursor(5, 258);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("Mensagem:"));
      tft.setTextColor(WHITE);
      tft.print(F("Publicada"));
      tft.setCursor(5, 278);
      tft.setTextColor(CYAN);
      
      tft.print(F("Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counterok);

      tft.setCursor(5, 298);
      tft.setTextColor(CYAN);
      tft.print(F("Nao Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counternok);

      // ========================================================================================================
      //ENCERRANDO CONEXÃO COM O SERVER:

      client.disconnect();
      delay(5000);

      // ========================================================================================================
      //GRAVANDO OD DADOS NO SD CARD:

      int pino53 = 53;
      pinMode(pino53, OUTPUT);

      delay(500);
      SD.begin(pino53);
      delay(500);
      myFile = SD.open("IoT0.txt", FILE_WRITE);
      myFile.print(F("NANO SMART AGRO - Mensagem Enviada ao Sever UBIDOTS, Device: ******"));
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Enviadas: "));
      myFile.print(msg_counterok);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas: "));
      myFile.print(msg_counternok);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas no Dia: "));
      myFile.print(msg_counternok_resete);
      myFile.print(F(";"));
      myFile.print(F(" DATA: "));
      myFile.print(t.date, DEC);
      myFile.print(F("/"));
      myFile.print(t.mon, DEC);
      myFile.print(F("/"));
      myFile.print(t.year, DEC);
      myFile.print(F(";"));
      myFile.print(F(" HORARIO: "));
      myFile.print(rtc.getTimeStr());
      myFile.print(F(";"));
      myFile.print(F(" STRING: "));
      myFile.print(msg);
      myFile.print(F(";"));
      myFile.print(F(" GSM SINAL: "));
      myFile.print(ss);
      myFile.print(F(";"));
      myFile.print(F(" IP:"));
      myFile.print(local);
      myFile.println();
      delay(1000);
      myFile.close();
      delay(2000);

      return;

    } else {

      tft.fillRect(0, 253, 240, 25, YELLOW);
      tft.setCursor(5, 258);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("Msg:"));
      tft.setTextColor(RED);
      tft.print(F("NAO Publicada!"));
      
      msg_counternok++;
      msg_counternok_resete++;

      client.disconnect();
      delay(2000);
      modemGSM.restart();
      delay(10000);

      //modemGSM.gprsDisconnect();  // caso a msg não for publicada, desconecta o GPRS para que haja um novo IP a ser identificado pelo Módulo SIM800L
      //delay(5000);

      // ========================================================================================================
      //GRAVANDO OD DADOS NO SD CARD:

      int pino53 = 53;
      pinMode(pino53, OUTPUT);

      delay(500);
      SD.begin(pino53);
      delay(500);
      myFile = SD.open("IoT0.txt", FILE_WRITE);
      myFile.print(F("NANO SMART AGRO - MENSAGEM NÃO ENVIADA AO SERVER UBIDOTS, DEVICE: ************"));
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Enviadas: "));
      myFile.print(msg_counterok);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas: "));
      myFile.print(msg_counternok);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas no Dia: "));
      myFile.print(msg_counternok_resete);
      myFile.print(F(";"));
      myFile.print(F(" DATA: "));
      myFile.print(t.date, DEC);
      myFile.print(F("/"));
      myFile.print(t.mon, DEC);
      myFile.print(F("/"));
      myFile.print(t.year, DEC);
      myFile.print(F(";"));
      myFile.print(F(" HORARIO: "));
      myFile.print(rtc.getTimeStr());
      myFile.print(F(";"));
      myFile.print(F(" STRING: "));
      myFile.print(msg);
      myFile.print(F(";"));
      myFile.print(F(" GSM SINAL: "));
      myFile.print(ss);
      myFile.print(F(";"));
      myFile.print(F(" IP:"));
      myFile.print(local);
      myFile.println();
      delay(1000);
      myFile.close();
      
      tft.setCursor(5, 278);
      tft.setTextColor(CYAN);
      tft.print(F("Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counterok);

      tft.setCursor(5, 298);
      tft.setTextColor(CYAN);
      tft.print(F("Nao Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counternok);

      delay(3000);
      return;
    }
  }
}


// ========================================================================================================
// FUNÇÃO PARA CRIAR A STRING JSON PARA ENVIO DAS INFORMAÇÕES AO SERVER UBIDOTS:

String createJsonString()
{
  dht1.begin();
  sensor_bmp.begin();

  /* Default settings from datasheet. */
  sensor_bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                         Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                         Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                         Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                         Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  float h10 = dht1.readHumidity();
  float t10 = dht1.readTemperature();
  float d10 = dewPoint(t10, h10);

  if (isnan(t1) || isnan(h)) {
    h10 = 25.0;
    t10 = 50.0;
    d10 = 25.0;
  }

  // ========================================================================================================
  // TRATAMENTO DA INDICAÇÃO DA VÁRIALVEL TEEMP_SOLO, CASO HAJA FALHA NO MÓDULO ELA INDICARÁ 25.0°C!!

  float ts10 = thermocouple.readCelsius();
  String falha = " NAN";
  String temp_solo_falha = "";
  temp_solo_falha.concat(ts10);

  if (temp_solo_falha == falha) {
    ts10 = 25.0;
  }

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL UMIDADE P1 DO SOLO EM %:

  for (int i = 0; i <= 200; i++) {
    sensorP1 = analogRead(SensorUmidadeP1);
    umidP1_analog = umidP1_analog + sensorP1;
  }

  // FILTRO PARA GARATIR UMA LEITURA MAIS ESTÁVEL COM 200 MEDIÇÕES:

  valorumidadeP1 = umidP1_analog / 200;
  umidadeP1 = ((valorumidadeP1 - minimoP1) / (maximoP1 - minimoP1)) * 100;
  umidadeP1 = (umidadeP1 - 100) * -1;

  umidP1_analog = 0;
  valorumidadeP1 = 0;

  // LÓGICA DE PARA INDICAÇÃO DOS VALORES MÁXIMOS E MÍNIMOS:

  if (umidadeP1 < umSminP1)
  {
    umSminP1 = umidadeP1;
  }

  if (umidadeP1 > umSmaxP1)
  {
    umSmaxP1 = umidadeP1;
  }


  // FILTRO DE PARA INDICAÇÃO DOS LIMITES MÁXIMOS E MÍNIMOS:

  if (umidadeP1 <= 0) {
    umidadeP1 = 0.00;
  }

  if (umidadeP1 >= 100.00) {
    umidadeP1 = 99.99;
  }

  float u10 = umidadeP1;

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL UMIDADE P1 DO SOLO EM %:

  for (int i = 0; i <= 200; i++) {
    sensorP2 = analogRead(SensorUmidadeP2);
    umidP2_analog = umidP2_analog + sensorP2;
  }

  // FILTRO PARA GARATIR UMA LEITURA MAIS ESTÁVEL COM 200 MEDIÇÕES:

  valorumidadeP2 = umidP2_analog / 200;
  umidadeP2 = ((valorumidadeP2 - minimoP2) / (maximoP2 - minimoP2)) * 100;
  umidadeP2 = (umidadeP2 - 100) * -1;

  umidP2_analog = 0;
  valorumidadeP2 = 0;

  // LÓGICA DE PARA INDICAÇÃO DOS VALORES MÁXIMOS E MÍNIMOS:

  if (umidadeP2 < umSminP2)
  {
    umSminP2 = umidadeP2;
  }

  if (umidadeP2 > umSmaxP2)
  {
    umSmaxP2 = umidadeP2;
  }

  // FILTRO DE PARA INDICAÇÃO DOS LIMITES MÁXIMOS E MÍNIMOS:

  if (umidadeP2 <= 0) {
    umidadeP2 = 0.00;
  }

  if (umidadeP2 >= 100.00) {
    umidadeP2 = 99.99;
  }

  float uu10 = umidadeP2;


  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA PRESSÃO ATMOSFÉRICA - MÓDULO BMP280:

  valor3 = 0;
  valorp = 0;

  for (int i = 0; i <= 100; i++) {
    valorp = sensor_bmp.readPressure();
    valor3 = valor3 + valorp;
  }

  p = valor3 / 100;
  p = p / 100;  // tranformando 1Pa em 1 mili Bar
  valor3 = 0;
  valorp = 0;

  float p10 = p;

  if (p < pMin)
  {
    pMin = p;
  }

  if (p > pMax)
  {
    pMax = p;
  }

  // ========================================================================================================
  // VARIAVEL DE INDICAÇÃO DE ALERA DE POSSIBILIDADE DE CHUVA (VALOR MAXIMO - VALOR MINIMO) > REFERENCIA: CHUVA!!

  float pa10 = pMax - pMin;

  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA ALTITUDE - MÓDULO BMP280:

  valor2 = 0;
  valoralt = 0;

  for (int i = 0; i <= 100; i++) {
    valoralt = sensor_bmp.readAltitude(1013.25);
    valor2 = valor2 + valoralt;
  }
  alt = valor2 / 100;
  valor2 = 0;
  valoralt = 0;

  float a10 = alt;

  // ========================================================================================================
  // CRIAÇÃO DA STRING DAS VARIAVEIS QUE SERÃO ENVIADAS PARA O UBIDOTS:

  // *******IMPORTANTE É APENAS PERMITIDO QUE ENVIE 9 VARIAVEIS AO UBIDOTS!!!!!*****************

  String data = "{";
  data += "\"TEMPERATURA AMBIENTE\":";
  data += String(t10);
  data += ",";

  data += "\"UMIDADE AMBIENTE\":";
  data += String(h10);
  data += ",";

  data += "\"UMIDADE DO SOLO P1\":";
  data += String(u10);
  data += ",";

  data += "\"UMIDADE DO SOLO P2\":";
  data += String(uu10);
  data += ",";

  data += "\"TEMPERATURA DO SOLO\":";
  data += String(ts10);
  data += ",";

  data += "\"PRESSAO ATMSOFERICA\":";
  data += String(p10);
  data += ",";

  data += "\"PRESSAO ALERTA\":";
  data += String(pa10);
  data += ",";

  data += "\"ALTITUDE\":";
  data += String(a10);
  data += ",";

  data += "\"DEW POINT\":";
  data += String(d10);
  data += "}";

  return data;
}






// ========================================================================================================
// FUNÇÃO PARA ENVIO DAS VARIAVEIS AO SERVIDOR DA UBIDOTS:

void iot_ubidots1() {

  bool error_server1 = false;
  serialGSM.begin(9600);
  rtc.begin();
  t = rtc.getTime();

  tft.fillRect(0, 0, 240, 320, BLACK);
  tft.fillRect(0, 0, 240, 35, RED);

  tft.setCursor(22, 5);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(F("UBIDOTS IoT"));

  delay(1000);

  // ========================================================================================================
  //INICIANDO SETUP MODULO GSM/GPRS SIM 800L:

  tft.setCursor(5, 40);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("Client ID:"));
  tft.setTextColor(WHITE);
  tft.print(F("********"));

  sendAT("AT+GSMBUSY=1");
  delay(1000);

  int sim = modemGSM.getSimStatus();

  tft.setCursor(5, 80);
  tft.setTextColor(CYAN);
  tft.print(F("Status SIM CARD:"));
  tft.setTextColor(WHITE);
  if (sim == 1) {
    tft.print(F("OK"));
  } else {
    tft.setTextColor(RED);
    tft.print(F("NOK"));

    msg_counternok1++;
    msg_counternok1_resete++;
    
    delay(1000);
    tft.setCursor(5, 278);
    tft.setTextColor(CYAN);
    tft.print(F("Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counterok1);

    tft.setCursor(5, 298);
    tft.setTextColor(CYAN);
    tft.print(F("Nao Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counternok1);
    delay(3000);

    int pino53 = 53;
    pinMode(pino53, OUTPUT);

    delay(500);
    SD.begin(pino53);
    delay(500);
    myFile = SD.open("IoT1.txt", FILE_WRITE);
    myFile.print(F("NANO SMART AGRO - MENSAGEM NÃO ENVIADA AO SERVER UBIDOTS, DEVICE: *********"));
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Enviadas: "));
    myFile.print(msg_counterok1);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas: "));
    myFile.print(msg_counternok1);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas no Dia: "));
    myFile.print(msg_counternok1_resete);
    myFile.print(F(";"));
    myFile.print(F(" SIM CARD NOK! "));
    myFile.print(F(";"));
    myFile.print(F(" DATA: "));
    myFile.print(t.date, DEC);
    myFile.print(F("/"));
    myFile.print(t.mon, DEC);
    myFile.print(F("/"));
    myFile.print(t.year, DEC);
    myFile.print(F(";"));
    myFile.print(F(" HORARIO: "));
    myFile.print(rtc.getTimeStr());
    myFile.println();
    delay(1000);
    myFile.close();
    delay(2000);

    return;
  }

  delay(1000);

  int ss = modemGSM.getSignalQuality();
  tft.setCursor(5, 100);
  tft.setTextColor(CYAN);
  tft.print(F("Sinal Quality:"));

  if ( ss >= 31) {
    tft.setTextColor(RED);
  }

  if ( ss <= 30 && ss >= 20) {
    tft.setTextColor(WHITE);
  }
  if ( ss <= 19 && ss >= 15) {
    tft.setTextColor(WHITE);
  }
  if ( ss < 15 && ss >= 10) {
    tft.setTextColor(YELLOW);
  }
  if ( ss < 10) {
    tft.setTextColor(RED);
  }

  tft.print(ss);
  delay(1000);

  tft.setCursor(5, 120);
  tft.setTextColor(CYAN);
  tft.print(F("Sinal GSM:"));

  tft.setCursor(125, 120);
  tft.setTextColor(WHITE);

  if ( ss >= 31) {
    tft.print(F("EM FALHA!"));
  }

  if ( ss <= 30 && ss >= 20 ) {
    tft.print(F("Excelente"));
  }
  if ( ss <= 19 && ss >= 15) {
    tft.print(F("Otimo"));
  }
  if ( ss < 15 && ss >= 10) {
    tft.print(F("Bom"));
  }
  if ( ss < 10) {
    tft.print(F("Fraco"));
  }

  //client.setKeepAlive (60);
  delay(1000);

  tft.setCursor(5, 140);
  tft.setTextColor(CYAN);
  tft.print(F("GPRS Connection:"));
  tft.setTextColor(WHITE);

  bool res = modemGSM.isGprsConnected();
  if (res == 1) {
    delay(1000);
    tft.print("OK");

  } else {

    if (modemGSM.gprsConnect(apn, gprsUser, gprsPass) == 1) {
      delay(3000);
      tft.print(F("OK"));

    } else {
      delay(3000);
      tft.setTextColor(RED);
      tft.print(F("NOK"));

      msg_counternok1 ++;
      msg_counternok1_resete++;
      
      delay(1000);
      tft.setCursor(5, 278);
      tft.setTextColor(CYAN);
      tft.print(F("Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counterok1);

      tft.setCursor(5, 298);
      tft.setTextColor(CYAN);
      tft.print(F("Nao Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counternok1);
      delay(3000);

      int pino53 = 53;
      pinMode(pino53, OUTPUT);

      delay(500);
      SD.begin(pino53);
      delay(500);
      myFile = SD.open("IoT1.txt", FILE_WRITE);
      myFile.print(F("NANO SMART AGRO - MENSAGEM NÃO ENVIADA AO SERVER UBIDOTS, DEVICE: *********"));
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Enviadas: "));
      myFile.print(msg_counterok1);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas: "));
      myFile.print(msg_counternok1);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas no Dia: "));
      myFile.print(msg_counternok1_resete);
      myFile.print(F(";"));
      myFile.print(F(" GPRS NOT CONNECT! "));
      myFile.print(F(";"));
      myFile.print(F(" DATA: "));
      myFile.print(t.date, DEC);
      myFile.print(F("/"));
      myFile.print(t.mon, DEC);
      myFile.print(F("/"));
      myFile.print(t.year, DEC);
      myFile.print(F(";"));
      myFile.print(F(" HORARIO: "));
      myFile.print(rtc.getTimeStr());
      myFile.print(F(";"));
      myFile.print(F(" GSM SINAL: "));
      myFile.print(ss);
      myFile.println();
      delay(1000);
      myFile.close();
      delay(2000);

      return;

    }


  }

  delay(1000);

  IPAddress local = modemGSM.localIP();
  tft.setCursor(5, 160);
  tft.setTextColor(CYAN);
  tft.print(F("IP:"));
  tft.setTextColor(WHITE);
  tft.print(local);

  delay(1000);
  client.setServer(server1, 1883);

  while (!!!client.connect(clientId1, token1, "")) {
    tft.setCursor(5, 180);
    tft.setTextColor(WHITE);
    tft.print(F("ID:"));
    tft.setTextColor(RED);
    tft.print(F("SEM CONEXAO!"));

    tft.setCursor(5, 200);
    tft.setTextColor(WHITE);
    tft.print(F("ERROR MQTT SERVER: "));
    tft.setCursor(5, 220);
    tft.setTextColor(RED);

    status_server1 = client.state();
    
    if(status_server1 == -4){
      tft.print(F("CONNECTION_TIMEOUT"));
    }
    if(status_server1 == -3){
      tft.print(F("CONNECTION_LOST"));
    }
    if(status_server1 == -2){
      tft.print(F("CONNECTION_FAILED"));
    }
    if(status_server1 == -1){
      tft.print(F("MQTT_DISCONNECTED"));
    }
    if(status_server1 == 1){
      tft.print(F("BAD_PROTOCOL"));
    }
    if(status_server1 == 2){
      tft.print(F("BAD_CLIENT_ID"));
    }
    if(status_server1 == 3){
      tft.print(F("CONNECT_UNAVAILABLE"));
    }
    if(status_server1 == 4){
      tft.print(F("CONNECT_BAD_CREDENTIALS"));
    }
    if(status_server1 == 5){
      tft.print(F("CONNECT_UNAUTHORIZED"));
    }

    msg_counternok1 ++;
    msg_counternok1_resete++;
    
    delay(1000);
    error_server1 = true;

    tft.setCursor(5, 278);
    tft.setTextColor(CYAN);
    tft.print(F("Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counterok1);

    tft.setCursor(5, 298);
    tft.setTextColor(CYAN);
    tft.print(F("Nao Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counternok1);

    // ========================================================================================================
    //ENCERRANDO CONEXÃO COM O SERVER:

    client.disconnect();
    delay(5000);
    
    //modemGSM.gprsDisconnect();
    //delay(5000);
    
    break;

  }

  if (error_server1 == true) {
    int pino53 = 53;
    pinMode(pino53, OUTPUT);

    delay(500);
    SD.begin(pino53);
    delay(500);
    myFile = SD.open("IoT1.txt", FILE_WRITE);
    myFile.print(F("NANO SMART AGRO - MENSAGEM NÃO ENVIADA AO SERVER UBIDOTS, DEVICE: ********"));
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Enviadas: "));
    myFile.print(msg_counterok1);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas: "));
    myFile.print(msg_counternok1);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas no Dia: "));
    myFile.print(msg_counternok1_resete);
    myFile.print(F(";"));
    myFile.print(F(" DATA: "));
    myFile.print(t.date, DEC);
    myFile.print(F("/"));
    myFile.print(t.mon, DEC);
    myFile.print(F("/"));
    myFile.print(t.year, DEC);
    myFile.print(F(";"));
    myFile.print(F(" HORARIO: "));
    myFile.print(rtc.getTimeStr());
    myFile.print(F(";"));
    myFile.print(F(" CLIENT ERROR: "));
    myFile.print(status_server1);
    myFile.print(F(";"));
    myFile.print(F(" GSM SINAL: "));
    myFile.print(ss);
    myFile.print(F(";"));
    myFile.print(F(" IP:"));
    myFile.print(local);
    myFile.println();
    delay(1000);
    myFile.close();
    delay(4000);

    return;


  } else {

    status_server1 = client.state();
    tft.setCursor(5, 180);
    tft.setTextSize(2);
    tft.setTextColor(CYAN);
    tft.print(F("ID:"));
    if (status_server1 == 0) {
      tft.setTextColor(WHITE);
      tft.print(F("Conectado"));
    }

    String msg = createJsonString1();

    tft.drawRect(0, 200, 240, 1, YELLOW);
    tft.setCursor(5, 206);
    tft.setTextColor(CYAN);
    tft.setTextSize(1);
    tft.print(F("STRING:"));
    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    tft.print(msg);
    tft.drawRect(0, 255, 240, 1, YELLOW);

    bool status_public1 = client.publish(topic1, msg.c_str());
    if (status_public1) {
      
      msg_counterok1 ++;
      
      tft.setCursor(5, 258);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("Mensagem:"));
      tft.setTextColor(WHITE);
      tft.print(F("Publicada"));

      tft.setCursor(5, 278);
      tft.setTextColor(CYAN);
      tft.print(F("Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counterok1);

      tft.setCursor(5, 298);
      tft.setTextColor(CYAN);
      tft.print(F("Nao Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counternok1);

      // ========================================================================================================
      //ENCERRANDO CONEXÃO COM O SERVER:

      client.disconnect();      
      delay(5000);

      // ========================================================================================================
      //GRAVANDO OD DADOS NO SD CARD:

      int pino53 = 53;
      pinMode(pino53, OUTPUT);

      delay(500);
      SD.begin(pino53);
      delay(500);
      myFile = SD.open("IoT1.txt", FILE_WRITE);
      myFile.print(F("NANO SMART AGRO - Mensagem Enviada ao Sever UBIDOTS, Device: **********"));
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Enviadas: "));
      myFile.print(msg_counterok1);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas: "));
      myFile.print(msg_counternok1);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas no Dia: "));
      myFile.print(msg_counternok1_resete);
      myFile.print(F(";"));
      myFile.print(F(" DATA: "));
      myFile.print(t.date, DEC);
      myFile.print(F("/"));
      myFile.print(t.mon, DEC);
      myFile.print(F("/"));
      myFile.print(t.year, DEC);
      myFile.print(F(";"));
      myFile.print(F(" HORARIO: "));
      myFile.print(rtc.getTimeStr());
      myFile.print(F(";"));
      myFile.print(F(" STRING: "));
      myFile.print(msg);
      myFile.print(F(";"));
      myFile.print(F(" GSM SINAL: "));
      myFile.print(ss);
      myFile.print(F(";"));
      myFile.print(F(" IP:"));
      myFile.print(local);
      myFile.println();
      delay(1000);
      myFile.close();
      delay(2000);

      return;

    } else {

      tft.fillRect(0, 253, 240, 25, YELLOW);
      tft.setCursor(5, 258);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("Msg:"));
      tft.setTextColor(RED);
      tft.print(F("NAO Publicada!"));
      
      msg_counternok1 ++;
      msg_counternok1_resete++;

      client.disconnect();
      delay(2000);
      modemGSM.restart();
      delay(10000);

      //modemGSM.gprsDisconnect();  // caso a msg não for publicada, desconecta o GPRS para que haja um novo IP a ser identificado pelo Módulo SIM800L
      //delay(5000);

      // ========================================================================================================
      //GRAVANDO OD DADOS NO SD CARD:

      int pino53 = 53;
      pinMode(pino53, OUTPUT);

      delay(500);
      SD.begin(pino53);
      delay(500);
      myFile = SD.open("IoT1.txt", FILE_WRITE);
      myFile.print(F("NANO SMART AGRO - MENSAGEM NÃO ENVIADA AO SERVER UBIDOTS, DEVICE: **********"));
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Enviadas: "));
      myFile.print(msg_counterok1);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas: "));
      myFile.print(msg_counternok1);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas no Dia: "));
      myFile.print(msg_counternok1_resete);
      myFile.print(F(";"));
      myFile.print(F(" DATA: "));
      myFile.print(t.date, DEC);
      myFile.print(F("/"));
      myFile.print(t.mon, DEC);
      myFile.print(F("/"));
      myFile.print(t.year, DEC);
      myFile.print(F(";"));
      myFile.print(F(" HORARIO: "));
      myFile.print(rtc.getTimeStr());
      myFile.print(F(";"));
      myFile.print(F(" STRING: "));
      myFile.print(msg);
      myFile.print(F(";"));
      myFile.print(F(" GSM SINAL: "));
      myFile.print(ss);
      myFile.print(F(";"));
      myFile.print(F(" IP:"));
      myFile.print(local);
      myFile.println();
      delay(1000);
      myFile.close();
      delay(2000);

      tft.setCursor(5, 278);
      tft.setTextColor(CYAN);
      tft.print(F("Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counterok1);

      tft.setCursor(5, 298);
      tft.setTextColor(CYAN);
      tft.print(F("Nao Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counternok1);
      delay(3000);

      return;
    }
  }
}


// ========================================================================================================
// FUNÇÃO PARA CRIAR A STRING JSON PARA ENVIO DAS INFORMAÇÕES AO SERVER UBIDOTS:

String createJsonString1()
{

  const int c_aux = 87451;
  const float pi = 3.1416;
  const int altura_caixa = 109;

  // ========================================================================================================
  // TRATAMENTO DA INDICAÇÃO DA VÁRIALVEL NIVEL E VOLUME DOS RESERVATÓRIOS, CASO HAJA FALHA NO MÓDULO ELA INDICARÁ O CM!!

  pinMode(pinVCC_Nivel, OUTPUT);           // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DE SENSORES
  pinMode(pinGND_Nivel, OUTPUT);           // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DE SENSORES
  digitalWrite(pinVCC_Nivel, true);        // aux VCC
  digitalWrite(pinGND_Nivel, false);       // aux GND

  delay(1000);
  Ultrasonic ultrasonic(12, 11); // 12 - CINZA ECHO // 11 - TRIGGER BRANCO
  distance = ultrasonic.read();

  // ========================================================================================================
  // TRATAMENTO DA INDICAÇÃO DA VÁRIALVEL NIVEL, CASO HAJA FALHA NO MÓDULO ELA INDICARÁ O CM!!

  if (distance == 357) {
    volume_reservatorio = 0;
    volume_Min = 0;
    nivel = 0;
    nivelMin = -1;
  } else {
    nivel = altura_caixa - distance;
    volume_reservatorio = (((nivel * pi) / 3) * c_aux);
    volume_reservatorio = volume_reservatorio / 1000;
    volume_reservatorio = volume_reservatorio * 2;
  }

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL VAZÃO:

  float v10 = Litros;
  if (v10 <= 2.00){
    v10 = 0.00;
  }
  
  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL PRECIPTAÇÃO EM %:

  for (int i = 0; i <= 100; i++) {
    chuva_analog = analogRead(chuvaPIN);
    valor5 = valor5 + chuva_analog;
  }

  preciptacao1 = valor5 / 100;

  preciptacao = ((preciptacao1 - minimo2) / (maximo2 - minimo2)) * 100;
  preciptacao = (preciptacao - 100) * -1;
  valor5 = 0;
  preciptacao1 = 0;

  if (preciptacao < cpmin)
  {
    cpmin = preciptacao;
  }
  if (preciptacao > cpmax)
  {
    cpmax = preciptacao;
  }

  if (preciptacao <= 4.99) {
    preciptacao = 0.0;
  }

  if (preciptacao >= 100.00) {
    preciptacao = 99.9;
  }


  float prec10 = preciptacao;

  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO DA PRECIPTAÇÃO EM mm: 1 milímetro de chuva significa um litro de água acumulado em um metro quadrado.
  // Quando a gente diz que teve uma chuva de 200 milímetros, em 24h, significa que 200 litros d’água caíram num metro quadrado.

  volatile int pluvPulsos = contaPulso1;
  float c10 = pluvPulsos * 0.25;  // Mede a quantidade de chuva em milimitros!


  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL LUMINOSFIDADE EM LUX:

  float l10 = lux;

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL ÍNDICE UV:

  float uv10 = UV_index;

  // ========================================================================================================
  // CRIAÇÃO DA STRING DAS VARIAVEIS QUE SERÃO ENVIADAS PARA O UBIDOTS:

  // *******IMPORTANTE É APENAS PERMITIDO QUE ENVIE 9 VARIAVEIS AO UBIDOTS!!!!!*****************

  String data = "{";

  data += "\"VOLUME\":";
  data += String(volume_reservatorio);
  data += ",";

  data += "\"NIVEL\":";
  data += String(nivel);
  data += ",";

  data += "\"PLUVIOMETRO\":";
  data += String(c10);
  data += ",";

  data += "\"LUMINOSIDADE\":";
  data += String(l10);
  data += ",";

  data += "\"ORVALHO-CHUVA\":";
  data += String(prec10);
  data += ",";

  data += "\"INDICE UV\":";
  data += String(uv10);
  data += ",";

  data += "\"MSG SD CARD OK\":";
  data += String(msg_sdcard_ok);
  data += ",";

  data += "\"MSG SD CARD NOK\":";
  data += String(msg_sdcard_nok);
  data += ",";

  data += "\"TOTALIZADOR\":";
  data += String(v10);
  data += "}";

  return data;
}



unsigned long testLines_SD(uint16_t color) {
  int           x1, y1, x2, y2,
                w = tft.width(),
                h = tft.height();

  tft.fillRect(0, 0, 240, 320, BLACK);
  yield();

  x1    = 0;
  y1    = h - 1;
  y2    = 0;

  for (x2 = 0; x2 < w; x2 += 6) tft.drawLine(x1, y1, x2, y2, color);
  x2    = w - 1;
  for (y2 = 0; y2 < h; y2 += 6) tft.drawLine(x1, y1, x2, y2, color);

}



// ========================================================================================================
// FUNÇÃO PARA ENVIO DAS VARIAVEIS AO SERVIDOR DO THINGSPEAK:

void iot_thingspeak() {

  bool error_server_t = false;
  serialGSM.begin(9600);
  rtc.begin();
  t = rtc.getTime();

  tft.fillRect(0, 0, 240, 320, BLACK);
  tft.fillRect(0, 0, 240, 35, RED);

  tft.setCursor(2, 5);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(F("THINGSPEAK"));
  tft.setCursor(185, 5);
  tft.print(F("IoT"));

  delay(1000);

  // ========================================================================================================
  //INICIANDO SETUP MODULO GSM/GPRS SIM 800L:


  tft.setCursor(5, 40);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("Channel ID:"));
  tft.setTextColor(WHITE);
  tft.print(F("9999999"));

  sendAT("AT+GSMBUSY=1");
  delay(1000);

  int sim = modemGSM.getSimStatus();

  tft.setCursor(5, 80);
  tft.setTextColor(CYAN);
  tft.print(F("Status SIM CARD:"));
  tft.setTextColor(WHITE);
  if (sim == 1) {
    tft.print(F("OK"));
  } else {
    tft.setTextColor(RED);
    tft.print(F("NOK"));

    msg_counternok_t++;
    msg_counternok_t_resete++;
    
    delay(1000);
    tft.setCursor(5, 278);
    tft.setTextColor(CYAN);
    tft.print(F("Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counterok_t);

    tft.setCursor(5, 298);
    tft.setTextColor(CYAN);
    tft.print(F("Nao Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counternok_t);
    delay(3000);

    int pino53 = 53;
    pinMode(pino53, OUTPUT);

    delay(500);
    SD.begin(pino53);
    delay(500);
    myFile = SD.open("IoT2.txt", FILE_WRITE);
    myFile.print(F("NANO SMART AGRO - MENSAGEM NÃO ENVIADA AO SERVER THINGSPEAK, CHANNEL: 999999"));
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Enviadas: "));
    myFile.print(msg_counterok_t);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas: "));
    myFile.print(msg_counternok_t);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas no Dia: "));
    myFile.print(msg_counternok_t_resete);
    myFile.print(F(";"));
    myFile.print(F(" SIM CARD NOK! "));
    myFile.print(F(";"));
    myFile.print(F(" DATA: "));
    myFile.print(t.date, DEC);
    myFile.print(F("/"));
    myFile.print(t.mon, DEC);
    myFile.print(F("/"));
    myFile.print(t.year, DEC);
    myFile.print(F(";"));
    myFile.print(F(" HORARIO: "));
    myFile.print(rtc.getTimeStr());
    myFile.println();
    delay(1000);
    myFile.close();
    delay(2000);

    return;
  }

  delay(1000);

  int ss = modemGSM.getSignalQuality();
  tft.setCursor(5, 100);
  tft.setTextColor(CYAN);
  tft.print(F("Sinal Quality:"));

  if ( ss >= 31) {
    tft.setTextColor(RED);
  }

  if ( ss <= 30 && ss >= 20) {
    tft.setTextColor(WHITE);
  }
  if ( ss <= 19 && ss >= 15) {
    tft.setTextColor(WHITE);
  }
  if ( ss < 15 && ss >= 10) {
    tft.setTextColor(YELLOW);
  }
  if ( ss < 10) {
    tft.setTextColor(RED);
  }

  tft.print(ss);
  delay(1000);

  tft.setCursor(5, 120);
  tft.setTextColor(CYAN);
  tft.print(F("Sinal GSM:"));

  tft.setCursor(125, 120);
  tft.setTextColor(WHITE);

  if ( ss >= 31) {
    tft.print(F("EM FALHA!"));
  }

  if ( ss <= 30 && ss >= 20 ) {
    tft.print(F("Excelente"));
  }
  if ( ss <= 19 && ss >= 15) {
    tft.print(F("Otimo"));
  }
  if ( ss < 15 && ss >= 10) {
    tft.print(F("Bom"));
  }
  if ( ss < 10) {
    tft.print(F("Fraco"));
  }

  //client.setKeepAlive (60);
  delay(1000);

  tft.setCursor(5, 140);
  tft.setTextColor(CYAN);
  tft.print(F("GPRS Connection:"));
  tft.setTextColor(WHITE);

  bool res = modemGSM.isGprsConnected();

  if (res == 1) {
    delay(1000);
    tft.print("OK");

  } else {

    if (modemGSM.gprsConnect(apn, gprsUser, gprsPass) == 1) {
      delay(3000);
      tft.print(F("OK"));

    } else {
      delay(3000);
      tft.setTextColor(RED);
      tft.print(F("NOK"));

      msg_counternok_t ++;
      msg_counternok_t_resete++;
      
      delay(1000);
      tft.setCursor(5, 278);
      tft.setTextColor(CYAN);
      tft.print(F("Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counterok_t);

      tft.setCursor(5, 298);
      tft.setTextColor(CYAN);
      tft.print(F("Nao Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counternok_t);
      delay(3000);

      int pino53 = 53;
      pinMode(pino53, OUTPUT);

      delay(500);
      SD.begin(pino53);
      delay(500);
      myFile = SD.open("IoT2.txt", FILE_WRITE);
      myFile.print(F("NANO SMART AGRO - MENSAGEM NÃO ENVIADA AO SERVER THINGSPEAK, CHANNEL: 999999"));
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Enviadas: "));
      myFile.print(msg_counterok_t);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas: "));
      myFile.print(msg_counternok_t);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas no Dia: "));
      myFile.print(msg_counternok_t_resete);
      myFile.print(F(";"));
      myFile.print(F(" GPRS NOT CONNECT! "));
      myFile.print(F(";"));
      myFile.print(F(" DATA: "));
      myFile.print(t.date, DEC);
      myFile.print(F("/"));
      myFile.print(t.mon, DEC);
      myFile.print(F("/"));
      myFile.print(t.year, DEC);
      myFile.print(F(";"));
      myFile.print(F(" HORARIO: "));
      myFile.print(rtc.getTimeStr());
      myFile.print(F(";"));
      myFile.print(F(" GSM SINAL: "));
      myFile.print(ss);
      myFile.println();
      delay(1000);
      myFile.close();
      delay(2000);

      return;

    }


  }

  delay(1000);

  IPAddress local = modemGSM.localIP();
  tft.setCursor(5, 160);
  tft.setTextColor(CYAN);
  tft.print(F("IP:"));
  tft.setTextColor(WHITE);
  tft.print(local);

  delay(1000);
  client.setServer(server_T1, 1883); // atualizado Server

  while (!!!client.connect(clientIdMQTT, mqttUserName, mqttPassword)) {  // atualizado parâmetros do client connect
    tft.setCursor(5, 180);
    tft.setTextColor(WHITE);
    tft.print(F("ID:"));
    tft.setTextColor(RED);
    tft.print(F("SEM CONEXAO!"));

    tft.setCursor(5, 200);
    tft.setTextColor(WHITE);
    tft.print(F("ERROR MQTT SERVER: "));
    tft.setCursor(5, 220);
    tft.setTextColor(RED);

    status_server_t = client.state();
    
    if(status_server_t == -4){
      tft.print(F("CONNECTION_TIMEOUT"));
    }
    if(status_server_t == -3){
      tft.print(F("CONNECTION_LOST"));
    }
    if(status_server_t == -2){
      tft.print(F("CONNECTION_FAILED"));
    }
    if(status_server_t == -1){
      tft.print(F("MQTT_DISCONNECTED"));
    }
    if(status_server_t == 1){
      tft.print(F("BAD_PROTOCOL"));
    }
    if(status_server_t == 2){
      tft.print(F("BAD_CLIENT_ID"));
    }
    if(status_server_t == 3){
      tft.print(F("CONNECT_UNAVAILABLE"));
    }
    if(status_server_t == 4){
      tft.print(F("CONNECT_BAD_CREDENTIALS"));
    }
    if(status_server_t == 5){
      tft.print(F("CONNECT_UNAUTHORIZED"));
    }

    msg_counternok_t++;
    msg_counternok_t_resete++;
    
    delay(1000);
    error_server_t = true;

    tft.setCursor(5, 278);
    tft.setTextColor(CYAN);
    tft.print(F("Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counterok_t);

    tft.setCursor(5, 298);
    tft.setTextColor(CYAN);
    tft.print(F("Nao Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counternok_t);

    // ========================================================================================================
    //ENCERRANDO CONEXÃO COM O SERVER:

    client.disconnect();
    delay(5000);

    

    //    modemGSM.gprsDisconnect();  // caso a msg não for publicada, desconecta o GPRS para que haja um novo IP a ser identificado pelo Módulo SIM800L
    //    delay(5000);


    break;

  }

  if (error_server_t == true) {

    int pino53 = 53;
    pinMode(pino53, OUTPUT);

    delay(500);
    SD.begin(pino53);
    delay(500);
    myFile = SD.open("IoT2.txt", FILE_WRITE);
    myFile.print(F("NANO SMART AGRO - MENSAGEM NÃO ENVIADA AO SERVER THINGSPEAK, CHANNEL: 99999"));
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Enviadas: "));
    myFile.print(msg_counterok_t);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas: "));
    myFile.print(msg_counternok_t);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas no Dia: "));
    myFile.print(msg_counternok_t_resete);
    myFile.print(F(";"));
    myFile.print(F(" DATA: "));
    myFile.print(t.date, DEC);
    myFile.print(F("/"));
    myFile.print(t.mon, DEC);
    myFile.print(F("/"));
    myFile.print(t.year, DEC);
    myFile.print(F(";"));
    myFile.print(F(" HORARIO: "));
    myFile.print(rtc.getTimeStr());
    myFile.print(F(";"));
    myFile.print(F(" CLIENT ERROR: "));
    myFile.print(status_server1);
    myFile.print(F(";"));
    myFile.print(F(" GSM SINAL: "));
    myFile.print(ss);
    myFile.print(F(";"));
    myFile.print(F(" IP:"));
    myFile.print(local);
    myFile.println();
    delay(1000);
    myFile.close();
    delay(2000);

    return;


  } else {
    
    status_server_t = client.state();

    tft.setCursor(5, 180);
    tft.setTextColor(CYAN);
    tft.print(F("ID:"));
    if (status_server_t == 0) {
      tft.setTextColor(WHITE);
      tft.setTextSize(2);
      tft.print(F("Conectado"));
    }

    // Create data string to send to ThingSpeak:
    String data = createJsonString2();
    int length = data.length();
    const char *msgBuffer;
    msgBuffer = data.c_str();

    tft.drawRect(0, 200, 240, 1, YELLOW);
    tft.setCursor(5, 206);
    tft.setTextColor(CYAN);
    tft.setTextSize(1);
    tft.print(F("STRING:"));
    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    //tft.print(msgBuffer);
    tft.print(data);
    tft.drawRect(0, 255, 240, 1, YELLOW);

    //Parametro topic antigo:
    //String topicString = "channels/" + String( channelID ) + "/publish/" + String(writeAPIKey);
    
    // Atualizado o parametro topic:
    String topicString = "channels/" + String( channelID ) + "/publish";
    length = topicString.length();
    const char *topicBuffer;
    topicBuffer = topicString.c_str();

    bool status_publict1 = client.publish( topicBuffer, msgBuffer );

    if (status_publict1) {

      msg_counterok_t ++;

      tft.setCursor(5, 258);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("Mensagem:"));

      tft.setTextColor(WHITE);
      tft.print(F("Publicada"));
      tft.setCursor(5, 278);
      tft.setTextColor(CYAN);
      tft.print(F("Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counterok_t);

      tft.setCursor(5, 298);
      tft.setTextColor(CYAN);
      tft.print(F("Nao Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counternok_t);

      // ========================================================================================================
      //ENCERRANDO CONEXÃO COM O SERVER:

      client.disconnect();
      delay(5000);

      // ========================================================================================================
      //GRAVANDO OD DADOS NO SD CARD:

      int pino53 = 53;
      pinMode(pino53, OUTPUT);

      delay(500);
      SD.begin(pino53);
      delay(500);
      myFile = SD.open("IoT2.txt", FILE_WRITE);
      myFile.print(F("NANO SMART AGRO - Mensagem Enviada ao Sever THINGSPEAK, Channel: 999999"));
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Enviadas: "));
      myFile.print(msg_counterok_t);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas: "));
      myFile.print(msg_counternok_t);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas no Dia: "));
      myFile.print(msg_counternok_t_resete);
      myFile.print(F(";"));
      myFile.print(F(" DATA: "));
      myFile.print(t.date, DEC);
      myFile.print(F("/"));
      myFile.print(t.mon, DEC);
      myFile.print(F("/"));
      myFile.print(t.year, DEC);
      myFile.print(F(";"));
      myFile.print(F(" HORARIO: "));
      myFile.print(rtc.getTimeStr());
      myFile.print(F(";"));
      myFile.print(F(" STRING: "));
      myFile.print(msgBuffer);
      myFile.print(F(";"));
      myFile.print(F(" GSM SINAL: "));
      myFile.print(ss);
      myFile.print(F(";"));
      myFile.print(F(" IP:"));
      myFile.print(local);
      myFile.println();
      delay(1000);
      myFile.close();
      delay(2000);

      return;

    } else {

      tft.fillRect(0, 253, 240, 25, YELLOW);
      tft.setCursor(5, 258);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("Msg:"));
      tft.setTextColor(RED);
      tft.print(F("NAO Publicada!"));
      
      msg_counternok_t++;
      msg_counternok_t_resete++;

      client.disconnect();
      delay(2000);
      modemGSM.restart();
      delay(10000);

      //modemGSM.gprsDisconnect();  // caso a msg não for publicada, desconecta o GPRS para que haja um novo IP a ser identificado pelo Módulo SIM800L
      //delay(5000);

      // ========================================================================================================
      //GRAVANDO OD DADOS NO SD CARD:

      int pino53 = 53;
      pinMode(pino53, OUTPUT);

      delay(500);
      SD.begin(pino53);
      delay(500);
      myFile = SD.open("IoT2.txt", FILE_WRITE);
      myFile.print(F("NANO SMART AGRO - MENSAGEM NÃO ENVIADA AO SERVER THINGSPEAK, CHANNEL: 999999"));
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Enviadas: "));
      myFile.print(msg_counterok_t);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas: "));
      myFile.print(msg_counternok_t);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas no Dia: "));
      myFile.print(msg_counternok_t_resete);
      myFile.print(F(";"));
      myFile.print(F(" DATA: "));
      myFile.print(t.date, DEC);
      myFile.print(F("/"));
      myFile.print(t.mon, DEC);
      myFile.print(F("/"));
      myFile.print(t.year, DEC);
      myFile.print(F(";"));
      myFile.print(F(" HORARIO: "));
      myFile.print(rtc.getTimeStr());
      myFile.print(F(";"));
      myFile.print(F(" STRING: "));
      myFile.print(msgBuffer);
      myFile.print(F(";"));
      myFile.print(F(" GSM SINAL: "));
      myFile.print(ss);
      myFile.print(F(";"));
      myFile.print(F(" IP:"));
      myFile.print(local);
      myFile.println();
      delay(1000);
      myFile.close();
      delay(2000);

      tft.setCursor(5, 278);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counterok_t);

      tft.setCursor(5, 298);
      tft.setTextColor(CYAN);
      tft.print(F("Nao Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counternok_t);

      delay(3000);

      return;
    }
  }
}


// ========================================================================================================
// FUNÇÃO PARA CRIAR A STRING JSON PARA ENVIO DAS INFORMAÇÕES AO SERVER THINGSPEAK:

String createJsonString2()
{

  dht1.begin();
  delay(500);

  float h20 = dht1.readHumidity();
  float t20 = dht1.readTemperature();

  sensor_bmp.begin();

  /* Default settings from datasheet. */
  sensor_bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                         Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                         Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                         Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                         Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL UMIDADE P1 DO SOLO EM %:

  for (int i = 0; i <= 200; i++) {
    sensorP1 = analogRead(SensorUmidadeP1);
    umidP1_analog = umidP1_analog + sensorP1;
  }

  // FILTRO PARA GARATIR UMA LEITURA MAIS ESTÁVEL COM 200 MEDIÇÕES:

  valorumidadeP1 = umidP1_analog / 200;
  umidadeP1 = ((valorumidadeP1 - minimoP1) / (maximoP1 - minimoP1)) * 100;
  umidadeP1 = (umidadeP1 - 100) * -1;

  umidP1_analog = 0;
  valorumidadeP1 = 0;

  // LÓGICA DE PARA INDICAÇÃO DOS VALORES MÁXIMOS E MÍNIMOS:

  if (umidadeP1 < umSminP1)
  {
    umSminP1 = umidadeP1;
  }

  if (umidadeP1 > umSmaxP1)
  {
    umSmaxP1 = umidadeP1;
  }


  // FILTRO DE PARA INDICAÇÃO DOS LIMITES MÁXIMOS E MÍNIMOS:

  if (umidadeP1 <= 0) {
    umidadeP1 = 0.00;
  }

  if (umidadeP1 >= 100.00) {
    umidadeP1 = 99.99;
  }

  float u20 = umidadeP1;

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL UMIDADE P1 DO SOLO EM %:

  for (int i = 0; i <= 200; i++) {
    sensorP2 = analogRead(SensorUmidadeP2);
    umidP2_analog = umidP2_analog + sensorP2;
  }

  // FILTRO PARA GARATIR UMA LEITURA MAIS ESTÁVEL COM 200 MEDIÇÕES:

  valorumidadeP2 = umidP2_analog / 200;
  umidadeP2 = ((valorumidadeP2 - minimoP2) / (maximoP2 - minimoP2)) * 100;
  umidadeP2 = (umidadeP2 - 100) * -1;

  umidP2_analog = 0;
  valorumidadeP2 = 0;

  // LÓGICA DE PARA INDICAÇÃO DOS VALORES MÁXIMOS E MÍNIMOS:

  if (umidadeP2 < umSminP2)
  {
    umSminP2 = umidadeP2;
  }

  if (umidadeP2 > umSmaxP2)
  {
    umSmaxP2 = umidadeP2;
  }

  // FILTRO DE PARA INDICAÇÃO DOS LIMITES MÁXIMOS E MÍNIMOS:

  if (umidadeP2 <= 0) {
    umidadeP2 = 0.00;
  }

  if (umidadeP2 >= 100.00) {
    umidadeP2 = 99.99;
  }

  float uu20 = umidadeP2;

  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO DA PRECIPTAÇÃO EM mm: 1 milímetro de chuva significa um litro de água acumulado em um metro quadrado.
  // Quando a gente diz que teve uma chuva de 200 milímetros, em 24h, significa que 200 litros d’água caíram num metro quadrado.

  volatile int pluvPulsos = contaPulso1;
  float c20 = pluvPulsos * 0.25;  // Mede a quantidade de chuva em milimitros!

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL PRECIPTAÇÃO EM %:

  for (int i = 0; i <= 100; i++) {
    chuva_analog = analogRead(chuvaPIN);
    valor5 = valor5 + chuva_analog;
  }

  preciptacao1 = valor5 / 100;

  preciptacao = ((preciptacao1 - minimo2) / (maximo2 - minimo2)) * 100;
  preciptacao = (preciptacao - 100) * -1;
  valor5 = 0;
  preciptacao1 = 0;

  if (preciptacao < cpmin)
  {
    cpmin = preciptacao;
  }
  if (preciptacao > cpmax)
  {
    cpmax = preciptacao;
  }

  if (preciptacao <= 4.99) {
    preciptacao = 0.0;
  }

  if (preciptacao >= 100.00) {
    preciptacao = 99.9;
  }

  float prec20 = preciptacao;

  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA PRESSÃO ATMOSFÉRICA - MÓDULO BMP280:

  valor3 = 0;
  valorp = 0;

  for (int i = 0; i <= 100; i++) {
    valorp = sensor_bmp.readPressure();
    valor3 = valor3 + valorp;
  }

  p = valor3 / 100;
  p = p / 100;  // tranformando 1Pa em 1 mili Bar
  valor3 = 0;
  valorp = 0;

  float p20 = p;

  if (p < pMin)
  {
    pMin = p;
  }

  if (p > pMax)
  {
    pMax = p;
  }

  // ========================================================================================================
  // VARIAVEL DE INDICAÇÃO DE ALERA DE POSSIBILIDADE DE CHUVA (VALOR MAXIMO - VALOR MINIMO) > REFERENCIA: CHUVA!!

  float pa20 = pMax - pMin;

  // ========================================================================================================
  // CRIAÇÃO DA STRING DAS VARIAVEIS QUE SERÃO ENVIADAS PARA O SERVER IOT THINGSPEAK:

  String data = String("field1=") + String(t20, 1) + "&field2=" + String(h20, 1) + "&field3=" + String(u20, 2) + "&field4=" + String(uu20, 2) + "&field5=" + String(c20, 2) + "&field6=" + String(prec20, 2) + "&field7=" + String(pa20, 2) + "&field8=" + String(p20, 2);

  return data;
}



// ========================================================================================================
// FUNÇÃO PARA ENVIO DAS VARIAVEIS AO SERVIDOR DO THINGSPEAK: CHANNEL NANO SMART AGRO1

void iot_thingspeak1() {


  bool error_server_t1 = false;
  serialGSM.begin(9600);
  rtc.begin();
  t = rtc.getTime();

  tft.fillRect(0, 0, 240, 320, BLACK);
  tft.fillRect(0, 0, 240, 35, RED);

  tft.setCursor(2, 5);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(F("THINGSPEAK"));
  tft.setCursor(185, 5);
  tft.print(F("IoT"));

  delay(1000);

  // ========================================================================================================
  //INICIANDO SETUP MODULO GSM/GPRS SIM 800L:


  tft.setCursor(5, 40);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("Channel ID:"));
  tft.setTextColor(WHITE);
  tft.print(F("888888"));

  sendAT("AT+GSMBUSY=1");
  delay(1000);

  int sim = modemGSM.getSimStatus();

  tft.setCursor(5, 80);
  tft.setTextColor(CYAN);
  tft.print(F("Status SIM CARD:"));
  tft.setTextColor(WHITE);
  if (sim == 1) {
    tft.print(F("OK"));
  } else {
    tft.setTextColor(RED);
    tft.print(F("NOK"));

    msg_counternok_t1++;
    msg_counternok_t1_resete++;
    
    delay(1000);
    tft.setCursor(5, 278);
    tft.setTextColor(CYAN);
    tft.print(F("Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counterok_t1);

    tft.setCursor(5, 298);
    tft.setTextColor(CYAN);
    tft.print(F("Nao Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counternok_t1);
    delay(3000);

    int pino53 = 53;
    pinMode(pino53, OUTPUT);

    delay(500);
    SD.begin(pino53);
    delay(500);
    myFile = SD.open("IoT3.txt", FILE_WRITE);
    myFile.print(F("NANO SMART AGRO1 - MENSAGEM NÃO ENVIADA AO SERVER THINGSPEAK, CHANNEL: 8888888"));
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Enviadas: "));
    myFile.print(msg_counterok_t1);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas: "));
    myFile.print(msg_counternok_t1);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas no Dia: "));
    myFile.print(msg_counternok_t1_resete);
    myFile.print(F(";"));
    myFile.print(F(" SIM CARD NOK! "));
    myFile.print(F(";"));
    myFile.print(F(" DATA: "));
    myFile.print(t.date, DEC);
    myFile.print(F("/"));
    myFile.print(t.mon, DEC);
    myFile.print(F("/"));
    myFile.print(t.year, DEC);
    myFile.print(F(";"));
    myFile.print(F(" HORARIO: "));
    myFile.print(rtc.getTimeStr());
    myFile.println();
    delay(1000);
    myFile.close();
    delay(2000);

    return;
  }

  delay(1000);

  int ss = modemGSM.getSignalQuality();
  tft.setCursor(5, 100);
  tft.setTextColor(CYAN);
  tft.print(F("Sinal Quality:"));

  if ( ss >= 31) {
    tft.setTextColor(RED);
  }

  if ( ss <= 30 && ss >= 20) {
    tft.setTextColor(WHITE);
  }
  if ( ss <= 19 && ss >= 15) {
    tft.setTextColor(WHITE);
  }
  if ( ss < 15 && ss >= 10) {
    tft.setTextColor(YELLOW);
  }
  if ( ss < 10) {
    tft.setTextColor(RED);
  }

  tft.print(ss);
  delay(1000);

  tft.setCursor(5, 120);
  tft.setTextColor(CYAN);
  tft.print(F("Sinal GSM:"));

  tft.setCursor(125, 120);
  tft.setTextColor(WHITE);

  if ( ss >= 31) {
    tft.print(F("EM FALHA!"));
  }

  if ( ss <= 30 && ss >= 20 ) {
    tft.print(F("Excelente"));
  }
  if ( ss <= 19 && ss >= 15) {
    tft.print(F("Otimo"));
  }
  if ( ss < 15 && ss >= 10) {
    tft.print(F("Bom"));
  }
  if ( ss < 10) {
    tft.print(F("Fraco"));
  }

  //client.setKeepAlive (60);
  delay(1000);

  bool res = modemGSM.isGprsConnected();

  tft.setCursor(5, 140);
  tft.setTextColor(CYAN);
  tft.print(F("GPRS Connection:"));
  tft.setTextColor(WHITE);

  if (res == 1) {
    delay(1000);
    tft.print("OK");

  } else {

    if (modemGSM.gprsConnect(apn, gprsUser, gprsPass) == 1) {
      delay(3000);
      tft.print(F("OK"));

    } else {
      delay(3000);
      tft.setTextColor(RED);
      tft.print(F("NOK"));

      msg_counternok_t1 ++;
      delay(1000);
      tft.setCursor(5, 278);
      tft.setTextColor(CYAN);
      tft.print(F("Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counterok_t1);

      tft.setCursor(5, 298);
      tft.setTextColor(CYAN);
      tft.print(F("Nao Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counternok_t1);
      delay(3000);

      int pino53 = 53;
      pinMode(pino53, OUTPUT);

      delay(500);
      SD.begin(pino53);
      delay(500);
      myFile = SD.open("IoT3.txt", FILE_WRITE);
      myFile.print(F("NANO SMART AGRO1 - MENSAGEM NÃO ENVIADA AO SERVER THINGSPEAK, CHANNEL: 8888888"));
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Enviadas: "));
      myFile.print(msg_counterok_t1);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas: "));
      myFile.print(msg_counternok_t1);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas no Dia: "));
      myFile.print(msg_counternok_t1_resete);
      myFile.print(F(";"));
      myFile.print(F(" GPRS NOT CONNECT! "));
      myFile.print(F(";"));
      myFile.print(F(" DATA: "));
      myFile.print(t.date, DEC);
      myFile.print(F("/"));
      myFile.print(t.mon, DEC);
      myFile.print(F("/"));
      myFile.print(t.year, DEC);
      myFile.print(F(";"));
      myFile.print(F(" HORARIO: "));
      myFile.print(rtc.getTimeStr());
      myFile.print(F(";"));
      myFile.print(F(" GSM SINAL: "));
      myFile.print(ss);
      myFile.println();
      delay(1000);
      myFile.close();
      delay(2000);

      return;

    }


  }

  delay(1000);

  IPAddress local = modemGSM.localIP();
  tft.setCursor(5, 160);
  tft.setTextColor(CYAN);
  tft.print(F("IP:"));
  tft.setTextColor(WHITE);
  tft.print(local);

  delay(1000);
  client.setServer(server_T1, 1883); // atualizado Server

  while (!!!client.connect(clientIdMQTT, mqttUserName, mqttPassword)) {  // atualizado parâmetros do client connect
    tft.setCursor(5, 180);
    tft.setTextColor(WHITE);
    tft.print(F("ID:"));
    tft.setTextColor(RED);
    tft.print(F("SEM CONEXAO!"));

    tft.setCursor(5, 200);
    tft.setTextColor(WHITE);
    tft.print(F("ERROR MQTT SERVER: "));
    tft.setCursor(5, 220);
    tft.setTextColor(RED);

    status_server_t1 = client.state();
    
    if(status_server_t1 == -4){
      tft.print(F("CONNECTION_TIMEOUT"));
    }
    if(status_server_t1 == -3){
      tft.print(F("CONNECTION_LOST"));
    }
    if(status_server_t1 == -2){
      tft.print(F("CONNECTION_FAILED"));
    }
    if(status_server_t1 == -1){
      tft.print(F("MQTT_DISCONNECTED"));
    }
    if(status_server_t1 == 1){
      tft.print(F("BAD_PROTOCOL"));
    }
    if(status_server_t1 == 2){
      tft.print(F("BAD_CLIENT_ID"));
    }
    if(status_server_t1 == 3){
      tft.print(F("CONNECT_UNAVAILABLE"));
    }
    if(status_server_t1 == 4){
      tft.print(F("CONNECT_BAD_CREDENTIALS"));
    }
    if(status_server_t1 == 5){
      tft.print(F("CONNECT_UNAUTHORIZED"));
    }

    msg_counternok_t1++;
    msg_counternok_t1_resete++;
    
    delay(1000);
    error_server_t1 = true;

    tft.setCursor(5, 278);
    tft.setTextColor(CYAN);
    tft.print(F("Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counterok_t1);

    tft.setCursor(5, 298);
    tft.setTextColor(CYAN);
    tft.print(F("Nao Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counternok_t1);

    // ========================================================================================================
    //ENCERRANDO CONEXÃO COM O SERVER:

    client.disconnect();
    delay(5000);


    //modemGSM.gprsDisconnect();  // caso a msg não for publicada, desconecta o GPRS para que haja um novo IP a ser identificado pelo Módulo SIM800L
    //delay(5000);

    break;

  }

  if (error_server_t1 == true) {

    int pino53 = 53;
    pinMode(pino53, OUTPUT);

    delay(500);
    SD.begin(pino53);
    delay(500);
    myFile = SD.open("IoT3.txt", FILE_WRITE);
    myFile.print(F("NANO SMART AGRO1 - MENSAGEM NÃO ENVIADA AO SERVER THINGSPEAK, CHANNEL: 8888888"));
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Enviadas: "));
    myFile.print(msg_counterok_t1);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas: "));
    myFile.print(msg_counternok_t1);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas no Dia: "));
    myFile.print(msg_counternok_t1_resete);
    myFile.print(F(";"));
    myFile.print(F(" DATA: "));
    myFile.print(t.date, DEC);
    myFile.print(F("/"));
    myFile.print(t.mon, DEC);
    myFile.print(F("/"));
    myFile.print(t.year, DEC);
    myFile.print(F(";"));
    myFile.print(F(" HORARIO: "));
    myFile.print(rtc.getTimeStr());
    myFile.print(F(";"));
    myFile.print(F(" CLIENT ERROR: "));
    myFile.print(status_server_t1);
    myFile.print(F(";"));
    myFile.print(F(" GSM SINAL: "));
    myFile.print(ss);
    myFile.print(F(";"));
    myFile.print(F(" IP: "));
    myFile.print(local);
    myFile.println();
    delay(1000);
    myFile.close();
    delay(2000);

    return;


  } else {

    status_server_t1 = client.state();
    
    tft.setCursor(5, 180);
    tft.setTextColor(CYAN);
    tft.print(F("ID:"));
    if (status_server_t1 == 0) {
      tft.setTextColor(WHITE);
      tft.setTextSize(2);
      tft.print(F("Conectado"));
    }

    // Create data string to send to ThingSpeak:
    String data = createJsonString3();


    int length = data.length();
    const char *msgBuffer;
    msgBuffer = data.c_str();

    tft.drawRect(0, 200, 240, 1, YELLOW);
    tft.setCursor(5, 206);
    tft.setTextColor(CYAN);
    tft.setTextSize(1);
    tft.print(F("STRING:"));
    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    //tft.print(msgBuffer);
    tft.print(data);
    tft.drawRect(0, 255, 240, 1, YELLOW);
    
    //Parametro topic antigo:
    //String topicString = "channels/" + String( channelID1 ) + "/publish/" + String(writeAPIKey1);
    
    // Atualizado o parametro topic:
    String topicString = "channels/" + String( channelID1 ) + "/publish";
    length = topicString.length();
    const char *topicBuffer;
    topicBuffer = topicString.c_str();

    bool status_publict2 = client.publish( topicBuffer, msgBuffer );

    if (status_publict2) {

      msg_counterok_t1++;
      
      tft.setCursor(5, 258);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("Mensagem:"));

      tft.setTextColor(WHITE);
      tft.print(F("Publicada"));
      tft.setCursor(5, 278);
      tft.setTextColor(CYAN);
      tft.print(F("Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counterok_t1);

      tft.setCursor(5, 298);
      tft.setTextColor(CYAN);
      tft.print(F("Nao Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counternok_t1);

      // ========================================================================================================
      //ENCERRANDO CONEXÃO COM O SERVER:

      client.disconnect();
      delay(5000);

      // ========================================================================================================
      //GRAVANDO OD DADOS NO SD CARD:

      int pino53 = 53;
      pinMode(pino53, OUTPUT);

      delay(500);
      SD.begin(pino53);
      delay(500);
      myFile = SD.open("IoT3.txt", FILE_WRITE);
      myFile.print(F("NANO SMART AGRO1 - Mensagem Enviada ao Sever THINGSPEAK, CHANNEL: 888888"));
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Enviadas: "));
      myFile.print(msg_counterok_t1);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas: "));
      myFile.print(msg_counternok_t1);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas no Dia: "));
      myFile.print(msg_counternok_t1_resete);
      myFile.print(F(";"));
      myFile.print(F(" DATA: "));
      myFile.print(t.date, DEC);
      myFile.print(F("/"));
      myFile.print(t.mon, DEC);
      myFile.print(F("/"));
      myFile.print(t.year, DEC);
      myFile.print(F(";"));
      myFile.print(F(" HORARIO: "));
      myFile.print(rtc.getTimeStr());
      myFile.print(F(";"));
      myFile.print(F(" STRING: "));
      myFile.print(msgBuffer);
      myFile.print(F(";"));
      myFile.print(F(" GSM SINAL: "));
      myFile.print(ss);
      myFile.print(F(";"));
      myFile.print(F(" IP: "));
      myFile.print(local);
      myFile.println();
      delay(1000);
      myFile.close();
      delay(2000);

      return;

    } else {

      tft.fillRect(0, 253, 240, 25, YELLOW);
      tft.setCursor(5, 258);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("Msg:"));
      tft.setTextColor(RED);
      tft.print(F("NAO Publicada!"));
      
      msg_counternok_t1++;
      msg_counternok_t1_resete++;

      client.disconnect();
      delay(2000);
      modemGSM.restart();
      delay(10000);

      //modemGSM.gprsDisconnect();  // caso a msg não for publicada, desconecta o GPRS para que haja um novo IP a ser identificado pelo Módulo SIM800L
      //delay(5000);

      // ========================================================================================================
      //GRAVANDO OD DADOS NO SD CARD:

      int pino53 = 53;
      pinMode(pino53, OUTPUT);

      delay(500);
      SD.begin(pino53);
      delay(500);
      myFile = SD.open("IoT3.txt", FILE_WRITE);
      myFile.print(F("NANO SMART AGRO1 - MENSAGEM NÃO ENVIADA AO SERVER THINGSPEAK, CHANNEL: 888888"));
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Enviadas: "));
      myFile.print(msg_counterok_t1);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas: "));
      myFile.print(msg_counternok_t1);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas no Dia: "));
      myFile.print(msg_counternok_t1_resete);
      myFile.print(F(";"));
      myFile.print(F(" DATA: "));
      myFile.print(t.date, DEC);
      myFile.print(F("/"));
      myFile.print(t.mon, DEC);
      myFile.print(F("/"));
      myFile.print(t.year, DEC);
      myFile.print(F(";"));
      myFile.print(F(" HORARIO: "));
      myFile.print(rtc.getTimeStr());
      myFile.print(F(";"));
      myFile.print(F(" STRING: "));
      myFile.print(msgBuffer);
      myFile.print(F(";"));
      myFile.print(F(" GSM SINAL: "));
      myFile.print(ss);
      myFile.print(F(";"));
      myFile.print(F(" IP: "));
      myFile.print(local);
      myFile.println();
      delay(1000);
      myFile.close();
      delay(2000);

      tft.setCursor(5, 278);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counterok_t1);

      tft.setCursor(5, 298);
      tft.setTextColor(CYAN);
      tft.print(F("Nao Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counternok_t1);
      delay(3000);

      return;
    }
  }
}





// ========================================================================================================
// FUNÇÃO PARA CRIAR A STRING JSON PARA ENVIO DAS INFORMAÇÕES AO SERVER THINGSPEAK: CHANNEL NANO SMART AGRO1

String createJsonString3()
{

  dht2.begin();
  delay(500);

  // ========================================================================================================
  // VARIAVEl DE INDICAÇÃO TEMPERATURA INTERNA DO SENSOR DTH22:

  float t30 = dht2.readTemperature();

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL NÍVEL DOS RESERVATÓRIOS:

  float n30;
  float vol_res30;
  const int c_aux = 87451;
  const float pi = 3.1416;
  const int altura_caixa = 109;

  // ========================================================================================================
  // TRATAMENTO DA INDICAÇÃO DA VÁRIALVEL NIVEL E VOLUME DOS RESERVATÓRIOS, CASO HAJA FALHA NO MÓDULO ELA INDICARÁ O CM!!

  pinMode(pinVCC_Nivel, OUTPUT);           // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DE SENSORES
  pinMode(pinGND_Nivel, OUTPUT);           // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DE SENSORES
  digitalWrite(pinVCC_Nivel, true);        // aux VCC
  digitalWrite(pinGND_Nivel, false);       // aux GND

  delay(1000);
  Ultrasonic ultrasonic(12, 11); // 12 - CINZA ECHO // 11 - TRIGGER BRANCO
  int distance1 = ultrasonic.read();

  // ========================================================================================================
  // TRATAMENTO DA INDICAÇÃO DA VÁRIALVEL NIVEL, CASO HAJA FALHA NO MÓDULO ELA INDICARÁ O CM!!

  if (distance == 357) {
    volume_reservatorio = 0;
    vol_res30 = 0;
    volume_Min = 0;
    nivel = 0;
    nivelMin = -1;
    n30 = nivel;
  } else {
    nivel = altura_caixa - distance1;
    n30 = nivel;
    volume_reservatorio = (((nivel * pi) / 3) * c_aux);
    volume_reservatorio = volume_reservatorio / 1000;
    volume_reservatorio = volume_reservatorio * 2;
    vol_res30 = volume_reservatorio;
  }

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL VAZÃO:

  float v30 = Litros;
  if (v30 <= 2.00){
    v30 = 0.00;
  }
  

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL LUMINOSFIDADE EM LUX:

  float l30 = lux;

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL ÍNDICE UV:

  float uv30 = UV_index;

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL DE GRAVAÇÃO DO SD CARD:

  float sd_card_ok = msg_sdcard_ok;
  float sd_card_nok = msg_sdcard_nok;

  // ========================================================================================================
  // CRIAÇÃO DA STRING DAS VARIAVEIS QUE SERÃO ENVIADAS PARA O SERVER IOT THINGSPEAK:

  String data = String("field1=") + String(n30, 2) + "&field2=" + String(vol_res30, 1) + "&field3=" + String(v30, 1) + "&field4=" + String(uv30, 0) + "&field5=" + String(l30, 1) + "&field6=" + String(t30, 1) + "&field7=" + String(sd_card_ok, 0) + "&field8=" + String(sd_card_nok, 0);

  return data;
}







// ========================================================================================================
// FUNÇÃO PARA ENVIO DAS VARIAVEIS AO SERVIDOR DO THINGSPEAK: IoT - Vinhedo (PIEDADE-SP)

void iot_thingspeak2() {

  bool error_server_t2 = false;
  serialGSM.begin(9600);
  rtc.begin();
  t = rtc.getTime();

  tft.fillRect(0, 0, 240, 320, BLACK);
  tft.fillRect(0, 0, 240, 35, RED);

  tft.setCursor(2, 5);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(F("THINGSPEAK"));
  tft.setCursor(185, 5);
  tft.print(F("IoT"));

  delay(1000);

  // ========================================================================================================
  //INICIANDO SETUP MODULO GSM/GPRS SIM 800L:

  tft.setCursor(5, 40);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print(F("Channel ID:"));
  tft.setTextColor(WHITE);
  tft.print(F("777777"));

  sendAT("AT+GSMBUSY=1");
  delay(1000);

  int sim3 = modemGSM.getSimStatus();

  tft.setCursor(5, 80);
  tft.setTextColor(CYAN);
  tft.print(F("Status SIM CARD:"));
  tft.setTextColor(WHITE);
  if (sim3 == 1) {
    tft.print(F("OK"));
  } else {
    tft.setTextColor(RED);
    tft.print(F("NOK"));

    msg_counternok_t2 ++;
    delay(1000);
    tft.setCursor(5, 278);
    tft.setTextColor(CYAN);
    tft.print(F("Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counterok_t2);

    tft.setCursor(5, 298);
    tft.setTextColor(CYAN);
    tft.print(F("Nao Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counternok_t2);
    delay(3000);

    int pino53 = 53;
    pinMode(pino53, OUTPUT);

    delay(500);
    SD.begin(pino53);
    delay(500);
    myFile = SD.open("IoT4.txt", FILE_WRITE);
    myFile.print(F("NANO SMART AGRO2 - MENSAGEM NÃO ENVIADA AO SERVER THINGSPEAK, CHANNEL: 777777"));
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Enviadas: "));
    myFile.print(msg_counterok_t1);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas: "));
    myFile.print(msg_counternok_t1);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas no Dia: "));
    myFile.print(msg_counternok_t1_resete);
    myFile.print(F(";"));
    myFile.print(F(" SIM CARD NOK! "));
    myFile.print(F(";"));
    myFile.print(F(" DATA: "));
    myFile.print(t.date, DEC);
    myFile.print(F("/"));
    myFile.print(t.mon, DEC);
    myFile.print(F("/"));
    myFile.print(t.year, DEC);
    myFile.print(F(";"));
    myFile.print(F(" HORARIO: "));
    myFile.print(rtc.getTimeStr());
    myFile.println();
    delay(1000);
    myFile.close();
    delay(2000);

    return;
  }

  delay(1000);

  int ss = modemGSM.getSignalQuality();
  tft.setCursor(5, 100);
  tft.setTextColor(CYAN);
  tft.print(F("Sinal Quality:"));

  if ( ss >= 31) {
    tft.setTextColor(RED);
  }

  if ( ss <= 30 && ss >= 20) {
    tft.setTextColor(WHITE);
  }
  if ( ss <= 19 && ss >= 15) {
    tft.setTextColor(WHITE);
  }
  if ( ss < 15 && ss >= 10) {
    tft.setTextColor(YELLOW);
  }
  if ( ss < 10) {
    tft.setTextColor(RED);
  }

  tft.print(ss);
  delay(1000);

  tft.setCursor(5, 120);
  tft.setTextColor(CYAN);
  tft.print(F("Sinal GSM:"));

  tft.setCursor(125, 120);
  tft.setTextColor(WHITE);

  if ( ss >= 31) {
    tft.print(F("EM FALHA!"));
  }

  if ( ss <= 30 && ss >= 20 ) {
    tft.print(F("Excelente"));
  }
  if ( ss <= 19 && ss >= 15) {
    tft.print(F("Otimo"));
  }
  if ( ss < 15 && ss >= 10) {
    tft.print(F("Bom"));
  }
  if ( ss < 10) {
    tft.print(F("Fraco"));
  }

  //client.setKeepAlive (60);
  delay(1000);

  bool res3 = modemGSM.isGprsConnected();

  tft.setCursor(5, 140);
  tft.setTextColor(CYAN);
  tft.print(F("GPRS Connection:"));
  tft.setTextColor(WHITE);

  if (res3 == 1) {
    delay(1000);
    tft.print("OK");

  } else {

    if (modemGSM.gprsConnect(apn, gprsUser, gprsPass) == 1) {
      delay(3000);
      tft.print(F("OK"));

    } else {
      delay(3000);
      tft.setTextColor(RED);
      tft.print(F("NOK"));

      msg_counternok_t2++;
      msg_counternok_t2_resete++;
      
      delay(1000);
      tft.setCursor(5, 278);
      tft.setTextColor(CYAN);
      tft.print(F("Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counterok_t2);

      tft.setCursor(5, 298);
      tft.setTextColor(CYAN);
      tft.print(F("Nao Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counternok_t2);
      delay(3000);

      int pino53 = 53;
      pinMode(pino53, OUTPUT);

      delay(500);
      SD.begin(pino53);
      delay(500);
      myFile = SD.open("IoT4.txt", FILE_WRITE);
      myFile.print(F("NANO SMART AGRO2 - MENSAGEM NÃO ENVIADA AO SERVER THINGSPEAK, CHANNEL: 777777"));
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Enviadas: "));
      myFile.print(msg_counterok_t1);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas: "));
      myFile.print(msg_counternok_t1);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas no Dia: "));
      myFile.print(msg_counternok_t1_resete);
      myFile.print(F(";"));
      myFile.print(F(" GPRS NOT CONNECT! "));
      myFile.print(F(";"));
      myFile.print(F(" DATA: "));
      myFile.print(t.date, DEC);
      myFile.print(F("/"));
      myFile.print(t.mon, DEC);
      myFile.print(F("/"));
      myFile.print(t.year, DEC);
      myFile.print(F(";"));
      myFile.print(F(" HORARIO: "));
      myFile.print(rtc.getTimeStr());
      myFile.print(F(";"));
      myFile.print(F(" GSM SINAL: "));
      myFile.print(ss);
      myFile.println();
      delay(1000);
      myFile.close();
      delay(2000);

      return;

    }


  }

  delay(1000);

  IPAddress local = modemGSM.localIP();
  tft.setCursor(5, 160);
  tft.setTextColor(CYAN);
  tft.print(F("IP:"));
  tft.setTextColor(WHITE);
  tft.print(local);

  delay(1000);
  client.setServer(server_T1, 1883); // atualizado Server

  while (!!!client.connect(clientIdMQTT, mqttUserName, mqttPassword)) {  // atualizado parâmetros do client connect
    tft.setCursor(5, 180);
    tft.setTextColor(WHITE);
    tft.print(F("ID:"));
    tft.setTextColor(RED);
    tft.print(F("SEM CONEXAO!"));

    tft.setCursor(5, 200);
    tft.setTextColor(WHITE);
    tft.print(F("ERROR MQTT SERVER: "));
    tft.setCursor(5, 220);
    tft.setTextColor(RED);

    status_server_t2 = client.state();
    
    if(status_server_t2 == -4){
      tft.print(F("CONNECTION_TIMEOUT"));
    }
    if(status_server_t2 == -3){
      tft.print(F("CONNECTION_LOST"));
    }
    if(status_server_t2 == -2){
      tft.print(F("CONNECTION_FAILED"));
    }
    if(status_server_t2 == -1){
      tft.print(F("MQTT_DISCONNECTED"));
    }
    if(status_server_t2 == 1){
      tft.print(F("BAD_PROTOCOL"));
    }
    if(status_server_t2 == 2){
      tft.print(F("BAD_CLIENT_ID"));
    }
    if(status_server_t2 == 3){
      tft.print(F("CONNECT_UNAVAILABLE"));
    }
    if(status_server_t2 == 4){
      tft.print(F("CONNECT_BAD_CREDENTIALS"));
    }
    if(status_server_t2 == 5){
      tft.print(F("CONNECT_UNAUTHORIZED"));
    }

    msg_counternok_t2++;
    msg_counternok_t2_resete++;
    
    delay(1000);
    error_server_t2 = true;

    tft.setCursor(5, 278);
    tft.setTextColor(CYAN);
    tft.setTextSize(2);
    tft.print(F("Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counterok_t2);

    tft.setCursor(5, 298);
    tft.setTextColor(CYAN);
    tft.print(F("Nao Enviadas:"));
    tft.setTextColor(WHITE);
    tft.print(msg_counternok_t2);

    // ========================================================================================================
    //ENCERRANDO CONEXÃO COM O SERVER:

    client.disconnect();
    delay(5000);

    //modemGSM.gprsDisconnect();  // caso a msg não for publicada, desconecta o GPRS para que haja um novo IP a ser identificado pelo Módulo SIM800L
    //delay(5000);

    break;

  }

  if (error_server_t2 == true) {

    int pino53 = 53;
    pinMode(pino53, OUTPUT);

    delay(500);
    SD.begin(pino53);
    delay(500);
    myFile = SD.open("IoT4.txt", FILE_WRITE);
    myFile.print(F("NANO SMART AGRO2 - MENSAGEM NÃO ENVIADA AO SERVER THINGSPEAK, CHANNEL: 777777"));
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Enviadas: "));
    myFile.print(msg_counterok_t1);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas: "));
    myFile.print(msg_counternok_t1);
    myFile.print(F(";"));
    myFile.print(F(" Mensagens Não Enviadas no Dia: "));
    myFile.print(msg_counternok_t1_resete);
    myFile.print(F(";"));
    myFile.print(F(" DATA: "));
    myFile.print(t.date, DEC);
    myFile.print(F("/"));
    myFile.print(t.mon, DEC);
    myFile.print(F("/"));
    myFile.print(t.year, DEC);
    myFile.print(F(";"));
    myFile.print(F(" HORARIO: "));
    myFile.print(rtc.getTimeStr());
    myFile.print(F(";"));
    myFile.print(F(" CLIENT ERROR: "));
    myFile.print(status_server_t2);
    myFile.print(F(";"));
    myFile.print(F(" GSM SINAL: "));
    myFile.print(ss);
    myFile.print(F(";"));
    myFile.print(F(" IP: "));
    myFile.print(local);
    myFile.println();
    delay(1000);
    myFile.close();
    delay(2000);

    return;


  } else {


    tft.setCursor(5, 180);
    tft.setTextColor(CYAN);
    tft.print(F("ID:"));

    status_server_t2 = client.state();
    
    if (status_server_t2 == 0) {
      tft.setTextColor(WHITE);
      tft.setTextSize(2);
      tft.print(F("Conectado"));
    }
    
    // Create data string to send to ThingSpeak:
    String data = createJsonString4();
    int length = data.length();
    const char *msgBuffer;
    msgBuffer = data.c_str();

    tft.drawRect(0, 200, 240, 1, YELLOW);
    tft.setCursor(5, 206);
    tft.setTextColor(CYAN);
    tft.setTextSize(1);
    tft.print(F("STRING:"));
    tft.setTextColor(WHITE);
    tft.setTextSize(1);
    //tft.print(msgBuffer);
    tft.print(data);
    tft.drawRect(0, 255, 240, 1, YELLOW);

    //Parametro topic antigo:
    //String topicString = "channels/" + String( channelID2 ) + "/publish/" + String(writeAPIKey2);
    
    // Atualizado o parametro topic:
    String topicString = "channels/" + String( channelID2 ) + "/publish";
    length = topicString.length();
    const char *topicBuffer;
    topicBuffer = topicString.c_str();

    bool status_publict3 = client.publish( topicBuffer, msgBuffer );

    if (status_publict3) {

      tft.setCursor(5, 258);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("Mensagem:"));

      tft.setTextColor(WHITE);
      tft.print(F("Publicada"));
      msg_counterok_t2 ++;

      tft.setCursor(5, 278);
      tft.setTextColor(CYAN);
      tft.print(F("Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counterok_t2);

      tft.setCursor(5, 298);
      tft.setTextColor(CYAN);
      tft.print(F("Nao Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counternok_t2);

      // ========================================================================================================
      //ENCERRANDO CONEXÃO COM O SERVER:

      client.disconnect();
      delay(5000);

      // ========================================================================================================
      //GRAVANDO OD DADOS NO SD CARD:

      int pino53 = 53;
      pinMode(pino53, OUTPUT);

      delay(500);
      SD.begin(pino53);
      delay(500);
      myFile = SD.open("IoT4.txt", FILE_WRITE);
      myFile.print(F("NANO SMART AGRO2 - Mensagem Enviada ao Sever THINGSPEAK, CHANNEL: 777777"));
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Enviadas: "));
      myFile.print(msg_counterok_t1);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas: "));
      myFile.print(msg_counternok_t1);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas no Dia: "));
      myFile.print(msg_counternok_t1_resete);
      myFile.print(F(";"));
      myFile.print(F(" DATA: "));
      myFile.print(t.date, DEC);
      myFile.print(F("/"));
      myFile.print(t.mon, DEC);
      myFile.print(F("/"));
      myFile.print(t.year, DEC);
      myFile.print(F(";"));
      myFile.print(F(" HORARIO: "));
      myFile.print(rtc.getTimeStr());
      myFile.print(F(";"));
      myFile.print(F(" STRING: "));
      myFile.print(msgBuffer);
      myFile.print(F(";"));
      myFile.print(F(" GSM SINAL: "));
      myFile.print(ss);
      myFile.print(F(";"));
      myFile.print(F(" IP: "));
      myFile.print(local);
      myFile.println();
      delay(1000);
      myFile.close();
      delay(2000);
      
      return;

    } else {

      tft.fillRect(0, 253, 240, 25, YELLOW);
      tft.setCursor(5, 258);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("Msg:"));
      tft.setTextColor(RED);
      tft.print(F("NAO Publicada!"));

      msg_counternok_t2 ++;
      msg_counternok_t2_resete++;

      client.disconnect();
      delay(2000);
      modemGSM.restart();
      delay(10000);

      //modemGSM.gprsDisconnect();  // caso a msg não for publicada, desconecta o GPRS para que haja um novo IP a ser identificado pelo Módulo SIM800L
      //delay(5000);

      // ========================================================================================================
      //GRAVANDO OD DADOS NO SD CARD:

      int pino53 = 53;
      pinMode(pino53, OUTPUT);

      delay(500);
      SD.begin(pino53);
      delay(500);
      myFile = SD.open("IoT4.txt", FILE_WRITE);
      myFile.print(F("NANO SMART AGRO2 - MENSAGEM NÃO ENVIADA AO SERVER THINGSPEAK, CHANNEL: 777777"));
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Enviadas: "));
      myFile.print(msg_counterok_t1);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas: "));
      myFile.print(msg_counternok_t1);
      myFile.print(F(";"));
      myFile.print(F(" Mensagens Não Enviadas no Dia: "));
      myFile.print(msg_counternok_t1_resete);
      myFile.print(F(";"));
      myFile.print(F(" DATA: "));
      myFile.print(t.date, DEC);
      myFile.print(F("/"));
      myFile.print(t.mon, DEC);
      myFile.print(F("/"));
      myFile.print(t.year, DEC);
      myFile.print(F(";"));
      myFile.print(F(" HORARIO: "));
      myFile.print(rtc.getTimeStr());
      myFile.print(F(";"));
      myFile.print(F(" STRING: "));
      myFile.print(msgBuffer);
      myFile.print(F(";"));
      myFile.print(F(" GSM SINAL: "));
      myFile.print(ss);
      myFile.print(F(";"));
      myFile.print(F(" IP: "));
      myFile.print(ultimoGSM);
      myFile.println();
      delay(1000);
      myFile.close();
      delay(2000);

      tft.setCursor(5, 278);
      tft.setTextColor(CYAN);
      tft.setTextSize(2);
      tft.print(F("Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counterok_t2);

      tft.setCursor(5, 298);
      tft.setTextColor(CYAN);
      tft.print(F("Nao Enviadas:"));
      tft.setTextColor(WHITE);
      tft.print(msg_counternok_t2);
      delay(3000);

      return;
    }
  }
}





// ========================================================================================================
// FUNÇÃO PARA CRIAR A STRING JSON PARA ENVIO DAS INFORMAÇÕES AO SERVER THINGSPEAK: CHANNEL NANO SMART AGRO1

String createJsonString4()
{

  dht1.begin();
  delay(500);

  float h40 = dht1.readHumidity();
  float t40 = dht1.readTemperature();

  sensor_bmp.begin();

  /* Default settings from datasheet. */
  sensor_bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                         Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                         Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                         Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                         Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL UMIDADE P1 DO SOLO EM %:

  for (int i = 0; i <= 200; i++) {
    sensorP1 = analogRead(SensorUmidadeP1);
    umidP1_analog = umidP1_analog + sensorP1;
  }

  // FILTRO PARA GARATIR UMA LEITURA MAIS ESTÁVEL COM 200 MEDIÇÕES:

  valorumidadeP1 = umidP1_analog / 200;
  umidadeP1 = ((valorumidadeP1 - minimoP1) / (maximoP1 - minimoP1)) * 100;
  umidadeP1 = (umidadeP1 - 100) * -1;

  umidP1_analog = 0;
  valorumidadeP1 = 0;

  // LÓGICA DE PARA INDICAÇÃO DOS VALORES MÁXIMOS E MÍNIMOS:

  if (umidadeP1 < umSminP1)
  {
    umSminP1 = umidadeP1;
  }

  if (umidadeP1 > umSmaxP1)
  {
    umSmaxP1 = umidadeP1;
  }


  // FILTRO DE PARA INDICAÇÃO DOS LIMITES MÁXIMOS E MÍNIMOS:

  if (umidadeP1 <= 0) {
    umidadeP1 = 0.00;
  }

  if (umidadeP1 >= 100.00) {
    umidadeP1 = 99.99;
  }

  float u40 = umidadeP1;

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL UMIDADE P1 DO SOLO EM %:

  for (int i = 0; i <= 200; i++) {
    sensorP2 = analogRead(SensorUmidadeP2);
    umidP2_analog = umidP2_analog + sensorP2;
  }

  // FILTRO PARA GARATIR UMA LEITURA MAIS ESTÁVEL COM 200 MEDIÇÕES:

  valorumidadeP2 = umidP2_analog / 200;
  umidadeP2 = ((valorumidadeP2 - minimoP2) / (maximoP2 - minimoP2)) * 100;
  umidadeP2 = (umidadeP2 - 100) * -1;

  umidP2_analog = 0;
  valorumidadeP2 = 0;

  // LÓGICA DE PARA INDICAÇÃO DOS VALORES MÁXIMOS E MÍNIMOS:

  if (umidadeP2 < umSminP2)
  {
    umSminP2 = umidadeP2;
  }

  if (umidadeP2 > umSmaxP2)
  {
    umSmaxP2 = umidadeP2;
  }

  // FILTRO DE PARA INDICAÇÃO DOS LIMITES MÁXIMOS E MÍNIMOS:

  if (umidadeP2 <= 0) {
    umidadeP2 = 0.00;
  }

  if (umidadeP2 >= 100.00) {
    umidadeP2 = 99.99;
  }

  float uu40 = umidadeP2;

  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO MÁXIMA E MÍNIMA DA PRESSÃO ATMOSFÉRICA - MÓDULO BMP280:

  valor3 = 0;
  valorp = 0;

  for (int i = 0; i <= 100; i++) {
    valorp = sensor_bmp.readPressure();
    valor3 = valor3 + valorp;
  }

  p = valor3 / 100;
  p = p / 100;  // tranformando 1Pa em 1 mili Bar
  valor3 = 0;
  valorp = 0;

  float p40 = p;

  if (p < pMin)
  {
    pMin = p;
  }

  if (p > pMax)
  {
    pMax = p;
  }


  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL NÍVEL DOS RESERVATÓRIOS:

  const int altura_caixa4 = 109;
  float n40;

  // ========================================================================================================
  // TRATAMENTO DA INDICAÇÃO DA VÁRIALVEL NIVEL E VOLUME DOS RESERVATÓRIOS, CASO HAJA FALHA NO MÓDULO ELA INDICARÁ O CM!!

  pinMode(pinVCC_Nivel, OUTPUT);           // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DE SENSORES
  pinMode(pinGND_Nivel, OUTPUT);           // ALIMENTAÇÃO AUXILIAR DA PLACA INTERNA DE SENSORES
  digitalWrite(pinVCC_Nivel, true);        // aux VCC
  digitalWrite(pinGND_Nivel, false);       // aux GND

  delay(1000);
  Ultrasonic ultrasonic(12, 11); // 12 - CINZA ECHO // 11 - TRIGGER BRANCO
  int distance4 = ultrasonic.read();

  // ========================================================================================================
  // TRATAMENTO DA INDICAÇÃO DA VÁRIALVEL NIVEL, CASO HAJA FALHA NO MÓDULO ELA INDICARÁ O CM!!

  if (distance == 357) {
    nivel = 0;
    nivelMin = -1;
    n40 = nivel;
  } else {
    nivel = altura_caixa4 - distance4;
    n40 = nivel;
  }

  // ========================================================================================================
  // CÁLCULO PARA EXIBIR A VARIÁVEL VAZÃO:

  float v40 = Litros;
  if (v40 <= 2.00){
    v40 = 0.00;
  }
  // ========================================================================================================
  // VARIAVEIS DE INDICAÇÃO DA PRECIPTAÇÃO EM mm: 1 milímetro de chuva significa um litro de água acumulado em um metro quadrado.
  // Quando a gente diz que teve uma chuva de 200 milímetros, em 24h, significa que 200 litros d’água caíram num metro quadrado.

  volatile int pluvPulsos40 = contaPulso1;
  float c40 = pluvPulsos40 * 0.25;  // Mede a quantidade de chuva em milimitros!

  // ========================================================================================================
  // CRIAÇÃO DA STRING DAS VARIAVEIS QUE SERÃO ENVIADAS PARA O SERVER IOT THINGSPEAK:

  String data = String("field1=") + String(t40, 1) + "&field2=" + String(h40, 1) + "&field3=" + String(u40, 2) + "&field4=" + String(uu40, 2) + "&field5=" + String(p40, 1) + "&field6=" + String(c40, 2) + "&field7=" + String(v40, 1) + "&field8=" + String(n40, 1);

  return data;
}
