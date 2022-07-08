package Model.Board;
import java.util.Random;
import Model.Collection.Collection;
import Model.Tiles.AmphoraTile;
import Model.Tiles.Colors;
import Model.Tiles.LandSlideTile;
import Model.Tiles.MosaicTile;
import Model.Tiles.SkeletonTile;
import Model.Tiles.StatueTile;
import Model.Tiles.Tile;

/**
 *
 * @author nicktz4
 */
public class Board {
	/**
	 * a collection of amproae
	 */
	private Collection amphorae;	
	/**
	 * a collection of landSlides
	 */
	private Collection landSlides;
	/**
	 * a collection of mosaics
	 */
	private Collection mosaics;
	/**
	 * a collection of skeletons
	 */
	private Collection skeletons;
	/**
	 * a collection of statues
	 
	 */
	private Collection statues;

	public Board() {
	amphorae = new Collection();
	landSlides = new Collection();
	mosaics = new Collection();
	skeletons = new Collection();
	statues = new Collection();
	}	
	
	
	
	/**
	 * <b>Transformer:</b> adds a Tile in its collection 
	 * <b>Precondition:</b> i must be a Tile 
	 * <b>Postcondition:</b> Succesfully adds a Tile to  its collection
	 * @param i is a Tile to add in its  collection
	 */

	
	public void addTile(Tile i) {
		if(i==null) {

		System.out.println("I could not find the tile you want to add");
			return;
		}
		if(i instanceof AmphoraTile) {
			amphorae.addTile((AmphoraTile) i);
			return;
		}	
		if(i instanceof LandSlideTile ) {
			landSlides.addTile((LandSlideTile)i);
			return;
		}
		if(i instanceof MosaicTile) {
			mosaics.addTile((MosaicTile)i);
			return;
		}
		if(i instanceof SkeletonTile) {
			skeletons.addTile((SkeletonTile)i);
			return;
		}
		if(i instanceof StatueTile) {
			statues.addTile((StatueTile)i);
			return;
		}
		
	}
	/**
	 * <b>Transformer:</b> Removes a tile from the board
	 * <b>Precondition:</b> Tile must be in the board
	 * <b>Postcondition:</b> Succesfully removes  the tile from the board
	 * @param i is the tile that it will be removed from the board
	 */
	
	public void removeTile(Tile i) {
		if(i instanceof AmphoraTile) {
			amphorae.removeTile((AmphoraTile) i);
			return;
		}	
		if(i instanceof LandSlideTile ) {
			landSlides.removeTile((LandSlideTile)i);
			return;
		}
		if(i instanceof MosaicTile) {
			mosaics.removeTile((MosaicTile)i);
			return;
		}
		if(i instanceof SkeletonTile) {
			skeletons.removeTile((SkeletonTile)i);
			return;
		}
		if(i instanceof StatueTile) {
			statues.removeTile((StatueTile)i);
			return;
		}
		System.out.println("I could not find the tile you want to remove");
		return;		
		
	}
	/**
	 * <b>Accessor</b>
	 * Returns the number of tiles of an area of the board 
	 * <b>Postcondition</b> Succesfully returns the number of tiles of the area of the board
	 * @param i is the area of the board
	 * @return the number of the tiles that the area has
	 */
	public int getTiles(Tile i) {
		if(i instanceof AmphoraTile) {
			return 	amphorae.getSize();
		}	
		if(i instanceof LandSlideTile ) {
			return landSlides.getSize();
		}
		if(i instanceof MosaicTile) {
			return mosaics.getSize();
		}
		if(i instanceof SkeletonTile) {
			return skeletons.getSize();
		}
		if(i instanceof StatueTile) {
			return statues.getSize();
		}
		
		return -1;
			
	}

	/**
	 * initializes the board  
	 * <b>Postcondition</b> Succesfully sets the starting board
	 * @param bag is the bag to take the tiles from
	 */
	public void StartingBoard(Collection bag) {
		Random rand = new Random();
		int i = 0;
		
		while(i<4) {
		int upper = bag.getSize();
		int randomNumber = rand.nextInt(upper);
		if(checkCol(bag.getTile(randomNumber)) && !"LandSlide".equals(bag.getTile(randomNumber).getCategory())) 		{
		
		addTile(bag.getTile(randomNumber));
		bag.removeTile(bag.getTile(randomNumber));
		i++;
		}
		
		}	
		
	}
	/**
	 * checks if the collection of category of Tile i is empty
	 * @param i is the Tile 
	 * @return true if the collection is empty and false otherwise
	 * 
	 */
	boolean checkCol(Tile i) {
	return getTiles(i)==0;
		
	}

	

	/**
	 * <b>Accessor</b> returns the amphorae collection of the board
	 * <b>Postcondition</b> succesfully returns the amphorae collection of the board
	 * @return a collection
	 */
	public Collection getAmphoraeCollection() {
		return amphorae;
	}
	/**
	 * <b>Accessor</b> returns the mosaic collection of the board
	 * <b>Postcondition</b> succesfully returns the mosaic collection of the board
	 * @return a collection
	 */
	public Collection getMosaicCollection() {
		return mosaics;
	}
	/**
	 * <b>Accessor</b> returns the landSlide collection of the board
	 * <b>Postcondition</b> succesfully returns the landSlide collection of the board
	 * @return a collection
	 */
	public Collection getLandSlideCollection() {
		return landSlides;
	}
	/**
	 * <b>Accessor</b> returns the skeleton collection of the board
	 * <b>Postcondition</b> succesfully returns the skeleton collection of the board
	 * @return a collection
	 */
	public Collection getSkeletonCollection() {
		return skeletons;
	}
	/**
	 * <b>Accessor</b> returns the statue collection of the board
	 * <b>Postcondition</b> succesfully returns the statue collection of the board
	 * @return a collection
	 */
	public Collection getStatueCollection() {
		return statues;
	}
	
	
}

