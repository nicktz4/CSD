
package Model.Tiles;

/**
 *
 * @author nicktz4
 */


	
public class AmphoraTile extends FindingTile{
	/**
	 * the color of the amphora Tile
	 */
	private Colors color;	
	
	/**
	 * Constructor of AmphoraTile
	 * <b>Precondition:</b> State value must be valid,color must be valid
	 * <b>Postcondition:</b> Succesfully creates a AmphoraTile 
	 * @param color is the color of the Amphora Tile 
	 * @param state is the state of the AmphoraTile
	 * 
	 */	
	public AmphoraTile(Colors color, int state) {
		super("Amphora", state);
		this.color = color;
	}

	/**
	 * <b>Accessor:</b> returns amphora's color
	 * <b>Postcondition:</b> amphora's color returned succesfully
	 * @return Amphora's color
	 *
	 * */
	public Colors getColor() {
		return color;
	}
	
}
