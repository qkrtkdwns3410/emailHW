#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void parseEmailToPart();

void concatPartToEmail();

/*
 *
 *
 * @ 함수 : main
 * @ 목적 : 이메일 변환기
 *
 *
 *
 *
 * */
int main() {
    printf("메뉴\n");
    printf("1 : E-mail --> 각 요소로 분리하기\n");
    printf("2 : 각 요소 --> E-mail 만들기\n");
    printf("선택하세요:\n");
    
    //문자형 변수 선언
    char switch_str[20];
    scanf("%s", &switch_str);
    
    //atoi : ASCII to int
    switch (atoi(switch_str)) {
        case 1:
            parseEmailToPart();
            break;
        case 2:
            concatPartToEmail();
            break;
        default:
            printf("잘못된 번호 입력");
    }
    
    return 0;
}

/*
 * @ 메서드 : concatPartToEmail
 * @ 반환 :X
 * @ 설명 : 이메일을 입력받고 , 모든 문자를 소문자로 변환 후 해당 조건별로 분류합니다.
 *
 * */
void concatPartToEmail() {
    
    char name[20];
    char system[50];
    char domain[50];
    char org[50];
    char country[50];
    
    printf("입력 : [이름] [시스템] [도메인] [기관] [국가]\n");
    printf("(E-mail에 국가 이름 없을 경우 \"usa\" 입력)\n");
    scanf("%s %s %s %s %s", &name, &system, &domain, &org, &country);
    
    if (strcmp(country, "usa") == 0) {
        printf("E-mail : %s@%s.%s.%s", name, system, domain, org);
        
    } else {
        printf("E-mail : %s@%s.%s.%s.%s", name, system, domain, org, country);
        
    }
    
    
}

/*
 * @ 메서드 : parseEmailToPart
 * @ 반환 :X
 * @ 설명 : 요소 내용을 입력받고, 이메일을 만들어 출력합니다.
 *
 * */
void parseEmailToPart() {
    char email_str[50];
    printf("E-mail을 입력 하시오 : \n");
    printf("( 예:name@sys.domain.org OR name@sys.domain.org.country )\n");
    
    scanf("%s", &email_str);
    strlwr(email_str);
    char *ptr = strtok(email_str, ".");
    
    char *special_name_sys;
    char *special_domain;
    char *special_organization;
    char *special_country = NULL;
    char *special_name;
    char *special_sys;
    
    int index = 0;
    int index2 = 0;
    while (ptr != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
    {
        switch (index) {
            case 0:
                special_name_sys = ptr;
                break;
            case 1:
                special_domain = ptr;
                break;
            case 2:
                special_organization = ptr;
                break;
            case 3:
                special_country = ptr;
                break;
            default:
                break;
        }
        index += 1;
        ptr = strtok(NULL, ".");      // 다음 문자열을 잘라서 포인터를 반환
    }
    
    char *ptr2 = strtok(special_name_sys, "@");
    while (ptr2 != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
    {
        switch (index2) {
            case 0:
                special_name = ptr2;
                break;
            
            case 1:
                special_sys = ptr2;
                break;
            
            default:
                break;
        }
        index2 += 1;
        ptr2 = strtok(NULL, "@");      // 다음 문자열을 잘라서 포인터를 반환
    }
    
    printf("name : %s\n", special_name);
    printf("system : %s\n", special_sys);
    printf("domain : %s\n", special_domain);
    printf("organization : %s\n", special_organization);
    if (special_country != NULL) {
        printf("country : %s\n", special_country);
        
    }
    
    
}
