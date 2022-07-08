
package Model.Cards;

import Model.Tiles.Colors;
import static Model.Tiles.Colors.RED;

/**
 *
 * @author nicktz4
 */
public class Assistant extends Card {
	/**
	 * Constructor.
	 * <b>Postcondition:</b> Creates a new Assistant  card with attribute 
	 * @param cardHolder is the holder of the card
	 */
	public Assistant(Colors cardHolder) {
		super(cardHolder);
	attribute = "Pick 1 tile from any one sorting area.\n";	
	}

	
}
