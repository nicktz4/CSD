
package Model.Player;

import Model.Cards.*;
import Model.Collection.Collection;
import Model.Tiles.Colors;
import Model.Tiles.*;
import Model.Tiles.Tile;
import java.util.Random;

/**
 *
 * @author nicktz4
 */
public class Player {
	/**
	 * the name of the player
	 */
	private String name;	
	/**
	 * the tiles that the player has taken
	 */
	private Collection myTiles;	
	/**
	 * the color of the player
	 */
	private Colors myColor; 
	/**
	 * a  boolean variable to see if the player has ended his turn
	 */
	private boolean endTurn;
	/**
	 * The professor card of the player
	 */
	private Card Professor;
	/**
	 * the digger card of the player
	 */
	private Card Digger;
	/**
	 * the assistant card of the player
	 */
	private Card Assistant;
	/**
	 * the archaeologist card of the player
	 */
	private Card Archaeologist;
	/**
	 * the points of the player
	 */
	private int points;

	/**
	 * <b>Constructor:</b> of Player
	 * <b>Precondition:</b> 
	 * <b>Postcondition:</b>Succesfully creates a new player 
	 * @param name is the name of the player
	 * @param playerColor is the color of the player
	 */
	public Player(String name ,Colors playerColor) {
		this.myTiles = new Collection();
		this.name = name;
		myColor = playerColor;
		Professor = new Professor(myColor);
		Digger = new Digger(myColor);
		Assistant = new Assistant(myColor);
		Archaeologist = new Archaeologist(myColor);
	}
	/**
	 * <b>Accessor:</b>returns the name of the player
	 * <b>Postcondition:</b> succesfully returns the name of the player
	 * @return the name of the player
	 */
	public String getName() {
		return name;
	}
	/**
	 * <b>Accessor:</b> returns the color of the player
	 * 
	 * @return the color of the player 
	 */
	public Colors getColor() {
		return myColor;
	}	
	/**
	 * <b>Accessor</b> returns the Professor card of the player
	 * <b>Postcondition:</b> Succesfully returns the Professor card of the player
	 * @return a professor Card
	 */
	public Card getProfessor() {
		return Professor;
	}
	/**
	 * <b>Accessor</b> returns the Digger card of the player
	 * <b>Postcondition:</b> Succesfully returns the Digger card of the player
	 * @return a Digger Card
	 */
	public Card getDigger() {
		return Digger;
	}
	/**
	 * <b>Accessor</b> returns the Assistant card of the player
	 * <b>Postcondition:</b> Succesfully returns the Assistant card of the player
	 * @return an Assistant Card
	 */
	public Card getAssistant() {
		return Assistant;
		
	}
	/**
	 * <b>Accessor</b> returns the Archaeologist card of the player
	 * <b>Postcondition:</b> Succesfully returns the Archaeologist card of the player
	 * @return an Archaeologist Card
	 */
	public Card getArchaeologist() {
		return Archaeologist;
	}
	/**
	 * <b>Transformer:</b> calculates the points of the player and returns it.(Without statue points)
	 * <b>Postcondition:</b> Succesfully calculates the points of the player and returns it (Without statue points)
	 * 
	 * @return the points of the player without the statue points 
	 */
	public int calculatePoints() {
		return getMosaicPoints() + getAmphoraPoints() + getSkeletonPoints();

		
		
	}
/**
 * function to calculate the MosaicPoints of the player
 * @return 
 */
	public int getMosaicPoints() {
		/* 	mosaicsColors[0] is for GREEN
			mosaicsColors[1] is for RED
			mosaicsColors[2] is for YELLOW
		*/
		int mosaicsColors[] = {0,0,0};
		
		for(int i = 0; i < myTiles.getSize();i++) {
			if("Mosaic".equals(myTiles.getTile(i).getCategory())) {
				if( (  (MosaicTile) myTiles.getTile(i)).getColor() == Colors.GREEN ) {
					mosaicsColors[0]++;
					
				}else if(((MosaicTile) myTiles.getTile(i)).getColor()== Colors.RED) {
					mosaicsColors[1]++;
				} else {
					mosaicsColors[2]++;
				}
				
			}
		}
		int mosaicPoints = 0;
		for(int i = 0 ; i < 3 ; i++) {
			// 4 pontous otan uparxoyn 4 idia xrwmata
			mosaicPoints = mosaicPoints  + 4*(mosaicsColors[i]/4);
			// osa menoun ta kratame
			mosaicsColors[i] =  mosaicsColors[i]%4;
			
		}
		
		mosaicPoints = mosaicPoints + 2*((mosaicsColors[0]+mosaicsColors[1]+mosaicsColors[2])/4);
		return mosaicPoints;	
		
		
	}
/**
 * a function to calculate Amphora Points
 * @return the points that collected from AmphoraTiles
 */
	public int getAmphoraPoints() {
		/*
			amphoraColors[0] for GREEN
			amphoraColors[1] for RED
			amphoraColors[2] for YELLOW
			amphoraColors[3] for PURPLE
			amphoraColors[4] for BLUE
			amphoraColors[5] for BROWN
		*/
		int amphoraColors[] = {0,0,0,0,0,0};
		for(int i = 0; i < myTiles.getSize();i++) {
			if("Amphora".equals(myTiles.getTile(i).getCategory())) {
				if( (  (AmphoraTile) myTiles.getTile(i)).getColor() == Colors.GREEN ) {
					amphoraColors[0]++;
					
				}else if(((AmphoraTile) myTiles.getTile(i)).getColor()== Colors.RED) {
					amphoraColors[1]++;
				} else if(((AmphoraTile) myTiles.getTile(i)).getColor()==Colors.YELLOW) {
					amphoraColors[2]++;
				} else if(((AmphoraTile) myTiles.getTile(i)).getColor()==Colors.PURPLE) {
					amphoraColors[3]++;
			} 	  else if(((AmphoraTile) myTiles.getTile(i)).getColor()==Colors.BLUE) {
				amphoraColors[4]++;
			} else {
				amphoraColors[5]++;
				}
				
			}
		}
		int amphoraPoints=0;
		while(true) {
	int amphoraes = 0;	
	for(int i = 0 ; i<6;i++) {
		if(amphoraColors[i]!=0) {
			amphoraes ++;
			amphoraColors[i]--;
		}
	}
			switch (amphoraes) {
				case 6:
					amphoraPoints+=6;
					break;
				case 5:
					amphoraPoints+=4;
					break;
				case 4:
					amphoraPoints+=2;
					break;
				case 3:
					amphoraPoints+=1;
					break;
				default:
					break;
			}
	if(amphoraes == 2 || amphoraes == 1 || amphoraes == 0) {
		break;
	}
		}
	
	return amphoraPoints;	
	}
/**
 * this function takes as parameter the statuePoints
 * statuePoints are calculated in Controller
 * @param statuePoints is the statuePoints
 * @return  the statue Points of the player
 
 */
	public int getStatuePoints(int statuePoints[]) {
		if(getColor()==Colors.RED) {
			return statuePoints[0];
		} else if(getColor()==Colors.GREEN) {
			return statuePoints[1];
		} else if(getColor()==Colors.BLUE) {
			return statuePoints[2];
		} else {
			return statuePoints[3];
		}
		
	}

