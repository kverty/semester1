import Prelude hiding (id, log)
import Data.List
import Control.Monad
import Data.Maybe

data Edge = Edge {
    weight :: Int,
    idTo :: Int,
    idFrom :: Int
}

instance Show Edge where
    show (Edge _ idTo idFrom) = show idFrom ++ "->" ++ show idTo

data Label = Label {
    dist :: Int,
    path :: [Edge]
} deriving Show

instance Ord Label where
    compare (Label dist1 es1) (Label dist2 es2) = compare dist2 dist1

instance Eq Label where
    (==) a b = dist a == dist b

data Vertex = Vertex {
    id :: Int, 
    label :: Maybe Label
} deriving Show

instance Eq Vertex where
    (==) a b = id a == id b

instance Ord Vertex where
    compare (Vertex _ Nothing) (Vertex _ Nothing) = EQ
    compare (Vertex _ (Just label)) (Vertex _ Nothing) = LT
    compare (Vertex _ Nothing) (Vertex _ (Just label)) = GT
    compare (Vertex _ (Just label1)) (Vertex _ (Just label2)) = compare label2 label1

data Graph = Graph [Vertex] [Edge]
            deriving Show

toNormalForm :: [Vertex] -> [(Int, Int, Maybe [Edge])]
toNormalForm [] = []
toNormalForm ((Vertex id Nothing) : vs) = (id, -1, Nothing) : (toNormalForm vs)
toNormalForm ((Vertex id (Just (Label dist es))) : vs) = (id, dist, Just es) : (toNormalForm vs)

sumMaybe :: Maybe Label -> Maybe Label -> Maybe Label
sumMaybe (Just _) Nothing = Nothing
sumMaybe Nothing Nothing = Nothing
sumMaybe Nothing (Just _) = Nothing
sumMaybe (Just (Label dist1 es1)) (Just (Label dist2 es2)) = Just (Label (dist1 + dist2) (es1 ++ es2))

findEdge :: Int -> Int -> [Edge] -> Maybe Label
findEdge _ _ [] = Nothing
findEdge id1 id2 (e : ess)
    | id1 == (idFrom e) && id2 == (idTo e) = Just (Label (weight e) (e : []))
    | otherwise = findEdge id1 id2 ess

dijkstra :: Graph -> [(Int, Int, Maybe [Edge])]
dijkstra (Graph vs es) = toNormalForm (dijkstra' [] vs)
    where dijkstra' visited [] = visited
          dijkstra' visited rest =
              let closest = minimum rest
                  newVisited = closest : visited
                  newRest = delete closest (map (triangleIneq closest) rest)
                  triangleIneq (Vertex id1 label1) (Vertex id2 label2) = (Vertex id2 (max label2 (sumMaybe label1 (edge id1 id2))))
                  edge id1 id2 = findEdge id1 id2 es
              in dijkstra' newVisited newRest

g2 = Graph [(Vertex 1 Nothing), (Vertex 2 Nothing), (Vertex 3 Nothing), (Vertex 4 Nothing), (Vertex 5 (Just (Label 0 [])))] [(Edge 1 3 1), (Edge 1 4 1), (Edge 4 2 3), (Edge 1 4 3), (Edge 6 2 4), (Edge 1 3 4), (Edge 3 3 5), (Edge 1 4 5)]
