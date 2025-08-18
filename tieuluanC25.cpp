#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Sach {
   int MaSach;
   char TenSach[100];
   char TacGia[50];
   int NamXuatBan;

} Sach;
void Themsach(Sach ds[], int n) {
    for (int i = 0; i < n; i++) {
        // Nhap thong tin sach
        printf("Nhap Ma SSach: ");
        scanf("%d", &ds[i].MaSach);
        getchar(); // xoa bo dem '\n' sau khi nhap Ma Sach
    printf("Nhap ten sach: ");
    fgets(ds[i].TenSach, sizeof(ds[i].TenSach), stdin);
    ds[i].TenSach[strcspn(ds[i].TenSach, "\n")] = '\0'; // tim vi tri '\n' va thay the bang '\0'
    printf("Nhap Tac Gia: ");
    fgets(ds[i].TacGia, sizeof(ds[i].TacGia), stdin);
    ds[i].TacGia[strcspn(ds[i].TacGia, "\n")] = '\0'; // tim vi tri '\n' va thay the bang '\0'
    printf("Nhap nam xuat ban: ");
    scanf("%d", &ds[i].NamXuatBan);
    }
}
void thongtinSach(Sach ds[], int n) {
    printf("Thong tin sach:\n");
    for (int i = 0; i < n; i++) {
        // In thong tin sach
        printf("Ma Sach: %d\n", ds[i].MaSach);
        printf("Ten Sach: %s\n", ds[i].TenSach);
        printf("Tac Gia: %s\n", ds[i].TacGia);
        printf("Nam Xuat Ban: %d\n", ds[i].NamXuatBan);
        printf("-------------------------\n");
    }
}

void timkiemsach(Sach ds[], int n, int maSachCanTim, char tenSachCanTim[], char tacGiaCanTim[], int namXuatBanCanTim) {
    int found = 0; // bien kiem tra co tim thay sach khong
    for (int i = 0; i < n; i++) {
        // Kiem tra Ma Sach, ten sach, tac gia, nam xuat ban
        if (ds[i].MaSach == maSachCanTim || strcmp(ds[i].TenSach, tenSachCanTim) == 0 || strcmp(ds[i].TacGia, tacGiaCanTim) == 0 || ds[i].NamXuatBan == namXuatBanCanTim) {
            //in ra thong tin sach tim thay
            printf("Sach tim thay:\n");
            printf("Ma Sach: %d\n", ds[i].MaSach);
            printf("Ten Sach: %s\n", ds[i].TenSach);
            printf("Tac Gia: %s\n", ds[i].TacGia);
            printf("Nam Xuat Ban: %d\n", ds[i].NamXuatBan);
            printf("-------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sach phu hop voi thong tin tim kiem!\n");
    }
}
int XoaSachbangma(Sach ds[],int n, int maSachCanXoa) {
    int found = 0; // bien kiem tra co tim thay sach khong
    for (int i = 0; i < n; i++) {
        if (ds[i].MaSach == maSachCanXoa) {
            found = 1;
            for (int j = i; j < n - 1; j++) {
                ds[j] = ds[j + 1]; // dich chuyen cac phan tu ve ben trai
            }
            n--; // giam so luong sach
            break;
        }
    }
    return n; // tra ve so luong sach con lai
}

int main() {
    Sach ds[100]; // mang luu tru sach
        int n;
    printf("Nhap so luong sach can them: ");
        scanf("%d", &n);//nhap so luong sach can them
    Themsach(ds, n);
    thongtinSach(ds, n);
    char tenSachCanTim[100];
    int MaSachCanTim;
    char tacGiaCanTim[50];
    int namXuatBanCanTim;
    // nhap thong tin de tim sach
        printf("Nhap ten sach can tim: ");
        getchar(); // xoa bo dem '\n'
            fgets(tenSachCanTim, sizeof(tenSachCanTim), stdin);
            tenSachCanTim[strcspn(tenSachCanTim, "\n")] = '\0'; // tim vi tri '\n' va thay the bang '\0'
        printf("Nhap Ma Sach can tim: ");
            scanf("%d", &MaSachCanTim);

        printf("Nhap tac gia sach can tim: ");
            getchar(); // xoa bo dem '\n' sau khi nhap Ma Sach
            fgets(tacGiaCanTim, sizeof(tacGiaCanTim), stdin);
            tacGiaCanTim[strcspn(tacGiaCanTim, "\n")] = '\0'; // tim vi tri '\n' va thay the bang '\0'
        printf("Nhap nam xuat ban sach can tim: ");
            scanf("%d", &namXuatBanCanTim);
   timkiemsach(ds, n, MaSachCanTim, tenSachCanTim, tacGiaCanTim, namXuatBanCanTim); // tim kiem sach theo Ma Sach, ten, tac gia, nam xuat ban
    return 0;
}