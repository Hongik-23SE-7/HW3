g++ -std=c++11 main.cpp boundary/SignUpUI.cpp boundary/LoginUI.cpp control/SignUp.cpp control/Login.cpp entity/Member.cpp entity/MemberRepository.cpp entity/Authenticator.cpp entity/Session.cpp -o test
./test
rm test