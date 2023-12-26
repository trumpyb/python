#include <iostream>
#include <math.h>
#include <string>
#include <bitset>
#include <cmath>
#include <vector>
#include <cctype>
#include <algorithm>
#include <stdlib.h>

using namespace std;


long WHITE_CASTLE_KINGSIDE=(0x6000000000000000);
long WHITE_CASTLE_QUEENSIDE=(0x0e00000000000000);
long BLACK_CASTLE_KINGSIDE=(0x0000000000000060);
long BLACK_CASTLE_QUEENSIDE=(0x000000000000000e);

long RANK_8=0x00000000000000ff;
long RANK_7=RANK_8 << 8;
long RANK_6=RANK_7 << 8;
long RANK_5=RANK_6 << 8;
long RANK_4=RANK_5 << 8;
long RANK_3=RANK_4 << 8;
long RANK_2=RANK_3 << 8;
long RANK_1=RANK_2 << 8;

long RANKS[8]={RANK_1,RANK_2,RANK_3,RANK_4,RANK_5,RANK_6,RANK_7,RANK_8};

long FILE_A=0x0101010101010101;
long FILE_B=FILE_A << 1;
long FILE_C=FILE_B << 1;
long FILE_D=FILE_C << 1;
long FILE_E=FILE_D << 1;
long FILE_F=FILE_E << 1;
long FILE_G=FILE_F << 1;
long FILE_H=FILE_G << 1;

long FILES[8]={FILE_A,FILE_B,FILE_C,FILE_D,FILE_E,FILE_F,FILE_G,FILE_H};

string names[64]={"a8","b8","c8","d8","e8","f8","g8","h8","a7","b7","c7","d7","e7","f7","g7","h7","a6","b6","c6","d6","e6","f6","g6","h6","a5","b5","c5","d5","e5","f5","g5","h5","a4","b4","c4","d4","e4","f4","g4","h4","a3","b3","c3","d3","e3","f3","g3","h3","a2","b2","c2","d2","e2","f2","g2","h2","a1","b1","c1","d1","e1","f1","g1","h1"};

/*
long A8L = (0x0000000000000001);
long B8L = (0x0000000000000102);
long C8L = (0x0000000000010204);
long D8L = (0x0000000001020408);
long E8L = (0x0000000102040810);
long F8L = (0x0000010204081020);
long G8L = (0x0001020408102040);
long H8L = (0x0102040810204080);
long H7L = (0x0204081020408000);
long H6L = (0x0408102040800000);
long H5L = (0x0810204080000000);
long H4L = (0x1020408000000000);
long H3L = (0x2040800000000000);
long H2L = (0x4080000000000000);
long H1L = (0x8000000000000000);

long H8R = (0x0000000000000080);
long G8R = (0x0000000000008040);
long F8R = (0x0000000000804020);
long E8R = (0x0000000080402010);
long D8R = (0x0000008040201008);
long C8R = (0x0000804020100804);
long B8R = (0x0080402010080402);
long A8R = (0x8040201008040201);
long A7R = (0x4020100804020100);
long A6R = (0x2010080402010000);
long A5R = (0x1008040201000000);
long A4R = (0x0804020100000000);
long A3R = (0x0402010000000000);
long A2R = (0x0201000000000000);
long A1R = (0x0100000000000000);
*/

