#include <stdio.h>
#include <string.h>

struct SinhVien {
    char id[20];
    char name[20];
    int age;
    char phoneNumber[10];
};

void hienThiDanhSach(struct SinhVien *sv, int n);
void sapXepSinhVienTheoTen(struct SinhVien *sv, int n);

int main(){
    struct SinhVien sv[5]={
        {"QA0001", "Nguyen Quynh Anh", 18, "0918377546"},
        {"QA0002", "Pham Viet An", 18, "0866168006"},
        {"QA0003", "Pham Quynh Anh", 19, "0192857182"},
        {"QA0004", "Nguyen Viet An", 19, "0192848477"},
        {"QA0005", "Pham Quynh An", 20, "0192837472"}
    };
    int n = 5;

    printf("Danh sach sinh vien ban dau:\n");
    hienThiDanhSach(sv, n);

    sapXepSinhVienTheoTen(sv, n);
    
    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    hienThiDanhSach(sv, n);

    return 0;
}

void hienThiDanhSach(struct SinhVien *sv, int n){
    for(int i = 0; i < n; i++){
        printf("ID: %s\n", sv[i].id);
        printf("Ten: %s\n", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
        printf("So dien thoai: %s\n", sv[i].phoneNumber);
        printf("------------------------------\n");
    }
}

void sapXepSinhVienTheoTen(struct SinhVien *sv, int n){
    struct SinhVien temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++) {
            if(strcmp(sv[i].name, sv[j].name) > 0){
                temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

