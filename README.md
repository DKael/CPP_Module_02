# CPP Module 02

## 1️⃣ 프로젝트 소개

정수형 내부 표현을 사용하는 Fixed-point(고정소수점) 클래스를 설계·구현하고, 여기에 정통 캐노니컬 폼(Orthodox Canonical Form) 과 연산자 오버로딩을 단계적으로 적용합니다. 마지막에는 이 클래스를 활용해 점-삼각형 내부 판별(bsp) 을 구현하며 수치 표현 → 연산 오버로딩 → 기하 알고리즘까지 자연스럽게 확장합니다.

---

## 2️⃣ 과제 목표
	•	클래스의 수명/복사 규약(Rule of Three)을 준수한 안전한 설계
	•	고정소수점 산술의 정확도/성능 트레이드오프 이해
	•	비교/산술/증감/스트림/유틸리티 연산자 오버로딩 숙달
	•	const-correctness, 참조 반환, 오버로드 해상도 등 C++ 언어 규칙 체득
	•	수치 클래스를 이용한 실전 알고리즘(bsp) 적용

---

## 3️⃣ Exercise별 구현 사항

### ex00 — My First Class in Orthodox Canonical Form
* 클래스: Fixed
  - 내부 표현: int _rawBits;
  - 고정 소수 비트수: static const int _fractionalBits = 8; (Q8 고정소수)
* 정통 캐노니컬 폼(= Rule of Three)
  - 기본 생성자 / 복사 생성자 / 소멸자 / 대입 연산자
* 접근자
  - int  getRawBits() const;
  - void setRawBits(int const raw);
* 디버깅용 메시지(과제 main에 맞춰 생성/소멸/복사 시 로그 출력)

### ex01 — ToInt/ToFloat & Stream Insertion
* 추가 생성자
  - Fixed(int);  → raw = i << _fractionalBits;
  - Fixed(float); → raw = roundf(f * (1 << _fractionalBits));
* 변환 함수
  - float toFloat() const; → raw / 256.0f
  - int   toInt()   const; → raw >> _fractionalBits
* 출력 연산자
  - std::ostream& operator<<(std::ostream&, Fixed const&); (요구사항: 부동소수 형태로 출력)

### ex02 — Operators & min/max
* 비교: <, >, <=, >=, ==, !=  (대개 raw 비교로 충분)
* 산술: +, -, *, /
  - 구현 선택지
  - 간단: toFloat()로 변환해 부동소수 연산 후 다시 Fixed로
  - 정밀: 64비트 중간값 사용해 정수 산술(오버플로 관리)
* 증감:
  - 전위/후위 ++x, x++, --x, x-- (반환 타입 주의)
* 정적/오버로드 min/max
  - static Fixed&       min(Fixed&, Fixed&);
  - static Fixed const& min(Fixed const&, Fixed const&); (const 오버로드)
  - max도 동일 패턴

### ex03 — bsp(Point in Triangle)
* 자료형: Point(불변 좌표, 내부적으로 Fixed)
* 함수: bool bsp(Point const a, Point const b, Point const c, Point const p);
* 방법: 방향성/면적(바리센트릭) 기반 내부 판별
  - 세 변에 대한 same side 판정 또는
  - 삼각형 면적 = 부분 삼각형 면적 합(동등성, collinear 배제)

---

## 4️⃣ 배운 점

### 4.1 정통 캐노니컬 폼 & Rule of Three
* 복사 생성자/대입 연산자/소멸자 일관 구현
* 객체 소유/복사 의미 명확화
* 얕은 복사·이중 해제·자기 대입 검사 사례 체감

### 4.2 고정소수점(Fixed-point) 표현
* Q8(소수부 8비트) 스케일링 기반 정수 연산
* float ↔ Fixed 변환 시 라운딩 정책 통일
* 곱셈/나눗셈 스케일 보정 오류 확인 및 교정
* 64비트 중간 계산 vs 부동소수 경유 정확도/성능 비교

### 4.3 연산자 오버로딩 규약
* 내부 정수(raw) 직접 비교로 정확·고성능 달성
* 산술 연산: 간결성(부동소수 변환) vs 정밀성(정수 산술) 선택 필요
* 전위/후위 증감 반환 타입 차이 및 const-correctness 체득
* min/max const 오버로드·참조 반환 설계

### 4.4 스트림 삽입과 표현 일관성
* operator<< 를 toFloat() 출력으로 고정
* 디버깅/로깅 시 일관된 뷰 제공
* 출력 형식 통일로 테스트 신뢰성·외부 계약(Contract) 유지

### 4.5 기하 알고리즘(bsp) 안정성
* 방향성(orientation) 기반 내부/외부 판별
* 경계 조건(공선/정점 위) 정의의 중요성 인식
* Fixed 활용으로 부동소수 오차 감소 및 결정성 확보

### 4.6 인터페이스 설계 & 캡슐화
* _rawBits 은닉, toInt()/toFloat() 통한 외부 노출
* 멤버/비멤버 연산자 배치로 사용성(Usability) 향상


---

## 5️⃣ Exercise별 실행 방법

### 공통

bash
```
make            # 전체 빌드
make clean / fclean / re
```

### ex00

bash
```
./ex00
# 생성/복사/대입/소멸 순서와 getRawBits/setRawBits 동작 로그 확인
```

### ex01

bash
```
./ex01
# 정수/실수 생성자, toInt/toFloat, << 연산자 출력 확인
```

### ex02

bash
```
./ex02
# 비교/산술/증감, min/max 테스트
# 예) Fixed a(2.5f), b(1.25f); std::cout << (a+b) << ", " << Fixed::max(a,b) << "\n";
```

### ex03

bash
```
./ex03
# 삼각형 정점(a,b,c)과 점(p)을 주고 bsp(a,b,c,p) 결과 출력
# 내부(true)/외부(false)/경계 처리 정책 확인
```

---

## 6️⃣ 기술 스택
	•	언어: C++98
	•	운영체제/환경: Unix/Linux
	•	빌드 도구: GNU Make
	•	디버그 도구: VSCode, valgrind
	•	구성 요소
	  •	수치 클래스: Fixed(Q8 고정소수, OCF)
	  •	기하 유틸: Point(불변 좌표, Fixed 기반), bsp()
