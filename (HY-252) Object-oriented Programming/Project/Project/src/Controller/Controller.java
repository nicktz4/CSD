
package Controller;

import Model.Board.Board;
import Model.Collection.Collection;
import Model.Player.Player;
import Model.Tiles.Colors;
import static Model.Tiles.Colors.*;
import Model.Tiles.*;
import Model.Tiles.Tile;

/**
 *
 * @author nicktz4
 */
public class Controller {
	/**
	 * The players of the game
	 */
	private Player P1,P2,P3,P4;
	/**
	 * the board of the game
	 */
	private Board board;	
	/**
	 * the bag with the tiles
	 */
	private Collection bag;
	/**
	 * variable to check if the player has played 
	 * 0 for nothing
	 * 1 after draw tiles
	 * 2 after picked 2 tiles from board
	 * 3 if used a card character
	 */
	private int hasPlayedState=0;
	/**
	 * the player that plays the current turn
	 */
	private Colors playerThatPlays;

	/**
	 * this variable is to determine how the pick tile round will go
	 * state 0: has not picked any tile
	 * state 1: has picked 1 tile
	 * state 2 : has picked 2 tiles.
	 */
	private int pickTileState;
	/**
	 * this variable is the collection that the player chose to pick a tile
	 */
	
	/**
	 * <b>Constructor</b> of controller.Initializes everything that we need to start the game
	 * <b>Postcondition</b> Succesfully initializes all we need
	 * initializes the players,the bag and the starting board
	 */
	public Controller() {
		P1 = new Player("p1",Colors.RED);
		P2 = new Player("p2",Colors.GREEN);
		P3 = new Player("p3",Colors.BLUE);
		P4 = new Player("p4",Colors.BROWN);
		this.playerThatPlays = P1.getColor();
		bag = new Collection();
		this.bag.initializeTiles();
		board = new Board();
		this.board.StartingBoard(bag);
	}

