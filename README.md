## Text-Based RPG Project: ProgramPatterns_Problem Solving Using C_Term Project

### Project Overview

이 프로젝트는 문제 해결 기법 수업의 팀 프로젝트로, 텍스트 기반의 RPG 게임을 C언어를 이용하여 구현함.
플레이어는 텍스트를 입력하여 게임을 진행하며, 다양한 선택지를 통해 스토리를 이끌어나갈 수 있음.

### File Description

* **color.h:** 게임 내 텍스트 출력 시 다양한 색상을 사용하기 위한 헤더 파일. 'cmd' 환경에서 글자색을 지정하는 기능을 포함하고 있음.
* **english.c:** 영어 언어 지원을 위한 파일. 게임 내에 등장하는 텍스트를 영어로 출력하기 위해 영어로 구성된 다양한 함수를 추가함.
* **index.c:** 메인 함수가 포함된 메인 파일. 게임의 전체적인 흐름을 제어하며, 다른 파일들을 호출하여 게임을 실행함.
* **korean.c:** 한국어 언어 지원을 위한 파일. 게임 내에 등장하는 텍스트를 한국어로 출력하기 위해 한국어로 구성된 다양한 함수를 추가함.
* **stringFunc.h:** 다양한 문자열 처리를 담당하는 함수들을 모아놓은 파일.
* **rpg_struct.h:** RPG 게임에 필요한 다양한 데이터 구조체를 정의한 헤더 파일.
* **TermProject.exe:** color.h, english.c, korean.c, stringFunc.h, rpg_struct.h, index.c 파일들을 사용하여 만들어진 RPG 게임 실행 파일입니다.

### Tech Stack

* **C언어:** 게임의 모든 로직을 구현하기 위한 주요 언어
* **color.h:** 터미널 컬러 설정을 위한 커스텀 헤더 파일
* **TermProject.exe:** C언어로 개발되었으며, color.h를 이용하여 터미널에서 색상을 표현하고, english.c와 korean.c를 통해 영어와 한국어를 지원하는 텍스트 기반 RPG 게임 실행 파일입니다.

### Development process

1. **기획:** 게임의 스토리, 캐릭터, 시스템 등을 설계.
2. **설계:** 각 기능별로 필요한 함수와 데이터 구조를 설계.
3. **구현:** C언어를 이용하여 설계하였고 매우 다양한 기능들을 구현함.
4. **테스트:** 구현된 기능들을 테스트하고 버그를 수정함. / 제일 많은 시간을 들였음.

### Finish

이 프로젝트를 통해 C언어를 활용하여 실제 프로그램을 개발하는 경험을 쌓았으며, 문제 해결 능력을 향상시킬 수 있었음. 특히, 사용자/이용자로부터 생성되는 수많은 예외들을 처리하는 것에 중점을 두어 많은 노력이 필요했음.

## License

This project is subject to the MIT license.

[![MIT License](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)