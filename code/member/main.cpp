// 헤더 선언
#include <iostream>
#include <fstream>
#include "boundary/SignUpUI.hpp"
#include "boundary/LoginUI.hpp"
#include "boundary/LogOutUI.hpp"
#include "boundary/WithdrawUI.hpp"

// 상수 선언
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

// 함수 선언
void doTask();
void program_exit();

static ifstream input;
static ofstream output;

int main() {
  // 파일 입출력을 위한 초기화
    input.open("input.txt");
    output.open("output.txt");

    doTask();
    
    input.close();
    output.close();

    return 0;
}

void doTask() {
  // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0, menu_level_3 = 0;
    int is_program_exit = 0;

    string memberId = "hello";
    
    while(!is_program_exit) { // 입력파일에서 메뉴 숫자 2개를 읽기
        input >> menu_level_1 >> menu_level_2;


        // 메뉴 구분 및 해당 연산 수행
        switch(menu_level_1) {
            case 1: {
                switch (menu_level_2) {
                    case 1: {
                        input >> menu_level_3;
                        SignUpUI *boundary = new SignUpUI();
                        switch (menu_level_3) {
                            case 1: {
                                boundary->companyMemberSignUp(input, output);
                                break;
                            }
                            case 2: {
                                boundary->generalMemberSignUp(input, output);
                                break;
                            }
                        }
                        break;
                    }
                    case 2: {
                        WithdrawUI *withdrawUI = new WithdrawUI();
                        withdrawUI->withdraw(output);
                        break;
                    }
                }
                break;
            }
            case 2: {
                switch (menu_level_2) {
                    case 1: {
                        LoginUI *boundary = new LoginUI();
                        boundary->login(input, output);
                        break;
                    }
                    case 2: {
                        LogOutUI *boundary = new LogOutUI();
                        boundary->logOut(output);
                        break;
                    }
                }
                break;
            }
            case 6: {
                switch(menu_level_2) {
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
    output << "6.1. 종료";
}
