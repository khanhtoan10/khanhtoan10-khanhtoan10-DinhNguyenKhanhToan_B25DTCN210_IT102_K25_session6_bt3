#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char maPhieu[MAX][20];
    char maSach[MAX][20];
    int soNgayMuon[MAX];
    int soLuong = 0;

    int luaChon;

    do {
        printf("\n================ HE THONG QUAN LY MUON TRA SACH ================\n");
        printf("1. Them moi phieu muon sach\n");
        printf("2. Hien thi danh sach phieu muon & Tien phat qua han\n");
        printf("3. Cap nhat so ngay muon sach\n");
        printf("4. Xac nhan tra sach / Xoa phieu muon\n");
        printf("5. Thoat chuong trinh\n");
        printf("==============================================================================\n");
        printf("Lua chon cua ban (1-5): ");
        scanf("%d", &luaChon);

        while (getchar() != '\n');

        switch (luaChon) {
            case 1: {
                printf("\n--- THEM MOI PHIEU MUON ---\n");
                if (soLuong >= MAX) {
                    printf("Bo nho danh sach da day, khong the them moi!\n");
                } else {
                    char maNhap[20];
                    int trungMa = 0;

                    printf("Nhap ma phieu: ");
                    scanf("%s", maNhap);
                    while (getchar() != '\n');

                    for (int i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[i], maNhap) == 0) {
                            trungMa = 1;
                            break;
                        }
                    }

                    if (trungMa == 1) {
                        printf("Ma phieu da ton tai trong he thong!\n");
                    } else {
                        strcpy(maPhieu[soLuong], maNhap);

                        printf("Nhap ma sach: ");
                        scanf("%s", maSach[soLuong]);
                        while (getchar() != '\n');

                        int ngayInput;
                        do {
                            printf("Nhap so ngay muon: ");
                            scanf("%d", &ngayInput);
                            while (getchar() != '\n');
                            if (ngayInput <= 0) {
                                printf("So ngay muon phai lon hon 0. Vui long nhap lai!\n");
                            }
                        } while (ngayInput <= 0);

                        soNgayMuon[soLuong] = ngayInput;
                        soLuong++;

                        printf("Them moi phieu muon thanh cong!\n");
                    }
                }
                break;
            }

            case 2: {
                if (soLuong == 0) {
                    printf("\nDanh sach phieu muon hien dang rong!\n");
                } else {
                    printf("\n========================= DANH SACH PHIEU MUON =========================\n");
                    printf("%-3s %-10s %-12s %-15s %-18s %-15s\n", 
                           "STT", "MA PHIEU", "MA SACH", "SO NGAY", "TRANG THAI", "TIEN PHAT (VND)");

                    for (int i = 0; i < soLuong; i++) {
                        int tienPhat = 0;
                        char trangThai[15];

                        if (soNgayMuon[i] > 14) {
                            int ngayQuaHan = soNgayMuon[i] - 14;
                            tienPhat = ngayQuaHan * 5000;
                            strcpy(trangThai, "QUA HAN");
                        } else {
                            tienPhat = 0;
                            strcpy(trangThai, "DUNG HAN");
                        }

                        printf("%-3d %-10s %-12s %-15d %-18s %-15d\n", 
                               i + 1, maPhieu[i], maSach[i], soNgayMuon[i], trangThai, tienPhat);
                    }
                    printf("========================================================================\n");
                }
                break;
            }

            case 3: {
                printf("\n--- CAP NHAT SO NGAY MUON ---\n");
                if (soLuong == 0) {
                    printf("Danh sach phieu muon hien dang rong!\n");
                } else {
                    char maNhap[20];
                    printf("Nhap ma phieu can cap nhat: ");
                    scanf("%s", maNhap);
                    while (getchar() != '\n');

                    int pos = -1;
                    for (int i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[i], maNhap) == 0) {
                            pos = i;
                            break;
                        }
                    }

                    if (pos == -1) {
                        printf("Khong tim thay ma phieu trong he thong!\n");
                    } else {
                        printf("So ngay muon hien tai cua phieu %s la: %d\n", maPhieu[pos], soNgayMuon[pos]);
                        
                        int ngayMoi;
                        do {
                            printf("Nhap so ngay muon moi: ");
                            scanf("%d", &ngayMoi);
                            while (getchar() != '\n');
                            if (ngayMoi <= 0) {
                                printf("So ngay muon phai lon hon 0. Vui long nhap lai!\n");
                            }
                        } while (ngayMoi <= 0);

                        soNgayMuon[pos] = ngayMoi;
                        printf("Cap nhat so ngay muon thanh cong!\n");
                    }
                }
                break;
            }

            case 4: {
                printf("\n--- XAC NHAN TRA SACH / XOA PHIEU MUON ---\n");
                if (soLuong == 0) {
                    printf("Danh sach phieu muon hien dang rong!\n");
                } else {
                    char maNhap[20];
                    printf("Nhap ma phieu xac nhan tra/xoa: ");
                    scanf("%s", maNhap);
                    while (getchar() != '\n');

                    int pos = -1;
                    for (int i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[i], maNhap) == 0) {
                            pos = i;
                            break;
                        }
                    }

                    if (pos == -1) {
                        printf("Khong tim thay ma phieu can xoa!\n");
                    } else {
                        for (int i = pos; i < soLuong - 1; i++) {
                            strcpy(maPhieu[i], maPhieu[i + 1]);
                            strcpy(maSach[i], maSach[i + 1]);
                            soNgayMuon[i] = soNgayMuon[i + 1];
                        }
                        soLuong--;
                        printf("Xac nhan tra sach va xoa phieu muon thanh cong!\n");
                    }
                }
                break;
            }

            case 5: {
                printf("\nCam on ban da su dung phan mem. Tam biet!\n");
                break;
            }

            default:
                printf("\nLua chon khong hop le, vui long chon lai!\n");
                break;
        }

    } while (luaChon != 5);

    return 0;
}
