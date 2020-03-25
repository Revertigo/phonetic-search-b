
#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of I with i or y or Y") {
    string text = "I should just accept";
    CHECK(find(text, "I") == string("I"));
    CHECK(find(text, "i") == string("I"));
    CHECK(find(text, "y") == string("I"));
    CHECK(find(text, "Y") == string("I"));
}

TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    string text2 = "The event was well publicized all over town";
    CHECK(find(text2, "publicized") == string("publicized"));
    CHECK(find(text2, "puplicized") == string("publicized"));
    CHECK(find(text2, "bublicized") == string("publicized"));
    CHECK(find(text2, "buplicized") == string("publicized"));
}

TEST_CASE("Test replacement of p and f") {
    string text = "My sister stopped blasting annoying songs";
    CHECK(find(text, "stopped") == string("stopped"));
    CHECK(find(text, "stoffed") == string("stopped"));
    CHECK(find(text, "stopfed") == string("stopped"));
    CHECK(find(text, "stofped") == string("stopped"));
    string text2 = "We would like to fingerprint every one of your employees";
    CHECK(find(text2, "fingerprint") == string("fingerprint"));
    CHECK(find(text2, "pingerprint") == string("fingerprint"));
    CHECK(find(text2, "pingerfrint") == string("fingerprint"));
    CHECK(find(text2, "fingerfrint") == string("fingerprint"));
}

TEST_CASE("Test replacement of b and f") {
    string text = "a rabbit hole";
    CHECK(find(text, "rabbit") == string("rabbit"));
    CHECK(find(text, "raffit") == string("rabbit"));
    CHECK(find(text, "rabfit") == string("rabbit"));
    CHECK(find(text, "rafbit") == string("rabbit"));
    string text2 = "How should we give and receive feedback";
    CHECK(find(text2, "feedback") == string("feedback"));
    CHECK(find(text2, "beedback") == string("feedback"));
    CHECK(find(text2, "feedfack") == string("feedback"));
    CHECK(find(text2, "beedfack") == string("feedback"));
}

TEST_CASE("Test replacement of g and j") {
    string text = "Maybe its time to get a bigger vocabulary";
    CHECK(find(text, "bigger") == string("bigger"));
    CHECK(find(text, "bijjer") == string("bigger"));
    CHECK(find(text, "bijger") == string("bigger"));
    CHECK(find(text, "bigjer") == string("bigger"));
    string text2 = "You should not judge people by their appearance";
    CHECK(find(text2, "judge") == string("judge"));
    CHECK(find(text2, "gudge") == string("judge"));
    CHECK(find(text2, "gudje") == string("judge"));
    CHECK(find(text2, "judje") == string("judge"));
}

TEST_CASE("Test replacement of c and k") {
    string text = "not a very accurate measurement";
    CHECK(find(text, "accurate") == string("accurate"));
    CHECK(find(text, "akkurate") == string("accurate"));
    CHECK(find(text, "akcurate") == string("accurate"));
    CHECK(find(text, "ackurate") == string("accurate"));
    string text2 = "The lottery jackpot is up to one million dollars";
    CHECK(find(text2, "jackpot") == string("jackpot"));
    CHECK(find(text2, "jakkpot") == string("jackpot"));
    CHECK(find(text2, "jaccpot") == string("jackpot"));
    CHECK(find(text2, "jakcpot") == string("jackpot"));
}

TEST_CASE("Test replacement of k and q") {
    string text = "That means you can learn it very quickly";
    CHECK(find(text, "quickly") == string("quickly"));
    CHECK(find(text, "kuickly") == string("quickly"));
    CHECK(find(text, "quicqly") == string("quickly"));
    CHECK(find(text, "kuicqly") == string("quickly"));
    string text2 = "Managers must tire of being told to get their chequebook out";
    CHECK(find(text2, "chequebook") == string("chequebook"));
    CHECK(find(text2, "chekuebook") == string("chequebook"));
    CHECK(find(text2, "chekuebooq") == string("chequebook"));
    CHECK(find(text2, "chequebooq") == string("chequebook"));
}

