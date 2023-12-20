#include <iostream>
#include <math.h>
#include <string>
#include <bitset>
#include <cmath>
#include <vector>
#include <cctype>

using namespace std;

string names[64]={"a8","b8","c8","d8","e8","f8","g8","h8","a7","b7","c7","d7","e7","f7","g7","h7","a6","b6","c6","d6","e6","f6","g6","h6","a5","b5","c5","d5","e5","f5","g5","h5","a4","b4","c4","d4","e4","f4","g4","h4","a3","b3","c3","d3","e3","f3","g3","h3","a2","b2","c2","d2","e2","f2","g2","h2","a1","b1","c1","d1","e1","f1","g1","h1"};
long pawn=0x00ff00000000ff00;
long knight=0x4200000000000042;
long bishop=0x2400000000000024;
long rook=0x8100000000000081;
long queen=0x0800000000000008;
long king=0x1000000000000010;
long white=0xffff000000000000;
long black=0x000000000000ffff;

long wdpm=0x00ff000000000000;
long bdpm=0x000000000000ff00;

long lcpm=0xfefefefefefefefe;
long rcpm=0x7f7f7f7f7f7f7f7f;
long dcpm=0x00ffffffffffffff;
long ucpm=0xffffffffffffff00;

long nclm=0xfcfcfcfcfcfcfcfc;
long ncrm=0x3f3f3f3f3f3f3f3f;
long ncdm=0x0000ffffffffffff;
long ncum=0xffffffffffff0000;

long a_file=0x0101010101010101;
long b_file=0x0202020202020202;
long c_file=0x0404040404040404;
long d_file=0x0808080808080808;
long e_file=0x1010101010101010;
long f_file=0x2020202020202020;
long g_file=0x4040404040404040;
long h_file=0x8080808080808080;

long rank_1=0xff00000000000000;
long rank_2=0x00ff000000000000;
long rank_3=0x0000ff0000000000;
long rank_4=0x000000ff00000000;
long rank_5=0x00000000ff000000;
long rank_6=0x0000000000ff0000;
long rank_7=0x000000000000ff00;
long rank_8=0x00000000000000ff;

long makemove(int start, int end, long bitboard){
  long output=bitboard-pow(2,start);
  output=output|long (pow(2,end));
  return output;
}

void printbitboard(long bitboard) {
  bitset<64> y(bitboard);

  for(int i=0; i<64; i++){
    cout << y[i];
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

void printboard(){
  bitset<64> p(pawn);
  bitset<64> n(knight);
  bitset<64> b(bishop);
  bitset<64> r(rook);
  bitset<64> q(queen);
  bitset<64> k(king);
  bitset<64> w(white);

  for(int i=0; i<64; i++){
    char out = '.';
    if(p[i]==1){
      out='p';
    }
    if(n[i]==1){
      out='n';
    }
    if(b[i]==1){
      out='b';
    }
    if(r[i]==1){
      out='r';
    }
    if(q[i]==1){
      out='q';
    }
    if(k[i]==1){
      out='k';
    }
    if(w[i]==1){
      out=toupper(out);
    } 
    cout << out << " ";
    if((i+1)%8==0){
      cout << "\n";
    }
  }
}

vector<string> get_moves(bool color){
  vector<string> moves={};
  long fullboard=black|white;
  bitset<64> full(fullboard);
  if(color){
    long pawns=pawn&white&ucpm;
    long doublepawn=pawns&wdpm;
    long leftcapture=pawns&lcpm;
    long rightcapture=pawns&rcpm;

    bitset<64> p(pawns);
    bitset<64> dp(doublepawn);
    bitset<64> lc(leftcapture);
    bitset<64> rc(rightcapture);
    bitset<64> Black(black);
    
    for(int x=0; x<64; x++){
      if(p[x]==1&&full[x-8]==0){
        moves.push_back(names[x]+names[x-8]);
        if (dp[x]==1&&full[x-16]==0){
          moves.push_back(names[x]+names[x-16]);
        } 
      }
      if(lc[x]==1&&Black[x-9]==1){
        moves.push_back(names[x]+names[x-9]);
      }
      if(rc[x]==1&&Black[x-7]==1){
        moves.push_back(names[x]+names[x-7]);
      }
      
    }
  }
  else if(not(color)){
      long pawns=pawn&black&ucpm;
      long doublepawn=pawns&bdpm;
      long leftcapture=pawns&lcpm;
      long rightcapture=pawns&rcpm;

      bitset<64> p(pawns);
      bitset<64> dp(doublepawn);
      bitset<64> lc(leftcapture);
      bitset<64> rc(rightcapture);
      bitset<64> White(white);

      for(int x=0; x<64; x++){
        if(p[x]==1&&full[x+8]==0){
          moves.push_back(names[x]+names[x+8]);
          if (dp[x]==1&&full[x+16]==0){
            moves.push_back(names[x]+names[x+16]);
          } 
        }
        if(lc[x]==1&&White[x+7]==1){
          moves.push_back(names[x]+names[x+7]);
        }
        if(rc[x]==1&&White[x+9]==1){
          moves.push_back(names[x]+names[x+9]);
        }
    }
  }
  return moves;
}


int main() {
  bool turn=true;
  while(true){
    string input;
    printboard();
    vector<string> moves= get_moves(turn);
    for(string i: moves){
      cout << i << ' ';
    }
    cout << '\n' << "input move" << '\n';
    cin >> input;
    int start=lan(input.substr(0,2));
    int end=lan(input.substr(2,2));
    cout << '\n' << start << ' ' << end << '\n';
    pawn=makemove(start, end, pawn);
    if(turn){
      white=makemove(start, end, white);
    }
    if(not(turn)){
      black=makemove(start, end, black);
    }
    turn=not(turn);
  }
}