long ROOK_PCB[64]={72340172838076926,144680345676153597,289360691352306939,578721382704613623,1157442765409226991,2314885530818453727,4629771061636907199,-9187201950435737473,72340172838141441,144680345676217602,289360691352369924,578721382704674568,1157442765409283856,2314885530818502432,4629771061636939584,-9187201950435737728,72340172854657281,144680345692602882,289360691368494084,578721382720276488,1157442765423841296,2314885530830970912,4629771061645230144,-9187201950435803008,72340177082712321,144680349887234562,289360695496279044,578721386714368008,1157442769150545936,2314885534022901792,4629771063767613504,-9187201950452514688,72341259464802561,144681423712944642,289361752209228804,578722409201797128,1157443723186933776,2314886351157207072,4629771607097753664,-9187201954730704768,72618349279904001,144956323094725122,289632270724367364,578984165983651848,1157687956502220816,2315095537539358752,4629910699613634624,-9187203049947365248,143553341945872641,215330564830528002,358885010599838724,645993902138460168,1220211685215703056,2368647251370188832,4665518383679160384,-9187483425412448128,-143832609275707135,-215607624513486334,-359157654989044732,-646257715940161528,-1220457837842395120,-2368858081646862304,-4665658569255796672,9187484529235886208};

long BISHOP_PCB[64]={-9205322385119247872,36099303471056128,141012904249856,550848566272,6480472064,1108177604608,283691315142656,72624976668147712,4620710844295151618,-9205322385119182843,36099303487963146,141017232965652,1659000848424,283693466779728,72624976676520096,145249953336262720,2310355422147510788,4620710844311799048,-9205322380790986223,36100411639206946,424704217196612,72625527495610504,145249955479592976,290499906664153120,1155177711057110024,2310355426409252880,4620711952330133792,-9205038694072573375,108724279602332802,145390965166737412,290500455356698632,580999811184992272,577588851267340304,1155178802063085600,2310639079102947392,4693335752243822976,-9060072569221905919,326598935265674242,581140276476643332,1161999073681608712,288793334762704928,577868148797087808,1227793891648880768,2455587783297826816,4911175566595588352,-8624392940535152127,1197958188344280066,2323857683139004420,144117404414255168,360293502378066048,720587009051099136,1441174018118909952,2882348036221108224,5764696068147249408,-6917353036926680575,4611756524879479810,567382630219904,1416240237150208,2833579985862656,5667164249915392,11334324221640704,22667548931719168,45053622886727936,18049651735527937};

long KING_PCB[64]={770,1797,3594,7188,14376,28752,57504,49216,197123,460039,920078,1840156,3680312,7360624,14721248,12599488,50463488,117769984,235539968,471079936,942159872,1884319744,3768639488,3225468928,12918652928,30149115904,60298231808,120596463616,241192927232,482385854464,964771708928,825720045568,3307175149568,7718173671424,15436347342848,30872694685696,61745389371392,123490778742784,246981557485568,211384331665408,846636838289408,1975852459884544,3951704919769088,7903409839538176,15806819679076352,31613639358152704,63227278716305408,54114388906344448,216739030602088448,505818229730443264,1011636459460886528,2023272918921773056,4046545837843546112,8093091675687092224,-2260560722335367168,-4593460513685372928,144959613005987840,362258295026614272,724516590053228544,1449033180106457088,2898066360212914176,5796132720425828352,-6854478632857894912,4665729213955833856};

long KNIGHT_PCB[64]={132096,329728,659712,1319424,2638848,5277696,10489856,4202496,33816580,84410376,168886289,337772578,675545156,1351090312,2685403152,1075839008,8657044482,21609056261,43234889994,86469779988,172939559976,345879119952,687463207072,275414786112,2216203387392,5531918402816,11068131838464,22136263676928,44272527353856,88545054707712,175990581010432,70506185244672,567348067172352,1416171111120896,2833441750646784,5666883501293568,11333767002587136,22667534005174272,45053588738670592,18049583422636032,145241105196122112,362539804446949376,725361088165576704,1450722176331153408,2901444352662306816,5802888705324613632,-6913025356609880064,4620693356194824192,288234782788157440,576469569871282176,1224997833292120064,2449995666584240128,4899991333168480256,-8646761407372591104,1152939783987658752,2305878468463689728,1128098930098176,2257297371824128,4796069720358912,9592139440717824,19184278881435648,38368557762871296,4679521487814656,9077567998918656};

