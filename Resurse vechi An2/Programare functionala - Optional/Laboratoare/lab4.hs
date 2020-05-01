pare [] = []
pare (x:xs) = if (even x ) then [x]++pare(xs) else pare(xs)

impare [] = []
impare (x:xs)=if (odd x) then [x]++impare(xs) else impare(xs)

--{x^2 | x in {1..5},x<3}
--[x^2|x<-[1..5],x<3]

pare2 xs = [ x| x<-xs , even x] 

impare2 xs = [x | x<-xs , odd x]

len2 xs = sum [ 1 | x<-xs ]

divizori x = [ a | a<-[1..x], mod x a == 0 ]

prim x = if divizori x == [1,x] then True else False

--n nr prime

primN n = take n [ x | x<-[2..], prim x ]

perfectN n = take n [ x | x<-[1..], perfect x]
	where perfect x = if(sum (init (divizori x)) == x) then True else False

perfect n = [ x | x<-[1..n], perfect x ]
	where perfect x = if(sum (init (divizori x)) == x) then True else False

--fst (x,y) return first
--snd (x,y) return second
--zip :: [a]->[b]->[(a,b)]

cartezian x y = sum ([ (fst a)*(snd a)| a<- (zip x y)])
cartezian2 x y = sum ([ a * b | (a,b)<-(zip x y) ])

pozPare xs = [xs!!i | i<-[0..(length xs)-1],mod i 2==0]
pozPare2 xs = [ x | (x,p)<-zip xs [0..], even p]

--[(x,y)|x<-[1..5],y<-[7..9]]

ordonate n = [ (x,y) | x<-[1..n],y<-[1..n],x<y]
concatenare l = [x | xs<-l, x<-xs ] --concatenare lista de liste