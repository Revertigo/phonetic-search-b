#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

/*
This test written by python script that makes all the test by checking 
all scenarios. I wrote the script. 
This test file test this scenarios:
* replacement of lower letters and another lower letters
    (All scenarios, checks all options)
* replacement of high letters and another high letters
    (All scenarios, checks all options)

* Mix test- replacement of high/lower letter by another high/lower letter.
    (All scenarios, checks all options)

* words that cannot be changed. (Like 'be')

* same words. check this scenarios: find(text,originalWord) == originalWord

* Empty words

* Words that appear twice

*/

TEST_CASE("Test replacement of lower letters and another lower letters"){ 

	 string text = "hello world";
	 CHECK(find(text, "hellu") == string("hello"));
	 CHECK(find(text, "hello") == string("hello"));
	 CHECK(find(text, "vurlt") == string("world"));
	 CHECK(find(text, "vurld") == string("world"));
	 CHECK(find(text, "vorlt") == string("world"));
	 CHECK(find(text, "vorld") == string("world"));
	 CHECK(find(text, "wurlt") == string("world"));
	 CHECK(find(text, "wurld") == string("world"));
	 CHECK(find(text, "worlt") == string("world"));
	 CHECK(find(text, "world") == string("world"));
	 text = "vw bfp gj ckq sz dt ou iy";
	 CHECK(find(text, "wv") == string("vw"));
	 CHECK(find(text, "ww") == string("vw"));
	 CHECK(find(text, "vv") == string("vw"));
	 CHECK(find(text, "vw") == string("vw"));
	 CHECK(find(text, "fbb") == string("bfp"));
	 CHECK(find(text, "fbp") == string("bfp"));
	 CHECK(find(text, "fbf") == string("bfp"));
	 CHECK(find(text, "ffb") == string("bfp"));
	 CHECK(find(text, "ffp") == string("bfp"));
	 CHECK(find(text, "fff") == string("bfp"));
	 CHECK(find(text, "fpb") == string("bfp"));
	 CHECK(find(text, "fpp") == string("bfp"));
	 CHECK(find(text, "fpf") == string("bfp"));
	 CHECK(find(text, "bbb") == string("bfp"));
	 CHECK(find(text, "bbp") == string("bfp"));
	 CHECK(find(text, "bbf") == string("bfp"));
	 CHECK(find(text, "bfb") == string("bfp"));
	 CHECK(find(text, "bfp") == string("bfp"));
	 CHECK(find(text, "bff") == string("bfp"));
	 CHECK(find(text, "bpb") == string("bfp"));
	 CHECK(find(text, "bpp") == string("bfp"));
	 CHECK(find(text, "bpf") == string("bfp"));
	 CHECK(find(text, "pbb") == string("bfp"));
	 CHECK(find(text, "pbp") == string("bfp"));
	 CHECK(find(text, "pbf") == string("bfp"));
	 CHECK(find(text, "pfb") == string("bfp"));
	 CHECK(find(text, "pfp") == string("bfp"));
	 CHECK(find(text, "pff") == string("bfp"));
	 CHECK(find(text, "ppb") == string("bfp"));
	 CHECK(find(text, "ppp") == string("bfp"));
	 CHECK(find(text, "ppf") == string("bfp"));
	 CHECK(find(text, "jg") == string("gj"));
	 CHECK(find(text, "jj") == string("gj"));
	 CHECK(find(text, "gg") == string("gj"));
	 CHECK(find(text, "gj") == string("gj"));
	 CHECK(find(text, "kcc") == string("ckq"));
	 CHECK(find(text, "kcq") == string("ckq"));
	 CHECK(find(text, "kck") == string("ckq"));
	 CHECK(find(text, "kkc") == string("ckq"));
	 CHECK(find(text, "kkq") == string("ckq"));
	 CHECK(find(text, "kkk") == string("ckq"));
	 CHECK(find(text, "kqc") == string("ckq"));
	 CHECK(find(text, "kqq") == string("ckq"));
	 CHECK(find(text, "kqk") == string("ckq"));
	 CHECK(find(text, "ccc") == string("ckq"));
	 CHECK(find(text, "ccq") == string("ckq"));
	 CHECK(find(text, "cck") == string("ckq"));
	 CHECK(find(text, "ckc") == string("ckq"));
	 CHECK(find(text, "ckq") == string("ckq"));
	 CHECK(find(text, "ckk") == string("ckq"));
	 CHECK(find(text, "cqc") == string("ckq"));
	 CHECK(find(text, "cqq") == string("ckq"));
	 CHECK(find(text, "cqk") == string("ckq"));
	 CHECK(find(text, "qcc") == string("ckq"));
	 CHECK(find(text, "qcq") == string("ckq"));
	 CHECK(find(text, "qck") == string("ckq"));
	 CHECK(find(text, "qkc") == string("ckq"));
	 CHECK(find(text, "qkq") == string("ckq"));
	 CHECK(find(text, "qkk") == string("ckq"));
	 CHECK(find(text, "qqc") == string("ckq"));
	 CHECK(find(text, "qqq") == string("ckq"));
	 CHECK(find(text, "qqk") == string("ckq"));
	 CHECK(find(text, "zs") == string("sz"));
	 CHECK(find(text, "zz") == string("sz"));
	 CHECK(find(text, "ss") == string("sz"));
	 CHECK(find(text, "sz") == string("sz"));
	 CHECK(find(text, "td") == string("dt"));
	 CHECK(find(text, "tt") == string("dt"));
	 CHECK(find(text, "dd") == string("dt"));
	 CHECK(find(text, "dt") == string("dt"));
	 CHECK(find(text, "uo") == string("ou"));
	 CHECK(find(text, "uu") == string("ou"));
	 CHECK(find(text, "oo") == string("ou"));
	 CHECK(find(text, "ou") == string("ou"));
	 CHECK(find(text, "yi") == string("iy"));
	 CHECK(find(text, "yy") == string("iy"));
	 CHECK(find(text, "ii") == string("iy"));
	 CHECK(find(text, "iy") == string("iy"));
} 