long WHITE_PAWN_PUSH_PCB[64]={0,0,0,0,0,0,0,0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296,8589934592,17179869184,34359738368,68719476736,137438953472,274877906944,549755813888,1103806595072,2207613190144,4415226380288,8830452760576,17660905521152,35321811042304,70643622084608,141287244169216,0,0,0,0,0,0,0,0};

long BLACK_PAWN_PUSH_PCB[64]={0,0,0,0,0,0,0,0,16842752,33685504,67371008,134742016,269484032,538968064,1077936128,2155872256,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296,8589934592,17179869184,34359738368,68719476736,137438953472,274877906944,549755813888,1099511627776,2199023255552,4398046511104,8796093022208,17592186044416,35184372088832,70368744177664,140737488355328,281474976710656,562949953421312,1125899906842624,2251799813685248,4503599627370496,9007199254740992,18014398509481984,36028797018963968,72057594037927936,144115188075855872,288230376151711744,576460752303423488,1152921504606846976,2305843009213693952,4611686018427387904,long(0x8000000000000000),0,0,0,0,0,0,0,0};

long WHITE_PAWN_CAPTURE_PCB[64]={0,0,0,0,0,0,0,0,2,5,10,20,40,80,160,64,512,1280,2560,5120,10240,20480,40960,16384,131072,327680,655360,1310720,2621440,5242880,10485760,4194304,33554432,83886080,167772160,335544320,671088640,1342177280,2684354560,1073741824,8589934592,21474836480,42949672960,85899345920,171798691840,343597383680,687194767360,274877906944,2199023255552,5497558138880,10995116277760,21990232555520,43980465111040,87960930222080,175921860444160,70368744177664,0,0,0,0,0,0,0,0};

long BLACK_PAWN_CAPTURE_PCB[64]={0,0,0,0,0,0,0,0,131072,327680,655360,1310720,2621440,5242880,10485760,4194304,33554432,83886080,167772160,335544320,671088640,1342177280,2684354560,1073741824,8589934592,21474836480,42949672960,85899345920,171798691840,343597383680,687194767360,274877906944,2199023255552,5497558138880,10995116277760,21990232555520,43980465111040,87960930222080,175921860444160,70368744177664,562949953421312,1407374883553280,2814749767106560,5629499534213120,11258999068426240,22517998136852480,45035996273704960,18014398509481984,144115188075855872,360287970189639680,720575940379279360,1441151880758558720,2882303761517117440,5764607523034234880,-6917529027641081856,4611686018427387904,0,0,0,0,0,0,0,0};

vector<long> FEN_TO_BITBOARD(string fen){
  long pawn=0;
  long knight=0;
  long bishop=0;
  long rook=0;
  long queen=0;
  long king=0;
  long white=0;
  long black=0;
  long castle_mask=0x9100000000000091;
  long ep_mask=0;
  
  int rank = 0;
  int file = 0;
  
  for (char c : fen) {
      if (c == ' ') {
          break;
      } else if (c == '/') {
          ++rank;  
          file = 0; 
      } else if (isdigit(c)) {
          file += c - '0';  
      } else {
        if(tolower(c)=='p'){
          pawn |= (1ULL << (rank * 8 + file));
        }
        if(tolower(c)=='n'){
          knight |= (1ULL << (rank * 8 + file));
        }
        if(tolower(c)=='b'){
          bishop |= (1ULL << (rank * 8 + file));
        }
        if(tolower(c)=='r'){
          rook |= (1ULL << (rank * 8 + file));
        }
        if(tolower(c)=='q'){
          queen |= (1ULL << (rank * 8 + file));
        }
        if(tolower(c)=='k'){
          king |= (1ULL << (rank * 8 + file));
        }
        if(isupper(c)){
          white |= (1ULL << (rank * 8 + file));
        }
        if(islower(c)){
          black |= (1ULL << (rank * 8 + file));
        }
        ++file;
      }
  }

  return vector<long> {pawn,knight,bishop,rook,queen,king,white,black,castle_mask,ep_mask};
}

