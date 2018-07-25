#include "../includes/printf.h"
#include <stdio.h>
#include <float.h>

int main(void)
{
/*
****************
** STRING : s **
****************

	ft_putnbr(ft_printf("{y__}%s : {bW_}%s\n{d__}", "red", "green"));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%s%s : %s%s\n", KRED, "red", KGRN, "green"));
//	ft_putendl(" : return vrai printf");
//	ft_putendl("");

	ft_putendl("s :");
	ft_putnbr(ft_printf("%s \n", "la maison est"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%s \n", "la maison est"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("s basic_01 : NULL");
	ft_putnbr(ft_printf("%s \n", NULL));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%s \n", NULL));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("s basic_02 : coco");
	ft_putnbr(ft_printf("%s \n", "coco"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%s \n", "coco"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("s basic_03 : ");
	ft_putnbr(ft_printf("%s \n", ""));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%s \n", ""));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("s precision_01 : .15 coco");
	ft_putnbr(ft_printf("%.15s \n", "coco"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.15s \n", "coco"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("s precision_02 : .5 coco et titi");
	ft_putnbr(ft_printf("%.5s \n", "coco et titi"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.5s \n", "coco et titi"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("s precision_03 : .0 coco et titi");
	ft_putnbr(ft_printf("%.0s \n", "coco et ti"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.0s \n", "coco et ti"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("s precision_04 : . coco");
	ft_putnbr(ft_printf("%.s \n", "coco"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.s \n", "coco"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("s precision_04 : .2 NULL");
	ft_putnbr(ft_printf("%.2s \n", NULL));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.2s \n", NULL));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("s padding_01 : 10 NULL");
	ft_putnbr(ft_printf("%10s \n", NULL));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%10s \n", NULL));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("s padding_02 : -8 coco");
	ft_putnbr(ft_printf("%-8s \n", "coco"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%-8s \n", "coco"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("s padding_03 : 1 hi");
	ft_putnbr(ft_printf("%1s \n", "hi"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%1s \n", "hi"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("s padding_04 : -2 ");
	ft_putnbr(ft_printf("%-2s \n", ""));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%-2s \n", ""));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("s all_01 : .0 hi	coco	---12 NULL");
	ft_putnbr(ft_printf("Coucou %.0s\n%s%---12s\n", "hi", "coco", NULL));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("Coucou %.0s\n%s%---12s\n", "hi", "coco", NULL));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("s all_02 : 4.2 coco		-1 NULL		---5.3 yooo");
	ft_putnbr(ft_printf("u%4.2ss, %-1.s\n %---5.3s \n", "coco", NULL, "yooo"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("u%4.2ss, %-1.s\n %---5.3s \n", "coco", NULL, "yooo"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("s all_03 : 1.4 tuuu		-6.8 12345		4.2 hu");
	ft_putnbr(ft_printf("%1.4s et %-6.8s et %4.2s\n", "tuuu", "12345", "hu"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%1.4s et %-6.8s et %4.2s\n", "tuuu", "12345", "hu"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

****************
** STRING : S **
****************

	wchar_t k[4];

	k[0] = 0x53;
	k[1] = 0x3abc;
	k[2] = 0x81000;
	k[3] = '\0';

	ft_putendl("S basic_01 :");
	ft_putnbr(ft_printf("%S \n", k));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%S \n", k));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	wchar_t j[4];

	j[0] = 0x53;
	j[1] = 0xd800;
	j[2] = 0x81000;
	j[3] = '\0';

	ft_putendl("S basic_02 :");
	ft_putnbr(ft_printf("%S \n", j));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%S \n", j));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	wchar_t h[4];

	h[0] = 'a';
	h[1] = 254;
	h[2] = 'b';
	h[3] = '\0';

	ft_putendl("S basic_03 :");
	ft_putnbr(ft_printf("%S \n", h));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%S \n", h));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	wchar_t s[4];

	s[0] = 254;
	s[1] = 256;
	s[2] = 'b';
	s[3] = '\0';

	ft_putendl("S basic_04 :");
	ft_putnbr(ft_printf("%S \n", s));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%S \n", s));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	wchar_t s[4];

	s[0] = '\0';
	s[1] = 256;
	s[2] = 'b';
	s[3] = '\0';

	ft_putendl("S basic_05 :");
	ft_putnbr(ft_printf("%S \n", s));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%S \n", s));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	wchar_t s[4];

	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';

	ft_putendl("S precision_01 :");
	ft_putnbr(ft_printf("%.9S \n", s));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%.9S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S precision_02 :");
	ft_putnbr(ft_printf("%.5S \n", s));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%.5S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S precision_03 :");
	ft_putnbr(ft_printf("%.3S \n", s));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%.3S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S precision_04 :");
	ft_putnbr(ft_printf("%.S \n", s));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%.S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S precision_05 :");
	ft_putnbr(ft_printf("%.0S \n", s));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%.0S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S precision_09 :");
	ft_putnbr(ft_printf("%.4S \n", s));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%.4S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

	wchar_t s[4];

	s[0] = 'S';
	s[1] = 254;
	s[2] = 'u';
	s[3] = '\0';

	ft_putendl("S precision_07 :");
	ft_putnbr(ft_printf("%.2S \n", s));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%.2S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S precision_08 :");
	ft_putnbr(ft_printf("%.1S \n", s));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%.1S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

	wchar_t s[4];

	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';

	ft_putendl("S padding_01 :");
	ft_putnbr(ft_printf("%10S \n", s));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%10S \n", s));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S padding_02 :");
	ft_putnbr(ft_printf("%5S \n", s));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%5S \n", s));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S padding_03 :");
	ft_putnbr(ft_printf("%-12S \n", s));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%-12S \n", s));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	wchar_t s[4];

	s[0] = 'a';
	s[1] = 250;
	s[2] = 'b';
	s[3] = '\0';

	ft_putendl("S padding_04 :");
	ft_putnbr(ft_printf("%-4S \n", s));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%-4S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

	wchar_t s[4];

	s[0] = 'a';
	s[1] = 256;
	s[2] = 'b';
	s[3] = '\0';

	ft_putendl("S padding_05 :");
	ft_putnbr(ft_printf("%9S \n", s));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%9S \n", s));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	wchar_t s[4];

	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';

	ft_putendl("S all_01 :");
	ft_putnbr(ft_printf("%---10.5S \n", s));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%---10.5S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

//	wchar_t *c = (wchar_t *)'a';
	
//	ft_putnbr((int)c);

	ft_putendl("S all_02 :");
	ft_putnbr(ft_printf("*%9.6ls %S*\n", s, (wchar_t *)"a"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("*%9.6ls %S*\n", s, (wchar_t *)"a"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S all_03 :");
	ft_putnbr(ft_printf("cc %10.0ls et %.ls et %-2S%-12S\n", s, s, s, s));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("cc %10.0ls et %.ls et %-2S%-12S\n", s, s, s, s));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S :");
	ft_putnbr(ft_printf("%S \n", L"ਊ௸"));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%25s \n", "la maison est"));
//	ft_putendl(" : return vrai printf");
//	ft_putendl("");
	//ft_printf("%S \n", "ਊ௸༺ဪ");
	//ਊ௸༺ဪ%

	ft_putendl("leaks cachée :");
	ft_putnbr(ft_printf("%-10.2ls!!\n", L"〻"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%-10.2ls!!\n", L"〻"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

**************
** CHAR : c **
**************

	ft_putendl("c :");
	ft_putnbr(ft_printf("%25c \n", 'c'));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%25c \n", 'c'));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("c basic_02 :");
	ft_putnbr(ft_printf("**%c** \n", '\0'));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("**%c** \n", '\0'));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("c all_01 : /0	 	(char)564");
	ft_putnbr(ft_printf("hello ca*%----4c* *%1c* va *%10c* *%-c* ??", '\0', '\n', (char)564, 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("hello ca*%----4c* *%1c* va *%10c* *%-c* ??", '\0', '\n', (char)564, 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");


**************
** CHAR : C **
**************

	ft_putendl("C :");
	ft_putnbr(ft_printf("%C \n", L'Æ'));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%25c \n", 'c'));
//	ft_putendl(" : return vrai printf");
//	ft_putendl("");

	ft_putendl("C basic_01 :");
	ft_putnbr(ft_printf("%C \n", 111));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%C \n", 111));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C basic_02 :");
	ft_putnbr(ft_printf("%lc \n", 0x4e6));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%lc \n", 0x4e6));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C basic_03 :");
	ft_putnbr(ft_printf("%lc \n", 0x1e40));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%lc \n", 0x1e40));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C basic_04 :");
	ft_putnbr(ft_printf("%lc \n", 0x40501));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%lc \n", 0x40501));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C basic_05 :");
	ft_putnbr(ft_printf("%C \n", 0x11ffff));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%C \n", 0x11ffff));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C basic_06 :");
	ft_putnbr(ft_printf("%C \n", 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%C \n", 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C basic_07 :");
	ft_putnbr(ft_printf("%C \n", (wint_t)-2));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%C \n", (wint_t)-2));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C basic_08 :");
	ft_putnbr(ft_printf("%C \n", 0xd800));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%C \n", 0xd800));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C basic_09 :");
	ft_putnbr(ft_printf("%C \n", 0xdb02));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%C \n", 0xdb02));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C basic_10 :");
	ft_putnbr(ft_printf("%C \n", 0xdfff));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%C \n", 0xdfff));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C basic_11 :");
	ft_putnbr(ft_printf("%C \n", 0xbffe));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%C \n", 0xbffe));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C basic_12 :");
	ft_putnbr(ft_printf("%C \n", 254));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%C \n", 254));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C basic_13 :");
	ft_putnbr(ft_printf("%C \n", 83));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%C \n", 83));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C basic_14 :");
	ft_putnbr(ft_printf("%C \n", 256));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%C \n", 256));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C basic_15 :");
	ft_putnbr(ft_printf("%C \n", 0xe000));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%C \n", 0xe000));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C padding_01 :");
	ft_putnbr(ft_printf("%5lc \n", 350));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%5lc \n", 350));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C padding_01 :");
	ft_putnbr(ft_printf("%4c", 'U'));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%4c", 'U'));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C padding_02 :");
	ft_putnbr(ft_printf("%-8C \n", 1350));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%-8C \n", 1350));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C padding_03 :");
	ft_putnbr(ft_printf("%-1C \n", 2250));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%-1C \n", 2250));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("c all_01 :");
	ft_putnbr(ft_printf("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C all_01 :");
	ft_putnbr(ft_printf("%8C et coco %C titi %lc\n", 3250, 0x11ffff, 'a'));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%8C et coco %C titi %lc\n", 3250, 0x11ffff, 'a'));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C all_02 :");
	ft_putnbr(ft_printf("%---8C et coco %1C titi\n", 3250, 0xffff));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%---8C et coco %1C titi\n", 3250, 0xffff));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C all_03 :");
	ft_putnbr(ft_printf("%6C et coco %C titi %C tyty\n", 3250, 0xd800, 'u'));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%6C et coco %C titi %C tyty\n", 3250, 0xd800, 'u'));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("C all_04 :");
	ft_putnbr(ft_printf("yo%2C%-12lc et %C titi %C tyty\n", 'u', 254, 256, 'a'));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("yo%2C%-12lc et %C titi %C tyty\n", 'u', 254, 256, 'a'));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

*********************
** INT : i, d et D **
*********************

	ft_putendl("test : ");
	ft_putnbr(ft_printf("%#020X", 12));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#020X", 12));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("test 2 : ");
	ft_putnbr(ft_printf("%#20g", 12.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#20g", 12.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("i et d : basic_01");
	ft_putnbr(ft_printf("%d", 42));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%d", 42));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("i et d : basic_02");
	ft_putnbr(ft_printf("%d", -42));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%d", -42));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("i et d : basic_03");
	ft_putnbr(ft_printf("%d", 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%d", 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("i et d : basic_04");
	ft_putnbr(ft_printf("%d", 3));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%d", 3));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	size_t i = 456454;
	ft_putendl("i et d :");
	ft_putnbr(ft_printf("%zi \n", i));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%zi \n", i));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("i et d :");
	ft_putnbr(ft_printf("%i \n", -0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%i \n", -0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("d precision_06 : ");
	ft_putnbr(ft_printf("%.0i", 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.0i", 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("d precision_05 : ");
	ft_putnbr(ft_printf("%.5d", -421));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.5d", -421));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("d precision_07 : ");
	ft_putnbr(ft_printf("%.d", 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.d", 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("d precision_01 : ");
	ft_putnbr(ft_printf("%.12d", 1144));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.12d", 1144));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("d padding_07 : 0");
	ft_putnbr(ft_printf("04d : **%04d** \n", 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("04d : **%04d** \n", 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("d padding_01 : -741");
	ft_putnbr(ft_printf("5d : **%5d**\n", -741));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("5d : **%5d**\n", -741));
	ft_putendl(" : return vrai printf");
	ft_putendl("");
*/	
	char *s = ft_itoabase(2, 2);
	ft_putstr(s);
	ft_putendl(" : nb");
/*	
	ft_putendl("d all_03 :");
	ft_putnbr(ft_printf("%20.ld et %.4hhi !\n", 0x11ffaa147, (signed char)-8));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%20.ld et %.4hhi !\n", 0x11ffaa147, (signed char)-8));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("d all_04 :");
	ft_putnbr(ft_printf("% 20.12ld et % 05D% 4.8hi !\n", 0x11ffaa147, 24, (short)-2345));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("% 20.12ld et % 05D% 4.8hi !\n", 0x11ffaa147, 24, (short)-2345));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("d all_05 :");
	ft_putnbr(ft_printf("toto%.0d et %+.i et  %   .0D !!!\n", 0, 0, 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("toto%.0d et %+.i et  %   .0D !!!\n", 0, 0, 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("lli modifier_07 :");
	ft_putnbr(ft_printf("%lli \n", (long long)0x11ff11ff11ff11ff));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%lli \n", (long long)0x11ff11ff11ff11ff));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("D :");
	ft_putnbr(ft_printf("%D \n", 0xff11ff11ff88));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%lD \n", 0xff11ff11ff88));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("* :");
	ft_putnbr(ft_printf("%0*.*i %*.*f  \n", 15, 2, 45456, 20, 8, 12.45));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%0*.*i %*.*f  \n", 15, 2, 45456, 20, 8, 12.45));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

*******************************
** UNSIGNED base 10 : u et U **
*******************************

	ft_putendl("u :");
	ft_putnbr(ft_printf("%.u\n", 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.u\n", 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("u : basic_02");
	ft_putnbr(ft_printf("%u", 1234));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%u", 1234));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("u : basic_03");
	ft_putnbr(ft_printf("%u", -1001234));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%u", -1001234));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("u : basic_04");
	ft_putnbr(ft_printf("%U", 231009999));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%U", 231009999));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("u : basic_04");
	ft_putnbr(ft_printf("%hhu", (unsigned char)20));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%hhu", (unsigned char)20));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("u : basic_04");
	ft_putnbr(ft_printf("%hu", (unsigned short)12220));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%hu", (unsigned short)12220));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("lu :");
	ft_putnbr(ft_printf("%llu\n", (unsigned long long)-12345612220));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%llu\n", (unsigned long long)-12345612220));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("zu :");
	ft_putnbr(ft_printf("%zu\n", (size_t)-145612220));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%zu\n", (size_t)-145612220));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("u :");
	ft_putnbr(ft_printf("ko%-4.2hhu et %05.2u!\n", (unsigned char)-456, 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("ko%-4.2hhu et %05.2u!\n", (unsigned char)-456, 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("u précision_05 et 06 : 0");
	ft_putnbr(ft_printf(".u : **%.u**		.0U : **%.0U**\n", 0, 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf(".u : **%.u**		.0U : **%.0U**\n", 0, 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("u all_02 :	0		(unsigned long)14			200");
	ft_putnbr(ft_printf("00009U : **%00009U**		-2lu : **%-2lu**		--14u : **%--14u**\n", 0, (unsigned long)14, 200));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("00009U : **%00009U**		-2lu : **%-2lu**		--14u : **%--14u**\n", 0, (unsigned long)14, 200));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("u all_03 :");
	ft_putnbr(ft_printf("ko%-4.2hhu et %05.2u!", (unsigned char)-456, 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("ko%-4.2hhu et %05.2u!", (unsigned char)-456, 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

******************************
** UNSIGNED base 8 : o et O **
******************************

	ft_putendl("o flag_01 :");
	ft_putnbr(ft_printf("%#o \n", 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#o \n", 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");	

	ft_putendl("o flag_03 :");
	ft_putnbr(ft_printf("%#o \n", -896));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#o \n", -896));
	ft_putendl(" : return vrai printf");
	ft_putendl("");	

	ft_putendl("o modifier_01 :");
	ft_putnbr(ft_printf("%hho \n", (unsigned char)-12));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%hho \n", (unsigned char)-12));
	ft_putendl(" : return vrai printf");
	ft_putendl("");	

	ft_putendl("o modifier_04 :");
	ft_putnbr(ft_printf("%llo \n", (unsigned long long)-127));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%llo \n", (unsigned long long)-127));
	ft_putendl(" : return vrai printf");
	ft_putendl("");	

	ft_putendl("o modifier_05 :");
	ft_putnbr(ft_printf("%zo \n", 0xffff14785aa));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%zo \n", 0xffff14785aa));
	ft_putendl(" : return vrai printf");
	ft_putendl("");	

	ft_putendl("o modifier_06 :");
	ft_putnbr(ft_printf("%jo \n", (uintmax_t)-14785000));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%jo \n", (uintmax_t)-14785000));
	ft_putendl(" : return vrai printf");
	ft_putendl("");	

	ft_putendl("o all_01 :\n		12				-874");
	ft_putnbr(ft_printf("-#24 : **%-#24O** #012 : **%#012o**\n", 12, -874));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("-#24 : **%-#24O** #012 : **%#012o**\n", 12, -874));
	ft_putendl(" : return vrai printf");
	ft_putendl("");	

	ft_putendl("o all_02 :\n	0			0			0");
	ft_putnbr(ft_printf("04.2 : **%04.2o**		#2 : **%#2o**		#-8.3 : **%#-8.3o**\n", 0, 0, 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("04.2 : **%04.2o**		#2 : **%#2o**		#-8.3 : **%#-8.3o**\n", 0, 0, 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");	

	ft_putendl("o all_03 :\n	(unsigned char)12				0			123654789");
	ft_putnbr(ft_printf("024hh : **%024hho**		#1.2 : **%#1.2o**		0012. : **%0012.O**\n", (unsigned char)12, 0, 123654789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("024hh : **%024hho**		#1.2 : **%#1.2o**		0012. : **%0012.O**\n", (unsigned char)12, 0, 123654789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");	

	ft_putendl("o all_04 :\n	012		   036				  12587499");
	ft_putnbr(ft_printf("#.4 : **%#.4o**		02 : **%02o**		0#14.0 : **%0#14.0o**\n", 012, 036, 12587499));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("#.4 : **%#.4o**		02 : **%02o**		0#14.0 : **%0#14.0o**\n", 012, 036, 12587499));
	ft_putendl(" : return vrai printf");
	ft_putendl("");	

	ft_putendl("o all_05 :\n	  0		   0			 0");
	ft_putnbr(ft_printf("###.0o : **%###.0o**		#.O : **%#.O**		#.1o : **%#.1o**		#.o : **%#.o**\n", 0, 0, 0, 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("###.0o : **%###.0o**		#.O : **%#.O**		#.1o : **%#.1o**		#.o : **%#.o**", 0, 0, 0, 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("o all_06 :");
	ft_putnbr(ft_printf("m%#.9od\nee", 123456789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("m%#.9od\nee", 123456789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("o all_06 :");
	ft_putnbr(ft_printf("m%#.9od\nee", 012));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("m%#.9od\nee", 012));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	printf("%dkl kiki", 12);
	ft_putendl("j'affiche qqch");

	ft_putendl("o :");
	ft_putnbr(ft_printf("%#12o \n", 45));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#12o \n", 45));
	ft_putendl(" : return vrai printf");
	ft_putendl("");	

	ft_putendl("o :");
	ft_putnbr(ft_printf("%8.5lo \n", 45L));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%8.5lo \n", 45L));
	ft_putendl(" : return vrai printf");
	ft_putendl("");	

******************************
** UNSIGNED base 2 : b et B **
******************************

	ft_putendl("b :");
	ft_putnbr(ft_printf("%b \n", 45));
	ft_putendl(" : return mon printf");

	ft_putendl("b :");
	ft_putnbr(ft_printf("%b \n", -5));
	ft_putendl(" : return mon printf");

	ft_putendl("b :");
	ft_putnbr(ft_printf("%b \n", 0));
	ft_putendl(" : return mon printf");

	ft_putendl("b :");
	ft_putnbr(ft_printf("%b \n", 3));
	ft_putendl(" : return mon printf");

*******************************
** UNSIGNED base 16 : x et X **
*******************************

	ft_putendl("x et X :");
	ft_putnbr(ft_printf("%lX \n", 1321L));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%lX \n", 1321L));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("x basic_04 et 05 : -12345678	-1234567800");
	ft_putnbr(ft_printf("		%x	%X\n", -12345678, -1234567800));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("		%x	%X\n", -12345678, -1234567800));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("x flags_01 : 0");
	ft_putnbr(ft_printf("#X : **%#X**\n", 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("#X : **%#X**\n", 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("x modifiers_05 : (unsigned long)-178965423");
	ft_putnbr(ft_printf("lx : **%lx**\n", (unsigned long)-178965423));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("lx : **%lx**\n", (unsigned long)-178965423));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("x modifiers_06 : (uintmax_t)-1765423");
	ft_putnbr(ft_printf("jX : **%jX**\n", (uintmax_t)-1765423));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("jX : **%jX**\n", (uintmax_t)-1765423));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("x padding_04 : 0xdd66");
	ft_putnbr(ft_printf("011X : **%011X**\n", 0xdd66));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("011X : **%011X**\n", 0xdd66));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("x précision_01 : 12");
	ft_putnbr(ft_printf(".x : **%.x**\n", 12));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf(".x : **%.x**\n", 12));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("x précision_02 : 0xaabbcc");
	ft_putnbr(ft_printf(".0X : **%.0X**\n", 0xaabbcc));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf(".0X : **%.0X**\n", 0xaabbcc));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("x précision_08 : 0");
	ft_putnbr(ft_printf(".0x : **%.0x**\n", 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf(".0x : **%.0x**\n", 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("x précision_07 : 0");
	ft_putnbr(ft_printf("%.7X", 0xaa));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.7X", 0xaa));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("x all_02 : 0xab		0x876			0xff11ff11ff1");
	ft_putnbr(ft_printf("#7.5X : **%#7.5X**	0006.2x : **%0006.2x**	lX : **%lX**\n", 0xab, 0x876, 0xff11ff11ff1));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("#7.5X : **%#7.5X**	0006.2x : **%0006.2x**	lX : **%lX**\n", 0xab, 0x876, 0xff11ff11ff1));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("x all_04 : 0xaef		0xe			(unsigned short)0");
	ft_putnbr(ft_printf("#.4X : **%#.4X**	#0012x : **%#0012x**	#04hX : **%#04hX**\n", 0xaef, 0xe, (unsigned short)0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("#.4X : **%#.4X**	#0012x : **%#0012x**	#04hX : **%#04hX**\n", 0xaef, 0xe, (unsigned short)0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("x all_05 : 0xff1144ff1144			0xffaabbccee");
	ft_putnbr(ft_printf("#.22zX : **%#.22zX**	020.14jx : **%020.14jx**", 0xff1144ff1144, 0xffaabbccee));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("#.22zX : **%#.22zX**	020.14jx : **%020.14jx**", 0xff1144ff1144, 0xffaabbccee));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("x all_06 : (unsigned long long)-1248759650	(unsigned char)-1478223695");
	ft_putnbr(ft_printf("#9llX :**%#9llX**			-12hhx : **%-12hhx**\n", (unsigned long long)-1248759650, (unsigned char)-1478223695));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("#9llX :**%#9llX**			-12hhx : **%-12hhx**\n", (unsigned long long)-1248759650, (unsigned char)-1478223695));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("x all_07 : 0			0		0		0");
	ft_putnbr(ft_printf("##.0x : **%##.0x**		#.X : **%#.X**	#.x : **%#.x**	###.1x : **%###.1x**\n", 0, 0, 0, 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("##.0x : **%##.0x**		#.X : **%#.X**	#.x : **%#.x**	###.1x : **%###.1x**\n", 0, 0, 0, 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("x all_09 :");
	ft_putnbr(ft_printf("%0#10.0x", 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%0#10.0x", 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");
	

*********************
** DOUBLE : f et F **
*********************

	ft_putendl("f : #");
	ft_putnbr(ft_printf("%f \n", 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%f \n", 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : #");
	ft_putnbr(ft_printf("%f \n", 1.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%f \n", 1.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	float ld = -0.0;
	unsigned int ui = (unsigned int)ld;

	if (ui == 0b10000000000000000000000000000000)
		ft_putendl("ld est negatif");

	double l = -0.625;
	unsigned int j = (unsigned int)l;

	ft_putendl("f : #");
	ft_putnbr(ft_printf("%f %b \n", l, j));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%f \n", l));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

// met - devant le 0....
	ft_putendl("f : #");
	ft_putnbr(ft_printf("%f \n", -0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%f \n", -0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : #");
	ft_putnbr(ft_printf("%f \n", 5.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%f \n", 5.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : 0");
	ft_putnbr(ft_printf("%.15f \n", 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.15f \n", 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : 1 .15");
	ft_putnbr(ft_printf("%.15f \n", 1.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.15f \n", 1.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : 5 .15");
	ft_putnbr(ft_printf("%.15f \n", 5.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.15f \n", 5.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : long");
	ft_putnbr(ft_printf("%f %f \n", -0.000000000000000004745, -45486486456456784.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%f %f \n", -0.000000000000000004745, -45486486456456784.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

//	-45486486456456.789			*
//	-45486486456456.789062		***
//	-454864864564567.789		*
//	-454864864564567.812500		***
//	-4548648645645678.789		*
//	-4548648645645678.999759	**
//	-4548648645645679.000000	***

	ft_putendl("f : tres long");
	ft_putnbr(ft_printf("%f %f \n", -0.000000000000000004745, -45486486456456456445648.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%f %f \n", -0.000000000000000004745, -45486486456456456445648.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

//	-4548648645645645	64.789			*
//	-4548648645645645	44.000000		***
//	-4548648645645645	6445648.789		*
//	-45486486456456460	632064.000000	***

	ft_putendl("f : negative");
	ft_putnbr(ft_printf("%f %f \n", -0.0004745, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%f %f \n", -0.0004745, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : width 15");
	ft_putnbr(ft_printf("%15f %15f \n", -0.0004745, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%15f %15f \n", -0.0004745, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : width 0");
	ft_putnbr(ft_printf("%0f %0f \n", -0.0004745, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%0f %0f \n", -0.0004745, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : precision .15");
	ft_putnbr(ft_printf("%.15f %.15f \n", -0.0004745, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.15f %.15f \n", -0.0004745, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : precision .0");
	ft_putnbr(ft_printf("%.0f %.0f \n", -0.0004745, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.0f %.0f \n", -0.0004745, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : precision .1");
	ft_putnbr(ft_printf("%.1f %.1f \n", -0.0004745, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.1f %.1f \n", -0.0004745, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : #.");
	ft_putnbr(ft_printf("%#8.2f \n", 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#8.2f \n", 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : #.");
	ft_putnbr(ft_printf("%#.f \n", 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.f \n", 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : #.");
	ft_putnbr(ft_printf("%#.f \n", 1.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.f \n", 1.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : #");
	ft_putnbr(ft_printf("%#f %#f \n", 0.0004745, 45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#f %#f \n", 0.0004745, 45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : #");
	ft_putnbr(ft_printf("%#.f %#.f \n", 0.0, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.f %#.f \n", 0.0, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : #");
	ft_putnbr(ft_printf("%#7.5f %#0.12f \n", 0.0004745, 45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#7.5f %#0.12f \n", 0.0004745, 45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("F : #");
	ft_putnbr(ft_printf("%#.F %#.f \n", 0.0004745, 45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.F %#.f \n", 0.0004745, 45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("F : #");
	ft_putnbr(ft_printf("%#.1F %#.1f \n", 0.0004745, 45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.1F %#.1f \n", 0.0004745, 45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f :"); // double en double, long double en long double
	ft_putnbr(ft_printf("%.f %.f \n", 0.0004745, 45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.f %.f \n", 0.0004745, 45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("* :");
	ft_putnbr(ft_printf("%0*.*i %*.*f  \n", 15, 2, 45456, 20, 8, 12.45));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%0*.*i %*.*f  \n", 15, 2, 45456, 20, 8, 12.45));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

//	ft_putnbr(LDBL_MAX);
//	ft_putendl(" : max ld");
//	ici pas bon : voir si type float ok
	ft_putendl(".20 :");
	ft_putnbr(ft_printf("%.20f  \n", 4895.457));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.20f  \n", 4895.457));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

*********************
** DOUBLE : e et E **
*********************

	ft_putendl("e : 0");
	ft_putnbr(ft_printf("%e \n", 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%e \n", 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e : 1");
	ft_putnbr(ft_printf("%e \n", 1.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%e \n", 1.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e : 5");
	ft_putnbr(ft_printf("%e \n", 5.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%e \n", 5.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e : .15 5");
	ft_putnbr(ft_printf("%.15e \n", 5.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.15e \n", 5.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e : . 5");
	ft_putnbr(ft_printf("%.e \n", 5.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.e \n", 5.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e : 5.2");
	ft_putnbr(ft_printf("%e \n", 5.2));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%e \n", 5.2));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e : 0");
	ft_putnbr(ft_printf("%e \n", -0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%e \n", -0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e :"); // double en double, long double en long double
	ft_putnbr(ft_printf("%e \n", 4.1));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%e \n", 4.1));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e :"); // double en double, long double en long double
	ft_putnbr(ft_printf("%e \n", 4.005));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%e \n", 4.005));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e :"); // double en double, long double en long double
	ft_putnbr(ft_printf("%e \n", 4.005565656));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%e \n", 4.005565656));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e :"); // double en double, long double en long double
	ft_putnbr(ft_printf("%e \n", 4.115645456));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%e \n", 4.115645456));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e .0 :");
	ft_putnbr(ft_printf("%e \n", 78.458565));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%e \n", 78.458565));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e :"); // double en double, long double en long double
	ft_putnbr(ft_printf("%e \n", -0.00000048787895));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%e \n", -0.00000048787895));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e :"); // double en double, long double en long double
	ft_putnbr(ft_printf("%.0e \n", -0.00000048787895));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.0e \n", -0.00000048787895));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e tres long :");
	ft_putnbr(ft_printf("%E \n", -0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000758912));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%E \n", -0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000758912));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e .0 :");
	ft_putnbr(ft_printf("%.0e \n", 78.458565));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.0e \n", 78.458565));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e .20 :");
	ft_putnbr(ft_printf("%.20e \n", 78.458565));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.20e \n", 78.458565));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e : #");
	ft_putnbr(ft_printf("%#e %#e \n", -0.0004745, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#e %#e \n", -0.0004745, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("E : #.");
	ft_putnbr(ft_printf("%#.1E %#.1E \n", 0.0004745, 45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.1E %#.1E \n", 0.0004745, 45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("E : 20 width");
	ft_putnbr(ft_printf("%20E %20E \n", 0.0004745, 45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%20E %20E \n", 0.0004745, 45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("* :");
	ft_putnbr(ft_printf("%*.*e  \n", 20, 8, 12.45));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%*.*e  \n", 20, 8, 12.45));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("* :");
	ft_putnbr(ft_printf("%*.*e  \n", 20, 10, 1354554667878645345456464646547.45));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%*.*e  \n", 20, 10, 1354554667878645345456464646547.45));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : #");
	ft_putnbr(ft_printf("%#7.5e %#0.12e \n", 0.0004745, 45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#7.5e %#0.12e \n", 0.0004745, 45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

*********************
** DOUBLE : g et G **
*********************

	ft_putendl("g : 0");
	ft_putnbr(ft_printf("%g \n", 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%g \n", 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : 1");
	ft_putnbr(ft_printf("%g \n", 1.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%g \n", 1.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : 5");
	ft_putnbr(ft_printf("%g \n", 5.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%g \n", 5.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : 0");
	ft_putnbr(ft_printf("%g \n", -0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%g \n", -0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : 0");
	ft_putnbr(ft_printf("%.15g \n", 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.15g \n", 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : 1 .15");
	ft_putnbr(ft_printf("%.15g \n", 1.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.15g \n", 1.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : 5 .15");
	ft_putnbr(ft_printf("%.15g \n", 5.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.15g \n", 5.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : 1.1");
	ft_putnbr(ft_printf("%g \n", 1.1));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%g \n", 1.1));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : width");
	ft_putnbr(ft_printf("%15g %15g \n", -0.0004745, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%15g %15g \n", -0.0004745, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : #");
	ft_putnbr(ft_printf("%#g %#g \n", -0.0004745, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#g %#g \n", -0.0004745, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : #");
	ft_putnbr(ft_printf("%#g \n", 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#g \n", 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : #.");
	ft_putnbr(ft_printf("%#.g \n", 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.g \n", 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : #.12");
	ft_putnbr(ft_printf("%#.12g \n", 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.12g \n", 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : #.");
	ft_putnbr(ft_printf("%#.g \n", 0.1));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.g \n", 0.1));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : #.");
	ft_putnbr(ft_printf("%#.12g \n", 0.1));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.12g \n", 0.1));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : #.");
	ft_putnbr(ft_printf("%#.g \n", 1.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.g \n", 1.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : #.");
	ft_putnbr(ft_printf("%#.g \n", 1.1));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.g \n", 1.1));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : #.");
	ft_putnbr(ft_printf("%#.12g \n", 1.1));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.12g \n", 1.1));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : #");
	ft_putnbr(ft_printf("%#g \n", 1.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#g \n", 1.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : #");
	ft_putnbr(ft_printf("%#g \n", 5.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#g \n", 5.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : #");
	ft_putnbr(ft_printf("%.2g \n", 1.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.2g \n", 1.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : #");
	ft_putnbr(ft_printf("%#g %#g \n", +0.000000000004745, -454568972136897.846852238639));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#g %#g \n", +0.000000000004745, -454568972136897.846852238639));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : #");
	ft_putnbr(ft_printf("%#.g %#.g \n", +0.000000000004745, -454568972136897.846852238639));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.g %#.g \n", +0.000000000004745, -454568972136897.846852238639));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : #");
	ft_putnbr(ft_printf("%#.g %#.g \n", 0.0, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.g %#.g \n", 0.0, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : #");
	ft_putnbr(ft_printf("%#g %#g \n", 0.0, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#g %#g \n", 0.0, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g :"); // double en double, long double en long double
	ft_putnbr(ft_printf("%.20g **** %.20g \n", 4565445.5546456, 0.0004567878));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.20g **** %.20g \n", 4565445.5546456, 0.0004567878));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g :"); // double en double, long double en long double
	ft_putnbr(ft_printf("%Lg **** %.5Lg \n", 4565445.5546456L, 0.0004567878L));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%Lg **** %.5Lg \n", 4565445.5546456L, 0.0004567878L));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g :"); // double en double, long double en long double
	ft_putnbr(ft_printf("%.g %.g \n", -4565445.0, -0.0004567878));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.g %.g \n", -4565445.0, -0.0004567878));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("L :");
	ft_putnbr(ft_printf("%Lg \n", 4565445.5546456L));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%Lg \n", 4565445.5546456L));
	ft_putendl(" : return vrai printf");
	ft_putendl("");


*************************
** DOUBLE HEX : a et A **
*************************

	ft_putendl("a : 0");
	ft_putnbr(ft_printf("%a \n", 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%a \n", 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : 1");
	ft_putnbr(ft_printf("%a \n", 1.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%a \n", 1.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : 5");
	ft_putnbr(ft_printf("%a \n", 5.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%a \n", 5.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : 0");
	ft_putnbr(ft_printf("%a \n", -0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%a \n", -0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : 0");
	ft_putnbr(ft_printf("%.15a \n", 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.15a \n", 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : 0");
	ft_putnbr(ft_printf("%.a \n", 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.a \n", 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : 1 .");
	ft_putnbr(ft_printf("%.a \n", 1.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.a \n", 1.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : 1 .8");
	ft_putnbr(ft_printf("%.8a \n", 1.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.8a \n", 1.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : 5 .15");
	ft_putnbr(ft_printf("%.15a \n", 5.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.15a \n", 5.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : 1.1");
	ft_putnbr(ft_printf("%a \n", 1.1));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%a \n", 1.1));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : width");
	ft_putnbr(ft_printf("%15a %15a \n", -0.0004745, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%15a %15a \n", -0.0004745, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #");
	ft_putnbr(ft_printf("%#a %#a \n", -0.0004745, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#a %#a \n", -0.0004745, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #.");
	ft_putnbr(ft_printf("%#.a %#.a \n", -0.0004745, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.a %#.a \n", -0.0004745, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : .");
	ft_putnbr(ft_printf("%.a %.a \n", -0.0004745, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.a %.a \n", -0.0004745, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : .0");
	ft_putnbr(ft_printf("%.0a %.0a \n", -0.0004745, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.0a %.0a \n", -0.0004745, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : .1");
	ft_putnbr(ft_printf("%.1a %.1a \n", -0.0004745, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.1a %.1a \n", -0.0004745, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #");
	ft_putnbr(ft_printf("%#a \n", 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#a \n", 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #.");
	ft_putnbr(ft_printf("%#.a \n", 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.a \n", 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #.12");
	ft_putnbr(ft_printf("%#.12a \n", 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.12a \n", 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #.");
	ft_putnbr(ft_printf("%#.a \n", 0.1));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.a \n", 0.1));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : .12");
	ft_putnbr(ft_printf("%#.12a \n", 0.1));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.12a \n", 0.1));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #.");
	ft_putnbr(ft_printf("%#.a \n", 1.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.a \n", 1.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #.");
	ft_putnbr(ft_printf("%#.a \n", 1.1));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.a \n", 1.1));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #.12");
	ft_putnbr(ft_printf("%#.12a \n", 1.1));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.12a \n", 1.1));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #");
	ft_putnbr(ft_printf("%#a \n", 1.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#a \n", 1.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #");
	ft_putnbr(ft_printf("%#a \n", 5.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#a \n", 5.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #");
	ft_putnbr(ft_printf("%.2a \n", 1.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.2a \n", 1.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #");
	ft_putnbr(ft_printf("%#a %#a \n", +0.000000000004745, -454568972136897.846852238639));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#a %#a \n", +0.000000000004745, -454568972136897.846852238639));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #");
	ft_putnbr(ft_printf("%#.a %#.a \n", +0.000000000004745, -454568972136897.846852238639));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.a %#.a \n", +0.000000000004745, -454568972136897.846852238639));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #");
	ft_putnbr(ft_printf("%#.a %#.a \n", 0.0, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.a %#.a \n", 0.0, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #");
	ft_putnbr(ft_printf("%#a %#a \n", 0.0, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#a %#a \n", 0.0, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a :"); // double en double, lona double en lona double
	ft_putnbr(ft_printf("%.20a **** %.20a \n", 4565445.5546456, 0.0004567878));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.20a **** %.20a \n", 4565445.5546456, 0.0004567878));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a :"); // double en double, lona double en lona double
	ft_putnbr(ft_printf("%La **** %.5La \n", 4565445.5546456L, 0.0004567878L));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%La **** %.5La \n", 4565445.5546456L, 0.0004567878L));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #."); // double en double, lona double en lona double
	ft_putnbr(ft_printf("%#.La **** %#.La \n", 4565445.5546456L, 0.0004567878L));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.La **** %#.La \n", 4565445.5546456L, 0.0004567878L));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : "); 
	ft_putnbr(ft_printf("%La **** %La \n", 0.0L, 1.0L));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%La **** %La \n", 0.0L, 1.0L));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : "); 
	ft_putnbr(ft_printf("%#.La **** %#.La \n", 0.0L, 1.0L));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.La **** %#.La \n", 0.0L, 1.0L));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : "); 
	ft_putnbr(ft_printf("%.20La **** %.20La \n", 4565445.5546456L, 0.0004567878L));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.20La **** %.20La \n", 4565445.5546456L, 0.0004567878L));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a :"); // double en double, lona double en lona double
	ft_putnbr(ft_printf("%.a %.a \n", -4565445.0, -0.0004567878));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.a %.a \n", -4565445.0, -0.0004567878));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("L :");
	ft_putnbr(ft_printf("%La \n", 4565445.5546456L));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%La \n", 4565445.5546456L));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #");
	ft_putnbr(ft_printf("%a %a \n", -0.0004745, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%a %a \n", -0.0004745, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a : #");
	ft_putnbr(ft_printf("%.6a %.6a \n", -0.0004745, -45.789));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.6a %.6a \n", -0.0004745, -45.789));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a :");
	ft_putnbr(ft_printf("%a \n", 16777215.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%a \n", 16777215.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a :");
	ft_putnbr(ft_printf("%.4a \n", 16777215.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.4a \n", 16777215.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a :");
	ft_putnbr(ft_printf("%#a \n", 16777215.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#a \n", 16777215.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a :");
	ft_putnbr(ft_printf("%#.a \n", 16777215.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.a \n", 16777215.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("a :");
	ft_putnbr(ft_printf("%.a \n", 16777215.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.a \n", 16777215.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

****************
** ADRESS : p **
****************

//	char *s = "la maison est bleue";
//	long long p = 45648675425;
//	int f = 456456;
//	char v = 'p';
	int *j;
	j = (int*)ft_memalloc(sizeof(int));
	*j = 15;

	ft_putendl("-----------");
	ft_putnbr(ft_printf("TEST: %d, %p\n", *j, j));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("TEST: %d, %p\n", *j, j));
	ft_putendl(" : return vrai printf");
	ft_putendl("-----------");

	ft_putendl("p :");
	ft_putnbr(ft_printf("%25p \n", &v));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%25p \n", &v));
	ft_putendl(" : return vrai printf");
	ft_putendl("");
*/
//	t_list data;
//	int ret;
/*

	ft_putendl("p : basic 01");
	ft_putnbr(ft_printf("%p\n", NULL));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%p\n", NULL));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("p : basic 02");
	ft_putnbr(ft_printf("%p\n", &data));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%p\n", &data));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("p : padding 01");
	ft_putnbr(ft_printf("%20p\n", &data));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%20p\n", &data));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("p : padding 02");
	ft_putnbr(ft_printf("%-25p\n", &data));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%-25p\n", &data));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("p : padding 03");
	ft_putnbr(ft_printf("%2p\n", &data));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%2p\n", &data));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("p :");
	ft_putnbr(ft_printf("%----24p et hello %2p %12p\n", &ret, &p_all_01, NULL));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%----24p et hello %2p %12p\n", &ret, &p_all_01, NULL));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

***********************
** NB WRITE CHAR : n **
***********************

	int n;
	
	ft_putendl("n :");
	ft_putnbr(ft_printf("la maison%n est bleue\n", &n));
	ft_putendl(" : return mon printf");
	ft_putnbr(n);
	ft_putendl(" : n");
	ft_putnbr(printf("la maison%n est bleue\n", &n));
	ft_putendl(" : return vrai printf");
	ft_putnbr(n);
	ft_putendl(" : n");

******************
** POURCENT : % **
******************

	ft_putendl("% basic_01 : %%");
	ft_putnbr(ft_printf("%% \n"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%% \n"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("% flags_01 : % %");
	ft_putnbr(ft_printf("% % \n"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("% % \n"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("% flags_02 : %+%");
	ft_putnbr(ft_printf("%+% \n"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%+% \n"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("% flags_03 : %#%");
	ft_putnbr(ft_printf("%#% \n"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#% \n"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("% précision_01 : %.8%");
	ft_putnbr(ft_printf("%.8% \n"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.8% \n"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("% précision_02 : %.1%");
	ft_putnbr(ft_printf("%.1% \n"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.1% \n"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("% précision_03 : %.0%");
	ft_putnbr(ft_printf("%.0% \n"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.0% \n"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("% précision_04 : %.%");
	ft_putnbr(ft_printf("%.% \n"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.% \n"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("% padding_01 : %12%");
	ft_putnbr(ft_printf("%12% \n"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%12% \n"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("% padding_02 : %-4%");
	ft_putnbr(ft_printf("%-4% \n"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%-4% \n"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("% padding_03 : %017%");
	ft_putnbr(ft_printf("%017% \n"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%017% \n"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("% padding_01 : +---12.5% et %%%0004% et %+1%");
	ft_putnbr(ft_printf("titi % +---12.5% et%%%0004% et %+1%\n"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("titi % +---12.5% et%%%0004% et %+1%\n"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("% test_01 :");
	ft_putnbr(ft_printf(""));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf(""));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

***********
** MIXED **
***********

	int ret;

	ft_putendl("test_01 :");
	ft_putnbr(ft_printf("test %-12i et %--2.4s %24s !\n", 0, NULL, "cooc"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("test %-12i et %--2.4s %24s !\n", 0, NULL, "cooc"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("test_02 :");
	ft_putnbr(ft_printf("%--.4u et %#O%#012lo%1lc\n", -12, 0, (unsigned long)0, 95));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%--.4u et %#O%#012lo%1lc\n", -12, 0, (unsigned long)0, 95));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("test_03 :");
	ft_putnbr(ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi\n", 125, 124, 256));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%-+-12.7Dt%0 4i %04.2% et %lc titi\n", 125, 124, 256));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("test_04 :");
	ft_putnbr(ft_printf("test%-8p, %---32p, %#5.3x%#024X", &ret, &ret, 0x25, 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("test%-8p, %---32p, %#5.3x%#024X", &ret, &ret, 0x25, 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("test_05 :");
	ft_putnbr(ft_printf("test %-7C %007d%-10.2ls!!\n", 0xd777, 0x45, L"〻"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("test %-7C %007d%-10.2ls!!\n", 0xd777, 0x45, L"〻"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

//	condition segfault sans -WWW :
//	printf("%.s", 42);
//	ft_printf("%.s", 42);
*/
//	while (1);

}
