----------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------CONNECT 4--------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------

import Data.List
import Data.Ord
import Data.Maybe

----------------------------------------------------------------------------------------------------------------------------------

{--
Define how you represent your GameState
In Connect 4, it's just a list of colums of sublists rows,
and an Int for whose turn it is, player 1 == 1, player 2(AI) == -1
--}
data GameState = GameState [[Int]] Int deriving Show

{--Define what a Move is an Int for the column--}
type Move = Int

----------------------------------------------------------------------------------------------------------------------------------

{--global variables--}
width = 7
height = 6
{--replicate Data.List : replicate n x is a list of length n with x the value of every element. --}
blankBoard = GameState (replicate width $ replicate height (0::Int)) 1 

----------------------------------------------------------------------------------------------------------------------------------
 
{--
Test what moves can be made and returns list 
map applies fst to each element of the list ( filtered when b==0 on the pairs of 0..width and every element of state list )
b is the element from the gameState matrix if its 0 then it is a possible future move 
if it has a winner or its tie it returns a null list
--}
possibleMoves :: GameState -> [Move]
possibleMoves gs@(GameState state _)
    | isNothing (testWinner gs) = map fst $ filter (\(a, b) -> head b == 0) $ zip [0..width] state  
    | otherwise = []
 
----------------------------------------------------------------------------------------------------------------------------------
{--
Define makeMove which takes a GameState, and applies a Move to it,
producing the next GameState. The Move might be Nothing 
--}
makeMove :: GameState -> Maybe Move -> GameState
makeMove gs@(GameState state playerMove) Nothing = gs --no move

makeMove gs@(GameState state playerMove) (Just moveCol)
    | numNonZero == height = gs -- when the number of non zero elements on the column == height it returns the gamestate unchanged 
    | not $ elem moveCol $ possibleMoves gs = gs -- tests if the selected column is not in the posible moves list and returns the gamestate unchanged 
    | otherwise = GameState (pre ++ newCol ++ post) (-playerMove) --returns the changed gameState and make the other player play
    where
        col = state !! moveCol --the list of numbers that is the column from the matrix
        nonZeroElems = filter (/= 0) col -- filters a column so it will return the list with non zero elemnts
        numNonZero = length nonZeroElems -- counts the non zero elements from a column
        pre = take moveCol state -- the beggining of the game matrix (without the changed column)
        post = reverse $ take (width-moveCol-1) $ reverse state --the end of the game matrix (without the changed column)
        newCol = [(replicate (height-numNonZero-1) (0::Int)) ++ [playerMove] ++ nonZeroElems]
        			--puts 0's above the will-be move        --adds the playerMove --adds the non ZeroElements

---------------------------------------------------------------------------------------------------------------------------------- 

{--
Define testWinner which takes a GameState and returns the winning player
or Nothing if the game is not over. When tie return Just (Player 0) 
minMax - makes a pair with min and max from a list
	concatMap (map sum) $ map group $ transpose state - counts the +1 elements and -1 elements and returns a list of them
	(minHorz, maxHorz) the pair of min an max values for the list of horizontal lines from the matrix 
	(minVert, maxVert) the pair of min an max values for the list of vertical lines from the matrix 
	(minNESW, maxNESW) the pair of min and max values for the list of the lines on the directions NE-SW
	(minNWSE, maxNWSE) the pair of min and max values for the list of the lines on the directions NW-SE
 
	sum (map abs (concat state)) -- counts every absolute value of elements from matrxi
--}
testWinner :: GameState -> Maybe Int
testWinner (GameState state _) 
    | minHorz <= -4 = Just (-1) -- AI WINS
    | minVert <= -4 = Just (-1) -- AI WINS
    | minNWSE <= -4 = Just (-1) -- AI WINS
    | minNESW <= -4 = Just (-1) -- AI WINS
    | maxHorz >= 4 = Just 1  -- PLAYER WINS
    | maxVert >= 4 = Just 1  -- PLAYER WINS
    | maxNWSE >= 4 = Just 1  -- PLAYER WINS
    | maxNESW >= 4 = Just 1  -- PLAYER WINS
    | sum (map abs (concat state)) == width*height = Just 0 --TIE
    | otherwise = Nothing 
    where
        minMax xs = (minimum xs, maximum xs) 
        (minHorz, maxHorz) = minMax $ concatMap (map sum) $ map group $ transpose state
        (minVert, maxVert) = minMax $ concatMap (map sum) $ map group state
        (minNESW, maxNESW) = minMax $ concatMap (map sum) $ map group $ (transpose . oblique) state
        (minNWSE, maxNWSE) = minMax $ concatMap (map sum) $ map group $ (transpose . oblique . reverse) state
 
{--
oblique = transforms the list of list;  used for testing diagonal wins
eg  100    10000
    010    01000
    001    00100
xs - list of list
--}
oblique :: [[Int]] -> [[Int]]
oblique xs = obliqueHelper xs 0 $ (length $ head xs)-1
 
{--
obliqueHelper takes a list of list , a start and the lenght of the list from the list list and
returns list with the elements moved 
--}
obliqueHelper :: [[Int]] -> Int -> Int -> [[Int]]
obliqueHelper [] _ _ = []
obliqueHelper (x:xs) pre post = ((replicate pre (0::Int)) ++ x ++ (replicate post (0::Int))) : obliqueHelper xs (pre+1) (post-1)
 
