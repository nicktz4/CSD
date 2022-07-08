
package Model.Tiles;

/**
 *
 * @author nicktz4
 */
public abstract class StatueTile extends FindingTile {
	private String type;	
	/**
	 *<b>Constructor:</b> of Statue.
	 * <b>Precondition:</b> Value of state must be valid.Value of type must be valid
	 * <b>Postcondition:</b> Succesfully creates a statue
	 * @param state
	 */
	public StatueTile(int state,String type) {
		super("Statue", state);
		this.type = type;
	}

	/**
	 *<b>Accessor</b> Returns the type of the statue 
	 * @return  the type of the StatueTile
	 */
	public String getType() {
		return type;
	}
	
	
	
}
