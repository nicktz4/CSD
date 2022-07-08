package Model.Tiles;

/**
 *
 * @author nicktz4
 */
public abstract class Tile {
	/**
	 * String for the category of the Tile
	 */
	protected String category; 
	/**
	 *  state of the tile.1 if its in the bag,0 if its on board,-1 if a player has it
	 */
	//protected int State;
	/**
	 * the points that the tile gives
	 */

	/**
	 * <b>Constructor</b> of Tile.
	 * <b>Precondition</b>  state has to be a valid state
	 * <b>Postcondition</b> succesfully sets category and state of the tile
	 * 
	 * @param category is the category of the tile
	 * @param state  is the state of the tile
	 * @throws IllegalArgumentException if the state is not valid
	 * 
	 */
	public Tile(String category,int state) {
		this.category = category;
		if(state!=1 && state !=0 && state!=-1) {
			throw new IllegalArgumentException("State is not valid");
		}
		//this.State = state;
	}
	/**
	 * <b>Accessor</b> returns the state of the tile
	 */
	//public int getState() {
	//	return State;
	//}

	/**
	 * <b>Accessor</b> returns a String with the category of the Tile
	 */
        public	String getCategory() {
		return category;
	}
	
	/**
	 * <b>Transformer:</b> Sets the state of the tile
	 * <b>Precondition:</b> State values:1 or 0 or -1
	 * <b>Postcondition:</b> Succesfully returns tile state
	 * @param state is the state of the tile
	 */
	//public void setState(int state) {
	//	State = state;
	//}	
	
	
	
	
}