	/**
	 * <b>Observer</b> returns the state of the player
	 * <b>Postcondition:</b> succesfully returns the state of the player 
	 * @return the state of the player	
	 * 
	 */
	public int getPlayerState() {
		return hasPlayedState;
	}
	/**
	 * <b>Transformer</b> sets if the player has played 
	 * <b>Postcondition:</b>Succesfully sets hasPlayedState
	 * @param hasPlayed is the state of hasPlayedState to set
	 */
	public void setPlayerState(int hasPlayed) {
		this.hasPlayedState = hasPlayed;
	}
	/**
	 * <b>Accessor</b> returns the player that plays in the current turn
	 * <b>Postcondition</b> succesfully returns the player that plays in current turn
	 * @return a Color(the player that plays in current turn)
	 */
	public Player getCurrentPlayer() {
		if(playerThatPlays == Colors.RED) {
			return P1;
		}
		if(playerThatPlays == Colors.GREEN)
		{
		return P2;
		}
		if(playerThatPlays == Colors.BLUE) {
			return P3;
		}
		return P4;
		
	}
	/**
	 * <b>Transformer</b> sets the current player
	 * <b>Postcondition</b> succesfully sets the new current player
	 * @param playerColor is the color of the new current player
	 */
	public void setCurrentPlayer(Colors playerColor) {
		playerThatPlays = playerColor;
	}
	/**
	 * <b>Accessor</b> returns the bag of the game
	 * <b>Postcondition</b> succesfully returns the bag collection
	 * @return a collection of tiles 
	 */
	public Collection getBag() {
		return bag;
	}
	/**
	 * <b>Accessor</b> returns the board of the game
	 * <b> Postcondition</b> succesfully returns the board of the game
	 * @return the main board
	 */
	public Board getBoard() {
		return board;
	}
	/**
	 * <b>Accessor</b> Returns player 1
	 * @return player 1
	 */
	public Player getPlayer1() {
		return P1;
	}
	/**
	 * <b>Accessor</b> Returns player 2
	 * @return player 2
	 */
	public Player getPlayer2() {
		return P2;
	}
	/**
	 * <b>Accessor</b> Returns player 3
	 * @return player 3
	 */
	public Player getPlayer3() {
		return P3;
	}
	/**
	 * <b>Accessor</b> Returns player 4
	 * @return player 4
	 */
	public Player getPlayer4() {
		return P4;
	}
/**
 * a function to return the URL of the image 
 * @param category is the tile for the image
 * @return  a string with the url for the image
 */
	public String getURL(Tile category) {
		
		switch (category.getCategory()) {
			case "Amphora":
				if(( (AmphoraTile) category).getColor() == Colors.BLUE) {
				return "images_2020/amphora_blue.png";		
				} 
				else if(( (AmphoraTile) category).getColor() == Colors.BROWN) {
					return "images_2020/amphora_brown.png";
				}else if(( (AmphoraTile) category).getColor() == Colors.GREEN) {
					return "images_2020/amphora_green.png";
					
				}else if(( (AmphoraTile) category).getColor() == Colors.PURPLE) {
					return "images_2020/amphora_purple.png";
				} else if(( (AmphoraTile) category).getColor() == Colors.RED) {
					return "images_2020/amphora_red.png";
				} else {
					return "images_2020/amphora_yellow.png";
				}

				
			case "Statue":
				if("Sphinx".equals(((StatueTile) category).getType()) ){
					return "images_2020/sphinx.png";
					
				}else {
					return "images_2020/caryatid.png";
				}
				
			case "LandSlide":
				return "images_2020/landslide.png";
			case "Mosaic":
				if(( (MosaicTile) category).getColor() == Colors.GREEN) {
					return "images_2020/mosaic_green.png";
					
				} else if(( (MosaicTile) category).getColor() == Colors.RED){
					return "images_2020/mosaic_red.png"; 
				}else {
					return "images_2020/mosaic_yellow.png";
					}	
					
					
					
			case "Skeleton":
				if("LARGE".equals(((SkeletonTile)category).getSkeletonSize())) {	
				if("UPPER".equals(((SkeletonTile) category).getSkeletonBody())) {
					return "images_2020/skeleton_big_top.png";
					
				} else {
					return "images_2020/skeleton_big_bottom.png";
				}
				
			 } else {
				if("UPPER".equals(((SkeletonTile) category).getSkeletonBody())) { {
					return "images_2020/skeleton_small_top.png";
				}
				} else {
					return "images_2020/skeleton_small_bottom.png";
				}
				}
		}
		return "images_2020/tile_back.png";
	
	
}
	/**
	 * <b>Accessor</b> Returns the pickTileState variable
	 * @return  the pickTileState variable
	 */
	public int getPickTileState() {
		return pickTileState;
	}
	