TEST_CASE("Test replacement of a high letters"){ 
	 string text = "AriEL";
	 CHECK(find(text, "ARIEL") == string("AriEL"));
	 CHECK(find(text, "ARiEL") == string("AriEL"));
	 CHECK(find(text, "ArIEL") == string("AriEL"));
	 CHECK(find(text, "AriEL") == string("AriEL"));
	 text = "Vw BFP gJ CkQ SZ dt oU IY";
	 CHECK(find(text, "VW") == string("Vw"));
	 CHECK(find(text, "Vw") == string("Vw"));
	 CHECK(find(text, "BFP") == string("BFP"));
	 CHECK(find(text, "GJ") == string("gJ"));
	 CHECK(find(text, "gJ") == string("gJ"));
	 CHECK(find(text, "CKQ") == string("CkQ"));
	 CHECK(find(text, "CkQ") == string("CkQ"));
	 CHECK(find(text, "SZ") == string("SZ"));
	 CHECK(find(text, "DT") == string("dt"));
	 CHECK(find(text, "Dt") == string("dt"));
	 CHECK(find(text, "dT") == string("dt"));
	 CHECK(find(text, "dt") == string("dt"));
	 CHECK(find(text, "OU") == string("oU"));
	 CHECK(find(text, "oU") == string("oU"));
	 CHECK(find(text, "IY") == string("IY"));
} 

