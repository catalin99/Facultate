// Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BigNumber.h"
#include <gtest\gtest.h>
TEST(TestClasa, CharactersCountOk)
{
	BigNumber test;
	EXPECT_EQ(0, test.ChCount);
}
int main(int argc, char* argv[])
{
	///
	//BigNumber constr1;
	//BigNumber constr2(2526);
	//BigNumber constr3("357");
	//BigNumber constr4(constr2);
	//constr4.Set("97");
	//constr1.testData();
	//constr2.testData();
	//constr3.testData();
	//constr4.testData();
	//constr2.RealNumber();
	///operator +
	//BigNumber constr5("107377777777211");
	//cout << constr5[3]<<'\n';
	//constr5.Afisare();
	//BigNumber constr6("9088888888888888888888888881");
	//BigNumber rez = constr5 + constr6;
	///rez.testData();
	//rez.RealNumber();
	///end +
	///operator *
	//BigNumber constr7(25);
	//BigNumber constr8(5);
	//BigNumber rez = constr7 * constr8;
	//rez.RealNumber();
	//rez.testData();
	///end *
	///operators [] ()
	//BigNumber constr5("107377777777211");
	//cout << constr5[3]<<'\n';
	//constr5.Afisare();
	//BigNumber constr10 = constr5(2, 4);
	//constr10.testData();
	///end []()
	///friend ==
	//BigNumber constr15("2233");
	//BigNumber constr16("22333");
	//if (constr15 == constr16)
		//cout << "cele doua obiecte sunt identice \n";
	//else
		//cout << "diferite \n";
	///end
	///test * operator
	//BigNumber constr20("8981457621423894723894239047998324902384237490237402374203423849239048239048230948209348230423047238472304723472383242347238942384723904234237402384329472303423482304823094823048230948230948902347230482309472390472384723047230472304723047230472304723904723047320472309472304923742730427302482374823750823750184702347023472304723042735923075233042304283049238402373253205892395230402374039454534522343242342342432423423423423423342342383209411");
	//BigNumber constr21("901019190124325239523952352243223723423904823482309437204823904239483294723472309482390482304823094823094823048232349238402384092384923048239048230482309482304809484293443423894723894723847293472397423842384702834723048034823742304234923840234823094834923094823592234238523958239582302350329523057230572305723057230589582332952375923857023502375023750235385239582353242342324237409238492384233423423923859235800");
	//BigNumber rez22 = constr20 * constr21;
	//rez22.Afisare();
	///end mul
	///test - operator
	//BigNumber constr23("74553231");
	//BigNumber constr24(3446799);
	//BigNumber rez25 = constr23 - constr24;
	//rez25.Afisare();
	///end sub.
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}

