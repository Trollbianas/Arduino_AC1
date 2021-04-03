//variaveis da led
const int vermelho = 5;
const int verde = 6;
const int azul = 7;

bool estadoLedVermelho = false;

//iniciação  das constantes 1  e 2
const int botao1 = 2;
const int botao2 = 3;

unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
const int botaoDelay = 100;

//inicializaç do setup
void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  
  Serial.begin(9600);
	
  Serial.println("AC1 - Meu Primeiro Projeto 2021");
  Serial.println("     V1.0");
  Serial.println("Grupo:TROLLBIANAS");
}

// determinando o loop

void loop()
{
// regra do botão 1
  if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(botao1)){
  	Serial.println("início prod");
    ledVermelho(true);
  	lastDebounceTime1 = millis();
  }
	
// regra do botão 2
 if((millis() - lastDebounceTime2) > botaoDelay && digitalRead(botao2)){
	Serial.Sprintln("final prod");
    ledVermelho(false);
	 lastDebounceTime2 = millis();
 }
		 
// regra de decisão do led verde
  if(getLuminosidade() > 5){
        ledVerde(false);
       Serial.println("luminosidade além do planejado");
  }else{
	ledVerde(true);
       Serial.println("luminosidade planejada");
  }

  //verificador de tempetura
  if(getTemperatura() > 15){
    ledAzul(false);
        Serial.println("temperatura além do planejado");
  }else{
  	ledAzul(true); 
       Serial.println("temperatura planejada");
  }  
  delay(10);
}

//definiçáo do estado do led
void ledAzul(bool estado){
  digitalWrite(azul,estado);
}

void ledVerde(bool estado){
  digitalWrite(verde,estado);
}

void ledVermelho(bool estado){
digitalWrite(vermelho,estado);
}

//calculo de temperaturo
int getTemperatura(){
  	int temperaturaC;
	temperaturaC = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  	return temperaturaC;
} 

//funcao de leitura da luminosidade
int getLuminosidade(){
  	int luminosidade;
	luminosidade = map(analogRead(A1), 6, 619, -3, 10);
  	return luminosidade;
}