----------------------------------------------------------------------------------------------------------------------------------

{--
Define eval which takes a GameState and produces an integer value of the state
from the point of view of the first player. That is, higher values mean a better
state from the first player's perspective, lower values are better for second player
In this function I just evaluate based on winning or not.
bitonic = [1,2,3...(width+1)/2 .. 3,2,1]
--}
eval :: GameState -> Int
eval gs@(GameState state _)
    | isNothing win = sum $ zipWith (*) bitonic (map sum state)
    | otherwise = (div (maxBound::Int) 2) * (fromJust win) --The fromJust function extracts the element out of a Just and throws an error if its argument is Nothing.
    where
        win = testWinner gs
        bitonicUp = [1..(div (width+1) 2)]  
        bitonicDown = reverse [1..(div width 2)]
        bitonic = bitonicUp ++ bitonicDown 

----------------------------------------------------------------------------------------------------------------------------------
--the NegaMax algorithm (variant if minimax) for calculating the next move


type NegaMaxData = (Int, Int, Int, Move, Bool)
--(depth, alpha, beta, move, failFast)
{--Calculates the best move for the game--}
negaMax :: GameState -> Int -> Maybe Move
negaMax gs depth 
    | 0 == length pms = Nothing --no possible move
    | depth <= 0 = Just (head pms) --case when depth reaches 0
    | isNothing $ testWinner gs = Just move --when there is no testWinner yet
    | otherwise = Nothing
    where
        pms = possibleMoves gs
        bestBelow = if (depth <= 0) 
                    then (head pms) 
                    else (fromJust $ negaMax gs (depth-1))
        moves = bestBelow:(delete bestBelow pms)
        initFoldVal = (depth, div (minBound::Int) 4, div (maxBound::Int) 4, head moves, False) --initialize a new NegaMaxData
        toFold = zip moves $ replicate (length moves) gs --makes a set for each move to a gamestate
        (_, _, _, move, _) = foldl negaUpdate initFoldVal toFold
 
negaUpdate :: NegaMaxData -> (Move, GameState) -> NegaMaxData
negaUpdate foldval@(_, _, _, _, True) _ = foldval --with no set move,gamestate given 
negaUpdate foldval@(depth, alpha, beta, bestMove, False) (move, gs)
    | score >= beta = (depth, alpha, beta, move, True) 
    | score > alpha = (depth, score, beta, move, False) 
    | otherwise = foldval
    where
        score = -(negaMaxAux (makeMove gs (Just move)) (-beta) (-alpha) (depth-1))
 
 
negaMaxAux :: GameState -> Int -> Int -> Int -> Int
negaMaxAux gs@(GameState _ player) _ _ 0 = player * (eval gs)
negaMaxAux gs alpha beta depth = val
    where
        pms = possibleMoves gs
        initFoldVal = (depth, alpha, beta, alpha, False)
        toFold = zip pms $ replicate (length pms) gs
        (_, _, _, val, _) = foldl negaAuxUpdate initFoldVal toFold
 
--(depth, alpha, beta, returnVal, failFast)
type NegaMaxAuxData = (Int, Int, Int, Int, Bool)
negaAuxUpdate :: NegaMaxAuxData -> (Move, GameState) -> NegaMaxAuxData
negaAuxUpdate foldval@(_, _, _, _, True) _ = foldval
negaAuxUpdate foldval@(depth, alpha, beta, returnVal, False) (move, gs)
    | score >= beta = (depth, alpha, beta, score, True)
    | score > alpha = (depth, score, beta, score, False)
    | otherwise = foldval
    where
        score = -(negaMaxAux (makeMove gs (Just move)) (-beta) (-alpha) (depth-1))

----------------------------------------------------------------------------------------------------------------------------------

{--The toString method of the game-}
printGame :: GameState -> String
printGame (GameState state 1) = (concat (intersperse ['\n'] (map ((intersperse ' ') . (map f)) (transpose state))))++"\n\nYour turn, make a move\n\n"
    where
        f a
            | a == 0 = '_' 	  --no move 
            | a == 1 = 'X'	  --player
            | otherwise = 'O' --AI

printGame (GameState state (-1)) = (concat (intersperse ['\n'] (map ((intersperse ' ') . (map f)) (transpose state))))++"\n\nAI turn, please wait\n\n"
    where
        f a
            | a == 0 = '_' 	  --no move 
            | a == 1 = 'X'	  --player
            | otherwise = 'O' --AI 

----------------------------------------------------------------------------------------------------------------------------------

play :: GameState -> IO ()
play gs@(GameState _ 1) = do
                            move <- getLine
                            let nextState = makeMove gs $ Just (read move::Int)
                            putStrLn $ printGame nextState
                            if isNothing $ testWinner nextState
                            then play nextState
                            else return ()
 
play gs@(GameState _ (-1)) = do
                                putStrLn $ printGame nextState
                                if isNothing $ testWinner nextState
                                then play nextState
                                else return ()
                                where
                                    move = negaMax gs width
                                    nextState = makeMove gs move

----------------------------------------------------------------------------------------------------------------------------------

main = do

        putStrLn (printGame blankBoard)
        play blankBoard
        putStrLn "Game Over"

----------------------------------------------------------------------------------------------------------------------------------
