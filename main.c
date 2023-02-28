/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 30

typedef struct { //silahkan menyesuaikan isi dari struct ini
	char jurusan[2];
	int angkatan;
	int* nim;
	int* gender;
	int jumlah_mahasiswa;
} data;

//deklarasi fungsi
//fungsi-fungsi ini tidak wajib dipakai, silahkan manfaatkan atau tambahkan fungsi lain
//jangan mengubah format output pada fungsi processOutput
void processOutput (data pemain);
void processLoses (data *pemain);
data loadFile(char filename[MAX_STRLEN]);

int main(){
	//inisialisasi variabel dan struct
	int index = 0;
	data* data_mahasiswa = malloc(sizeof *data_mahasiswa);

	//loop untuk membaca file dan memasukkannya ke struct data_mahasiswa
	//bila user memasukkan string exit, loop berhenti
	while (1){
        char filename[MAX_STRLEN];
		printf("Masukkan nama file: ");
		scanf("%s",filename);

		if (strcmp(filename, "cukup") == 0){
			printf("\n");
			break;
		}

        //lengkapi ... untuk kondisi file tidak tersedia
        if (...) {
            printf("File tidak tersedia, silahkan coba lagi\n");
            continue;
        }
        fclose(...);

		//menambah alokasi data dari array data_mahasiswa
		data_mahasiswa = realloc(data_mahasiswa, (index+1) * sizeof *data_mahasiswa);

		//memanggil fungsi loadFile untuk memasukkan informasi file.csv ke data_mahasiswa[index]
		data_mahasiswa[index] = loadFile(filename);

		//inkrementasi indeks
		index++;
	}

	//menerima input user
	// silahkan lengkapi sendiri
	printf("Jumlah orang yang akan kalah: ");
	scanf(...);
	printf("Tiap orang ke berapa yang akan kalah: ");
	scanf(...);

    //loop pemanggilan fungsi untuk tiap index data_mahasiswa
    for (int i = 0; i < index; i++){
		processLoses(&data_mahasiswa[i]);           //fungsi mencari mahasiswa yang akan kalah
		processOutput(data_mahasiswa[i]);             //fungsi print output
	}
	return(0);
}

//menerima input berupa pointer ke variabel bertipe 'data'
//bertugas untuk mencari mahasiswa yang akan kalah
void processLoses (data *pemain){
    //fungsi ini tidak wajib dipakai, silahkan lengkapi sendiri
	return;
}

//menerima input berupa variabel bertipe 'data'
//bertugas untuk menampilkan output ke pengguna
//silahkan lengkapi fungsi berikut
void processOutput (data pemain){
    printf("\n%s %d\n", pemain.jurusan, pemain.angkatan);
    if (...){
        printf("Seluruh mahasiswa telah kalah\n");
    }
    else {
        printf("Jumlah orang yang belum kalah: %d\n", ...);

        printf("%d orang laki-laki dan %d orang perempuan\n", ..., ...);
        printf("NIM mahasiswa yang belum kalah:\n");
        for (int i=0; i<pemain.jumlah_mahasiswa; i++){
            if (...){
                printf("%d\n",pemain.nim[i]);
            }
        }
    }
}

//menerima input berupa nama file
//bertugas untuk melakukan parsing data
//mereturn hasil parsing data ke suatu variabel bertipe 'data'
data loadFile(char filename[MAX_STRLEN]){
    //inisialisasi struct
	data data_siswa;

	/*
        lengkapi fungsi agar dapat mengimport file txt
        dan memasukkan informasi yang terdapat di file tersbut ke variabel data_siswa
    */

	return data_siswa;
}
