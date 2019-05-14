#include "printf.h"
#include <stdio.h>
#include <float.h>

int main(void)
{
/*
************
** BASICS **
************

	ft_putendl("BASICS");
	ft_putendl("s :");
	ft_putnbr(ft_printf("coco\net titi \n"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("coco\net titi \n"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

****************
** STRING : s **
****************

	ft_putendl("STRING : s");
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

	ft_putendl("STRING : big_S");
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

	wchar_t j5[4];

	j5[0] = 0x53;
	j5[1] = 0xd800;
	j5[2] = 0x81000;
	j5[3] = '\0';

	ft_putendl("S basic_02 :");
	ft_putnbr(ft_printf("%S \n", j5));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%S \n", j5));
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

	wchar_t o[4];

	o[0] = '\0';
	o[1] = 256;
	o[2] = 'b';
	o[3] = '\0';

	ft_putendl("S basic_05 :");
	ft_putnbr(ft_printf("%S \n", o));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%S \n", o));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	wchar_t s1[4];

	s1[0] = 0x53;
	s1[1] = 0x3abc;
	s1[2] = 0x81000;
	s1[3] = '\0';

	ft_putendl("S precision_01 :");
	ft_putnbr(ft_printf("%.9S \n", s1));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%.9S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S precision_02 :");
	ft_putnbr(ft_printf("%.5S \n", s1));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%.5S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S precision_03 :");
	ft_putnbr(ft_printf("%.3S \n", s1));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%.3S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S precision_04 :");
	ft_putnbr(ft_printf("%.S \n", s1));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%.S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S precision_05 :");
	ft_putnbr(ft_printf("%.0S \n", s1));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%.0S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S precision_09 :");
	ft_putnbr(ft_printf("%.4S \n", s1));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%.4S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

	wchar_t s2[4];

	s2[0] = 'S';
	s2[1] = 254;
	s2[2] = 'u';
	s2[3] = '\0';

	ft_putendl("S precision_07 :");
	ft_putnbr(ft_printf("%.2S \n", s2));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%.2S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S precision_08 :");
	ft_putnbr(ft_printf("%.1S \n", s2));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%.1S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

	wchar_t s3[4];

	s3[0] = 0x53;
	s3[1] = 0x3abc;
	s3[2] = 0x81000;
	s3[3] = '\0';

	ft_putendl("S padding_01 :");
	ft_putnbr(ft_printf("%10S \n", s3));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%10S \n", s3));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S padding_02 :");
	ft_putnbr(ft_printf("%5S \n", s3));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%5S \n", s3));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S padding_03 :");
	ft_putnbr(ft_printf("%-12S \n", s3));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%-12S \n", s3));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	wchar_t s4[4];

	s4[0] = 'a';
	s4[1] = 250;
	s4[2] = 'b';
	s4[3] = '\0';

	ft_putendl("S padding_04 :");
	ft_putnbr(ft_printf("%-4S \n", s4));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%-4S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

	wchar_t s5[4];

	s5[0] = 'a';
	s5[1] = 256;
	s5[2] = 'b';
	s5[3] = '\0';

	ft_putendl("S padding_05 :");
	ft_putnbr(ft_printf("%9S \n", s5));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%9S \n", s5));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	wchar_t s6[4];

	s6[0] = 0x53;
	s6[1] = 0x3abc;
	s6[2] = 0x81000;
	s6[3] = '\0';

	ft_putendl("S all_01 :");
	ft_putnbr(ft_printf("%---10.5S \n", s6));
	ft_putendl(" : return mon printf");
//	ft_putnbr(printf("%---10.5S \n", s));
//	ft_putendl(" : return vrai printf");
	ft_putendl("");

//	wchar_t *c = (wchar_t *)'a';
	
//	ft_putnbr((int)c);

	ft_putendl("S all_02 :");
	ft_putnbr(ft_printf("*%9.6ls %S*\n", s6, (wchar_t *)"a"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("*%9.6ls %S*\n", s6, (wchar_t *)"a"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("S all_03 :");
	ft_putnbr(ft_printf("cc %10.0ls et %.ls et %-2S%-12S\n", s6, s6, s6, s6));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("cc %10.0ls et %.ls et %-2S%-12S\n", s6, s6, s6, s6));
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

	ft_putendl("CHAR : c");
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
	ft_putnbr(ft_printf("hello ca**%----4c** **%1c** va **%10c****%-c** ??", '\0', '\n', (char)564, 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("hello ca**%----4c** **%1c** va **%10c****%-c** ??", '\0', '\n', (char)564, 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

**************
** CHAR : C **
**************

	ft_putendl("CHAR : big_C");
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
	ft_putnbr(ft_printf("hello ca**%----4c** **%1c** va **%10c****%-c** ??", '\0', '\n', (char)564, 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("hello ca**%----4c** **%1c** va **%10c****%-c** ??", '\0', '\n', (char)564, 0));
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

	ft_putendl("INT : i, d, D");
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

	ft_putnbr(ft_atoi("456466"));
	ft_putendl(" : nb");
	ft_putnbr(atoi("456466"));
	ft_putendl(" : le atoi");
	
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

	ft_putendl("UNSIGNED base 10 : u et U");
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

	ft_putendl("UNSIGNED base 8 : o et O");
	ft_putendl("o basic_01 :");
	ft_putnbr(ft_printf("%o", 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%o", 0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");	

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

	ft_putendl("UNSIGNED base 2 : b et B");
	ft_putendl("b :");
	ft_putnbr(ft_printf("%b \n", 45));
	ft_putendl(" : return mon printf");

	ft_putendl("b :");
	ft_putnbr(ft_printf("%b \n", 16));
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

	ft_putendl("UNSIGNED base 16 : x et X");
	ft_putendl("x et X :");
	ft_putnbr(ft_printf("%x \n", 64));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%x \n", 64));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

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

	ft_putendl("DOUBLE : f et F");
	ft_putendl("f : #");
	ft_putnbr(ft_printf("%f %f \n", 0.0, -0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%f %f \n", 0.0, -0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : #");
	ft_putnbr(ft_printf("%f \n", 1.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%f \n", 1.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

//	float ld = -0.0;
//	unsigned int ui = (unsigned int)ld;

//	if (ui == 0b10000000000000000000000000000000)
//		ft_putendl("ld est negatif");

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

	ft_putendl("f : precision .0");
	ft_putnbr(ft_printf("%.0f %.0f %.0f %.0f %.0f %.15f \n", 0.0004745, -45.789, 5.0, 1.0, 0.0, 999999.9999));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.0f %.0f %.0f %.0f %.0f \n", 0.0004745, -45.789, 5.0, 1.0, 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");


	long double h;
	double		g;
	int i;
	int k;

	h = 999999.9999;
	g = 999999.9999;
	i = -1;

	while (h / 10 > 1)
		h = h / 10;
	while (g / 10 > 1)
		g = g / 10;
	while (++i < 20)
	{
		k = h * 1;
		ft_putchar(k + '0');
		h = h - k;
		h = h * 10;
	}
	ft_putchar('\n');
	i = -1;
	while (++i < 20)
	{
		k = g * 1;
		ft_putchar(k + '0');
		g = g - k;
		g = g * 10;
	}


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
	ft_putnbr(ft_printf("%f %f %.2f %.2f\n", -0.000000000000000004745, -45486486456456456445648.999, 99999.9489, -99999.949));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%f %f %.2f %.2f\n", -0.000000000000000004745, -45486486456456456445648.999, 99999.9489, -99999.949));
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
	ft_putnbr(ft_printf("%f %f %f %f %f %f \n", -0.0004745, -45.789, 5.0, 9999.9, -0.0, 999999.999));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%f %f %f %f %f %f \n", -0.0004745, -45.789, 5.0, 9999.9, -0.0, 999999.999));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : precision .0");
	ft_putnbr(ft_printf(" %f %.35f %.35f %f %.4f %.4f\n", 12.0785438794, 0.99999, -99.99999, -9999.9999999, 99.999944, -999.999935));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf(" %f %.35f %.35f %f %.4f %.4f\n", 12.0785438794, 0.99999, -99.99999, -9999.9999999, 99.999944, -999.999935));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("f : precision .0");
	ft_putnbr(ft_printf("%f\n", 12.07854387946));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%f\n", 12.07854387946));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	long double h = 42.5180;
	int u = 42;
	long double j = h * 10000000000000000000;

	ft_putendl("f : precision .0");
	ft_putnbr(ft_printf("%.19Lf %.19Lf \n", h, j));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.19Lf %.19Lf \n", h, j));
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

printf("67.8463756,   67.8463755,   67.8463745,   67.8463754,   67.8463785,   67.8463758,   67.8463786,   67.8463786\n");
printf("%f     %f     %f     %f     %f     %f     %f     %f \n\n", 67.8463756, 67.8463755, 67.8463745, 67.8463754, 67.8463785, 67.8463758, 67.8463786, 67.8463786);
printf("0.7843756, 0.7843755, 0.7843745, 0.7843754, 0.7843785, 0.7843756, 0.7843786, 0.7843786\n");
printf("%f   %f   %f   %f   %f   %f   %f   %f   \n\n", 0.7843756, 0.7843755, 0.7843745, 0.7843754, 0.7843785, 0.7843756, 0.7843786, 0.7843786);
printf("67.8463765,  67.8463775,  67.8463755,   67.8463745,   67.8463754,   67.8463785,   67.8463758,   67.8463786,   67.8463786\n");
printf("%f     %f     %f     %f     %f     %f     %f     %f     %f   \n\n", 67.8463765, 67.8463775, 67.8463755, 67.8463745, 67.8463754, 67.8463785, 67.8463758, 67.8463786, 67.843786);
printf("0.7843765, 0.7843775, 0.7843755, 0.7843745, 0.7843754, 0.7843785, 0.7843756, 0.7843786, 0.7843786\n");
printf("%f   %f   %f   %f   %f   %f   %f   %f   %f   \n\n", 0.7843765, 0.7843775, 0.7843755, 0.7843745, 0.7843754, 0.7843785, 0.7843756, 0.7843786, 0.7843786);


*********************
** DOUBLE : e et E **
*********************

	ft_putendl("DOUBLE : e et E");
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
	ft_putnbr(ft_printf("%e %e %e %e %e %e %e %e\n", 4.1, 4.01, 4.001, 4.0001, 4.00001, 4.000001, 4.0000001, 4.00000001));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%e %e %e %e %e %e %e %e\n", 4.1, 4.01, 4.001, 4.0001, 4.00001, 4.000001, 4.0000001, 4.00000001));
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
	ft_putnbr(ft_printf("%e %e %e %e %e\n", 78.458565, 999999.999, 9.9, 9999.9, -9999.9999999));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%e %e %e %e %e\n", 78.458565, 999999.999, 9.9, 9999.9, -9999.9999999));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e :"); // double en double, long double en long double
	ft_putnbr(ft_printf("%.e %.e \n", -0.00000048787895, 0.067843775));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.e %.e \n", -0.00000048787895, 0.067843775));
	ft_putendl(" : return vrai printf");
	ft_putendl("");


printf("67.843756,   67.843755,   67.843745,   67.843754,   67.843785,   67.843758,   67.843786,   67.843786\n");
printf("%e %e %e %e %e %e %e %e \n\n", 67.843756, 67.843755, 67.843745, 67.843754, 67.843785, 67.843758, 67.843786, 67.843786);
printf("0.067843756, 0.067843755, 0.067843745, 0.067843754, 0.067843785, 0.067843756, 0.067843786, 0.067843786\n");
printf("%e %e %e %e %e %e %e %e \n\n", 0.067843756, 0.067843755, 0.067843745, 0.067843754, 0.067843785, 0.067843756, 0.067843786, 0.067843786);
printf("67.843765,  67.843775,  67.843755,   67.843745,   67.843754,   67.843785,   67.843758,   67.843786,   67.843786\n");
printf("%e %e %e %e %e %e %e %e %e \n\n", 67.843765, 67.843775, 67.843755, 67.843745, 67.843754, 67.843785, 67.843758, 67.843786, 67.843786);
printf("0.067843765, 0.067843775, 0.067843755, 0.067843745, 0.067843754, 0.067843785, 0.067843756, 0.067843786, 0.067843786\n");
printf("%e %e %e %e %e %e %e %e %e \n", 0.067843765, 0.067843775, 0.067843755, 0.067843745, 0.067843754, 0.067843785, 0.067843756, 0.067843786, 0.067843786);


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

	ft_putendl("e .15 :");
	ft_putnbr(ft_printf("%.15e %.15e %.15e %.15e %.15e\n", -0.00000048787895, 78.458565, 5.0, 1.0, 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.15e %.15e %.15e %.15e %.15e\n", -0.00000048787895, 78.458565, 5.0, 1.0, 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("e #. :");
	ft_putnbr(ft_printf("%#.E %#.E %#.E %#.E %#.E\n", -0.00000048787895, 78.458565, 5.0, 1.0, 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.E %#.E %#.E %#.E %#.E\n", -0.00000048787895, 78.458565, 5.0, 1.0, 0.0));
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

	ft_putendl("C : s");
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
	ft_putnbr(ft_printf("%g \n", -1.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%g \n", -1.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : 0");
	ft_putnbr(ft_printf("%g \n", -0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%g \n", -0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : width");
	ft_putnbr(ft_printf("%g\n", -0.0004745));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%g\n", -0.0004745));
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

	ft_putendl("g : 1.1");
	ft_putnbr(ft_printf("%g %i %s \n", 999999.99, -76, "il fait beau"));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%g %i %s \n", 999999.99, -76, "il fait beau"));
	ft_putendl(" : return vrai printf");
	ft_putendl("");
	int i1 = 0;
	scanf("%d", &i1);
*/
	ft_putendl("g : #");
	ft_putnbr(ft_printf("%.2g %.3g %g %g %g %.3g %.3g\n", -0.0004745, -45.789, -5.0, 1.0, 0.0, 0.000064300000078884389, 782456482.5662223));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%.2g %.3g %g %g %g %.3g %.3g\n", -0.0004745, -45.789, -5.0, 1.0, 0.0, 0.000064300000078884389, 782456482.5662223));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("g : precision .0");
	ft_putnbr(ft_printf("%g %.35g %.35g %.35g %g %.4g %.4g\n", 12.0785438794, 15438.7543323, 0.99999, -99.99999, -9999.9999999, 99.999944, -999.999935));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%g %.35g %.35g %.35g %g %.4g %.4g\n", 12.0785438794, 15438.7543323, 0.99999, -99.99999, -9999.9999999, 99.999944, -999.999935));
	ft_putendl(" : return vrai printf");
	ft_putendl("");
/*
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
	ft_putnbr(ft_printf("%#g %#g %#g %#g %#g\n", -0.0004745, -45.789, -5.0, 1.0, 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#g %#g %#g %#g %#g\n", -0.0004745, -45.789, -5.0, 1.0, 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	printf("%1$#g %1$#.g %1$#.0g %1$#.1g %1$#.2g %1$#.3g %1$#.4g %1$#.5g %1$#.6g %1$#.7g %1$#.8g %1$#.9g %1$#.10g\n", 0.0);
	printf("%1$g %1$.g %1$.0g %1$.1g %1$.2g %1$.3g %1$.4g %1$.5g %1$.6g %1$.7g %1$.8g %1$.9g %1$.10g\n", 0.12);
	printf("%1$g %1$.g %1$.0g %1$.1g %1$.2g %1$.3g %1$.4g %1$.5g %1$.6g %1$.7g %1$.8g %1$.9g %1$.10g\n", 0.01);
	printf("%1$g %1$.g %1$.0g %1$.1g %1$.2g %1$.3g %1$.4g %1$.5g %1$.6g %1$.7g %1$.8g %1$.9g %1$.10g\n", 0.001);
	printf("%1$g %1$.g %1$.0g %1$.1g %1$.2g %1$.3g %1$.4g %1$.5g %1$.6g %1$.7g %1$.8g %1$.9g %1$.10g\n", 0.00001);
	printf("%1$g %1$.g %1$.0g %1$.1g %1$.2g %1$.3g %1$.4g %1$.5g %1$.6g %1$.7g %1$.8g %1$.9g %1$.10g\n", 0.0000067428378945987);
	printf("%1$g %1$.g %1$.0g %1$.1g %1$.2g %1$.3g %1$.4g %1$.5g %1$.6g %1$.7g %1$.8g %1$.9g %1$.10g\n", 125839.038000038);
	printf("%1$g %1$.g %1$.0g %1$.1g %1$.2g %1$.3g %1$.4g %1$.5g %1$.6g %1$.7g %1$.8g %1$.9g %1$.10g\n", 0.0000001);
	printf("%1$g %1$.g %1$.0g %1$.1g %1$.2g %1$.3g %1$.4g %1$.5g %1$.6g %1$.7g %1$.8g %1$.9g %1$.10g\n", 0.00000001);
	printf("%1$g %1$.g %1$.0g %1$.1g %1$.2g %1$.3g %1$.4g %1$.5g %1$.6g %1$.7g %1$.8g %1$.9g %1$.10g\n", 0.000000001);
	printf("%1$g %1$.g %1$.0g %1$.1g %1$.2g %1$.3g %1$.4g %1$.5g %1$.6g %1$.7g %1$.8g %1$.9g %1$.10g\n", -0.1);
	printf("%1$g %1$.g %1$.0g %1$.1g %1$.2g %1$.3g %1$.4g %1$.5g %1$.6g %1$.7g %1$.8g %1$.9g %1$.10g\n", -0.01);
	printf("%1$g %1$.g %1$.0g %1$.1g %1$.2g %1$.3g %1$.4g %1$.5g %1$.6g %1$.7g %1$.8g %1$.9g %1$.10g\n", -0.001);
	printf("%1$g %1$.g %1$.0g %1$.1g %1$.2g %1$.3g %1$.4g %1$.5g %1$.6g %1$.7g %1$.8g %1$.9g %1$.10g\n", -0.0001);
	printf("%1$g %1$.g %1$.0g %1$.1g %1$.2g %1$.3g %1$.4g %1$.5g %1$.6g %1$.7g %1$.8g %1$.9g %1$.10g\n", -0.00001);
	printf("%1$g %1$.g %1$.0g %1$.1g %1$.2g %1$.3g %1$.4g %1$.5g %1$.6g %1$.7g %1$.8g %1$.9g %1$.10g\n", -0.000001);
	printf("%1$g %1$.g %1$.0g %1$.1g %1$.2g %1$.3g %1$.4g %1$.5g %1$.6g %1$.7g %1$.8g %1$.9g %1$.10g\n", -0.0000001);
	printf("%1$g %1$.g %1$.0g %1$.1g %1$.2g %1$.3g %1$.4g %1$.5g %1$.6g %1$.7g %1$.8g %1$.9g %1$.10g\n", -0.00000001);

//		chiffre < 1
// a partir de 5 zero apres la virgule mettre en e -> nb < 1
// . .0 et .1 = 1 chiffre apres la virgule si nb < 1, chiffre seule sans virgule si nb > 1
// si nb > 1 on met les chiffres apres la virgule jusqu'a 5 chiffres (ou jusqu'a la precision)
// la precision signifie le nb de caractere que prend le nb en entier sans les 0 derriere 
//			ex : .5 de 8.325442133 = 8.324   ou .8 de 78.563000000006524 = 78.563
// chiffres apres la virgule :
//		- si nb < 1 
//			- si le nb de 0 apres la virgule est < 4 -> 6 chiffres apres les 0 (sans precision)
//						0.0047392093 = 0.00473921
//			- si le nb de 0 apres la virgule est >= 4 -> passage en conv e et 5 chiffres apres 
//				la virgule avec les 0 inclus (sans precision) les 0 a la fin sont ignorés
//						0.000064378884389 = 6.43789e-05
//						0.000007008920073 = 7.00892e-06
//						0.000068038000038 = 6.8038e-05
//		- si nb > 1
//			- si le nb de 0 apres la virgule est >= 5 avec arrondi -> pas de chiffre apres la virgule (sans precision)
//						2.0000038540938 = 2
//						3.0000084783 = 3.00001
//			- si le nb de 0 apres la virgule est < 5 -> 5 chiffres apres la virgules avec les 0 inclus (s p)
//					et les 0 a la fin sont ignorés
//						89.003728
// le nombre ne dois pas depasser 6 chiffres ou precision en tout (en excluant les 0 devants si leur nombre est <= 4 et la virgule)
// s'il depasse 6 chiffres on passe en mode e


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

	ft_putendl("C : s");
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

	ft_putendl("a : \n%a     %.a     %.0a     %.1a     %.2a            %.12a           %.15a ");
	ft_putnbr(ft_printf("%a %.1a %.2a %.3a %.5a %.7a %.9a %.11a \n", 1.470834294502112449, 1.470834294502112449, 1.470834294502112449, 1.470834294502112449, 1.470834294502112449, 1.470834294502112449, 1.470834294502112449, 1.470834294502112449));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%a %.1a %.2a %.3a %.5a %.7a %.9a %.11a \n", 1.470834294502112449, 1.470834294502112449, 1.470834294502112449, 1.470834294502112449, 1.470834294502112449, 1.470834294502112449, 1.470834294502112449, 1.470834294502112449));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

// 0x7.88898a8b8c84 = 1.470834294502112449
// 0x7.88898a8b8c8d8e8 = 7.533348712033832939L
	ft_putendl("a : \n%a     %.a     %.0a     %.1a     %.2a            %.12a           %.15a ");
	ft_putnbr(ft_printf("%#a %#a %#.a %a %a %a %.11a \n", 0.0, 1.0, 16777215.0, -5.0, 9.99, 0.00045, 999999.9999));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#a %#a %#.a %a %a %a %.11a \n", 0.0, 1.0, 16777215.0, -5.0, 9.99, 0.00045, 999999.9999));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	ft_putendl("la : \n%la     %.la     %.0la     %.1la     %.2la            %.12la           %.15la ");
	ft_putnbr(ft_printf("%A %.A %.0A %.1A %.2A %.12A %.15A \n", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%A %.A %.0A %.1A %.2A %.12A %.15A \n", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	printf("a : %1$a %1$.a %1$.0a %1$.1a %1$.2a %1$.3a %1$.4a %1$.5a %1$.6a %1$.7a %1$.8a %1$.9a %1$.10a\n", 0.0);
	printf("la : %1$la %1$.la %1$.0la %1$.1la %1$.2la %1$.3la %1$.4la %1$.5la %1$.6la %1$.7la %1$.8la %1$.9la %1$.10la\n", 0.0);
	printf("La : %1$La %1$.La %1$.0La %1$.1La %1$.2La %1$.3La %1$.4La %1$.5La %1$.6La %1$.7La %1$.8La %1$.9La %1$.10La\n", 0.0L);
	printf("A : %1$A %1$.A %1$.0A %1$.1A %1$.2A %1$.3A %1$.4A %1$.5A %1$.6A %1$.7A %1$.8A %1$.9A %1$.10A\n", 0.0);
	printf("lA : %1$lA %1$.lA %1$.0lA %1$.1lA %1$.2lA %1$.3lA %1$.4lA %1$.5lA %1$.6lA %1$.7lA %1$.8lA %1$.9lA %1$.10lA\n", 0.0);
	printf("LA : %1$LA %1$.LA %1$.0LA %1$.1LA %1$.2LA %1$.3LA %1$.4LA %1$.5LA %1$.6LA %1$.7LA %1$.8LA %1$.9LA %1$.10LA\n\n", 0.0L);

	printf("a : %1$a %1$.a %1$.0a %1$.1a %1$.2a %1$.3a %1$.4a %1$.5a %1$.6a %1$.7a %1$.8a %1$.9a %1$.10a\n", 0.12);
	printf("la : %1$la %1$.la %1$.0la %1$.1la %1$.2la %1$.3la %1$.4la %1$.5la %1$.6la %1$.7la %1$.8la %1$.9la %1$.10la\n", 0.12);
	printf("La : %1$La %1$.La %1$.0La %1$.1La %1$.2La %1$.3La %1$.4La %1$.5La %1$.6La %1$.7La %1$.8La %1$.9La %1$.10La\n", 0.12L);
	printf("A : %1$A %1$.A %1$.0A %1$.1A %1$.2A %1$.3A %1$.4A %1$.5A %1$.6A %1$.7A %1$.8A %1$.9A %1$.10A\n", 0.12);
	printf("lA : %1$lA %1$.lA %1$.0lA %1$.1lA %1$.2lA %1$.3lA %1$.4lA %1$.5lA %1$.6lA %1$.7lA %1$.8lA %1$.9lA %1$.10lA\n", 0.12);
	printf("LA : %1$LA %1$.LA %1$.0LA %1$.1LA %1$.2LA %1$.3LA %1$.4LA %1$.5LA %1$.6LA %1$.7LA %1$.8LA %1$.9LA %1$.10LA\n\n", 0.12L);

	printf("a : %1$a %1$.a %1$.0a %1$.1a %1$.2a %1$.3a %1$.4a %1$.5a %1$.6a %1$.7a %1$.8a %1$.9a %1$.10a\n", 0.01);
	printf("la : %1$la %1$.la %1$.0la %1$.1la %1$.2la %1$.3la %1$.4la %1$.5la %1$.6la %1$.7la %1$.8la %1$.9la %1$.10la\n", 0.01);
	printf("La : %1$La %1$.La %1$.0La %1$.1La %1$.2La %1$.3La %1$.4La %1$.5La %1$.6La %1$.7La %1$.8La %1$.9La %1$.10La\n", 0.01L);
	printf("A : %1$A %1$.A %1$.0A %1$.1A %1$.2A %1$.3A %1$.4A %1$.5A %1$.6A %1$.7A %1$.8A %1$.9A %1$.10A\n", 0.01);
	printf("lA : %1$lA %1$.lA %1$.0lA %1$.1lA %1$.2lA %1$.3lA %1$.4lA %1$.5lA %1$.6lA %1$.7lA %1$.8lA %1$.9lA %1$.10lA\n", 0.01);
	printf("LA : %1$LA %1$.LA %1$.0LA %1$.1LA %1$.2LA %1$.3LA %1$.4LA %1$.5LA %1$.6LA %1$.7LA %1$.8LA %1$.9LA %1$.10LA\n\n", 0.01L);

	printf("a : %1$a %1$.a %1$.0a %1$.1a %1$.2a %1$.3a %1$.4a %1$.5a %1$.6a %1$.7a %1$.8a %1$.9a %1$.10a\n", 12.7639);
	printf("la : %1$la %1$.la %1$.0la %1$.1la %1$.2la %1$.3la %1$.4la %1$.5la %1$.6la %1$.7la %1$.8la %1$.9la %1$.10la\n", 12.7639);
	printf("La : %1$La %1$.La %1$.0La %1$.1La %1$.2La %1$.3La %1$.4La %1$.5La %1$.6La %1$.7La %1$.8La %1$.9La %1$.10La\n", 12.7639L);
	printf("A : %1$A %1$.A %1$.0A %1$.1A %1$.2A %1$.3A %1$.4A %1$.5A %1$.6A %1$.7A %1$.8A %1$.9A %1$.10A\n", 12.7639);
	printf("lA : %1$lA %1$.lA %1$.0lA %1$.1lA %1$.2lA %1$.3lA %1$.4lA %1$.5lA %1$.6lA %1$.7lA %1$.8lA %1$.9lA %1$.10lA\n", 12.7639);
	printf("LA : %1$LA %1$.LA %1$.0LA %1$.1LA %1$.2LA %1$.3LA %1$.4LA %1$.5LA %1$.6LA %1$.7LA %1$.8LA %1$.9LA %1$.10LA\n\n", 12.7639L);



	printf("u : %1$u %1$.u %1$.0u %1$.1u %1$.2u %1$.3u %1$.4u %1$.5u %1$.6u %1$.7u %1$.8u %1$.9u %1$.10u\n", 0);
	printf("lu : %1$lu %1$.lu %1$.0lu %1$.1lu %1$.2lu %1$.3lu %1$.4lu %1$.5lu %1$.6lu %1$.7lu %1$.8lu %1$.9lu %1$.10lu\n", 0);
	printf("llu : %1$llu %1$.llu %1$.0llu %1$.1llu %1$.2llu %1$.3llu %1$.4llu %1$.5llu %1$.6llu %1$.7llu %1$.8llu %1$.9llu %1$.10Lu\n", 0L);
	printf("U : %1$U %1$.U %1$.0U %1$.1U %1$.2U %1$.3U %1$.4U %1$.5U %1$.6U %1$.7U %1$.8U %1$.9U %1$.10U\n", 0);
	printf("lU : %1$lU %1$.lU %1$.0lU %1$.1lU %1$.2lU %1$.3lU %1$.4lU %1$.5lU %1$.6lU %1$.7lU %1$.8lU %1$.9lU %1$.10lU\n", 0);
	printf("llU : %1$llU %1$.llU %1$.0llU %1$.1llU %1$.2llU %1$.3llU %1$.4llU %1$.5llU %1$.6llU %1$.7llU %1$.8llU %1$.9llU %1$.10llU\n\n", 0L);

	printf("u : %1$u %1$.u %1$.0u %1$.1u %1$.2u %1$.3u %1$.4u %1$.5u %1$.6u %1$.7u %1$.8u %1$.9u %1$.10u\n", 12);
	printf("lu : %1$lu %1$.lu %1$.0lu %1$.1lu %1$.2lu %1$.3lu %1$.4lu %1$.5lu %1$.6lu %1$.7lu %1$.8lu %1$.9lu %1$.10lu\n", 12);
	printf("llu : %1$llu %1$.llu %1$.0llu %1$.1llu %1$.2llu %1$.3llu %1$.4llu %1$.5llu %1$.6llu %1$.7llu %1$.8llu %1$.9llu %1$.10llu\n", 12L);
	printf("U : %1$U %1$.U %1$.0U %1$.1U %1$.2U %1$.3U %1$.4U %1$.5U %1$.6U %1$.7U %1$.8U %1$.9U %1$.10U\n", 12);
	printf("lU : %1$lU %1$.lU %1$.0lU %1$.1lU %1$.2lU %1$.3lU %1$.4lU %1$.5lU %1$.6lU %1$.7lU %1$.8lU %1$.9lU %1$.10lU\n", 12);
	printf("llU : %1$llU %1$.llU %1$.0llU %1$.1llU %1$.2llU %1$.3llU %1$.4llU %1$.5llU %1$.6llU %1$.7llU %1$.8llU %1$.9llU %1$.10llU\n\n", 12L);

	printf("u : %1$u %1$.u %1$.0u %1$.1u %1$.2u %1$.3u %1$.4u %1$.5u %1$.6u %1$.7u %1$.8u %1$.9u %1$.10u\n", -45);
	printf("lu : %1$lu %1$.lu %1$.0lu %1$.1lu %1$.2lu %1$.3lu %1$.4lu %1$.5lu %1$.6lu %1$.7lu %1$.8lu %1$.9lu %1$.10lu\n", -45);
	printf("Lu : %1$Lu %1$.Lu %1$.0Lu %1$.1Lu %1$.2Lu %1$.3Lu %1$.4Lu %1$.5Lu %1$.6Lu %1$.7Lu %1$.8Lu %1$.9Lu %1$.10Lu\n", -45L);
	printf("U : %1$U %1$.U %1$.0U %1$.1U %1$.2U %1$.3U %1$.4U %1$.5U %1$.6U %1$.7U %1$.8U %1$.9U %1$.10U\n", -45);
	printf("lU : %1$lU %1$.lU %1$.0lU %1$.1lU %1$.2lU %1$.3lU %1$.4lU %1$.5lU %1$.6lU %1$.7lU %1$.8lU %1$.9lU %1$.10lU\n", -45);
	printf("LU : %1$LU %1$.LU %1$.0LU %1$.1LU %1$.2LU %1$.3LU %1$.4LU %1$.5LU %1$.6LU %1$.7LU %1$.8LU %1$.9LU %1$.10LU\n\n", -45L);

	printf("u : %1$u %1$.u %1$.0u %1$.1u %1$.2u %1$.3u %1$.4u %1$.5u %1$.6u %1$.7u %1$.8u %1$.9u %1$.10u\n", 127639);
	printf("lu : %1$lu %1$.lu %1$.0lu %1$.1lu %1$.2lu %1$.3lu %1$.4lu %1$.5lu %1$.6lu %1$.7lu %1$.8lu %1$.9lu %1$.10lu\n", 127639);
	printf("llu : %1$llu %1$.llu %1$.0llu %1$.1llu %1$.2llu %1$.3llu %1$.4llu %1$.5llu %1$.6llu %1$.7llu %1$.8llu %1$.9llu %1$.10llu\n", 127639);
	printf("U : %1$U %1$.U %1$.0U %1$.1U %1$.2U %1$.3U %1$.4U %1$.5U %1$.6U %1$.7U %1$.8U %1$.9U %1$.10U\n", 127639);
	printf("lU : %1$lU %1$.lU %1$.0lU %1$.1lU %1$.2lU %1$.3lU %1$.4lU %1$.5lU %1$.6lU %1$.7lU %1$.8lU %1$.9lU %1$.10lU\n", 127639);
	printf("llU : %1$llU %1$.llU %1$.0llU %1$.1llU %1$.2llU %1$.3llU %1$.4llU %1$.5llU %1$.6llU %1$.7llU %1$.8llU %1$.9llU %1$.10llU\n\n", 127639);


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
	ft_putnbr(ft_printf("%#.A %#.A \n", +0.000000000004745, -454568972136897.846852238639));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%#.A %#.A \n", +0.000000000004745, -454568972136897.846852238639));
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

//a revoir
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

	ft_putendl("ADRESS : p");
//	char *s = "la maison est bleue";
//	long long p = 45648675425;
//	int f = 456456;
	char v = 'p';
	int *j1;
	j1 = (int*)ft_memalloc(sizeof(int));
	*j1 = 15;

	ft_putendl("-----------");
	ft_putnbr(ft_printf("TEST: %d, %p\n", *j1, j1));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("TEST: %d, %p\n", *j1, j1));
	ft_putendl(" : return vrai printf");
	ft_putendl("-----------");

	ft_putendl("p :");
	ft_putnbr(ft_printf("%25p \n", &v));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%25p \n", &v));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

	t_list data;
	int ret;


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
	ft_putnbr(ft_printf("%----24p et hello %2p %12p\n", &ret, &main, NULL));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("%----24p et hello %2p %12p\n", &ret, &main, NULL));
	ft_putendl(" : return vrai printf");
	ft_putendl("");

***********************
** NB WRITE CHAR : n **
***********************

	ft_putendl("NB WRITE CHAR : n");
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

	ft_putendl("POURCENT : %");
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

	ft_putendl("MIXED");
	int ret1;

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
	ft_putnbr(ft_printf("test%-8p, %---32p, %#5.3x%#024X", &ret1, &ret1, 0x25, 0));
	ft_putendl(" : return mon printf");
	ft_putnbr(printf("test%-8p, %---32p, %#5.3x%#024X", &ret1, &ret1, 0x25, 0));
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

	double	i = -0.;
	double	a;
	int		b;

	//i = (size_t)i & 0x8000000000000000;
	a = (int)i;
	b = ~(size_t)i;
	if (i == -0.0)
		ft_putendl("=");
	if (i == -0)
		ft_putendl("===");
	printf("i = %f\n", i);
	printf("a = %f\n", a);
	printf("b = %d\n", b);



int i5 = 0;
scanf("%d", &i5);
*/
}
