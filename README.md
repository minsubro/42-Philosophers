# Philosophers
## 1. 프로젝트 소개
Philosophers는 운영체제의 교착상태를 설명하기 위한 대표적인 문제인 식사하는 철학자 문제를 시뮬레이션화한 프로그램이다. \
포크를 한번에 한 프로세스만 사용할수 있게 처리하기 위해 뮤텍스를 이용하여 포크를 구했기 때문에 교착상태가 발생할 수 있는 상태가 되었다. \
교착상태 발생 조건이 모두 충족된 상태에서 교착상태가 발생하지 않게 프로그램을 실행시키는 것이 핵심인 프로젝트이다.
## 2. 개발환경
- C
## 3. 서브젝트 이해
각각의 철학자들은 특정한 행동패턴을 반복한다.
1. 포크를 집는다.
2. 먹는다.
3. 잔다.
4. 생각한다. 

철학자의 수, 식사를 하지 않으면 죽는 시간, 식사를 하는 시간, 잠을 자는 시간은 매개변수를 통해 주어진다.
```
./philo 4 410 200 200
```
포크는 철학자 만큼만 존재하고 철학자는 식사를 하기위해 자신의 왼쪽과 오른쪽 포크를 사용할 수 있다. \
왼쪽과 오른쪽 포크를 모두 집어야만 식사를 시작할 수 있다. \
각 철학자는 스레드로 구현이 되며, 포크는 공유자원으로 관리된다. 데이터 레이스를 방지하기 위해 포크는 mutex로 관리한다. \
매개변수로 주어진 시간동안 식사를 하지 못하면 철학자는 죽고 프로그램이 종료된다.
## 4. 교착상태 발생 조건 확인
1. 상호 배제 \
철학자 양옆의 포크는 뮤텍스로 관리되고 있어 한번에 한명의 철학자만 사용할 수 있다.
2. 점유 대기 \
왼쪽 포크를 들고 있더라도 오른쪽 포크를 내 옆 철학자가 사용중이라면 식사를 마치고 내려놓을 때까지 기다려야 한다.
3. 비선점 \
옆 철학자가 포크를 들고 식사중이라면 끝날때까지 포크를 빼앗을 수 없다.
4. 순환 대기 \
포크와 철학자의 자원 할당 그래프를 확인하면 아래와 같이 원형의 형태를 띄고있다.
<img width="665" alt="스크린샷 2024-01-29 오후 12 52 31" src="https://github.com/minsubro/42-Philosophers/assets/96279704/7c2e5ee3-7df7-4c34-97ba-e6515f374552">

## 5. 교착 상태 예방 방법
이 프로젝트에서는 교착상태를 해결하기위해 모든 철학자는 포크를 왼쪽부터 들며 철학자를 짝수 번호와, 홀수 번호로 나눠 시뮬레이션이 시작하면 짝수 스레드는 잠시 대기상태에 있다가 루틴을 시작한다. 이렇게 하면 서로 동시에 포크를 집는 상황이 사라져 철학자들이 서로 번갈아가며 포크를 사용할 수 있다. 하지만 교착상태 발생 조건이 제거되지 않았기 때문에 교착상태가 발생할 가능성은 존재한다.

## 6. 뮤텍스(mutex)
여러 스레드나 픠로세스가 공동으로 이용하는 자원을 공유자원이라고 한다. 이 공유 자원을 두 개 이상의 스레드나 프로세스가 동시에 읽고 쓰는 작업을 하게 될 경우에는 데이터 레이스가 발생한다. 뮤텍스로 데이터를 사용하는 동안 다른 스레드의 접근을 차단하여 데이터 레이스를 방지할 수 있다.
## 참고자료
- https://namu.wiki/w/%EC%8B%9D%EC%82%AC%ED%95%98%EB%8A%94%20%EC%B2%A0%ED%95%99%EC%9E%90%20%EB%AC%B8%EC%A0%9C