void printboard( vector<long> bitboards){
  bitset<64> p(bitboards[0]);
  bitset<64> n(bitboards[1]);
  bitset<64> b(bitboards[2]);
  bitset<64> r(bitboards[3]);
  bitset<64> q(bitboards[4]);
  bitset<64> k(bitboards[5]);
  bitset<64> w(bitboards[6]);

  string output="";

  for(int i=0; i<64; i++){
    string out = ".";
    if(p[i]==1){
      out="p";
    }
    if(n[i]==1){
      out="n";
    }
    if(b[i]==1){
      out="b";
    }
    if(r[i]==1){
      out="r";
    }
    if(q[i]==1){
      out="q";
    }
    if(k[i]==1){
      out="k";
    }
    if(w[i]==1){
      transform(out.begin(), out.end(), out.begin(), ::toupper);
    } 
    output+= out;
  }
  for(int x=0; x<8; x++){
    for(int y=0; y<8; y++){
      cout << output.substr(8*x+y,1) << " ";
    }
    cout << '\n';
  }
}

void printbitboard(long bitboard) {
  bitset<64> y(bitboard);

  for(int i=0; i<64; i++){
    cout << y[i] << ' ';
    if((i+1)%8==0){
      cout << "\n";
    }
  }

}

int lan(string move) {
  string indx="hgfedcba";
  int sqx=indx.find(move[0]);
  int sqy=move[1]-'0';
  return 63-((sqy*8)-(8-sqx));
}

int file_find(int square){
  return square%8;
}

int rank_find(int square){
  return 7-(square-file_find(square))/8;
}

long rookmoves(int square, vector<long> bitboards, bool color){

  long blockers_board = (ROOK_PCB[square]&(bitboards[6]|bitboards[7]));
  long onsquare = 1ULL << square;

  long Candidate_moves_left = 0;
  long Candidate_moves_right = 0;
  long Candidate_moves_up = 0;
  long Candidate_moves_down= 0;

  if((onsquare&(~FILE_A))!=0){
    for(int x = 1; x<8; x++){
      Candidate_moves_left |= onsquare >> x;
      if( ((Candidate_moves_left&blockers_board)!=0)||(file_find(square-x)==0)){
        break;
      }
    }
  }

  if((onsquare&(~FILE_H))!=0){
    for(int x = 1; x<8; x++){
      Candidate_moves_right |= onsquare << x;
      if( ((Candidate_moves_right&blockers_board)!=0)||(file_find(square+x)==7)){
        break;
      }
    }
  }

  if((onsquare&(~RANK_8))!=0){
    for(int x = 1; x<8; x++){
      Candidate_moves_up |= onsquare >> (8*x);
      if( ((Candidate_moves_up&blockers_board)!=0)||(rank_find(square-(8*x))==0)){
        break;
      }
    }
  }

  if((onsquare&(~RANK_1))!=0){
    for(int x = 1; x<8; x++){
      Candidate_moves_down |= onsquare << (8*x);
      if( ((Candidate_moves_down&blockers_board)!=0)||(rank_find(square+(8*x))==0)){
        break;
      }
    }
  }


  long Candidate_moves= Candidate_moves_left|Candidate_moves_right|Candidate_moves_up|Candidate_moves_down;

  if(color){
    return Candidate_moves&(~bitboards[6]);
  }
  return Candidate_moves&(~bitboards[7]);

}