TEST_CASE("Test replacement of c and q") {
    string text = "I should just accept";
    CHECK(find(text, "accept") == string("accept"));
    CHECK(find(text, "aqqept") == string("accept"));
    CHECK(find(text, "aqcept") == string("accept"));
    CHECK(find(text, "acqept") == string("accept"));
    string text2 = "His technique was different to anything seen previously";
    CHECK(find(text2, "technique") == string("technique"));
    CHECK(find(text2, "teqhnique") == string("technique"));
    CHECK(find(text2, "technicue") == string("technique"));
    CHECK(find(text2, "technicue") == string("technique"));
}

TEST_CASE("Test replacement of s and z") {
    string text =  "I guess I can just say";
    CHECK(find(text, "guess") == string("guess"));
    CHECK(find(text, "guezz") == string("guess"));
    CHECK(find(text, "guezs") == string("guess"));
    CHECK(find(text, "guesz") == string("guess"));
    string text2 =  "assess his campaign"; // 16 different combinations of word 'assess'
    CHECK(find(text2, "assess") == string("assess"));//1
    CHECK(find(text2, "azzezz") == string("assess"));//2
    CHECK(find(text2, "assezz") == string("assess"));//3
    CHECK(find(text2, "azzess") == string("assess"));//4
    CHECK(find(text2, "azsess") == string("assess"));//5
    CHECK(find(text2, "aszess") == string("assess"));//6
    CHECK(find(text2, "assezs") == string("assess"));//7
    CHECK(find(text2, "assesz") == string("assess"));//8
    CHECK(find(text2, "aszesz") == string("assess"));//9
    CHECK(find(text2, "azsezs") == string("assess"));//10
    CHECK(find(text2, "aszezs") == string("assess"));//11
    CHECK(find(text2, "azsesz") == string("assess"));//12
    CHECK(find(text2, "azzezs") == string("assess"));//13
    CHECK(find(text2, "azzesz") == string("assess"));//14
    CHECK(find(text2, "aszezz") == string("assess"));//15
    CHECK(find(text2, "azsezz") == string("assess"));//16
}

TEST_CASE("Test replacement of d and t") {
    string text = "to be written in a single day";
    CHECK(find(text, "written") == string("written"));
    CHECK(find(text, "wridden") == string("written"));
    CHECK(find(text, "wridten") == string("written"));
    CHECK(find(text, "writden") == string("written"));
    string text2 = "Amazon detects first Coronavirus case in a US warehouse";
    CHECK(find(text2, "detects") == string("detects"));
    CHECK(find(text2, "tetects") == string("detects"));
    CHECK(find(text2, "tedects") == string("detects"));
    CHECK(find(text2, "tedecds") == string("detects"));
    CHECK(find(text2, "dedecds") == string("detects"));
    CHECK(find(text2, "detecds") == string("detects"));
    CHECK(find(text2, "tetecds") == string("detects"));
    CHECK(find(text2, "dedects") == string("detects"));
}

TEST_CASE("Test replacement of o and u") {
    string text = "gone too far";
    CHECK(find(text, "too") == string("too"));
    CHECK(find(text, "tuu") == string("too"));
    CHECK(find(text, "tou") == string("too"));
    CHECK(find(text, "tuo") == string("too"));
    string text2 = "xxx yyy buzzword fff";
    CHECK(find(text2, "buzzword") == string("buzzword"));
    CHECK(find(text2, "bozzword") == string("buzzword"));
    CHECK(find(text2, "bozzwurd") == string("buzzword"));
    CHECK(find(text2, "buzzwurd") == string("buzzword"));
}

TEST_CASE("Test replacement of i and y") {
    string text = "I did my part";
    CHECK(find(text, "did") == string("did"));
    CHECK(find(text, "dyd") == string("did"));
    string text2 = "I went to the winery";
    CHECK(find(text2, "winery") == string("winery"));
    CHECK(find(text2, "wynery") == string("winery"));
    CHECK(find(text2, "wineri") == string("winery"));
    CHECK(find(text2, "wyneri") == string("winery"));
}

