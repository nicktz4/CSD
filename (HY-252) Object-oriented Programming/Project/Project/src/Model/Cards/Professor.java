
package Model.Cards;

import Model.Tiles.Colors;
import static Model.Tiles.Colors.BROWN;

/**
 *
 * @author nicktz4
 */
public class Professor extends Card {

	/**
	 * Constructor.
	 * <b>Postcondition:</b> Creates a new  Professor card with attribute 
	 * @param cardHolder is the holder of the card
	 */
	public Professor(Colors cardHolder) {
		super(cardHolder);
	attribute = "Pick 1 tile from each sorting area other than the one you chose earlier in your turn.\n";	
	}
	
}
