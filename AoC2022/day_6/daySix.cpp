////
/*
    Part 1:
        We have a string of characters. 
        We need to find the location of where we have 4 unique characters(no repeating)

    Part 2: 
        Same string of characters, same goal, but instead 14 unique characters. 

    EZPZ
*/
////
#include <vector> 
#include <iostream>
using namespace std;

bool checkNoMatch(vector<char> c)
{
    for (int i = 0; i < c.size(); i++)
    {
        if (std::count(c.begin(), c.end(), c[i]) > 1)
        {
            return false;
        }   
    }
    return true;
}

int main()
{
    vector<char> characters;
    vector<char> characters2;
    
    string input = "rdzrddbgdbbqtbqbrrznznjzjjctcbtttrvrwwsvwssjfjcjnjzzqgzgzsggfddvnnrbbwgwfwgfgpgrprgrprmmqjmqmvmlmmgjmmgqmqppqgqlqmllszsmzzwfzfqzzgcccmggvfgvvzlvzlznnjfjsscrsrprcrscsqsfqfggrrhccpnpwphwhchfhtfhttzpzwzjzqzjjqjdqqnvqnqjqbqcbqccdllbcblbjljgjbgbhhgphghjhrrvbrvbrvvfggwbwnnghgwhhpbpgphpnpgpqqzvqzqtzzngzngnjnnffgbgbvvjvqvwwqnwqnnvrnnfgfttcftcfczzpbbdlbdbhbssrggtfgfbgfgfnffqsfqfcqqqwvvqpphfpfcfrrjmjhjrjbblcbbznzwwpbwwsvvwnvvzjvzzmllrpllqffplpwlpwwlpwwmnmrrlggvssjggdjjsffbtthlhsswvwjjbtbjbsswqsshppddcjjlrlttwgtwwcnwcncmcpmpnnhndnccqscqqzqpplglvvpggcvvhnhmhqqsvvhcvvjpphbhnndpdbdndjnnmccmjmhmrrlcrrfzfnndldffstffhqffhcffhbhwhzhnhrhprhhtqtztntnptnppjdpdqdzqqpzprrqbqmqhmqqmhqqjttlrrqbqnqdnnrqqtqfqjjdfjfdjjsnspptltlgttmctcgttcthcttdpppzphpnhhvthtccbvccpplpwwfgwfffhfbbrsbbgppnhpnhhwnnnrprcpcncffrqqpjprpddjnddnccqtcthhfqfnnnlrrzhhmvvczzlbzbrzbbjpjpbbjttmwtwbtbqqtssgdsdsmsmbsmsfftltmtwwsswbwdbdwbbblgbbqpbqbmbgmbgmbbvcvbbmrrldlpdpqqnvvrzzcddjsdjjfvjvvndnvvrsvrsvrsrmsswlswlssqllfmlffmwmttjgttzgtggghrhprppbgbdgdtgddvmdvvbmmchhjppczzglzglzglzgggsmsrrsttgddmvvhddvdhvvcfcvvglvlmvmdvmdvdcdvvgfftccljllmssrvvqhvvnlnplnlglrlvrvfvrrgjjzqjjzcjcvcsvvbppgrrbdrdsrddqsspwssdlltlcttgngzglgfgzfzhfzhfhnffmsspvsscjjrbbpgbbfgbffhggzpznzmnmcmzmdzmzjzddcsscgssdnddjbdjdtdzdwwshwhfhtthjhsjjfjvvdnnmzmtmmlrlblzzmmspsnpnbnvvczvzsszrrsgsbsrrlprrzfrrjdrdbdhdvvwrvvrfvrrvwrrqlqwwqjjpwwffdvffwfbwwdrwdrddhhhjghjhvhccgbcbvblllbwlwtlldbdzbbdpbbqmmglmllvwwzmzhhfnfcnfcfddvrvhvbvzvbvhvthtrtppsccggdgpghgfhhhnwnmmwfwtffpjfppmdpdhppvwvfvvhdhzhtzhtzzplpspmpnpzpgzgqgvvqcqcqmqffzszwzfwfzzcmchhmgmppgwwvffnnvhhttvtjvjgjljmmfcmmzmvvjfjggppqmpqqswsnwwdvwdvwdwjwrrrtprpqrrsddsshgssbbpbgpbbprprzppsnsbszszccddfcftcfczffchfcfjjffjwwsbbvfvpfprpbczqdnvrqrlhsrzvlvgzbqpwgpmgftzfvtlnlqrtmpjfstmsrbfjldtmhvvqwznrcflbvmsnbzcrjvbzgvvmwlzcwggwvhnpscnwhjldzjvmtfdgvptfhjtdtwfjntzqtswqgwvnfgqhqpdvdchfqjzfhgjmdstmchppcvgpdfrqbrhrvdvzbtnnrpqsnmnljjzgzqfnzmlvbzmwzfbfszvfsqdnqfstpjglwtcdjpmdfqzfcsngbcvvjvdzlnzndcggcdtdjpwgvfzlfdqpgbgfjjfvgtwwrgtrfcpfvmzvrwrftpfdprzmcmrpnjpfrdvbmlrfzrjcdzhvwbpgmbpdnqggjdpqttgnqbtjfmrglqbvcfjwghrqtcgjddhwpntjgtghmfgvjdhbzzgmfnrrrgvdmsfbhndfcwlbbtsdcbpgfpbvnwmpwdpjlvcbcgnwjzftsfqhvwdshzltrmqpcsngfzrvfwhffrcjzlfqjqdbcntdwhfrfnrzwftqhlfjpjqpngjqjcnfnrpmmbprdtzgsvsdjpzsnzzmzdfjplfhzqrnrwggcvrrmqzwlvslwvtvhbgwmjmnzftrbfhdrzszcvmdhgfvwgwgsgqtpwgvpvfrszczmsmstwhnhtnftmmmjblpchrnrdwlnhrvqtbwqwdchfjbcldmjmjzwlcngfgfvmblgmnwtwvjmzswzmpvdjtcfgcpvvqhrfnwcczrrrhwwvfrngwmlstqcvvrqrshwdvrgtgbffvlwtvwhvlcwwqgspnfmndbsbpvdbjwdlfntwrrmtgsdtwbfmjjcjfvsvltwdjmvswwpchpdtsjmbbgcgtddcbprwznsldmwflrgcrgfflzwllrzcrgdgqgsvrqmspqzsrzvppztrhlpsnqdlhmghdcrppvbljsnrjgcwhpvmlgcnswrjjbjltwnctqbqsffbcfpclhcbrnsjlmrstpngbvcfcbjstgvzwfgcsqbwgqqblsnmfddprrqmpqgfrjbhfptrdvltcrmtrcqgcdfpjhjptzngzqdghqhpsfwlmrwgfhldzpfrbtzzgsblcfmwztjmtjzgwrpttvwfhbntvsgnfvbpfpnscdspmcvncsqltzqnwczvdbtphwrdtjcszmhbpcfnvbrbgfpnrrhvhzlrglthpldrlfscpvpvttvjtfdrqpjvnwvmscdvclbnzfvppslzgmglrvvdvpsbsfhflnjbdnpqzjzlrfgwgjvwvpthjptftlzppmnmrrpfvdhgwfzfdnnbhqpwrzvvdgtcrflwfjgbmvbgsnqzqtmsvrdlfmlbqqdnfftljbtphnpqqrgbrlzrbbhlgvjpcdbmtvzlpqhbvjpmhpdmtrmjwvzrbfrdrdfmwsfvllljdwmnqlgcnzvpphwmlmstcsljvmljcjprtgmzfssgbtjlttssfzbcqbgnjnvrwzchtwtwdtfwngdflwzjrhzdlrrqfnsztvdbzqfwfzppqrghrhzsqtwqstsfspddpjrpffhgqvspzwmlzwhtzqqldqbwlsrqhlmvhhmzjpdsrgdcvqnfpldnmblgvvssrcdnjqvcgwtwmhqdcwtsqqhbntvjnlbljlqjqglggvpqncpdzztlvhhlghtrncfcdhjtzwjqdhlntjfrzccbnmglmnzwvplclvcmnsppqjhbggbzncqlcfnzbbzdjrvcdthcqwjzjvdbjddcbjchwfgbjhwqpzbpgsdtlwlphtvhwddjdbwbpsnqhnffqptcrljcqzzhszdfpdfsgflhwwsgbfcnwrbdqflnrcwddwwmfztlbswlzhtzzcllnvbtqgjsdzmhcpnnqpdpqgdntlfwgvddgqvhqhrbvstsmzrmgwslpdjlsbgthfhgnlftbqdnzsvcrrmllcjvdlqrzbvrbrjcbpttsvwcrnlvvbnjvfgldzmtflvmzqdgbnjcgctllrldgzltwlswmfbbwjmcqpldhhdsmqpbvnjprdqnvrbjhrjzqwqfrfqwngwtwjjmzdbqmpmvqrprjhnhnrlmlgpfwwzjhlgmbzdlpshcqpnlgrqvprbspmdznzzsvhdlzwmttpdnlrlqjllqnshjllvvsrblscjcmbcqlsgpcjlmmpgwrvjnjzvzfgvgghwqfjswjbjghmzcgdpsjwhbnzmbhtzgnchpbrmnfdbfscgzldpqmvprjpvcwtwdfjblfshffwqctdphhnhngsjlrqtqprpjhwqcbmhctqbpdtpzvbbfncfrcvmbfvqmbmqjvgtdvspfqfbqnmjwhzbcpcfgbhtllbsssqntfbmsmlwhjchgcsrvsfznbmspwwszqfnwzzljfnvcwnwmgfzqfvmwwwdjd";
    
    //PART 1
    int count = 0; 
    int place = 0;
    for (char c : input)
    {
        characters.push_back(c);
        count++;
        place++;
        if (count == 4)
        {
            if(checkNoMatch(characters))
            {
                printf("The # we are looking for is %i", place);
            }
            else
            {
                characters.erase(characters.begin());
                count--;
            }
        }
    }

    //PART 2
    count = 0; 
    place = 0;
    
    for (char c : input)
    {
        characters2.push_back(c);
        count++;
        place++;
        if (count == 14)
        {
            if(checkNoMatch(characters2))
            {
                printf("The # we are looking for is %i\n", place);
            }
            else
            {
                characters2.erase(characters2.begin());
                count--;
            }
        }
    }
}