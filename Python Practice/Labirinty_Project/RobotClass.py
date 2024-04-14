import random
class Robot:
    def __init__(self, name_file):
        self.contatore_movimento=0
        self.name_file=name_file
        self.pos_x=0
        self.pos_y=0
        self.startx=''
        self.starty=''
        self.endx=''
        self.endy=''
        self.labirinto=[]
        self.elenco_movimenti=[]
        self.spostamento=[]
        self.posizione=''
        self.input_file=open(self.name_file,'r',encoding='utf-8')
    def start_pos(self):
        (self.starty, self.startx)=self.input_file.readline().split(',')
        (self.endy, self.endx)=self.input_file.readline().split(',')
        self.pos_x=int(self.startx.strip())
        self.pos_y=int(self.starty.strip())
    def movimenti_robot(self):
        for linea in self.input_file:
            self.labirinto.append(list(linea))
        if self.labirinto[self.pos_y][self.pos_x]=="X":
            print('errata posizione di partenza')
        print(f'il robot parte da x:{self.pos_x}', f'y:{self.pos_y}')
        while self.pos_x != int(self.endx.strip()) or self.pos_y != int(self.endy.strip()):
            self.spostamento=self.analisi_spostamento(self.labirinto, self.pos_x, self.pos_y)
            if len(self.spostamento)!=0:
                self.labirinto[self.pos_y][self.pos_x]='V'
                self.pos_y=self.spostamento[0][0]
                self.pos_x=self.spostamento[0][1]
                self.elenco_movimenti.append(list((self.pos_x, self.pos_y)))
            else:
                self.labirinto[self.pos_y][self.pos_x]='V'
                self.elenco_movimenti.pop()
                self.pos_y=self.elenco_movimenti[-1][1]
                self.pos_x=self.elenco_movimenti[-1][0]
            self.contatore_movimento+=1
            self.posizione=str(self.pos_x)+str(self.pos_y)  
            print(f'Movimento numero {self.contatore_movimento}:'f'x->{self.pos_x}',f'y->{self.pos_y}')
    def movimenti(self, labirinto, pos_x, pos_y):
        movimentazione=[]
        if labirinto[pos_y][pos_x+1] == ' ':
            movimentoy, movimentox= pos_y, pos_x+1
            movimentazione.append(list((movimentoy, movimentox)))
        if labirinto[pos_y][pos_x-1] == ' ':
            movimentoy, movimentox= pos_y, pos_x-1
            movimentazione.append(list((movimentoy, movimentox)))
        if labirinto[pos_y-1][pos_x] == ' ':
            movimentoy, movimentox= pos_y-1, pos_x
            movimentazione.append(list((movimentoy, movimentox)))
        if labirinto[pos_y+1][pos_x] == ' ':
            movimentoy, movimentox= pos_y+1, pos_x
            movimentazione.append(list((movimentoy, movimentox)))
        return movimentazione
    def analisi_spostamento(self, labirinto, pos_x, pos_y):
        spostamenti=[]
        mosse=self.movimenti(labirinto, pos_x, pos_y)
        if len(mosse)>1:
            move=random.choice(mosse)
            pos_y=move[0]
            pos_x=move[1]
            spostamenti.append(list((pos_y, pos_x)))
        if len(mosse)==1:
            pos_y=mosse[0][0]
            pos_x=mosse[0][1]
            spostamenti.append(list((pos_y, pos_x)))
        if len(mosse)==0:
            spostamenti=[]
        return spostamenti
    def close_file(self):
        self.input_file.close()