TEST_CASE("Test mix- replacement of a lower/high letters"){ 
	 string text = "Vw BfP";
	 CHECK(find(text, "wv") == string("vw"));
	 CHECK(find(text, "WV") == string("vw"));
	 CHECK(find(text, "Wv") == string("vw"));
	 CHECK(find(text, "wV") == string("vw"));
	 CHECK(find(text, "ww") == string("vw"));
	 CHECK(find(text, "WW") == string("vw"));
	 CHECK(find(text, "Ww") == string("vw"));
	 CHECK(find(text, "wW") == string("vw"));
	 CHECK(find(text, "vv") == string("vw"));
	 CHECK(find(text, "VV") == string("vw"));
	 CHECK(find(text, "Vv") == string("vw"));
	 CHECK(find(text, "vV") == string("vw"));
	 CHECK(find(text, "vw") == string("vw"));
	 CHECK(find(text, "VW") == string("vw"));
	 CHECK(find(text, "Vw") == string("vw"));
	 CHECK(find(text, "vW") == string("vw"));
	 CHECK(find(text, "fbb") == string("bfp"));
	 CHECK(find(text, "FBB") == string("bfp"));
	 CHECK(find(text, "FBb") == string("bfp"));
	 CHECK(find(text, "FbB") == string("bfp"));
	 CHECK(find(text, "Fbb") == string("bfp"));
	 CHECK(find(text, "fBB") == string("bfp"));
	 CHECK(find(text, "fBb") == string("bfp"));
	 CHECK(find(text, "fbB") == string("bfp"));
	 CHECK(find(text, "fbp") == string("bfp"));
	 CHECK(find(text, "FBP") == string("bfp"));
	 CHECK(find(text, "FBp") == string("bfp"));
	 CHECK(find(text, "FbP") == string("bfp"));
	 CHECK(find(text, "Fbp") == string("bfp"));
	 CHECK(find(text, "fBP") == string("bfp"));
	 CHECK(find(text, "fBp") == string("bfp"));
	 CHECK(find(text, "fbP") == string("bfp"));
	 CHECK(find(text, "fbf") == string("bfp"));
	 CHECK(find(text, "FBF") == string("bfp"));
	 CHECK(find(text, "FBf") == string("bfp"));
	 CHECK(find(text, "FbF") == string("bfp"));
	 CHECK(find(text, "Fbf") == string("bfp"));
	 CHECK(find(text, "fBF") == string("bfp"));
	 CHECK(find(text, "fBf") == string("bfp"));
	 CHECK(find(text, "fbF") == string("bfp"));
	 CHECK(find(text, "ffb") == string("bfp"));
	 CHECK(find(text, "FFB") == string("bfp"));
	 CHECK(find(text, "FFb") == string("bfp"));
	 CHECK(find(text, "FfB") == string("bfp"));
	 CHECK(find(text, "Ffb") == string("bfp"));
	 CHECK(find(text, "fFB") == string("bfp"));
	 CHECK(find(text, "fFb") == string("bfp"));
	 CHECK(find(text, "ffB") == string("bfp"));
	 CHECK(find(text, "ffp") == string("bfp"));
	 CHECK(find(text, "FFP") == string("bfp"));
	 CHECK(find(text, "FFp") == string("bfp"));
	 CHECK(find(text, "FfP") == string("bfp"));
	 CHECK(find(text, "Ffp") == string("bfp"));
	 CHECK(find(text, "fFP") == string("bfp"));
	 CHECK(find(text, "fFp") == string("bfp"));
	 CHECK(find(text, "ffP") == string("bfp"));
	 CHECK(find(text, "fff") == string("bfp"));
	 CHECK(find(text, "FFF") == string("bfp"));
	 CHECK(find(text, "FFf") == string("bfp"));
	 CHECK(find(text, "FfF") == string("bfp"));
	 CHECK(find(text, "Fff") == string("bfp"));
	 CHECK(find(text, "fFF") == string("bfp"));
	 CHECK(find(text, "fFf") == string("bfp"));
	 CHECK(find(text, "ffF") == string("bfp"));
	 CHECK(find(text, "fpb") == string("bfp"));
	 CHECK(find(text, "FPB") == string("bfp"));
	 CHECK(find(text, "FPb") == string("bfp"));
	 CHECK(find(text, "FpB") == string("bfp"));
	 CHECK(find(text, "Fpb") == string("bfp"));
	 CHECK(find(text, "fPB") == string("bfp"));
	 CHECK(find(text, "fPb") == string("bfp"));
	 CHECK(find(text, "fpB") == string("bfp"));
	 CHECK(find(text, "fpp") == string("bfp"));
	 CHECK(find(text, "FPP") == string("bfp"));
	 CHECK(find(text, "FPp") == string("bfp"));
	 CHECK(find(text, "FpP") == string("bfp"));
	 CHECK(find(text, "Fpp") == string("bfp"));
	 CHECK(find(text, "fPP") == string("bfp"));
	 CHECK(find(text, "fPp") == string("bfp"));
	 CHECK(find(text, "fpP") == string("bfp"));
	 CHECK(find(text, "fpf") == string("bfp"));
	 CHECK(find(text, "FPF") == string("bfp"));
	 CHECK(find(text, "FPf") == string("bfp"));
	 CHECK(find(text, "FpF") == string("bfp"));
	 CHECK(find(text, "Fpf") == string("bfp"));
	 CHECK(find(text, "fPF") == string("bfp"));
	 CHECK(find(text, "fPf") == string("bfp"));
	 CHECK(find(text, "fpF") == string("bfp"));
	 CHECK(find(text, "bbb") == string("bfp"));
	 CHECK(find(text, "BBB") == string("bfp"));
	 CHECK(find(text, "BBb") == string("bfp"));
	 CHECK(find(text, "BbB") == string("bfp"));
	 CHECK(find(text, "Bbb") == string("bfp"));
	 CHECK(find(text, "bBB") == string("bfp"));
	 CHECK(find(text, "bBb") == string("bfp"));
	 CHECK(find(text, "bbB") == string("bfp"));
	 CHECK(find(text, "bbp") == string("bfp"));
	 CHECK(find(text, "BBP") == string("bfp"));
	 CHECK(find(text, "BBp") == string("bfp"));
	 CHECK(find(text, "BbP") == string("bfp"));
	 CHECK(find(text, "Bbp") == string("bfp"));
	 CHECK(find(text, "bBP") == string("bfp"));
	 CHECK(find(text, "bBp") == string("bfp"));
	 CHECK(find(text, "bbP") == string("bfp"));
	 CHECK(find(text, "bbf") == string("bfp"));
	 CHECK(find(text, "BBF") == string("bfp"));
	 CHECK(find(text, "BBf") == string("bfp"));
	 CHECK(find(text, "BbF") == string("bfp"));
	 CHECK(find(text, "Bbf") == string("bfp"));
	 CHECK(find(text, "bBF") == string("bfp"));
	 CHECK(find(text, "bBf") == string("bfp"));
	 CHECK(find(text, "bbF") == string("bfp"));
	 CHECK(find(text, "bfb") == string("bfp"));
	 CHECK(find(text, "BFB") == string("bfp"));
	 CHECK(find(text, "BFb") == string("bfp"));
	 CHECK(find(text, "BfB") == string("bfp"));
	 CHECK(find(text, "Bfb") == string("bfp"));
	 CHECK(find(text, "bFB") == string("bfp"));
	 CHECK(find(text, "bFb") == string("bfp"));
	 CHECK(find(text, "bfB") == string("bfp"));
	 CHECK(find(text, "bfp") == string("bfp"));
	 CHECK(find(text, "BFP") == string("bfp"));
	 CHECK(find(text, "BFp") == string("bfp"));
	 CHECK(find(text, "BfP") == string("bfp"));
	 CHECK(find(text, "Bfp") == string("bfp"));
	 CHECK(find(text, "bFP") == string("bfp"));
	 CHECK(find(text, "bFp") == string("bfp"));
	 CHECK(find(text, "bfP") == string("bfp"));
	 CHECK(find(text, "bff") == string("bfp"));
	 CHECK(find(text, "BFF") == string("bfp"));
	 CHECK(find(text, "BFf") == string("bfp"));
	 CHECK(find(text, "BfF") == string("bfp"));
	 CHECK(find(text, "Bff") == string("bfp"));
	 CHECK(find(text, "bFF") == string("bfp"));
	 CHECK(find(text, "bFf") == string("bfp"));
	 CHECK(find(text, "bfF") == string("bfp"));
	 CHECK(find(text, "bpb") == string("bfp"));
	 CHECK(find(text, "BPB") == string("bfp"));
	 CHECK(find(text, "BPb") == string("bfp"));
	 CHECK(find(text, "BpB") == string("bfp"));
	 CHECK(find(text, "Bpb") == string("bfp"));
	 CHECK(find(text, "bPB") == string("bfp"));
	 CHECK(find(text, "bPb") == string("bfp"));
	 CHECK(find(text, "bpB") == string("bfp"));
	 CHECK(find(text, "bpp") == string("bfp"));
	 CHECK(find(text, "BPP") == string("bfp"));
	 CHECK(find(text, "BPp") == string("bfp"));
	 CHECK(find(text, "BpP") == string("bfp"));
	 CHECK(find(text, "Bpp") == string("bfp"));
	 CHECK(find(text, "bPP") == string("bfp"));
	 CHECK(find(text, "bPp") == string("bfp"));
	 CHECK(find(text, "bpP") == string("bfp"));
	 CHECK(find(text, "bpf") == string("bfp"));
	 CHECK(find(text, "BPF") == string("bfp"));
	 CHECK(find(text, "BPf") == string("bfp"));
	 CHECK(find(text, "BpF") == string("bfp"));
	 CHECK(find(text, "Bpf") == string("bfp"));
	 CHECK(find(text, "bPF") == string("bfp"));
	 CHECK(find(text, "bPf") == string("bfp"));
	 CHECK(find(text, "bpF") == string("bfp"));
	 CHECK(find(text, "pbb") == string("bfp"));
	 CHECK(find(text, "PBB") == string("bfp"));
	 CHECK(find(text, "PBb") == string("bfp"));
	 CHECK(find(text, "PbB") == string("bfp"));
	 CHECK(find(text, "Pbb") == string("bfp"));
	 CHECK(find(text, "pBB") == string("bfp"));
	 CHECK(find(text, "pBb") == string("bfp"));
	 CHECK(find(text, "pbB") == string("bfp"));
	 CHECK(find(text, "pbp") == string("bfp"));
	 CHECK(find(text, "PBP") == string("bfp"));
	 CHECK(find(text, "PBp") == string("bfp"));
	 CHECK(find(text, "PbP") == string("bfp"));
	 CHECK(find(text, "Pbp") == string("bfp"));
	 CHECK(find(text, "pBP") == string("bfp"));
	 CHECK(find(text, "pBp") == string("bfp"));
	 CHECK(find(text, "pbP") == string("bfp"));
	 CHECK(find(text, "pbf") == string("bfp"));
	 CHECK(find(text, "PBF") == string("bfp"));
	 CHECK(find(text, "PBf") == string("bfp"));
	 CHECK(find(text, "PbF") == string("bfp"));
	 CHECK(find(text, "Pbf") == string("bfp"));
	 CHECK(find(text, "pBF") == string("bfp"));
	 CHECK(find(text, "pBf") == string("bfp"));
	 CHECK(find(text, "pbF") == string("bfp"));
	 CHECK(find(text, "pfb") == string("bfp"));
	 CHECK(find(text, "PFB") == string("bfp"));
	 CHECK(find(text, "PFb") == string("bfp"));
	 CHECK(find(text, "PfB") == string("bfp"));
	 CHECK(find(text, "Pfb") == string("bfp"));
	 CHECK(find(text, "pFB") == string("bfp"));
	 CHECK(find(text, "pFb") == string("bfp"));
	 CHECK(find(text, "pfB") == string("bfp"));
	 CHECK(find(text, "pfp") == string("bfp"));
	 CHECK(find(text, "PFP") == string("bfp"));
	 CHECK(find(text, "PFp") == string("bfp"));
	 CHECK(find(text, "PfP") == string("bfp"));
	 CHECK(find(text, "Pfp") == string("bfp"));
	 CHECK(find(text, "pFP") == string("bfp"));
	 CHECK(find(text, "pFp") == string("bfp"));
	 CHECK(find(text, "pfP") == string("bfp"));
	 CHECK(find(text, "pff") == string("bfp"));
	 CHECK(find(text, "PFF") == string("bfp"));
	 CHECK(find(text, "PFf") == string("bfp"));
	 CHECK(find(text, "PfF") == string("bfp"));
	 CHECK(find(text, "Pff") == string("bfp"));
	 CHECK(find(text, "pFF") == string("bfp"));
	 CHECK(find(text, "pFf") == string("bfp"));
	 CHECK(find(text, "pfF") == string("bfp"));
	 CHECK(find(text, "ppb") == string("bfp"));
	 CHECK(find(text, "PPB") == string("bfp"));
	 CHECK(find(text, "PPb") == string("bfp"));
	 CHECK(find(text, "PpB") == string("bfp"));
	 CHECK(find(text, "Ppb") == string("bfp"));
	 CHECK(find(text, "pPB") == string("bfp"));
	 CHECK(find(text, "pPb") == string("bfp"));
	 CHECK(find(text, "ppB") == string("bfp"));
	 CHECK(find(text, "ppp") == string("bfp"));
	 CHECK(find(text, "PPP") == string("bfp"));
	 CHECK(find(text, "PPp") == string("bfp"));
	 CHECK(find(text, "PpP") == string("bfp"));
	 CHECK(find(text, "Ppp") == string("bfp"));
	 CHECK(find(text, "pPP") == string("bfp"));
	 CHECK(find(text, "pPp") == string("bfp"));
	 CHECK(find(text, "ppP") == string("bfp"));
	 CHECK(find(text, "ppf") == string("bfp"));
	 CHECK(find(text, "PPF") == string("bfp"));
	 CHECK(find(text, "PPf") == string("bfp"));
	 CHECK(find(text, "PpF") == string("bfp"));
	 CHECK(find(text, "Ppf") == string("bfp"));
	 CHECK(find(text, "pPF") == string("bfp"));
	 CHECK(find(text, "pPf") == string("bfp"));
	 CHECK(find(text, "ppF") == string("bfp"));
} 

