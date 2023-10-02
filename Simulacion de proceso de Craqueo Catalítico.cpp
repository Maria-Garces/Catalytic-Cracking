/*	Programa que simula el proceso de craqueo catalítico de la refinería Amuay - Punto Fijo, Venezuela

	Programa realizado por:
	- María Garcés
	- Alejandro Rodríguez
	- Gabriel Pacheco
	- Alan Ruz
	
	Fecha:
	
*/

#include<iostream> // Mostrar datos en pantalla
#include<fstream> // leer y escribir en un archivo de texto
#include<windows.h> // Control de ejecución (tiempo de refrescamiento de pantalla)
using namespace std;

int main()
{
 string bomba_cat="ENCENDIDA";
 string bomba_cru="ENCENDIDA";
 double presion_cat=30;
 double presion_cru=40;
 string switch_temp="ON";
 double temperatura=79;
 string pantalla="ON";
 int aux = 0;
 
 // Leemos los datos del archivo de texto prueba a través de la función
 // Casabe (Puede ser cualquier nombre)
 
 inicio:
 
 ifstream leer("c://simulacion//torre.txt"); 
  
 int perturbacion;
 string switch_pres_dif;
 string valvula;
  
 leer>>perturbacion>>switch_pres_dif>>valvula; 
  
 // imprimimos los valores en pantalla
 
 	if(pantalla=="ON")
 		{
			system("cls");
			cout <<" - La bomba de crudo esta = "<<bomba_cru<<endl;
			cout <<" - La bomba de catalizador esta = "<<bomba_cat<<endl;
	 		cout <<"-  La Presion de la bomba de crudo = "<<presion_cru<<" psi"<<endl;
	 		cout <<"-  La Presion de la bomba de catalizador = "<<presion_cat<<" psi"<<endl;   
	 		cout <<" - El Switch de temperatura esta en = "<<switch_temp<<endl;
	 		cout <<" - La temperatura esta a = "<<temperatura<<" grados centigrados"<<endl;
	 		cout <<" - La perturbacion es de = "<<perturbacion<<" grados centigrados"<<endl;
	 		cout <<" - El Switch de Presión Diferencial esta en = "<<switch_pres_dif<<endl;  
	    	cout <<" - La valvula manual esta = "<<valvula<<endl;
	 		pantalla ="OFF"; 
   		}	

//  Establecemos un tiempo de 1 de segundo para ver los cambios de la pantalla

    Sleep (1000);
    
// Simulamos el funcionamiento del Transmisor de Temperatura

			
    
// Simulamos el funcionamiento del Switch de Temperatura 
	if(temperatura>100 and switch_temp == "ON")
	{
		switch_temp="OFF";
		pantalla = "ON";
	}
	if(temperatura<95 and switch_temp == "OFF")
	{
		switch_temp="ON";
		pantalla = "ON";
	}
	
// Simulamos el funcionamiento del Transmisor de Presión de la Bomba de Crudo
	if(bomba_cru == "ENCENDIDA")
	{
		if(presion_cru < 70)
		{
			presion_cru = presion_cru + 1;
			pantalla = "ON";
		} 
		if(presion_cru > 70)
		{
			presion_cru = presion_cru - 1;
			pantalla = "ON";
		}
	}
	if(bomba_cru == "APAGADA")
	{
		presion_cru = presion_cru - 1;
		pantalla = "ON";
	}
	if (presion_cru<0)
    {
     	presion_cru=0;
     	pantalla ="ON";
    }
	
// Controlamos el encendido y apagado de la Bomba de Crudo
	if(presion_cru<50 and switch_temp == "ON" and switch_pres_dif == "ON" and bomba_cru == "APAGADA")
	{
		bomba_cru = "ENCENDIDA";
		pantalla = "ON";
	}
	if(presion_cru<50 and switch_temp == "ON" and switch_pres_dif == "OFF" and bomba_cru == "ENCENDIDA")
	{
		bomba_cru = "APAGADA";
		pantalla = "ON";
	}
	if(presion_cru<50 and switch_temp == "OFF" and switch_pres_dif == "ON" and bomba_cru == "ENCENDIDA")
	{
		bomba_cru = "APAGADA";
		pantalla = "ON";
	} 
	if(presion_cru<50 and switch_temp == "OFF" and switch_pres_dif == "OFF" and bomba_cru == "ENCENDIDA")
	{
		bomba_cru = "APAGADA";
		pantalla = "ON";
	}
	if(presion_cru>90 and switch_temp == "ON" and switch_pres_dif == "ON" and bomba_cru == "ENCENDIDA")
	{
		bomba_cru = "APAGADA";
		pantalla = "ON";
	}
	if(presion_cru>90 and switch_temp == "ON" and switch_pres_dif == "OFF" and bomba_cru == "ENCENDIDA")
	{
		bomba_cru = "APAGADA";
		pantalla = "ON";
	}
	if(presion_cru>90 and switch_temp == "OFF" and switch_pres_dif == "ON" and bomba_cru == "ENCENDIDA")
	{
		bomba_cru = "APAGADA";
		pantalla = "ON";
	}
	if(presion_cru>90 and switch_temp == "OFF" and switch_pres_dif == "OFF" and bomba_cru == "ENCENDIDA")
	{
		bomba_cru = "APAGADA";
		pantalla = "ON";
	}
	if(presion_cru>=50 and presion_cru<=90 and switch_temp == "ON" and switch_pres_dif == "OFF" and bomba_cru == "ENCENDIDA")
	{
		bomba_cru = "APAGADA";
		pantalla = "ON";
	}
	if(presion_cru>=50 and presion_cru<=90 and switch_temp == "OFF" and switch_pres_dif == "ON" and bomba_cru == "ENCENDIDA")
	{
		bomba_cru = "APAGADA";
		pantalla = "ON";
	}
	if(presion_cru>=50 and presion_cru<=90 and switch_temp == "OFF" and switch_pres_dif == "OFF" and bomba_cru == "ENCENDIDA")
	{
		bomba_cru = "APAGADA";
		pantalla = "ON";
	}
	
// Simulamos el funcionamiento del Transmisor de Presión de la Bomba de Catalizador
	if(bomba_cat == "ENCENDIDA" and valvula == "ABIERTA")
	{
		if(presion_cat < 55)
		{
			presion_cat = presion_cat + 1;
			pantalla = "ON";
		}
		if(presion_cat > 55)
		{
			presion_cat = presion_cat - 1;
			pantalla = "ON";
		} 
	}
	if(bomba_cat == "ENCENDIDA" and valvula == "CERRADA")
	{
		presion_cat = presion_cat + 2;
		pantalla = "ON";
	}
	if(bomba_cat == "APAGADA" and valvula == "ABIERTA")
	{
		presion_cat = presion_cat - 1;
		pantalla = "ON";
	}
		if (presion_cat<0)
    {
     	presion_cat=0;
     	pantalla ="ON";
    }
	
// Controlamos el encendido y apagado de la Bomba de Catalizador
	if(presion_cat<40 and switch_temp == "ON" and switch_pres_dif == "ON" and bomba_cat == "APAGADA")
	{
		bomba_cat = "ENCENDIDA";
		pantalla = "ON";
	}
	if(presion_cat<40 and switch_temp == "ON" and switch_pres_dif == "OFF" and bomba_cat == "ENCENDIDA")
	{
		bomba_cat = "APAGADA";
		pantalla = "ON";
	}
	if(presion_cat<40 and switch_temp == "OFF" and switch_pres_dif == "ON" and bomba_cat == "ENCENDIDA")
	{
		bomba_cat = "APAGADA";
		pantalla = "ON";
	} 
	if(presion_cat<40 and switch_temp == "OFF" and switch_pres_dif == "OFF" and bomba_cat == "ENCENDIDA")
	{
		bomba_cat = "APAGADA";
		pantalla = "ON";
	}
	if(presion_cat>70 and switch_temp == "ON" and switch_pres_dif == "ON" and bomba_cat == "ENCENDIDA")
	{
		bomba_cat = "APAGADA";
		pantalla = "ON";
	}
	if(presion_cat>70 and switch_temp == "ON" and switch_pres_dif == "OFF" and bomba_cat == "ENCENDIDA")
	{
		bomba_cat = "APAGADA";
		pantalla = "ON";
	}
	if(presion_cat>70 and switch_temp == "OFF" and switch_pres_dif == "ON" and bomba_cat == "ENCENDIDA")
	{
		bomba_cat = "APAGADA";
		pantalla = "ON";
	}
	if(presion_cat>70 and switch_temp == "OFF" and switch_pres_dif == "OFF" and bomba_cat == "ENCENDIDA")
	{
		bomba_cat = "APAGADA";
		pantalla = "ON";
	}
	if(presion_cat>=40 and presion_cat<=70 and switch_temp == "ON" and switch_pres_dif == "OFF" and bomba_cat == "ENCENDIDA")
	{
		bomba_cat = "APAGADA";
		pantalla = "ON";
	}
	if(presion_cat>=40 and presion_cat<=70 and switch_temp == "OFF" and switch_pres_dif == "ON" and bomba_cat == "ENCENDIDA")
	{
		bomba_cat = "APAGADA";
		pantalla = "ON";
	}
	if(presion_cat>=40 and presion_cat<=70 and switch_temp == "OFF" and switch_pres_dif == "OFF" and bomba_cat == "ENCENDIDA")
	{
		bomba_cat = "APAGADA";
		pantalla = "ON";
	}		
 goto inicio;
 
}
