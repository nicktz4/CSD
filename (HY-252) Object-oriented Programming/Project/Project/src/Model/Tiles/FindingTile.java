
package Model.Tiles;

/**
 *
 * @author nicktz4
 */
public abstract class FindingTile extends Tile{

	/**
	 * Constructor of a FindingTile
	 * <b>Precondition:</b> State value must be valid
	 * 
	 * <b>Postcondition:</b> Succesfully creates a LandSlideTile 
	 * @param state is the state of the FindingTile 
	 * @param category is the category of the FindingTile
	 */
	public FindingTile(String category, int state) {
		super(category, state);
	}
	

	
}