TEST_CASE("Test words that cannot be changed"){ 
	 string text = "Be bee";
	 CHECK(find(text, "Be") == string("Be"));
	 CHECK(find(text, "bee") == string("bee"));
} 

TEST_CASE("Test same words"){ 
	 string text = "CaT dOg";
	 CHECK(find(text, "CaT") == string("CaT"));
	 CHECK(find(text, "dOg") == string("dOg"));
} 

TEST_CASE("appear twice")
{
    string text = "dond dont";

    CHECK(find(text, "dont") == string("dond"));
    CHECK(find(text, "dond") == string("dond"));

}

TEST_CASE("Test word that do not exist in the text"){ 
	 string text = "Vw BfP";
	 CHECK_THROWS_AS(find(text, "AAA"),  std::exception);
	 CHECK_THROWS_AS(find(text, "abbas"),  std::exception);
	 CHECK_THROWS_AS(find(text, "AAA"),  std::exception);
	 CHECK_THROWS_AS(find(text, "abbey"),  std::exception);
	 CHECK_THROWS_AS(find(text, "abbas"),  std::exception);
	 CHECK_THROWS_AS(find(text, "AAAS"),  std::exception);
	 CHECK_THROWS_AS(find(text, "abash"),  std::exception);
	 CHECK_THROWS_AS(find(text, "abbreviate"),  std::exception);
	 CHECK_THROWS_AS(find(text, "abate"),  std::exception);
	 CHECK_THROWS_AS(find(text, "Aaron"),  std::exception);
	 CHECK_THROWS_AS(find(text, "abbreviate"),  std::exception);
	 CHECK_THROWS_AS(find(text, "AAA"),  std::exception);
	 CHECK_THROWS_AS(find(text, "abbot"),  std::exception);
	 CHECK_THROWS_AS(find(text, "abate"),  std::exception);
	 CHECK_THROWS_AS(find(text, "abalone"),  std::exception);
	 CHECK_THROWS_AS(find(text, "ABA"),  std::exception);
	 CHECK_THROWS_AS(find(text, "abalone"),  std::exception);
	 CHECK_THROWS_AS(find(text, "abacus"),  std::exception);
	 CHECK_THROWS_AS(find(text, "Aarhus"),  std::exception);
	 CHECK_THROWS_AS(find(text, "Aarhus"),  std::exception);
} 

TEST_CASE("Test empty word")
{
    string text = " ";
    string text2 = "        ";
    string text3 = "";
    string anyWord = "anyWord";

    CHECK_THROWS_AS(find(text, anyWord), std::exception);
    CHECK_THROWS_AS(find(text2, anyWord), std::exception);
    CHECK_THROWS_AS(find(text3, anyWord), std::exception);
}


