from pygame.constants import KEYDOWN, MOUSEBUTTONDOWN, K_u, K_w, K_b, K_f
import chess
import os
import pygame as p
import random




from Blobfish import ComputerMove

game=['1.']

board=chess.Board()
fen=board.fen()
flipboard=False
comcolor=''


    


p.init()
BOARD_WIDTH = BOARD_HEIGHT = 500
MOVE_LOG_PANEL_WIDTH = 250
MOVE_LOG_PANEL_HEIGHT = BOARD_HEIGHT
Dimension = 8
Sq_Size = BOARD_HEIGHT // Dimension
Max_FPS = 15
Images = {}
screen = p.display.set_mode((BOARD_WIDTH, BOARD_HEIGHT))
playerClicks=[]
sqSelected=()

a=0

while a==0:

  p.display.set_caption('Press (w) or (b) key to start game.')
  p.display.flip()
  for event in p.event.get():
    if event.type == KEYDOWN:
      if event.key==K_w:
        comcolor='b'
        
        a=1
      if event.key==K_b:
        comcolor='w'
        flipboard=True
        a=1
      
      


pieces = ['wp', 'wR', 'wN', 'wB', 'wQ', 'wK', 'bp', 'bR', 'bN', 'bB', 'bQ', 'bK']
for piece in pieces:
    Images[piece] = p.transform.scale(p.image.load("images/" + piece + ".png"), (Sq_Size, Sq_Size))

def drawPieces(screen, board):

  b=str(board)
  if flipboard:
    b=b[::-1]
  piecesb=['P','R','N','B','Q','K','p','r','n','b','q','k','.']
  pieces = ['wp', 'wR', 'wN', 'wB', 'wQ', 'wK', 'bp', 'bR', 'bN', 'bB', 'bQ', 'bK','--']
  for file in range(Dimension):
      for rank in range(Dimension):
          piece = b.replace(' ','').replace('\n','')[rank+(8*(file))]
          piece=pieces[piecesb.index(piece)]
          if(piece != "--"):
              screen.blit(Images[piece], p.Rect(rank*Sq_Size, file*Sq_Size, Sq_Size, Sq_Size))

def drawBoard(screen):
  global colors
  colors = [(240,217,181), (181,136,99)]
  for file in range(Dimension):
      for rank in range(Dimension):
          color = colors[((file + rank) % 2)]
          p.draw.rect(screen, color, p.Rect(rank*Sq_Size, file*Sq_Size, Sq_Size, Sq_Size))


p.init()
screen = p.display.set_mode((BOARD_WIDTH, BOARD_HEIGHT))
clock = p.time.Clock()
screen.fill(p.Color("White"))


if ('w' in fen and comcolor=='w') or ('w' not in fen and comcolor!='w'):
  playmove=False
else:
  playmove=True

iswhite=False
if 'w' in fen:
  iswhite=True

drawBoard(screen)
drawPieces(screen, board)
p.display.flip()
while not(board.is_game_over()):

  
  for e in p.event.get():
    if e.type == p.QUIT:
        exit()
    if e.type == p.KEYDOWN:
      if e.key == K_u:
        game=game[:-3]
        if str(board.fen())!='rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1':
          board.pop()
          playmove=not(playmove)
        if str(board.fen())!='rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1':
          board.pop()
          playmove=not(playmove)
        drawBoard(screen)
        drawPieces(screen, board)
        p.display.set_caption('Move Undone')
        p.display.flip()
      if e.key == K_f:
        flipboard=not(flipboard)
        drawBoard(screen)
        drawPieces(screen, board)
        p.display.flip()

    if e.type == MOUSEBUTTONDOWN:
        names='abcdefgh'
        location = p.mouse.get_pos()
        file = location[0] // Sq_Size
        rank = location[1] // Sq_Size
        if flipboard:
          file=7-file
          rank=rank+1
        else:
          rank=8-rank
      
        if sqSelected == (rank, file)  or file >= 8:
          sqSelected = ()
          playerClicks = []
        else:
          sqSelected = (rank, file)
          playerClicks.append(names[file]+str(rank))
          if len(playerClicks)==1 and (board.piece_at(chess.parse_square(playerClicks[0]))==None):
            playerClicks=[]



      
    if playmove and len(playerClicks)==2:
      move=playerClicks[0]+playerClicks[1]
      print(move)
      move=chess.Move.from_uci(move)
      if move not in board.legal_moves:
        move=chess.Move.from_uci(str(move)+'q')
        if move not in board.legal_moves:
          playerClicks=[]
          break
      game.append(board.san(move))
      board.push(move)
      playmove=not(playmove)
      drawBoard(screen)
      drawPieces(screen, board)
      playerClicks=[]
      p.display.flip()
    if board.is_game_over():
      game.append(str(board.outcome))
      break

    if len(game)/3==int(len(game)/3):
      game.append(str(int(len(game)/3)+1)+'.')
  
    if not(playmove):
      p.display.set_caption('Computer Move')
      p.display.flip()
      move=board.san(ComputerMove(board))
      game.append(move)
      board.push_san(move)
      playmove=not(playmove)
      drawBoard(screen)
      drawPieces(screen, board)
      p.display.set_caption('Computer Plays: '+str(move)+'.  Your Move')
      p.display.flip()
      playerClicks=[]
    if board.is_game_over():
      break

    if len(game)/3==int(len(game)/3):
      game.append(str(int(len(game)/3)+1)+'.')
os.system('clear')

open('games.txt','a').write('Computer plays as: '+comcolor+' '+' '.join(game)+'\n')
