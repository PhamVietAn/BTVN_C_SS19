#include <stdio.h>
#include <string.h>

struct SinhVien{
    char id[20];
    char name[20];
    int age;
    char phoneNumber[10];
};

void hienThiDanhSach(struct SinhVien *sv, int n);
void xoaSinhVien(struct SinhVien *sv, int *currentLength, char id[]);

int main(){
    struct SinhVien sv[50]={
        {"QA0001", "Nguyen Quynh Anh", 18, "0918377546"},
        {"QA0002", "Pham Viet An", 18, "0866168006"},
        {"QA0003", "Pham Quynh Anh", 19, "0192857182"},
        {"QA0004", "Nguyen Viet An", 19, "0192848477"},
        {"QA0005", "Pham Quynh An", 20, "0192837472"};
    int currentLength = 5;
    char idToDelete[20];

    printf("Danh sach sinh vien ban dau:\n");
    hienThiDanhSach(sv, currentLength);

    printf("\nNhap id sinh vien can xoa: ");
    fgets(idToDelete, sizeof(idToDelete), stdin);
    idToDelete[strcspn(idToDelete, "\n")] = '\0';
    
    xoaSinhVien(sv, &currentLength, idToDelete);
    
    printf("\nDanh sach sinh vien sau khi xoa:\n");
    hienThiDanhSach(sv, currentLength);

    return 0;
}

void hienThiDanhSach(struct SinhVien *sv, int n){
    for(int i = 0; i < n; i++) {
        printf("ID: %s\n", sv[i].id);
        printf("Ten: %s\n", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
        printf("So dien thoai: %s\n", sv[i].phoneNumber);
        printf("------------------------------\n");
    }
}

void xoaSinhVien(struct SinhVien *sv, int *currentLength, char id[]){
    int index = -1;
    for(int i = 0; i < *currentLength; i++){
        if(strcmp(sv[i].id, id) == 0){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("Sinh vien khong ton tai.\n");
        return;
    }

    for(int i = index; i < *currentLength - 1; i++){
        sv[i] = sv[i + 1];
    }

    (*currentLength)--;
    printf("Da xoa sinh vien co id: %s\n", id);
}

