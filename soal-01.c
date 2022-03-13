/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 4 - Structures and Dynamic Arrays
*Percobaan        : -
*Hari dan Tanggal : Kamis, 17 Maret 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-01.c
*Deskripsi        : -
*/

/*
	Keterangan:
	Template ini hanya berperan sebagai pembantu
	Silakan ubah kode sesuka hati, asalakan output masih benar (jangan ubah fungsi processOutput)
*/

#define BUFF_LEN 512
#define MAX_STRLEN 30  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

typedef struct {
	char* name;
	float fuel; 
	float kml;
	float* x;
	float* y;
	float* z;
	int coordinateCount;
	float distance;
	float finalFuel;
} data;
 
//deklarasi fungsi
float power(float x, int y);
float squareRoot(float x);
void processOutput (data person);
void calculateFuelUsed (data *person);
void calculateDistance (data *person);
data loadFile(char filename[MAX_STRLEN]);

int main(){ 
	//inisialisasi variabel dan struct
	int index = 0; 
	data* data_tentara = malloc(sizeof *data_tentara); 

	//loop untuk membaca file dan memasukkannya ke struct data_tentara
	//bila user memasukkan string exit, loop berhenti
	while (1){
		char filename[MAX_STRLEN]; 
		
		printf("Masukkan nama file: ");
		scanf(" %s",filename); 

		if (strcmp(filename, "exit") == 0){
			printf("\n");
			break;
		}
		 
		//lengkapi ... untuk kondisi file tidak tersedia
		if ( ... ){
			printf("File tidak tersedia, silahkan coba lagi\n");
			continue;
		} 

		//menambah alokasi data dari array data_tentara 
		data_tentara = realloc(data_tentara, (index+1) * sizeof *data_tentara);

		//memanggil fungsi loadFile untuk memasukkan informasi file.csv ke data_tentara[index]
		data_tentara[index] = loadFile(filename);

		//inkrementasi indeks
		index++; 
	}
	
	//loop pemanggilan fungsi untuk tiap index data_tentara
	for (int i = 0; i < index; i++){ 
		calculateDistance(&data_tentara[i]);        //fungsi menghitung total jarak tempuh
		calculateFuelUsed(&data_tentara[i]);        //fungsi menghitung bahan bakar yang digunakan
		processOutput(data_tentara[i]);             //fungsi print output 
	} 
}

//menerima input berupa pointer ke variabel bertipe 'data'
//bertugas untuk menghitung bahan bakar yang digunakan
void calculateFuelUsed (data *person){
	/*
		lengkapi fungsi agar dapat menghitung bahan bakar yang digunakan
		dan memasukkannya ke person.finalFuel
	*/
   return;
}

//menerima input berupa pointer ke variabel bertipe 'data'
//bertugas untuk menghitung jarak total yang ditempuh
void calculateDistance (data *person){    
	/*
		lengkapi fungsi agar dapat menghitung total jarak tempuh
		dan memasukkannya ke person.distance 
	*/
	 
	return;
}

//menerima input berupa variabel bertipe 'data'
//bertugas untuk menampilkan output ke pengguna 
void processOutput (data person){ 
	if (person.finalFuel >= 0){
		printf("Prajurit %s\nBahan bakar awal: %.2f\nKonsumsi bahan bakar: %.2f km/liter\n", person.name, person.fuel, person.kml);
		printf("Jarak tempuh: %.2f km\nSisa bahan bakar: %.2f liter\n\n", person.distance, person.finalFuel);
	}
	else{
		printf("Prajurit %s\nBahan bakar awal: %.2f\nKonsumsi bahan bakar: %.2f km/liter\n",person.name, person.fuel, person.kml);
		printf("Jarak tempuh: %.2f km\nBahan bakar tidak cukup, tambah sebanyak %.2f liter\n\n", person.distance, (-1*person.finalFuel));
	}
}

//menerima input berupa nama file
//bertugas untuk melakukan parsing data
//mereturn hasil parsing data ke suatu variabel bertipe 'data'
data loadFile(char filename[MAX_STRLEN]){
	//inisialisasi variabel
	FILE *fp;
	char buff[BUFF_LEN];  
	data data_orang;
	
	int index = 0;
	int loopKoordinat = 0;
	data_orang.coordinateCount = 0;

	//buka file csv
	fp = fopen(filename, "r");    
	
	//inisialisasi array koordinat
	data_orang.x = (float*)malloc(sizeof(float));
	data_orang.y = (float*)malloc(sizeof(float));
	data_orang.z = (float*)malloc(sizeof(float));

	while (!feof(fp)){
		char* token;
		fgets(buff, BUFF_LEN, (FILE*)fp);  

		//parsing baris pertama - nama prajurit
		if (index == 0){
			data_orang.name = (char*)malloc(strlen(buff)*sizeof(char*)); 
			token = strtok(buff, "\n");
			strcpy(data_orang.name, token); 
		}
		
		//parsing baris kedua - jumlah bahan bakar awal
		else if (index == 1){ 
			data_orang.fuel = atof(buff);
		}

		//parsing baris ketiga - faktor konsumsi bahan bakar
		else if (index == 2){
			data_orang.kml = atof(buff);
		}

		//parsing baris keempat dan seterusnya - pasangan koordinat x, y, dan z
		else{
			//alokasi memori tambahan untuk memasukkan koordinat baru ke array x,y,z didalam variabel data_orang
			data_orang.x = (float*)realloc(data_orang.x, (loopKoordinat+1) *sizeof(data_orang.x));
			data_orang.y = (float*)realloc(data_orang.y, (loopKoordinat+1) *sizeof(data_orang.y));
			data_orang.z = (float*)realloc(data_orang.z, (loopKoordinat+1) *sizeof(data_orang.z));

			token = strtok(buff, ",");                      //parsing x  
			data_orang.x[loopKoordinat] = atof(token);    
			token = strtok(NULL, ",");                      //parsing y
			data_orang.y[loopKoordinat] = atof(token);       
			token = strtok(NULL, ",");                      //parsing z
			data_orang.z[loopKoordinat] = atof(token);    
			
			loopKoordinat++;
		} 
		index++;  
	}
	fclose(fp);  
	//memasukkan jumlah koordinat yang dibaca ke variabel coordinateCount didalam struct data_orang
	data_orang.coordinateCount = loopKoordinat;
	
	return data_orang; 

	return data_orang; 
}

//gunakan fungsi ini untuk melakukan operasi pangkat, dengan ketentuan x^y
//y merupakan  integer lebih besar dari 0
float power(float x, int y){
	float result = 1.0;
	for (int i = 0; i < y; i++){
		result = result * x;
	}
	return result;
}

//gunakan fungsi ini untuk melakukan operasi akar pangkat 2
float squareRoot(float x){ 
	float temp, sqrt; 
	sqrt = x / 2;
	temp = 0; 
	while(sqrt != temp){ 
		temp = sqrt; 
		sqrt = ( x/temp + temp) / 2;
	} 
	return sqrt;
}