TEST_CASE("Test replacement of s/z i/y g/j t/d in one word") {
    string text = "We went sightseeing in Paris";
    CHECK(find(text, "sightseeing") == string("sightseeing"));
    CHECK(find(text, "zightseeing") == string("sightseeing"));
    CHECK(find(text, "syghtseeing") == string("sightseeing"));
    CHECK(find(text, "sijhtseeing") == string("sightseeing"));
    CHECK(find(text, "sighdseeing") == string("sightseeing"));
    CHECK(find(text, "sightzeeing") == string("sightseeing"));
    CHECK(find(text, "sightseeyng") == string("sightseeing"));
    CHECK(find(text, "sightseeinj") == string("sightseeing"));
    CHECK(find(text, "zyjhdzeeyng") == string("sightseeing"));
    CHECK(find(text, "zyjhdzeeinj") == string("sightseeing"));
    CHECK(find(text, "zyghtseeing") == string("sightseeing"));
    CHECK(find(text, "zyjhtseeing") == string("sightseeing"));
    CHECK(find(text, "zyjhtzeeing") == string("sightseeing"));
    CHECK(find(text, "zyihtseeyng") == string("sightseeing"));
    CHECK(find(text, "zyihtseeinj") == string("sightseeing"));
    CHECK(find(text, "zyjhdzeeynj") == string("sightseeing"));
    CHECK(find(text, "sightseeing") == string("sightseeing"));
    CHECK(find(text, "zyjhdseeing") == string("sightseeing"));
    CHECK(find(text, "zyjhdseeing") == string("sightseeing"));
    CHECK(find(text, "zyjhtseeyng") == string("sightseeing"));
    CHECK(find(text, "zyjhtseeinj") == string("sightseeing"));
    CHECK(find(text, "zyjhdzeeing") == string("sightseeing"));
    CHECK(find(text, "zyjhdseeyng") == string("sightseeing"));
    CHECK(find(text, "zyjhdseeinj") == string("sightseeing"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    string text2 = "everyone needs to be taking the right steps";
    CHECK(find(text2, "eVeRyOnE") == string("everyone"));
    CHECK(find(text2, "NeEdS") == string("needs"));
    CHECK(find(text2, "To") == string("to"));
    CHECK(find(text2, "bE") == string("be"));
    CHECK(find(text2, "TaKiNg") == string("taking"));
    CHECK(find(text2, "tHe") == string("the"));
    CHECK(find(text2, "rIgHt") == string("right"));
    CHECK(find(text2, "sTePs") == string("steps"));
}

TEST_CASE("Test replacement of lower-case and upper-case and s/z i/y g/j t/d in one word") {
    string text = "We went sightseeing in Paris";
    CHECK(find(text, "Sightseeing") == string("sightseeing"));
    CHECK(find(text, "zigHtseeing") == string("sightseeing"));
    CHECK(find(text, "syghtseeinG") == string("sightseeing"));
    CHECK(find(text, "SIJHTSEEING") == string("sightseeing"));
    CHECK(find(text, "sighdsEEING") == string("sightseeing"));
    CHECK(find(text, "sightZEeing") == string("sightseeing"));
    CHECK(find(text, "SIghtseeyNG") == string("sightseeing"));
    CHECK(find(text, "SIghtSEeinJ") == string("sightseeing"));
    CHECK(find(text, "ZyjhdzeeynG") == string("sightseeing"));
    CHECK(find(text, "zyjhdzEEinj") == string("sightseeing"));
    CHECK(find(text, "zyGHtseeing") == string("sightseeing"));
    CHECK(find(text, "zyJhTseeIng") == string("sightseeing"));
    CHECK(find(text, "ZyjhtZeeing") == string("sightseeing"));
}