long bishopmoves(int square, vector<long> bitboards, bool color){

  long blockers_board = (BISHOP_PCB[square]&(bitboards[6]|bitboards[7]));
  long onsquare = 1ULL << square;

  long Candidate_moves_NW = 0;
  long Candidate_moves_NE = 0;
  long Candidate_moves_SE = 0;
  long Candidate_moves_SW= 0;

  long NW=~(FILE_A|RANK_8);
  long NE=~(FILE_H|RANK_8);
  long SE=~(FILE_H|RANK_1);
  long SW=~(FILE_A|RANK_1);

  if((onsquare&(NW))!=0){
    for(int x = 1; x<8; x++){
      Candidate_moves_NW |= onsquare >> (9*x);
      if( ((Candidate_moves_NW&blockers_board)!=0)||(file_find(square-(x*9))==0)){
        break;
      }
    }
  }

  if((onsquare&(SW))!=0){
    for(int x = 1; x<8; x++){
      Candidate_moves_SW |= onsquare << (9*x);
      if( ((Candidate_moves_SW&blockers_board)!=0)||(file_find(square+(9*x))==7)){
        break;
      }
    }
  }

  if((onsquare&(NE))!=0){
    for(int x = 1; x<8; x++){
      Candidate_moves_NE |= onsquare >> (7*x);
      if( ((Candidate_moves_NE&blockers_board)!=0)||(rank_find(square-(7*x))==0)){
        break;
      }
    }
  }

  if((onsquare&(SE))!=0){
    for(int x = 1; x<8; x++){
      Candidate_moves_SE |= onsquare << (7*x);
      if( ((Candidate_moves_SE&blockers_board)!=0)||(rank_find(square+(7*x))==0)){
        break;
      }
    }
  }


  long Candidate_moves= Candidate_moves_NW|Candidate_moves_SW|Candidate_moves_NE|Candidate_moves_SE;

  if(color){
    return Candidate_moves&(~bitboards[6]);
  }
  return Candidate_moves&(~bitboards[7]);

}

long ATTACK_MASK(vector<long> bitboards, bool color){
  long output = 0;
  
  if(color){
    bitset<64> pawn(bitboards[0]&bitboards[6]);
    bitset<64> knight(bitboards[1]&bitboards[6]);
    bitset<64> bishop(bitboards[2]&bitboards[6]);
    bitset<64> rook(bitboards[3]&bitboards[6]);
    bitset<64> queen(bitboards[4]&bitboards[6]);
    bitset<64> king(bitboards[5]&bitboards[6]);
    for(int x=0; x<64; x++){
      if(pawn[x]==1){
        output |= WHITE_PAWN_CAPTURE_PCB[x];
      }
      if(knight[x]==1){
        output |= KNIGHT_PCB[x];
      }
      if(bishop[x]==1){
        output |= bishopmoves(x, bitboards, color);
      }
      if(rook[x]==1){
        output |= rookmoves(x, bitboards, color);
      }
      if(queen[x]==1){
        output |= bishopmoves(x, bitboards, color)|rookmoves(x, bitboards, color);
      }
      if(king[x]==1){
        output |= KING_PCB[x];
      }
    }
    return output&(~bitboards[6]);
  }else{
    bitset<64> pawn(bitboards[0]&bitboards[7]);
    bitset<64> knight(bitboards[1]&bitboards[7]);
    bitset<64> bishop(bitboards[2]&bitboards[7]);
    bitset<64> rook(bitboards[3]&bitboards[7]);
    bitset<64> queen(bitboards[4]&bitboards[7]);
    bitset<64> king(bitboards[5]&bitboards[7]);
    for(int x=0; x<64; x++){
      if(pawn[x]==1){
        output |= BLACK_PAWN_CAPTURE_PCB[x];
      }
      if(knight[x]==1){
        output |= KNIGHT_PCB[x];
      }
      if(bishop[x]==1){
        output |= bishopmoves(x, bitboards, color);
      }
      if(rook[x]==1){
        output |= rookmoves(x, bitboards, color);
      }
      if(queen[x]==1){
        output |= bishopmoves(x, bitboards, color)|rookmoves(x, bitboards, color);
      }
      if(king[x]==1){
        output |= KING_PCB[x];
      }
    }
    return output&(~bitboards[7]);
  }

  
}