	public int getSkeletonPoints( ) {
		/* skeletons[0] for LARGE and UPPER
		   skeletons[1] for LARGE and LOWER
		   skeletons[2] for SMALL and UPPER
		   skeletons[3] for SMALL and LOWER
		
		*/
	int skeletons[] = {0,0,0,0};	
		for(int i = 0 ; i < myTiles.getSize();i++) {
			if("Skeleton".equals(myTiles.getTile(i).getCategory())) {
				if("LARGE".equals(((SkeletonTile)myTiles.getTile(i)).getSkeletonSize())) {	
				if("UPPER".equals(((SkeletonTile) myTiles.getTile(i)).getSkeletonBody())) {
					skeletons[0]++;
				
					
				} else {
					skeletons[1]++;
				}
				
			 } else {
				if("UPPER".equals(((SkeletonTile) myTiles.getTile(i)).getSkeletonBody())) { 
					skeletons[2]++;
				
				} else {
					skeletons[3]++;
				}
			}
			
		}
	}
		int skeletonPoints = 0;
		while(true) {
			if(skeletons[0]>1 && skeletons[1]>1) {
				if(skeletons[2]!=0 && skeletons[3]!=0) {
						skeletonPoints+=6;
						skeletons[0]--;
						skeletons[1]--;
						skeletons[2]--;
						skeletons[3]--;
					} else {
						break;
					}
				
			} else {
				break;
			}
		}		
		while(true) {
			if(skeletons[0]!=0 && skeletons[1]!=0) { 
				skeletonPoints+=1;
				skeletons[0]--;
				skeletons[1]--;
			} else {
				break;
			}
			
		}
		while(true) {
		if(skeletons[2]!=0 && skeletons[3]!=0) {
				skeletonPoints+=1;
				skeletons[2]--;
				skeletons[3]--;
			}else {
			break;
		}
		
	
	}
		return skeletonPoints;
	}
	
	/**
	 * <b>Accessor</b> Returns the points of the player
	 * <b>Postcondition:</b> Succesfully returns the points of the player
	 * @return the points of the player
	 */
	 public int getPoints() {
		return points;
	}
	 /**
	  * <b>Transformer</b> sets the endTurn variable
	  * <b>Postcondition:</b> Succesfully sets the endTurn variable
	  * @param turn is the boolean value for the endTurn
	  */
	 public void setEndTurn(boolean turn) {
		 endTurn = turn;
	 }
	 /**
	  * <b>Accessor</b> returns the state of the endTurn variable
	  * <b>Postcondition:</b> Succesfully returns the endTurn variable
	  * 
	 * @return the state of the endTurn of the player 
	  */
	 public boolean getEndTurn() {
		 return endTurn;
	 }

	/**
	 * draws a tile from the bag ,removes it from the bag and returns it
	 * @param bag is the bag 
	 * @return the tile that got from the bag
	 */ 
	public Tile drawTile(Collection bag) {
		if(!bag.isEmpty()) {
		Random rand = new Random();
		int upper = bag.getSize();
		int randomNumber = rand.nextInt(upper);
		
		Tile i = bag.getTile(randomNumber);
		bag.removeTile(bag.getTile(randomNumber));
		return i;
		}
		return null;
		
		
	}	
	/**
	 * <b>Transformer</b> Draws a tile from the collection and add it to player's collection of tiles
	 * @param col  is the collection to get the tile
	 */
	public void getTile(Collection col) {
		Random rand = new Random();
		int upper = col.getSize();
		int randomNumber = rand.nextInt(upper);
		myTiles.addTile(col.getTile(randomNumber));
		
		
		
	}
/**
 * <b>Accessor</b>Returns the collection of tiles of the player
 * <b>Postcondition</b>Succesfully returns the collection of tiles of the player
	 * @param playersPoints are the points of every player
 * @return a collection of tiles
 */	
	public Collection getPlayerCollection() {
		return myTiles;
	}
}
