#include <stdio.h>
#include <string.h>

struct SinhVien{
    char id[20];
    char name[20];
    int age;
    char phoneNumber[10];
};

void hienThiDanhSach(struct SinhVien *sv, int n);
void themSinhVien(struct SinhVien *sv, int *n);
void suaThongTinSinhVien(struct SinhVien *sv, int n);
void xoaSinhVien(struct SinhVien *sv, int *n);
void timKiemSinhVien(struct SinhVien *sv, int n);
void sapXepSinhVienTheoTen(struct SinhVien *sv, int n);

int main(){
    struct SinhVien sv[50]={
        {"QA0001", "Nguyen Quynh Anh", 18, "0918377546"},
        {"QA0002", "Pham Viet An", 18, "0866168006"},
        {"QA0003", "Pham Quynh Anh", 19, "0192857182"},
        {"QA0004", "Nguyen Viet An", 19, "0192848477"},
        {"QA0005", "Pham Quynh An", 20, "0192837472"}
    };
    int currentLength = 5;
    int choice;

    do{
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:
                hienThiDanhSach(sv, currentLength);
                break;
            case 2:
                themSinhVien(sv, &currentLength);
                break;
            case 3:
                suaThongTinSinhVien(sv, currentLength);
                break;
            case 4:
                xoaSinhVien(sv, &currentLength);
                break;
            case 5:
                timKiemSinhVien(sv, currentLength);
                break;
            case 6:
                sapXepSinhVienTheoTen(sv, currentLength);
                printf("Danh sach sinh vien sau khi sap xep:\n");
                hienThiDanhSach(sv, currentLength);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }while(choice != 7);

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

void themSinhVien(struct SinhVien *sv, int *n){
    if(*n >= 50){
        printf("Khong the them sinh vien moi, mang da day.\n");
        return;
    }

    struct SinhVien svMoi;

    printf("Nhap id sinh vien: ");
    fgets(svMoi.id, sizeof(svMoi.id), stdin);
    svMoi.id[strcspn(svMoi.id, "\n")] = '\0';

    printf("Nhap ten sinh vien: ");
    fgets(svMoi.name, sizeof(svMoi.name), stdin);
    svMoi.name[strcspn(svMoi.name, "\n")] = '\0';

    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &svMoi.age);
    getchar();

    printf("Nhap so dien thoai sinh vien: ");
    fgets(svMoi.phoneNumber, 11, stdin);
    svMoi.phoneNumber[strcspn(svMoi.phoneNumber, "\n")] = '\0';

    sv[*n] = svMoi;
    (*n)++;
}

void suaThongTinSinhVien(struct SinhVien *sv, int n){
    char id[20];
    printf("Nhap id sinh vien can sua: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    for(int i = 0; i < n; i++){
        if(strcmp(sv[i].id, id) == 0){
            printf("Nhap ten sinh vien moi: ");
            fgets(sv[i].name, sizeof(sv[i].name), stdin);
            sv[i].name[strcspn(sv[i].name, "\n")] = '\0';

            printf("Nhap tuoi sinh vien moi: ");
            scanf("%d", &sv[i].age);
            getchar();

            printf("Nhap so dien thoai moi: ");
            fgets(sv[i].phoneNumber, 11, stdin);
            sv[i].phoneNumber[strcspn(sv[i].phoneNumber, "\n")] = '\0';

            printf("Thong tin sinh vien da duoc cap nhat.\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien co id: %s\n", id);
}

void xoaSinhVien(struct SinhVien *sv, int *currentLength){
    char id[20];
    printf("Nhap id sinh vien can xoa: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    int index = -1;
    for(int i = 0; i < *currentLength; i++){
        if(strcmp(sv[i].id, id) == 0){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("Khong tim thay sinh vien co id: %s\n", id);
        return;
    }

    for(int i = index; i < *currentLength - 1; i++){
        sv[i] = sv[i + 1];
    }

    (*currentLength)--;
    printf("Da xoa sinh vien co id: %s\n", id);
}

void timKiemSinhVien(struct SinhVien *sv, int n){
    char id[20];
    printf("Nhap id sinh vien can tim: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    for(int i = 0; i < n; i++){
        if(strcmp(sv[i].id, id) == 0){
            printf("Thong tin sinh vien:\n");
            printf("ID: %s\n", sv[i].id);
            printf("Ten: %s\n", sv[i].name);
            printf("Tuoi: %d\n", sv[i].age);
            printf("So dien thoai: %s\n", sv[i].phoneNumber);
            return;
        }
    }
    printf("Khong tim thay sinh vien co id: %s\n", id);
}

void sapXepSinhVienTheoTen(struct SinhVien *sv, int n){
    struct SinhVien temp;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (strcmp(sv[i].name, sv[j].name) > 0){
                temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