vector<string> pseudolegal_moves(vector<long> bitboards, bool color){
  vector<string> output={};

  long attack_board=ATTACK_MASK(bitboards, !color);
  bitset<64> CASTLE_HAS_MOVED(bitboards[8]);

  bool a8_moved=(CASTLE_HAS_MOVED[0]==1);
  bool e8_moved=(CASTLE_HAS_MOVED[4]==1);
  bool h8_moved=(CASTLE_HAS_MOVED[7]==1);

  bool a1_moved=(CASTLE_HAS_MOVED[56]==1);
  bool e1_moved=(CASTLE_HAS_MOVED[60]==1);
  bool h1_moved=(CASTLE_HAS_MOVED[63]==1);

  
  if(color){
    bitset<64> pawn(bitboards[0]&bitboards[6]);
    bitset<64> knight(bitboards[1]&bitboards[6]);
    bitset<64> bishop(bitboards[2]&bitboards[6]);
    bitset<64> rook(bitboards[3]&bitboards[6]);
    bitset<64> queen(bitboards[4]&bitboards[6]);
    bitset<64> king(bitboards[5]&bitboards[6]);

    bitset<64> en_passant(bitboards[9]);
    for(int x=0; x<64; x++){
      if(en_passant[x]==1){
        if(file_find(x)!=0&&pawn[x+1]==1){
          output.push_back(names[x+1]+names[x-8]+"ep");
        }
        if(file_find(x)!=7&&pawn[x-1]==1){
          output.push_back(names[x-1]+names[x-8]+"ep");
        }
      }
      for(int y=0; y<64; y++){
        
        string start=names[x];
        
        if(pawn[x]==1){
          bitset<64> ppush(WHITE_PAWN_PUSH_PCB[x]&(~bitboards[7])&(~bitboards[6]));
          bitset<64> pcapt(WHITE_PAWN_CAPTURE_PCB[x]&bitboards[7]);
          
            if(ppush[y]==1){
              if(y<=7){
                output.push_back(start+names[y]+"n");
                output.push_back(start+names[y]+"b");
                output.push_back(start+names[y]+"r");
                output.push_back(start+names[y]+"q");
              }else{
                output.push_back(start+names[y]);
              }
            }
            if(pcapt[y]==1){
              if(y<=7){
                output.push_back(start+names[y]+"n");
                output.push_back(start+names[y]+"b");
                output.push_back(start+names[y]+"r");
                output.push_back(start+names[y]+"q");
              }else{
                output.push_back(start+names[y]);
              }
            }
          }
        
        if(knight[x]==1){
          bitset<64> n(KNIGHT_PCB[x]&(~bitboards[6]));
          if(n[y]==1){
            output.push_back(start+names[y]);
          }
        }

        if(bishop[x]==1){
          bitset<64> b(bishopmoves(x, bitboards, color));
          if(b[y]==1){
            output.push_back(start+names[y]);
          }
        }

        if(rook[x]==1){
          bitset<64> r(rookmoves(x, bitboards, color));
          if(r[y]==1){
            output.push_back(start+names[y]);
          }
        }

        if(queen[x]==1){
          bitset<64> q(rookmoves(x, bitboards, color)|bishopmoves(x, bitboards, color));
          if(q[y]==1){
            output.push_back(start+names[y]);
          }
        }
        
        if(king[x]==1){
          bitset<64> k(KING_PCB[x]&(~bitboards[6]));
          if(k[y]==1){
            output.push_back(start+names[y]);
          }
        }

        
      }
    }

    long kingside_attacked = WHITE_CASTLE_KINGSIDE&attack_board;
    long kingside_full= WHITE_CASTLE_KINGSIDE&(bitboards[6]|bitboards[7]);
    long queenside_attacked= WHITE_CASTLE_QUEENSIDE&attack_board;
    long queenside_full=WHITE_CASTLE_QUEENSIDE&(bitboards[6]|bitboards[7]);

    if(((kingside_full+kingside_attacked)==0)&&e1_moved&&h1_moved){
      output.push_back("e1g1");
    }
    if(((queenside_full+queenside_attacked)==0)&&e1_moved&&a1_moved){
      output.push_back("e1c1");
    }
    
  }else{
    
    bitset<64> pawn(bitboards[0]&bitboards[7]);
    bitset<64> knight(bitboards[1]&bitboards[7]);
    bitset<64> bishop(bitboards[2]&bitboards[7]);
    bitset<64> rook(bitboards[3]&bitboards[7]);
    bitset<64> queen(bitboards[4]&bitboards[7]);
    bitset<64> king(bitboards[5]&bitboards[7]);

    bitset<64> en_passant(bitboards[9]);
    
    for(int x=0; x<64; x++){
      if(en_passant[x]==1){
        if(file_find(x)!=0&&pawn[x+1]==1){
          output.push_back(names[x+1]+names[x-8]+"ep");
        }
        if(file_find(x)!=7&&pawn[x-1]==1){
          output.push_back(names[x-1]+names[x-8]+"ep");
        }
      }
      for(int y=0; y<64; y++){
        string start=names[x];
        
        if(pawn[x]==1){
          bitset<64> ppush(BLACK_PAWN_PUSH_PCB[x]&(~bitboards[7])&(~bitboards[6]));
          bitset<64> pcapt(BLACK_PAWN_CAPTURE_PCB[x]&bitboards[6]);

            if(ppush[y]==1){
              
              if(y>=56){
                output.push_back(start+names[y]+"n");
                output.push_back(start+names[y]+"b");
                output.push_back(start+names[y]+"r");
                output.push_back(start+names[y]+"q");
              }else{
                output.push_back(start+names[y]);
              }
            }
            if(pcapt[y]==1){
              if(y>=56){
                output.push_back(start+names[y]+"n");
                output.push_back(start+names[y]+"b");
                output.push_back(start+names[y]+"r");
                output.push_back(start+names[y]+"q");
              }else{
                output.push_back(start+names[y]);
              }
            }
          }
        
        if(knight[x]==1){
          bitset<64> n(KNIGHT_PCB[x]&(~bitboards[7]));
          if(n[y]==1){
            output.push_back(start+names[y]);
          }
        }

        if(bishop[x]==1){
          bitset<64> b(bishopmoves(x, bitboards, color));
          if(b[y]==1){
            output.push_back(start+names[y]);
          }
        }

        if(rook[x]==1){
          bitset<64> r(rookmoves(x, bitboards, color));
          if(r[y]==1){
            output.push_back(start+names[y]);
          }
        }

        if(queen[x]==1){
          bitset<64> q(rookmoves(x, bitboards, color)|bishopmoves(x, bitboards, color));
          if(q[y]==1){
            output.push_back(start+names[y]);
          }
        }
        
        if(king[x]==1){
          bitset<64> k(KING_PCB[x]&(~bitboards[7]));
          if(k[y]==1){
            output.push_back(start+names[y]);
          }
        }
      }
    }
    long kingside_attacked = BLACK_CASTLE_KINGSIDE&attack_board;
    long kingside_full= BLACK_CASTLE_KINGSIDE&(bitboards[6]|bitboards[7]);
    long queenside_attacked= BLACK_CASTLE_QUEENSIDE&attack_board;
    long queenside_full=BLACK_CASTLE_QUEENSIDE&(bitboards[6]|bitboards[7]);

    if(((kingside_full+kingside_attacked)==0)&&e8_moved&&h8_moved){
      output.push_back("e8g8");
    }
    if(((queenside_full+queenside_attacked)==0)&&e8_moved&&a8_moved){
      output.push_back("e8c8");
    }
  }

  return output;
}
  
