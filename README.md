# C-practice

# Virtual Box

- 윈도우에서 가상환경위에 우분투 설치 : https://mainia.tistory.com/2379
- 우분투에서 가상환경위에 윈도우 설치 : https://hiseon.me/linux/ubuntu/ubuntu-virtualbox-install/

### [에러]

1. **VT-x is disabled in the BIOS for all CPU modes**

bios창에서 데스크탑이 가상환경을 사용할 수 있도록 설정해줘야 한다.

**참고** : https://memory-note.tistory.com/16

2. **fatal no bootable medium found**

**참고** : 

https://extrememanual.net/11157

https://blog.naver.com/PostView.naver?blogId=chjinho2030&logNo=222408477361&categoryNo=61&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=search

# 네트워크 통신(ping)

- apt-get으로 설치가능한 패키지와 버전을 최신으로 업데이트 ->

sudo apt-get update

- ping 유틸 설치 ->

sudo apt-get install iputils-ping

- ifconfig 유틸 설치 ->

sudo apt install net-tools

## wire shark, tcp dump

1. [wire shark]
- wireshark 설치 참고 : https://websetnet.net/ko/install-and-use-wireshark-on-ubuntu-linux/
- wireshark로 터미널에서 실행했을때 wireshark 오류나면 -> sudo wireshark로 실행
<br>

![wireshark1](https://user-images.githubusercontent.com/60745844/182393598-e2512d33-fc70-447f-bdb2-318578ad8d0f.png)

<br>
1. [tcpdump]
- 참고 : https://jinane.tistory.com/6
- 자주 사용되는 단축 명령어 :https://m.blog.naver.com/sung_mk1919/221214060931
- reply,request 조건 참고 : https://www.howtouselinux.com/post/tcpdump-filter-icmpv6-packets
- tcpdump 특정 ip 핑 캡처

sudo tcpdump -i any -nn host 192.168.0.171