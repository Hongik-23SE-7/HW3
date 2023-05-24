// ��� ����
#include <iostream>
#include <fstream>
#include "RecruitmentSystem.h"

// ��� ����
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

// �Լ� ����
void doTask();
void program_exit();

static ifstream input;
static ofstream output;

int main() {
    // ���� ������� ���� �ʱ�ȭ
    input.open(INPUT_FILE_NAME);
    output.open(OUTPUT_FILE_NAME);

    doTask();

    input.close();
    output.close();

    return 0;
}

void doTask() {
    // �޴� �Ľ��� ���� level ������ ���� ����
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    GeneralMemberRepository* generalMemberRepository = GeneralMemberRepository::getGeneralMemberRepository();
    RecruitmentRepository* recruitmentRepository = RecruitmentRepository::getRecruitmentRepository();
    string memberId = "hello";

    while (!is_program_exit) { // �Է����Ͽ��� �޴� ���� 2���� �б�
        input >> menu_level_1 >> menu_level_2;

        // �޴� ���� �� �ش� ���� ����
        switch (menu_level_1) {
        case 1: {
            switch (menu_level_2) {
            case 1: {
                generalMemberRepository->join(memberId);
                output << "1.1. ȸ������\n> ȸ������ �Ϸ�\n";
                break;
            }
            }
            break;
        }
        case 3: {
            switch (menu_level_2) {
            case 1: {
                recruitmentRepository->addRecruitment("hankook", "3456", "accounting", "2", "2023/05/26");
                output << "3.1. ä�� ���� ���\n > ä�� ���� ��� �Ϸ�\n";
                break;
            }
            }
            break;
        }
        case 4: {
            switch (menu_level_2) {
            case 1: {
                SearchRecruitmentUI* boundary = new SearchRecruitmentUI();
                boundary->searchRecruitment(input, output);
                break;
            }
            case 2: {
                ApplyRecruitmentUI* boundary = new ApplyRecruitmentUI();
                boundary->applyRecruitment(input, output, memberId);
                break;
            }
            case 3: {
                ApplicationInfoUI* boundary = new ApplicationInfoUI();
                boundary->showApplicationInfo(input, output, memberId);
                break;
            }
            }
            break;
        }
        case 6: {
            switch (menu_level_2) {
            case 1: {
                program_exit();
                is_program_exit = 1;
                break;
            }
            }
            break;
        }
        }
    }
}

void program_exit() {
    output << "6.1. ����";
}