vector<long> make_move(vector<long> bitboards, string move){
  
  int start=lan(move.substr(0,2));
  int end=lan(move.substr(2,2));
  
  if(move.length()==6){
    if(start<30){
      bitboards=make_move(bitboards,names[end+8]+names[end]);
    }
    if(start>30){
      bitboards=make_move(bitboards,names[end-8]+names[end]);
    }
  }

  vector<long> output={};
  
  for(long BB : bitboards){
    bitset<64> bits(BB);
    if(bits[start]==1&&bits[end]==0){
      BB-=(1ULL << start);
      BB+=(1ULL << end);
    }
    if(bits[start]==0&&bits[end]==1){
      BB-=(1ULL << end);
    }
    if(bits[start]==1&&bits[end]==1){
      BB-=(1ULL << start);
    }
    output.push_back(BB);
  }
  
  if(abs(end-start)==16&&((bitboards[0]&(1ULL << start))!=0)){
    output[9] = 1ULL << end;
  }
  if(move.length()==5){
    bitboards[0]-=1ULL << end;
    string piece = move.substr(4,1);
    if(piece=="n"){
      bitboards[1]+=1ULL<<end;
    }
    if(piece=="b"){
      bitboards[2]+=1ULL<<end;
    }
    if(piece=="r"){
      bitboards[3]+=1ULL<<end;
    }
    if(piece=="q"){
      bitboards[4]+=1ULL<<end;
    }
  }
  output[8] &= 0x9100000000000091;

  if(move=="e1g1"){
    output=make_move(output, "h1f1");
  }
  if(move=="e1c1"){
    output=make_move(output, "a1d1");
  }
  if(move=="e8g8"){
    output=make_move(output, "h8f8");
  }
  if(move=="e8c8"){
    output=make_move(output, "a8d8");
  }
  
  return output;
}