	/**
	 * <b>Transformer</b>Sets the pickTileState
	 * @param i is the new state of the pickTileState
	 */
	public void setPickTileState(int i) {
		pickTileState = i;
	}


/**
	 * function to calculate sphinx Tiles for all players
	 * @return  an int array with the sphinx tiles for all players
	 */
	public int[] calculateSphinxTilesForPlayers() {
	/*
			0 for p1
			1 for p2
			2 for p3
			3 for p4
			
		*/
	int sphinxTiles[] = {0,0,0,0};

	for(int i = 0;i<P1.getPlayerCollection().getSize();i++) {
		if("Statue".equals(P1.getPlayerCollection().getTile(i).getCategory()))
		if("Sphinx".equals(((StatueTile)P1.getPlayerCollection().getTile(i) ).getType())) {
			sphinxTiles[0]++;
		}
	}for(int i = 0;i<P2.getPlayerCollection().getSize();i++) {
		
		if("Statue".equals(P2.getPlayerCollection().getTile(i).getCategory()))
		if("Sphinx".equals(((StatueTile)P2.getPlayerCollection().getTile(i) ).getType())) {
			sphinxTiles[1]++;
		}
	}for(int i = 0;i<P3.getPlayerCollection().getSize();i++) {
		
		if("Statue".equals(P3.getPlayerCollection().getTile(i).getCategory()))
		if("Sphinx".equals(((StatueTile)P3.getPlayerCollection().getTile(i) ).getType())) {
			sphinxTiles[2]++;
		}
	}for(int i = 0;i<P4.getPlayerCollection().getSize();i++) {
		if("Statue".equals(P4.getPlayerCollection().getTile(i).getCategory()))
		if("Sphinx".equals(((StatueTile)P4.getPlayerCollection().getTile(i) ).getType())) {
			sphinxTiles[3]++;
		}
	}
	return sphinxTiles;
}
	/**
	 * function to calculate caryatid Tiles for all players
	 * @return  an int array with the caryatid tiles for all players
	 */
	public int[] calculateCaryatidTilesForPlayers() {
	/*
			0 for p1
			1 for p2
			2 for p3
			3 for p4
			
		*/
	int caryatidTiles[] = {0,0,0,0};

	for(int i = 0;i<P1.getPlayerCollection().getSize();i++) {
		if("Statue".equals(P1.getPlayerCollection().getTile(i).getCategory())) {
		if("Caryatid".equals(((StatueTile)P1.getPlayerCollection().getTile(i)).getType())) {
			caryatidTiles[0]++;
		}
		}
	}for(int i = 0;i<P2.getPlayerCollection().getSize();i++) {
		if("Statue".equals(P2.getPlayerCollection().getTile(i).getCategory())) {
		if("Caryatid".equals(((StatueTile)P2.getPlayerCollection().getTile(i)).getType())) {
			caryatidTiles[1]++;
		}
		}
	}for(int i = 0;i<P3.getPlayerCollection().getSize();i++) {
		if("Statue".equals(P3.getPlayerCollection().getTile(i).getCategory())) {
		if("Caryatid".equals(((StatueTile)P3.getPlayerCollection().getTile(i)).getType())) {
			caryatidTiles[2]++;
		}
		}
	}for(int i = 0;i<P4.getPlayerCollection().getSize();i++) {
		if("Statue".equals(P4.getPlayerCollection().getTile(i).getCategory())) {
		if("Caryatid".equals(((StatueTile)P4.getPlayerCollection().getTile(i)).getType())) {
			caryatidTiles[3]++;
		}
		}
	}
	return caryatidTiles;
}
	/**
	 * function to calculate statue points for all players
	 * @return  an array with the points of all players from Statues
	 */
	public int[] calculateStatuePointsForPlayers() {
		int sphinxTiles[];
		sphinxTiles = calculateSphinxTilesForPlayers();
		int caryatidTiles[];
		caryatidTiles = calculateCaryatidTilesForPlayers();
		int maxS = sphinxTiles[0];
		int minS = sphinxTiles[0];
		int maxC = caryatidTiles[0];
		int minC = caryatidTiles[0];
		for(int i = 0;i<4;i++) {
			if(sphinxTiles[i] > maxS) {
				maxS = sphinxTiles[i];
			}
			if(sphinxTiles[i] < minS) {
				minS = sphinxTiles[i];
			}
			if(caryatidTiles[i] > maxC) {
				maxC = caryatidTiles[i];
			}
			if(caryatidTiles[i] < minC) {
				minC = caryatidTiles[i];
			}
			
		}
		
		int pointsToAdd[] = {0,0,0,0};

		for(int i = 0;i<4;i++) {
			if(sphinxTiles[i] == maxS) {
				pointsToAdd[i]+=6;
			}
			if(sphinxTiles[i]!= minS && sphinxTiles[i]!=maxS) {
				pointsToAdd[i]+=3;
			}
			if(caryatidTiles[i]==maxC) {
				pointsToAdd[i]+=6;
			}
			if(caryatidTiles[i]!=minC && caryatidTiles[i]!=maxC) {
				pointsToAdd[i]+=3;
			}
			
		}
			
		
		
		
		return pointsToAdd;
	}
}

