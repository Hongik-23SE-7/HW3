g++ -std=c++11 main.cpp boundary/SignUpUI.cpp boundary/LoginUI.cpp boundary/LogOutUI.cpp boundary/WithdrawUI.cpp control/SignUp.cpp control/Login.cpp control/LogOut.cpp control/Withdraw.cpp entity/Member.cpp entity/MemberRepository.cpp entity/Authenticator.cpp -o test
./test
rm test