vector<string> legal_moves(vector<long> bitboards, bool color){
  vector<string> moves=pseudolegal_moves(bitboards, color);
  vector<string> output={};
  int num=7;
  if(color){
    num=6;
  }
  for(string move:moves){
    vector<long> bb=make_move(bitboards, move);
    long squares_attacked=ATTACK_MASK(bb, !color);
    if((bb[5]&bb[num]&squares_attacked)==0){
      output.push_back(move);
    }
  }
  return output;
}

int PERFT(int depth, vector<long>bitboards, bool color){
  int node=0;
  if(depth==0){
    return 1ULL;
  }
  vector<string> moves=legal_moves(bitboards, color);

  for(string move : moves){
    node += PERFT(depth-1,make_move(bitboards, move), !color);
  }
  return node;
}

int main() {
  string fen="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
  vector<string> pieces={"pawn","knight","bishop","rook","queen","king","white","black","castle_mask","ep_mask"};

  vector<long> bitboards=FEN_TO_BITBOARD(fen);
  string move="";
  bool color=false;
  if(fen.find('w')){
    color = true;
  }
  vector<string> moves=legal_moves(bitboards, color);

  for(int depth=0; depth<5; depth++){
    cout << depth << " : " << PERFT(depth, bitboards, color) << '\n';
  }
}
//Use Board
/*
string fen="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
vector<string> pieces={"pawn","knight","bishop","rook","queen","king","white","black","castle_mask","ep_mask"};

vector<long> bitboards=FEN_TO_BITBOARD(fen);
string move="";
bool color=false;
if(fen.find('w')){
  color = true;
}
while(move!="0000"){
  move="";

  vector<string> moves = legal_moves(bitboards, color);
  while (find(moves.begin(), moves.end(), move) == moves.end()) {
    printboard(bitboards);
    cout << "[ ";
    for(string m : moves){
      cout << m << " ";
    }
    cout << "]" << '\n';
    cout << "Choose a move" << endl;
    cin >> move;
    if(move=="0000"){
      break;
    }
  }
  if(move=="0000"){
    break;
  }
  bitboards=make_move(bitboards, move);
  color=!color;
}
*/
