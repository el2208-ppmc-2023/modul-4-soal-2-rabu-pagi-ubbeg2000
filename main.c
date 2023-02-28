/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#define BUFF_LEN 512
#define MAX_STRLEN 30
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char jurusan[2];
	int angkatan;
	int* nim;
	int* gender;
	int jumlah_mahasiswa;
	int semua_kalah;
} data;

//deklarasi fungsi
void processOutput (data pemain);
void processLoses (data *pemain);
data loadFile(char filename[MAX_STRLEN]);

int jumlah_kalah, orang_keberapa;

int main(){
	//inisialisasi variabel dan struct
	int index = 0;
	data* data_mahasiswa = malloc(sizeof *data_mahasiswa);

	//loop untuk membaca file dan memasukkannya ke struct data_mahasiswa
	//bila user memasukkan string "cukup", loop berhenti
	while (1){
        char filename[MAX_STRLEN];
		printf("Masukkan nama file: ");
		scanf("%s",filename);

		if (strcmp(filename, "cukup") == 0){
			printf("\n");
			break;
		}

        FILE *fp = fopen(filename, "r");
        if (!fp) {
            printf("File tidak tersedia, silahkan coba lagi\n");
            continue;
        }
        fclose(fp);

		//menambah alokasi data dari array data_mahasiswa
		data_mahasiswa = realloc(data_mahasiswa, (index+1) * sizeof *data_mahasiswa);

		//memanggil fungsi loadFile untuk memasukkan informasi file.csv ke data_mahasiswa[index]
		data_mahasiswa[index] = loadFile(filename);

		//inkrementasi indeks
		index++;
	}

	//menerima input user
	printf("Jumlah orang yang akan kalah: ");
	scanf("%d", &jumlah_kalah);
	printf("Tiap orang ke berapa yang akan kalah: ");
	scanf("%d", &orang_keberapa);

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
    if (jumlah_kalah >= pemain->jumlah_mahasiswa){
        pemain->semua_kalah = 1;
    }
    else{
        int sudah_kalah = 0;
        int i = 0;
        int count_temp = 0;
        while(sudah_kalah != jumlah_kalah){
            if (i == pemain->jumlah_mahasiswa){
                i = 0;
            }
            while (pemain->nim[i] == 0){
                i++;
                if (i == pemain->jumlah_mahasiswa){
                    i = 0;
                }
            }
            count_temp++;
            if (count_temp == orang_keberapa){
                pemain->nim[i] = 0;
                count_temp = 0;
                sudah_kalah++;
            }
            i++;
        }
    }
	return;
}

//menerima input berupa variabel bertipe 'data'
//bertugas untuk menampilkan output ke pengguna
void processOutput (data pemain){
    printf("\n%s %d\n", pemain.jurusan, pemain.angkatan);
    if (pemain.semua_kalah == 1){
        printf("Seluruh mahasiswa telah kalah\n");
    }
    else {
        printf("Jumlah orang yang belum kalah: %d\n", pemain.jumlah_mahasiswa-jumlah_kalah);
        int cowo=0, cewe=0;
        for (int i=0; i<pemain.jumlah_mahasiswa; i++){
            if (pemain.nim[i] != 0){
                if (pemain.gender[i] == 1){
                    cowo++;
                }
                else{
                    cewe++;
                }
            }
        }
        printf("%d orang laki-laki dan %d orang perempuan\n", cowo, cewe);
        printf("NIM mahasiswa yang belum kalah:\n");
        for (int i=0; i<pemain.jumlah_mahasiswa; i++){
            if (pemain.nim[i] != 0){
                printf("%d\n",pemain.nim[i]);
            }
        }
    }
}

//menerima input berupa nama file
//bertugas untuk melakukan parsing data
//mereturn hasil parsing data ke suatu variabel bertipe 'data'
data loadFile(char filename[MAX_STRLEN]){
	//inisialisasi variabel
	FILE *fp;
	char buff[BUFF_LEN];
	data data_siswa;
	int count = 0;
	int index = 0;

	//buka file csv
	fp = fopen(filename, "r");

    //inisialisasi array koordinat
    data_siswa.nim = (int*) malloc(sizeof(int));
    data_siswa.gender = (int*) malloc(sizeof(int));

    while (!feof(fp)){
        char* token;
        fgets(buff, BUFF_LEN, (FILE*)fp);

        //parsing baris pertama - jurusan
        if (index == 0){
            token = strtok(buff, "\n");
            strcpy(data_siswa.jurusan, token);
        }

        //parsing baris kedua - jumlah bahan bakar awal
        else if (index == 1){
            data_siswa.angkatan = atoi(buff);
        }

        //parsing baris ketiga dan seterusnya - pasangan nama, NIM, jenis kelamin
        else{
            //alokasi memori tambahan untuk memasukkan koordinat baru ke array x,y,z didalam variabel data_orang
            data_siswa.nim = (int*) realloc(data_siswa.nim, (count+1)*sizeof(int));
            data_siswa.gender = (int*) realloc(data_siswa.gender, (count+1)*sizeof(int));

            token = strtok(buff, ",");                       //parsing nim
            data_siswa.nim[count] = atoi(token);
            token = strtok(NULL, "\n");                      //parsing jenis kelamin
            data_siswa.gender[count] = atoi(token);

            count++;
        }
        index++;
    }
    data_siswa.jumlah_mahasiswa = count;
    data_siswa.semua_kalah = 0;
    fclose(fp);

	return data_siswa;
}
