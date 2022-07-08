
package Model.Collection;

import Model.Tiles.*;
import java.util.ArrayList;

/**
 *This class creates an arrayList with the tiles
 * @author nicktz4
 */
public class Collection {
	/**
	 * An arrayList with tiles
	 */
private ArrayList<Tile> tiles;	
	
/**
 * <b>Constructor</b> of the collection
 * Creates a new collection from Tiles
 * 
 */
public Collection() {
	tiles = new ArrayList<Tile>();
}

/**
 * <b>Transformer:</b> Initializes  all the tiles
 * <b>Postcondition:</b> Succesfully creates the collection
 */
public void initializeTiles() {
for(int i = 0 ; i < 127;i++) {
	
if(i < 12) {
	addTile(new CaryatidTile(1));
} else if(i < 24) {
	addTile(new SphinxTile(1));
	
}	else if(i<40) {
	addTile(new LandSlideTile(1));
	
}else if(i<67) {
		if(i<49) {
			addTile(new MosaicTile(1,Colors.GREEN) );
		} else if( i < 58) {
			addTile(new MosaicTile(1,Colors.RED));
		} else {
			addTile(new MosaicTile(1,Colors.YELLOW));
		}
	
}else if(i<98) {
	if(i < 77) {
		addTile(new SkeletonTile("LARGE","UPPER",1));
			
	} else if(i < 88) {
		addTile(new SkeletonTile("LARGE","LOWER",1));
	} else if( i < 93) {
		addTile(new SkeletonTile("SMALL","UPPER",1));
	} else {
		addTile(new SkeletonTile("SMALL","LOWER",1));
			
	}
	
}else {
	if(i<103) {
		addTile(new AmphoraTile(Colors.BLUE,1));
	}	else if(i < 108) {
		addTile(new AmphoraTile(Colors.BROWN, 1));
	} else if( i < 113) {
		addTile(new AmphoraTile(Colors.RED,1));
	} else if( i < 118) {
		addTile(new AmphoraTile(Colors.GREEN,1));
	} else if(i<123) {
		addTile(new AmphoraTile(Colors.YELLOW, 1));
	} else {
		addTile(new AmphoraTile(Colors.PURPLE, 1));
	}
	
}


}	
}

/**
 * <b>Transformer:</b> Adds a Tile to the Collection
 <b>Postcondition:</b> succesfully adds a Tile to the bag
 * @param i is the Tile to add
 */
public void addTile(Tile i) {
	tiles.add(i);
	
}
/**
 * <b>Transformer:</b> Removes a Tile from the bag
 * <b>Postcondition:</b> Succesfully removes tile i from the collection,or if there is not tile I in the list,it does not remove anything
 * 
 * @param i is the tile that will be removed
 */
public void removeTile(Tile i ) {
	if(getSize()!=0) {
		tiles.remove(i);
	}
	
}
/**
 * <b>Accessor</b>returns the size of the collection (how many tiles are in the collection)
 * @return the size of the collection
 */
public int getSize() {
	return tiles.size();
}

/**
 * <b>Accessor:</b> returns tile's toString
 * <b>Postcondition:</b> tile's toString in position i has returned
 * @param i is the position for the tile
 * @return toString of the tile in position i
 */
public String getTileString(int i) {
	return tiles.get(i).toString();
}

/**
 * <b>Accessor</b> returns the tile with index i
 * <b>Precondition</b> arrayList must have a tile in i position
 * <b>Postcondition</b> Succesfully returns the tile in position i of the arrayList
 * @param i is the position for the tile
 * @return  the tile in the position i of the arrayList
 */
public Tile getTile(int i ) {
	if(tiles.isEmpty()) {
		
		throw new ArithmeticException("There are not any tiles in collection to give");
	}
	return tiles.get(i);
}

/**
 * <b>Observer:</b> Checks if the collection is empty
 * <b>Postcondition:</b> Returns true if collection is empty,false otherwise
 * @return true if collection has no elements,false otherwise
 */
public boolean isEmpty() {
	if(tiles.size()==0) {
	return true;	
	}
	return false;
}




}
